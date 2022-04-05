/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __M_CMODULEMANAGER_H__
#define __M_CMODULEMANAGER_H__


#include <map>
#include <string>
#include <memory>
#include <mutex>          // Lock & mutex


using namespace std;

#include <zmq.hpp>

#include "ServerMessage.h"
#include "IModuleManager.h"



class M_CModuleManager : public IModuleManager
{
    public:
        // Singleton
        static M_CModuleManager& getInstance()
        {
            static M_CModuleManager instance;

            return instance;
        }

        virtual ~M_CModuleManager();

        // delete copy and move constructors and assign operators
        M_CModuleManager(M_CModuleManager const&) = delete;             // Copy construct
        M_CModuleManager(M_CModuleManager&&) = delete;                  // Move construct
        M_CModuleManager& operator=(M_CModuleManager const&) = delete;  // Copy assign
        M_CModuleManager& operator=(M_CModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();

        // Publisher
        void publishMessage(const ServerMessage& inMessage);


    protected:
        M_CModuleManager();

    private:
        // Flag for signaling end of message processing
        bool                          done_;

        // ZeroMQ context
        zmq::context_t                context_;

        // Publish events
        shared_ptr<zmq::socket_t>     publisher_;

        std::mutex                    mutex_;


        void runZeroMQ();
};

#endif // __M_CMODULEMANAGER_H__
