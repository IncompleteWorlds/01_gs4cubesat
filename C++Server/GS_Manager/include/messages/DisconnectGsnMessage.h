/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __DISCONNECT_H__
#define __DISCONNECT_H__

#include "BaseMessage.h"

// It is a disconnect to a Ground Station Message
// It shall contain the station id to disconnect from
class DisconnectGsnMessage : public BaseMessage
{
public:
    DisconnectGsnMessage();
    ~DisconnectGsnMessage();

    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __DISCONNECT_H__

