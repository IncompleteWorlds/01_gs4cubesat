/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */


#ifndef __TOOLS_FACTORY_MESSAGE_H__
#define __TOOLS_FACTORY_MESSAGE_H__

#include <memory>

using namespace std;

#include "BaseMessage.h"

#include "GetLayerParametersMessage.h"
#include "GetMissionMessage.h"
#include "GetFrameTypesMessage.h"
#include "GetMissionLayersMessage.h"
#include "ToolsLoginMessage.h"
#include "GetSatelliteMessage.h"
#include "ImportScDbMessage.h"
#include "RegisterUserMessage.h"
#include "AddMissionMessage.h"
#include "AddSatelliteMessage.h"
#include "UpdateMissionMessage.h"
#include "UpdateSatelliteMessage.h"
#include "RemoveSatelliteMessage.h"
#include "GetSubsystemMessage.h"
#include "AddSubsystemMessage.h"
#include "UpdateSubsystemMessage.h"
#include "RemoveSubsystemMessage.h"
#include "RemoveMissionMessage.h"
#include "GetDefaultMissionLayersMessage.h"
#include "AddMissionLayerMessage.h"
#include "RemoveMissionLayerMessage.h"


class ToolsFactoryMessage
{
public:
    ToolsFactoryMessage() {}

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
            case OperationCodeEnum::CODE_START_UP:
                break;
            case OperationCodeEnum::CODE_START_UP_RESPONSE:
                break;
            case OperationCodeEnum::CODE_SHUTDOWN:
                break;
            case OperationCodeEnum::CODE_SHUTDOWN_RESPONSE:
                break;

            // M&C 
            case OperationCodeEnum::CODE_LOGIN:
                output = move( shared_ptr<ToolsLoginMessage> (new ToolsLoginMessage()) );
                break;
            case OperationCodeEnum::CODE_LOGOUT:
                break;
            case OperationCodeEnum::CODE_REGISTER_USER:
                output = move( shared_ptr<RegisterUserMessage> (new RegisterUserMessage()) );
                break;
                
            // TOOLS                
            case OperationCodeEnum::CODE_GET_NODE: 
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
                
            case OperationCodeEnum::CODE_IMPORT_SC_DATABASE: // (from XTCE. Check YAMCS)
                output = move( shared_ptr<ImportScDbMessage> (new ImportScDbMessage()) );
                break;

            // ==== MISSION =================================
            case OperationCodeEnum::CODE_GET_MISSION:
                output = move( shared_ptr<GetMissionMessage> (new GetMissionMessage()) );
                break;
            case OperationCodeEnum::CODE_ADD_MISSION:
                output = move( shared_ptr<AddMissionMessage> (new AddMissionMessage()));
                break;

            case OperationCodeEnum::CODE_UPDATE_MISSION:
                output = move( shared_ptr<UpdateMissionMessage> (new UpdateMissionMessage()));
                break;
                
            case OperationCodeEnum::CODE_DELETE_MISSION:
                output = move( shared_ptr<RemoveMissionMessage> (new RemoveMissionMessage()));
                break;

            // ==== LAYERS =================================
            // Retrieve the parameters related to a Comm Layer
            case OperationCodeEnum::CODE_GET_LAYER_PARAMETERS:
                output = move( shared_ptr<GetLayerParametersMessage> (new GetLayerParametersMessage()) );
                break;
            // Retrieve the Frame definitions a layer will use
            case OperationCodeEnum::CODE_GET_LAYER_FRAME_TYPES:
                output = move( shared_ptr<GetFrameTypesMessage> (new GetFrameTypesMessage()) );
                break;
            case OperationCodeEnum::CODE_GET_MISSION_LAYERS:
                output = move( shared_ptr<GetMissionLayersMessage> (new GetMissionLayersMessage()) );
                break;
                
            case OperationCodeEnum::CODE_GET_DEFAULT_MISSION_LAYERS:
                output = move( shared_ptr<GetDefaultMissionLayersMessage> (new GetDefaultMissionLayersMessage()) );
                break;
                
            case OperationCodeEnum::CODE_ADD_MISSION_LAYER:
                output = move( shared_ptr<AddMissionLayerMessage> (new AddMissionLayerMessage()) );
                break;
            case OperationCodeEnum::CODE_DELETE_MISSION_LAYER:
                output = move( shared_ptr<RemoveMissionLayerMessage> (new RemoveMissionLayerMessage()) );
                break;
                
            // ==== SATELLITE =================================
            case OperationCodeEnum::CODE_ADD_SATELLITE:
                output = move( shared_ptr<AddSatelliteMessage> (new AddSatelliteMessage()));
                break;
            case OperationCodeEnum::CODE_GET_SATELLITE:
                output = move( shared_ptr<GetSatelliteMessage> (new GetSatelliteMessage()) );
                break;
            case OperationCodeEnum::CODE_UPDATE_SATELLITE:
                output = move( shared_ptr<UpdateSatelliteMessage> (new UpdateSatelliteMessage()) );
                break;
            case OperationCodeEnum::CODE_DELETE_SATELLITE:
                output = move( shared_ptr<RemoveSatelliteMessage> (new RemoveSatelliteMessage()) );
                break;
                
            // ==== SUBSYSTEM =================================
            case OperationCodeEnum::CODE_GET_SUBSYSTEM: 
                output = move( shared_ptr<GetSubsystemMessage> (new GetSubsystemMessage()) );
                break;
            case OperationCodeEnum::CODE_ADD_SUBSYSTEM:
                output = move( shared_ptr<AddSubsystemMessage> (new AddSubsystemMessage()) );
                break;
            case OperationCodeEnum::CODE_UPDATE_SUBSYSTEM:
                output = move( shared_ptr<UpdateSubsystemMessage> (new UpdateSubsystemMessage()) );
                break;
            case OperationCodeEnum::CODE_DELETE_SUBSYSTEM:
                output = move( shared_ptr<RemoveSubsystemMessage> (new RemoveSubsystemMessage()) );
                break;
                
            // ==== TC =================================
            case OperationCodeEnum::CODE_GET_TC: 
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
            case OperationCodeEnum::CODE_UPDATE_TC: 
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
            case OperationCodeEnum::CODE_ADD_TC: 
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
            case OperationCodeEnum::CODE_DELETE_TC:
                break;
            
            // ==== TM =================================
            case OperationCodeEnum::CODE_GET_TM: 
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
            case OperationCodeEnum::CODE_UPDATE_TM: 
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
            case OperationCodeEnum::CODE_ADD_TM: 
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
            case OperationCodeEnum::CODE_DELETE_TM:
                //output = move( shared_ptr<GetXXXXMessage> (new GetXXXXMessage()) );
                break;
    
            // ==== FRAMES =================================
            case OperationCodeEnum::CODE_ADD_FRAME:
                //output = move( shared_ptr<AddFrameMessage> (new addFrameMessage()) );
                break;
        }

        return output;
    }
};

#endif // __TOOLS_FACTORY_MESSAGE_H__

