/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <string>
#include <vector>

using namespace std;

#include "AvroTypes.h"

#include "GSException.h"
#include "RoleEnum.h"
#include "SecurityAccessIF.h"
#include "MessageUtils.h"
#include "ServerWorker.h"
#include "ConfigurationManager.h"
#include "LogManager.h"
#include "TimeUtils.h"
#include "ToolsDatabase.h"

#include "RegisterUserMessage.h"

using namespace IW;


RegisterUserMessage::RegisterUserMessage()
{
}

RegisterUserMessage::~RegisterUserMessage()
{
}

ServerMessage RegisterUserMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;
    
    LogManager::getInstance().debug("Start:  RegisterUser Message");

    // It has to be a RegisterUser message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_REGISTER_USER)
    {
        // Extract the AVRO message from body
        IW::MsgRegisterUser      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgRegisterUser>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            if (avroInputMessage.user.userName.empty() == false &&
                avroInputMessage.user.password.empty() == false &&
                avroInputMessage.user.firstName.empty() == false &&
                avroInputMessage.user.lastName.empty() == false)
            {
                int64_t userId = ToolsDatabase::getInstance().createUser(avroInputMessage.user);
                                                                         
                if (avroInputMessage.mission.name.empty() == false &&
                    avroInputMessage.mission.owner.empty() == false &&
                    avroInputMessage.mission.adminIdentifier == 0)
                {
                    avroInputMessage.mission.adminIdentifier = userId;
                    avroInputMessage.mission.creationTime    = TimeUtils::getCurrentTimeString();
                    int64_t missionId = ToolsDatabase::getInstance().createMission(avroInputMessage.mission);
                    
                    createReply(outputMessage, 0, "User correctly created: " + avroInputMessage.user.userName + 
                                " New id: " + std::to_string(userId));
                }
                else
                {
                    createReply(outputMessage, -1, "Mission data is null or empty");
                }
            }
            else
            {
                createReply(outputMessage, -1, "User data is null or empty");
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

    LogManager::getInstance().debug("RegisterUser message response: " + outputMessage.toString());

    return outputMessage;
}
