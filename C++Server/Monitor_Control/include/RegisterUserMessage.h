/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __REGISTER_USER_MESSAGE_H__
#define __REGISTER_USER_MESSAGE_H__

#include "BaseMessage.h"

// It represents a received Login Message
// It shall contain a msg_login (user name, hash password)
// It will reply with a msg_login_response or msg_return_data
class RegisterUserMessage : public BaseMessage
{
public:
    RegisterUserMessage();
    ~RegisterUserMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);


protected:

};

#endif // __REGISTER_USER_MESSAGE_H__

