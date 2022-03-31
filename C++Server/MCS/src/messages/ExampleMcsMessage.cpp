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

#include "ExampleMcsMessage.h"

using namespace IW;


GetGsnMessage::GetGsnMessage()
{
}

GetGsnMessage::~GetGsnMessage()
{
}

// It represents a received Get Ground Station Message
// Second level message
ServerMessage GetGsnMessage::processMessage(const ServerMessage &inMessage)
{
    // Create first level message
    //---------------------------------------------------------------
    // IW::MsgGetGroundStation  avroMessage;
    // IW::MsgReturnData        returnData;

    // avroMessage.groundStationId = static_cast<int>(OperationCodeEnum::CODE_GET_GROUND_STATION);

    //VectorUint8  avroMessageData{inMessage.getData()};

    //avroMessage.message = inMessage.getData();

    // Send to GS Manager
    //ZeroMQ.send();

    // Wait for answer
    //ZeroMQ.receive();


    // Send return message
    ServerMessage outputMessage;

    //cout << "DEBUG. Return data: " << returnData.errorCode << " " << returnData.errorMessage << endl;

    //if (returnData.errorCode == 0)
    //{
    //    std::vector<uint8_t>   tmpAvroMessage;

//        tmpAvroMessage = buildMessageVector<IW::ListGroundStations>(listGroundStations);

    //    outputMessage.setOperationCode(OperationCodeEnum::CODE_GET_GROUND_STATION_RESPONSE);
    //    outputMessage.setData(tmpAvroMessage);
   // }



   // outputMessage.setCorrelationId(inMessage.getCorrelationId());

    cout << "DEBUG: Login message response: " << outputMessage.toString() << endl;

    return outputMessage;
}

