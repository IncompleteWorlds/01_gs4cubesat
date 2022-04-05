/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */


#include <iostream>
#include <ctime>

using namespace std;


#include "M_CModuleManager.h"

// ******************************************************************
// ******************************************************************
// ******************************************************************


void usage()
{
    cout << endl;
    cout << "Usage: " << endl;
    cout << "       m_c_main  <filename_and_path>/config_filename.json" << endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    int output = -1;

    cout << "Monitor and Control System (M&C)" << endl;
    cout << "(c) 2017 Incomplete Worlds" << endl;
    time_t currentTime = time(nullptr);
    cout << "Date: " <<  asctime( gmtime( &currentTime) ) << endl;
    cout << endl;

    // Check parameters
    if (argc < 2) {
        cout << "ERROR: Incorrect number of parameters." << endl;

        usage();
        output=0;
    } else {
        // Initialize and load configuration
        M_CModuleManager::getInstance().init( argv[1] );

        // Module will be started and stopped by means of the External IF
        M_CModuleManager::getInstance().start();

        output = 0;
    }

    return output;
}















/*
#include <iostream>

using namespace std;

#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>

using namespace qpid::messaging;

int main()
{
    std::string address("127.0.0.1:5672/examples");

    int message_count = 100;
    options opts(argc, argv);

    opts.add_value(address, 'a', "address", "connect to and receive from URL", "URL");
    opts.add_value(message_count, 'm', "messages", "receive COUNT messages", "COUNT");

    try {
        opts.parse();

        simple_recv recv(address, message_count);
        proton::container(recv).run();

        return 0;
    } catch (const bad_option& e) {
        std::cout << opts << std::endl << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 1;
*/


    /*
    string  broker = "localhost:5672";
    string  address = "amq.topic";
    string  connOptions = "";

    cout << "Creating connection" << endl;

    Connection  conn(broker, connOptions);

    try {
        conn.open();

        Session session = conn.createSession();

        Receiver receiver = session.createReceiver(address);
        Sender sender = session.createSender(address);

        sender.send( Message("Hello World") );





        Message msg = receiver.fetch(Duration::SECOND * 1);
        cout << msg.getContent() << endl;

        session.acknowledge();

        conn.close();
        return 0;

    } catch (const exception &e) {
        cerr << e.what() << endl;
        conn.close();
        return 1;
    }
    */

//}

