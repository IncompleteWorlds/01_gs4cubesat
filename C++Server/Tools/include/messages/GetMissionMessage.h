/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __GET_MISSION_MESSAGE_H__
#define __GET_MISSION_MESSAGE_H__

#include "BaseMessage.h"

// It reads the current mission data from the database and
// return it. If there is an error, it will return
// MsgReturnData with the error code
class GetMissionMessage : public BaseMessage
{
public:
    GetMissionMessage();
    ~GetMissionMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __GET_MISSION_MESSAGE_H__

