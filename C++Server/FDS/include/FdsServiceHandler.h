/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __FDSSERVICEHANDLER_H_INCLUDED__
#define __FDSSERVICEHANDLER_H_INCLUDED__

#include <thread>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include "ExternalIF.h"
#include "Constants.h"
#include "register_utils.h"

#include "FdsService.h"

using namespace std;

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::IW;
using namespace  ::IWCommon;


class FdsServiceHandler : virtual public FdsServiceIf
{
    public:
        FdsServiceHandler()
        {
            // Register this service
            string tmpPort = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_THRIFT_FDS_PORT);
            int fdsPort = atoi(tmpPort.c_str());

            string fdsUrl = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_THRIFT_FDS_URL);

            // Start a separated thread that register the handler
            // We do not wait for it
            this->registerThread = move( thread{ registerService, FDS_DEFAULT_NAME, fdsUrl, fdsPort } );
        }

        // ---- MODULE OPERATIONS ----------------------------------------
        // ---------------------------------------------------------------
        /**
        * Start the component
        */
        void start()
        {
            // Your implementation goes here
            printf("start\n");
        }

        /**
         * Shutdown the component
         */
        void shutdown()
        {
            // Your implementation goes here
            printf("shutdown\n");
        }

        /**
         * Hearbeat. It indicates whether the component is alive
         * 0 - It is alive
         * -1 - On error
         */
        int32_t heartbeat()
        {
            // Your implementation goes here
            printf("heartbeat\n");
            return 0;
        }

        // ---- FDS OPERATIONS -------------------------------------------
        // ---------------------------------------------------------------

        /**
         * Return the list of passes of a spacecraft over a ground station between
         * start and end times
         * Each pass will contain;
         *
         *
         * missionId - Mission identifier
         * satelliteId - Satellite identifier
         * groundStationId - Ground Station identifier
         * startTime - Start time of time period. Format: YYYY-MM-DDTHH:mm:SS
         * stopTime - Stop time of time period. Format: YYYY-MM-DDTHH:mm:SS
         *
         * @param inToken
         * @param inMissionId
         * @param inSatelliteId
         * @param inGroundStationId
         * @param inStartTime
         * @param inStopTime
         */
        void getPasses(ListPassesType& _return, const std::string& inToken, const std::string& inMissionId,
                       const std::string& inSatelliteId, const std::string& inGroundStationId,
                       const std::string& inStartTime, const std::string& inStopTime)
        {
            cout << "GET PASSES" << endl;

            IW::List_Passes listPasses;

            ExternalIF::getInstance().getPasses(inMissionId, inSatelliteId, inGroundStationId, inStartTime, inStopTime,
                                                listPasses);

        }

private:
        thread  registerThread;
};



#endif // __FDSSERVICEHANDLER_H_INCLUDED__
