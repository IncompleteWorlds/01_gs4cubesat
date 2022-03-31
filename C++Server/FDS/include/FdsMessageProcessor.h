/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __FDS_MESSAGE_PROCESSOR_H__
#define __FDS_MESSAGE_PROCESSOR_H__


#include "ServerWorkerZmq.h"
#include "ServerMessage.h"
#include "BaseMessage.h"

/**
 * This class receives the Fds messages, which request a FDS service
 */
class FdsMessageProcessor : public BaseMessage
{
    public:
        FdsMessageProcessor();
        virtual ~FdsMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);

    protected:

    private:

};

#endif // __FDS_MESSAGE_PROCESSOR_H__
