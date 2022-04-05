/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __SERVERWORKER_H__
#define __SERVERWORKER_H__

#include <zmq.hpp>

#include "ServerMessage.h"

#include "IMessageProcessor.h"

//  Each worker task works on one request at a time and sends a reply

class ServerWorker {
    public:
        ServerWorker(zmq::context_t &ctx, int sock_type);
        virtual ~ServerWorker();

        void setMessageProcessor(MessageProcessorSharedPtr  inProcessor);

        ServerMessage forward(const string& inServerName, const ServerMessage& inMessage);

        virtual void run();

    protected:
        zmq::context_t             &ctx_;
        zmq::socket_t               worker_;
        bool                        done_;
        MessageProcessorSharedPtr   processor_;

        void internalRun();
};

#endif // __SERVERWORKER_H__

