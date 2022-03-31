/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __REMOVE_SATELLITE_MESSAGE_H__
#define __REMOVE_SATELLITE_MESSAGE_H__

#include "BaseMessage.h"

// It Removes a new SATELLITE to the database 
class RemoveSatelliteMessage : public BaseMessage
{
public:
    RemoveSatelliteMessage();
    ~RemoveSatelliteMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);


protected:

};

#endif // __REMOVE_SATELLITE_MESSAGE_H__

