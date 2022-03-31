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

#include "messages/AddGsnMessage.h"



AddGsnMessage::AddGsnMessage()
{
}

AddGsnMessage::~AddGsnMessage()
{
}

/**
 * @class AddGsnMessage
 * @author Alberto
 * @date 11/11/17
 * @file AddGsnMessage.h
 * @brief It represents a received Add Ground Station Message
 * See msg_add_ground_station.json for a description of the contents
 * It will reply with a Ground Station object
 */
ServerMessage AddGsnMessage::processMessage(const ServerMessage &inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;
    IW::MsgReturnData      returnData;


    // It has to be a LoginResponse message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_ADD_GROUND_STATION) 
    {
        IW::MsgAddGroundStation      avroInputMessage;
        IW::GroundStation            groundStation;

        try 
        {
            // Extract the AVRO message from body
            extractMessageVector<IW::MsgAddGroundStation>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // Add the G/S to the DB
            string newStationId{""};
            
            newStationId = GsDatabase::getInstance().create(avroInputMessage.groundStation);
            
            // Set the id
            avroInputMessage.groundStation.identifier = std::atoi(newStationId.c_str());

        } catch(GSException& gsExc) 
        {
            returnData.errorCode = gsExc.getErrorCode();
            returnData.errorMessage = gsExc.getErrorMessage();
        }

        // Send return message
        LogManager::getInstance().debug( "Return data: " + toString(returnData) );

        if (returnData.errorCode == 0) 
        {
            std::vector<uint8_t>   tmpAvroMessage;

            tmpAvroMessage = buildMessageVector<IW::GroundStation>(groundStation);

            outputMessage.setOperationCode(OperationCodeEnum::CODE_ADD_GROUND_STATION_RESPONSE);
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
