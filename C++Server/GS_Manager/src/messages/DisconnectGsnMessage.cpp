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
#include "messages/DisconnectGsnMessage.h"

DisconnectGsnMessage::DisconnectGsnMessage()
{
}

DisconnectGsnMessage::~DisconnectGsnMessage()
{
}

ServerMessage DisconnectGsnMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    // Create reply message
    ServerMessage          outputMessage;
    IW::MsgReturnData      returnData;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_DISCONNECT_GROUND_STATION)
    {
        // Extract the AVRO message from body
        IW::MsgDisconnectGroundStation      avroInputMessage;
        string                              connectionId;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgDisconnectGroundStation>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            if (avroInputMessage.connectionId != -1)
            {
                GsConnection::PtrGsConnection conn = GsConnectionManager::getInstance().getConnection(avroInputMessage.connectionId);

                // Disconnect from G/S
                conn->disconnect();

                // Release the connection
                GsConnectionManager::getInstance().release(conn);

                // Not needed but ...
                returnData.errorCode    = 0;
                returnData.errorMessage = "";
            }
            else
            {
                // Throw an exception
                string tmpMessage{"Invalid G/S identifier"};

                cout << "ERROR: " << tmpMessage << endl;
                throw GSException(tmpMessage);
            }

            // ----------------------------------------------------------------------
        } catch(GSException& gsExc)
        {
            returnData.errorCode = gsExc.getErrorCode();
            returnData.errorMessage = gsExc.getErrorMessage();
        }


        // Send return message
        cout << "DEBUG: Return data: " << returnData.errorCode << " " << returnData.errorMessage << endl;

        createReply(outputMessage, returnData);
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

