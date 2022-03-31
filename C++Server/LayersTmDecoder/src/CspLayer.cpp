/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

// CHAR_BITS
#include <climits>
#include <iostream>
#include <bitset>

using namespace std;

#include "TimeUtils.h"

#include "CspLayer.h"


// Cubesat Space Protocol
const string CspLayer::LAYER_NAME = "CSP";

CspLayer::CspLayer()
{
    dataFieldIndex_ = 0;
    dataGroupIndex_ = 0;
}

CspLayer::~CspLayer()
{

}

RawFrameType CspLayer::request(RawFrameType &inRawData)
{
    RawFrameType  outputFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame
        encodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

IW::TM_ProcessedFrame CspLayer::indication(RawFrameType &inRawData)
{
    IW::TM_ProcessedFrame  outputFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame
        decodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

RawFrameType CspLayer::response(RawFrameType &inRawData)
{
    RawFrameType  outputFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame
        encodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

IW::TM_ProcessedFrame CspLayer::confirm(RawFrameType &inRawData)
{
    IW::TM_ProcessedFrame  outputFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame
        decodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

void CspLayer::encodeFrame(RawFrameType& inData, RawFrameType &outData)
{
    if (inData.size() > 0)
    {

    }
}

int CspLayer::decodeFrame(RawFrameType& inData, IW::TM_ProcessedFrame &outFrame)
{
    int output = -1;

    cout << "DEBUG: CSP frame: [" << vectorToString(inData) << "]" << endl;

    // 32 bits header
    Bitstream bs{ reinterpret_cast<const char *>(inData.data()),
                  reinterpret_cast<ulong>(inData.size() * CHAR_BIT) };

    // Set frame details
    // Create new group
    IW::GroupProcessedField  cspGroup;

    cspGroup.id = 0; // "TODO:id-csp";
    cspGroup.oolFlag = false;

    dataGroupIndex_ = 0;

    uint  fieldCounter = 0;


    // Padding bytes. Based on a Parameter



    // Length
    uint16_t  frameLength;

    bs >> frameLength;

    IW::ProcessedField tmpField;

    tmpField.index = fieldCounter;
    fieldCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "length";
    tmpField.value = to_string(frameLength);

    cspGroup.fields.push_back(tmpField);


    if (inData.size() < frameLength)
    {
        cout << "ERROR: Invalid CSP frame length" << endl;
    }
    else
    {
        // Process header
        processHeader(bs, fieldCounter, cspGroup);

        // Data: 0 - 65535
        processInfo(bs, fieldCounter, frameLength, cspGroup);

        // Add group
        outFrame.groups.get_array().push_back(cspGroup);

        // No error
        output = 0;
    }

    return output;
}

int CspLayer::processHeader(Bitstream &inBitStream, uint &outCounter, IW::GroupProcessedField &outData)
{
    int output = -1;

    bitset<2> priority = 0;
    bitset<5> source = 0;
    bitset<5> destination = 0;
    bitset<6> source_port = 0;
    bitset<6> destination_port = 0;
    bitset<1> flag = 0;

    IW::ProcessedField tmpField;

    // Priority
    inBitStream >> priority;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "priority";
    tmpField.value = to_string(priority.to_ulong());

    outData.fields.push_back(tmpField);

    // Source
    inBitStream >> source;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "source";
    tmpField.value = to_string(source.to_ulong());

    outData.fields.push_back(tmpField);

    // Destination
    inBitStream >> destination;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "destination";
    tmpField.value = to_string(destination.to_ulong());

    outData.fields.push_back(tmpField);

    // Source Port
    inBitStream >> source_port;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "source_port";
    tmpField.value = to_string(source_port.to_ulong());

    outData.fields.push_back(tmpField);


    // Destination Port
    inBitStream >> destination_port;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "destination_port";
    tmpField.value = to_string(destination_port.to_ulong());

    outData.fields.push_back(tmpField);


    // Flags; HMAC, RDP, etc.
    // 3 reserved bits
    inBitStream >> flag;
    inBitStream >> flag;
    inBitStream >> flag;

    // Use fragmentation
    inBitStream >> flag;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "fragmentation";
    tmpField.value = to_string(flag.to_ulong());

    outData.fields.push_back(tmpField);

    // Use HMAC verification
    inBitStream >> flag;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "HMAC";
    tmpField.value = to_string(flag.to_ulong());

    outData.fields.push_back(tmpField);

    // Use XTEA encryption
    inBitStream >> flag;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "XTEA";
    tmpField.value = to_string(flag.to_ulong());

    outData.fields.push_back(tmpField);

    // Use RDP protocol
    inBitStream >> flag;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "RDP";
    tmpField.value = to_string(flag.to_ulong());

    outData.fields.push_back(tmpField);

    // Use CRC32 checksum
    inBitStream >> flag;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "CRC32";
    tmpField.value = to_string(flag.to_ulong());

    outData.fields.push_back(tmpField);

    return output;
}


int CspLayer::processInfo(Bitstream &inBitStream, uint &outCounter, uint inFrameLength, IW::GroupProcessedField &outData)
{
    int output = -1;

    string data;
    uint8_t c;

    for(uint i = 0; i < inFrameLength; i ++)
    {
        inBitStream >> c;

        data.push_back(c);
        // Alternative
        //data[i] = c;
    }

    IW::ProcessedField tmpField;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "info";
    tmpField.value = data;

    outData.fields.push_back(tmpField);

    // Duplicated but ...
    dataFieldIndex_ = tmpField.index;


    return output;
}
