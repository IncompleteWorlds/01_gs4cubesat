/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */


#include <iostream>
#include <ctime>

using namespace std;


#include "M_CModuleManager.h"

// ******************************************************************
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       m_c_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    cout << "Monitor and Control System (M&C)" << endl;
    cout << "(c) 2017-2019 Incomplete Worlds" << endl;
    time_t currentTime = time(nullptr);
    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    cout << endl;

    // Check parameters
    if (argc < 2) 
    {
        cout << "ERROR: Incorrect number of parameters." << endl;

        usage();
    } 
    else 
    {
        // Initialize and load configuration
        M_CModuleManager::getInstance().init( argv[1] );

        // Module will be started and stopped by means of the External IF
        M_CModuleManager::getInstance().start();
    }

    return 0;
}



