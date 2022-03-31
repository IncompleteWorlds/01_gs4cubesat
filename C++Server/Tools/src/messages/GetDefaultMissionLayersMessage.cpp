/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include "AvroTypes.h"
#include "GSException.h"
#include "MessageUtils.h"
#include "LogManager.h"
#include "ToolsDatabase.h"

#include "GetDefaultMissionLayersMessage.h"

GetDefaultMissionLayersMessage::GetDefaultMissionLayersMessage()
{
}

GetDefaultMissionLayersMessage::~GetDefaultMissionLayersMessage()
{
}

ServerMessage GetDefaultMissionLayersMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_DEFAULT_MISSION_LAYERS)
    {
        // Extract the AVRO message from body
        IW::MsgGetDefaultMissionLayers      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgGetDefaultMissionLayers>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // TODO: Check authorizatiob token

            // Get Mission layers            
            IW::ListLayers   listLayers;

            listLayers = ToolsDatabase::getInstance().getDefaultMissionLayers();

            // Generate response
            VectorUint8   avroOutputMessage;

            avroOutputMessage = buildMessageVector<IW::ListLayers>(listLayers);

            outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_DEFAULT_MISSION_LAYERS_RESPONSE);
            outputMessage.setData(avroOutputMessage);
            
            // ----------------------------------------------------------------------
        } catch(GSException& gsExc)
        {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
            createReply(outputMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
        }
    }
    else
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        LogManager::getInstance().error(errorMessage);

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Get Mission Layers response: " + outputMessage.toString());

    return outputMessage;
}


