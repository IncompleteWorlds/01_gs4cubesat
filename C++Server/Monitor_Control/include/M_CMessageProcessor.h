/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __M_CMESSAGEPROCESSOR_H__
#define __M_CMESSAGEPROCESSOR_H__

#include "ServerWorkerZmq.h"
#include "ServerMessage.h"
#include "BaseMessage.h"


class M_CMessageProcessor : public BaseMessage
{
    public:
        M_CMessageProcessor();
        virtual ~M_CMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);


    protected:

    private:


};

#endif // __M_CMESSAGEPROCESSOR_H__
