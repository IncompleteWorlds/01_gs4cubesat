/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <memory>

using namespace std;

#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace boost;
using namespace boost::asio::ip;

//using boost::asio::ip::tcp;

#include "CommonTypes.h"


// COMPILE WITH:
//
//   make -f makefile_old  gs_simulator
//




// Read a frame from the input file taking into account the type of layer to be used
//
void readFrame(ifstream& inInputFile, string& inFrameType, RawFrameType& outFrame)
{
    bool useDelimiter = false;
    bool useLength = false;
    uint8_t delimiter = 0;

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
        char tmpBuffer[2];

        // Read frame length
        inInputFile.read(tmpBuffer, 2);

        // Big endian
        frameLength = (tmpBuffer[0] << 8) + tmpBuffer[1];

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

    if(argc < 4) {
        cout << "ERROR: Incorrect number of parameters" << endl;
        cout << endl;
        cout << "Usage: simulate_gs   type    input_binary_file    server_name   port" << endl;
        cout << endl;
        cout << "Where:" << endl;
        cout << "   type - kiss, ax25, csp" << endl;
    } else {
        string fileName{ argv[2] };
        string layerType{ argv[1] };
        string serverName{ argv[3] };
        string portNumber{ argv[4] };
        
        try {
         
            // Open file
            ifstream inputFile(fileName, ios::binary);

            if(inputFile.good() == true) {
                // Open URL
                asio::io_service io_service;

                tcp::resolver resolver(io_service);

                // A resolver takes a query object and turns it into a list of endpoints.
                // We construct a query using the name of the server, specified in argv[1],
                // and the name of the service, in this case "daytime".
                tcp::resolver::query  query("", "");
                
                if (portNumber.empty() == false) {
                    tcp::resolver::query tmpQuery(serverName, "gs_sim");
                    
                    query = std::move(tmpQuery);
                } else {
                    tcp::resolver::query tmpQuery(serverName, portNumber);
                    
                    query = std::move(tmpQuery);
                }

                // The list of endpoints is returned using an iterator of type ip::tcp::resolver::iterator.
                // A default constructed ip::tcp::resolver::iterator object can be used as an end iterator.
                tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

                // Now we create and connect the socket.
                // The list of endpoints obtained above may contain both IPv4 and IPv6 endpoints,
                // so we need to try each of them until we find one that works.
                // This keeps the client program independent of a specific IP version.
                // The boost::asio::connect() function does this for us automatically.
                tcp::socket socket(io_service);

                //boost::asio::connect(socket, endpoint_iterator);
                asio::connect(socket, endpoint_iterator);

                // Read frames
                RawFrameType rawFrame;

                readFrame(inputFile, layerType, rawFrame);

                while(inputFile.eof() == false) {
                    // Debug
                    cout << endl;
                    cout << "Raw frame: " << vectorToHexString(rawFrame, false) << endl;
                    cout << endl;

                    // Write the frame
                    system::error_code ignored_error;
                    
                    asio::write(socket, asio::buffer(rawFrame), ignored_error);
                    
                    if (ignored_error) {
                        throw boost::system::system_error(ignored_error); // Some other error.
                    }

                    // Read next frame
                    readFrame(inputFile, layerType, rawFrame);
                }
            } else {
                cout << "ERROR: Opening file: " << fileName << endl;
            }

        } catch(std::exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
    }
    
    return 0;
}

