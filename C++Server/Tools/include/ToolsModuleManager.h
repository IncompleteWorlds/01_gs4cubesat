/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __TOOLS_MODULE_MANAGER_H__
#define __TOOLS_MODULE_MANAGER_H__


#include <map>
#include <string>
#include <memory>
#include <mutex>

using namespace std;

#include <zmq.hpp>

#include "ServerMessage.h"
#include "IModuleManager.h"


class ToolsModuleManager : public IModuleManager
{
    public:
        // Singleton
        static ToolsModuleManager& getInstance()
        {
            static ToolsModuleManager instance;

            return instance;
        }

        virtual ~ToolsModuleManager();

        // delete copy and move constructors and assign operators
        ToolsModuleManager(ToolsModuleManager const&) = delete;             // Copy construct
        ToolsModuleManager(ToolsModuleManager&&) = delete;                  // Move construct
        ToolsModuleManager& operator=(ToolsModuleManager const&) = delete;  // Copy assign
        ToolsModuleManager& operator=(ToolsModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();


    protected:
        ToolsModuleManager();

    private:
        // ZeroMQ context
        zmq::context_t                context_;


        void runZeroMQ();
};

#endif // __TOOLS_MODULE_MANAGER_H__
