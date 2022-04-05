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

#include "AvroTypes.h"

#include "ModuleStatusEnum.h"

#include "OperationCodeEnum.h"
#include "EventTypeEnum.h"
#include "CommonTypes.h"
#include "ServerMessage.h"
#include "ConfigurationManager.h"
#include "MessageUtils.h"
#include "TimeUtils.h"



/**
 * All main subsystems shall implement this interface
 */
class IModuleManager {

public:
        IModuleManager(): publisher_{}, mutex_{} {};
        virtual ~IModuleManager() {};

        virtual void start() = 0;
        virtual void shutdown() = 0;

        virtual ModuleStatusEnum getStatus() = 0;
        
        // Compose and send the start up message to the M&C
        void sendStartUpMessage()
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
            outputMessage.setData(avroOutputMessage);

            sendMessage(*publisher_, outputMessage);
            
            // Reply
            ServerMessage   unusedMessage;
            
            receiveMessage(*publisher_, unusedMessage);
        }
        
        
        // Compose and send a Publish Event message
        // Publish an Event in the Pub-Sub socket
        void publishEvent(const ServerMessage &inMessage, const EventTypeEnum inEventType)
        {
            std::unique_lock<std::mutex> lck(mutex_);
            
            // Get timestamp (if GS_Manager does not have it)
            unsigned long currentTime = TimeUtils::getCurrentTimeMilliseconds();

            // Publish an Event containing the raw or processed frame
            IW::MsgPublishEvent msgPublishEvent;

            msgPublishEvent.authorizationToken = "TODO";
            
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

            sendMessage(*publisher_, outputMessage);
            
            // Reply
            ServerMessage   unusedMessage;
            
            receiveMessage(*publisher_, unusedMessage);
        }
        
        
protected:
        shared_ptr<zmq::socket_t>     publisher_;

        std::mutex                    mutex_;
};

#endif // IMODULEMANAGER_INCLUDED
