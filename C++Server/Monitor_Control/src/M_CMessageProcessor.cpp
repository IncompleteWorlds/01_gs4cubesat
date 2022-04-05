/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <memory>
#include <thread>

using namespace std;

#include "AvroTypes.h"

#include "M_CModuleManager.h"
#include "M_CFactoryMessage.h"
#include "MessageUtils.h"
#include "LogManager.h"

#include "M_CMessageProcessor.h"


M_CMessageProcessor::M_CMessageProcessor()
    : BaseMessage{}
{
}

M_CMessageProcessor::~M_CMessageProcessor()
{
}

/**
 * Process received messages. They are received as an external component
 * requesting a service or as a response
 */
ServerMessage M_CMessageProcessor::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    ServerMessage  firstOutputMessage;

    // Process the message
    LogManager::getInstance().debug("Message Processor. Process Msg: " + const_cast<ServerMessage&>(inMessage).getOperationCodeAsString());

    // Create and store the message
    shared_ptr<BaseMessage> currentMessage = M_CFactoryMessage::createMessage(inMessage);

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

