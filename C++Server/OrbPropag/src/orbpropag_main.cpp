/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

#include "orbpropag_ModuleManager.h"


// ******************************************************************
//         This is an example of a FDS module in C++ 
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       fds_module_main  <filename_and_path>/input_filename.json" << endl;
    cout << endl;
}

/**
 * @brief Perform Orbit Propagation
 * @param argc - 1 parameter. input file
 * @param argv
 * @return 
 */

int main(int argc, char *argv[])
{
    cout << "Flight Dynamic System (FDS) - Orbit Propagator Module" << endl;
    cout << "(c) 2019 Incomplete Worlds" << endl;
    time_t currentTime = time(nullptr);
    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    cout << endl;

    // Check parameters
    if (argc < 2)
    {
        cout << "ERROR: Incorrect number of parameters." << endl;

        usage();
        return 0;
    }
        
    // Initialize and load configuration
    orbpropag_ModuleManager::getInstance().init( argv[1] );

    // Module will be started and stopped by means of the External IF
    orbpropag_ModuleManager::getInstance().start();

    return 0;
}
