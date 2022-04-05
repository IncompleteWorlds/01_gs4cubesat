/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __UPDATE_MISSION_MESSAGE_H__
#define __UPDATE_MISSION_MESSAGE_H__

#include "BaseMessage.h"

// It adds a new mission to the database 
class UpdateMissionMessage : public BaseMessage
{
public:
    UpdateMissionMessage();
    ~UpdateMissionMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __UPDATE_MISSION_MESSAGE_H__

