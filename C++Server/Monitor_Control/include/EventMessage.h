/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __EVENT_MESSAGE_H__
#define __EVENT_MESSAGE_H__

#include "BaseMessage.h"

// It represents an event. It will be published in the
// Publisher socket, so, all subscribers will receive it
class EventMessage : public BaseMessage
{
public:
    EventMessage();
    ~EventMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);

protected:

};

#include "BaseMessage.h"



#endif // __EVENT_MESSAGE_H__
