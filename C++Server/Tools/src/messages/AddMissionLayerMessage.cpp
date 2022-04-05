/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */

#include <string>
#include <iostream>

using namespace std;

#include "AvroTypes.h"

#include "ToolsDatabase.h"
#include "GSException.h"
#include "LogManager.h"
#include "MessageUtils.h"

#include "messages/AddMissionLayerMessage.h"



AddMissionLayerMessage::AddMissionLayerMessage()
{
}

AddMissionLayerMessage::~AddMissionLayerMessage()
{
}

ServerMessage AddMissionLayerMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_ADD_MISSION_LAYER)
    {
        // Extract the AVRO message from body
        IW::MsgAddMissionLayer      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgAddMissionLayer>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // Get Mission
            if (avroInputMessage.missionName.empty() == false)
            {
                IW::Layer   theLayer;
                int64_t     layerId;

                layerId = ToolsDatabase::getInstance().createLayer(avroInputMessage.layer);
                
                createReply(outputMessage, 0, "");                
            }
            else
            {
                createReply(outputMessage, -1, "Mission name is null or empty");
            }
            // ----------------------------------------------------------------------
        } catch(GSException& gsExc)
        {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
            createReply(outputMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
        }
    }
    else
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        LogManager::getInstance().error(errorMessage);

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Add Mission Layer response: " + outputMessage.toString());

    return outputMessage;
}

