/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "OperationCodeEnum.h"
#include "M_CModuleManager.h"
#include "AvroTypes.h"
#include "MessageUtils.h"
#include "LogManager.h"

#include "EventMessage.h"

EventMessage::EventMessage()
{
}

EventMessage::~EventMessage()
{
}

ServerMessage EventMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    ServerMessage    outputMessage;
    
    LogManager::getInstance().debug("Start:  Event Message");

    // It has to be a PublishEvent message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_PUBLISH_EVENT)
    {
        // Forward the message to Publisher socket
        M_CModuleManager::getInstance().publishMessage(inMessage);
    }
    else
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        LogManager::getInstance().error(errorMessage);

        ::createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Login message response: " + outputMessage.toString());

    return outputMessage;
}

