/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

#include "LayersTmDecoderModuleManager.h"


// ******************************************************************
//         TM Decoder based on Layers
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       LayersTmDecoder  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

/**
 * @brief TM Decoder based on Layers
 * It decodes a Raw Frame applying successive defined layers of protocols
 * I.e.
 * Layer 2 - Application
 * Layer 1 - CSP
 * Layer 0 - Ax.25
 * 
 * @param argc - 1 parameter. configuration input file
 * @param argv
 * @return 
 */

int main(int argc, char *argv[])
{
    cout << "Mission Control System (MCS) - Layers Tm Decoder" << endl;
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
    LayersTmDecoderModuleManager::getInstance().init( argv[1] );

    // Module will be started and stopped by means of the External IF
    LayersTmDecoderModuleManager::getInstance().start();

    return 0;
}
