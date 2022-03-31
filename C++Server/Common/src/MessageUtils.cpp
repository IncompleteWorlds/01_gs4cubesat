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
        output = vectorToString(tmpAvroBuffer);
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

    // Receive Message Code and Authorization Token at the same time.
    // Format: Code.Auth_Token
    inSocket.recv(&zeroMqMsg);

    const char *tmpBuffer = static_cast<const char*>(zeroMqMsg.data());
    string msgCodeAuth = string(tmpBuffer, tmpBuffer + zeroMqMsg.size());

    //LogManager::getInstance().debug("   RECEIVED Message. Code: " + msgCodeAuth);

    // Clean it
    if (zeroMqMsg.more() == true)
    {
        // Receive a message
        zeroMqMsg.rebuild();
        inSocket.recv(&zeroMqMsg);
        
        // Extract the message data only
        extractMessage(zeroMqMsg, outMessage);
        //LogManager::getInstance().debug("DATA: " + outMessage.toString());

        outMessage.extractCodeAndAuthToken(msgCodeAuth);
    }
    else
    {
        outMessage.setOperationCode( OperationCodeEnum::CODE_NONE );
        outMessage.setAuthorizationToken("");
    }
}

void sendMessage(zmq::socket_t &inSocket, const ServerMessage& inMessage)
{
    LogManager::getInstance().debug("Sending a message");
    
    // Send Message Code and Authorization Token at the same time.
    // Format: Code.Auth_Token
    string tmpBuffer = const_cast<ServerMessage&>(inMessage).getCodeAndAuthToken();

    zmq::message_t zeroMqMsg{tmpBuffer.data(), tmpBuffer.size()};

    LogManager::getInstance().debug("   SENDING Message. Code: " + tmpBuffer);
    inSocket.send(zeroMqMsg, ZMQ_SNDMORE);

    // Send message data
    zeroMqMsg.rebuild(const_cast<ServerMessage&>(inMessage).getData().data(),
                      const_cast<ServerMessage&>(inMessage).getDataSize());

    //LogManager::getInstance().debug("DATA: " + const_cast<ServerMessage&>(inMessage).toString());
    inSocket.send(zeroMqMsg);
}


// -- NANOMSG ----------------------------
void extractMessage(nng::msg &inMqMessage, ServerMessage &outMessage)
{        
    vector<uint8_t>  outData(inMqMessage.body().size());
    
    auto inputData = inMqMessage.body().data<uint8_t>();
    //uint8_t *inputData = static_cast<uint8_t *>(inZeroMqMessage.data());

    for(uint32_t i = 0; i < inMqMessage.body().size(); i ++)
    {
        outData[i] = inputData[i];
        //printf(" %02x  %02x \n", tmpData[i],  outData[i]);
    }

    outMessage.setData(outData);
}

void convertMessage(ServerMessage& inMessage, nng::msg &outMqMessage)
{
    vector<uint8_t>  inputData{inMessage.getData()};
    //uint32_t  messageLength = inMessage.getDataSize();

    // Clear the message
    outMqMessage.body().clear();
    //outMqMessage.rebuild(messageLength);

    //uint8_t *outData = static_cast<uint8_t *>(outMqMessage.data());
    auto outData = outMqMessage.body().data<uint8_t>();

    for(uint32_t i = 0; i < inMessage.getDataSize(); i ++)
    {
        outData[i] = inputData[i];
        //printf(" %02x  %02x \n", tmpData[i],  outData[i]);
    }
}

void receiveMessage(nng::socket &inSocket, ServerMessage& outMessage)
{
    LogManager::getInstance().debug("Waiting for a message ");
 
    try
    {
        // Read the message
        nng::msg mqMsg;

        mqMsg = inSocket.recv_msg();
        
        // Message format
        // MsgCode (16 bits), Len Auth Token (16 bits), Token (256 bytes max), Rest of message (2 or 4 KB - TBC)
        
        // Read message code
        auto msgCode = mqMsg.body().trim_u16();
        
        // Read Authorization Token length
        auto authTokenLen = mqMsg.body().trim_u16();
        
        char *tmpBuffer = mqMsg.body().data<char>();
        
        // Read Authorization Token
        string authToken(authTokenLen, ' ');
        uint  i;
        
        for(i = 0; i < authTokenLen; i ++)
        {
            authToken[i] = tmpBuffer[i];
        }
        LogManager::getInstance().debug("   RECEIVED Message. Auth Token: " + authToken);
        
        // Read rest of message
        auto msgLen = mqMsg.body().size();
        LogManager::getInstance().debug("   RECEIVED Message. Msg Len: " + to_string(msgLen));
        
        vector<uint8_t>  msgBuffer(msgLen);
        uint j{0};
        
        for(j = 0; i < msgLen; i ++, j ++)
        {
            msgBuffer[j] = tmpBuffer[i];
        }
        
        outMessage.setOperationCodeAsInt(msgCode);
        outMessage.setAuthorizationToken(authToken);
        outMessage.setData(msgBuffer);
    }
    catch( const nng::exception& e ) 
    {
        // who() is the name of the nng function that produced the error
        // what() is a description of the error code
        LogManager::getInstance().error(string(e.who()) + " " + string(e.what()));
    }
}

void sendMessage(nng::socket &inSocket, const ServerMessage& inMessage)
{
    LogManager::getInstance().debug("Sending a message");
     
    try
    {
        // Message format
        // MsgCode (16 bits), Len Auth Token (16 bits), Token (256 bytes max), Rest of message (2 or 4 KB - TBC)

        nng::msg mqMsg{static_cast<int>(0)};
        
        // Add the Operation Code
        mqMsg.body().append_u16( static_cast<uint16_t>(inMessage.getOperationCodeAsInt()) );
        
        string authToken = inMessage.getAuthorizationToken();
        
        // Add Authentication Token length
        mqMsg.body().append_u16( authToken.size() );
        
        nng::view  tmpAuthToken{ authToken.data(), authToken.size() };
        
        // Add Authentication Token
        mqMsg.body().append(tmpAuthToken);
        
        // Add the message
        nng::view  tmpMsg{ const_cast<ServerMessage&>(inMessage).getData().data(), 
                           const_cast<ServerMessage&>(inMessage).getDataSize() };
        
        mqMsg.body().append(tmpMsg);
        
        inSocket.send(std::move(mqMsg));
        
        LogManager::getInstance().debug("Message sent");
    }
    catch( const nng::exception& e ) 
    {
        // who() is the name of the nng function that produced the error
        // what() is a description of the error code
        LogManager::getInstance().error(string(e.who()) + " " +  string(e.what()));
    }
}




