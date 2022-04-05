/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __UPDATE_SUBSYSTEM_MESSAGE_H__
#define __UPDATE_SUBSYSTEM_MESSAGE_H__

#include "BaseMessage.h"

// It adds a new Subsystem to the database 
class UpdateSubsystemMessage : public BaseMessage
{
public:
    UpdateSubsystemMessage();
    ~UpdateSubsystemMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __UPDATE_SUBSYSTEM_MESSAGE_H__

