/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include <iostream>

using namespace std;

#include <thrift/server/TNonblockingServer.h>
#include <thrift/concurrency/PosixThreadFactory.h>

using namespace ::apache::thrift::concurrency;

#include "ConfigurationManager.h"

#include "FdsServiceHandler.h"

#include "FdsModuleManager.h"



FdsModuleManager::FdsModuleManager()
{
}

FdsModuleManager::~FdsModuleManager()
{
    // ???
    shutdown();
}

void FdsModuleManager::init(const string& inConfigFileName)
{
    if (inConfigFileName.empty() == false) {
        try {
            // Read the MCS configuration from a JSON config file
            // Throws and exception if an error is found
            ConfigurationManager::getInstance().load(inConfigFileName);

            // Start the external interface (REST, QPID, etc.) depending on
            // configuration value
            // It could be a Factory.
            auto interfaceType = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_EXTERNAL_IF_TYPE);

            cout << "DEBUG:  interfaceType = " << interfaceType << endl;

            // Start Thrift interface
            initThrift();
        } catch (const std::exception& e) {
            cerr << e.what() << std::endl;
        } catch (...) {
            cerr << "Unknown exception" << std::endl;
        }
    } else {
        cerr << "ERROR: Empty configuration file name" << endl;
    }
}

void FdsModuleManager::start()
{
    cout << "log.INFO  FDS Module starting up" << endl;

    // TODO: Start thread to check input folder:  data -> input
}

void FdsModuleManager::shutdown()
{
    cout << "log.INFO  FDS Module shutting down" << endl;
}

ModuleStatusEnum FdsModuleManager::getStatus()
{
    return MODE_RUNNING;
}

void FdsModuleManager::initThrift()
{
    //
    // Start the server
    string tmpPort = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_THRIFT_FDS_PORT);
    int port = atoi(tmpPort.c_str());

    cout << "DEBUG: *** Starting non-block THRIFT! ***" << endl;
    boost::shared_ptr<FdsServiceHandler> handler(new FdsServiceHandler( ));
    boost::shared_ptr<TProcessor>        processor(new FdsServiceProcessor(handler));
    boost::shared_ptr<TProtocolFactory>  protocolFactory(new TBinaryProtocolFactory());

    boost::shared_ptr<TTransportFactory> transportFactory(new TFramedTransportFactory());

    boost::shared_ptr<ThreadManager>      threadManager=ThreadManager::newSimpleThreadManager(15);
    boost::shared_ptr<PosixThreadFactory> threadFactory = boost::shared_ptr<PosixThreadFactory>(new PosixThreadFactory());

    threadManager->threadFactory(threadFactory);
    threadManager->start();

    TNonblockingServer server(processor,
                              transportFactory, transportFactory,
                              protocolFactory, protocolFactory,
                              port, threadManager);

    string tmpTextValue = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_THRIFT_DEFAULT_TIMEOUT);
    int thriftTimeout = atoi(tmpTextValue.c_str());

    cout << "DEBUG: Thrift timeout: " << thriftTimeout << endl;
    server.setTaskExpireTime(thriftTimeout);

    server.serve();
}
