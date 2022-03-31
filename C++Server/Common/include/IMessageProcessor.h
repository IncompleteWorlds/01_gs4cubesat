/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __IMESSAGE_PROCESSOR_H__
#define __IMESSAGE_PROCESSOR_H__

#include "ServerMessage.h"

class ServerWorkerZmq;

/**
 * All message handlers shall implement this interface
 */
class IMessageProcessor
{
    public:
        IMessageProcessor() {};
        virtual ~IMessageProcessor() {};

        // Handler
        virtual ServerMessage processMessage(const ServerMessage &inMessage) = 0;

    protected:
};


#endif // __IMESSAGE_PROCESSOR_H__
