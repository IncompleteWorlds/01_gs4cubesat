/*
 * GetLayerParameters.cpp
 *
 *  Created on: 16 Jun 2017
 *      Author: alberto
 */

#include "GSException.h"
#include "AvroTypes.h"
#include "MessageUtils.h"
#include "ToolsDatabase.h"
#include "LogManager.h"

#include "GetLayerParametersMessage.h"

GetLayerParametersMessage::GetLayerParametersMessage()
{
}

GetLayerParametersMessage::~GetLayerParametersMessage()
{
}

//ServerMessage GetLayerParametersMessage::processMessage(const ServerMessage& inMessage, ServerWorkerZmq& inParent)
ServerMessage GetLayerParametersMessage::processMessage(const ServerMessage& inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_LAYER_PARAMETERS)
    {
        // Extract the AVRO message from body
        IW::MsgGetLayerParameters      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgGetLayerParameters>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // TODO: Check authorizatiob token

            // Get Mission layers
            if (avroInputMessage.layerName.empty() == false)
            {               
                // Get Layer parameters
                IW::ListKeyValues   listParameters;

                listParameters = ToolsDatabase::getInstance().getLayerParameters(avroInputMessage.layerName);

                // Generate response
                VectorUint8   avroOutputMessage;

                avroOutputMessage = buildMessageVector<IW::ListKeyValues>(listParameters);

                outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_LAYER_PARAMETERS_RESPONSE);
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

    LogManager::getInstance().debug("Get Layer Parameters response: " + outputMessage.toString());

    return outputMessage;
}
