/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include "AvroTypes.h"

#include "FdsModuleManager.h"
#include "FdsFactoryMessage.h"

#include "MessageUtils.h"
#include "LogManager.h"

#include "FdsMessageProcessor.h"

FdsMessageProcessor::FdsMessageProcessor()
    : BaseMessage{}
{
}

FdsMessageProcessor::~FdsMessageProcessor()
{
}

ServerMessage FdsMessageProcessor::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    ServerMessage  firstOutputMessage;

    // Process the message
    LogManager::getInstance().debug("Message Processor. Process Msg: " + const_cast<ServerMessage&>(inMessage).getOperationCodeAsString() );

    // Create and store the message
    shared_ptr<BaseMessage> currentMessage = FdsFactoryMessage::createMessage(inMessage);

    if (currentMessage.get() != nullptr)
    {
        // It is a bit redundant, but we are reusing IMessageProcessor interface
        firstOutputMessage = currentMessage->processMessage(inMessage);
    }
    else
    {
        createReply(firstOutputMessage, -1, "ERROR: Unknown message. IGNORED");
        // Unknown message
        LogManager::getInstance().error("Unknown message. IGNORED");
    }

    return firstOutputMessage;
}

