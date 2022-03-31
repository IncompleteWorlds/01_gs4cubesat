/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __GET_LAYER_PARAMETERS_MESSAGE_H__
#define __GET_LAYER_PARAMETERS_MESSAGE_H__

#include "BaseMessage.h"

class GetLayerParametersMessage : public BaseMessage
{
public:
    GetLayerParametersMessage();
    virtual ~GetLayerParametersMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);
};

#endif // __GET_LAYER_PARAMETERS_MESSAGE_H__
