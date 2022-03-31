/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <exception>

using namespace std;

#include <nngpp/transport/tcp.h>


#include "EventTypeEnum.h"
#include "Constants.h"
#include "ServerMessage.h"
#include "MessageUtils.h"
#include "TimeUtils.h"
#include "GsModuleManager.h"

#include "GsTcpConnection.h"


void readHandler(void *);


GsTcpConnection::GsTcpConnection(const string& inIdentifier)
    : GsConnection{inIdentifier},
      tcpSocket_{},
      tcpStream_{},
      url_{string{}},
      port_{0},
      frameSize_{DEFAULT_FRAME_SIZE},
      bytesBuffer_{},
      endTransferMcs_{false},
      deliverThread_{},
      mutex_{},
      frames_{}
{   
    setFrameSize(DEFAULT_FRAME_SIZE);
}

GsTcpConnection::GsTcpConnection(const string& inIdentifier, string& inURL, int inPort, size_t inFrameSize)
    : GsConnection{inIdentifier},
      tcpSocket_{},
      tcpStream_{},
      url_{inURL},
      port_{inPort},
      frameSize_{inFrameSize},
      bytesBuffer_{},
      endTransferMcs_{false},
      deliverThread_{},
      mutex_{},
      frames_{}
{
    setFrameSize(inFrameSize);
}

GsTcpConnection::~GsTcpConnection()
{
    disconnect();
}

void GsTcpConnection::connect()
{
    if (this->url_.empty() == false)
    {        
        /*
         * char uri[64];
	     snprintf(uri, sizeof(uri), "tcp://127.0.0.1:%d", test_htons(sa.s_in.sa_port));
	     auto d = nng::stream::dialer(uri);
        */
        string tcpAddress = "tcp://" + url_ + ":" + std::to_string(port_);
        
        this->tcpSocket_ = nng::stream::make_dialer(tcpAddress.c_str());
        
        nng::aio  tmpAio = nng::make_aio(nullptr, nullptr);
        
        // Connect to the G/S
        this->tcpSocket_.dial(tmpAio);

        // The `nng_aio_wait()` function waits for an asynchronous I/O operation
        // to complete.
        tmpAio.wait();
        
        if (tmpAio.result() != nng::error::success)
        {
            string errorMessage = "Unable to connect to Ground Station: " + this->identifier_;
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }

        // Create the stream
        nng::stream::stream   tmpStream( tmpAio.get_output<nng_stream>(0) );
        this->tcpStream_ = std::move(tmpStream);
        
        if (!tcpStream_)
        {
            string errorMessage = "Unable to create connection stream. Ground Station: " + this->identifier_;
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
        
        // Set stream option
        this->tcpStream_.set_bool( to_name(nng::tcp::option::no_delay), true);
        this->tcpStream_.set_bool( to_name(nng::tcp::option::keep_alive), true);

        // Start delivery thread
        std::thread tmpThread{ std::bind(&GsTcpConnection::sendFramesToMCS, this) };
        this->deliverThread_ = std::move(tmpThread);

        // First read
        internalRead();
    }
}

void GsTcpConnection::disconnect()
{
    // Is it created?
    if (this->tcpSocket_)
    {
        // Close the socket
        this->tcpSocket_.close();
    }

    // Stop the MCS delivery thread
    this->endTransferMcs_ = true;
}

/**
 * @brief GsTcpConnection::read starts reading bytes from the socket
 */
void GsTcpConnection::read()
{
}

void GsTcpConnection::write()
{
}

// It will receive the pointer to the G/S TCP Connection class
void readHandler(void *inArgument)
{
    LogManager::getInstance().debug("Received frame: ");
    
    GsTcpConnection  *pParent = static_cast<GsTcpConnection *>(inArgument);
    
    // Store a copy
    //RawFrameType  mcsFrame{ this->bytesBuffer_ };

    pParent->internalAddFrame();

    pParent->internalRead();
}

void GsTcpConnection::internalRead()
{
    nng::aio readAio(readHandler, this);

    this->bytesBuffer_.clear();
    
    readAio.set_iov( {this->bytesBuffer_.data(), this->frameSize_} );
    
    this->tcpStream_.recv(readAio);
    
    if (readAio.result() != nng::error::success)
    {            
        string errorMessage = "Error reading bytes from Ground Station: " + this->identifier_;
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }

    // We do not care about reading less bytes
//        REQUIRE(aio1.count() == 5);
}

void GsTcpConnection::internalAddFrame()
{
    std::unique_lock<std::mutex> lck(this->mutex_);
    
    this->frames_.push_back( this->bytesBuffer_ );
}

// Send the current frame to the HK TM Processor (in the MCS)
// It will run in a separated thread
void GsTcpConnection::sendFramesToMCS()
{
    while (this->endTransferMcs_ == false)
    {
        RawFrameType  currentFrame;

        // Try to retrieve a frame, if there are no available ones, wait for one            
        currentFrame = this->frames_.front();

        ServerMessage  outputMessage;

        // TODO: Add the timestamp to the message
        outputMessage.setOperationCode(OperationCodeEnum::CODE_NEW_RAW_FRAME);
        outputMessage.setAuthorizationToken("TODO");
        outputMessage.setData(currentFrame);

        GsModuleManager::getInstance().sendToTmProcessor(outputMessage);
    }
}

void GsTcpConnection::setUrl(const string &inURL)
{
    this->url_ = inURL;
}

string GsTcpConnection::getUrl()
{
    return this->url_;
}

void GsTcpConnection::setPort(int inPort)
{
    this->port_ = inPort;
}

int GsTcpConnection::getPort()
{
    return this->port_;
}

/**
 * @brief GsTcpConnection::setFrameSize
 * Reset the buffer size
 * @param inFrameSize
 */
void GsTcpConnection::setFrameSize(size_t inFrameSize)
{
    this->frameSize_ = inFrameSize;

    this->bytesBuffer_.resize(inFrameSize);
}

size_t GsTcpConnection::getFrameSize()
{
    return this->frameSize_;
}

