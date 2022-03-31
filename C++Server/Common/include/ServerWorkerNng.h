/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __SERVERWORKER_NNG_H__
#define __SERVERWORKER_NNG_H__

// Nanomsg
#include <nngpp/nngpp.h>
#include <nngpp/protocol/req0.h>
#include <nngpp/protocol/rep0.h>
#include <nngpp/protocol/bus0.h>

#include "ServerMessage.h"

#include "IMessageProcessor.h"

//  Each worker task works on one request at a time and sends a reply

class ServerWorkerNng {
    public:
        ServerWorkerNng();
        virtual ~ServerWorkerNng();

        void setMessageProcessor(MessageProcessorSharedPtr  inProcessor);

        ServerMessage forward(const string& inServerName, const ServerMessage& inMessage);

        virtual void run();
        
        void setDone(const bool inFlag)
        {
            done_ = inFlag;
        }

    protected:
        nng::socket                 worker_;
        bool                        done_;
        MessageProcessorSharedPtr   processor_;

        void internalRun();
};

#endif // __SERVERWORKER_H__

