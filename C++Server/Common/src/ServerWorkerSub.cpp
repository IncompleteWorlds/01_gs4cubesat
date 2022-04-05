
/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <thread>

using namespace std;

#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

#include "AvroTypes.h"
#include "LogManager.h"

#include "ServerWorkerSub.h"

ServerWorkerSub::ServerWorkerSub(zmq::context_t &ctx, int inSockType, string& inServerName, string& inSubAddress)
    : ServerWorker{ctx, inSockType},
      name_{inServerName},
      address_{inSubAddress}
{
    // IMPORTANT: The address shall NOT include "*". It has to be a 'concrete' address
}

ServerWorkerSub::~ServerWorkerSub()
{
}

void ServerWorkerSub::subscribe(const string &inOptions)
{
    if (inOptions.empty() == false)
    {
        LogManager::getInstance().debug("   Adding subscription options: " + inOptions);
        //cout << "DEBUG:    Adding subscription options: " << inOptions << endl;
        worker_.setsockopt(ZMQ_SUBSCRIBE, inOptions.data(), inOptions.size());
    }
}

void ServerWorkerSub::run()
{
    LogManager::getInstance().debug("    Subscription worker run");
    //cout << "DEBUG:    Subscription worker run" << endl;

    if (address_.empty() == false)
    {
        LogManager::getInstance().debug("    Subscription worker connecting to: " + address_);
        //cout << "DEBUG:    Subscription worker connecting to: " << address_ << endl;

        worker_.connect(address_);

        // Set options. All messages
        worker_.setsockopt(ZMQ_SUBSCRIBE, "", 0);

        internalRun();
    }
    else
    {
        LogManager::getInstance().error("ERROR:  Trying to subscribe to an empty address");
        //cout << "ERROR: Trying to subscribe to an empty address" << endl;
    }
}

