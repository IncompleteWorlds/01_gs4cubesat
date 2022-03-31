/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#ifndef __START_EXECUTION_MESSAGE__
#define __START_EXECUTION_MESSAGE__

#include "BaseMessage.h" // Base class: BaseMessage

class StartExecutionMessage : public BaseMessage
{
    public:
        StartExecutionMessage();
        virtual ~StartExecutionMessage();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
        ServerMessage processMessage(const ServerMessage &inMessage);

    protected:

    private:
        ServerMessage runExternalModule(IW::FdsModule &inModule);
        ServerMessage runInternalModule(IW::FdsModule &inModule);
    
};

#endif // __START_EXECUTION_MESSAGE__
