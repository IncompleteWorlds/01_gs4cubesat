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

#include "TcProcessorModuleManager.h"
#include "TcProcessorFactoryMessage.h"

#include "TcProcessorMessageProcessor.h"


TcProcessorMessageProcessor::TcProcessorMessageProcessor(ServerWorker &inWorker)
    : BaseMessage{}, parent_{inWorker}
{
}

TcProcessorMessageProcessor::~TcProcessorMessageProcessor()
{
}

/**
 * Process received messages. They are received as an external component
 * requesting a service or as a response
 */
ServerMessage TcProcessorMessageProcessor::processMessage(const ServerMessage &inMessage, ServerWorker& inParent)
{
    ServerMessage  firstOutputMessage;

    // Process the message
    cout << "log.DEBUG  Message Processor. Process Msg: " << inMessage.getOperationCodeAsInt() << endl;

    // Create and store the message
    shared_ptr<BaseMessage> currentMessage = TcProcessorFactoryMessage::createMessage(inMessage);

    if (currentMessage.get() != nullptr)
    {
        // It is a bit redundant, but we are reusing IMessageProcessor interface
        firstOutputMessage = currentMessage->processMessage(inMessage, inParent);
    }
    else
    {
        createReply(firstOutputMessage, -1, "ERROR: Unknown message. IGNORED");
        // Unknown message
        cout << "ERROR: Unknown message. IGNORED" << endl;
    }

    return firstOutputMessage;
}


