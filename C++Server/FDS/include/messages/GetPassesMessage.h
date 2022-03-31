/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#ifndef __GET_PASSES_MESSAGE__
#define __GET_PASSES_MESSAGE__

#include "BaseMessage.h" // Base class: BaseMessage

class GetPassesMessage : public BaseMessage
{
public:
    GetPassesMessage();
    virtual ~GetPassesMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);
};

#endif // __GET_PASSES_MESSAGE__
