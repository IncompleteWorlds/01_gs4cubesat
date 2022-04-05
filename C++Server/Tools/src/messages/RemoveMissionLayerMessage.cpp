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

#include "messages/RemoveMissionLayerMessage.h"



RemoveMissionLayerMessage::RemoveMissionLayerMessage()
{
}

RemoveMissionLayerMessage::~RemoveMissionLayerMessage()
{
}

ServerMessage RemoveMissionLayerMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_DELETE_MISSION_LAYER)
    {
        // Extract the AVRO message from body
        IW::MsgRemoveMissionLayer      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgRemoveMissionLayer>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get MissionLayer
            if (avroInputMessage.missionName.empty() == false && avroInputMessage.layerName.empty() == false)
            {
                ToolsDatabase::getInstance().removeLayer(avroInputMessage.layerName);
                
                createReply(outputMessage, 0, "Mission Layer correctly removed");                
            }
            else
            {
                createReply(outputMessage, -1, "Mission name or Layer name is null or empty");
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

    LogManager::getInstance().debug("Remove Mission Layer response: " + outputMessage.toString());

    return outputMessage;
}

