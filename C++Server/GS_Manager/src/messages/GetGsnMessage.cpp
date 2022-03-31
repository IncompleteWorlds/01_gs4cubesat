/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <string>
#include <vector>

using namespace std;


#include "AvroTypes.h"

#include "GSException.h"
#include "GsDatabase.h"
#include "LogManager.h"

#include "MessageUtils.h"

#include "messages/GetGsnMessage.h"



GetGsnMessage::GetGsnMessage()
{
}

GetGsnMessage::~GetGsnMessage()
{
}

// It represents a received Get Ground Station Message
// It shall contain:
// - Station id. Only returns the station identified by its name
// - Station name. Only returns the station identified by its name
// - Station code. Only returns the station identified by its code
// - None. If all criteria are empty or null, it will return all stations
//
// It will reply with a list of ground station or msg_return_data
ServerMessage GetGsnMessage::processMessage(const ServerMessage &inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;
    IW::MsgReturnData      returnData;


    // It has to be a LoginResponse message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_GET_GROUND_STATION) 
    {
        // Extract the AVRO message from body
        IW::MsgGetGroundStation      avroInputMessage;
        IW::ListGroundStations       listGroundStations;
        IW::GroundStation            groundStation;

        try 
        {
            extractMessageVector<IW::MsgGetGroundStation>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // Get GS
            if (avroInputMessage.groundStationCode.empty() == false) 
            {
                groundStation = GsDatabase::getInstance().getById(avroInputMessage.groundStationCode);

                listGroundStations.listGroundStations.push_back(groundStation);
                listGroundStations.numberGroundStations = 1;
            } 
            else 
            {
                if (avroInputMessage.groundStationCode.empty() == false) 
                {
                    groundStation = GsDatabase::getInstance().getByCode(avroInputMessage.groundStationCode);

                    listGroundStations.listGroundStations.push_back(groundStation);
                    listGroundStations.numberGroundStations = 1;
                } 
                else 
                {
                    listGroundStations.listGroundStations = GsDatabase::getInstance().getAll();
                    listGroundStations.numberGroundStations = listGroundStations.listGroundStations.size();
                }
            }
        } catch(GSException& gsExc) 
        {
            returnData.errorCode = gsExc.getErrorCode();
            returnData.errorMessage = gsExc.getErrorMessage();
        }


        // Send return message
        LogManager::getInstance().debug( "Return data: " + toString(returnData) );

        if (returnData.errorCode == 0) {
            std::vector<uint8_t>   tmpAvroMessage;

            tmpAvroMessage = buildMessageVector<IW::ListGroundStations>(listGroundStations);

            outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_GROUND_STATION_RESPONSE);
            outputMessage.setData(tmpAvroMessage);
        } 
        else 
        {
            createReply(outputMessage, returnData);
        }
    } 
    else 
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        LogManager::getInstance().error(errorMessage);

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    return outputMessage;
}
