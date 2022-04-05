/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */


#ifndef __M_C_FACTORY_MESSAGE_H__
#define __M_C_FACTORY_MESSAGE_H__

#include <memory>

using namespace std;

#include "OperationCodeEnum.h"

#include "LoginMessage.h"
#include "EventMessage.h"
#include "StartUpMessage.h"
#include "RegisterUserMessage.h"


class M_CFactoryMessage
{
public:
    M_CFactoryMessage() {}

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
            case OperationCodeEnum::CODE_LOGIN:
                output = move( shared_ptr<LoginMessage> (new LoginMessage()) );
                break;
            case OperationCodeEnum::CODE_LOGIN_RESPONSE:
                break;
            case OperationCodeEnum::CODE_LOGOUT:
                break;

            case OperationCodeEnum::CODE_START_UP:
                output = move( shared_ptr<StartUpMessage> (new StartUpMessage()) );
                break;
            case OperationCodeEnum::CODE_START_UP_RESPONSE:
                break;
            case OperationCodeEnum::CODE_SHUTDOWN:
                break;
            case OperationCodeEnum::CODE_SHUTDOWN_RESPONSE:
                break;
           case OperationCodeEnum::CODE_PUBLISH_EVENT:
                output = move( shared_ptr<EventMessage> (new EventMessage()) );
                break;
            case OperationCodeEnum::CODE_REGISTER_USER:
                output = move( shared_ptr<RegisterUserMessage> (new RegisterUserMessage()) );
                break;
        }

        return output;
    }
};

#endif // __M_C_FACTORY_MESSAGE_H__

