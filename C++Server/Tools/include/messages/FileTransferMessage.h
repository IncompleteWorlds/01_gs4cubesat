/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __FILE_TRANSFER_MESSAGE__
#define __FILE_TRANSFER_MESSAGE__

#include "BaseMessage.h"


class FileTransferMessage : public BaseMessage
{
public:
    FileTransferMessage();
    virtual ~FileTransferMessage();

    ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);
    
};

#endif // __FILE_TRANSFER_MESSAGE__
