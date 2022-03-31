/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
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

/**
 * @brief curl -k -i -X GET -H "Content-Type:application/json" http://<host_ip>:6502/v1/ivmero/api/service/test
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char *argv[])
{
    cout << "Flight Dynamic System (FDS)" << endl;
    cout << "(c) 2019 Incomplete Worlds" << endl;
    time_t currentTime = time(nullptr);
    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    cout << endl;

    // Check parameters
    if (argc < 2) {
        cout << "ERROR: Incorrect number of parameters." << endl;

        usage();
        return 0;
    }

    // Initialize and load configuration
    FdsModuleManager::getInstance().init( argv[1] );

    // Module will be started and stopped by means of the External IF
    FdsModuleManager::getInstance().start();

    return 0;
}
