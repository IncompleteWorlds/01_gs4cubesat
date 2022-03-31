/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __GS_MESSAGE_PROCESSOR_H__
#define __GS_MESSAGE_PROCESSOR_H__

//#include "ServerWorkerZmq.h"
#include "ServerMessage.h"

#include "IMessageProcessor.h"


class GsMessageProcessor : public IMessageProcessor
{
    public:
        GsMessageProcessor();
        virtual ~GsMessageProcessor();

        // This is not needed, as we are not using the parent
        //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
        ServerMessage processMessage(const ServerMessage &inMessage);

    protected:

    private:
};

#endif // __GS_MESSAGE_PROCESSOR_H__
