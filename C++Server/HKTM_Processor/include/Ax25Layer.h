/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __AX25_LAYER_H__
#define __AX25_LAYER_H__

// CHAR_BITS
#include <climits>
#include <string>

using namespace std;

#include "boost/bitstream/bstream.hpp"

using Bitstream = boost::bitstream::ibitstream;

#include "CommonTypes.h"

#include "BaseLayer.h"





class Ax25Layer : public BaseLayer
{
public:
    // Each derived layer needs its own attribute
    static const string LAYER_NAME;

    Ax25Layer();
    virtual ~Ax25Layer();


    // Operations
    // It receives a stream of bytes from bottom layer,
    // process it and pass to the upper layer
    //    a) REQUEST primitive type: used by a higher layer to request a service from the next lower layer;
    virtual RawFrameType request(RawFrameType& inRawData);

    //    b) INDICATION primitive type: used by a layer to provide a service to notify the next higher layer of any
    //    specific activity that is service related. The INDICATION primitive may be the result of an activity of the
    //    lower layer related to the primitive type REQUEST at the peer entity;
    virtual IW::ProcessedFrame indication(RawFrameType& inRawData);

    // It receives a stream of bytes from upper layer,
    // process it and pass to the bottom layer
    //    c) RESPONSE primitive type: used by a layer to acknowledge receipt from a lower layer of the primitive
    //    type INDICATION. AX.25 does not use the RESPONSE primitive; and
    virtual RawFrameType response(RawFrameType& inRawData);

    //    d) CONFIRM primitive type: used by a layer to provide the requested service to confirm that the activity has
    //    been completed.
    virtual IW::ProcessedFrame confirm(RawFrameType& inRawData);



protected:
    void encodeFrame(RawFrameType& inData, RawFrameType &outData);

    int decodeFrame(RawFrameType& inData, IW::ProcessedFrame &outData);

    bool checkFCS(VectorUint8& inBuffer, ushort inFrameCRC);

    int processDestinationAddress(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField& outGroup);

    int processSourceAddress(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField &outGroup);

    int processControlFlag(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField& outGroup);

    int processPID(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField &outGroup);

    int processInfo(Bitstream& inBitStream, uint &outCounter, IW::GroupProcessedField &outGroup);

    int processFCS(RawFrameType& inData, uint &outCounter, IW::GroupProcessedField &outGroup);



    static std::string encode_addr(const std::string address, bool flags_first_bit, bool flags_last_bit);

    static std::string encode_source_addr(const std::string address, bool is_cmd_res, bool has_repeaters);

    static std::string encode_destination_addr(const std::string address, bool is_cmd_res);

    static std::string encode_repeater_addr(const std::string address, bool has_been_repeated, bool is_last_repeater);

    static std::string encode_frame_data_repeater_mode(const std::string source_addr, const std::string destination_addr,
                                    const std::vector<std::string> *repeaters_addrs,
                                    const std::string data);

    char SrcCallsign[7];
    char DestCallsign[7];

    uint8_t ssid_source;
    uint8_t ssid_destination;
    char message[256];

    int Index = 0;
    unsigned int FCS = 0;

};

#endif // __AX25_LAYER_H__

