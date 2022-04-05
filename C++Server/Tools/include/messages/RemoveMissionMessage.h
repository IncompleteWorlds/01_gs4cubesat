/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __REMOVE_MISSION_MESSAGE_H__
#define __REMOVE_MISSION_MESSAGE_H__

#include "BaseMessage.h"

// It Removes a new Mission to the database 
class RemoveMissionMessage : public BaseMessage
{
public:
    RemoveMissionMessage();
    ~RemoveMissionMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __REMOVE_MISSION_MESSAGE_H__

