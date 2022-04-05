/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include <vector>
#include <bitset>

using namespace std;


#include "Crc.h"
#include "TimeUtils.h"

#include "Ax25Layer.h"




const uint AX25_MIN_INFO_LEN = 0;
const uint AX25_MAX_INFO_LEN = 256;    // Without bits stuffing and FCS

const uint AX25_MAX_ADDRS = 10;     // Destination, Source, 8 digipeaters

const uint AX25_MIN_PACKET_LEN = ( 2 * 7 + 1 );
const uint AX25_MAX_PACKET_LEN = ( AX25_MAX_ADDRS * 7 + 2 + 3 + AX25_MAX_INFO_LEN);

const uint8_t AX25_FLAG = 0x7E;




const string Ax25Layer::LAYER_NAME = "ax.25";

// U and S frames; data field is 3.
// I frames; data field is 4
// Index starts in 0
Ax25Layer::Ax25Layer()
    : ssid_source{}, ssid_destination{}
{
    dataFieldIndex_ = 3;
    dataGroupIndex_ = 0;
}

Ax25Layer::~Ax25Layer()
{
}



// Operations
// It receives a stream of bytes from bottom layer,
// process it and pass to the upper layer
//    a) REQUEST primitive type: used by a higher layer to request a service from the next lower layer;
RawFrameType Ax25Layer::request(RawFrameType& inRawData)
{
    RawFrameType  outputFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame
        encodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

//    b) INDICATION primitive type: used by a layer to provide a service to notify the next higher layer of any
//    specific activity that is service related. The INDICATION primitive may be the result of an activity of the
//    lower layer related to the primitive type REQUEST at the peer entity;
IW::ProcessedFrame Ax25Layer::indication(RawFrameType& inRawData)
{
    IW::ProcessedFrame  outputFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame
        decodeFrame(inRawData, outputFrame);
    }

    return outputFrame;    
}

// It receives a stream of bytes from upper layer,
// process it and pass to the bottom layer
//    c) RESPONSE primitive type: used by a layer to acknowledge receipt from a lower layer of the primitive
//    type INDICATION. AX.25 does not use the RESPONSE primitive; and
RawFrameType Ax25Layer::response(RawFrameType& inRawData)
{
    RawFrameType  outputFrame;

    if (inRawData.size() > 0)
    {
        // Encode frame
        encodeFrame(inRawData, outputFrame);
    }

    return outputFrame;
}

//    d) CONFIRM primitive type: used by a layer to provide the requested service to confirm that the activity has
//    been completed.
IW::ProcessedFrame Ax25Layer::confirm(RawFrameType& inRawData)
{
    IW::ProcessedFrame  outputFrame;

    if (inRawData.size() > 0)
    {
        // Decode frame
        decodeFrame(inRawData, outputFrame);
    }
    
    return outputFrame;
}


void Ax25Layer::encodeFrame(RawFrameType& inData, RawFrameType &outData)
{
    if (inData.size() > 0)
    {

    }
}

int Ax25Layer::decodeFrame(RawFrameType& inData, IW::ProcessedFrame &outData)
{
    int output = -1;

    uint  frameLength = inData.size();

    cout << "DEBUG: AX.25 frame: [" << vectorToString(inData) << "]" << endl;

    // Check length
    if (frameLength < AX25_MIN_PACKET_LEN || frameLength > AX25_MAX_PACKET_LEN)
    {
        // TODO:
        cout << "ERROR: Invalid AX.25 frame length" << endl;
    }
    else
    {
        // Flag
        if (inData[0] != AX25_FLAG)
        {
            // TODO:
            cout << "ERROR: Invalid AX.25 frame. Initial flag not found" << endl;
        }
        else
        {
            uint lastIndex = frameLength - 1;

            if (inData[lastIndex] != AX25_FLAG)
            {
                // TODO:
                cout << "ERROR: Invalid AX.25 frame. Final flag not found" << endl;
            }
            else
            {
                // Process FCS
                uint  fieldCounter = 0;

                // Set frame details
                // Create new group
                IW::GroupProcessedField  ax25Group;

                ax25Group.id = 0; //"TODO:id-ax25";
                ax25Group.oolFlag = false;

                dataGroupIndex_ = 0;

                if (processFCS(inData, fieldCounter, ax25Group) == 0)
                {
                    RawFrameType tmpData{inData};

                    // Remove first delimiter
                    tmpData.front();

                    // Remove last delimiter
                    tmpData.pop_back();

                    // Remove FCS
                    tmpData.pop_back();
                    tmpData.pop_back();

                    Bitstream bs{ reinterpret_cast<const char *>(tmpData.data()),
                                  reinterpret_cast<ulong>(tmpData.size() * CHAR_BIT) };
                    //Bitstream bs(tmpData);


                    // Destination Address
                    processDestinationAddress(bs, fieldCounter, ax25Group);

                    // Source Address
                    processSourceAddress(bs, fieldCounter, ax25Group);


                    // Control
                    if (processControlFlag(bs, fieldCounter, ax25Group) == 0)
                    {
                        // Process PID
                        if (processPID(bs, fieldCounter, ax25Group) == 0)
                        {
                            // Info. Data
                            // Max length 256 bytes before byte stuffing
                            processInfo(bs, fieldCounter, ax25Group);

                            // Add group
                            outData.groups.push_back(ax25Group);

                            // No error
                            output = 0;
                        }
                    }
                }
            }
        }
    }

    return output;
}


int Ax25Layer::processDestinationAddress(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField& outGroup)
{
    int output = -1;

    uint8_t c = 0;
    string destinationAddress{6};
    std::bitset<1> firstBitC = 0;

    for(uint i = 0; i < 6; i ++)
    {
        //c = inBitStream.pop1Byte();
        inBitStream >> c;
        destinationAddress[i] = c >> 1;
    }

    // Add the field
    IW::ProcessedField tmpField;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "destination_address";
    tmpField.value = destinationAddress;

    outGroup.fields.push_back(tmpField);


    // C Bit
    //firstBitC = inBitStream.pop1Bit();
    inBitStream >> firstBitC;

    // RR
    //uint8_t destinationRR = inBitStream.pop(2);
    bitset<2>  destinationRR;

    inBitStream >> destinationRR;


    // Destination SSID
    //uint8_t destinationSSID = inBitStream.pop(4);
    bitset<4>  destinationSSID;

    inBitStream >> destinationSSID;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "destination_SSID";
    tmpField.value = std::to_string( destinationSSID.to_ulong() );
    outGroup.fields.push_back(tmpField);

    // Extension bit
    //uint8_t firstExtensionBit = inBitStream.pop1Bit();
    bitset<1>   firstExtensionBit;

    inBitStream >> firstExtensionBit;

    output = 0;
    return output;
}

int Ax25Layer::processSourceAddress(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField& outGroup)
{
    int output = -1;

    uint8_t c = 0;
    string sourceAddress{6};
    //uint8_t secondBitC = 0;

    for(uint i = 0; i < 6; i ++)
    {
        //c = inBitStream.pop1Byte();
        inBitStream >> c;
        sourceAddress[i] = c >> 1;
    }

    // Add the field
    IW::ProcessedField tmpField;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "source_address";
    tmpField.value = sourceAddress;

    outGroup.fields.push_back(tmpField);


    // C Bit
    //secondBitC = inBitStream.pop1Bit();
    bitset<1> secondBitC;

    inBitStream >> secondBitC;

    // RR
    //uint8_t sourceRR = inBitStream.pop(2);
    bitset<2> sourceRR;

    inBitStream >> sourceRR;

    // Source SSID
    //uint8_t sourceSSID = inBitStream.pop(4);
    bitset<4> sourceSSID;

    inBitStream >> sourceSSID;


    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "source_SSID";
    tmpField.value = std::to_string( sourceSSID.to_ulong() );

    outGroup.fields.push_back(tmpField);

    // Extension bit. It should be 1. Ignored
    //uint8_t secondExtensionBit = inBitStream.pop1Bit();
    bitset<1> secondExtensionBit;

    inBitStream >> secondExtensionBit;

    output = 0;
    return output;
}

int Ax25Layer::processControlFlag(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField &outGroup)
{
    int output = -1;

    //uint8_t  first3Bits = inBitStream.pop(3);
    bitset<3>  first3Bits;

    inBitStream >> first3Bits;

    //uint8_t  pfFlag = inBitStream.pop1Bit();
    bitset<1> pfFlag;

    inBitStream >> pfFlag;

    //uint8_t  second2Bits = inBitStream.pop(2);
    bitset<2>   second2Bits;

    inBitStream >> second2Bits;

    //uint8_t  uiFrameFlag = inBitStream.pop(2);
    bitset<2>  uiFrameFlag;

    inBitStream >> uiFrameFlag;

    uint8_t  controlFlag = ( (first3Bits.to_ulong() << 3) | second2Bits.to_ulong() ) & 0xFF;

    /*
Control Flag

S e t A s y n c B a l a n c e d M o d e  SABME   C m d    0 1 1 P 1 1 1 1
S e t A s y n c B a l a n c e d M o d e S A B M C m d     0 0 1 P 1 1 1 1
D i s c o n n e c t D I S C C m d      0 1 0 P 0 0 1 1
D i s c o n n e c t M o d e D M R e s     0 0 0 F 1 1 1 1
U n n u m b e r e d A c k n o w l e d g e U A R e s    0 1 1 F 0 0 1 1
F r a m e R e j e c t F R M R R e s      1 0 0 F 0 1 1 1
U n n u m b e r e d I n f o r m a t i o n  UI  E i t h e r     0 0 0 P / F 0 0 1 1
E x c h a n g e I d e n t i f i c a t i o n X I D E i t h e r     1 0 1 P / F 1 1 1 1
T e s t T E S T E i t h e r     1 1 1 P / F 0 0 1 1
*/

    // Is a UI frame?
    if (uiFrameFlag != 0x03)
    {
        // TODO:
        cout << "ERROR: Non UI received. Ignored" << endl;
    }
    else
    {
        // Unexpected frame type
        if (controlFlag != 0)
        {
            // TODO:
            cout << "ERROR: Non UI received. Ignored" << endl;
        }
        else
        {
            // Add the field
            IW::ProcessedField tmpField;

            tmpField.index = outCounter;
            outCounter ++;
            tmpField.fieldTypeId = 0;
            tmpField.fieldName = "control_flag";
            tmpField.value = std::to_string(controlFlag);

            outGroup.fields.push_back(tmpField);

            // No error
            output = 0;
        }
    }

    return output;
}

int Ax25Layer::processPID(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField& outGroup)
{
    int output = -1;

    uint8_t pidByte;    //= inBitStream.pop1Byte();
    inBitStream >> pidByte;

    // We can only accept "No Layer 3 protocol"
    if (pidByte == 0xF0)
    {
        // Add the field
        IW::ProcessedField tmpField;

        tmpField.index = outCounter;
        outCounter ++;
        tmpField.fieldTypeId = 0;
        tmpField.fieldName = "pid";
        tmpField.value = std::to_string(pidByte);

        outGroup.fields.push_back(tmpField);

        // No error
        output = 0;
    }
    else
    {
        // TODO:
        cout << "ERROR: Invalid protocol. Only 'No layer 3 protocol' is allowed" << endl;
    }

    return output;
}


int Ax25Layer::processInfo(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField& outGroup)
{
    int output = -1;

    VectorUint8  payloadData;
    //uint8_t  c = 0;
    bitset<1> c;
    uint  bitCounter = 0;
    uint  bitsInByte = 0;
    std::bitset<8> aByte;

    //.getEof()  isEmpty()
    while (inBitStream.eof() == false)
    {
        //c = inBitStream.pop1Bit();
        inBitStream >> c;

        if (c == 0x01) {
            bitCounter ++;
        } else {
            bitCounter = 0;
        }

        if (bitCounter == 5) {
            // Skip this bit and reset counter
            bitCounter = 0;
        } else {
            aByte[bitsInByte] = c.test(0);
            bitsInByte ++;
            if (bitsInByte >= 8) {
                payloadData.push_back( aByte.to_ulong() & 0xFF );
                bitsInByte = 0;
            }
        }
    }

    // Add processed field
    IW::ProcessedField tmpField;

    tmpField.index = outCounter;
    outCounter ++;
    tmpField.fieldTypeId = 0;
    tmpField.fieldName = "info";
    // tmpField.value_ = Array<uint8_t>::toString(payloadData, "hex", payloadData.size(), true);
    tmpField.value = vectorToString(payloadData);

    outGroup.fields.push_back(tmpField);

    // Duplicated but ...
    dataFieldIndex_ = tmpField.index;

    return output;
}

int Ax25Layer::processFCS(RawFrameType &inBuffer, uint &outCounter, IW::GroupProcessedField& outGroup)
{
    int output = -1;
    uint  frameLength = inBuffer.size();

    // Extract everything excepts the FCS and delimiters
    RawFrameType  tmpDataFrame{ inBuffer.size() };

    // We start from 1
    for(uint i = 1, j = 0; i < frameLength - 3; i ++, j ++)
    {
        tmpDataFrame[j] = inBuffer[i];
    }

    // Extract FCS
    uint8_t  firstByte = inBuffer[frameLength - 3];
    uint8_t  secondByte = inBuffer[frameLength - 2];

    ushort frameCRC = (firstByte << 8) | secondByte;

    // Check the FCS before going further in the processing
    if (checkFCS(tmpDataFrame, frameCRC) == true)
    {
        // Field processed field
        IW::ProcessedField fcsField;

        fcsField.index     = outCounter;
        outCounter ++;
        fcsField.fieldTypeId = 0;
        fcsField.fieldName = "FCS";
        fcsField.value     = toHexString<ushort>(frameCRC);

        outGroup.fields.push_back(fcsField);

        output = 0;
    }
    else
    {
        // TODO:
        cout << "ERROR: Invalid AX.25 frame. CRC is incorrect. Frame CRC: ";
        cout << hex << frameCRC << dec << endl;
    }

    return output;
}

bool Ax25Layer::checkFCS(VectorUint8& inBuffer, ushort inFrameCRC)
{
    ushort calculatedCRC = CRC_INITIAL_VALUE;

    calculatedCRC = crc16(inBuffer, calculatedCRC);

    return (inFrameCRC == calculatedCRC);
}






/*
 *
 *

namespace extmodem {

    std::string ax25_utils::encode_addr(const std::string address, bool flags_first_bit, bool flags_last_bit) {

        // check SSID presence
        int ssid = 0;
        std::string::size_type sep = address.find('-', 0);
        if (sep != std::string::npos && sep != address.length() - 1)
            ssid = std::atoi(address.substr(sep + 1, address.length() - sep).c_str());
        else
            sep = address.length();

        // shift address bits
        std::string out = std::string(7, ' ' << 1);
        for (unsigned i = 0; i < std::min(sep, (std::string::size_type) 6); ++i)
            out.at(i) = address.at(i) << 1;

        // last octet with SSID and flags
        char octet = (char) ssid;
        octet <<= 1;
        octet ^= (-flags_first_bit ^ octet) & (1 << 7);
        octet |= 1 << 6;
        octet |= 1 << 5;
        octet ^= (-flags_last_bit ^ octet) & (1 << 0);
        out.at(6) = octet;

        return out;
    }

    std::string ax25_utils::encode_source_addr(const std::string address, bool is_cmd_res, bool has_repeaters) {

        return encode_addr(address, is_cmd_res, !has_repeaters);
    }

    std::string ax25_utils::encode_destination_addr(const std::string address, bool is_cmd_res) {

        return encode_addr(address, is_cmd_res, 0);
    }

    std::string
    ax25_utils::encode_repeater_addr(const std::string address, bool has_been_repeated, bool is_last_repeater) {

        return encode_addr(address, has_been_repeated, is_last_repeater);
    }

    std::string
    ax25_utils::encode_frame_data_repeater_mode(const std::string source_addr, const std::string destination_addr,
                                                const std::vector<std::string> *repeaters_addrs,
                                                const std::string data) {

        unsigned long nreps = repeaters_addrs->size();

        // compose frame data with destination and source
        std::stringstream ss;
        ss << encode_destination_addr(destination_addr, true);
        ss << encode_source_addr(source_addr, true, nreps > 0);

        // add repeaters
        for (unsigned long k = 0; k < nreps; k++)
            ss << encode_repeater_addr(repeaters_addrs->at(k), false, k == nreps - 1);

        // control field, protocol and information
        ss << (char) AX25_UI_FRAME;
        ss << (char) AX25_PID_NO_LAYER_3;
        ss << data;

        return ss.str();
    }
}



void AX25::bitProcessing(byte *Buffer, uint8_t bytelength) {

    byte BitSequence[bytelength*8+1];
    byte BitSequenceStuffed[bytelength*8+bytelength*8/5+1];
    int k = 0; //general counter
    int _size = 0;
    int s = 0; //stuffed sequence counter
    uint8_t cnt = 0 ;//Bit stuff counter
    uint8_t remBits = 0;
    byte temp = 0;
    byte byte_temp[255*8];//max message lenght 255 bytes

    k = 0;
    //Convert bits to byte size
    for (int i = 0; i< bytelength ; i++)
    {
      for (register uint8_t t=128; t>0 ; t = t/2) {
        if (Buffer[i] & t) BitSequence[k++] = 0x01;
        else BitSequence[k++] = 0x00;
       }
     }

     // stuff a 0 after five consecutive 1s.
     for (int i = 0; i < k ; i++)
     {
        if (BitSequence[i] == 0x01) cnt++;
        else cnt = 0; // restart count at 1

        BitSequenceStuffed[s++] = BitSequence[i]; // add the bit to the final sequence

        if (cnt == 5) // there are five consecutive bits of the same value
        {
            BitSequenceStuffed[s++] = 0x00; // stuff with a zero bit
            cnt = 0; // and reset cnt to zero
        }
      }

      _size = 0;
       //Recreate 0b01111110 (FLAG) in byte size
      for (int i=0; i < 64 ; i++)
      {
         Buffer[_size++] = 0x00;
         for (int j=0; j < 6 ; j++)
         {
           Buffer[_size++] = 0x01;
         }
         Buffer[_size++] = 0x00;
      }

      for (int i=0; i < s ; i++) Buffer[_size++] = BitSequenceStuffed[i];

      //Insert 0b01111110 (FLAG)
       Buffer[_size++] = 0x00;
       for (int j=0; j < 6 ; j++)
       {
         Buffer[_size++] = 0x01;
       }
       Buffer[_size++] = 0x00;

      for (int i = 0; i< 255*8 ; i++) byte_temp[i] = 0x00;

      //NRZI encoding
      for (int i=0; i < _size ; i++)
      {
         if (Buffer[i] == 0x00)
         {
           byte_temp[i+1] = ! byte_temp[i];
         }
         else
         {
           byte_temp[i+1] = byte_temp[i];
         }
      }

      //extrabits = (_size+1) % 8;
      if (((_size+1) % 8) > 0) remBits = 8 - ((_size+1) % 8);

      for (int i = (_size + 1) ; i < (_size + 1 + remBits ) ; i++)
      {
         byte_temp[i] = 0x01;
      }

      //Convert to bit after NRZI and added remaining bits to form byte array
      Index = 0;
      for (int i = 0; i < (_size + 1 + remBits); i = i + 8)
      {
        temp = 0;
        if  (byte_temp[i] == 0x01)   temp = temp + 0b10000000;
        if  (byte_temp[i+1] == 0x01) temp = temp + 0b01000000;
        if  (byte_temp[i+2] == 0x01) temp = temp + 0b00100000;
        if  (byte_temp[i+3] == 0x01) temp = temp + 0b00010000;
        if  (byte_temp[i+4] == 0x01) temp = temp + 0b00001000;
        if  (byte_temp[i+5] == 0x01) temp = temp + 0b00000100;
        if  (byte_temp[i+6] == 0x01) temp = temp + 0b00000010;
        if  (byte_temp[i+7] == 0x01) temp = temp + 0b00000001;
        finalSequence[Index++] = temp;
      }
}

*/


