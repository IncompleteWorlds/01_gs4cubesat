/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
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

#include "messages/GetMissionMessage.h"



GetMissionMessage::GetMissionMessage()
{
}

GetMissionMessage::~GetMissionMessage()
{
}

//ServerMessage GetMissionMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
ServerMessage GetMissionMessage::processMessage(const ServerMessage &inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_MISSION)
    {
        // Extract the AVRO message from body
        IW::MsgGetMission      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgGetMission>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Mission
            if (avroInputMessage.missionName.empty() == false)
            {
                IW::Mission   theMission;

                theMission = ToolsDatabase::getInstance().getMissionByName(avroInputMessage.missionName);

                // Generate response
                std::vector<uint8_t>   avroOutputMessage;

                avroOutputMessage = buildMessageVector<IW::Mission>(theMission);

                outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_MISSION_RESPONSE);
                outputMessage.setData(avroOutputMessage);
            }
            else
            {
                createReply(outputMessage, -1, "Mission identifier is null or empty");
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

    LogManager::getInstance().debug("Get Mission response: " + outputMessage.toString());

    return outputMessage;
}

