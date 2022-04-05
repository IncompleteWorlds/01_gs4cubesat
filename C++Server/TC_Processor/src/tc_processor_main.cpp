/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>

using namespace std;

#include "ConfigurationManager.h"
#include "GSException.h"

// ******************************************************************
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       tc_processor_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    int output = -1;

    cout << "Mission Control System (MCS). TC Processor" << endl;
    cout << "(c) 2017 Incomplete Worlds" << endl;
    cout << endl;

    time_t currentTime = time(nullptr);

    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    cout << endl;

    // Check parameters
    if (argc < 2) {
        cout << "ERROR: Incorrect number of parameters." << endl;
        usage();
    } else {
        try
        {
          // Read the MCS configuration from a JSON config file
          // Throws and exception if an error is found
          ConfigurationManager::getInstance().load( string{argv[1]} );

          // Initialize and load configuration
          //TcModuleManager::getInstance().init();

          // Module will be started and stopped by means of the External IF

          output = 0;
        } catch(GSException exc)
        {
             cout << "EXCEPTION: " << exc.getErrorMessage() << endl;
        }
    }

    return output;
}


