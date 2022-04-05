/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __CONNECTGSMESSAGE_H__
#define __CONNECTGSMESSAGE_H__

#include "BaseMessage.h"

// It is a connect to a Ground Station Message
// It shall contain the station id to connect to
// It will return the connection id of the Ground Station or
// MsgReturnData with the error code
class ConnectGsnMessage : public BaseMessage
{
public:
    ConnectGsnMessage();
    ~ConnectGsnMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __CONNECTGSMESSAGE_H__

