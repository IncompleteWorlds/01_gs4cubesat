/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "AvroTypes.h"

#include "EventTypeEnum.h"
#include "GSException.h"
#include "TimeUtils.h"
#include "ServerWorker.h"
#include "ConfigurationManager.h"

#include "MessageUtils.h"

#include "HkTmProcessorModuleManager.h"
#include "messages/NewRawFrameMessage.h"

NewRawFrameMessage::NewRawFrameMessage()
{
}

NewRawFrameMessage::~NewRawFrameMessage()
{
}

// Frame sent by the GS Manager directly
ServerMessage NewRawFrameMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    ServerMessage outputMessage;


    return outputMessage;
}

void NewRawFrameMessage::publishEvent(const ServerMessage &inMessage, ServerWorker &inParent)
{
}
