/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __IMESSAGE_PROCESSOR_NNG_H__
#define __IMESSAGE_PROCESSOR_NNG_H__

#include "ServerMessage.h"

class ServerWorkerNng;

/**
 * All message handlers shall implement this interface
 */
class IMessageProcessorNng : public IMessageProcessor
{
    public:
        IMessageProcessorNng() {};
        virtual ~IMessageProcessorNng() {};

        // Handler
        //virtual ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerNng& inParent) = 0;
        virtual ServerMessage processMessage(const ServerMessage &inMessage) = 0;

    protected:
};

#endif // __IMESSAGE_PROCESSOR_NNG_H__
