/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __ARCHIVE_MODULE_MANAGER_H__
#define __ARCHIVE_MODULE_MANAGER_H__


#include <map>
#include <string>
#include <memory>
#include <mutex>

using namespace std;

#include <zmq.hpp>

#include "ServerMessage.h"
#include "ServerWorkerSub.h"

#include "IModuleManager.h"



class ArchiveModuleManager : public IModuleManager
{
    public:
        // Singleton
        static ArchiveModuleManager& getInstance()
        {
            static ArchiveModuleManager instance;

            return instance;
        }

        virtual ~ArchiveModuleManager();

        // delete copy and move constructors and assign operators
        ArchiveModuleManager(ArchiveModuleManager const&) = delete;             // Copy construct
        ArchiveModuleManager(ArchiveModuleManager&&) = delete;                  // Move construct
        ArchiveModuleManager& operator=(ArchiveModuleManager const&) = delete;  // Copy assign
        ArchiveModuleManager& operator=(ArchiveModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();


    protected:
        ArchiveModuleManager();

    private:
        // ZeroMQ context
        zmq::context_t                context_;


        void runZeroMQ();

        void subscribeEvents(shared_ptr<ServerWorkerSub>& inSubscriber);
};

#endif // __MCS_MODULE_MANAGER_H__
