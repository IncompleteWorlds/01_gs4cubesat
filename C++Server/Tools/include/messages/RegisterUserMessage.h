/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __TOOLS_REGISTER_USER_MESSAGE_H__
#define __TOOLS_REGISTER_USER_MESSAGE_H__

#include "BaseMessage.h"

class RegisterUserMessage : public BaseMessage
{
public:
    RegisterUserMessage();
    ~RegisterUserMessage();

    //ServerMessage processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent);
    ServerMessage processMessage(const ServerMessage &inMessage);

protected:

};

#endif // __TOOLS_REGISTER_USER_MESSAGE_H__

