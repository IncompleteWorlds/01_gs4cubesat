/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __GSCONNECTION__
#define __GSCONNECTION__

#include <string>
#include <memory>

using namespace std;



/**
 * @brief Abstract class that represents a connection to a G/S
 * It is envisaged that each connection runs in its own thread
 */
class GsConnection
{
    public:
        typedef shared_ptr<GsConnection> PtrGsConnection;

        GsConnection(const string& inIdentifier) : identifier_{inIdentifier} {}
        virtual ~GsConnection() {}

        string getId();


        // Operations to be implemented
        virtual void connect() = 0;

        virtual void disconnect() = 0;

        virtual void read() = 0;
        
        virtual void write() = 0;


    protected:
        string identifier_;
};

#endif // __GSCONNECTION__

