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

#include "messages/RemoveSatelliteMessage.h"



RemoveSatelliteMessage::RemoveSatelliteMessage()
{
}

RemoveSatelliteMessage::~RemoveSatelliteMessage()
{
}

ServerMessage RemoveSatelliteMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_DELETE_SATELLITE)
    {
        // Extract the AVRO message from body
        IW::MsgRemoveSatellite      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgRemoveSatellite>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            LogManager::getInstance().debug("Remove satellite: " + avroInputMessage.satelliteName);

            // Get Satellite
            if (avroInputMessage.satelliteName.empty() == false &&
                avroInputMessage.missionName.empty() == false)
            {
                ToolsDatabase::getInstance().removeSatellite(avroInputMessage.satelliteName);
                
                createReply(outputMessage, 0, "Satellite correctly removed");                
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

    LogManager::getInstance().debug("Remove Satellite response: " + outputMessage.toString());

    return outputMessage;
}

