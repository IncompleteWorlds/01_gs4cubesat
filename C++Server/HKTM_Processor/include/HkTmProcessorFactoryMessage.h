/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __HKTM_PROCESSOR_FACTORY_MESSAGE_H__
#define __HKTM_PROCESSOR_FACTORY_MESSAGE_H__

#include <memory>

using namespace std;

#include "OperationCodeEnum.h"
#include "BaseMessage.h"

#include "messages/NewRawFrameMessage.h"


class HkTmProcessorFactoryMessage
{
public:
    HkTmProcessorFactoryMessage() {}

    static shared_ptr<BaseMessage> createMessage(const ServerMessage &inMessage)
    {
        shared_ptr<BaseMessage> output{nullptr};

        switch(inMessage.getOperationCode())
        {
            case OperationCodeEnum::CODE_NONE:
                break;

            // GENERAL
            case OperationCodeEnum::CODE_REPLY_MESSAGE:
                break;
            case OperationCodeEnum::CODE_END_PROCESSING:
                break;


            // M_C
            case OperationCodeEnum::CODE_START_UP:
                break;
            case OperationCodeEnum::CODE_START_UP_RESPONSE:
                break;
            case OperationCodeEnum::CODE_SHUTDOWN:
                break;
            case OperationCodeEnum::CODE_SHUTDOWN_RESPONSE:
                break;


            // MCS
            // A new frame has been received from the GS Manager
            // This is an special case that is handled without a message
            case OperationCodeEnum::CODE_NEW_RAW_FRAME:
                break;
        }

        return output;
    }
};

#endif // __HKTM_PROCESSOR_FACTORY_MESSAGE_H__

