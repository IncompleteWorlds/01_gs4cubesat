/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __GS_FACTORY_MESSAGE_H__
#define __GS_FACTORY_MESSAGE_H__

#include <memory>

using namespace std;

#include "OperationCodeEnum.h"

#include "messages/GetGsnMessage.h"
#include "messages/ConnectGsnMessage.h"
#include "messages/DisconnectGsnMessage.h"
#include "messages/AddGsnMessage.h"
#include "messages/RemoveGsnMessage.h"



class GsFactoryMessage
{
public:
    GsFactoryMessage() {}

    static shared_ptr<BaseMessage> createMessage(const ServerMessage &inMessage)
    {
        shared_ptr<BaseMessage> output{nullptr};

        switch(inMessage.getOperationCode())
        {
            // GENERAL
            case OperationCodeEnum::CODE_START_UP:
                break;
            case OperationCodeEnum::CODE_START_UP_RESPONSE:
                break;
            case OperationCodeEnum::CODE_SHUTDOWN:
                break;


            // GS MANAGER
            case OperationCodeEnum::CODE_CONNECT_GROUND_STATION:
                output = move( shared_ptr<ConnectGsnMessage> (new ConnectGsnMessage()) );
                break;
            case OperationCodeEnum::CODE_DISCONNECT_GROUND_STATION:
                output = move( shared_ptr<DisconnectGsnMessage> (new DisconnectGsnMessage()) );
                break;
            case OperationCodeEnum::CODE_SEND_FRAME_GROUND_STATION:
                break;
            case OperationCodeEnum::CODE_ADD_GROUND_STATION:
                output = move( shared_ptr<AddGsnMessage> (new AddGsnMessage()) );
                break;
            case OperationCodeEnum::CODE_REMOVE_GROUND_STATION:
                output = move( shared_ptr<RemoveGsnMessage> (new RemoveGsnMessage()) );
                break;
            case OperationCodeEnum::CODE_UPDATE_GROUND_STATION:
                break;
            case OperationCodeEnum::CODE_GET_GROUND_STATION:
                output = move( shared_ptr<GetGsnMessage> (new GetGsnMessage()) );
                break;



            default:
                // Do nothing
                break;
        }

        return output;
    }
};

#endif // __GS_FACTORY_MESSAGE_H__

