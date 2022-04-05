/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>

using namespace std;

#include "CommonTypes.h"
#include "TimeUtils.h"

#include "KissLayer.h"

static const uint8_t KISS_FEND  = 0xC0;   // Frame  End
static const uint8_t KISS_FESC  = 0xDB;   // Frame  Escape
static const uint8_t KISS_TFEND = 0xDC;   // Transposed Frame End
static const uint8_t KISS_TFESC = 0xDD;   // Transposed Frame Escape

static const uint32_t MAX_KISS_FRAME_LENGTH = 2048;


const string KissLayer::LAYER_NAME = "kiss";


KissLayer::KissLayer()
{
    dataFieldIndex_ = 2;
    dataGroupIndex_ = 0;
}

KissLayer::~KissLayer()
{

}

RawFrameType KissLayer::request(RawFrameType &inRawData)
{
    RawFrameType kissFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame
        encodeFrame(inRawData, kissFrame);

//        // Transfer to next low level layer
//        if (this->previous_ != nullptr)
//        {
//            previous_->request(kissFrame);
//        }
    }

    return kissFrame;
}

IW::ProcessedFrame KissLayer::indication(RawFrameType &inRawData)
{
    IW::ProcessedFrame  kissFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame
        decodeFrame(inRawData, kissFrame);

//        // Transfer to next low level layer
//        if (this->next_ != nullptr)
//        {
//            next_->indication(kissFrame);
//        }
    }

    return kissFrame;
}

RawFrameType KissLayer::response(RawFrameType &inRawData)
{
    RawFrameType  kissFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame

        encodeFrame(inRawData, kissFrame);

//        // Transfer to next low level layer
//        if (this->previous_ != nullptr)
//        {
//            previous_->response(kissFrame);
//        }
    }

    return kissFrame;
}

IW::ProcessedFrame KissLayer::confirm(RawFrameType &inRawData)
{
    IW::ProcessedFrame  kissFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame

        decodeFrame(inRawData, kissFrame);

//        // Transfer to next low level layer
//        if (this->next_ != nullptr)
//        {
//            next_->confirm(kissFrame);
//        }
    }

    return kissFrame;
}


// Create a KISS frame
void KissLayer::encodeFrame(RawFrameType &inData, RawFrameType &outData)
{
    if (inData.size() > 0)
    {
        size_t frameLength = inData.size();

        outData.reserve(frameLength + 2);
        outData.push_back(KISS_FEND);

        // Set data frame
        uint8_t frameType = 0;   // Data frame

        outData.push_back(frameType);

        for (size_t i = 0; i < frameLength; i ++)
        {
            if (inData[i] == KISS_FEND)
            {
                // If a FEND byte appears in the data, replace it by FESC TRawFrameTypeFEND
                outData.push_back(KISS_FESC);
                outData.push_back(KISS_TFEND);
            }
            else if (inData[i] == KISS_FESC)
            {
                // If a FESC byte appears in the data, replace it by FESC TFESC
                outData.push_back(KISS_FESC);
                outData.push_back(KISS_TFESC);
            }
            else
            {
                outData.push_back(inData[i]);
            }
        }

        outData.push_back(KISS_FEND);
    }
}


// Decode a KISS frame
int KissLayer::decodeFrame(RawFrameType& inData, IW::ProcessedFrame& outData)
{
    int output = -1;

    if (inData.size() >  0)
    {
        size_t frameLength = inData.size();

        // Check minimu size; FEND, frame type and FEND
        if (frameLength < 3)
        {
            // TODO:
            cout << "ERROR: Invalid KISS frame length. Minimum length is 3" << endl;
            output = -1;
        }
        else
        {
            // Check frame delimiters
            if (inData[0] != KISS_FEND || inData[frameLength - 1] != KISS_FEND)
            {
                // TODO:
                cout << "ERROR: Invalid KISS frame. Start and end delimiters not found" << endl;
                output = -1;
            }
            else
            {
                // Check frame type. Only data
                if ((inData[1] & 0x0F) != 0)
                {
                    // TODO
                    cout << "WARNING: Only data frames are implemented" << endl;
                }
                else
                {
                    // Create new group
                    IW::GroupProcessedField  kissGroup;

                    kissGroup.id = 0; //"TODO:kiss-id";
                    kissGroup.oolFlag = false;
                    
                    dataGroupIndex_ = 0;

                    // Delimiters are not included

                    // Field 1
                    IW::ProcessedField  field1;

                    field1.index = 0;
                    field1.fieldTypeId = 0;
                    field1.fieldName = "port";
                    field1.value = std::to_string( (inData[1] & 0xF0) >> 4 );
                    kissGroup.fields.push_back(field1);

                    // Field 2
                    IW::ProcessedField  field2;

                    field2.index = 1;
                    field2.fieldTypeId = 0;
                    field2.fieldName = "command";
                    field2.value = std::to_string( (inData[1] & 0x0F) );
                    kissGroup.fields.push_back(field2);

                    // Field 3. Data
                    IW::ProcessedField  field3;

                    // Duplicated but ...
                    field3.index = 2;
                    field3.fieldTypeId = 0;
                    field3.fieldName = "data";
                    dataFieldIndex_ = 2;

                    RawFrameType   payloadData;

                    for (std::size_t i = 2; i < frameLength - 1; i++)
                    {
                        if (inData[i] == KISS_FESC)
                        {
                            if (inData[i+1] == KISS_TFEND)
                            {
                                payloadData.push_back(KISS_FEND);
                                i ++;
                            } else if (inData[i+1] == KISS_TFESC)
                            {
                                payloadData.push_back(KISS_FESC);
                                i ++;
                            }
                            else
                            {
                                cout << "ERROR: Invalid character in KISS frame " << hex << inData[i+1]
                                     << dec << endl;
                                output = -1;

                                // TODO: Generate an Exception
                                break;
                            }
                        }
                        else
                        {
                            payloadData.push_back(inData[i]);
                        }
                    }

                    field3.value = vectorToString(payloadData);
                    kissGroup.fields.push_back(field3);

                    // Add group
                    outData.groups.push_back(kissGroup);

                    output = 0;
                }
            }
        }
    }

    return output;
}
