/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "ToolsDatabase.h"
#include "LogManager.h"
#include "GSException.h"
#include "MessageUtils.h"

#include "messages/GetSatelliteMessage.h"

GetSatelliteMessage::GetSatelliteMessage()
{

}

GetSatelliteMessage::~GetSatelliteMessage()
{

}

//ServerMessage GetSatelliteMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent)
ServerMessage GetSatelliteMessage::processMessage(const ServerMessage &inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_SATELLITE)
    {
        // Extract the AVRO message from body
        IW::MsgGetSatellite      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgGetSatellite>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            LogManager::getInstance().debug("Reading satellites for mission: " + avroInputMessage.missionName);
            
            // Get Mission
            if (avroInputMessage.missionName.empty() == false)
            {
                IW::ListSatellites   listSatellite;
                bool                 errorFlag = false;

                if (avroInputMessage.satelliteName.empty() == false)
                {
                    IW::Satellite aSatellite = ToolsDatabase::getInstance().getSatelliteByName(avroInputMessage.missionName, 
                                                                                         avroInputMessage.satelliteName);
                    listSatellite.listSatellites.push_back(aSatellite);
                }
                else
                {
                    if (avroInputMessage.satelliteCode.empty() == false)
                    {
                        IW::Satellite aSatellite = ToolsDatabase::getInstance().getSatelliteByCode(avroInputMessage.missionName, 
                                                                                                   avroInputMessage.satelliteCode);
                        listSatellite.listSatellites.push_back(aSatellite);
                    }
                    else
                    {
                        // If no code or name is used, it will return all satellites of the mission
                        listSatellite.listSatellites = ToolsDatabase::getInstance().getSatellites(avroInputMessage.missionName);
                    }
                }

                if (errorFlag == false)
                {
                    // Generate response
                    std::vector<uint8_t>   avroOutputMessage;

                    avroOutputMessage = buildMessageVector<IW::ListSatellites>(listSatellite);

                    outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_SATELLITE_RESPONSE);
                    outputMessage.setData(avroOutputMessage);
                }
            }
            else
            {
                createReply(outputMessage, -1, "Mission name is null or empty");
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

    LogManager::getInstance().debug("Get Satellite response: " + outputMessage.toString());

    return outputMessage;
}
