/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <thread>

using namespace std;

#include "LogManager.h"
#include "ConfigurationManager.h"

#include "ServerWorker.h"
#include "ServerWorkerSub.h"
#include "McsMessageProcessor.h"

#include "McsModuleManager.h"



McsModuleManager::McsModuleManager()
    : done_{false}, context_{1}, subscribers_{}
{
}

McsModuleManager::~McsModuleManager()
{
    // ???
    shutdown();
}

/**
 * Start the message loop
 *
 */
void McsModuleManager::init(const string &inConfigFileName)
{
    if (inConfigFileName.empty() == false) {
        try {
            // Read the MCS configuration from a JSON config file
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

void McsModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    cout << "INFO: " << moduleName << " starting up" << endl;

    // Run
    // Create sockets, connections and subscribers
    runZeroMQ();
}

void McsModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    cout << "INFO  " << moduleName << " shutting down" << endl;
}

ModuleStatusEnum McsModuleManager::getStatus()
{
    return MODE_RUNNING;
}

void McsModuleManager::runZeroMQ()
{
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    const int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;

    cout << "DEBUG: Max HW concurrencty: " << std::thread::hardware_concurrency() << endl;

    auto mcsAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SERVER_ADDRESS);
    cout << "INFO: Connecting to: " << mcsAddress << endl;


    // Create ROUTER-DEALER. It will receive incoming messages and forward them to workers
    frontend_.bind(mcsAddress);
    backend_.bind("inproc://backend");

    std::vector<ServerWorker *>     worker;
    std::vector<std::thread *>      worker_thread;

    for (int i = 0; i < kMaxThread; ++i)
    {
        ServerWorker* tmpWorker;

        cout << "DEBUG: Creating server worker: " << i << endl;
        tmpWorker = new ServerWorker(this->context_, ZMQ_REP);

        tmpWorker->setMessageProcessor( std::make_shared<McsMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorker::run, tmpWorker)));
        worker_thread.back()->detach();
    }



    // Create a socket for sending events to the M&C
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto mcsPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_PUB_ADDRESS);

    cout << "INFO: Sending events to: " << mcsPublisherAddress << endl;

    publisher_ = std::move( tmpPublisher );
    
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    publisher_->setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    publisher_->connect(mcsPublisherAddress);



    // Create subscriber
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    auto subscriberAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SUB_ADDRESS);

    cout << "DEBUG: Creatinng subscriber server worker to Event bus " << " - " << subscriberAddress << endl;

    shared_ptr<ServerWorkerSub> subscriptionWorker( new ServerWorkerSub(this->context_, ZMQ_SUB, moduleName, subscriberAddress) );

    subscriptionWorker->setMessageProcessor( std::make_shared<McsMessageProcessor>() );


    // TODO
    // SUBSCRIBE TO RAW AND PROCESSED FRAMES. MAYBE RAW IS NOT NEEDED BUT PROCESSED IS NEEDED



    // Create and detach the thread
    worker_thread.push_back(new std::thread(std::bind(&ServerWorkerSub::run, subscriptionWorker)));
    worker_thread.back()->detach();



    // Send start up message to M&C
    sendStartUpMessage();


    // Create proxy between ROUTER and DEALER
    try
    {
        cout << "DEBUG: Creating proxy" << endl;
        zmq::proxy(static_cast<void *>(&frontend_), static_cast<void *>(&backend_), nullptr);
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

