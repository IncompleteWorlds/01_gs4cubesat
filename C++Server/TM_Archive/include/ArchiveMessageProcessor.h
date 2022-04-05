/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __ARCHIVE_MESSAGEPROCESSOR_H__
#define __ARCHIVE_MESSAGEPROCESSOR_H__

#include "ServerWorker.h"
#include "ServerMessage.h"
#include "BaseMessage.h"


class ArchiveMessageProcessor : public BaseMessage
{
    public:
        ArchiveMessageProcessor();
        virtual ~ArchiveMessageProcessor();

        ServerMessage processMessage(const ServerMessage &inMessage, ServerWorker& inParent);


    protected:


    private:
};

#endif // __ARCHIVE_MESSAGEPROCESSOR_H__


