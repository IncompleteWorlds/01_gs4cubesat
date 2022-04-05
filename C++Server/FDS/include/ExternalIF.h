 /**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 * This class is the entry point of the component.
 * It will be used by other protocol adapters like REST, QPID
 */

#ifndef __EXTERNALIF_H__
#define __EXTERNALIF_H__

#include <string>

using namespace std;


#include "data_model/List_Passes.h"

/**
 * This class defines the external interface of the component
 *
 */
class ExternalIF
{
    public:
        // Singleton
        static ExternalIF& getInstance()
        {
            static ExternalIF instance;

            return instance;
        }
        virtual ~ExternalIF();

        void getPasses(const string &inMission, const string &inSatellite,
                       const string &inGroundStation, const string &inStartTime, const string &inSopTime,
                       IW::List_Passes &outListPasses);

    protected:
        ExternalIF();

    private:
};

#endif // __CEXTERNALIF_H__
