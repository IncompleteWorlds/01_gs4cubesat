/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __ADD_SUBSYSTEM_MESSAGE_H__
#define __ADD_SUBSYSTEM_MESSAGE_H__

#include "BaseMessage.h"

// It adds a new Subsystem to the database 
class AddSubsystemMessage : public BaseMessage
{
public:
    AddSubsystemMessage();
    ~AddSubsystemMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __ADD_SUBSYSTEM_MESSAGE_H__

