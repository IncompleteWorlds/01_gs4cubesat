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

#include "ServerWorkerZmq.h"
#include "ServerWorkerSubZmq.h"
#include "ToolsMessageProcessor.h"
#include "ToolsDatabase.h"
#include "MessageUtils.h"
#include "LogManager.h"

#include "ToolsModuleManager.h"



ToolsModuleManager::ToolsModuleManager()
    : context_{1}
{
}

ToolsModuleManager::~ToolsModuleManager()
{
    // ???
    shutdown();
}

void ToolsModuleManager::init(const string& inConfigFileName)
{
    if (inConfigFileName.empty() == false) {
        try {
            // Read the Tools configuration from a JSON config file
            // Throws and exception if an error is found
            ConfigurationManager::getInstance().load(inConfigFileName);

            int major, minor, patch;

            zmq::version(&major, &minor, &patch);

            // Initialize the Log Manager
            LogManager&  logMng = LogManager::getInstance();
            
            logMng.init( ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_LOG_FILE ));
            
            logMng.info("Configuration correctly loaded");
            string tmpMessage = "Current ZeroMQ version: " + to_string(major) + "." + to_string(minor) + "." + to_string(patch);
            logMng.info(tmpMessage);

            ToolsDatabase::getInstance().open();

        } catch (const std::exception& e) {
            LogManager::getInstance().error(e.what());
        } catch (...) {
            LogManager::getInstance().error("Unknown exception");
        }
    } else {
        cerr << "ERROR: Empty configuration file name" << endl;
    }
}

void ToolsModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info("--------------------------------------------------------------");
    LogManager::getInstance().info("      " + moduleName + " STARTING UP");
    LogManager::getInstance().info("--------------------------------------------------------------");
    
    // Run
    runZeroMQ();
}

void ToolsModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info(moduleName + " SHUTTING DOWN");
}

ModuleStatusEnum ToolsModuleManager::getStatus()
{
    return MODE_RUNNING;
}

void ToolsModuleManager::runZeroMQ()
{
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;
    // At least a thread shall be created
    if (kMaxThread <= 0)
        kMaxThread = 1;

    LogManager::getInstance().debug("Max HW concurrencty: " + to_string(std::thread::hardware_concurrency()) );

    auto toolsAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_SERVER_ADDRESS);
    LogManager::getInstance().info("Connecting to: " + toolsAddress);

    // Create ROUTER-DEALER. It will receive incoming messages and forward them to workers
    frontend_.bind(toolsAddress);
    backend_.bind("inproc://backend");

    std::vector<ServerWorkerZmq *>     worker;
    std::vector<std::thread *>      worker_thread;

    for (int i = 0; i < kMaxThread; ++i)
    {
        ServerWorkerZmq* tmpWorker;

        LogManager::getInstance().debug("Creating server worker: " + to_string(i) );
        tmpWorker = new ServerWorkerZmq(this->context_, ZMQ_REP);

        tmpWorker->setMessageProcessor( std::make_shared<ToolsMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorkerZmq::run, tmpWorker)));
        worker_thread.back()->detach();
    }


    // Create a socket for sending events to the M&C
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto mcPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_PUB_ADDRESS);

    LogManager::getInstance().info("Publishing events to: " + mcPublisherAddress);

    publisher_ = std::move( tmpPublisher );
    
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    publisher_->setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    publisher_->connect(mcPublisherAddress);


    // Create subscriber
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    auto subscriberAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_SUB_ADDRESS);

    LogManager::getInstance().debug("Creating subscriber server worker to Event bus: " + subscriberAddress);

    shared_ptr<ServerWorkerSubZmq> subscriptionWorker( new ServerWorkerSubZmq(this->context_, ZMQ_SUB, moduleName, subscriberAddress) );

    subscriptionWorker->setMessageProcessor( std::make_shared<ToolsMessageProcessor>() );

    // Create and detach the thread
    worker_thread.push_back(new std::thread(std::bind(&ServerWorkerSubZmq::run, subscriptionWorker)));
    worker_thread.back()->detach();


    // Send start up message to M&C
    sendStartUpMessage();


    // Create proxy between ROUTER and DEALER
    try
    {
        LogManager::getInstance().debug("Creating proxy");
        // Just cast to void *, as socket_t has the operator (void *)
        zmq::proxy((void *) frontend_, (void *) backend_, nullptr);
    }
    catch (std::exception &e)
    {
        LogManager::getInstance().error("Exception creating proxy: " + string{e.what()} );
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
        LogManager::getInstance().info("Removing server worker ");
        delete xx;
    }

    for(auto xx: worker_thread)
    {
        LogManager::getInstance().info("Removing server worker thread ");
        delete xx;
    }
}

