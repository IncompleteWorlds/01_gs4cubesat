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

#include "GetMissionLayersMessage.h"

GetMissionLayersMessage::GetMissionLayersMessage()
{
}

GetMissionLayersMessage::~GetMissionLayersMessage()
{
}

ServerMessage GetMissionLayersMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_MISSION_LAYERS)
    {
        // Extract the AVRO message from body
        IW::MsgGetMissionLayers      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgGetMissionLayers>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // TODO: Check authorizatiob token

            // Get Mission layers
            if (avroInputMessage.missionName.empty() == false)
            {
                IW::ListLayers   listLayers;

                listLayers = ToolsDatabase::getInstance().getMissionLayers( avroInputMessage.missionName );


                // Generate response
                VectorUint8   avroOutputMessage;

                avroOutputMessage = buildMessageVector<IW::ListLayers>(listLayers);

                outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_MISSION_LAYERS_RESPONSE);
                outputMessage.setData(avroOutputMessage);
            }
            else
            {
                createReply(outputMessage, -1, "Mission identifier is null or empty");
            }
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


