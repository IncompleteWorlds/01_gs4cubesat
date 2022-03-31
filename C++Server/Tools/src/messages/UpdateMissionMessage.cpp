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

#include "messages/UpdateMissionMessage.h"



UpdateMissionMessage::UpdateMissionMessage()
{
}

UpdateMissionMessage::~UpdateMissionMessage()
{
}

ServerMessage UpdateMissionMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_UPDATE_MISSION)
    {
        // Extract the AVRO message from body
        IW::MsgUpdateMission      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgUpdateMission>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Mission
            if (avroInputMessage.mission.name.empty() == false)
            {
                ToolsDatabase::getInstance().updateMission(avroInputMessage.mission);
                
                // Generate response
                createReply(outputMessage, 0, "Mission correctly updated");
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

    LogManager::getInstance().debug("Update Mission response: " + outputMessage.toString());

    return outputMessage;
}

