/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include "AvroTypes.h"

#include "MessageUtils.h"
#include "LogManager.h"

#include "StartUpMessage.h"

StartUpMessage::StartUpMessage()
{
}

StartUpMessage::~StartUpMessage()
{
}

ServerMessage StartUpMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    LogManager::getInstance().debug("Start:  Start Up Message");

    // It has to be a LoginResponse message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_START_UP)
    {
        // Extract the AVRO message from body
        IW::MsgStartup avroInputMessage;

        extractMessageVector<IW::MsgStartup>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


        // TODO: Add the component to the list of active components

        // Show a message
        LogManager::getInstance().info(avroInputMessage.message);

        // Reply; no error
        createReply(outputMessage, 0, "");
    }
    else
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        LogManager::getInstance().error(errorMessage);

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Startup message response: " + outputMessage.toString());

    return outputMessage;
}

