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
    : operationCode_{OperationCodeEnum::CODE_NONE},
      eventType_{EventTypeEnum::EVT_NONE},
      id_{0},
      correlationId_{0},
      data_{}
{
}

ServerMessage::ServerMessage(const ServerMessage& inSecond)
    : operationCode_{inSecond.operationCode_},
      eventType_{inSecond.eventType_},
      id_{inSecond.id_},
      correlationId_{inSecond.correlationId_},
      data_{inSecond.data_}
{
}

ServerMessage::ServerMessage(OperationCodeEnum inOperationCode, VectorUint8 inData)
    : operationCode_{inOperationCode},
     eventType_{EventTypeEnum::EVT_NONE},
     id_{0},
     correlationId_{0},
     data_{inData}
{
}

ServerMessage::~ServerMessage()
{
}

ServerMessage& ServerMessage::operator=(const ServerMessage& inSecond)
{
    if (this != &inSecond)
    {
        this->operationCode_ = inSecond.operationCode_;
        this->eventType_ = inSecond.eventType_;
        this->id_  = inSecond.id_;
        this->correlationId_  = inSecond.correlationId_;
        this->data_ = inSecond.data_;
        this->authorizationToken_ = inSecond.authorizationToken_;

        //cout << "   Operator= Message.body = [" << this->body << "] - [" << inSecond.body << "]" << endl;
    }

    return (*this);
}

void ServerMessage::setOperationCodeAsInt(const int inOperationCode)
{
    this->operationCode_ = static_cast<OperationCodeEnum>(inOperationCode);
}

uint32_t ServerMessage::getOperationCodeAsInt() const
{
    return static_cast<int>(this->operationCode_);
}

string ServerMessage::getOperationCodeAsString()
{
    return to_string( getOperationCodeAsInt() );
}

void ServerMessage::setOperationCodeAsString(const string &inCode)
{
    if (inCode.empty() == true)
        return;
        
    int tmpCode{ std::stoi(inCode) };
    setOperationCodeAsInt( tmpCode );
}

void ServerMessage::setOperationCode(const OperationCodeEnum inOperationCode)
{
    this->operationCode_ = inOperationCode;
}

OperationCodeEnum ServerMessage::getOperationCode()
{
    return this->operationCode_;
}

OperationCodeEnum ServerMessage::getOperationCode() const
{
    return this->operationCode_;
}

string ServerMessage::getId()
{
    return this->id_;
}

string ServerMessage::getId() const
{
    return this->id_;
}

void ServerMessage::setId(const string& inId)
{
    this->id_ = inId;
}

string ServerMessage::getCorrelationId()
{
    return this->correlationId_;
}

string ServerMessage::getCorrelationId() const
{
    return this->correlationId_;
}

void ServerMessage::setCorrelationId(const string& inCorrelationId)
{
    this->correlationId_ = inCorrelationId;
}

VectorUint8 &ServerMessage::getData()
{
    return this->data_;
}

uint32_t ServerMessage::getDataSize()
{
    return this->data_.size();
}

void ServerMessage::setData(VectorUint8 &inData)
{
    this->data_ = inData;
}

string ServerMessage::toStringShort()
{
    stringstream ss;

    ss << "Code: " << getOperationCodeAsInt()
       << " Ev type: " << getEventTypeAsInt()
       << " Msg id: " << id_
       << " Corr id: " << correlationId_;
       
    return ss.str();
}

string ServerMessage::toString()
{
    stringstream ss;

    ss << "Oper code: " << getOperationCodeAsInt()
       << " Event type: " << getEventTypeAsInt()
       << " Message id: " << id_
       << " Correl. id: " << correlationId_
       << " Data: " << vectorToHexString(data_);

    return ss.str();
    
    /*
    char buffer[64];

    cout << "Data: " << endl;
    for(uint32_t i = 0; i < this->data_.size(); i ++)
    {
        sprintf(buffer, "%02x ", this->data_[i]);
        ss << buffer;
    }
    cout << endl;
     */

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

}

void ServerMessage::setEventTypeAsInt(const int inEventType)
{
    eventType_ = static_cast<EventTypeEnum>(inEventType);
}

uint32_t ServerMessage::getEventTypeAsInt() const
{
    return static_cast<int>(eventType_);
}

string ServerMessage::getEventTypeAsString()
{
    return to_string( getEventTypeAsInt() );
}

void ServerMessage::setEventType(const EventTypeEnum inEventType)
{
    this->eventType_ = inEventType;
}

EventTypeEnum ServerMessage::getEventType()
{
    return this->eventType_;
}

EventTypeEnum ServerMessage::getEventType() const
{
    return this->eventType_;
}

void ServerMessage::setAuthorizationToken(const string& inAuthToken)
{
    this->authorizationToken_ = inAuthToken;
}

string ServerMessage::getAuthorizationToken()
{
    return this->authorizationToken_;
}

string ServerMessage::getAuthorizationToken() const
{
    return this->authorizationToken_;
}

string ServerMessage::getCodeAndAuthToken()
{
    string output = this->getOperationCodeAsString() + "." + this->authorizationToken_;
    
    return output;
}

void ServerMessage::extractCodeAndAuthToken(const string &inBuffer)
{
    if (inBuffer.empty() == true)
        return;
        
    std::size_t i = inBuffer.find('.');
    
    if (i != string::npos)
    {
        string msgCode = inBuffer.substr(0, i);
        
        setOperationCodeAsString(msgCode);
        
        this->authorizationToken_ = inBuffer.substr(i+1);
    }
}