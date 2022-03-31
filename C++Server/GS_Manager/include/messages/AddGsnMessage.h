/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __ADD_GSN_MESSAGE_H__
#define __ADD_GSN_MESSAGE_H__

#include "BaseMessage.h"

/**
 * @class AddGsnMessage
 * @author Alberto
 * @date 11/11/17
 * @file AddGsnMessage.h
 * @brief It represents a received Add Ground Station Message
 * See msg_add_ground_station.json for a description of the contents
 * It will reply with a Ground Station object
 */

class AddGsnMessage : public BaseMessage
{
public:
    AddGsnMessage();
    ~AddGsnMessage();

    ServerMessage processMessage(const ServerMessage &inMessage);


protected:

};

#endif // __GET_GSN_MESSAGE_H__

