/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __STARTUPMESSAGE_H__
#define __STARTUPMESSAGE_H__

#include "BaseMessage.h"

// It represents a message send by a system at start up time
//
class StartUpMessage : public BaseMessage
{
public:
    StartUpMessage();
    ~StartUpMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);

protected:

};

#endif // __STARTUPMESSAGE_H__
