/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include <iostream>
#include <ctime>

using namespace std;


#include "ToolsModuleManager.h"


// ******************************************************************
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       tools_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    cout << "Tools" << endl;
    cout << "(c) 2019 Incomplete Worlds" << endl;
    
    time_t currentTime = time(nullptr);
    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    cout << endl;

    // Test
    //writeData();

    // Check parameters
    if (argc < 2) 
    {
        cout << "ERROR: Incorrect number of parameters." << endl;

        usage();
    } 
    else 
    {
        // Initialize and load configuration
        ToolsModuleManager::getInstance().init( argv[1] );

        // Module will be started and stopped by means of the External IF
        ToolsModuleManager::getInstance().start();
    }

    return 0;
}


