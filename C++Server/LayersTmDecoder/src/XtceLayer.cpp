/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */
 
#include "XtceLayer.h"

XtceLayer::XtceLayer()
{
}

XtceLayer::~XtceLayer()
{
}

IW::TM_ProcessedFrame XtceLayer::confirm(RawFrameType& inRawData)
{
    //Send message to XTCE Java
}

IW::TM_ProcessedFrame XtceLayer::indication(RawFrameType& inRawData)
{
    //Send message to XTCE Java
}

RawFrameType XtceLayer::request(RawFrameType& inRawData)
{
    //Send message to XTCE Java
}

RawFrameType XtceLayer::response(RawFrameType& inRawData)
{
    //Send message to XTCE Java
}
