/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __GET_MISSION_LAYERS_MESSAGE_H__
#define __GET_MISSION_LAYERS_MESSAGE_H__

#include "BaseMessage.h"

class GetMissionLayersMessage : public BaseMessage
{
public:
    GetMissionLayersMessage();    
    ~GetMissionLayersMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);

};

#endif // __GET_MISSION_LAYERS_MESSAGE_H__
