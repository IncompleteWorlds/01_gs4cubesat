/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "LogManager.h"
#include "MessageUtils.h"



// Retrieve a message as a sequence of bytes (inside of a string)
string extractBody(unique_ptr<avro::OutputStream> &inAvroOutput)
{
    string output;

    // Flush remaining bytes. encoder->flush() is needed
    //this->avroEncoder->flush();
    //inAvroOutput->flush();

    // To be obtained after flush
    size_t msgLen = inAvroOutput->byteCount();

    if (msgLen > 0) {
        // Extract bytes
        std::unique_ptr<avro::InputStream> avroInput = avro::memoryInputStream(*inAvroOutput);

        // Copy encoded bytes to tmpAvroBuffer
        avro::StreamReader avroReader(*avroInput);
        VectorUint8 tmpAvroBuffer(msgLen);

        avroReader.fill();
        avroReader.readBytes(&tmpAvroBuffer[0], msgLen);

        // Binary message
        //proton::binary  tmpBinaryBuffer(msgLen);

        //for(uint32_t i = 0; i < msgLen; i++) {
        //    tmpBinaryBuffer[i] = tmpAvroBuffer[i];
        //}

        //string tmpBuffer{ tmpBinaryBuffer.begin(), tmpBinaryBuffer.end() };

        //output = move(tmpBuffer);
        output = "tmpAvroBuffer";
    } else {
        LogManager::getInstance().error("Error coding Avro message. No data. Message not sent");
        //cout << "ERROR: While coding Avro message. No data. Message not send" << endl;
    }

    return output;
}

// Retrieve a message as a sequence of bytes (inside of a string)
VectorUint8 extractBodyVector(unique_ptr<avro::OutputStream> &inAvroOutput)
{
    VectorUint8 output;

    // Flush remaining bytes. encoder->flush() is needed
    //this->avroEncoder->flush();
    //inAvroOutput->flush();

    // To be obtained after flush
    size_t msgLen = inAvroOutput->byteCount();

    if (msgLen > 0)
    {
        // Extract bytes
        std::unique_ptr<avro::InputStream> avroInput = avro::memoryInputStream(*inAvroOutput);

        // Copy encoded bytes to tmpAvroBuffer
        avro::StreamReader avroReader(*avroInput);

        output.resize(msgLen);

        avroReader.fill();
        avroReader.readBytes(&output[0], msgLen);
    }
    else
    {
        LogManager::getInstance().error("Error coding Avro message. No data. Message not sent");
        //cout << "ERROR: While coding Avro message. No data. Message not send" << endl;
    }

    return output;
}


void createReply(ServerMessage& outMessage, const int inErrorCode, const string &inErrorMessage)
{
    IW::MsgReturnData   returnData;

    returnData.errorCode    = inErrorCode;
    returnData.errorMessage = inErrorMessage;

    VectorUint8 tmpAvroMessage = buildMessageVector<IW::MsgReturnData>(returnData);

    outMessage.setOperationCode(OperationCodeEnum::CODE_REPLY_MESSAGE);
    outMessage.setData(tmpAvroMessage);
}

void createReply(ServerMessage& outMessage, const IW::MsgReturnData& inReturnData)
{
    VectorUint8 tmpAvroMessage = buildMessageVector<IW::MsgReturnData>(inReturnData);

    outMessage.setOperationCode(OperationCodeEnum::CODE_REPLY_MESSAGE);
    outMessage.setData(tmpAvroMessage);
}


// -- ZEROMQ ----------------------------

// Convert the received message from ZeroMQ to ServerMessage
void extractMessage(zmq::message_t &inZeroMqMessage, ServerMessage& outMessage)
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
void convertMessage(ServerMessage& inMessage, zmq::message_t &outZeroMqMessage)
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

void receiveMessage(zmq::socket_t &inSocket, ServerMessage& outMessage)
{
    LogManager::getInstance().debug("Waiting for a message ");
 
    zmq::message_t zeroMqMsg;

    // Receive message code
    inSocket.recv(&zeroMqMsg);

    const char *tmpBuffer = static_cast<const char*>(zeroMqMsg.data());
    string msgCode = string(tmpBuffer, tmpBuffer + zeroMqMsg .size());

    LogManager::getInstance().debug("   RECEIVED Message. Code: " + msgCode);

    // Clean it
    if (zeroMqMsg.more() == true)
    {
        // Receive a message
        zeroMqMsg.rebuild();
        inSocket.recv(&zeroMqMsg);
        
        // Extract the message data only
        extractMessage(zeroMqMsg, outMessage);
        //LogManager::getInstance().debug("DATA: " + outMessage.toString());

        outMessage.setOperationCodeAsInt( std::atoi(msgCode.c_str()) );
    }
    else
    {
        outMessage.setOperationCode( OperationCodeEnum::CODE_NONE );
    }
}


void sendMessage(zmq::socket_t &inSocket, const ServerMessage& inMessage)
{
    LogManager::getInstance().debug("Sending a message");
    
    // Send message code
    string msgCode = const_cast<ServerMessage&>(inMessage).getOperationCodeAsString();

    zmq::message_t zeroMqMsg{msgCode.data(), msgCode.size()};

    LogManager::getInstance().debug("   SENDING Message. Code: " + msgCode);
    inSocket.send(zeroMqMsg, ZMQ_SNDMORE);

    // Send message data
    zeroMqMsg.rebuild(const_cast<ServerMessage&>(inMessage).getData().data(),
                      const_cast<ServerMessage&>(inMessage).getDataSize());

    //LogManager::getInstance().debug("DATA: " + const_cast<ServerMessage&>(inMessage).toString());
    inSocket.send(zeroMqMsg);
}

