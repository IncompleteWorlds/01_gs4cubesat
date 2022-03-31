/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __HKTM_PROCESSOR_MESSAGE_PROCESSOR_H__
#define __HKTM_PROCESSOR_MESSAGE_PROCESSOR_H__

#include "ServerWorkerZmq.h"
#include "ServerMessage.h"
#include "BaseMessage.h"


class HkTmProcessorMessageProcessor : public BaseMessage
{
    public:
        HkTmProcessorMessageProcessor();
        virtual ~HkTmProcessorMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent);


    protected:
        uint32_t  frameCounter_;
    
        void processNewRawFrame(const ServerMessage &inMessage);


    private:
};


#endif // __HKTM_PROCESSOR_MESSAGE_PROCESSOR_H__

