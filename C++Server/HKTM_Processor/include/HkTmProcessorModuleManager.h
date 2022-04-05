/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __HKTM_PROCESSOR_MODULE_MANAGER_H__
#define __HKTM_PROCESSOR_MODULE_MANAGER_H__


#include <string>
#include <mutex>

using namespace std;

#include <zmq.hpp>

#include "ServerMessage.h"
#include "BaseLayer.h"
#include "IModuleManager.h"
#include "AvroTypes.h"



class HkTmProcessorModuleManager : public IModuleManager
{
    public:
        // Singleton
        static HkTmProcessorModuleManager& getInstance()
        {
            static HkTmProcessorModuleManager instance;

            return instance;
        }

        virtual ~HkTmProcessorModuleManager();

        // delete copy and move constructors and assign operators
        HkTmProcessorModuleManager(HkTmProcessorModuleManager const&) = delete;             // Copy construct
        HkTmProcessorModuleManager(HkTmProcessorModuleManager&&) = delete;                  // Move construct
        HkTmProcessorModuleManager& operator=(HkTmProcessorModuleManager const&) = delete;  // Copy assign
        HkTmProcessorModuleManager& operator=(HkTmProcessorModuleManager &&) = delete;      // Move assign

        // Load configuraiton
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();

        // Layers
        shared_ptr<BaseLayer> getLayer(const uint index);
        uint getNumLayers();


    protected:
        HkTmProcessorModuleManager();

    private:
        // ZeroMQ context
        zmq::context_t                context_;

        // Publish events
        shared_ptr<zmq::socket_t>     tools_;


        // Stack of protocol layers
        vector< shared_ptr<BaseLayer> >  layers_;


        void runZeroMQ();
        
        void createLayers();
        shared_ptr<BaseLayer> factoryLayers(const string& inLayerName);

        void getLayerParameters(const string& inLayerName, IW::ListParameters& inListParameters);
        void getFrameDefinitions(const string& inLayerName, IW::ListFrameTypes& listFrameTypes);
};

#endif // __HKTM_PROCESSOR_MODULE_MANAGER_H__
