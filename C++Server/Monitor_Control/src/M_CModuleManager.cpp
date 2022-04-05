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

#include "ServerWorker.h"
#include "M_CMessageProcessor.h"

#include "M_CModuleManager.h"
#include "LogManager.h"



M_CModuleManager::M_CModuleManager()
    : done_{false}, context_{1}, publisher_{}, mutex_{}
{
}

M_CModuleManager::~M_CModuleManager()
{
    // ???
    shutdown();
}

void M_CModuleManager::init(const string& inConfigFileName)
{
    if (inConfigFileName.empty() == false) {
        try {
            // Read the M&C configuration from a JSON config file
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

void M_CModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info("--------------------------------------------------------------");
    LogManager::getInstance().info("      " + moduleName + " STARTING UP");
    LogManager::getInstance().info("--------------------------------------------------------------");

    // Run
    runZeroMQ();
}

void M_CModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info(moduleName + " shutting down");

    done_ = true;
}

ModuleStatusEnum M_CModuleManager::getStatus()
{
    return MODE_RUNNING;
}

// Publish an Event in the Pub-Sub socket
// Add the prefix "EVT:" and sends the message to the socket
void M_CModuleManager::publishMessage(const ServerMessage &inMessage)
{
    std::unique_lock<std::mutex> lck(mutex_);

    // Publish only messages of type CODE_PUBLISH_EVENT
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_PUBLISH_EVENT)
    {
        // Send event type
        string eventId = EVENT_PREFIX + const_cast<ServerMessage&>(inMessage).getEventTypeAsString();

        zmq::message_t zeroMqMsg{eventId.data(), eventId.size()};

        publisher_->send(zeroMqMsg, ZMQ_SNDMORE);

        // Send message data
        zeroMqMsg.rebuild(const_cast<ServerMessage&>(inMessage).getData().data(),
                          const_cast<ServerMessage&>(inMessage).getDataSize());

        publisher_->send(zeroMqMsg);
    }
    else
    {
        LogManager::getInstance().warning("Trying to publish a non-event message. Incorrect type: " +
                         const_cast<ServerMessage&>(inMessage).getOperationCodeAsString() );
    }
}

void M_CModuleManager::runZeroMQ()
{
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    const int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;

    LogManager::getInstance().debug("Max HW concurrencty: " + std::thread::hardware_concurrency() );

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

        tmpWorker->setMessageProcessor( std::make_shared<M_CMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorker::run, tmpWorker)));
        worker_thread.back()->detach();
    }


    // Create Publisher socket
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_PUB} );

    auto mcPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_PUB_ADDRESS);

    LogManager::getInstance().info("Publishing events to: " + mcPublisherAddress);

    publisher_ = std::move( tmpPublisher );
    publisher_->bind(mcPublisherAddress);


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


