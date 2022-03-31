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
#include "MessageUtils.h"
#include "LogManager.h"
#include "GSException.h"

//#include "HkTmProcessorMessageProcessor.h"



#include "HkTmProcessorModuleManager.h"


HkTmProcessorModuleManager::HkTmProcessorModuleManager()
    : context_{1}, module_req_{context_, ZMQ_REQ}, tools_{}
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
    if (inConfigFileName.empty() == false) 
    {
        try 
        {
            // Read the HK TM Processor configuration from a JSON config file
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

        } 
        catch (const std::exception& e) 
        {
            LogManager::getInstance().error(e.what());
        } 
        catch (...) 
        {
            LogManager::getInstance().error("Unknown exception");
        }
    } 
    else 
    {
        cerr << "ERROR: Empty configuration file name" << endl;
    }
}

void HkTmProcessorModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info("--------------------------------------------------------------");
    LogManager::getInstance().info("      " + moduleName + " STARTING UP");
    LogManager::getInstance().info("--------------------------------------------------------------");

    // Run
    runZeroMQ();
}

void HkTmProcessorModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    
    //cout << "INFO  HK TM Processor Module shutting down" << endl;
    cout << moduleName + " shutting down" << endl;
}

ModuleStatusEnum HkTmProcessorModuleManager::getStatus()
{
    return MODE_RUNNING;
}

void HkTmProcessorModuleManager::runZeroMQ()
{
    // Socket for receiving module messages
    zmq::socket_t   tmpSocket(this->context_, ZMQ_REQ);
    
    module_req_ = std::move(tmpSocket);
    
    auto fdsModuleAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_FDS_MODULE_ADDRESS);
    LogManager::getInstance().info("Connecting to: " + fdsModuleAddress);

    module_req_.bind(fdsModuleAddress);
    
    
    
    // Create a socket with M&C for publishing events.
    // An event message will be sent to the M&C and it will publish the event
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto hktmProcPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_PUB_ADDRESS);

    LogManager::getInstance().info("Publishing events to: " + hktmProcPublisherAddress);

    eventBus_ = std::move( tmpPublisher );
    
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    eventBus_->setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    
    eventBus_->connect(hktmProcPublisherAddress);




    // Create socket with Tools
    shared_ptr<zmq::socket_t>    tmpTools( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto toolsServerAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_TOOLS_SERVER_ADDRESS);

    LogManager::getInstance().info("Tools server: " + toolsServerAddress);

    tools_ = std::move( tmpTools );
    tools_->connect(toolsServerAddress);

    // Get comm layers for each satellite of current mission
    // NOTE: Passes shall contain an indication of the satellite to be used
    // It needs the Tools server up and running
    //createLayers();


    // Wait for messages and process them
    internalRun();
    
    
    /*
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    const int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;
    // At least a thread shall be created
    if (kMaxThread <= 0)
        kMaxThread = 1;
        
    LogManager::getInstance().debug("Max HW concurrencty: " + to_string( std::thread::hardware_concurrency() ) );

    auto mcAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SERVER_ADDRESS);
    LogManager::getInstance().info( "Connecting to: " + mcAddress);

    // Create ROUTER-DEALER. It will receive incoming messages and forward them to workers
    frontend_.bind(mcAddress);
    backend_.bind("inproc://backend");

    std::vector<ServerWorkerZmq *>     worker;
    std::vector<std::thread *>      worker_thread;

    for (int i = 0; i < kMaxThread; ++i)
    {
        ServerWorkerZmq* tmpWorker;

        LogManager::getInstance().debug("Creating server worker: " + to_string(i) );
        tmpWorker = new ServerWorkerZmq(this->context_, ZMQ_REP);

        tmpWorker->setMessageProcessor( std::make_shared<HkTmProcessorMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorkerZmq::run, tmpWorker)));
        worker_thread.back()->detach();
    }






    // Create subscriber
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    auto subscriberAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_SUB_ADDRESS);

    LogManager::getInstance().debug("Creatinng subscriber server worker to Event bus - " + subscriberAddress);

    shared_ptr<ServerWorkerSubZmq> subscriptionWorker( new ServerWorkerSubZmq(this->context_, ZMQ_SUB, moduleName, subscriberAddress) );

    subscriptionWorker->setMessageProcessor( std::make_shared<HkTmProcessorMessageProcessor>() );


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
        //cout << "ERROR: Exception creating proxy: " << e.what() << endl;
        LogManager::getInstance().error("Exception creating proxy: " + *(e.what()) );
    }
*/



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

    /*
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
    */
}

void HkTmProcessorModuleManager::internalRun()
{
    // Main Loop
    ServerMessage   outputMessage;
    bool            done_;
    
    while (done_ == false)
    {
        try
        {
            ServerMessage  inputMessage;
    
            ::receiveMessage(module_req_, inputMessage);
    
            switch(inputMessage.getOperationCode())
            {               
                // Module stop
                case OperationCodeEnum::CODE_SHUTDOWN:
                    ::createReply(outputMessage, 0, "");
                    done_ = true;
                    break;
                    
                // Return the module status
                case OperationCodeEnum::CODE_GET_STATUS:
                    outputMessage = returnStatus(inputMessage);
                    break;
                    
                // New Raw frame has been received from a Ground Station
                case OperationCodeEnum::CODE_NEW_RAW_FRAME:
                    // Forward the message to a Decoder
                    ::sendMessage(xxx, inputMessage);
                    
                    // OPEN POINT: Do we have to reply to all messages?
                    ::createReply(outputMessage, 0, "");
                    break;
                                        
                // Unknown message received
                default:
                    string errorMessage = "ERROR: Unknown message received. It will be ignored. Code: " + inputMessage.getOperationCodeAsString();
            
                    ::createReply(outputMessage, -1, errorMessage);
            
                    LogManager::getInstance().error(errorMessage);
                    break;
            }
        }
        catch(GSException& gsException)
        {
            string exceptionMessage = "ERROR: GS Exception in SHkTmProcessorModuleManager::internalRun: " + gsException.getErrorMessage();
    
            // Create error message. MsgReturnData
            ::createReply(outputMessage, gsException.getErrorCode(), gsException.getErrorMessage());
    
            LogManager::getInstance().error(exceptionMessage);
            //cout << exceptionMessage << endl;
        }
        catch (std::exception &e)
        {
            string exceptionMessage = "ERROR: Exception in HkTmProcessorModuleManager::internalRun: " + string{e.what()};
    
            ::createReply(outputMessage, -1, exceptionMessage);
    
            LogManager::getInstance().error(exceptionMessage);
            //cout << exceptionMessage << endl;
        }
    
        // Send reply
        sendMessage(module_req_, outputMessage);
    }
    
    // Shutdown the module
    shutdown();
}
 
// Return the status of the module
ServerMessage HkTmProcessorModuleManager::returnStatus(ServerMessage &inMessage)
{
    ServerMessage outputMessage;

    // Input message is ignored. It is not needed
    
    try 
    {
        // ----------------------------------------------------------------------
        IW::MsgGetStatusResponse   outMessage;
        
        outMessage.componentId = ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME);
        outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::RUNNING;
       
        // Generate response
        VectorUint8   avroOutputMessage;

        avroOutputMessage = buildMessageVector<IW::MsgGetStatusResponse>(outMessage);

        outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_STATUS_RESPONSE);
        outputMessage.setData(avroOutputMessage);
                
        // ----------------------------------------------------------------------
    } 
    catch(GSException& gsExc) 
    {
        LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        createReply(outputMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Return Status response: " + outputMessage.toString());

    return outputMessage;
}






