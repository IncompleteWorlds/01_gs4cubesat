/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __REMOVE_SUBSYSTEM_MESSAGE_H__
#define __REMOVE_SUBSYSTEM_MESSAGE_H__

#include "BaseMessage.h"

// It Removes a new Subsystem to the database 
class RemoveSubsystemMessage : public BaseMessage
{
public:
    RemoveSubsystemMessage();
    ~RemoveSubsystemMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __REMOVE_SUBSYSTEM_MESSAGE_H__

