/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <thread>
#include <iostream>

using namespace std;

#include "Constants.h"
#include "ConfigurationManager.h"
#include "LogManager.h"

#include "EventTypeEnum.h"
#include "ServerWorker.h"
#include "ArchiveMessageProcessor.h"

#include "ArchiveModuleManager.h"


ArchiveModuleManager::ArchiveModuleManager()
    : context_{1}
{
}

ArchiveModuleManager::~ArchiveModuleManager()
{
    // ???
    shutdown();
}

/**
 * Start the message loop
 *
 */
void ArchiveModuleManager::init(const string &inConfigFileName)
{
    if (inConfigFileName.empty() == false) {
        try {
            // Read the TM Archive configuration from a JSON config file
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

void ArchiveModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    cout << "INFO: " << moduleName << " starting up" << endl;

    // Run
    runZeroMQ();
}

void ArchiveModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    cout << "INFO: " << moduleName << " shutting down" << endl;
}

ModuleStatusEnum ArchiveModuleManager::getStatus()
{
    return MODE_RUNNING;
}

void ArchiveModuleManager::runZeroMQ()
{
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    const int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;

    cout << "DEBUG: Max HW concurrencty: " << std::thread::hardware_concurrency() << endl;

    auto archiveAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SERVER_ADDRESS);
    cout << "INFO: Connecting to: " << archiveAddress << endl;

    // Create ROUTER-DEALER. It will receive incoming messages and forward them to workers
    frontend_.bind(archiveAddress);
    backend_.bind("inproc://backend");

    std::vector<ServerWorker *>     worker;
    std::vector<std::thread *>      worker_thread;

    for (int i = 0; i < kMaxThread; ++i)
    {
        ServerWorker* tmpWorker;

        cout << "DEBUG: Creating server worker: " << i << endl;
        tmpWorker = new ServerWorker(this->context_, ZMQ_REP);

        tmpWorker->setMessageProcessor( std::make_shared<ArchiveMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorker::run, tmpWorker)));
        worker_thread.back()->detach();
    }


    // Create a socket to send event to M&C
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto archivePublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_PUB_ADDRESS);

    cout << "INFO: Sending events to: " << archivePublisherAddress << endl;

    publisher_ = std::move( tmpPublisher );
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    publisher_->setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    publisher_->connect(archivePublisherAddress);



    // Create subscriber
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    auto subscriberAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SUB_ADDRESS);

    cout << "DEBUG: Creatinng subscriber server worker to Event bus " << " - " << subscriberAddress << endl;

    shared_ptr<ServerWorkerSub> subscriptionWorker( new ServerWorkerSub(this->context_, ZMQ_SUB, moduleName, subscriberAddress) );

    // Subscribe to event it is interested on
    subscribeEvents(subscriptionWorker);

    subscriptionWorker->setMessageProcessor( std::make_shared<ArchiveMessageProcessor>() );

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

// Subscribe to all events the Archive is interested on
// Events are prefixed with "EVT:"
void ArchiveModuleManager::subscribeEvents(shared_ptr<ServerWorkerSub> &inSubscriber)
{
    // Subscribe to events
    string eventId;

    eventId = EVENT_PREFIX + to_string( static_cast<int>(EventTypeEnum::EVT_NEW_RAW_FRAME));
    inSubscriber->subscribe(eventId);

    eventId = EVENT_PREFIX + to_string( static_cast<int>(EventTypeEnum::EVT_NEW_PROCESSED_FRAME));
    inSubscriber->subscribe(eventId);
}


