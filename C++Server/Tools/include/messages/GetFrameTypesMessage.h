/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __GET_FRAME_TYPES_MESSAGE_H__
#define __GET_FRAME_TYPES_MESSAGE_H__

#include "BaseMessage.h"

class GetFrameTypesMessage : public BaseMessage
{
public:
    GetFrameTypesMessage();
    virtual ~GetFrameTypesMessage();
    
    // Handler
    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);
};

#endif // __GET_FRAME_TYPES_MESSAGE_H__
