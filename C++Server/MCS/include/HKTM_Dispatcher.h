/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __HKTM_DISPATCHER_H__
#define __HKTM_DISPATCHER_H__

#include <array>

using namespace std;

#include "CommonTypes.h"


class HKTM_Dispatcher
{
    public:
        // Singleton
        static HKTM_Dispatcher& getInstance()
        {
            static HKTM_Dispatcher instance;

            return instance;
        }
        virtual ~HKTM_Dispatcher();

        void addRawFrame(const RawFrameType& inFrame);

        void addProcessedFrame(const RawFrameType& inFrame);


        // NOTE: Subscription and unsubscription is done by means of
        // ZeroMQ sockets


    protected:
        HKTM_Dispatcher();

    private:
};

#endif // __HKTM_DISPATCHER_H__
