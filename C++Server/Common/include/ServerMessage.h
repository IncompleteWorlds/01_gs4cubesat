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

        // Getter and Setter
        void setOperationCode(const OperationCodeEnum inOperationCode);

        OperationCodeEnum getOperationCode();

        OperationCodeEnum getOperationCode() const;

        void setOperationCodeAsInt(const int inOperationCode);

        uint32_t getOperationCodeAsInt() const;

        string getOperationCodeAsString();
        
        void setOperationCodeAsString(const string &inCode);

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
        
        void setAuthorizationToken(const string &inAuthToken);

        string getAuthorizationToken();

        string getAuthorizationToken() const;
        
        // MsgCode + Authorization Token
        string getCodeAndAuthToken();
        void extractCodeAndAuthToken(const string &inBuffer);



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
        
        // It contains onlye the header
        string toStringShort();


    private:
        // IDEA: FIX ME
        // Add the timestamp to the message
        // // Get timestamp (if GS_Manager does not have it)
        // unsigned long currentTime = TimeUtils::getCurrentTimeMilliseconds();
    
        // Id and Correlation id_ must be string
        // If using JMS, JMS Provider will assign 
        OperationCodeEnum  operationCode_;
        EventTypeEnum      eventType_;
        string             id_;
        string             correlationId_;
        string             authorizationToken_;
        VectorUint8        data_;
};

#endif // __SERVER_MESSAGE_H_INCLUDED__
