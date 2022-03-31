/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include "orbpropag_ModuleManager.h"
#include <stdio.h>

extern "C" 
{

    void send_message_c(int inCode, char* inMessage, char* outMessage)
    {
        printf("DEBUG: InMessage = %s\n", inMessage);

        orbpropag_ModuleManager::getInstance().sendFdsMessage(inCode, inMessage, outMessage);
        return;
    }

    void receive_message_c(char* outMessage)
    {
        //    if (outMessage != NULL)
        //    {
        //        // Size is below the frame size of TCP/IP
        //        char buffer[1024];
        //
        //        orbpropag_ModuleManager::getInstance().receiveFdsMessage(buffer);
        //
        //        printf("DEBUG: Received message = %s\n", buffer);
        //        // Copy to the output buffer
        //        strncpy(outMessage, buffer, 1024);
        //    }
        //
        return;
    }
    
    int get_parameter_c(const char* inKey, int inLen, char* outValue)
    {
        return orbpropag_ModuleManager::getInstance().getParameter(inKey, inLen, outValue);
    }
    
    int set_parameter_c(const char* inKey, char* inValue)
    {
        return orbpropag_ModuleManager::getInstance().setParameter(inKey, inValue);
    }

    void return_c(int inReturnCode, char* inErrorMessage)
    {
        orbpropag_ModuleManager::getInstance().setFortranReturnCode(inReturnCode, inErrorMessage);
        return;
    }

    // This is a test
    void print_c(char* inMessage)
    {
        if(inMessage != NULL)
            printf("%s\n", inMessage);

        return;
    }

}