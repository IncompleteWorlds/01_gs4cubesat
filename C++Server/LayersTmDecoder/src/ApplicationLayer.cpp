/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */
 
#include <string>
 
using namespace std;

#include "TimeUtils.h"
#include "MessageUtils.h"

#include "HkTmProcessorModuleManager.h"
#include "ApplicationLayer.h"

ApplicationLayer::ApplicationLayer()
{
    // Read frame definition from the database
}

ApplicationLayer::~ApplicationLayer()
{
}

RawFrameType ApplicationLayer::request(RawFrameType &inRawData)
{
    RawFrameType output;
    
    return output;
}

IW::TM_ProcessedFrame ApplicationLayer::indication(RawFrameType &inRawData)
{
    IW::TM_ProcessedFrame output;
    
    // Process frame

    // Generated processed frame

    // Send the processed frame to data bus
    sendDataBus();
    
    return output;
}

RawFrameType ApplicationLayer::response(RawFrameType &inRawData)
{
    RawFrameType output;
    
    return output;
}

IW::TM_ProcessedFrame ApplicationLayer::confirm(RawFrameType &inRawData)
{
    IW::TM_ProcessedFrame output;
    
    return output;
}

// Publish an event containing the processed frame
void ApplicationLayer::sendDataBus()
{
    VectorUint8   processedFrame;

    //TODO: Create processed frame
    
    // Publish the event
    ServerMessage  eventMsg;
    
    HkTmProcessorModuleManager::getInstance().publishEvent(eventMsg, EventTypeEnum::EVT_NEW_PROCESSED_FRAME);
}

