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

#include "messages/UpdateSubsystemMessage.h"



UpdateSubsystemMessage::UpdateSubsystemMessage()
{
}

UpdateSubsystemMessage::~UpdateSubsystemMessage()
{
}

ServerMessage UpdateSubsystemMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_UPDATE_SUBSYSTEM)
    {
        // Extract the AVRO message from body
        IW::MsgUpdateSubsystem      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgUpdateSubsystem>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);
        
            ToolsDatabase::getInstance().updateSubsystem(avroInputMessage.subsystem);
            
            // Generate response
            createReply(outputMessage, 0, "Subsystem correctly updated");
            
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

    LogManager::getInstance().debug("Update Subsystem response: " + outputMessage.toString());

    return outputMessage;
}

