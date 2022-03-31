/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

#include "GSException.h"
#include "ConfigurationManager.h"
#include "McsModuleManager.h"

// ******************************************************************
// ******************************************************************
// ******************************************************************



void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       mcs_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    int output = -1;

    cout << "Mission Control System (MCS)" << endl;
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
          // Initialize and load configuration
          McsModuleManager::getInstance().init( argv[1] );

          // Init database

          // Start TC Sender

          // Start TM Receiver


          // Module will be started and stopped by means of the External IF
          McsModuleManager::getInstance().start();

          output = 0;
        } catch(GSException exc)
        {
             cout << "EXCEPTION: " << exc.getErrorMessage() << endl;
        }
    }

    return output;
}

