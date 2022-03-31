/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __ARCHIVE_EVENT_MESSAGE_H__
#define __ARCHIVE_EVENT_MESSAGE_H__


#include "BaseMessage.h"

// It represents a received event
class EventMessage : public BaseMessage
{
public:
    EventMessage();
    ~EventMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);

protected:

};

#include "BaseMessage.h"



#endif // __ARCHIVE_EVENT_MESSAGE_H__
