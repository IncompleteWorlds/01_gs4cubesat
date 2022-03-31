/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

// For the HTTP inteface
#include <cpprest/json.h>

using namespace web::json;


#include "ConfigurationManager.h"

#include "ServerWorkerZmq.h"
#include "ServerWorkerSubZmq.h"
#include "MessageUtils.h"
#include "LogManager.h"
#include "GSException.h"

#include "FdsMessageProcessor.h"
#include "FdsModuleManager.h"


void FdsModuleManager::handleHttpRequest(http_request inRequest)
{
    // Check the method
    if (inRequest.method() != methods::GET  && 
        inRequest.method() != methods::POST && 
        inRequest.method() != methods::PUT &&
        inRequest.method() != methods::DEL) {
        LogManager::getInstance().error("Invalid method: " + inRequest.method() + " in HTTP request");
        inRequest.reply(status_codes::MethodNotAllowed);
        return;
    }

    // It returns a list of components of the path
    auto path = extractPath(inRequest);
    if (path.size() == 0) {
        LogManager::getInstance().error("Received HTTP with an empty path");
        inRequest.reply(status_codes::NotFound);
        return;
    }
    
    LogManager::getInstance().debug("Path: ");
    for(string p : path) {
        LogManager::getInstance().debug(p);
    }
    
    // Check first part of the Path
    if (path[0] != "gsaas") {
        if (path[0] != "fdsaas") {
            LogManager::getInstance().error("Invalid HTTP request. Unknown API call: " + path[0]);
            inRequest.reply(status_codes::BadRequest);
            return;
        } 
        
        // /fdsaas/ ....
    } else {
        // /gsaas
        // Remove first element
        path.erase( path.begin() );
        
        // is it fdsaas?
        if (path[0] != "fdsaas") {
            LogManager::getInstance().error("Invalid HTTP request. Unknown API call: " + path[0]);
            inRequest.reply(status_codes::BadRequest);
            return;
        }
        
        //  /fdsaas/ ...
    }

    // Convert into Message Code
    OperationCodeEnum messageCode = getMessageCode(inRequest.method(), path);
        
    // Get Authorization Token
    auto  requestHeaders = inRequest.headers();
    
    // Check the Authorization header is present  
    auto  referenceToAuthHeader = requestHeaders.find("Authorization");
    if (referenceToAuthHeader == requestHeaders.end()) {
        // Authorization token not found
        LogManager::getInstance().error("Authorization token not found in the HTTP headers");
        inRequest.reply(status_codes::Unauthorized);
        return;
    }
    string authorizationToken = referenceToAuthHeader->second;
    LogManager::getInstance().debug("Authorization token: " + authorizationToken);
    
    // Create message
    ServerMessage  interMessage;
    
    interMessage.setOperationCode(messageCode);
    interMessage.setAuthorizationToken(authorizationToken);
    
    inRequest
        .extract_json()
        .then([&interMessage](pplx::task<json::value> task) {
            try
            {
                // Get Body
                auto  requestBody = task.get();
 
                if (requestBody.is_null() == true)
                {
                    LogManager::getInstance().error("Body is empty");
                    inRequest.reply(status_codes::BadRequest);
                }
                
                // Create message
                    
                    // 
                    interMessage.setBody(requestBody);
    
                    // Send to main control loop
                    // nng::message m;
                    //http_socket_req_.send(m);
                    
                    // Read response
                    // nng::message mr;
                    //http_socket_req_.recv(mr);
                    
                    // Create HTTP response
                    
                    
                }
            }
            catch (http_exception const & e)
            {
                LogManager::getInstance().error("Exception while extracting JSON body: " + e.what() );
            }
        })
        .wait();    
}

/**
 * Extract the components of the HTTP RequEst path
 */
vector<utility::string_t> FdsModuleManager::extractPath(const http_request& inRequest) 
{
    LogManager::getInstance().debug("Path: " + inRequest.relative_uri().path() );
    auto relativePath = uri::decode(inRequest.relative_uri().path());

    LogManager::getInstance().debug("Relative Path: " + inRequest.relative_uri().path());
    return uri::split_path(relativePath);        
}

/**
 * Return the message associated to an HTTP request
 */
OperationCodeEnum FdsModuleManager::getMessageCode(const string& inMethod, const vector<utility::string_t>& inPathParts)
{
    if (inMethod.empty() == true)
        return OperationCodeEnum::CODE_NONE;

    OperationCodeEnum output;
    
    // GET Operations
    if (inMethod == methods::GET) {
        if (inPathParts[0] == "orb_propagation" || inPathParts[0] == "ORB_PROPAGATION") { 
            output = OperationCodeEnum::CODE_FDS_ORB_PROPAGATION;
        }
        
        if (inPathParts[0] == "orb_determination" || inPathParts[0] == "ORB_DETERMINATION") { 
            output = OperationCodeEnum::CODE_FDS_ORB_DETERMINATION;
        }
            
        if (inPathParts[0] == "passes" || inPathParts[0] == "PASSES") { 
            output = OperationCodeEnum::CODE_FDS_GET_PASSES;
        }
    }
    
    // POST (Update) Operations
    
    // PUT (Create) Operations

    // DELETE (Delete) Operations

    return output;
}





FdsModuleManager::FdsModuleManager()
    : nanomsgThread_{}, nanomsgBusThread_{}, endFlag_{false}  // context_{1},
{
}

FdsModuleManager::~FdsModuleManager()
{
    // ???
    shutdown();
}

void FdsModuleManager::init(const string& inConfigFileName)
{
    if (inConfigFileName.empty() == false) 
    {
        try 
        {
            // Read the FDS configuration from a JSON config file
            // Throws and exception if an error is found
            ConfigurationManager::getInstance().load(inConfigFileName);
            
            // TODO: Read the list of modules of FDS
            // Specific configuration processing

            //int major, minor, patch;

            //zmq::version(&major, &minor, &patch);

            // Initialize the Log Manager
            LogManager&  logMng = LogManager::getInstance();

            logMng.init( ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_LOG_FILE ));

            logMng.info("Configuration correctly loaded");
            //string tmpMessage = "Current ZeroMQ version: " + to_string(major) + "." + to_string(minor) + "." + to_string(patch);
            //logMng.info(tmpMessage);
            logMng.info("New Nanomsg version: " + string{nng_version()});
        } catch (const std::exception& e) {
            LogManager::getInstance().error(e.what());
        } catch (...) {
            LogManager::getInstance().error("Unknown exception");
        }
    } else {
        cerr << "ERROR: Empty configuration file name" << endl;
    }
}

void FdsModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info("--------------------------------------------------------------");
    LogManager::getInstance().info("      " + moduleName + " STARTING UP");
    LogManager::getInstance().info("--------------------------------------------------------------");
    
    // Create the main control loop REP socket
    main_socket_ = nng::rep::open();
    LogManager::getInstance().debug("Nanomsg main control socket created");
    
    // Get listening address for the In-Process control socket
    string nngServerAddress{"inproc://main_control"};
    LogManager::getInstance().info("Starting control loop at: " + nngServerAddress);

    main_socket_.listen(nngServerAddress.c_str());
    LogManager::getInstance().debug("Started listening");


    // Create HTTP interface
    createHttpInterface();
    
    // Create REQ/REP and BUS interfaces
    createNanoMsgInterface();
    
    // Run
    mainControlLoop();
}

void FdsModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info(moduleName + " SHUTTING DOWN");
}

ModuleStatusEnum FdsModuleManager::getStatus()
{
    return MODE_RUNNING;
}

/**
 * @brief It creates an HTTP interface
 * It creates a thread that receives HTTP requests using the REST protocol and JSON as payload
 * 
 */
void FdsModuleManager::createHttpInterface()
{
    // Create socket
    http_socket_req_ = nng::req::open();
    LogManager::getInstance().debug("Nanomsg HTTP socket created");
    
    // Get listening address
    LogManager::getInstance().info("Connecting HTTP socket to: inproc://main_control");

    http_socket_req_.dial("inproc://main_control");
    LogManager::getInstance().debug("HTTP socket ready to send messages");
    
    
    
    // Start a new thread
    auto httpAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_HTTP_SERVER_ADDRESS);
    LogManager::getInstance().info("Creating HTTP interface. Listen to address: " + httpAddress);

    http_listener tmpListener(httpAddress);
    

    // Create HTTP request handler
    tmpListener.support(std::bind(&FdsModuleManager::handleHttpRequest, this, std::placeholders::_1));

    listener_ = move(tmpListener);
}

/**
 * @brief Nanomsg Req/Rep control loop
 * It will run in a separated thread
 */
void FdsModuleManager::nanomsgRequest()
{
    int errorCode = 0;

    LogManager::getInstance().info("Creating Nanomsg REQ/REP interface");

    try {
        // Create socket
        reply_socket_ = nng::rep::open();
        LogManager::getInstance().debug("Nanomsg socket created");
        
        // Get listening address
        auto nngServerAddress = ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_FDS_SERVER_ADDRESS );
        LogManager::getInstance().info("Connecting to: " + nngServerAddress);

        reply_socket_.listen(nngServerAddress.c_str());
        LogManager::getInstance().debug("Started listening");

        while (endFlag_ == false) {
            // Read a message
            ServerMessage   inMessage;
            
            ::receiveMessage(reply_socket_, inMessage);
            
            LogManager::getInstance().debug("Nanomsg. Message received: " + inMessage.toStringShort() );

            // Send to main control loop
            ::sendMessage(main_socket_, inMessage);
        }
    } catch(exception &e) {
        LogManager::getInstance().error("Exception: While handling req/rep: " + string{ e.what() });
        throw GSException("Exception: " + string{e.what()});
    }
}

/**
 * @brief Nanomsg Bus control loop
 * It will run in a separated thread
 */
void FdsModuleManager::nanomsgBus()
{
    int errorCode = 0;

    LogManager::getInstance().info("Creating Nanomsg BUS interface");

    try {
        // Create socket
        reply_socket_ = nng::bus::open();
        LogManager::getInstance().debug("Nanomsg BUS socket created");
        
        // Get listening address
        auto nngServerAddress = ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_BUS_ADDRESS );
        LogManager::getInstance().info("Connecting to: " + nngServerAddress);

        reply_socket_.listen(nngServerAddress.c_str());
        LogManager::getInstance().debug("Started listening to BUS");

        while (endFlag_ == false) {
            // Read a message
            //auto  newMsg = reply_socket_.recv_msg();
            ServerMessage  inMessage;
            
            ::receiveMessage(reply_socket_, inMessage);
            
            LogManager::getInstance().debug("Nanomsg. Message received: " + inMessage.toStringShort() );

            // Send to main control loop
            // ::sendMessage(main, inMessage);
        }
    } catch(exception &e) {
        LogManager::getInstance().error("Exception: While handling bus: " + string{ e.what() });
        throw GSException("Exception: " + string{ e.what() });
    }
}

void FdsModuleManager::createNanoMsgInterface()
{
    // Create socket
    // The NanoMsg REQ/REP interface will use it to send message to the main Controller
    nng_socket_req_ = nng::req::open();
    LogManager::getInstance().debug("Nanomsg socket REQ created");
    
    // Get listening address
    LogManager::getInstance().info("Connecting to: inproc://main_control");

    nng_socket_req_.dial("inproc://main_control");
    LogManager::getInstance().debug("Reading to send messages");
    
    
    // Create socket
    // The NanoMsg BUS interface will use it to send message to the main Controller
    bus_socket_req_ = nng::req::open();
    LogManager::getInstance().debug("Nanomsg socket BUS REQ created");
    
    // Get listening address
    LogManager::getInstance().info("Connecting to: inproc://main_control");

    bus_socket_req_.dial("inproc://main_control");
    LogManager::getInstance().debug("Reading to send messages");
    
    
    
    // Create the Nanomsg REQ/REP interface
    //nanomsgThread_ = std::thread(std::bind(&FdsModuleManager::nanomsgRequest, this));
    
    // Create the Nanomsg BUS interface
    //nanomsgThread_ = std::thread(std::bind(&FdsModuleManager::nanomsgBus, this));
    
    
    
    /*
    zmq::socket_t   frontend_(this->context_, ZMQ_ROUTER);
    zmq::socket_t   backend_(this->context_, ZMQ_DEALER);

    // Max. number of "hw" threads
    int kMaxThread = (std::thread::hardware_concurrency() - 1) / 2;
    // At least a thread shall be created
    if (kMaxThread <= 0)
        kMaxThread = 1;

    LogManager::getInstance().debug("Max HW concurrencty: " + to_string(std::thread::hardware_concurrency()) );

    auto fdsAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_SERVER_ADDRESS);
    LogManager::getInstance().info("Connecting to: " + fdsAddress);

    // Create ROUTER-DEALER. It will receive incoming messages and forward them to workers
    frontend_.bind(fdsAddress);
    backend_.bind("inproc://backend");

    std::vector<ServerWorkerZmq *>     worker;
    std::vector<std::thread *>      worker_thread;

    for (int i = 0; i < kMaxThread; ++i)
    {
        ServerWorkerZmq* tmpWorker;

        LogManager::getInstance().debug("Creating server worker: " + to_string(i) );
        tmpWorker = new ServerWorkerZmq(this->context_, ZMQ_REP);

        tmpWorker->setMessageProcessor( std::make_shared<FdsMessageProcessor>() );

        worker.push_back(tmpWorker);

        // Create and detach the thread
        worker_thread.push_back(new std::thread(std::bind(&ServerWorkerZmq::run, tmpWorker)));
        worker_thread.back()->detach();
    }


    // Create a socket for sending events to the M&C
    shared_ptr<zmq::socket_t>    tmpPublisher( new zmq::socket_t{this->context_, ZMQ_REQ} );

    auto mcPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_PUB_ADDRESS);

    LogManager::getInstance().info("Publishing events to: " + mcPublisherAddress);

    auto eventBus_ = std::move( tmpPublisher );
    
    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    eventBus_->setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    eventBus_->connect(mcPublisherAddress);


    // Create subscriber
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);
    auto subscriberAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_SUB_ADDRESS);

    LogManager::getInstance().debug("Creating subscriber server worker to Event bus: " + subscriberAddress);

    shared_ptr<ServerWorkerSubZmq> subscriptionWorker( new ServerWorkerSubZmq(this->context_, ZMQ_SUB, moduleName, subscriberAddress) );

    subscriptionWorker->setMessageProcessor( std::make_shared<FdsMessageProcessor>() );

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
        LogManager::getInstance().info("Removing server worker ");
        delete xx;
    }

    for(auto xx: worker_thread)
    {
        LogManager::getInstance().info("Removing server worker thread ");
        delete xx;
    }
    */
}




void FdsModuleManager::mainControlLoop()
{
    // Main Loop
    ServerMessage   outputMessage; 
    
    // Create HTTP task
    pplx::task<void> listenerTask;
    
    try {
        listenerTask = listener_
        .open()
        //.then([&tmpListener]() {
        .then([]()  {
            LogManager::getInstance().info("HTTP. Starting to listen");
        })
        .then([=]() {
            // Infinite loop
            while (endFlag_ == false) {
                std::this_thread::sleep_for(200ms);
            }
        });
    } catch (exception  &e) {
        cout << e.what() << endl;
        LogManager::getInstance().error("Exception processing HTTP Request: " + string{ e.what() } );
    }
    
    while (endFlag_ == false)
    {
        try
        {
            ServerMessage  inputMessage;
    
            ::receiveMessage(main_socket_, inputMessage);
    
            switch(inputMessage.getOperationCode())
            {
                // Module stop
                case OperationCodeEnum::CODE_SHUTDOWN:
                    ::createReply(outputMessage, 0, "");
                    endFlag_ = true;
                    break;

                // Return the module status
                case OperationCodeEnum::CODE_GET_STATUS:
                    outputMessage = returnStatus("FDS Server", inputMessage);
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
            string exceptionMessage = "ERROR: GS Exception in FdsModuleManager::mainControlLoop: " + gsException.getErrorMessage();
    
            // Create error message. MsgReturnData
            ::createReply(outputMessage, gsException.getErrorCode(), gsException.getErrorMessage());
    
            LogManager::getInstance().error(exceptionMessage);
            //cout << exceptionMessage << endl;
        }
        catch (std::exception &e)
        {
            string exceptionMessage = "ERROR: Exception in FdsModuleManager::mainControlLoop: " + string{e.what()};
    
            ::createReply(outputMessage, -1, exceptionMessage);
    
            LogManager::getInstance().error(exceptionMessage);
            //cout << exceptionMessage << endl;
        }
    
        // Send reply
        ::sendMessage(main_socket_, outputMessage);
    }
    
    // Wait for HTTP interface
    if (listenerTask.is_done() == false)
        listenerTask.wait();
    LogManager::getInstance().debug("End of HTTP loop. Exiting");

    // Shutdown the module
    shutdown();
}