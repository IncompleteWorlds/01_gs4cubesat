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
#include "ConfigurationManager.h"
#include "ToolsDatabase.h"
#include "LogManager.h"

#include "ToolsLoginMessage.h"

using namespace IW;


ToolsLoginMessage::ToolsLoginMessage()
{
}

ToolsLoginMessage::~ToolsLoginMessage()
{
}

// Process the reply to a previous (this) message
// or
// Process and send the message
// Process this login message
ServerMessage ToolsLoginMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;
    IW::MsgReturnData      outputData;


    // It has to be a Login message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_LOGIN)
    {
        // Extract the AVRO message from body
        IW::MsgLogin avroInputMessage;

        extractMessageVector<IW::MsgLogin>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

        // Read user data
        IW::User   theUser;

        // TEMP
        // Create temporary user
//        ToolsDatabase::getInstance().createUser("user01", avroInputMessage.hashPassword, "user01", "user01", "mission1", 2);
//        ToolsDatabase::getInstance().createUser("admin", avroInputMessage.hashPassword, "admin", "admin", "mission1", 3);
//        ToolsDatabase::getInstance().createUser("ro", avroInputMessage.hashPassword, "read-only", "read-only", "mission1", 1);

        theUser = ToolsDatabase::getInstance().getUserByName(avroInputMessage.userName);
        
        // Compare hash passwords
        if (theUser.password == avroInputMessage.hashPassword)
        {
            // If no error, return user data including role
            // Fill message
            IW::MsgLoginResponse    loginResponse;
            std::vector<uint8_t>    avroOutputMessage;

            loginResponse.userData = theUser;
            // TODO:
            //   - Generate authorization token
            //   - Store in a table per user
            //   - Set expire time
            loginResponse.authorizationToken="TODO";

            avroOutputMessage = buildMessageVector<IW::MsgLoginResponse>(loginResponse);

            outputMessage.setOperationCode(OperationCodeEnum::CODE_LOGIN_RESPONSE);
            outputMessage.setData(avroOutputMessage);
        }
        else
        {
            // If error, return error message
            string errorMessage = "Invalid password";
            LogManager::getInstance().error(errorMessage);

            createReply(outputMessage, -1, errorMessage);
        }
    }
    else
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        LogManager::getInstance().error(errorMessage);

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Login message response: " + outputMessage.toString());

    return outputMessage;
}
