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

#include "KissLayer.h"
#include "Ax25Layer.h"
#include "CspLayer.h"
#include "HdlcLayer.h"
#include "CcsdsLayer.h"

#include "LayersTmDecoderModuleManager.h"

LayersTmDecoderModuleManager::LayersTmDecoderModuleManager()
    : context_{1}, 
      module_req_{context_, ZMQ_PULL}, 
      mcs_pub_{context_, ZMQ_REQ}
{
}

LayersTmDecoderModuleManager::~LayersTmDecoderModuleManager()
{
    // ???
    shutdown();
}

void LayersTmDecoderModuleManager::init(const string& inConfigFileName)
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

void LayersTmDecoderModuleManager::start()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info("--------------------------------------------------------------");
    LogManager::getInstance().info("      " + moduleName + " STARTING UP");
    LogManager::getInstance().info("--------------------------------------------------------------");
    
    // Run
    runZeroMQ();
}

void LayersTmDecoderModuleManager::shutdown()
{
    auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

    LogManager::getInstance().info(moduleName + " SHUTTING DOWN");
}

void LayersTmDecoderModuleManager::runZeroMQ()
{
    // Socket for receiving module messages
    zmq::socket_t   tmpSocket(this->context_, ZMQ_PULL);
    
    module_req_ = std::move(tmpSocket);
    
    auto mcsModuleAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_MCS_MODULE_ADDRESS);
    LogManager::getInstance().info("Connecting to: " + mcsModuleAddress);

    module_req_.bind(mcsModuleAddress);
    
    
    
    // Module for sending events to the MCS. I.e. processing has failed
    zmq::socket_t   tmpMcsPub(this->context_, ZMQ_PUB);
    
    mcs_pub_ = std::move(tmpMcsPub);
    
    auto fdsPublisherAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_MCS_PUB_ADDRESS);
    LogManager::getInstance().info("Publishing MCS events to: " + fdsPublisherAddress);

    // Set timeout
    auto  timeoutBuffer = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT);
    
    int  timeoutValue = std::atoi(timeoutBuffer.c_str());
    
    mcs_pub_.setsockopt(ZMQ_SNDTIMEO, timeoutValue);
    mcs_pub_.bind(fdsPublisherAddress);
    
    
    
    // Get comm layers for each satellite of current mission
    // NOTE: Passes shall contain an indication of the satellite to be used
    // It needs the Tools server up and running
    createLayers();
        
    // Main module loop
    internalRun();
}

void LayersTmDecoderModuleManager::internalRun()
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
                    outputMessage = processFrame(inputMessage);
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
            string exceptionMessage = "ERROR: GS Exception in LayersTmDecoderModuleManager::internalRun: " + gsException.getErrorMessage();
    
            // Create error message. MsgReturnData
            ::createReply(outputMessage, gsException.getErrorCode(), gsException.getErrorMessage());
    
            LogManager::getInstance().error(exceptionMessage);
            //cout << exceptionMessage << endl;
        }
        catch (std::exception &e)
        {
            string exceptionMessage = "ERROR: Exception in LayersTmDecoderModuleManager::internalRun: " + string{e.what()};
    
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


ServerMessage LayersTmDecoderModuleManager::returnStatus(ServerMessage &inMessage)
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

    LogManager::getInstance().debug("Return Status response: " + outputMessage.toString());

    return outputMessage;
}

ServerMessage LayersTmDecoderModuleManager::processFrame(ServerMessage &inMessage)
{    
    // Publish message; Raw Frame
    LogManager::getInstance().debug("Publishing event: Raw Frame");
    
    publishEvent(inMessage, EventTypeEnum::EVT_NEW_RAW_FRAME);
    
    // Process raw frame. Generate Processed Frame
    // Process the Raw frame by applying all layers
    LogManager::getInstance().debug("Processing: Raw Frame");
    IW::TM_ProcessedFrame   processedFrame = processLayers(inMessage);
    
    // Publish message; Processed Frame
    LogManager::getInstance().debug("Publishing event: Processed Frame");
    // Retrieve last processed frame. Send to the TM Archive
    VectorUint8 avroOutputMessage = buildMessageVector<IW::TM_ProcessedFrame>(processedFrame);

    ServerMessage tmpProcessedMessage;

    tmpProcessedMessage.setData(avroOutputMessage);

    publishEvent(tmpProcessedMessage, EventTypeEnum::EVT_NEW_PROCESSED_FRAME);
    
    
    ServerMessage               outputMessage;
        
    ::createReply(outputMessage, 0, "");
    
    return outputMessage;
}

void HkTmProcessorMessageProcessor::processLayers(const ServerMessage &inMessage)
{
    // Decommute frame
    shared_ptr<BaseLayer>   currentLayer;
    IW::TM_ProcessedFrame   processedFrame;
    RawFrameType            currentDataField{ static_cast<ServerMessage>(inMessage).getData() };

    // Set frame details
    processedFrame.id           = frameCounter_;
    processedFrame.frameTypeId  = 0;
    processedFrame.creationTime = TimeUtils::now();

    for(uint i = 0; i < HkTmProcessorModuleManager::getInstance().getNumLayers(); i ++)
    {
        currentLayer = HkTmProcessorModuleManager::getInstance().getLayer(i);

        // Process using next protocol
        processedFrame = currentLayer->indication(currentDataField);

        // Empty?
        if (processedFrame.groups.get_array().size() > 0)
        {
            // Extract data field
            uint groupId = currentLayer->getDataGroupIndex();
            uint fieldId = currentLayer->getDataFieldIndex();
            
            IW::ProcessedField  tmpField = processedFrame.groups.get_array()[groupId].fields[fieldId];

            currentDataField = stringToVector(tmpField.value);
        }
    }

    // Empty?
    if (processedFrame.groups.get_array().size() > 0)
    {
            /*
            // Convert between Avro and internal format
            IW::ProcessedFrame  avroProcessedFrame;

            avroProcessedFrame.id            = processedFrame.id_;
            avroProcessedFrame.frameTypeId   = processedFrame.frameTypeId_;
            avroProcessedFrame.creationTime  = processedFrame.creationTime_;
            
            // Copy groups
            for(IntGroupProcessedField currentGroup: processedFrame.groups_)
            {
                IW::GroupProcessedField  avroGroup;
                
                avroGroup.id = currentGroup.id_;
                avroGroup.oolFields = currentGroup.oolFields_;
                avroGroup.oolFlag = currentGroup.oolFlag_;
                              
                // Copy fields
                for(IntProcessedField  currentField: currentGroup.fields_)
                {
                    IW::ProcessedField   avroField;

                    avroField.index        = currentField.index_;
                    avroField.fieldTypeId  = currentField.fieldTypeId_;
                    avroField.fieldName    = currentField.fieldName_;
                    avroField.value        = currentField.value_;

                    // Add field to group
                    avroGroup.fields.push_back(avroField);
                }
                
                // Add group to frame
                avroProcessedFrame.groups.push_back(avroGroup);
            }
            */
    }
}

/**
 * @brief It publishes an error message, when the decoding fails
 */
void LayersTmDecoderModuleManager::publishErrorMessage()
{    
    
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

    mcs_pub_.send(zeroMqMsg, ZMQ_SNDMORE);

    // Send message data
    zeroMqMsg.rebuild(outputMsgData.data(), outputMsgData.size());

    mcs_pub_.send(zeroMqMsg);
    
    
    // Reset parameters
    executionId_         = ""; 
    algorithmIsRunning_  = false;
    fortranReturnCode_   = 0;
    fortranErrorMessage_ = "";
    fortranDone_         = true;
    
    
    // How to detect an error?
    // How to detect it is blocked?
}






/**
 * @brief HkTmProcessorModuleManager::createLayers
 * Retrieve the comm layers that the mission will use and create the stack of
 * protocols
 */
void LayersTmDecoderModuleManager::createLayers()
{
    LogManager::getInstance().info("INFO: Creating layers");
    
    // Retrieve layers
    IW::MsgGetMissionLayers  msgLayers;

    msgLayers.authorizationToken = "TODO";
    msgLayers.missionName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_MISSION_ID);

    VectorUint8    avroOutputMessage;

    avroOutputMessage = buildMessageVector<IW::MsgGetMissionLayers>(msgLayers);

    // Send message to Tools
    ServerMessage  outputMessage;

    outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_MISSION_LAYERS);
    outputMessage.setAuthorizationToken("TODO");
    outputMessage.setData(avroOutputMessage);

    ::sendMessage(*tools_, outputMessage);

    ServerMessage responseMessage;

    ::receiveMessage(*tools_, responseMessage);
    
    if (responseMessage.getOperationCode() == OperationCodeEnum::CODE_GET_MISSION_LAYERS_RESPONSE)
    {
        // Process response message
        // Layer = index
        IW::ListKeyValues   listLayers;

        ::extractMessageVector<IW::ListKeyValues>(responseMessage.getData(), listLayers);

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
                    
                    // TODO: Set Upper and Lower layer
                }
                else
                {
                    //cerr << "ERROR: Layer is a null pointer" << endl;
                    LogManager::getInstance().error("Layer is a null pointer");
                }
            }
        }
    }
    else
    {
        LogManager::getInstance().warning("Layers not found for mission: " + msgLayers.missionName);
    }
}





shared_ptr<BaseLayer> LayersTmDecoderModuleManager::getLayer(const uint index)
{
    shared_ptr<BaseLayer>  output{nullptr};

    if (index > 0 && index < layers_.size())
    {
        output = layers_[index];
    }

    return output;
}

uint LayersTmDecoderModuleManager::getNumLayers()
{
    return layers_.size();
}



shared_ptr<BaseLayer> LayersTmDecoderModuleManager::factoryLayers(const string& inLayerName)
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
    
    if (CcsdsLayer::LAYER_NAME == inLayerName)
    {
        output = move( shared_ptr<CcsdsLayer> (new CcsdsLayer()) );
    }

    return output;
}

void LayersTmDecoderModuleManager::getLayerParameters(const string& inLayerName, IW::ListParameters& inListParameters)
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

    ::sendMessage(*tools_, outputMessage);

    ServerMessage responseMessage;

    ::receiveMessage(*tools_, responseMessage);
    
    if (responseMessage.getOperationCode() == OperationCodeEnum::CODE_GET_LAYER_PARAMETERS_RESPONSE)
    {
        // Process response message
        IW::ListParameters   tmpListParameters;

        ::extractMessageVector<IW::ListParameters>(responseMessage.getData(), tmpListParameters);

        // Copy parameters
        inListParameters = tmpListParameters;
    }
}

void LayersTmDecoderModuleManager::getFrameDefinitions(const string& inLayerName, IW::ListFrameTypes& listFrameTypes)
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

    ::sendMessage(*tools_, outputMessage);

    ServerMessage responseMessage;

    receiveMessage(*tools_, responseMessage);

    if (responseMessage.getOperationCode() == OperationCodeEnum::CODE_GET_LAYER_FRAME_TYPES_RESPONSE)
    {
        // Process response message
        extractMessageVector<IW::ListFrameTypes>(responseMessage.getData(), listFrameTypes);         
    }
    else
    {
        LogManager::getInstance().info("No frames are defined for layer: " + inLayerName);
    }
}

