/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __NEW_RAW_FRAME_MESSAGE_H__
#define __NEW_RAW_FRAME_MESSAGE_H__

#include "BaseMessage.h"
#include "ServerMessage.h"

// The TM Processor has received a new raw frame from the
// Ground Station Manager (GS_Manager)
// It will return the MsgReturnData with the error code
class NewRawFrameMessage : public BaseMessage
{
public:
    NewRawFrameMessage();
    ~NewRawFrameMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

private:
    // Publish an event. Usually, a new frame (raw, processed) to the TM Dispatcher and
    // TM Archive
    void publishEvent(const ServerMessage &inMessage, ServerWorker &inParent);
};

#endif // __NEW_RAW_FRAME_MESSAGE_H__
