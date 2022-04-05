/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <fstream>
#include <sstream>

using namespace std;

#include "GSException.h"

#include "LogManager.h"
#include "ConfigurationManager.h"

const string ConfigurationManager::GROUP_ZMQ = "ZMQ";
const string ConfigurationManager::GROUP_GENERAL = "General";

const string ConfigurationManager::KEY_GEN_MODULE_NAME = "module_name";
const string ConfigurationManager::KEY_GEN_LOG_FILE = "log_file";
const string ConfigurationManager::KEY_MISSION_ID = "mission_id";

const string ConfigurationManager::KEY_ZEROMQ_SERVER_ADDRESS = "server_address";
const string ConfigurationManager::KEY_ZEROMQ_PUB_ADDRESS = "publisher_address";
const string ConfigurationManager::KEY_ZEROMQ_SUB_ADDRESS = "subscriber_address";
const string ConfigurationManager::KEY_ZEROMQ_RECV_TIMEOUT = "receive_msg_timeout";


// MCS
const string ConfigurationManager::KEY_ZEROMQ_GS_MANAGER_SERVER_ADDRESS = "gs_manager_server_address";
const string ConfigurationManager::KEY_ZEROMQ_MCS_SERVER_ADDRESS = "mcs_server_address";
const string ConfigurationManager::KEY_ARCHIVE_DATABASE = "archive_database_name";


// GS Manager
const string ConfigurationManager::KEY_GS_MANAGER_DATABASE = "gs_database_name";
const string ConfigurationManager::KEY_ZEROMQ_TM_PROCESSOR_ADDRESS = "tm_processor_address";

// Tools
const string ConfigurationManager::KEY_TOOLS_DATABASE = "tools_database_name";
const string ConfigurationManager::KEY_ZEROMQ_TOOLS_SERVER_ADDRESS = "tools_server_address";




// Protected constructor
ConfigurationManager::ConfigurationManager()
    : keyValues{}
{
}

ConfigurationManager::~ConfigurationManager()
{
}

void ConfigurationManager::load(const string& inConfigFileName)
{
    cout << "DEBUG: Loading configuration file: " << inConfigFileName << endl;

    if (inConfigFileName.empty() == false) {
        // Open file
        ifstream configFile(inConfigFileName);

        if (configFile.is_open() == false ) {
            // Error
            string tmpMessage = "Error: While opening configuration file: " + inConfigFileName;

            throw GSException(tmpMessage);
        } else {
            // Read the whole file as a string
            string inputBuffer;
            string tmpLine;

            // TODO: Add Log manager component. Log4cpp
            cout << "DEBUG: Config file: " << endl;
            while (configFile.eof() == false ) {
                getline (configFile,tmpLine);
                inputBuffer += tmpLine;

                cout << tmpLine << endl;
            }
            cout << "DEBUG: END Config file" << endl;

            configFile.close();

            // Read key values and store them
            json11::Json tmpKeyValues;
            string errorMessage;

            tmpKeyValues = json11::Json::parse(inputBuffer, errorMessage, json11::JsonParse::STANDARD);

            if (errorMessage.empty() == false) {
                string tmpMessage = "Parsing config JSON file. errorMessage: " + errorMessage;

                cout << "ERROR: " << tmpMessage << endl;
                throw GSException(tmpMessage);
            }
            else
            {
                // Group: General
                // ==============================================================
                json11::Json  tmpGroup = tmpKeyValues[GROUP_GENERAL];

                keyValues[KEY_GEN_LOG_FILE]     = tmpGroup[KEY_GEN_LOG_FILE].string_value();
                keyValues[KEY_GEN_MODULE_NAME]  = tmpGroup[KEY_GEN_MODULE_NAME].string_value();
                keyValues[KEY_MISSION_ID]       = tmpGroup[KEY_MISSION_ID].string_value();


                // GS Manager
                keyValues[KEY_GS_MANAGER_DATABASE]  = tmpGroup[KEY_GS_MANAGER_DATABASE].string_value();


                // Tools
                keyValues[KEY_TOOLS_DATABASE]  = tmpGroup[KEY_TOOLS_DATABASE].string_value();

                // MCS. TM Archive
                keyValues[KEY_ARCHIVE_DATABASE] = tmpGroup[KEY_ARCHIVE_DATABASE].string_value();





                // Group: ZeroMQ
                // ==============================================================
                tmpGroup = tmpKeyValues[GROUP_ZMQ];

                keyValues[KEY_ZEROMQ_SERVER_ADDRESS] = tmpGroup[KEY_ZEROMQ_SERVER_ADDRESS].string_value();

                keyValues[KEY_ZEROMQ_PUB_ADDRESS] = tmpGroup[KEY_ZEROMQ_PUB_ADDRESS].string_value();

                keyValues[KEY_ZEROMQ_SUB_ADDRESS] = tmpGroup[KEY_ZEROMQ_SUB_ADDRESS].string_value();
                
                keyValues[KEY_ZEROMQ_RECV_TIMEOUT] = tmpGroup[KEY_ZEROMQ_RECV_TIMEOUT].string_value();
                                

                // GS Manager
                keyValues[KEY_ZEROMQ_TM_PROCESSOR_ADDRESS]  = tmpGroup[KEY_ZEROMQ_TM_PROCESSOR_ADDRESS].string_value();


                // MCS
                keyValues[KEY_ZEROMQ_GS_MANAGER_SERVER_ADDRESS] = tmpGroup[KEY_ZEROMQ_GS_MANAGER_SERVER_ADDRESS].string_value();

                keyValues[KEY_ZEROMQ_MCS_SERVER_ADDRESS] = tmpGroup[KEY_ZEROMQ_MCS_SERVER_ADDRESS].string_value();

                // Tools
                keyValues[KEY_ZEROMQ_TOOLS_SERVER_ADDRESS] = tmpGroup[KEY_ZEROMQ_TOOLS_SERVER_ADDRESS].string_value();
            }
        }
    } else {
        throw GSException("Invalid configuration file name");
    }
}

string ConfigurationManager::getValue(const string &inKey)
{
    string output = "";

    //cout << "DEBUG:   inKey = " << inKey << endl;

    if (inKey.empty() == false) {
        output = keyValues[ inKey ];

        //LogManager::getInstance().debug("keyValues[ " + inKey + " ] = " + keyValues[ inKey ] );
        //cout << "DEBUG:    keyValues[ " << inKey << " ] = " << keyValues[ inKey ] << endl;
    }

    return output;
}

// It returns the list of strings contained in the value part
vector<string> ConfigurationManager::getListValues(const string &inKey) {
    vector<string>   output;

    if (inKey.empty() == false)
    {
        string tmpBuffer = getValue(inKey);

        output = move(splitStrings(tmpBuffer));
    }

    return output;
}

// Merge a set of strings into a single string separated by comma
string ConfigurationManager::mergeStrings(const vector<json11::Json> inArray)
{
    string output;

    if (inArray.empty() == false) {
        bool firstItem = true;

        for (auto current: inArray ) {
            // Only add first comma
            if (firstItem == false) {
                output.append(",");
            } else {
                firstItem = false;
            }
            output.append(current.string_value());
        }

    }
    return output;
}


// Split a string into a set of strings separated by comma
vector<string> ConfigurationManager::splitStrings(const string inString)
{
    vector<string> output;

    if (inString.empty() == false) {
        // Alternative
        //split(tmbBuffer, ",", output);

        stringstream ss;
        char delimiter = ',';

        ss.str(inString);
        string item;

        while (getline(ss, item, delimiter)) {
            if (item.empty() == false) {
                // There is no straightforward of doing trim
                output.push_back(item);
            }
        }

    }
    return output;
}
