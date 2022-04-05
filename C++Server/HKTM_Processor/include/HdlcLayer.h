/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __HDLCLAYER_H__
#define __HDLCLAYER_H__

#include <string>

using namespace std;

#include "boost/bitstream/bstream.hpp"

using Bitstream = boost::bitstream::ibitstream;


#include "BaseLayer.h"


class HdlcLayer : public BaseLayer
{
public:
    static const string LAYER_NAME;

    HdlcLayer();
    ~HdlcLayer();

    // Operations
    // It receives a stream of bytes from bottom layer,
    // process it and pass to the upper layer
    //  a) REQUEST primitive type: used by a higher layer to request a service from the next lower layer;
    RawFrameType request(RawFrameType& inRawData);

    // b) INDICATION primitive type: used by a layer to provide a service to notify the next higher layer of any
    //    specific activity that is service related. The INDICATION primitive may be the result of an activity of the
    //    lower layer related to the primitive type REQUEST at the peer entity;
    IW::ProcessedFrame indication(RawFrameType& inRawData);

    // It receives a stream of bytes from upper layer,
    // process it and pass to the bottom layer
    // c) RESPONSE primitive type: used by a layer to acknowledge receipt from a lower layer of the primitive
    //    type INDICATION. AX.25 does not use the RESPONSE primitive; and
    RawFrameType response(RawFrameType& inRawData);

    // d) CONFIRM primitive type: used by a layer to provide the requested service to confirm that the activity has
    //    been completed.
    IW::ProcessedFrame confirm(RawFrameType& inRawData);



protected:
    void encodeFrame(RawFrameType& inData, RawFrameType &outData);

    int decodeFrame(RawFrameType& inData, IW::ProcessedFrame &outData);
};

#endif // __HDLCLAYER_H__
