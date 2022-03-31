/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __FDS_MODULE_MANAGER_H__
#define __FDS_MODULE_MANAGER_H__


#include <map>
#include <string>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

// For the HTTP inteface
#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

// For the Nanomsg interface
extern "C" {
    #include <nng/nng.h>
    #include <nng/protocol/reqrep0/rep.h>
    #include <nng/protocol/reqrep0/req.h>
}

#include "IModuleManagerNng.h"


class FdsModuleManager : public IModuleManagerNng
{
    public:
        // Singleton
        static FdsModuleManager& getInstance()
        {
            static FdsModuleManager instance;

            return instance;
        }

        virtual ~FdsModuleManager();

        // delete copy and move constructors and assign operators
        FdsModuleManager(FdsModuleManager const&) = delete;             // Copy construct
        FdsModuleManager(FdsModuleManager&&) = delete;                  // Move construct
        FdsModuleManager& operator=(FdsModuleManager const&) = delete;  // Copy assign
        FdsModuleManager& operator=(FdsModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        void start();
        void shutdown();

        ModuleStatusEnum getStatus();

    protected:
        FdsModuleManager();

    private:
        // ZeroMQ context
        //zmq::context_t       context_;
        
        thread       nanomsgThread_;
        thread       nanomsgBusThread_;

        nng::socket   reply_socket_;
        nng::socket   bus_socket_;
        nng::socket   main_socket_;
        
        // These sockets are shared between the controller
        nng::socket   http_socket_req_;
        nng::socket   nng_socket_req_;
        nng::socket   bus_socket_req_;
        
        pplx::task<void> listenerTask_;
        http_listener    listener_;

        bool endFlag_;

        void createHttpInterface();
    
        void createNanoMsgInterface();
        
        // It processes all messages from all sockets; Nanomsg Request, HTTP REST, Nanomsg Bus
        void mainControlLoop();
        
        void handleHttpRequest(http_request request);
        
        // Nanomsg Request/Reply control loop
        void nanomsgRequest();
        
        // Nanomsg Bus control loop
        void nanomsgBus();

        // Return the message associated to an HTTP request
        OperationCodeEnum getMessageCode(const string& inMethod, const vector<utility::string_t>& inPathParts);

        vector<utility::string_t> extractPath(const http_request& inRequest);
};

#endif // __FDS_MODULE_MANAGER_H__

