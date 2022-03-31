/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "LogManager.h"
#include "FileTransferMessage.h"

FileTransferMessage::FileTransferMessage()
{
}

FileTransferMessage::~FileTransferMessage()
{
}

//ServerMessage FileTransferMessage::processMessage(const ServerMessage &inMessage, ServerWorkerZmq& inParent)
ServerMessage FileTransferMessage::processMessage(const ServerMessage &inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;


    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("File Transfer message: " + outputMessage.toString());

    return outputMessage;    
}