/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __TOOLS_MESSAGE_PROCESSOR_H__
#define __TOOLS_MESSAGE_PROCESSOR_H__


#include "ServerWorkerZmq.h"
#include "ServerMessage.h"
#include "BaseMessage.h"

/**
 * This class receives the Tools messages, which request a Tools service
 */
class ToolsMessageProcessor : public BaseMessage
{
    public:
        ToolsMessageProcessor();
        virtual ~ToolsMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);

    protected:

    private:

};

#endif // __TOOLS_MESSAGE_PROCESSOR_H__
