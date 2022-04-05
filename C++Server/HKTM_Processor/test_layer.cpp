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

#include "KissLayer.h"
#include "Ax25Layer.h"
#include "CspLayer.h"
#include "AvroTypes.h"
#include "CommonTypes.h"



shared_ptr<BaseLayer> CreateLayer(string& inType)
{
    shared_ptr<BaseLayer> output;

    if (inType == "kiss")
    {
        output = shared_ptr<BaseLayer>( new KissLayer() );
    }
    else if (inType == "ax25")
    {
        output = shared_ptr<BaseLayer>( new Ax25Layer() );
    }
    else if (inType == "csp")
    {
        output = shared_ptr<BaseLayer>( new CspLayer() );
    }

    return output;
}

void ReadFrame(ifstream& inInputFile, string& inFrameType, RawFrameType &outFrame)
{
    bool     useDelimiter = false;
    bool     useLength = false;
    uint8_t  delimiter = 0;

    if (inFrameType == "kiss")
    {
        delimiter = 0xC0;
        useDelimiter = true;
    }
    else if (inFrameType == "ax25")
    {
        delimiter = 0x7E;
        useDelimiter = true;
    }
    else if (inFrameType == "csp")
    {
        useLength = true;
    }

    // Clear input buffer
    outFrame.clear();



    // Read the frame delimited by delimiters
    char cc;
    uint8_t c;

    if (useDelimiter == true)
    {
        // Look for first delimiter
        inInputFile.read(&cc, 1);
        // Convert from char to uint8_t
        c = cc;
        while(inInputFile.eof() == false && c != delimiter)
        {
            inInputFile.read(&cc, 1);
            c = cc;
        }

        if (inInputFile.eof() == false)
        {
            // Add delimiter
            outFrame.push_back(c);

            // Copy data until the other delimiter is found
            inInputFile.read(&cc, 1);
            c = cc;
            while(inInputFile.eof() == false && c != delimiter)
            {
                outFrame.push_back(c);
                inInputFile.read(&cc, 1);
                c = cc;
            }

            // Add delimiter
            outFrame.push_back(c);
        }
    }

    if (useLength == true)
    {
        uint16_t  frameLength;
        char      tmpBuffer[2];

        // Read frame length
        inInputFile.read(tmpBuffer, 2);

        // Big endian
        frameLength = (tmpBuffer[0] << 8) + tmpBuffer[1];

        for(uint i = 0; i < frameLength && inInputFile.eof() == false; i ++)
        {
            inInputFile.read(&cc, 1);
            c = cc;

            outFrame.push_back(c);
        }
    }
}

int main(int argc, char *argv[])
{
    cout << "Ground Station Simulator" << endl;
    cout << "Incomplete Worlds (c) 2017 " << endl;
    cout << endl;

    if (argc < 3)
    {
        cout << "ERROR: Incorrect number of parameters" << endl;
        cout << endl;
        cout << "Usage: test_layer   type    input_binary_file    [output_binary_file]" << endl;
        cout << endl;
        cout << "Where:" << endl;
        cout << "   type - kiss, ax25, csp" << endl;
    }
    else
    {
        string fileName{argv[2]};
        string layerType{argv[1]};
        string outputFileName;
        bool outputFlag = false;

        if (argv[3] != nullptr)
        {
            outputFileName = argv[3];
            outputFlag = true;
        }


        shared_ptr<BaseLayer> bl;

        bl = CreateLayer(layerType);

        // Open file
        ifstream  inputFile(fileName, ios::binary);
        ofstream outputFile;

        if (outputFlag == true)
        {
            outputFile.open(outputFileName.c_str(), ios::binary);
        }

        if (inputFile.good() == true)
        {
            // Read frames
            RawFrameType  rawFrame;

            ReadFrame(inputFile, layerType, rawFrame);

            while(inputFile.eof() == false)
            {

                cout << endl;
                cout << "Raw frame: " << vectorToHexString(rawFrame, false) << endl;
                cout << endl;

                // Decode frame
                IW::ProcessedFrame  processedFrame = bl->indication(rawFrame);

                // Show frame
                cout << "Processed frame: " << toString(processedFrame) << endl;


                if (outputFlag == true)
                {
                    string payloadData;

                    uint i = bl->getDataGroupIndex();
                    uint j = bl->getDataFieldIndex();
                    
                    payloadData = processedFrame.groups[i].fields[j].value;

                    outputFile.write(payloadData.data(), payloadData.size());
                }

                ReadFrame(inputFile, layerType, rawFrame);
            }
        }

        if (outputFlag == true)
        {
            outputFile.close();
        }

    }
    return 0;
}
