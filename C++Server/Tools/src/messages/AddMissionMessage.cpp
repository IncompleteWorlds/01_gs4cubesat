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

#include "messages/AddMissionMessage.h"



AddMissionMessage::AddMissionMessage()
{
}

AddMissionMessage::~AddMissionMessage()
{
}

ServerMessage AddMissionMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_ADD_MISSION)
    {
        // Extract the AVRO message from body
        IW::MsgAddMission      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgAddMission>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Mission
            if (avroInputMessage.mission.name.empty() == false)
            {
                IW::Mission   theMission;
                int64_t       missionId;

                missionId = ToolsDatabase::getInstance().createMission(avroInputMessage.mission);
                
                theMission = avroInputMessage.mission;
                //theMission.identifier = static_cast<int32_t>(missionId);

                // Generate response
                std::vector<uint8_t>   avroOutputMessage;

                avroOutputMessage = buildMessageVector<IW::Mission>(theMission);

                outputMessage.setOperationCode(OperationCodeEnum::CODE_ADD_MISSION_RESPONSE);
                outputMessage.setData(avroOutputMessage);
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

    LogManager::getInstance().debug("Add Mission response: " + outputMessage.toString());

    return outputMessage;
}

