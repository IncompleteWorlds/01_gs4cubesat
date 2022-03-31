/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __IMODULEMANAGER_NNG_INCLUDED__
#define __IMODULEMANAGER_NNG_INCLUDED__

#include <string>
#include <memory>
#include <mutex>

using namespace std;


// Nanomsg
#include <nngpp/nngpp.h>
#include <nngpp/protocol/req0.h>
#include <nngpp/protocol/rep0.h>
#include <nngpp/protocol/bus0.h>


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
class IModuleManagerNng : public IModuleManager
{
    public:
        IModuleManagerNng(): IModuleManager{}, eventBus_{}, logBus_{}  {};
        virtual ~IModuleManagerNng() {};

        virtual void start() = 0;
        virtual void shutdown() = 0;

        
        // Compose and send the start up message to the M&C
        // It sends the IP and Port of the component for registering it.
        // This signals the start up of the module
        
        void sendStartUpMessage()
        {
            // Socket is not active
            if (!eventBus_)
                return;

            // Send message to M&C
            ServerMessage  tmpMessage = createStartUpMessage();

            ::sendMessage(eventBus_, tmpMessage);
            
            // Reply
            //ServerMessage   unusedMessage;
            
            //::receiveMessage(eventBus_, unusedMessage);
        }
        
        
        // Compose and send a Publish Event message
        // Publish an Event in the Pub-Sub socket
        void publishEvent(const ServerMessage &inMessage, const EventTypeEnum inEventType)
        {
            // Socket is not active
            if (eventBus_.id() == 0)
                return;

            ServerMessage   tmpMessage = createPublishEvent(inMessage, inEventType);
            
            ::sendMessage(eventBus_, tmpMessage);
            
            // Reply
            ServerMessage   unusedMessage;
            
            ::receiveMessage(eventBus_, unusedMessage);
        }
        
        
    protected:
        nng::socket    eventBus_;
        nng::socket    logBus_;

};

#endif // IMODULEMANAGERNNG_INCLUDED
