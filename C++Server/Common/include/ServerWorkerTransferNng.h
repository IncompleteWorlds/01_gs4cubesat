/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */
 
#ifndef __SERVERWORKERTRANSFER_NNG_H__
#define __SERVERWORKERTRANSFER_NNG_H__

#include <memory>

using namespace std;

//#include <nngpp/nngpp.h>
//#include <nngpp/protocol/req0.h>
//#include <nngpp/protocol/rep0.h>


// This class is a thread. It receives a message and transfers it to a central processing
// thread by using an Req/Rep socket
class ServerWorkerTransferNng
{
    public:
        ServerWorkerTransferNng(nng::socket& inInput, nng::socket& inOutput);
        virtual ~ServerWorkerTransferNng();

        void run();
        
        void setDone(const bool inFlag)
        {
            done_ = inFlag;
        }

    protected:
        shared_ptr<nng::socket>     inputSocket_;
        shared_ptr<nng::socket>     outputSocket_;
        bool                        done_;

        void internalRun();
};

#endif // __SERVERWORKERTRANSFER_H__
