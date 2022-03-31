/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <exception>

using namespace std;

#include <boost/asio/connect.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/bind.hpp>

#include "EventTypeEnum.h"
#include "Constants.h"
#include "ServerMessage.h"
#include "MessageUtils.h"
#include "TimeUtils.h"
#include "GsModuleManager.h"

#include "GsTcpConnection.h"




GsTcpConnection::GsTcpConnection(boost::asio::io_service& inIoService, const string& inIdentifier)
    : GsConnection{inIdentifier},
      tcpSocket_{inIoService},
      url_{string()},
      port_{0},
      frameSize_{DEFAULT_FRAME_SIZE},
      bytesBuffer_{},
      endTransferMcs_{false},
      deliverThread_{},
      frames_{}
{   
    setFrameSize(DEFAULT_FRAME_SIZE);
}

GsTcpConnection::GsTcpConnection(boost::asio::io_service& inIoService, const string& inIdentifier, string& inURL, int inPort, size_t inFrameSize)
    : GsConnection{inIdentifier},
      tcpSocket_{inIoService},
      url_{inURL},
      port_{inPort},
      frameSize_{inFrameSize},
      bytesBuffer_{},
      endTransferMcs_{false},
      deliverThread_{},
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
        // Convert the server name that was specified to a TCP endpoint.
        // To do this, we use an ip::tcp::resolver object.
        tcp::resolver resolver( tcpSocket_.get_io_service() );

        // URL + port
        tcp::resolver::query query(this->url_, to_string(this->port_));

        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);


        // Now we create and connect the socket.
        // The list of endpoints obtained above may contain both IPv4 and IPv6 endpoints,
        // so we need to try each of them until we find one that works.
        // This keeps the client program independent of a specific IP version.
        // The boost::asio::connect() function does this for us automatically.
        boost::asio::connect(this->tcpSocket_, endpoint_iterator);

        // After that, invoke read() in order to start reading bytes
        read();
    }
}

void GsTcpConnection::disconnect()
{
    if (this->tcpSocket_.is_open() == true)
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
    // Read the first batch of bytes
    this->tcpSocket_.async_read_some(boost::asio::buffer(bytesBuffer_),
                                     boost::bind(&GsTcpConnection::readHandler, this,
                                                 boost::asio::placeholders::error,
                                                 boost::asio::placeholders::bytes_transferred) );

    // Start delivery thread
    std::thread tmpThread{ std::bind(&GsTcpConnection::sendFramesToMCS, this) };
    this->deliverThread_ = std::move(tmpThread);
}

void GsTcpConnection::readHandler(const boost::system::error_code &ec, std::size_t bytes_transferred)
{
    if (!ec)
    {
        cout << "Received frame: " << endl;
        //cout.write( this->bytesBuffer.data(), bytes_transferred);

        /*
        // Is there enough bytes?
        if (this->bytesBuffer.size() >= this->frameSize)
        {
            // Extract the first N bytes
            vector<char> mcsFrame;

            for(size_t i = 0; i < this->frameSize; ++i)
            {
                mcsFrame.push_back( this->bytesBuffer.front() );
            }

            // Store a frame to be sent to the MCS
            this->frames.push(mcsFrame);

        }
        */

        // Store a copy
        RawFrameType  mcsFrame{ this->bytesBuffer_ };

        this->frames_.push_back(mcsFrame);

        // Read next bytes
        this->tcpSocket_.async_read_some(boost::asio::buffer(this->bytesBuffer_),
                                         boost::bind(&GsTcpConnection::readHandler, this,
                                                     boost::asio::placeholders::error,
                                                     boost::asio::placeholders::bytes_transferred) );
    }
}

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

