/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */


#include <iostream>
#include <ctime>

using namespace std;

#include "FdsModuleManager.h"


// ******************************************************************
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       fds_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    int output = -1;

    cout << "Flight Dynamic System (FDS)" << endl;
    cout << "(c) 2016 Incomplete Worlds" << endl;
    time_t currentTime = time(nullptr);
    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    cout << endl;

    // Check parameters
    if (argc < 2) {
        cout << "ERROR: Incorrect number of parameters." << endl;

        usage();
        output=0;
    } else {
        // Initialize and load configuration
        FdsModuleManager::getInstance().init( argv[1] );

        // Module will be started and stopped by means of the External IF

        output = 0;
    }

    return output;
}




