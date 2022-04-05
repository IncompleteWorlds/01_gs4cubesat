/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __GS_MESSAGE_PROCESSOR_H__
#define __GS_MESSAGE_PROCESSOR_H__

#include "ServerWorker.h"
#include "ServerMessage.h"
#include <BaseMessage.h>


class GsMessageProcessor : public BaseMessage
{
    public:
        GsMessageProcessor();
        virtual ~GsMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);

    protected:

    private:
};

#endif // __GS_MESSAGE_PROCESSOR_H__
