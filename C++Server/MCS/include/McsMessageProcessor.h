/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __MCS_MESSAGE_PROCESSOR_H__
#define __MCS_MESSAGE_PROCESSOR_H__

#include "ServerWorker.h"
#include "ServerMessage.h"
#include "BaseMessage.h"


class McsMessageProcessor : public BaseMessage
{
    public:
        McsMessageProcessor();
        virtual ~McsMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);

    protected:

    private:

};

#endif // __MCS_MESSAGE_PROCESSOR_H__
