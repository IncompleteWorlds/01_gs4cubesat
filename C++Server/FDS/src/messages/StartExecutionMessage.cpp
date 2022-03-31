/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

#include <string>
#include <iostream>

using namespace std;

#include "AvroTypes.h"

#include "GSException.h"
#include "LogManager.h"
#include "MessageUtils.h"

#include "FdsDatabase.h"

#include "messages/StartExecutionMessage.h"

StartExecutionMessage::StartExecutionMessage()
{
}

StartExecutionMessage::~StartExecutionMessage()
{
}

ServerMessage StartExecutionMessage::processMessage(const ServerMessage& inMessage, ServerWorkerZmq& inParent)
{
    // Create reply message
    ServerMessage outputMessage;

    LogManager::getInstance().warning("Not implemented");

    return outputMessage;
}

ServerMessage StartExecutionMessage::processMessage(const ServerMessage& inMessage)
{
    // Create reply message
    ServerMessage outputMessage;

    // Extract the AVRO message from body
    IW::MsgStartModuleExecution avroInputMessage;

    try
    {
        // ----------------------------------------------------------------------
        extractMessageVector<IW::MsgStartModuleExecution>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);
        
        // TODO: Check Authorization

        // Look for the Module by name
        IW::FdsModule moduleData = FdsDatabase::getInstance().getModuleByName(avroInputMessage.module_name);
    
        if (moduleData.type == IW::ModuleTypeEnum::EXTERNAL_MODULE)
        {
            outputMessage = runExternalModule(moduleData);
        }
        else
        {
            outputMessage = runInternalModule(moduleData);
        }
        
        // Record the process id, client id, start time
    /*
     * FdsDatabase::getInstance().addStartExecution();
     */
    }
    // ----------------------------------------------------------------------
    catch(GSException& gsExc)
    {
        LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        createReply(outputMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Start Execution response: " + outputMessage.toString());

    return outputMessage;
}


ServerMessage StartExecutionMessage::runExternalModule(IW::FdsModule &inModule)
{
    ServerMessage outputMessage;
    
    LogManager::getInstance().info("Start execution of external module: " + inModule.name);
    
    // Spawn a process
    string   cmd{ inModule.binary_file + " " + "resources/input.json" };
    pid_t pid;
    const char *pCmd = cmd.c_str();
    //const char *pCmd = "FIX ME";
    const char* argv[] = { "sh", "-c", pCmd, NULL };
    //extern char** environ;
    char **environ;

    // Where to run the binary
    
    // Where to store the input files
    
    
    LogManager::getInstance().info("    Run command: " + cmd);
    int status;

    const char *pBinaryFile = inModule.binary_file.c_str();
    //status = posix_spawn(&pid, pBinaryFile, NULL, NULL, argv, environ);
    
    if(status != 0) 
    {
        string errorMessage = "Posix_spawn error: " + string(strerror(status));
        
        LogManager::getInstance().error(errorMessage) ;
        ::createReply(outputMessage, -1, errorMessage);
        
        return outputMessage;
    }
    
    LogManager::getInstance().info("    Module pid: " + to_string(pid) );

    ::createReply(outputMessage, 0, "");
    return outputMessage;
}

ServerMessage StartExecutionMessage::runInternalModule(IW::FdsModule &inModule)
{
    ServerMessage outputMessage;
    
    // Invoke internal method
    switch(inModule.identifier)
    {
        case 1:
            // It should run asynchronously.
            // It shall report the final status in the same was as an external module 
            // class->method1();
            break;
            
        default:
            string errorMessage = "Unknwon module identifier: " + to_string(inModule.identifier);
        
            LogManager::getInstance().error(errorMessage) ;
            ::createReply(outputMessage, -1, errorMessage);        
            break;
    }
    
    ::createReply(outputMessage, 0, "");
    return outputMessage;
}