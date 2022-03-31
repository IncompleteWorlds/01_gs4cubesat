/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <thread>
#include <iostream>

using namespace std;

#include "ConfigurationManager.h"
#include "GsMessageProcessor.h"
#include "GsDatabase.h"
#include "LogManager.h"

#include "GsModuleManager.h"




GsModuleManager::GsModuleManager()
    : IModuleManagerNng{}, done_{false}, reply_{}, backend_{}, 
    backendThread_{}, logBusThread_{}, eventBusThread_{}, backendWorker_{}, transferWorkerLog_{},
    transferWorkerEvent_{}, tmProcessor_{}
{
}

GsModuleManager::~GsModuleManager()
{
    shutdown();
}

void GsModuleManager::init(const string &inConfigFileName)
{
    if (inConfigFileName.empty() == false) 
    {
        try 
        {
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

            tmpMessage = "Current NanoMsg version: " + string{nng::version()};
            logMng.info(tmpMessage);

            // Load GS Database
            GsDatabase::getInstance().open();
            
            
            //TODO: Activate modules depending on activation flags in the config.json file
            
        } catch (const std::exception& e) 
        {
            LogManager::getInstance().error(e.what());
        } catch (...) 
        {
            LogManager::getInstance().error("Unknown exception");
        }
        
        status_ = MODE_STARTED;
    } 
    else 
    {
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
    runMQ();
}

void GsModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info(moduleName + " shutting down");
    cout << "INFO  GS Module shutting down" << endl;
    
    // Kill the threads
    this->transferWorkerLog_->setDone(true);
    sleep(1);
    this->transferWorkerEvent_->setDone(true);
    sleep(1);
    this->backendWorker_->setDone(true);

    // Close the sockets    
    done_ = true;
}

void GsModuleManager::runMQ()
{
    // STEP 1: REQ-REP socket
    // ===========================================================
    // It controls the behaviour of the module
    // This is REP side
    // Ths module manager will receive and process some of the messages. The other ones will be 
    // forwarded to the central processing thread
    auto replyAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_SERVER_ADDRESS);
    LogManager::getInstance().info( "Listening to REP: " + replyAddress);
    
    this->reply_ = nng::rep::open();
    this->reply_.listen(replyAddress.c_str());
    
    
    
    // STEP 2: LOG BUS socket
    // ===========================================================    
    auto timeOut = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_RECV_TIMEOUT);
    nng_duration  busTimeout = std::atoi(timeOut.c_str());

    auto logBusAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_LOG_BUS_ADDRESS);
    LogManager::getInstance().info( "Listening to Log BUS: " + logBusAddress);
    
    this->logBus_ = nng::bus::open();
    this->logBus_.listen(logBusAddress.c_str());

    set_opt_recv_timeout(this->logBus_, busTimeout);
    

    // STEP 3: Event BUS socket
    // ===========================================================    
    // It processes general messages 
    auto eventBusAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_EVENT_BUS_ADDRESS);
    LogManager::getInstance().info( "Listening to Event BUS: " + eventBusAddress);
    
    this->eventBus_ = nng::bus::open();
    this->eventBus_.listen(eventBusAddress.c_str());
    
    set_opt_recv_timeout(this->eventBus_, busTimeout);

    
    // STEP 4: Create a thread per socket that can receive messages
    // ===========================================================
    this->backend_ = nng::req::open();


    // Create a bus processing thread
    // Input socket, output socket
    
    LogManager::getInstance().debug("Creating Log transfer worker: " );        
    this->transferWorkerLog_.reset( new ServerWorkerTransferNng(this->logBus_, this->backend_) );

    this->logBusThread_.reset( new std::thread( std::bind(&ServerWorkerTransferNng::run, this->transferWorkerLog_) ) );
    this->logBusThread_->detach();
    
    
    LogManager::getInstance().debug("Creating Event transfer worker: " );        
    this->transferWorkerEvent_.reset( new ServerWorkerTransferNng(this->eventBus_, this->backend_) );

    this->eventBusThread_.reset( new std::thread( std::bind(&ServerWorkerTransferNng::run, this->transferWorkerLog_) ) );
    this->eventBusThread_->detach();
    
    
    
    
    // Create the main message processing thread. It is internal to this process
    // It listen to "inproc://backend"
    this->backendWorker_.reset( new ServerWorkerNng() );

    LogManager::getInstance().debug("Creating Backendserver worker: " );        
    this->backendWorker_->setMessageProcessor( std::make_shared<GsMessageProcessor>() );

    this->backendThread_.reset( new std::thread( std::bind(&ServerWorkerNng::run, this->backendWorker_) ) );
    this->backendThread_->detach();

    // 1 sec delay
    sleep(1);
    
    this->backend_.dial("inproc://backend");
    
    
    // STEP 5: Notify the central M&C that module is up and running
    // ===========================================================
    // TODO: How to check the M&C is up and running. Or perhaps, just to put a message in the general bus
    // GS Manager shall register with its IP and port into a Central directory
    auto mcAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_MCC_SERVER_ADDRESS);
    LogManager::getInstance().info( "Connecting to M&C: " + mcAddress);

    // Send the start up message to M&C
    // it depends on eventBus_
    sendStartUpMessage();
    

    // STEP 6: TM Processor socket
    // ========================================================    
    auto tmProcessorAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GS_TM_PROCESSOR_ADDRESS);
    LogManager::getInstance().info( "Dialing to TM Processor: " + tmProcessorAddress);
    
    this->tmProcessor_ = nng::rep::open();
    this->tmProcessor_.dial(tmProcessorAddress.c_str());
   
    
    // STEP 7: Main processing loop
    // ========================================================
    // Any received message, except SHUTDOWN message, will be forward to a central processing thread
    ServerMessage   outputMessage;
    
    status_ = MODE_RUNNING;
    
    while(this->done_ == false) 
    {
        try 
        {
            ServerMessage  newMessage;

            ::receiveMessage(this->reply_, newMessage);
                    
            // TODO: Check the Authorization Token
            // SecurityManager->CheckToken( newMessage.getAuthorizationToken() );

            switch(newMessage.getOperationCode())
            {
                // Module stop
                case OperationCodeEnum::CODE_SHUTDOWN:
                    shutdown();
                    ::createReply(outputMessage, 0, "");
                    break;

                // Return the module status
                case OperationCodeEnum::CODE_GET_STATUS:
                    outputMessage = returnStatus(ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME),
                                                 newMessage);
                    break;
                
                // Default, send the message to the central processing thread
                default:
                    ::sendMessage(this->backend_, newMessage);

                    ::receiveMessage(this->backend_, outputMessage);                 
                    break;
            }
        }
        catch(GSException& gsException)
        {
            string exceptionMessage = "ERROR: GS Exception in ServerWorkerZmq::run: " + gsException.getErrorMessage();
    
            // Create error message. MsgReturnData
            ::createReply(outputMessage, gsException.getErrorCode(), gsException.getErrorMessage());
    
            LogManager::getInstance().error(exceptionMessage);
        }
        catch (std::exception &e)
        {
            string exceptionMessage = "ERROR: Exception in ServerWorkerZmq::run: " + string{e.what()};
    
            ::createReply(outputMessage, -1, exceptionMessage);
    
            LogManager::getInstance().error(exceptionMessage);
        }
    
        // Send reply
        ::sendMessage(this->reply_, outputMessage);
    } 
}

// Publish an Event in the Pub-Sub socket
void GsModuleManager::sendToTmProcessor(const ServerMessage &inMessage)
{
    std::unique_lock<std::mutex> lck(mutex_);

    // Send message code
    ::sendMessage(tmProcessor_, inMessage);
}
