/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <thread>
#include <iostream>

using namespace std;

#include "ServerWorker.h"
#include "ServerWorkerSub.h"
#include "ConfigurationManager.h"
#include "GsMessageProcessor.h"
#include "GsDatabase.h"
#include "LogManager.h"

#include "GsModuleManager.h"




GsModuleManager::GsModuleManager()
    : io_service{}, done_{false}, context_{1}, tmProcessor_{}
{
}

GsModuleManager::~GsModuleManager()
{
    shutdown();
}

void GsModuleManager::init(const string &inConfigFileName)
{
    if (inConfigFileName.empty() == false) {
        try {
            // Read the M&C configuration from a JSON config file
            // Throws and exception if an error is found
            ConfigurationManager::getInstance().load(inConfigFileName);

            // Get version of ZeroMQ
            int major, minor, patch;

            zmq::version(&major, &minor, &patch);

            // Initialize the Log Manager
            LogManager&  logMng = LogManager::getInstance();
            
            logMng.init( ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_LOG_FILE ));
            
            logMng.info("Configuration correctly loaded");
            string tmpMessage = "Current ZeroMQ version: " + to_string(major) + "," + to_string(minor) + "," + to_string(patch);
            logMng.info(tmpMessage);

            // Load GS Database
            GsDatabase::getInstance().open();
        } catch (const std::exception& e) {
            LogManager::getInstance().error(e.what());
        } catch (...) {
            LogManager::getInstance().error("Unknown exception");
        }
    } else {
        cerr << "ERROR: Empty configuration file name" << endl;
    }
}

void GsModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info("--------------------------------------------------------------");
    LogManager::getInstance().info("      " + moduleName + " STARTING UP");
    LogManager::getInstance().info("--------------------------------------------------------------");

    // Run
    runZeroMQ();
}

void GsModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info(moduleName + " shutting down");
    cout << "INFO  GS Module shutting down" << endl;

    done_ = true;
}

ModuleStatusEnum GsModuleManager::getStatus()
{
    return MODE_RUNNING;
}

void GsModuleManager::runZeroMQ()
{
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    const int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;

    LogManager::getInstance().debug("DEBUG: Max HW concurrencty: " + std::thread::hardware_concurrency() );

    auto mcAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SERVER_ADDRESS);
    LogManager::getInstance().info( "Connecting to: " + mcAddress);

    // Create ROUTER-DEALER. It will receive incoming messages and forward them to workers
    frontend_.bind(mcAddress);
    backend_.bind("inproc://backend");

    std::vector<ServerWorker *>     worker;
    std::vector<std::thread *>      worker_thread;

    for (int i = 0; i < kMaxThread; ++i)
    {
        ServerWorker* tmpWorker;

        LogManager::getInstance().debug("Creating server worker: " + to_string(i) );
        tmpWorker = new ServerWorker(this->context_, ZMQ_REP);

        tmpWorker->setMessageProcessor( std::make_shared<GsMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorker::run, tmpWorker)));
        worker_thread.back()->detach();
    }



    // Create a socket with M&C for publishing events.
    // An event message will be sent to the M&C and it will publish the event
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto gsPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_PUB_ADDRESS);

    LogManager::getInstance().info("Sending events to: " + gsPublisherAddress);

    publisher_ = std::move( tmpPublisher );
    
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    publisher_->setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    
    publisher_->connect(gsPublisherAddress);


    // Create MCS socket
    shared_ptr<zmq::socket_t>    tmpTmProcessor( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto tmProcessorAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_TM_PROCESSOR_ADDRESS);

    LogManager::getInstance().info("Sending new frames to: " + tmProcessorAddress);

    tmProcessor_ = std::move(tmpTmProcessor);
    tmProcessor_->bind(tmProcessorAddress);



    // Create subscriber
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    auto subscriberAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SUB_ADDRESS);

    LogManager::getInstance().debug("Creatinng subscriber server worker to Event bus - " + subscriberAddress);

    shared_ptr<ServerWorkerSub> subscriptionWorker( new ServerWorkerSub(this->context_, ZMQ_SUB, moduleName, subscriberAddress) );

    subscriptionWorker->setMessageProcessor( std::make_shared<GsMessageProcessor>() );

    // Create and detach the thread
    worker_thread.push_back(new std::thread(std::bind(&ServerWorkerSub::run, subscriptionWorker)));
    worker_thread.back()->detach();


    // Send start up message to M&C
    sendStartUpMessage();


    // Create proxy between ROUTER and DEALER
    try
    {
        LogManager::getInstance().debug("Creating proxy");
        zmq::proxy(frontend_, backend_, nullptr);
    }
    catch (std::exception &e)
    {
        LogManager::getInstance().error("Exception creating proxy: " + *(e.what()) );
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
        LogManager::getInstance().info("Removing server worker: ");
        delete xx;
    }

    for(auto xx: worker_thread)
    {
        LogManager::getInstance().info("Removing server worker thread: ");
        delete xx;
    }
}



// Publish an Event in the Pub-Sub socket
void GsModuleManager::sendToTmProcessor(const ServerMessage &inMessage)
{
    std::unique_lock<std::mutex> lck(mutex_);

    // Send message code
    sendMessage(*tmProcessor_, inMessage);
}
