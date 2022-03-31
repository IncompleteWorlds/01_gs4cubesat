/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */
 
#ifndef __ORB_PROPAG_MODULE_MANAGER__
#define __ORB_PROPAG_MODULE_MANAGER__

#include <thread>

using namespace std;

#include "IModuleManagerZmq.h" // Base class: IModuleManagerZmq

#include "BaseLayer.h"


class LayersTmDecoderModuleManager : public IModuleManagerZmq
{
    public:
        // Singleton
        static LayersTmDecoderModuleManager& getInstance()
        {
            static LayersTmDecoderModuleManager instance;

            return instance;
        }

        virtual ~LayersTmDecoderModuleManager();

        // delete copy and move constructors and assign operators
        LayersTmDecoderModuleManager(LayersTmDecoderModuleManager const&) = delete;             // Copy construct
        LayersTmDecoderModuleManager(LayersTmDecoderModuleManager&&) = delete;                  // Move construct
        LayersTmDecoderModuleManager& operator=(LayersTmDecoderModuleManager const&) = delete;  // Copy assign
        LayersTmDecoderModuleManager& operator=(LayersTmDecoderModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        virtual void start();
        virtual void shutdown();
        
    protected:
        LayersTmDecoderModuleManager();

    private:
        // ZeroMQ context
        zmq::context_t    context_;

        // Socket for receiving module messages        
        zmq::socket_t     module_req_;
    
        // Module for sending events to the HK TM Decoder. I.e. frame is processed
        zmq::socket_t     mcs_pub_;

        
        std::thread       theThread_;
        
        
        // Stack of protocol layers
        vector< shared_ptr<BaseLayer> >  layers_;
        
        void runZeroMQ();
        
        void internalRun();
        
        void internalRunAlgorithm();
        
        ServerMessage processFrame(ServerMessage &inMessage);
        //void processFrame(ServerMessage &inMessage);
        void processLayers(const ServerMessage &inMessage);

        // Layers
        shared_ptr<BaseLayer> getLayer(const uint index);
        uint getNumLayers();
        
        void createLayers();
        shared_ptr<BaseLayer> factoryLayers(const string& inLayerName);

        void getLayerParameters(const string& inLayerName, IW::ListParameters& inListParameters);
        void getFrameDefinitions(const string& inLayerName, IW::ListFrameTypes& listFrameTypes);
};

#endif // __ORB_PROPAG_MODULE_MANAGER__
