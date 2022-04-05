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

#include "messages/GetSubsystemMessage.h"



GetSubsystemMessage::GetSubsystemMessage()
{
}

GetSubsystemMessage::~GetSubsystemMessage()
{
}

ServerMessage GetSubsystemMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_SUBSYSTEM)
    {
        // Extract the AVRO message from body
        IW::MsgGetSubsystem      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgGetSubsystem>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Subsystem
            if (avroInputMessage.satelliteName.empty() == false &&
                avroInputMessage.subsystemName.empty() == false)
            {
                IW::Subsystem   theSubsystem;

                theSubsystem = ToolsDatabase::getInstance().getSubsystemByName(avroInputMessage.satelliteName, avroInputMessage.subsystemName);

                // Generate response
                std::vector<uint8_t>   avroOutputMessage;

                avroOutputMessage = buildMessageVector<IW::Subsystem>(theSubsystem);

                outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_SUBSYSTEM_RESPONSE);
                outputMessage.setData(avroOutputMessage);
            }
            else
            {
                createReply(outputMessage, -1, "Subsystem identifier is null or empty");
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

    LogManager::getInstance().debug("Get Subsystem response: " + outputMessage.toString());

    return outputMessage;
}

