/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include "AvroTypes.h"

#include "ToolsModuleManager.h"
#include "ToolsFactoryMessage.h"

#include "MessageUtils.h"
#include "LogManager.h"

#include "ToolsMessageProcessor.h"

ToolsMessageProcessor::ToolsMessageProcessor()
    : BaseMessage{}
{
}

ToolsMessageProcessor::~ToolsMessageProcessor()
{
}

ServerMessage ToolsMessageProcessor::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    ServerMessage  firstOutputMessage;

    // Process the message
    LogManager::getInstance().debug("Message Processor. Process Msg: " + const_cast<ServerMessage&>(inMessage).getOperationCodeAsString() );

    // Create and store the message
    shared_ptr<BaseMessage> currentMessage = ToolsFactoryMessage::createMessage(inMessage);

    if (currentMessage.get() != nullptr)
    {
        // It is a bit redundant, but we are reusing IMessageProcessor interface
        firstOutputMessage = currentMessage->processMessage(inMessage, inParent);
    }
    else
    {
        createReply(firstOutputMessage, -1, "ERROR: Unknown message. IGNORED");
        // Unknown message
        LogManager::getInstance().error("Unknown message. IGNORED");
    }

    return firstOutputMessage;
}

