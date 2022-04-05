/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __REMOVE_MISSION_LAYER_MESSAGE_H__
#define __REMOVE_MISSION_LAYER_MESSAGE_H__

#include "BaseMessage.h"

// It Removes a new Mission to the database 
class RemoveMissionLayerMessage : public BaseMessage
{
public:
    RemoveMissionLayerMessage();
    ~RemoveMissionLayerMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __REMOVE_MISSION_LAYER_MESSAGE_H__

