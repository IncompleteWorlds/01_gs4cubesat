/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <thread>
#include <future>

using namespace std;

#include "AvroTypes.h"

#include "GSException.h"
#include "GsTcpConnection.h"
#include "GsDatabase.h"
#include "GsConnectionManager.h"


GsConnectionManager::GsConnectionManager()
    : nextId{0}, activeConnections{}
{
    // Run io_service.run() in its own thread
    // We do not care about the result
    //std::future<void>  result = std::async(std::launch::async, std::bind(&GsConnectionManager::runIoService, this));

    //std::thread ioServiceThread(std::bind(&GsConnectionManager::runIoService, this));

    //ioServiceThread.detach();
}

GsConnectionManager::~GsConnectionManager()
{
    // Emtpy the queue
    // io_service should stop itself
    //io_service.reset();
}

GsConnection::PtrGsConnection GsConnectionManager::create(const string &inGsId)
{
    GsConnection::PtrGsConnection output = nullptr;

    // Get next connection Id
    this->nextId ++;
    string tmpId = to_string(this->nextId);

    // Read G/S parameters
    IW::GroundStation gs = GsDatabase::getInstance().getById(inGsId);

    switch(gs.connectionType)
    {
        case IW::ConnectionTypeEnum::TCP:
            {
                // Create the object
                shared_ptr<GsTcpConnection> tmpConnection{ new GsTcpConnection(tmpId) };

                // Set parameters
                tmpConnection->setUrl(gs.url);
                tmpConnection->setPort(gs.port);

                output = (GsConnection::PtrGsConnection) tmpConnection;
            }
            break;

        case IW::ConnectionTypeEnum::SERIAL:
            cout << "INFO: Serial connection is not supported yet" << endl;
            break;

        case IW::ConnectionTypeEnum::USB:
            cout << "INFO: USB connection is not supported yet" << endl;
            break;

        case IW::ConnectionTypeEnum::NONE:
        default:
            // Throw an exception
            string tmpMessage{"Invalid G/S connection type"};

            cout << "ERROR: " << tmpMessage << endl;
            throw GSException(tmpMessage);
            break;
    }

    if (output != nullptr)
    {
        // Store in the map
        this->activeConnections[tmpId] = output;
    }

    return output;
}

void GsConnectionManager::release(GsConnection::PtrGsConnection& inConnection)
{
    release(inConnection->getId());
}

void GsConnectionManager::release(const string& inConnectionId)
{
    if (inConnectionId.empty() == false)
    {
        map<string, GsConnection::PtrGsConnection>::iterator it{ this->activeConnections.find(inConnectionId) };

        if (it != this->activeConnections.end())
        {
            this->activeConnections.erase(it);
        }
    }
    else
    {
        string tmpMessage{"Unknown G/S connection identifier"};

        cout << "ERROR: " << tmpMessage << endl;
        throw GSException(tmpMessage);
    }
}

GsConnection::PtrGsConnection GsConnectionManager::getConnection(const string& inConnectionId)
{
    GsConnection::PtrGsConnection output;

    if (inConnectionId.empty() == false)
    {
        output = this->activeConnections[inConnectionId];
    }
    else
    {
        string tmpMessage{"Unknown G/S connection identifier"};

        cout << "ERROR: " << tmpMessage << endl;
        throw GSException(tmpMessage);
    }

    return output;
}

// Run the io_service in its separated thread
// See constructor
//void GsConnectionManager::runIoService()
//{
//    cout <<"INFO: Start of io_service thread" << endl;
//
//    // Prevent io_service to stop itself
//    boost::asio::io_service::work tmpWork(this->io_service);
//
//    this->io_service.run();
//
//    cout <<"INFO: End of io_service thread" << endl;
//}
