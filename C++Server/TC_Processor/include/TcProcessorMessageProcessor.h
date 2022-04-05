/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __HKTM_PROCESSOR_MESSAGE_PROCESSOR_H__
#define __HKTM_PROCESSOR_MESSAGE_PROCESSOR_H__

#include "ServerWorker.h"
#include "ServerMessage.h"
#include "BaseMessage.h"


class TcProcessorMessageProcessor : public BaseMessage
{
    public:
        TcProcessorMessageProcessor(ServerWorker &inWorker);
        virtual ~TcProcessorMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker &inParent);


    protected:
        ServerWorker& parent_;

    private:
};


#endif // __HKTM_PROCESSOR_MESSAGE_PROCESSOR_H__

