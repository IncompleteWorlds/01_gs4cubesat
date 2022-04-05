/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <thread>

using namespace std;

#include "ConfigurationManager.h"


#include "ServerWorker.h"
#include "ServerWorkerSub.h"
#include "MessageUtils.h"
#include "LogManager.h"

#include "HkTmProcessorMessageProcessor.h"

#include "KissLayer.h"
#include "Ax25Layer.h"
#include "CspLayer.h"
#include "HdlcLayer.h"

#include "HkTmProcessorModuleManager.h"


HkTmProcessorModuleManager::HkTmProcessorModuleManager()
    : context_{1}, tools_{}, layers_{}
{
}

HkTmProcessorModuleManager::~HkTmProcessorModuleManager()
{
    // ???
    shutdown();
}

/**
 * Start the message loop
 *
 */
void HkTmProcessorModuleManager::init(const string &inConfigFileName)
{
    if (inConfigFileName.empty() == false) {
        try {
            // Read the HK TM Processor configuration from a JSON config file
            // Throws and exception if an error is found
            ConfigurationManager::getInstance().load(inConfigFileName);

            int major, minor, patch;

            zmq::version(&major, &minor, &patch);
            
            // Initialize the Log Manager
            LogManager&  logMng = LogManager::getInstance();
            
            logMng.init( ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_LOG_FILE ));
            
            logMng.info("Configuration correctly loaded");
            string tmpMessage = "Current ZeroMQ version: " + to_string(major) + "," + to_string(minor) + "," + to_string(patch);
            logMng.info(tmpMessage);

        } catch (const std::exception& e) {
            LogManager::getInstance().error(e.what());
        } catch (...) {
            LogManager::getInstance().error("Unknown exception");
        }
    } else {
        cerr << "ERROR: Empty configuration file name" << endl;
    }
}

void HkTmProcessorModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    cout << "INFO: " << moduleName << " starting up" << endl;

    // Run
    runZeroMQ();
}

void HkTmProcessorModuleManager::shutdown()
{
    cout << "INFO  HK TM Processor Module shutting down" << endl;
}

ModuleStatusEnum HkTmProcessorModuleManager::getStatus()
{
    return MODE_RUNNING;
}

void HkTmProcessorModuleManager::runZeroMQ()
{
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    const int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;

    cout << "DEBUG: Max HW concurrencty: " << std::thread::hardware_concurrency() << endl;

    auto mcAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SERVER_ADDRESS);
    cout << "INFO: Connecting to: " << mcAddress << endl;

    // Create ROUTER-DEALER. It will receive incoming messages and forward them to workers
    frontend_.bind(mcAddress);
    backend_.bind("inproc://backend");

    std::vector<ServerWorker *>     worker;
    std::vector<std::thread *>      worker_thread;

    for (int i = 0; i < kMaxThread; ++i)
    {
        ServerWorker* tmpWorker;

        cout << "DEBUG: Creating server worker: " << i << endl;
        tmpWorker = new ServerWorker(this->context_, ZMQ_REP);

        tmpWorker->setMessageProcessor( std::make_shared<HkTmProcessorMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorker::run, tmpWorker)));
        worker_thread.back()->detach();
    }



    // Create a socket with M&C for publishing events.
    // An event message will be sent to the M&C and it will publish the event
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto hktmProcPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_PUB_ADDRESS);

    cout << "INFO: Sending events to: " << hktmProcPublisherAddress << endl;

    publisher_ = std::move( tmpPublisher );
    
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    publisher_->setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    
    publisher_->connect(hktmProcPublisherAddress);


    // Create socket with Tools
    shared_ptr<zmq::socket_t>    tmpTools( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto toolsServerAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_TOOLS_SERVER_ADDRESS);

    cout << "INFO: Tools server: " << toolsServerAddress << endl;

    tools_ = std::move( tmpTools );
    tools_->connect(toolsServerAddress);

    // Get comm layers for each satellite of current mission
    // NOTE: Passes shall contain an indication of the satellite to be used
    // It needs the Tools server up and running
    createLayers();



    // Create subscriber
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    auto subscriberAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SUB_ADDRESS);

    cout << "DEBUG: Creatinng subscriber server worker to Event bus " << " - " << subscriberAddress << endl;

    shared_ptr<ServerWorkerSub> subscriptionWorker( new ServerWorkerSub(this->context_, ZMQ_SUB, moduleName, subscriberAddress) );

    subscriptionWorker->setMessageProcessor( std::make_shared<HkTmProcessorMessageProcessor>() );


    // Create and detach the thread
    worker_thread.push_back(new std::thread(std::bind(&ServerWorkerSub::run, subscriptionWorker)));
    worker_thread.back()->detach();


    // Send start up message to M&C
    sendStartUpMessage();


    // Create proxy between ROUTER and DEALER
    try
    {
        cout << "DEBUG: Creating proxy" << endl;
        zmq::proxy(frontend_, backend_, nullptr);
    }
    catch (std::exception &e)
    {
        cout << "ERROR: Exception creating proxy: " << e.what() << endl;
    }




    /*
    ALTERNATIVE


    // Instead of connecting both socket, we will pool them
    zmq_pollitem_t items [] =
    {
        { frontend_, 0, ZMQ_POLLIN, 0 },
        { backend_,  0, ZMQ_POLLIN, 0 }
    };

    done_ = false;

    cout << "DEBUG: Start polling ..." << endl;
    while (done_ == false)
    {
        zmq::poll(items, 2, -1);

        zmq::message_t  newMessage;

        // Forward messages from front-end to back-end, and viceversa
        if(items[0].revents & ZMQ_POLLIN)
        {
            // Blocking
            // For non-blocking, add option ZMQ_DONTWAIT
            frontend_.recv(&newMessage, 0);
            backend_.send(newMessage);
            items[0].revents = 0;
        }

        if(items[1].revents & ZMQ_POLLIN)
        {
            // Blocking
            backend_.recv(&newMessage, 0);
            frontend_.send(newMessage);
            items[1].revents = 0;
        }
    }
    */


    // Free used resources
    for(auto xx: worker)
    {
        cout << "INFO: Removing server worker: " << xx << endl;
        delete xx;
    }

    for(auto xx: worker_thread)
    {
        cout << "INFO: Removing server worker thread: " << xx << endl;
        delete xx;
    }
}
 
shared_ptr<BaseLayer> HkTmProcessorModuleManager::getLayer(const uint index)
{
    shared_ptr<BaseLayer>  output{nullptr};

    if (index > 0 && index < layers_.size())
    {
        output = layers_[index];
    }

    return output;
}

uint HkTmProcessorModuleManager::getNumLayers()
{
    return layers_.size();
}

/**
 * @brief HkTmProcessorModuleManager::createLayers
 * Retrieve the comm layers that the mission will use and create the stack of
 * protocols
 */
void HkTmProcessorModuleManager::createLayers()
{
    cout << "INFO: Creating layers" << endl;
    
    // Retrieve layers
    IW::MsgGetMissionLayers  msgLayers;

    msgLayers.authorizationToken = "TODO";
    msgLayers.missionId = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_MISSION_ID);

    VectorUint8    avroOutputMessage;

    avroOutputMessage = buildMessageVector<IW::MsgGetMissionLayers>(msgLayers);

    // Send message to Tools
    ServerMessage  outputMessage;

    outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_MISSION_LAYERS);
    outputMessage.setData(avroOutputMessage);

    sendMessage(*tools_, outputMessage);

    ServerMessage responseMessage;

    receiveMessage(*tools_, responseMessage);
    
    if (responseMessage.getOperationCode() == OperationCodeEnum::CODE_GET_MISSION_LAYERS_RESPONSE)
    {
        // Process response message
        // Layer = index
        IW::ListKeyValues   listLayers;

        extractMessageVector<IW::ListKeyValues>(responseMessage.getData(), listLayers);

        IW::ListParameters   listParameters;

        if (listLayers.listKeyValues.size() > 0)
        {
            layers_.resize( listLayers.listKeyValues.size() );

            // Create stack of protocols
            for(IW::KeyValue  tmpValue : listLayers.listKeyValues)
            {
                // Create layer
                shared_ptr<BaseLayer>   newLayer{ factoryLayers(tmpValue.key) };

                if (newLayer != nullptr)
                {                
                    // Get frame definitions of the layer
                    IW::ListFrameTypes  listFrameTypes;

                    getFrameDefinitions(tmpValue.key, listFrameTypes);

                    newLayer->setFrameTypes(listFrameTypes);

                    // Get parameters of the layer
                    listParameters.listParameters.clear();

                    getLayerParameters(tmpValue.key, listParameters);

                    // Set parameters
                    newLayer->setParameters(listParameters);

                    // Store layer at the right index
                    uint i = std::atoi(tmpValue.value.c_str());

                    layers_[i] = newLayer;
                }
                else
                {
                    // TODO
                    cerr << "ERROR: Null layer pointer" << endl;
                }
            }
        }
    }
    else
    {
        cout << "WARNING: Layers are not found" << endl;
    }
}

shared_ptr<BaseLayer> HkTmProcessorModuleManager::factoryLayers(const string& inLayerName)
{
    shared_ptr<BaseLayer> output{nullptr};

    if (KissLayer::LAYER_NAME == inLayerName)
    {
        output = move( shared_ptr<KissLayer> (new KissLayer()) );
    }

    if (Ax25Layer::LAYER_NAME == inLayerName)
    {
        output = move( shared_ptr<Ax25Layer> (new Ax25Layer()) );
    }

    if (CspLayer::LAYER_NAME == inLayerName)
    {
        output = move( shared_ptr<CspLayer> (new CspLayer()) );
    }

    if (HdlcLayer::LAYER_NAME == inLayerName)
    {
        output = move( shared_ptr<HdlcLayer> (new HdlcLayer()) );
    }
    
    // TODO
    /*
    if (CcsdsLayer::LAYER_NAME == inLayerName)
    {
        output = move( shared_ptr<CcsdsLayer> (new CcsdsLayer()) );
    }
    */

    return output;
}

void HkTmProcessorModuleManager::getLayerParameters(const string& inLayerName, IW::ListParameters& inListParameters)
{
    // Send message to tools for retrieving parameters
    IW::MsgGetLayerParameters  msgParameters;

    msgParameters.authorizationToken = "TODO";
    msgParameters.layerName = inLayerName;

    VectorUint8    avroOutputMessage;

    avroOutputMessage = buildMessageVector<IW::MsgGetLayerParameters>(msgParameters);

    // Send message to Tools
    ServerMessage  outputMessage;

    outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_LAYER_PARAMETERS);
    outputMessage.setData(avroOutputMessage);

    sendMessage(*tools_, outputMessage);

    ServerMessage responseMessage;

    receiveMessage(*tools_, responseMessage);
    
    if (responseMessage.getOperationCode() == OperationCodeEnum::CODE_GET_LAYER_PARAMETERS_RESPONSE)
    {
        // Process response message
        IW::ListParameters   tmpListParameters;

        extractMessageVector<IW::ListParameters>(responseMessage.getData(), tmpListParameters);

        // Copy parameters
        inListParameters = tmpListParameters;
    }
}

void HkTmProcessorModuleManager::getFrameDefinitions(const string& inLayerName, IW::ListFrameTypes& listFrameTypes)
{
    // Send message to tools for retrieving parameters
    IW::MsgGetFrameTypes msgFrameTypes;

    msgFrameTypes.authorizationToken = "TODO";
    msgFrameTypes.layerName = inLayerName;

    VectorUint8    avroOutputMessage;

    avroOutputMessage = buildMessageVector<IW::MsgGetFrameTypes>(msgFrameTypes);

    // Send message to Tools
    ServerMessage  outputMessage;

    outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_LAYER_FRAME_TYPES);
    outputMessage.setData(avroOutputMessage);

    sendMessage(*tools_, outputMessage);

    ServerMessage responseMessage;

    receiveMessage(*tools_, responseMessage);

    if (responseMessage.getOperationCode() == OperationCodeEnum::CODE_GET_LAYER_FRAME_TYPES_RESPONSE)
    {
        // Process response message
        extractMessageVector<IW::ListFrameTypes>(responseMessage.getData(), listFrameTypes);         
    }
    else
    {
        cout << "INFO: No frames are defined for layer: " << inLayerName << endl;
    }
}

