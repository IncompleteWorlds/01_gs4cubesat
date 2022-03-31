/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include <iostream>
//#include <thread>

using namespace std;

#include "GSException.h"
//#include "ConfigurationManager.h"

//#include "IMessageProcessor.h"
#include "MessageUtils.h"
#include "LogManager.h"

#include "ServerMessage.h"
#include "ServerWorkerTransferNng.h"

// It is assumed that both sockets are already opened
ServerWorkerTransferNng::ServerWorkerTransferNng(nng::socket& inInput, nng::socket& inOutput)
    : inputSocket_{}, outputSocket_{}, done_{false}
{
    this->inputSocket_.reset(&inInput);
    this->outputSocket_.reset(&inOutput);
}

ServerWorkerTransferNng::~ServerWorkerTransferNng()
{
}

void ServerWorkerTransferNng::run()
{   
    ServerMessage  outputMessage;

    while(done_ == false) 
    {
        try 
        {
            ServerMessage   newMessage;
            
            ::receiveMessage(*this->inputSocket_, newMessage);

            // Send the message to the destination
            ::sendMessage(*this->outputSocket_, newMessage);
            
            // Receive the answer from the destination
            ::receiveMessage(*this->outputSocket_, outputMessage);            
        }
        catch(GSException& gsException) 
        {
            string exceptionMessage = "ERROR: GS Exception in ServerWorkerTransfer::run: " + gsException.getErrorMessage();

            // Create error message. MsgReturnData
            ::createReply(outputMessage, gsException.getErrorCode(), gsException.getErrorMessage());

            LogManager::getInstance().error(exceptionMessage);
        } 
        catch(std::exception& e) 
        {
            string exceptionMessage = "ERROR: Exception in ServerWorkerTransfer::run: " + string{ e.what() };

            ::createReply(outputMessage, -1, exceptionMessage);

            // FIX ME: It generates an error when the parent application exists
            // Maybe, it is due to thread interaction
            LogManager::getInstance().error(exceptionMessage);
        }

        // Send answer back to the originator
        ::sendMessage(*this->inputSocket_, outputMessage);
    }
}
