/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include "ConfigurationManager.h"
#include "OperationCodeEnum.h"
#include "McsModuleManager.h"
#include "GSException.h"
#include "McsFactoryMessage.h"

#include "MessageUtils.h"

#include "McsMessageProcessor.h"


McsMessageProcessor::McsMessageProcessor()
    : BaseMessage{}
{
}

McsMessageProcessor::~McsMessageProcessor()
{
}

ServerMessage McsMessageProcessor::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    ServerMessage  firstOutputMessage;

    // Process the message
    cout << "log.DEBUG  Message Processor. Process Msg: " << inMessage.getOperationCodeAsInt() << endl;

    if (inMessage.getOperationCode() > OperationCodeEnum::CODE_START_GS_MANAGER &&
        inMessage.getOperationCode() < OperationCodeEnum::CODE_END_GS_MANAGER)
    {
        // Forward message to GS Manager
        // It will only forward the data
        firstOutputMessage = inParent.forward(ConfigurationManager::KEY_ZEROMQ_GS_MANAGER_SERVER_ADDRESS,
                                               const_cast<const ServerMessage&>(inMessage));
    }
    else
    {
        if (inMessage.getOperationCode() > OperationCodeEnum::CODE_START_MCS &&
            inMessage.getOperationCode() < OperationCodeEnum::CODE_END_MCS)
        {
            // Create and store the message
            shared_ptr<BaseMessage> currentMessage = McsFactoryMessage::createMessage(inMessage);

            if (currentMessage.get() != nullptr)
            {
                // It is a bit redundant, but we are reusing IMessageProcessor interface
                firstOutputMessage = currentMessage->processMessage(inMessage, inParent);
            }
        }
        else
        {
            createReply(firstOutputMessage, -1, "ERROR: Unknown message. IGNORED");
            // Unknown message
            cout << "ERROR: Unknown message. IGNORED" << endl;
        }
    }

    return firstOutputMessage;
}


