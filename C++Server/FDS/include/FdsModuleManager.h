/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __FDS_MODULE_MANAGER_H__
#define __FDS_MODULE_MANAGER_H__

#include "IModuleManager.h"

#include <string>

using namespace std;


class FdsModuleManager : public IModuleManager
{
    public:
        // Singleton
        static FdsModuleManager& getInstance()
        {
            static FdsModuleManager instance;

            return instance;
        }

        virtual ~FdsModuleManager();

        // delete copy and move constructors and assign operators
        FdsModuleManager(FdsModuleManager const&) = delete;             // Copy construct
        FdsModuleManager(FdsModuleManager&&) = delete;                  // Move construct
        FdsModuleManager& operator=(FdsModuleManager const&) = delete;  // Copy assign
        FdsModuleManager& operator=(FdsModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();

    protected:
        FdsModuleManager();

    private:
        void initThrift();

};

#endif // __FDS_MODULE_MANAGER_H__

