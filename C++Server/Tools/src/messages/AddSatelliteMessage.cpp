/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2018 Incomplete Worlds
 *
 */

#include <string>
#include <iostream>

using namespace std;

#include "AvroTypes.h"

#include "ToolsDatabase.h"
#include "GSException.h"
#include "LogManager.h"
#include "MessageUtils.h"

#include "messages/AddSatelliteMessage.h"



AddSatelliteMessage::AddSatelliteMessage()
{
}

AddSatelliteMessage::~AddSatelliteMessage()
{
}

//ServerMessage AddSatelliteMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq &inParent)
ServerMessage AddSatelliteMessage::processMessage(const ServerMessage &inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_ADD_SATELLITE)
    {
        // Extract the AVRO message from body
        IW::MsgAddSatellite      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgAddSatellite>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);


            // Get Satellite
            if (avroInputMessage.satellite.name.empty() == false &&
                avroInputMessage.missionName.empty() == false)
            {
                IW::Satellite  theSatellite;
                int64_t        satelliteId;

                satelliteId = ToolsDatabase::getInstance().createSatellite(avroInputMessage.satellite);
                
                theSatellite = avroInputMessage.satellite;
                //theSatellite.identifier = static_cast<int32_t>(SatelliteId);

                // Generate response
                std::vector<uint8_t>   avroOutputMessage;

                avroOutputMessage = buildMessageVector<IW::Satellite>(theSatellite);

                outputMessage.setOperationCode(OperationCodeEnum::CODE_ADD_SATELLITE_RESPONSE);
                outputMessage.setData(avroOutputMessage);
            }
            else
            {
                createReply(outputMessage, -1, "Satellite name is null or empty");
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

    LogManager::getInstance().debug("Add Satellite response: " + outputMessage.toString());

    return outputMessage;
}

