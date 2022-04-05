/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __SERVERWORKERSUB_H__
#define __SERVERWORKERSUB_H__

#include <string>

using namespace std;

#include <zmq.hpp>


#include "ServerWorker.h"



//  Each worker task works on one request at a time and sends a reply

class ServerWorkerSub : public ServerWorker {
    public:
        ServerWorkerSub(zmq::context_t &ctx, int inSockType, string &inServerName, string &inSubAddress);
        virtual ~ServerWorkerSub();

        void subscribe(const string& inOptions);

        virtual void run();

    protected:
        string    name_;
        string    address_;
};

#endif // __SERVERWORKERSUB_H__

