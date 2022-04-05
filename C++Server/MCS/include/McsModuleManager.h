/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __MCS_MODULE_MANAGER_H__
#define __MCS_MODULE_MANAGER_H__

#include <map>
#include <string>
#include <memory>
#include <mutex>

using namespace std;

#include <zmq.hpp>

#include "ServerMessage.h"
#include "IModuleManager.h"



class McsModuleManager : public IModuleManager
{
    public:
        // Singleton
        static McsModuleManager& getInstance()
        {
            static McsModuleManager instance;

            return instance;
        }

        virtual ~McsModuleManager();

        // delete copy and move constructors and assign operators
        McsModuleManager(McsModuleManager const&) = delete;             // Copy construct
        McsModuleManager(McsModuleManager&&) = delete;                  // Move construct
        McsModuleManager& operator=(McsModuleManager const&) = delete;  // Copy assign
        McsModuleManager& operator=(McsModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();


    protected:
        McsModuleManager();

    private:
        // Flag for signaling end of message processing
        bool                          done_;

        // ZeroMQ context
        zmq::context_t                context_;

        // List of subscriber sockets; name = ip address
        map<string, string>           subscribers_;

        void initZeroMQ();

        void runZeroMQ();
};

#endif // __MCS_MODULE_MANAGER_H__
