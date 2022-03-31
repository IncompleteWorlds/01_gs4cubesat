/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include <iostream>

using namespace std;

#include "AvroTypes.h"

#include "ConfigurationManager.h"
#include "MessageUtils.h"
#include "LogManager.h"
#include "GSException.h"

#include "orbpropag_ModuleManager.h"

orbpropag_ModuleManager::orbpropag_ModuleManager()
    : context_{1}, 
      module_req_{context_, ZMQ_PULL}, 
      fds_pub_{context_, ZMQ_REQ}, 
      fds_req_{context_, ZMQ_REQ}, 
      executionId_{},
      parameters_{},
      algorithmIsRunning_{false},
      fortranReturnCode_{0},
      fortranErrorMessage_{},
      fortranDone_{true}
{
}

orbpropag_ModuleManager::~orbpropag_ModuleManager()
{
    // ???
    shutdown();
}

void orbpropag_ModuleManager::init(const string& inConfigFileName)
{
    if (inConfigFileName.empty() == true)
    {
        cerr << "ERROR: Empty configuration file name" << endl;
        return;
    }
    
    try
    {
        // Read the FDS configuration from a JSON config file
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

void orbpropag_ModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info("--------------------------------------------------------------");
    LogManager::getInstance().info("      " + moduleName + " STARTING UP");
    LogManager::getInstance().info("--------------------------------------------------------------");
    
    // Run
    runZeroMQ();
}

void orbpropag_ModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info(moduleName + " SHUTTING DOWN");
}

void orbpropag_ModuleManager::runZeroMQ()
{
    // Socket for receiving module messages
    zmq::socket_t   tmpSocket(this->context_, ZMQ_PULL);
    
    module_req_ = std::move(tmpSocket);
    
    auto fdsModuleAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_FDS_MODULE_ADDRESS);
    LogManager::getInstance().info("Connecting to: " + fdsModuleAddress);

    module_req_.bind(fdsModuleAddress);
    
    
    
    // Module for sending events to the FDS. I.e. algorithm has finished
    zmq::socket_t   tmpFdsPub(this->context_, ZMQ_PUB);
    
    fds_pub_ = std::move(tmpFdsPub);
    
    auto fdsPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_FDS_PUB_ADDRESS);
    LogManager::getInstance().info("Publishing FDS events to: " + fdsPublisherAddress);

    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    fds_pub_.setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    fds_pub_.bind(fdsPublisherAddress);
    
    
    
    // Socket for making requests to the FDS Server; i.e. log message, read or write data in the database
    zmq::socket_t   tmpSocketFds(this->context_, ZMQ_REQ);
    
    fds_req_ = std::move(tmpSocketFds);
    
    auto moduleAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_FDS_SERVER_ADDRESS);
    LogManager::getInstance().info("Connecting to FDS: " + moduleAddress);

    fds_req_.connect(moduleAddress);
        
    // Main module loop
    internalRun();
}

void orbpropag_ModuleManager::internalRun()
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
                    
                // Create a thread and run the algorithm
                case OperationCodeEnum::CODE_START_EXECUTION:
                    if (algorithmIsRunning_ == false)
                    {
                        outputMessage = runAlgorithm(inputMessage);                        
                    }
                    else
                    {
                        ::createReply(outputMessage, -1, "Algorithm is already running");
                    }
                    break;
                    
                case OperationCodeEnum::CODE_STOP_EXECUTION:
                    ::createReply(outputMessage, 0, "");
                    
                    // Trick
                    algorithmIsRunning_ = false;
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
            string exceptionMessage = "ERROR: GS Exception in ServerWorkerZmq::run: " + gsException.getErrorMessage();
    
            // Create error message. MsgReturnData
            ::createReply(outputMessage, gsException.getErrorCode(), gsException.getErrorMessage());
    
            LogManager::getInstance().error(exceptionMessage);
            //cout << exceptionMessage << endl;
        }
        catch (std::exception &e)
        {
            string exceptionMessage = "ERROR: Exception in ServerWorkerZmq::run: " + string{e.what()};
    
            ::createReply(outputMessage, -1, exceptionMessage);
    
            LogManager::getInstance().error(exceptionMessage);
            //cout << exceptionMessage << endl;
        }
    
        // Send reply
        ::sendMessage(module_req_, outputMessage);
    }
    
    // Shutdown the module
    shutdown();
}


ServerMessage orbpropag_ModuleManager::returnStatus(ServerMessage &inMessage)
{
    ServerMessage outputMessage;

    // Input message is ignored. It is not needed
    
    try 
    {
        // ----------------------------------------------------------------------
        IW::MsgGetStatusResponse   outMessage;
        
        outMessage.componentId = ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME);

        switch(status_)
        {
            case MODE_NONE:
                outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::MODE_NONE;
                break;
            case MODE_STARTED:
                outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::STARTED;
                break;
            case MODE_NOT_RUNNING:
                outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::NOT_RUNNING;
                break;
            case MODE_RUNNING:
                outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::RUNNING;
                break;
            case MODE_COMPLETE:
                outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::COMPLETE;
                break;
            case MODE_FAILED:
                outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::FAILED;
                break;
            default:
                outMessage.ComponentStatusEnum = IW::IntComponentStatusEnum::MODE_NONE;
                break;
        }
       
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

    LogManager::getInstance().debug("Add Mission Layer response: " + outputMessage.toString());

    return outputMessage;
}

ServerMessage orbpropag_ModuleManager::runAlgorithm(ServerMessage &inMessage)
{    
    IW::MsgStartModuleExecution avroInputMessage;
    ServerMessage               outputMessage;

    try 
    {
        // ----------------------------------------------------------------------
        extractMessageVector<IW::MsgStartModuleExecution>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);
        
        // Check module name
        string tmpInModuleName = avroInputMessage.module_name;
        
        if (tmpInModuleName != ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME) )
        {
            ::createReply(outputMessage, -1, "Incorrect module name. Module name does not match");
            return outputMessage;
        }
        
        // Store input parameters
        parameters_  = avroInputMessage.parameters;
        executionId_ = avroInputMessage.execution_id;
        
        // std::thread t(internalRunAlgorithm);
        std::thread t( std::bind(&orbpropag_ModuleManager::internalRunAlgorithm, this) );
        
        theThread_ = std::move(t);

        if (theThread_.joinable() == true)
        {
            theThread_.join();
        }
            
        algorithmIsRunning_  = true;
        fortranReturnCode_   = 0;
        fortranErrorMessage_ = "";
        fortranDone_         = false;
        
        ::createReply(outputMessage, 0, "");
    } 
    catch(GSException& gsExc) 
    {
        LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        createReply(outputMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
    }
    
    return outputMessage;
}

void orbpropag_ModuleManager::internalRunAlgorithm()
{    
    // Call Fortran main
    // Before finishing the Fortran Module sound send a message with the return data
    fortranMain();
    
    // Wait for response
    while (algorithmIsRunning_ == true && fortranDone_ == true)
    {
        // Wait for 250 ms
        std::chrono::milliseconds(250);
    }
    
    // Get response
    IW::MsgEndModuleExecution   outputMessage;

    // FIX ME: Copy from input message
    outputMessage.authorizationToken = "TODO";
    outputMessage.module_name        = ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME);
    outputMessage.execution_id       = executionId_;
    outputMessage.errorCode          = fortranReturnCode_;
    outputMessage.errorMessage       = fortranErrorMessage_;
    
    VectorUint8   avroOutputMessage;

    avroOutputMessage = buildMessageVector<IW::MsgEndModuleExecution>(outputMessage);

    
    // Publish the response (to FDS)
    IW::Event  evt;
    
    // Get timestamp (if GS_Manager does not have it)
    unsigned long currentTime = TimeUtils::getCurrentTimeMilliseconds();
    
    // Event will contain only the module name
    evt.type       = static_cast<int>(EventTypeEnum::EVT_FDS_MODULE_FINISHED);
    evt.eventTime  = currentTime;    
    evt.data       = avroOutputMessage;
    evt.dataLength = avroOutputMessage.size();
    
    VectorUint8 outputMsgData = buildMessageVector<IW::Event>(evt);

    
    // Send event type
    string eventId = EVENT_PREFIX + to_string( static_cast<int>(evt.type) );

    zmq::message_t zeroMqMsg{eventId.data(), eventId.size()};

    fds_pub_.send(zeroMqMsg, ZMQ_SNDMORE);

    // Send message data
    zeroMqMsg.rebuild(outputMsgData.data(), outputMsgData.size());

    fds_pub_.send(zeroMqMsg);
    
    
    // Reset parameters
    executionId_         = ""; 
    algorithmIsRunning_  = false;
    fortranReturnCode_   = 0;
    fortranErrorMessage_ = "";
    fortranDone_         = true;
    
    
    // How to detect an error?
    // How to detect it is blocked?
}

void orbpropag_ModuleManager::setFortranReturnCode(int inValue, char *inErrorMessage)
{    
    if (inErrorMessage != nullptr)
    {
        fortranErrorMessage_ = *inErrorMessage;
    }
    
    fortranReturnCode_ = inValue;
    fortranDone_ = true;
    
    LogManager::getInstance().debug("Fortran return code: " + std::to_string(inValue));
}

void orbpropag_ModuleManager::sendFdsMessage(const int inCode, const char* inMessage, char *outMessage)
{
    if (inMessage == nullptr || outMessage == nullptr)
    {
         LogManager::getInstance().error("Null pointer. Invalid message received from external module. Ignored");
        return;
    }
    
    // Build FDS message
    IW::MsgFds   fdsMessage;
    
    IW::ListKeyValues  listParameters;
    IW::KeyValue       tmpParameter;
    
    tmpParameter.key   = std::to_string(inCode);
    tmpParameter.value = *inMessage;
    
    listParameters.listKeyValues.push_back(tmpParameter);
    
    fdsMessage.authorizationToken = "TODO";
    fdsMessage.execution_id       = executionId_;
    fdsMessage.module_name        = ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME);
    fdsMessage.parameters         = listParameters;
    
    auto avroOutputMessage = buildMessageVector<IW::MsgFds>(fdsMessage);
    
    // Send to the FDS
    ServerMessage  outputMessage;
    
    outputMessage.setOperationCode(OperationCodeEnum::CODE_FDS_MESSAGE);
    outputMessage.setAuthorizationToken("TODO");
    outputMessage.setData(avroOutputMessage);

    ::sendMessage(fds_req_, outputMessage);
    
    
    
    
    // Receive and process the answer
    ServerMessage inFdsMessage;

    ::receiveMessage(fds_req_, inFdsMessage);

    // We reuse previous message
    try 
    {
        // ----------------------------------------------------------------------
        extractMessageVector<IW::MsgFds>(static_cast<ServerMessage>(inFdsMessage).getData(), fdsMessage);

        // At the moment, we only process the first parameter
        strcpy(outMessage, fdsMessage.parameters.listKeyValues[0].value.c_str());
    } 
    catch(GSException& gsExc) 
    {
        LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
    }    
}

// It will return 0, if the parameter exists
// It will return -1, if it is not found
int orbpropag_ModuleManager::getParameter(const char* inKey, int inLen, char* outValue)
{
    if (inKey == nullptr || outValue == nullptr) 
    {
        LogManager::getInstance().error("Module: " + ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME)
                                        + " Get Parameter: Null pointer");
        return -1;
    }

    string tmpKey{ *inKey };
    
    for(IW::KeyValue  tmpPair: parameters_.listKeyValues)
    {
        if (tmpPair.key == tmpKey)
        {
            strncpy(outValue, tmpPair.value.c_str(), inLen - 1);

            // Set end of line
            outValue[inLen] = 0x0;
            return 0;
        }
    }
        
    LogManager::getInstance().warning("Module: " + ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME) + 
                                      " Looking for a parameter that does not exist: " + tmpKey);
    return -1;
}

// Set or update the key.
// If it already exists, the content will be replaced
int orbpropag_ModuleManager::setParameter(const char* inKey, char* inValue)
{
    // FIX ME. Do I need a mutex?
    if (inKey == nullptr || inValue == nullptr)
    {
        LogManager::getInstance().error("Module: " + ConfigurationManager::getInstance().getValue( ConfigurationManager::KEY_GEN_MODULE_NAME)
                                    + " Set Parameter: Null pointer");
        return -1;
    }
    
    string tmpKey{ *inKey };
    string tmpValue{ *inValue };
    
    for(IW::KeyValue  tmpPair: parameters_.listKeyValues)
    {
        if (tmpPair.key == tmpKey)
        {
            // Replace the value
            tmpPair.value = tmpValue;
            return 0;
        }
    }
    
    IW::KeyValue  tmpPair;
    
    tmpPair.key   = tmpKey;
    tmpPair.value = tmpValue;
    
    // Not found, add it
    parameters_.listKeyValues.push_back( tmpPair );
    return 0;
}