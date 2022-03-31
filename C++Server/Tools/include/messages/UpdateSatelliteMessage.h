/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __UPDATE_SATELLITE_MESSAGE_H__
#define __UPDATE_SATELLITE_MESSAGE_H__

#include "BaseMessage.h"

// It updates an existing Satellite to the database 
class UpdateSatelliteMessage : public BaseMessage
{
public:
    UpdateSatelliteMessage();
    ~UpdateSatelliteMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);


protected:

};

#endif // __UPDATE_SATELLITE_MESSAGE_H__

