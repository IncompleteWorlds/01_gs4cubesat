/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __HKTM_PROCESSOR_MODULE_MANAGER_H__
#define __HKTM_PROCESSOR_MODULE_MANAGER_H__


#include <string>

using namespace std;

#include <zmq.hpp>

#include "IModuleManager.h"

class TcProcessorModuleManager : public IModuleManager
{
    public:
        // Singleton
        static TcProcessorModuleManager& getInstance()
        {
            static TcProcessorModuleManager instance;

            return instance;
        }

        virtual ~TcProcessorModuleManager();

        // delete copy and move constructors and assign operators
        TcProcessorModuleManager(TcProcessorModuleManager const&) = delete;             // Copy construct
        TcProcessorModuleManager(TcProcessorModuleManager&&) = delete;                  // Move construct
        TcProcessorModuleManager& operator=(TcProcessorModuleManager const&) = delete;  // Copy assign
        TcProcessorModuleManager& operator=(TcProcessorModuleManager &&) = delete;      // Move assign

        // Load configuraiton
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();


    protected:
        TcProcessorModuleManager();

    private:
        // ZeroMQ context
        zmq::context_t                context_;


        void runZeroMQ();
};

#endif // __HKTM_PROCESSOR_MODULE_MANAGER_H__
