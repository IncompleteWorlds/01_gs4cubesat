/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <thread>

using namespace std;

#include "GSException.h"
#include "ConfigurationManager.h"

#include "IMessageProcessor.h"
#include "MessageUtils.h"
#include "LogManager.h"

#include "ServerWorker.h"


ServerWorker::ServerWorker(zmq::context_t &ctx, int sock_type)
    : ctx_{ctx},
      worker_{ctx_, sock_type},
      done_{false},
      processor_{}
{
}

ServerWorker::~ServerWorker()
{
}

void ServerWorker::setMessageProcessor(MessageProcessorSharedPtr  inProcessor)
{
    this->processor_ = inProcessor;
}

void ServerWorker::run()
{
    worker_.connect("inproc://backend");

    internalRun();
}

void ServerWorker::internalRun()
{
    if (processor_.get() != nullptr)
    {
        ServerMessage   outputMessage;

        while (done_ == false)
        {
            try
            {
                ServerMessage  newMessage;

                receiveMessage(worker_, newMessage);

                outputMessage = processor_->processMessage(newMessage, *this);
            }
            catch(GSException& gsException)
            {
                string exceptionMessage = "ERROR: GS Exception in ServerWorker::run: " + gsException.getErrorMessage();
                
                // Create error message. MsgReturnData
                ::createReply(outputMessage, gsException.getErrorCode(), gsException.getErrorMessage());
                
                LogManager::getInstance().error(exceptionMessage);
                //cout << exceptionMessage << endl;
            }
            catch (std::exception &e)
            {
                string exceptionMessage = "ERROR: Exception in ServerWorker::run: " + string{e.what()};

                ::createReply(outputMessage, -1, exceptionMessage);

                LogManager::getInstance().error(exceptionMessage);
                //cout << exceptionMessage << endl;
            }

            // Send reply
            sendMessage(worker_, outputMessage);
        }
    }
    else
    {
        LogManager::getInstance().error("Message processor cannot be null. Stopping");
        //cout << "ERROR: Message processor cannot be null" << endl;
    }
}

ServerMessage ServerWorker::forward(const string& inServerName, const ServerMessage& inMessage)
{
    string serverAddress = ConfigurationManager::getInstance().getValue(inServerName);
    LogManager::getInstance().info("Forwarding message to: " + serverAddress);
    //cout << "INFO: Forwarding to: " << serverAddress << endl;

    // Create socket
    zmq::socket_t  forwardSocket{ctx_, ZMQ_REQ};
    
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    forwardSocket.setsockopt(ZMQ_RCVTIMEO, timeoutValue);

    forwardSocket.connect(serverAddress);

    // Send message
    sendMessage(forwardSocket, inMessage);

    // Wait for answer
    ServerMessage  outputMessage;

    receiveMessage(forwardSocket, outputMessage);

    // Return output message
    return outputMessage;
}








/*
// Convert the received message from ZeroMQ to ServerMessage
void ServerWorker::extractMessage(zmq::message_t &inZeroMqMessage, ServerMessage& outMessage)
{
    vector<uint8_t>  outData(inZeroMqMessage.size());

    uint8_t *inputData = static_cast<uint8_t *>(inZeroMqMessage.data());

    for(uint32_t i = 0; i < inZeroMqMessage.size(); i ++)
    {
        outData[i] = inputData[i];
        //printf(" %02x  %02x \n", tmpData[i],  outData[i]);
    }

    outMessage.setData(outData);
}

// Convert the outgoing message from ServerMessage to ZeroMQ
void ServerWorker::convertMessage(ServerMessage& inMessage, zmq::message_t &outZeroMqMessage)
{
    vector<uint8_t>  inputData{inMessage.getData()};

    uint32_t  messageLength = inMessage.getDataSize();

    outZeroMqMessage.rebuild(messageLength);

    uint8_t *outData = static_cast<uint8_t *>(outZeroMqMessage.data());

    for(uint32_t i = 0; i < messageLength; i ++)
    {
        outData[i] = inputData[i];
        //printf(" %02x  %02x \n", tmpData[i],  outData[i]);
    }

}

void ServerWorker::receiveMessage(zmq::socket_t &inSocket, ServerMessage& outMessage)
{
    zmq::message_t zeroMqMsg;

    // Receive message code
    inSocket.recv(&zeroMqMsg);

    const char *tmpBuffer = static_cast<const char*>(zeroMqMsg.data());
    string msgCode = string(tmpBuffer, tmpBuffer + zeroMqMsg .size());

    cout << "DEBUG: Message Code = " << msgCode << endl;


    // Clean it
    if (zeroMqMsg.more() == true)
    {
        // Receive a message
        zeroMqMsg.rebuild();
        inSocket.recv(&zeroMqMsg);

        // Extract the message data only
        extractMessage(zeroMqMsg, outMessage);

        outMessage.setOperationCodeAsInt( std::atoi(msgCode.c_str()) );
    }
    else
    {
        outMessage.setOperationCode( OperationCodeEnum::CODE_NONE );
    }
}


void ServerWorker::sendMessage(zmq::socket_t &inSocket, const ServerMessage& inMessage)
{
    // Send message code
    string msgCode = const_cast<ServerMessage&>(inMessage).getOperationCodeAsString();

    zmq::message_t zeroMqMsg{msgCode.data(), msgCode.size()};

    inSocket.send(zeroMqMsg, ZMQ_SNDMORE);

    // Send message data
    zeroMqMsg.rebuild(const_cast<ServerMessage&>(inMessage).getData().data(),
                      const_cast<ServerMessage&>(inMessage).getDataSize());

    inSocket.send(zeroMqMsg);
}

*/

/*
std::string recvAsString(int flags =0)
{
    zmq::message_t message;
    if(!socket_t::recv(&message, flags))
        throw error_t();

    const char* base = static_cast<const char*>(message.data());
    return std::string(base, base + message.size());
}
*/


// If I use DEALER, then each client shall have an id
/*
// Receive the identifier
zmq::message_t  msgIdentifier;

worker_.recv(&msgIdentifier);

const char *tmpIdentifier = static_cast<const char*>(msgIdentifier.data());
string msgId = string(tmpIdentifier, tmpIdentifier + msgIdentifier .size());

cout << "Identifier = " << msgId << endl;


// Clean it
msgIdentifier.rebuild(0);
worker_.send(&msgIdentifier, ZMQ_SNDMORE);
*/



/*
// Receive the operation code
inZeroMqMsg.rebuild();
worker_.recv(&inZeroMqMsg);

const char *tmpBuffer = static_cast<const char*>(inZeroMqMsg.data());
string msgCode = string(tmpBuffer, tmpBuffer + inZeroMqMsg .size());

cout << "DEBUG: Message Code = " << msgCode << endl;
outputMessage.setOperationCodeAsInt( std::atoi(msgCode.c_str()) );


// Clean it
if (inZeroMqMsg.more() == true)
{
    // Receive a message
    inZeroMqMsg.rebuild();
    worker_.recv(&inZeroMqMsg);

    // Extract the message data only
    ServerMessage  newMessage;

    extractMessage(inZeroMqMsg, newMessage);

    // Process the message
    // Convert to first and second level and process the message
    outputMessage = processor_->processMessage(newMessage, *this);
}
else
{
    // A multipart message has failed
    processor_->createReply(outputMessage, -1, "Invalida multipart message received");
}
*/
/*
//cout << "    ZeroMQ size: " << inZeroMqMessage.size() << endl;

vector<uint8_t>  outData(inZeroMqMessage.size() - 2);

uint8_t *inputData = static_cast<uint8_t *>(inZeroMqMessage.data());

// The first two bytes contain the message code
uint32_t  messageCode = (inputData[1] << 8) | inputData[0];

outMessage.setOperationCodeAsInt(messageCode);


//cout << "   EXTRACT" << endl;
for(uint32_t i = 2; i < inZeroMqMessage.size(); i ++)
{
    outData[i - 2] = inputData[i];
    //printf(" %02x  %02x \n", tmpData[i],  outData[i]);
}

outMessage.setData(outData);

//cout << "   outMessage = " << outMessage.toString() << endl;
*/

/*
vector<uint8_t>  inputData{inMessage.getData()};

// Add two bytes for the message code
uint32_t  messageLength = inMessage.getDataSize() + 2;

outZeroMqMessage.rebuild(messageLength);

uint8_t *outData = static_cast<uint8_t *>(outZeroMqMessage.data());

// Set the message code in the first two bytes. Byte 0 = LSB, Byte 1 = MSB
// Use first 16bits
uint32_t  messageCode = inMessage.getOperationCodeAsInt() & 0xFFFF;

outData[0] = messageCode & 0xFF;
outData[1] = (messageCode >> 8) & 0xFF;


//cout << "  CONVERT" << endl;
for(uint32_t i = 2; i < messageLength; i ++)
{
    outData[i] = inputData[i - 2];
    //printf(" %02x  %02x \n", tmpData[i],  outData[i]);
}
*/
