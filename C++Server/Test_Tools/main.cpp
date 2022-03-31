/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */
 
 
 /*
  * THIS TOOL IS INCOMPLETE
  * A GENERIC JSON CANNOT BE CREATED WITHOUT CREATING A MESSAGE
  * STRUCTURE BEFOREHAND. THUS, IT DOES NOT WORK 
  * 
  */

#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

#include <avro/Decoder.hh>
#include <avro/Encoder.hh>

#include <zmq.hpp>

void readFile(const string& inFileName, string& textMessage)
{
    // Open file
    ifstream inputFile(inFileName.c_str(), ios:: text);

    if(inputFile.is_open() == false) {
        // Error
        cout << "ERROR: Opening input message file: " << inFileName << endl;
    } else {
        // Read the whole file as a string
        string tmpLine;

        while(inputFile.eof() == false) {
            getline(inputFile, tmpLine);
            textMessage += tmpLine;

            // cout << tmpLine << endl;
        }
        
        // Close the file
        inputFile.close();
    }
}


int main(int argc, char* argv[])
{

    cout << "SendMessage" << endl;
    cout << "Incomplete Worlds (c) 2017 " << endl;
    cout << endl;

    if(argc < 4) {
        cout << "ERROR: Incorrect number of parameters" << endl;
        cout << endl;
        cout << "Usage: SendMessage message_file.json   IP_address:port" << endl;
        cout << endl;
    } else {
        // Read the input file. Message coded in JSON
        string messageFileName{ argv[1] };
        string ipAddress{ argv[2] };

        // Read the file and store in a string
        string textMessage;

        readFile(messageFileName, textMessage);

        // Read schema
        //avro::ValidSchema inputSchema;

        // Encode in Avro
        unique_ptr<avro::OutputStream> avroOutput = avro::memoryOutputStream();

        // Create a binary encoder
        avro::EncoderPtr avroEncoder = avro::binaryEncoder();

        // Encode the message - AVRO
        avroEncoder->init(*avroOutput);
        avro::encode(*avroEncoder, inAvroMsg);

        avroEncoder->flush();

        // Create a ZMQ socket
        zmq::context_t context_{ 1 };
        zmq::socket_t socket_(context_, ZMQ_REQ);

        socket_.connect(ipAddress);

        // Create message
        zmq::message_t outputMessage;

        AVRO_DECL DecoderPtr jsonDecoder(const ValidSchema& schema);

        vector<uint8_t> outData(textMessage.size());

        for(uint32_t i = 0; i < textMessage.size(); i++) {
            outData[i] = textMessage[i];
            // printf(" %02x  %02x \n", textMessage[i],  outData[i]);
        }

        // Send the message
        socket_.send(outputMessage);

        // Wait for reply
        zmq::message_t replyMessage;

        socket_.recv(replyMessage);

        // Show the answer
    }

    return 0;
}
