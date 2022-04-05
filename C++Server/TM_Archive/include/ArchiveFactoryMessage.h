/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */


#ifndef __ARCHIVE_FACTORY_MESSAGE_H__
#define __ARCHIVE_FACTORY_MESSAGE_H__

#include <memory>

using namespace std;

#include "OperationCodeEnum.h"

#include "BaseMessage.h"

#include "EventMessage.h"

class ArchiveFactoryMessage
{
public:
    ArchiveFactoryMessage() {}

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

            // Events
            case OperationCodeEnum::CODE_PUBLISH_EVENT:
                output = move( shared_ptr<EventMessage> (new EventMessage()) );
                break;
        }

        return output;
    }
};

#endif // __ARCHIVE_FACTORY_MESSAGE_H__


