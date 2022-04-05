/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __APPLICATIONLAYER_H__
#define __APPLICATIONLAYER_H__


#include "CommonTypes.h"

#include "BaseLayer.h"


/*
 * - Receive an application layer frame
 * - Decommute it and create a processed frame
 * - Put the processed into the data bus. It will be forwarded to
 *   the TM Archive and MCS / HK TM Dispatcher
 */
class ApplicationLayer : public BaseLayer
{
public:
    ApplicationLayer();
    virtual ~ApplicationLayer();

    RawFrameType request(RawFrameType& inRawData);

    IW::ProcessedFrame indication(RawFrameType& inRawData);

    RawFrameType response(RawFrameType& inRawData);

    IW::ProcessedFrame confirm(RawFrameType& inRawData);
    
protected:
    void sendDataBus();
};

#endif // __APPLICATIONLAYER_H__
