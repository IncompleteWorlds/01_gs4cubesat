/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __TOOLS_LOGIN_MESSAGE_H__
#define __TOOLS_LOGIN_MESSAGE_H__

#include "BaseMessage.h"
#include "ServerWorker.h"

// It represents a received Login Message
// It shall contain a msg_login (user name, hash password)
// It will reply with a msg_login_response or msg_return_data
class ToolsLoginMessage : public BaseMessage
{
public:
    ToolsLoginMessage();
    ~ToolsLoginMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


protected:

};

#endif // __TOOLS_LOGIN_MESSAGE_H__

