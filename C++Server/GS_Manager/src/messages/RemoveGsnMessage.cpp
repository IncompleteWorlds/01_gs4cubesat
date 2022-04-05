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

#include "MessageUtils.h"

#include "messages/RemoveGsnMessage.h"

using namespace IW;


RemoveGsnMessage::RemoveGsnMessage()
{
}

RemoveGsnMessage::~RemoveGsnMessage()
{
}

/**
 * @class RemoveGsnMessage
 * @author Alberto
 * @date 11/11/17
 * @file RemoveGsnMessage.h
 * @brief It represents a received Delete Ground Station Message
 * See msg_remove_ground_station.json for a description of the contents
 * It will reply with a return code
 */

ServerMessage RemoveGsnMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;
    IW::MsgReturnData      returnData;

    // It has to be a LoginResponse message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_REMOVE_GROUND_STATION) {
        IW::MsgRemoveGroundStation    avroInputMessage;
        IW::GroundStation             groundStation;

        try {
            // Extract the AVRO message from body
            extractMessageVector<IW::MsgRemoveGroundStation>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            // Remove the G/S to the DB           
            GsDatabase::getInstance().remove(avroInputMessage.groundStationName);
        } catch(GSException& gsExc) {
            returnData.errorCode = gsExc.getErrorCode();
            returnData.errorMessage = gsExc.getErrorMessage();
        }

        // Send return message
        cout << "DEBUG. Return data: " << returnData.errorCode << " " << returnData.errorMessage << endl;

        createReply(outputMessage, returnData);
    } else {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        cout << "ERROR: " << errorMessage << endl;

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    return outputMessage;
}
