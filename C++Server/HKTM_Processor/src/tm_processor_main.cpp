/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

#include "GSException.h"
#include "ConfigurationManager.h"
#include "HkTmProcessorModuleManager.h"



// ******************************************************************
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       tm_processor_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    cout << "Mission Control System (MCS). HK TM Processor" << endl;
    cout << "(c) 2019 Incomplete Worlds" << endl;
    cout << endl;

    time_t currentTime = time(nullptr);

    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    //strftime()
    cout << endl;

    // Check parameters
    if (argc < 2) 
    {
        cout << "ERROR: Incorrect number of parameters." << endl;
        usage();
        return 0;
    } 

    // Initialize and load configuration
    HkTmProcessorModuleManager::getInstance().init( string{argv[1]} );

    // Module will be started and stopped by means of the External IF
    HkTmProcessorModuleManager::getInstance().start();

    return 0;
}


