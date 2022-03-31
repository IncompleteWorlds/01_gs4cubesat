/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#ifndef __FDS_MESSAGE__
#define __FDS_MESSAGE__

#include "BaseMessage.h" // Base class: BaseMessage

class FdsMessage : public BaseMessage
{
public:
    FdsMessage();
    virtual ~FdsMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
};

#endif // __FDS_MESSAGE__
