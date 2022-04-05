/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __MESSAGE_UTILS_H__
#define __MESSAGE_UTILS_H__

#include <vector>
#include <string>

using namespace std;

#include <avro/Decoder.hh>
#include <avro/Encoder.hh>

#include <zmq.hpp>

#include "AvroTypes.h"

#include "CommonTypes.h"
#include "ServerMessage.h"


// -- FUNCTIONS ---------------------------------------------------
// ----------------------------------------------------------------

void createReply(ServerMessage& outMessage, const int inErrorCode, const string &inErrorMessage);

void createReply(ServerMessage& outMessage, const IW::MsgReturnData& inReturnData);

string extractBody(unique_ptr<avro::OutputStream> &inAvroOutput);

VectorUint8 extractBodyVector(unique_ptr<avro::OutputStream> &inAvroOutput);



// ZeroMQ
void extractMessage(zmq::message_t &inZeroMqMessage, ServerMessage &outMessage);

void convertMessage(ServerMessage& inMessage, zmq::message_t &outZeroMqMessage);

void receiveMessage(zmq::socket_t &inSocket, ServerMessage& outMessage);

void sendMessage(zmq::socket_t &inSocket, const ServerMessage& inMessage);



// -- TEMPLATES ---------------------------------------------------
// ----------------------------------------------------------------


// Convert T object to string
template<class T>
string buildMessage(const T &inAvroMsg)
{
    string output;

    unique_ptr<avro::OutputStream> avroOutput = avro::memoryOutputStream();

    // Create a binary encoder
    avro::EncoderPtr avroEncoder = avro::binaryEncoder();

    // Encode the message - AVRO
    avroEncoder->init(*avroOutput);
    avro::encode(*avroEncoder, inAvroMsg);

    avroEncoder->flush();

    output = extractBody(avroOutput);

    return output;
}

// Convert string to T object
template<class T>
void extractMessage(string &inBody, T &output)
{
    // Decoded message. Avro message coded in binary
    //AVRO_DECL std::auto_ptr<InputStream> memoryInputStream(const uint8_t* data, size_t len);
    unique_ptr<avro::InputStream> avroInput = avro::memoryInputStream(reinterpret_cast<const uint8_t*>(inBody.c_str()),
                                                                      inBody.size() );

    // Create a binary decoder
    avro::DecoderPtr avroDecoder = avro::binaryDecoder();

    avroDecoder->init(*avroInput);

    avro::decode(*avroDecoder, output);
}


// Convert array of bytes into a T object
template<class T>
void extractMessageVector(VectorUint8 &inBody, T &output)
{
    // Decoded message. Avro message coded in binary
    //AVRO_DECL std::auto_ptr<InputStream> memoryInputStream(const uint8_t* data, size_t len);
    unique_ptr<avro::InputStream> avroInput = avro::memoryInputStream(reinterpret_cast<const uint8_t*>(inBody.data()),
                                                                      inBody.size() );

    // Create a binary decoder
    avro::DecoderPtr avroDecoder = avro::binaryDecoder();

    avroDecoder->init(*avroInput);

    avro::decode(*avroDecoder, output);
}

// Convert array of bytes into a T object
template<class T>
void extractMessageVector(const VectorUint8 &inBody, T &output)
{
    // Decoded message. Avro message coded in binary
    //AVRO_DECL std::auto_ptr<InputStream> memoryInputStream(const uint8_t* data, size_t len);
    unique_ptr<avro::InputStream> avroInput = avro::memoryInputStream(inBody.data(), inBody.size() );

    // Create a binary decoder
    avro::DecoderPtr avroDecoder = avro::binaryDecoder();

    avroDecoder->init(*avroInput);

    avro::decode(*avroDecoder, output);
}

// Convert T object to vector message
template<class T>
VectorUint8 buildMessageVector(const T &inAvroMsg)
{
    VectorUint8 output;

    unique_ptr<avro::OutputStream> avroOutput = avro::memoryOutputStream();

    // Create a binary encoder
    avro::EncoderPtr avroEncoder = avro::binaryEncoder();

    // Encode the message - AVRO
    avroEncoder->init(*avroOutput);
    avro::encode(*avroEncoder, inAvroMsg);

    avroEncoder->flush();

    output = extractBodyVector(avroOutput);

    return output;
}



#endif // __MESSAGE_UTILS_H__
