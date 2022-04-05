/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "MessageUtils.h"

#include "ToolsDatabase.h"
#include "GSException.h"
#include "LogManager.h"

#include "GetFrameTypesMessage.h"

GetFrameTypesMessage::GetFrameTypesMessage()
{
}

GetFrameTypesMessage::~GetFrameTypesMessage()
{
}

ServerMessage GetFrameTypesMessage::processMessage(const ServerMessage& inMessage, ServerWorker& inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_LAYER_FRAME_TYPES)
    {
        // Extract the AVRO message from body
        IW::MsgGetFrameTypes     avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgGetFrameTypes>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // TODO: Check authorizatiob token

            // Get Frame Types of a layer
            if (avroInputMessage.layerName.empty() == false)
            {               
                // Get Frame Types
                IW::ListFrameTypes   listFrames;

                listFrames = ToolsDatabase::getInstance().getFrameTypesByLayer(avroInputMessage.layerName);

                // Generate response
                VectorUint8   avroOutputMessage;

                avroOutputMessage = buildMessageVector<IW::ListFrameTypes>(listFrames);

                outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_LAYER_FRAME_TYPES_RESPONSE);
                outputMessage.setData(avroOutputMessage);
            }
            else
            {
                createReply(outputMessage, -1, "Layer name is null or empty");
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

    LogManager::getInstance().debug("Get Frame Types response: " + outputMessage.toString());

    return outputMessage;
}
