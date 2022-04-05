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

#include "messages/AddSubsystemMessage.h"



AddSubsystemMessage::AddSubsystemMessage()
{
}

AddSubsystemMessage::~AddSubsystemMessage()
{
}

ServerMessage AddSubsystemMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_ADD_SUBSYSTEM)
    {
        // Extract the AVRO message from body
        IW::MsgAddSubsystem      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgAddSubsystem>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Subsystem
            if (avroInputMessage.satelliteName.empty() == false)
            {
                int64_t       subsystemId;

                subsystemId = ToolsDatabase::getInstance().createSubsystem(avroInputMessage.subsystem);
                
                createReply(outputMessage, 0, "Subsystem correctly created");
            }
            else
            {
                createReply(outputMessage, -1, "Subsystem name is null or empty");
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

    LogManager::getInstance().debug("Add Subsystem response: " + outputMessage.toString());

    return outputMessage;
}

