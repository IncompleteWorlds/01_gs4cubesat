/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __REMOVE_GSN_MESSAGE_H__
#define __REMOVE_GSN_MESSAGE_H__

#include "BaseMessage.h"

/**
 * @class RemoveGsnMessage
 * @author Alberto
 * @date 11/11/17
 * @file RemoveGsnMessage.h
 * @brief It represents a received Delete Ground Station Message
 * See msg_remove_ground_station.json for a description of the contents
 * It will reply with a return code
 */

class RemoveGsnMessage : public BaseMessage
{
public:
    RemoveGsnMessage();
    ~RemoveGsnMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __REMOVE_GSN_MESSAGE_H__

