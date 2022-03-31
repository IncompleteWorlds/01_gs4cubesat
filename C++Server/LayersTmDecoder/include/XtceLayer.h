/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#ifndef __XTCELAYER_H__
#define __XTCELAYER_H__

#include "BaseLayer.h" // Base class: BaseLayer

class XtceLayer : public BaseLayer
{
public:
    // Each derived layer needs its own attribute
    static const string LAYER_NAME;

    XtceLayer();
    virtual ~XtceLayer();

    virtual IW::TM_ProcessedFrame confirm(RawFrameType& inRawData);
    virtual IW::TM_ProcessedFrame indication(RawFrameType& inRawData);
    virtual RawFrameType request(RawFrameType& inRawData);
    virtual RawFrameType response(RawFrameType& inRawData);
};

#endif // __XTCELAYER_H__
