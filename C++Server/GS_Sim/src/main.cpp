/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include <map>
#include <array>

using namespace std;

#include <boost/asio.hpp>

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include "json11.hpp"
#include "CommonTypes.h"

/*
 
# log4cpp.properties

log4cpp.rootCategory=DEBUG, rootAppender
log4cpp.category.sub1=DEBUG, A1, A2
log4cpp.category.sub1.sub2=DEBUG, A3

log4cpp.appender.rootAppender=ConsoleAppender
log4cpp.appender.rootAppender.layout=PatternLayout
log4cpp.appender.rootAppender.layout.ConversionPattern=%d [%p] %m%n 

log4cpp.appender.A1=FileAppender
log4cpp.appender.A1.fileName=A1.log
log4cpp.appender.A1.layout=BasicLayout

log4cpp.appender.A2=FileAppender
log4cpp.appender.A2.threshold=WARN
log4cpp.appender.A2.fileName=A2.log
log4cpp.appender.A2.layout=PatternLayout
log4cpp.appender.A2.layout.ConversionPattern=%d [%p] %m%n 

log4cpp.appender.A3=RollingFileAppender
log4cpp.appender.A3.fileName=A3.log
log4cpp.appender.A3.maxFileSize=200
log4cpp.appender.A3.maxBackupIndex=1
log4cpp.appender.A3.layout=PatternLayout
log4cpp.appender.A3.layout.ConversionPattern=%d [%p] %m%n 
  
*/




map<string, string> configValues;

const string KEY_INPUT_FILE_NAME = "input_file_name";
const string KEY_TCP_ADDRESS = "tcp_address";
const string KEY_TCP_PORT = "tcp_port";
const string KEY_FRAME_SIZE = "frame_size";
const string KEY_DELAY = "delay_ms";
const string KEY_FRAME_TYPE = "frame_type";
const string KEY_LOG4CPP_PROPERTIES = "log4cpp_properties";


bool loadConfiguration(string& inFileName)
{
    bool output{ false };

    // Open file
    ifstream configFile(inFileName);

    if(configFile.is_open() == false) {
        // Error
        cout << "ERROR: While opening configuration file: " << inFileName << endl;
    } else {
        // Read the whole file as a string
        string inputBuffer;
        string tmpLine;

        while(configFile.eof() == false) {
            getline(configFile, tmpLine);
            inputBuffer += tmpLine;

            // cout << tmpLine << endl;
        }

        // TODO: Add Log manager component. Log4cpp
        // cout << "DEBUG: Config file: " << inputBuffer << endl;
        configFile.close();

        // Read key values and store them
        json11::Json tmpKeyValues;
        string errorMessage;

        tmpKeyValues = json11::Json::parse(inputBuffer, errorMessage, json11::JsonParse::STANDARD);

        if(errorMessage.empty() == false) {
            cout << "ERROR: Parsing config JSON file. errorMessage: " << errorMessage << endl;
        } else {
            // Extract keys
            configValues[KEY_INPUT_FILE_NAME] = tmpKeyValues[KEY_INPUT_FILE_NAME].string_value();
            configValues[KEY_TCP_ADDRESS] = tmpKeyValues[KEY_TCP_ADDRESS].string_value();
            configValues[KEY_TCP_PORT] = tmpKeyValues[KEY_TCP_PORT].string_value();
            configValues[KEY_FRAME_SIZE] = tmpKeyValues[KEY_FRAME_SIZE].string_value();
            configValues[KEY_DELAY] = tmpKeyValues[KEY_DELAY].string_value();
            configValues[KEY_FRAME_TYPE] = tmpKeyValues[KEY_FRAME_TYPE].string_value();
            configValues[KEY_LOG4CPP_PROPERTIES] = tmpKeyValues[KEY_LOG4CPP_PROPERTIES].string_value();
            
            output = true;
        }
    }

    return output;
}

// Read a frame from the input file taking into account the type of layer to be used
//
void readFrame(ifstream& inInputFile, RawFrameType& outFrame)
{
    bool useDelimiter = false;
    bool useLength = false;
    uint8_t delimiter = 0;
    string inFrameType = configValues[KEY_FRAME_TYPE];

    if(inFrameType == "kiss") {
        delimiter = 0xC0;
        useDelimiter = true;
    } else if(inFrameType == "ax25") {
        delimiter = 0x7E;
        useDelimiter = true;
    } else if(inFrameType == "csp") {
        useLength = true;
    }

    // Clear input buffer
    outFrame.clear();

    // Read the frame delimited by delimiters
    char cc;
    uint8_t c;

    if(useDelimiter == true) {
        // Look for first delimiter
        inInputFile.read(&cc, 1);
        // Convert from char to uint8_t
        c = cc;
        while(inInputFile.eof() == false && c != delimiter) {
            inInputFile.read(&cc, 1);
            c = cc;
        }

        if(inInputFile.eof() == false) {
            // Add delimiter
            outFrame.push_back(c);

            // Copy data until the other delimiter is found
            inInputFile.read(&cc, 1);
            c = cc;
            while(inInputFile.eof() == false && c != delimiter) {
                outFrame.push_back(c);
                inInputFile.read(&cc, 1);
                c = cc;
            }

            // Add delimiter
            outFrame.push_back(c);
        }
    }

    if(useLength == true) {
        uint16_t frameLength;

        if(inFrameType == "csp") {
            char tmpBuffer[2];

            // Read frame length
            inInputFile.read(tmpBuffer, 2);

            // Big endian
            frameLength = (tmpBuffer[0] << 8) + tmpBuffer[1];
        } else {
            frameLength = atoi(configValues[KEY_FRAME_SIZE].c_str());
        }

        // Read the frame
        for(uint i = 0; i < frameLength && inInputFile.eof() == false; i++) {
            inInputFile.read(&cc, 1);
            c = cc;

            outFrame.push_back(c);
        }
    }
}

int main(int argc, char* argv[])
{

    cout << "Ground Station Simulator" << endl;
    cout << "Incomplete Worlds (c) 2017 " << endl;
    cout << endl;
    
    if(argc < 2) {
        cout << "ERROR: Incorrect number of parameters" << endl;
        cout << endl;
        cout << "Usage: SendFrames   config_file.json" << endl;
        cout << endl;
        cout << "Config file content:" << endl;
        cout << "   input file name and path" << endl;
        cout << "   tcp address, port" << endl;
        cout << "   framesize" << endl;
        cout << "   frame_type" << endl;
        cout << "   delay between frames in milliseconds" << endl;
    } else {
        // Load configuration
        string configFileName{ argv[1] };

        if(loadConfiguration(configFileName) == true) {
            // Log file
            string initFileName = configValues[KEY_LOG4CPP_PROPERTIES];
    
            log4cpp::PropertyConfigurator::configure(initFileName);

            log4cpp::Category& root = log4cpp::Category::getRoot();

            root.info("Ground Station Simulator");
            root.info("Incomplete Worlds (c) 2017");

            string fileName{ configValues[KEY_INPUT_FILE_NAME] };
            int delayInMilliSeconds{ atoi(configValues[KEY_DELAY].c_str()) };

            // Open file
            ifstream inputFile(fileName, ios::binary);

            if(inputFile.good() == true) 
            {
                try 
                {
                    root.info("Input file correclty opened");
                    
                    // Open socket
                    // string tmpAddress{ configValues[KEY_TCP_ADDRESS] };

                    // GS port
                    int port = atoi(configValues[KEY_TCP_PORT].c_str());

                    boost::asio::io_service my_io_service;

                    /*
                    ip::tcp::resolver resolver(my_io_service);
                    ip::tcp::resolver::query query(tmpAddress, port);

                    ip::tcp::resolver::iterator iter = resolver.resolve(query);

                    ip::tcp::endpoint my_endpoint = *iter;
                    */

                    // ip::address_v4 my_address = ip::address_v4::from_string(tmpAddress);
                    
                    root.info("Port " + to_string(port));

                    boost::asio::ip::tcp::endpoint my_endpoint(boost::asio::ip::tcp::v4(), port);

                    boost::asio::ip::tcp::socket gsSocket(my_io_service);

                    // Accept incoming connections
                    boost::asio::ip::tcp::acceptor acceptor(my_io_service, my_endpoint);

                    root.info("Waiting for incoming connections ...");
                    acceptor.accept(gsSocket);
                    root.debug("Connected");

                    // First frame
                    RawFrameType currentFrame;

                    readFrame(inputFile, currentFrame);
                    root.debug("Frame: " + vectorToString(currentFrame));

                    //
                    //
                    //                int frameSize{ atoi(configValues[KEY_FRAME_SIZE].c_str()) };
                    //
                    //                // Add some margin
                    //                std::vector<char> currentFrame(frameSize + 32);
                    //
                    //                // Read first frame
                    //                inputFile.read(currentFrame.data(), frameSize);

                    while(inputFile.eof() == false) 
                    {
                        // Send frame
                        boost::system::error_code my_error;

                        root.debug("Sending frame");
                        boost::asio::write(gsSocket, boost::asio::buffer(currentFrame), my_error);

                        if(my_error) 
                        {
                            cout << "ERROR: " << boost::system::system_error(my_error).what() << endl;
                            break;
                        }

                        // If delay, sleep
                        try 
                        {
                            this_thread::sleep_for(chrono::seconds(delayInMilliSeconds));
                        } catch(...) 
                        {
                        }

                        // Read next frame
                        readFrame(inputFile, currentFrame);
                        root.debug("Frame: " + vectorToString(currentFrame));
                    }

                    // Close socket
                    gsSocket.close();

                    // Close file
                    inputFile.close();

                } catch(std::exception& e) 
                {
                    cout << "Exception: " << e.what() << endl;
                }
            } 
            else 
            {
                cout << "ERROR: Opening file: " << fileName << endl;
            }
            
            log4cpp::Category::shutdown();
        } 
        else 
        {
            cout << "ERROR: Opening configuration file" << endl;
        }
    }
    
    

    return 0;
}
