/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include <ctime>
#include <iostream>

using namespace std;

#include "ConfigurationManager.h"
#include "GsModuleManager.h"

// ******************************************************************
// ******************************************************************
// ******************************************************************

void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       gs_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char* argv[])
{
    cout << "Ground Stations Manager" << endl;
    cout << "(c) 2019 Incomplete Worlds" << endl;
    cout << endl;

    time_t currentTime = time(nullptr);
    cout << "Date: " << asctime(gmtime(&currentTime)) << endl;
    cout << endl;

    // Check parameters
    if(argc < 2) 
    {
        cout << "ERROR: Incorrect number of parameters." << endl;
        usage();
    }
    else
    {
        // Initialize and load configuration
        GsModuleManager::getInstance().init(argv[1]);

        // Module will be started and stopped by means of the External IF
        GsModuleManager::getInstance().start();
    }
    return 0;
}
