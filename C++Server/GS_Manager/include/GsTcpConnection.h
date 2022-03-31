/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __GSTCPCONNECTION_H__
#define __GSTCPCONNECTION_H__

#include <thread>
#include <vector>

using namespace std;

#include <nngpp/stream/dialer.h>
#include <nngpp/stream/stream.h>


#include "Constants.h"

#include "CommonTypes.h"
#include "GsConnection.h"




/**
 * @brief The GsTcpConnection class contains a TCP/IP connection with a
 * Ground Station
 */
// Using shared_ptr and enable_shared_from_this
// because we want to keep the tcp_connection object alive
// as long as there is an operation that refers to it.
// : public boost::enable_shared_from_this<GsTcpConnection>
class GsTcpConnection : public GsConnection
{
    public:
        // Constructor
        GsTcpConnection(const string& inIdentifier);
        GsTcpConnection(const string& inIdentifier,
                        string& inURL, int inPort, size_t inFrameSize=DEFAULT_FRAME_SIZE);

        virtual ~GsTcpConnection();

//        tcp::socket& getSocket()
//        {
//            return tcpSocket_;
//        }

        // Virtual operations
        virtual void connect();

        virtual void disconnect();

        virtual void read();
        
        virtual void write();

        // TCP Operations
        void setUrl(const string &inURL);

        string getUrl();

        void setPort(int inPort);

        int getPort();

        void setFrameSize(size_t inFrameSzie);

        size_t getFrameSize();
        
        void internalAddFrame();
        void internalRead();


    private:
        nng::stream::dialer   tcpSocket_;
        //nng::aio              callback_;
        nng::stream::stream   tcpStream_;
        
        string                url_;
        int                   port_;
        size_t                frameSize_;



        // TODO: Define a maximum constant
        RawFrameType          bytesBuffer_;

        // This thread will deliver frames to the MCS
        bool                  endTransferMcs_;
        std::thread           deliverThread_;
        std::mutex            mutex_;


        //shared_queue<RawFrameType>   frames;
        std::vector<RawFrameType>    frames_;


        /**
         * @brief readHandler
         * The handler will be invoked when some bytes are read from the socket
         * It will forward the bytes to the MCS
         * It could be relocated to GsConnection (base class)
         * @param ec
         * @param bytesTransferred
         */
        //void readHandler(const boost::system::error_code& ec, size_t bytesTransferred);

        /**
         * @brief GsTcpConnection::sendFramesToMCS
         * Extract a frame from the queue and forward it to the MCS
         */
        void sendFramesToMCS();

};

#endif // __GSTCPCONNECTION_H__
