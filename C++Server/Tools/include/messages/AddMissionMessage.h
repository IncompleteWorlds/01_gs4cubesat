/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __ADD_MISSION_MESSAGE_H__
#define __ADD_MISSION_MESSAGE_H__

#include "BaseMessage.h"

// It adds a new mission to the database 
class AddMissionMessage : public BaseMessage
{
public:
    AddMissionMessage();
    ~AddMissionMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __ADD_MISSION_MESSAGE_H__

