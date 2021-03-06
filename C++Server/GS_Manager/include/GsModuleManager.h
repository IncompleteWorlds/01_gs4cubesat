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

using namespace std;

#include <boost/asio.hpp>

#include <zmq.hpp>

#include "ServerMessage.h"

#include "IModuleManager.h"



class GsModuleManager : public IModuleManager
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

        ModuleStatusEnum getStatus();


        // Send a message to the TM Processor
        void sendToTmProcessor(const ServerMessage &inMessage);


    protected:
        GsModuleManager();

    private:
        // We need to create a server object to accept incoming client connections.
        boost::asio::io_service io_service;

        // Flag for signaling end of message processing
        bool                          done_;

        // ZeroMQ context
        zmq::context_t                context_;

        // Send events to MCS TM Processor
        shared_ptr<zmq::socket_t>     tmProcessor_;

        void runZeroMQ();
        //void sendStartUpMessage();
};

#endif // __GS_MODULE_MANAGER_H__
