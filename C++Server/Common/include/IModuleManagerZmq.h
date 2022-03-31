/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __IMODULEMANAGER_ZMQ_INCLUDED__
#define __IMODULEMANAGER_ZMQ_INCLUDED__

#include <string>
#include <memory>
#include <mutex>

using namespace std;

// ZeroMq
#include <zmq.hpp>

#include "AvroTypes.h"

#include "ModuleStatusEnum.h"

#include "OperationCodeEnum.h"
#include "EventTypeEnum.h"
#include "CommonTypes.h"
#include "ServerMessage.h"
#include "ConfigurationManager.h"
#include "MessageUtils.h"
#include "TimeUtils.h"
#include "ModuleStatusEnum.h"
#include "GSException.h"
#include "IModuleManager.h"



/**
 * All main subsystems shall implement this interface
 */
class IModuleManagerZmq : public IModuleManager
{
    public:
        IModuleManagerZmq(): IModuleManager{}, publisher_{}  {};
        virtual ~IModuleManagerZmq() {};

        virtual void start() = 0;
        virtual void shutdown() = 0;

        
        // Compose and send the start up message to the M&C
        // It sends the IP and Port of the component for registering it.
        // This signals the start up of the module
        
        void sendStartUpMessage()
        {
            if (publisher_.get() == nullptr)
                return;

            // Send message to M&C
            ServerMessage  tmpMessage = createStartUpMessage();

            ::sendMessage(*publisher_, tmpMessage);
            
            // Reply
            ServerMessage   unusedMessage;
            
            ::receiveMessage(*publisher_, unusedMessage);
        }
        
        
        // Compose and send a Publish Event message
        // Publish an Event in the Pub-Sub socket
        void publishEvent(const ServerMessage &inMessage, const EventTypeEnum inEventType)
        {
            if (publisher_ == nullptr)
                return;

            ServerMessage   tmpMessage = createPublishEvent(inMessage, inEventType);
            
            ::sendMessage(*publisher_, tmpMessage);
            
            // Reply
            ServerMessage   unusedMessage;
            
            ::receiveMessage(*publisher_, unusedMessage);
        }
        
        
    protected:
        shared_ptr<zmq::socket_t>     publisher_;

};

#endif // IMODULEMANAGERZMQ_INCLUDED
