/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __GET_SATELLITE_MESSAGE_H__
#define __GET_SATELLITE_MESSAGE_H__

#include "BaseMessage.h"

// It returns one or several satellites that belongs to a mission
// If there is an error, it will return MsgReturnData with the error code
class GetSatelliteMessage : public BaseMessage
{
public:
    GetSatelliteMessage();
    ~GetSatelliteMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __GET_SATELLITE_MESSAGE_H__


