/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#ifndef __STOP_EXECUTION_MESSAGE__
#define __STOP_EXECUTION_MESSAGE__

#include "BaseMessage.h" // Base class: BaseMessage

class StopExecutionMessage : public BaseMessage
{
public:
    StopExecutionMessage();
    virtual ~StopExecutionMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
};

#endif // __STOP_EXECUTION_MESSAGE__
