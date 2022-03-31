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
#include "ServerWorkerZmq.h"
#include "ConfigurationManager.h"
#include "LogManager.h"

#include "RegisterUserMessage.h"

using namespace IW;


RegisterUserMessage::RegisterUserMessage()
{
}

RegisterUserMessage::~RegisterUserMessage()
{
}

ServerMessage RegisterUserMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;
    
    LogManager::getInstance().debug("Start:  RegisterUser Message");

    // It has to be a RegisterUser message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_REGISTER_USER)
    {
        ServerMessage toolsResponse = inParent.forward(ConfigurationManager::KEY_ZEROMQ_TOOLS_SERVER_ADDRESS, inMessage);

        if (toolsResponse.getOperationCode() == OperationCodeEnum::CODE_REPLY_MESSAGE)
        {
            // Forward the output message
            outputMessage = toolsResponse;
        }
        else
        {
            string errorMessage = "Invalid received response message: " + toolsResponse.toString();
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

    LogManager::getInstance().debug("RegisterUser message response: " + outputMessage.toString());

    return outputMessage;
}
