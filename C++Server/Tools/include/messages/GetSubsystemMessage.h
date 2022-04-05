/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */


#ifndef __GET_SUBSYSTEM_MESSAGE_H__
#define __GET_SUBSYSTEM_MESSAGE_H__

#include "BaseMessage.h"

// It reads the current Subsystem data from the database and
// return it. If there is an error, it will return
// MsgReturnData with the error code
class GetSubsystemMessage : public BaseMessage
{
public:
    GetSubsystemMessage();
    ~GetSubsystemMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __GET_SUBSYSTEM_MESSAGE_H__

