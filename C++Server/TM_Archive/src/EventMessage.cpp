/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "AvroTypes.h"

#include "OperationCodeEnum.h"
#include "MessageUtils.h"
#include "ArchiveDatabase.h"

#include "EventMessage.h"


EventMessage::EventMessage()
{
}

EventMessage::~EventMessage()
{
}

ServerMessage EventMessage::processMessage(const ServerMessage &inMessage, ServerWorker &inParent)
{
    ServerMessage        outputMessage;
    IW::MsgReturnData    outputData;

    // It has to be a PublishEvent message
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_PUBLISH_EVENT)
    {
        // Extract the AVRO message from body
        IW::MsgPublishEvent avroInputMessage;

        extractMessageVector<IW::MsgPublishEvent>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

        // TODO: Check Authorization Token

        // Process the event. Store it in the DB
        ArchiveDatabase::getInstance().create(avroInputMessage.event);

    }
    else
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        cout << "ERROR: " << errorMessage << endl;
    }

    // Response: no error
    createReply(outputMessage, 0, "");
    
    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    cout << "DEBUG: Login message response: " << outputMessage.toString() << endl;

    return outputMessage;
}

