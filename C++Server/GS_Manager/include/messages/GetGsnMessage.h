/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __GET_GSN_MESSAGE_H__
#define __GET_GSN_MESSAGE_H__

#include "BaseMessage.h"

// It represents a received Get Ground Station Message
// It shall contain:
// - Station id. Only returns the station identified by its name
// - Station name. Only returns the station identified by its name
// - Station code. Only returns the station identified by its code
// - None. If all criteria are empty or null, it will return all stations
//
// It will reply with a list of ground station or msg_return_data
class GetGsnMessage : public BaseMessage
{
public:
    GetGsnMessage();
    ~GetGsnMessage();

    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __GET_GSN_MESSAGE_H__

