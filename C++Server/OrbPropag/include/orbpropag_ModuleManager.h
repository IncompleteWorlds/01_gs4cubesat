/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2019 Incomplete Worlds
 *
 */
 
#ifndef __ORB_PROPAG_MODULE_MANAGER__
#define __ORB_PROPAG_MODULE_MANAGER__

#include <thread>

using namespace std;

#include "IModuleManagerZmq.h" // Base class: IModuleManagerZmq

// Main entry point of the Fortran Module
extern "C" 
{
    // This is the main entry point of the Fortran code
    void fortranMain();
}

class orbpropag_ModuleManager : public IModuleManagerZmq
{
    public:
        // Singleton
        static orbpropag_ModuleManager& getInstance()
        {
            static orbpropag_ModuleManager instance;

            return instance;
        }

        virtual ~orbpropag_ModuleManager();

        // delete copy and move constructors and assign operators
        orbpropag_ModuleManager(orbpropag_ModuleManager const&) = delete;             // Copy construct
        orbpropag_ModuleManager(orbpropag_ModuleManager&&) = delete;                  // Move construct
        orbpropag_ModuleManager& operator=(orbpropag_ModuleManager const&) = delete;  // Copy assign
        orbpropag_ModuleManager& operator=(orbpropag_ModuleManager &&) = delete;      // Move assign

        // Load configuraiton and external IFs
        void init(const string &inConfigFileName);

        // Module IF
        virtual void start();
        virtual void shutdown();
        
        // Interface with the External Module
        void sendFdsMessage(const int inCode, const char* inMessage, char *outMessage);
        void setFortranReturnCode(int inValue, char *inErrorMessage);
        
        // It will return 0, if the parameter exists
        // It will return -1, if it is not found
        int getParameter(const char* inKey, int inLen, char* outValue);
        
        // Set or update the key.
        // If it already exists, the content will be replaced
        int setParameter(const char* inKey, char* inValue);

    protected:
        orbpropag_ModuleManager();

    private:
        // ZeroMQ context
        zmq::context_t    context_;

        // Socket for receiving module messages        
        zmq::socket_t     module_req_;
    
        // Module for sending events to the FDS. I.e. algorithm has finished
        zmq::socket_t     fds_pub_;
        
        // Socket for making requests to the FDS Server; i.e. log message, read or write data in the database
        zmq::socket_t     fds_req_;
        
        std::thread       theThread_;
        
        string            executionId_;
        IW::ListKeyValues parameters_;
        
        bool              algorithmIsRunning_;
        int               fortranReturnCode_;
        string            fortranErrorMessage_;
        bool              fortranDone_;


        void runZeroMQ();
        
        void internalRun();
        
        ServerMessage returnStatus(ServerMessage &inMessage);
        ServerMessage runAlgorithm(ServerMessage &inMessage);
        
        void internalRunAlgorithm();
};

#endif // __ORB_PROPAG_MODULE_MANAGER__
