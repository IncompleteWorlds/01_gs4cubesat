/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <climits>
#include <vector>
#include <bitset>

using namespace std;

// TBD
static const uint32_t HDLC_MIN_PACKET_LEN = 2;
static const uint32_t HDLC_MAX_PACKET_LEN = 256;


#include "HdlcLayer.h"

const string HdlcLayer::LAYER_NAME = "hdlc";


HdlcLayer::HdlcLayer()
{
    dataFieldIndex_ = 2;
    dataGroupIndex_ = 0;
}

HdlcLayer::~HdlcLayer()
{

}

RawFrameType HdlcLayer::request(RawFrameType &inRawData)
{
    RawFrameType  outputFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame
        encodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

IW::TM_ProcessedFrame HdlcLayer::indication(RawFrameType &inRawData)
{
    IW::TM_ProcessedFrame  outputFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame
        decodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

RawFrameType HdlcLayer::response(RawFrameType &inRawData)
{
    RawFrameType  outputFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame
        encodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

IW::TM_ProcessedFrame HdlcLayer::confirm(RawFrameType &inRawData)
{
    IW::TM_ProcessedFrame  outputFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame
        decodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

void HdlcLayer::encodeFrame(RawFrameType &inData, RawFrameType &outData)
{
}

int HdlcLayer::decodeFrame(RawFrameType &inData, IW::TM_ProcessedFrame &outData)
{
    int output = -1;

    uint  frameLength = inData.size();

    cout << "DEBUG: HDLC frame: [" << vectorToString(inData) << "]" << endl;


    // Check length
    if (frameLength < HDLC_MIN_PACKET_LEN || frameLength > HDLC_MAX_PACKET_LEN)
    {
        // TODO:
        cout << "ERROR: Invalid HDLC frame length" << endl;
    }
    else
    {
        // Process FCS
        uint  fieldCounter = 0;

        // Set frame details
        // Create new group
        IW::GroupProcessedField  hdlcGroup;

        hdlcGroup.id = 0;  // "TODO:id-hdlc";
        hdlcGroup.oolFlag = false;
        
        dataGroupIndex_ = 0;

        Bitstream bs{ reinterpret_cast<const char *>(inData.data()),
                      reinterpret_cast<ulong>(inData.size() * CHAR_BIT) };

    }

    return output;
}

