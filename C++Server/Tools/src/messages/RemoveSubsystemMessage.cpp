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

#include "messages/RemoveSubsystemMessage.h"



RemoveSubsystemMessage::RemoveSubsystemMessage()
{
}

RemoveSubsystemMessage::~RemoveSubsystemMessage()
{
}

ServerMessage RemoveSubsystemMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_DELETE_SUBSYSTEM)
    {
        // Extract the AVRO message from body
        IW::MsgRemoveSubsystem      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgRemoveSubsystem>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Subsystem
            if (avroInputMessage.satelliteName.empty() == false &&
                avroInputMessage.subsystemName.empty() == false)
            {
                ToolsDatabase::getInstance().removeSubsystem(avroInputMessage.subsystemName);
                
                createReply(outputMessage, 0, "Subsystem correctly removed");                
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

    LogManager::getInstance().debug("Remove Subsystem response: " + outputMessage.toString());

    return outputMessage;
}

