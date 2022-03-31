/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __IMODULEMANAGER_INCLUDED__
#define __IMODULEMANAGER_INCLUDED__

#include <string>
#include <memory>
#include <mutex>

using namespace std;

#include "ModuleStatusEnum.h"
#include "GSException.h"
#include "ConfigurationManager.h"
#include "MessageUtils.h"

#include "ServerMessage.h"
#include "LogManager.h"

/**
 * All main subsystems shall implement this interface
 */
class IModuleManager
{
    public:
        IModuleManager(): status_{MODE_NONE}, mutex_{} {};
        virtual ~IModuleManager() {};

        virtual void start() = 0;
        virtual void shutdown() = 0;
        
        virtual void sendStartUpMessage() = 0;
        virtual void publishEvent(const ServerMessage &inMessage, const EventTypeEnum inEventType) = 0;
        

        ModuleStatusEnum getStatus()
        {
            return status_;
        }
        
        ServerMessage returnStatus(const string& inModuleName, ServerMessage &inMessage)
        {
            ServerMessage outputMessage;

            // Input message is ignored. It is not needed
            try 
            {
                // ----------------------------------------------------------------------
                IW::MsgGetStatusResponse   outMessage;
                
                outMessage.componentId = inModuleName;

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

        
        // Compose and send the start up message to the M&C
        // It sends the IP and Port of the component for registering it.
        // This signals the start up of the module
        ServerMessage createStartUpMessage()
        {               
            // Create message 
            auto moduleName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_MODULE_NAME);

            IW::MsgStartup  msgStartUp;
         
            msgStartUp.message = "Component " + moduleName + " started up"; 
            
            // Create AVRO message
            VectorUint8    avroOutputMessage;

            avroOutputMessage = buildMessageVector<IW::MsgStartup>(msgStartUp);

            // Send message to M&C
            ServerMessage  outputMessage;

            outputMessage.setOperationCode(OperationCodeEnum::CODE_START_UP);
            outputMessage.setAuthorizationToken("TODO");
            outputMessage.setData(avroOutputMessage);

            return outputMessage;
        }
        
        
        // Compose and send a Publish Event message
        // Publish an Event in the Pub-Sub socket
        ServerMessage createPublishEvent(const ServerMessage &inMessage, const EventTypeEnum inEventType)
        {
            std::unique_lock<std::mutex> lck(mutex_);
            
            // Get timestamp (if GS_Manager does not have it)
            unsigned long currentTime = TimeUtils::getCurrentTimeMilliseconds();

            // Publish an Event containing the raw or processed frame
            IW::MsgPublishEvent msgPublishEvent;

            msgPublishEvent.authorizationToken = inMessage.getAuthorizationToken();
            
            msgPublishEvent.event.type = static_cast<int>(inEventType);
            msgPublishEvent.event.eventTime = currentTime;
            msgPublishEvent.event.data = const_cast<ServerMessage&>(inMessage).getData();
            msgPublishEvent.event.dataLength = const_cast<ServerMessage&>(inMessage).getDataSize();

            VectorUint8 outputMsgData = buildMessageVector<IW::MsgPublishEvent>(msgPublishEvent);


            // Create second level message
            ServerMessage  outputMessage;

            outputMessage.setOperationCode(OperationCodeEnum::CODE_PUBLISH_EVENT);
            outputMessage.setEventType(inEventType);
            outputMessage.setData(outputMsgData);

            return outputMessage;
        }
        
        
    protected:
        ModuleStatusEnum              status_;
    
        std::mutex                    mutex_;
};


#endif // IMODULEMANAGER_INCLUDED