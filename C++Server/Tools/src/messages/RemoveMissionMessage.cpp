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

#include "messages/RemoveMissionMessage.h"



RemoveMissionMessage::RemoveMissionMessage()
{
}

RemoveMissionMessage::~RemoveMissionMessage()
{
}

ServerMessage RemoveMissionMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_DELETE_MISSION)
    {
        // Extract the AVRO message from body
        IW::MsgRemoveMission      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgRemoveMission>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Mission
            if (avroInputMessage.missionName.empty() == false)
            {
                ToolsDatabase::getInstance().removeMission(avroInputMessage.missionName);
                
                createReply(outputMessage, 0, "Mission correctly removed");                
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

    LogManager::getInstance().debug("Remove Mission response: " + outputMessage.toString());

    return outputMessage;
}

