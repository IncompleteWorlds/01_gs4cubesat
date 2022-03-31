/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __GS_MODULE_MANAGER_H__
#define __GS_MODULE_MANAGER_H__

#include <map>
#include <string>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

//#include <boost/asio.hpp>

#include "ServerWorkerNng.h"
#include "ServerWorkerTransferNng.h"
#include "ServerMessage.h"

#include "IModuleManagerNng.h"



class GsModuleManager : public IModuleManagerNng
{
    public:
        // Singleton
        static GsModuleManager& getInstance()
        {
            static GsModuleManager instance;

            return instance;
        }

        virtual ~GsModuleManager();

        // delete copy and move constructors and assign operators
        GsModuleManager(GsModuleManager const&) = delete;             // Copy construct
        GsModuleManager(GsModuleManager&&) = delete;                  // Move construct
        GsModuleManager& operator=(GsModuleManager const&) = delete;  // Copy assign
        GsModuleManager& operator=(GsModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();


        // Send a message to the TM Processor
        void sendToTmProcessor(const ServerMessage &inMessage);


    protected:
        GsModuleManager();

    private:
        // We need to create a server object to accept incoming client connections.
        // TODO: Nanomsg includes Asynchronous IO
        //boost::asio::io_service io_service_;

        // Flag for signaling end of message processing
        bool               done_;

        // ZeroMQ context
        //zmq::context_t                context_;
        
        // Nanomsg sockets
        nng::socket      reply_;
        nng::socket      backend_;
        
        shared_ptr<thread>      backendThread_;
        shared_ptr<thread>      logBusThread_;
        shared_ptr<thread>      eventBusThread_;
        
        shared_ptr<ServerWorkerNng>          backendWorker_;
        shared_ptr<ServerWorkerTransferNng>  transferWorkerLog_;
        shared_ptr<ServerWorkerTransferNng>  transferWorkerEvent_;


        // Send events to MCS TM Processor
        nng::socket      tmProcessor_;

        void runMQ();
        //void sendStartUpMessage();
};

#endif // __GS_MODULE_MANAGER_H__
