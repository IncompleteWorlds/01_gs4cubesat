/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __GSCONNECTIONMANAGER_H__
#define __GSCONNECTIONMANAGER_H__

#include <map>
#include <string>

//#include <boost/asio.hpp>

#include "GsConnection.h"

using namespace std;


class GsConnectionManager
{
public:
    // Singleton
    static GsConnectionManager& getInstance()
    {
        static GsConnectionManager instance;

        return instance;
    }
    virtual ~GsConnectionManager();

    //void runIoService();

    GsConnection::PtrGsConnection create(const string& inGsId);

    void release(GsConnection::PtrGsConnection& inConnection);

    void release(const string& inConnectionId);

    GsConnection::PtrGsConnection getConnection(const string& inConnectionId);

protected:
    //boost::asio::io_service io_service;

    int  nextId;

    // Map < identifier, connection >
    map<string, GsConnection::PtrGsConnection>   activeConnections;

    GsConnectionManager();
};

#endif // __GSMANAGER_H__
