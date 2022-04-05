/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <string>
#include <iostream>

using namespace std;

#include "AvroTypes.h"

#include "GSException.h"
#include "MessageUtils.h"

#include "GsConnection.h"
#include "GsConnectionManager.h"

#include "messages/ConnectGsnMessage.h"



ConnectGsnMessage::ConnectGsnMessage()
{
}

ConnectGsnMessage::~ConnectGsnMessage()
{
}

ServerMessage ConnectGsnMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;
    IW::MsgReturnData      returnData;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_CONNECT_GROUND_STATION)
    {
        // Extract the AVRO message from body
        IW::MsgConnectGroundStation      avroInputMessage;
        string                           connectionId;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgConnectGroundStation>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            if (avroInputMessage.groundStationId.empty() == false)
            {
                GsConnection::PtrGsConnection conn = GsConnectionManager::getInstance().create(avroInputMessage.groundStationId);

                // Connect and start receiving data
                conn->connect();

                connectionId = conn->getId();
            }
            else
            {
                returnData.errorCode = -1;
                returnData.errorMessage = "Invalid G/S identifier";
            }
            // ----------------------------------------------------------------------
        } catch(GSException& gsExc)
        {
            returnData.errorCode = gsExc.getErrorCode();
            returnData.errorMessage = gsExc.getErrorMessage();
        }


        // Send return message
        cout << "DEBUG: Return data: " << returnData.errorCode << " " << returnData.errorMessage << endl;

        if (returnData.errorCode == 0)
        {
            vector<uint8_t>        tmpAvroMessage;
            IW::ListKeyValues      tmpList;
            IW::KeyValue           tmpValue;

            tmpValue.key = "connectionId";
            tmpValue.value = connectionId;

            tmpList.listKeyValues.push_back(tmpValue);

            tmpAvroMessage = buildMessageVector<IW::ListKeyValues>(tmpList);

            outputMessage.setOperationCode(OperationCodeEnum::CODE_CONNECT_GROUND_STATION_RESPONSE);
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
        cout << "ERROR: " << errorMessage << endl;

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    cout << "DEBUG: Connect Gsn response: " << outputMessage.toString() << endl;

    return outputMessage;
}

