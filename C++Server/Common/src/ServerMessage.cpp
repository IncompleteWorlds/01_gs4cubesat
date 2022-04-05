/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <sstream>

using namespace std;


#include "ServerMessage.h"

ServerMessage::ServerMessage()
    : operationCode{OperationCodeEnum::CODE_NONE},
      eventType{EventTypeEnum::EVT_NONE},
      id{0},
      correlationId{0},
      data{}
{
}

ServerMessage::ServerMessage(const ServerMessage& inSecond)
    : operationCode{inSecond.operationCode},
      eventType{inSecond.eventType},
      id{inSecond.id},
      correlationId{inSecond.correlationId},
      data{inSecond.data}
{
}

ServerMessage::ServerMessage(OperationCodeEnum inOperationCode, VectorUint8 inData)
    : operationCode{inOperationCode},
      eventType{EventTypeEnum::EVT_NONE},
      id{0},
      correlationId{0},
      data{inData}
{
}

ServerMessage::~ServerMessage()
{
}

ServerMessage& ServerMessage::operator=(const ServerMessage& inSecond)
{
    if (this != &inSecond)
    {
        this->operationCode = inSecond.operationCode;
        this->eventType = inSecond.eventType;
        this->id  = inSecond.id;
        this->correlationId  = inSecond.correlationId;
        this->data = inSecond.data;

        //cout << "   Operator= Message.body = [" << this->body << "] - [" << inSecond.body << "]" << endl;
    }

    return (*this);
}

void ServerMessage::setOperationCodeAsInt(const int inOperationCode)
{
    operationCode = static_cast<OperationCodeEnum>(inOperationCode);
}

uint32_t ServerMessage::getOperationCodeAsInt() const
{
    return static_cast<int>(operationCode);
}

string ServerMessage::getOperationCodeAsString()
{
    return to_string( getOperationCodeAsInt() );
}

void ServerMessage::setOperationCode(const OperationCodeEnum inOperationCode)
{
    this->operationCode = inOperationCode;
}

OperationCodeEnum ServerMessage::getOperationCode()
{
    return this->operationCode;
}

OperationCodeEnum ServerMessage::getOperationCode() const
{
    return this->operationCode;
}

string ServerMessage::getId()
{
    return this->id;
}

string ServerMessage::getId() const
{
    return this->id;
}

void ServerMessage::setId(const string& inId)
{
    this->id = inId;
}

string ServerMessage::getCorrelationId()
{
    return this->correlationId;
}

string ServerMessage::getCorrelationId() const
{
    return this->correlationId;
}

void ServerMessage::setCorrelationId(const string& inCorrelationId)
{
    this->correlationId = inCorrelationId;
}

VectorUint8 &ServerMessage::getData()
{
    return this->data;
}

uint32_t ServerMessage::getDataSize()
{
    return this->data.size();
}

void ServerMessage::setData(VectorUint8 &inData)
{
    this->data = inData;
}

string ServerMessage::toString()
{
    stringstream ss;

    ss << "Oper code: " << getOperationCodeAsInt()
       << " Event type: " << getEventTypeAsInt()
       << " Message id: " << id
       << " Correl. id: " << correlationId
       << endl;

    char buffer[64];

    cout << "Data: " << endl;
    for(uint32_t i = 0; i < this->data.size(); i ++)
    {
        sprintf(buffer, "%02x ", this->data[i]);
        ss << buffer;
    }
    cout << endl;

    /*
    for(uint32_t i = 0; i < this->body.length(); i ++) {
        char c = (this->body[i] & 0xff);

        if (c >= 0 && c <= 0xF)
        {
            c += '0';
        }
        cout << " " << c;
    }
    cout << endl;
    */

    return ss.str();
}

void ServerMessage::setEventTypeAsInt(const int inEventType)
{
    eventType = static_cast<EventTypeEnum>(inEventType);
}

uint32_t ServerMessage::getEventTypeAsInt() const
{
    return static_cast<int>(eventType);
}

string ServerMessage::getEventTypeAsString()
{
    return to_string( getEventTypeAsInt() );
}

void ServerMessage::setEventType(const EventTypeEnum inEventType)
{
    this->eventType = inEventType;
}

EventTypeEnum ServerMessage::getEventType()
{
    return this->eventType;
}

EventTypeEnum ServerMessage::getEventType() const
{
    return this->eventType;
}

