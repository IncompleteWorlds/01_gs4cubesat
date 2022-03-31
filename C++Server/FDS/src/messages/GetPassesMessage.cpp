/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include <string>
#include <iostream>

using namespace std;

#include "AvroTypes.h"

#include "GSException.h"
#include "LogManager.h"
#include "MessageUtils.h"

#include "messages/GetPassesMessage.h"

GetPassesMessage::GetPassesMessage()
{
}

GetPassesMessage::~GetPassesMessage()
{
}

ServerMessage GetPassesMessage::processMessage(const ServerMessage& inMessage, ServerWorkerZmq& inParent)
{
    // Create reply message
    ServerMessage outputMessage;

    // Extract the AVRO message from body
    IW::MsgGetPasses avroInputMessage;

    try
    {
        // ----------------------------------------------------------------------
        extractMessageVector<IW::MsgGetPasses>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);
        
//        // Check Authorization
//        // Retrieve layers
//    IW::MsgGetMissionLayers  msgLayers;
//
//    msgLayers.authorizationToken = "TODO";
//    msgLayers.missionName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_MISSION_ID);
//
//    VectorUint8    avroOutputMessage;
//
//    avroOutputMessage = buildMessageVector<IW::MsgGetMissionLayers>(msgLayers);
//
//    // Send message to Tools
//    ServerMessage  outputMessage;
//
//    outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_MISSION_LAYERS);
//    outputMessage.setData(avroOutputMessage);
//
//    sendMessage(*tools_, outputMessage);
//
//    ServerMessage responseMessage;
//
//    receiveMessage(*tools_, responseMessage);

        //            // Get Mission
        //            if (avroInputMessage.missionName.empty() == false)
        //            {
        //                IW::Layer   theLayer;
        //                int64_t     layerId;
        //
        //                layerId = ToolsDatabase::getInstance().createLayer(avroInputMessage.layer);
        //
        //                createReply(outputMessage, 0, "");
        //            }
        //            else
        //            {
        //                createReply(outputMessage, -1, "Mission name is null or empty");
    }
    // ----------------------------------------------------------------------
    catch(GSException& gsExc)
    {
        LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        createReply(outputMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Add Mission Layer response: " + outputMessage.toString());

    return outputMessage;
}


ServerMessage GetPassesMessage::processMessage(const ServerMessage& inMessage)
{
    ServerMessage outputMessage;
    
    LogManager::getInstance().info("Not implemented");

    return outputMessage;
}