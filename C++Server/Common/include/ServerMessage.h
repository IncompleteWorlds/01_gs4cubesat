/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __SERVER_MESSAGE_H_INCLUDED__
#define __SERVER_MESSAGE_H_INCLUDED__

#include <string>
#include <vector>

using namespace std;

#include "CommonTypes.h"
#include "OperationCodeEnum.h"
#include "EventTypeEnum.h"


class ServerMessage
{
    public:
        ServerMessage();
        ServerMessage(const ServerMessage& inSecond);

        ServerMessage& operator=(const ServerMessage& inSecond);

        ~ServerMessage();

        ServerMessage(OperationCodeEnum inOperationCode, VectorUint8 inData);

        void setOperationCode(const OperationCodeEnum inOperationCode);

        OperationCodeEnum getOperationCode();

        OperationCodeEnum getOperationCode() const;

        void setOperationCodeAsInt(const int inOperationCode);

        uint32_t getOperationCodeAsInt() const;

        string getOperationCodeAsString();

        string getId();

        string getId() const;

        void setId(const string &inId);

        string getCorrelationId();

        string getCorrelationId() const;

        void setCorrelationId(const string &inCorrelationId);

        VectorUint8 &getData();

        uint32_t getDataSize();

        void setData(VectorUint8& inData);

        void setEventType(const EventTypeEnum inEventType);

        void setEventTypeAsInt(const int inEventType);

        EventTypeEnum getEventType();

        EventTypeEnum getEventType() const;

        uint32_t getEventTypeAsInt() const;

        string getEventTypeAsString();




        /*
        Messages
        ========
        SUBJECT        = Message type. I.e. LOGIN, LOGOUT, START UP
        TYPE           = Message type
        ID             = Message identifier
        CORRELATION_ID = Identifier of the message to which this is related to
        TO             = Name of queue or exchange
        REPLY_TO       =
        BODY           = Message encoded in AVRO
        */

        string toString();


    private:
        // Id and Correlation id must be string and assigned by JMS Provider
        OperationCodeEnum  operationCode;
        EventTypeEnum      eventType;
        string             id;
        string             correlationId;
        VectorUint8        data;
};

#endif // __SERVER_MESSAGE_H_INCLUDED__
