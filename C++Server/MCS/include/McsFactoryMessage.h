/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __MCS_FACTORY_MESSAGE_H__
#define __MCS_FACTORY_MESSAGE_H__

#include <memory>

using namespace std;

#include "messages/ExampleMcsMessage.h"



class McsFactoryMessage
{
public:
    McsFactoryMessage() {}

    static shared_ptr<BaseMessage> createMessage(const ServerMessage &inMessage)
    {
        shared_ptr<BaseMessage> output{nullptr};

        switch(inMessage.getOperationCode())
        {
            case OperationCodeEnum::CODE_NONE:
                break;

            // MCS



        }

        return output;
    }
};

#endif // __MCS_FACTORY_MESSAGE_H__

