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
#include "MessageUtils.h"

#include "GsFactoryMessage.h"
#include "GsMessageProcessor.h"
#include "LogManager.h"


GsMessageProcessor::GsMessageProcessor()
{
}

GsMessageProcessor::~GsMessageProcessor()
{
}

/**
 * Process received messages. They are received as an external component
 * requesting a service or as a response
 */
ServerMessage GsMessageProcessor::processMessage(const ServerMessage &inMessage)
{
    ServerMessage  firstOutputMessage;

    // Process the message
    LogManager::getInstance().debug("Message Processor. Process Msg: " + static_cast<ServerMessage>(inMessage).toStringShort());

    // Create and store the message
    shared_ptr<BaseMessage> currentMessage = GsFactoryMessage::createMessage(inMessage);

    if (currentMessage.get() != nullptr)
    {
        // It is a bit redundant, but we are reusing IMessageProcessor interface
        firstOutputMessage = currentMessage->processMessage(inMessage);
    }
    else
    {
        string errorMessage{"ERROR: Unknown message. IGNORED"};
        
        // Unknown message
        LogManager::getInstance().error(errorMessage);
        ::createReply(firstOutputMessage, -1, errorMessage);
    }

    return firstOutputMessage;
}

