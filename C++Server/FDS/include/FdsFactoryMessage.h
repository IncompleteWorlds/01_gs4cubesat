/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */


#ifndef __FDS_FACTORY_MESSAGE_H__
#define __FDS_FACTORY_MESSAGE_H__

#include <memory>

using namespace std;

#include "BaseMessage.h"

#include "messages/GetPassesMessage.h"
#include "messages/StartExecutionMessage.h"



class FdsFactoryMessage
{
public:
    FdsFactoryMessage() {}

    static shared_ptr<BaseMessage> createMessage(const ServerMessage &inMessage)
    {
        shared_ptr<BaseMessage> output{nullptr};

        switch(inMessage.getOperationCode())
        {
            case OperationCodeEnum::CODE_NONE:
                break;
                
            // Start up of the module
            case OperationCodeEnum::CODE_START_UP:
                break;
                
            // Shutdown
            case OperationCodeEnum::CODE_SHUTDOWN:
                // FIX ME
                // To create a message and return it or
                //
                // To execute: FdsModuleManager::getInstance().shutdown()
                break;

            case OperationCodeEnum::CODE_GET_PASSES:
                output = move( shared_ptr<GetPassesMessage> (new GetPassesMessage()) );
                break;
                
            case OperationCodeEnum::CODE_START_EXECUTION:
                output = move( shared_ptr<StartExecutionMessage> (new StartExecutionMessage()) );
                break;
                
//            case OperationCodeEnum::CODE_STOP_EXECUTION:
//                output = move( shared_ptr<StopExecutionMessage> (new StopExecutionMessage()) );
//                break;
                
//            case OperationCodeEnum::CODE_FDS_MESSAGE:
//                output = move( shared_ptr<FdsMessage> (new FdsMessage()) );
//                break;
        }

        return output;
    }
};

#endif // __FDS_FACTORY_MESSAGE_H__

