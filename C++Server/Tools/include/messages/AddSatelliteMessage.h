/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __ADD_SATELLITE_MESSAGE_H__
#define __ADD_SATELLITE_MESSAGE_H__

#include "BaseMessage.h"

// It adds a new SATELLITE to the database 
class AddSatelliteMessage : public BaseMessage
{
public:
    AddSatelliteMessage();
    ~AddSatelliteMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __ADD_SATELLITE_MESSAGE_H__

