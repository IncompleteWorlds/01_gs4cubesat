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
const string ConfigurationManager::GROUP_NNG = "NNG";
const string ConfigurationManager::GROUP_GENERAL = "General";
const string ConfigurationManager::GROUP_HTTP = "HTTP";

const string ConfigurationManager::KEY_GEN_MODULE_NAME = "module_name";
const string ConfigurationManager::KEY_GEN_LOG_FILE = "log_file";

//TODO: Rename to mission_name
const string ConfigurationManager::KEY_MISSION_ID = "mission_id";

const string ConfigurationManager::KEY_SERVER_ADDRESS = "server_address";
const string ConfigurationManager::KEY_PUB_ADDRESS = "publisher_address";
const string ConfigurationManager::KEY_SUB_ADDRESS = "subscriber_address";
const string ConfigurationManager::KEY_RECV_TIMEOUT = "receive_msg_timeout";

// Nanomsg Buses
const string ConfigurationManager::KEY_BUS_ADDRESS = "bus_address";
const string ConfigurationManager::KEY_EVENT_BUS_ADDRESS = "event_bus_address";
const string ConfigurationManager::KEY_LOG_BUS_ADDRESS = "log_bus_address";

// HTTP
const string ConfigurationManager::KEY_HTTP_SERVER_ADDRESS = "http_server_address";


// MCS
const string ConfigurationManager::KEY_MCS_GS_MANAGER_SERVER_ADDRESS = "gs_manager_server_address";
const string ConfigurationManager::KEY_MCS_SERVER_ADDRESS = "mcs_server_address";
const string ConfigurationManager::KEY_MCS_ARCHIVE_DATABASE = "archive_database_name";


// GS Manager
const string ConfigurationManager::KEY_GS_MANAGER_DATABASE = "gs_database_name";
const string ConfigurationManager::KEY_GS_TM_PROCESSOR_ADDRESS = "tm_processor_address";

// Tools
const string ConfigurationManager::KEY_TOOLS_DATABASE = "tools_database_name";
const string ConfigurationManager::KEY_TOOLS_SERVER_ADDRESS = "tools_server_address";

// FDS
const string ConfigurationManager::KEY_FDS_DATABASE = "fds_database_name";
const string ConfigurationManager::KEY_FDS_SERVER_ADDRESS = "fds_server_address";
const string ConfigurationManager::KEY_FDS_EXECUTABLE_NAME = "executable_name";

const string ConfigurationManager::KEY_FDS_MODULE_ADDRESS = "module_address";

const string ConfigurationManager::KEY_FDS_PUB_ADDRESS = "fds_publisher_address";

// MCC
const string ConfigurationManager::KEY_MCC_SERVER_ADDRESS = "mcc_server_address";


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

	if (inConfigFileName.empty() == true) {
		throw GSException("Invalid configuration file name");
	}

	// Open file
	ifstream configFile(inConfigFileName);

	if (configFile.is_open() == false ) {
		// Error
		string tmpMessage = "Error: While opening configuration file: " + inConfigFileName;
		LogManager::getInstance().error(tmpMessage);

		throw GSException(tmpMessage);
	}

	// Read the whole file as a string
	string inputBuffer;
	string tmpLine;

	LogManager::getInstance().debug("DEBUG: Config file: ");
	while (configFile.eof() == false ) {
		getline (configFile,tmpLine);
		inputBuffer += tmpLine;

		LogManager::getInstance().debug(tmpLine);
		//cout << tmpLine << endl;
	}
	//cout << "DEBUG: END Config file" << endl;

	configFile.close();

	// Read key values and store them
	json11::Json tmpKeyValues;
	string errorMessage;

	tmpKeyValues = json11::Json::parse(inputBuffer, errorMessage, json11::JsonParse::STANDARD);

	if (errorMessage.empty() == false) {
		string tmpMessage = "Parsing config JSON file. errorMessage: " + errorMessage;

		LogManager::getInstance().error(tmpMessage);
		throw GSException(tmpMessage);
	}
	// Group: General
	// ==============================================================
	json11::Json  tmpGroup = tmpKeyValues[GROUP_GENERAL];

	if (tmpGroup.is_null() == false) {
		if (tmpGroup[KEY_GEN_LOG_FILE].is_null() == false)
			keyValues[KEY_GEN_LOG_FILE]     = tmpGroup[KEY_GEN_LOG_FILE].string_value();
		if (tmpGroup[KEY_GEN_MODULE_NAME].is_null() == false)
			keyValues[KEY_GEN_MODULE_NAME]  = tmpGroup[KEY_GEN_MODULE_NAME].string_value();
		if (tmpGroup[KEY_MISSION_ID].is_null() == false)
			keyValues[KEY_MISSION_ID]       = tmpGroup[KEY_MISSION_ID].string_value();

		// GS Manager
		if (tmpGroup[KEY_GS_MANAGER_DATABASE].is_null() == false)
			keyValues[KEY_GS_MANAGER_DATABASE]  = tmpGroup[KEY_GS_MANAGER_DATABASE].string_value();


		// Tools
		if (tmpGroup[KEY_TOOLS_DATABASE].is_null() == false)
			keyValues[KEY_TOOLS_DATABASE]  = tmpGroup[KEY_TOOLS_DATABASE].string_value();


		// MCS. TM Archive
		if (tmpGroup[KEY_MCS_ARCHIVE_DATABASE].is_null() == false)
			keyValues[KEY_MCS_ARCHIVE_DATABASE] = tmpGroup[KEY_MCS_ARCHIVE_DATABASE].string_value();


		// FDS
		if (tmpGroup[KEY_FDS_DATABASE].is_null() == false)
			keyValues[KEY_FDS_DATABASE] = tmpGroup[KEY_FDS_DATABASE].string_value();
		// TODO: Process list of Groups
	}


	// Group: ZeroMQ
	// ==============================================================
	tmpGroup = tmpKeyValues[GROUP_ZMQ];

	if (tmpGroup.is_null() == false) {
		if (tmpGroup[KEY_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_SERVER_ADDRESS] = tmpGroup[KEY_SERVER_ADDRESS].string_value();

		if (tmpGroup[KEY_PUB_ADDRESS].is_null() == false)
			keyValues[KEY_PUB_ADDRESS] = tmpGroup[KEY_PUB_ADDRESS].string_value();

		if (tmpGroup[KEY_SUB_ADDRESS].is_null() == false)
			keyValues[KEY_SUB_ADDRESS] = tmpGroup[KEY_SUB_ADDRESS].string_value();

		if (tmpGroup[KEY_RECV_TIMEOUT].is_null() == false)
			keyValues[KEY_RECV_TIMEOUT] = tmpGroup[KEY_RECV_TIMEOUT].string_value();


		// GS Manager
		if (tmpGroup[KEY_GS_TM_PROCESSOR_ADDRESS].is_null() == false)
			keyValues[KEY_GS_TM_PROCESSOR_ADDRESS]  = tmpGroup[KEY_GS_TM_PROCESSOR_ADDRESS].string_value();


		// MCS
		if (tmpGroup[KEY_MCS_GS_MANAGER_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_MCS_GS_MANAGER_SERVER_ADDRESS] = tmpGroup[KEY_MCS_GS_MANAGER_SERVER_ADDRESS].string_value();

		if (tmpGroup[KEY_MCS_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_MCS_SERVER_ADDRESS] = tmpGroup[KEY_MCS_SERVER_ADDRESS].string_value();

		// Tools
		if (tmpGroup[KEY_TOOLS_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_TOOLS_SERVER_ADDRESS] = tmpGroup[KEY_TOOLS_SERVER_ADDRESS].string_value();

		// FDS
		if (tmpGroup[KEY_FDS_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_FDS_SERVER_ADDRESS] = tmpGroup[KEY_FDS_SERVER_ADDRESS].string_value();

		if (tmpGroup[KEY_FDS_MODULE_ADDRESS].is_null() == false)
			keyValues[KEY_FDS_MODULE_ADDRESS] = tmpGroup[KEY_FDS_MODULE_ADDRESS].string_value();

		if (tmpGroup[KEY_FDS_PUB_ADDRESS].is_null() == false)
			keyValues[KEY_FDS_PUB_ADDRESS] = tmpGroup[KEY_FDS_PUB_ADDRESS].string_value();
	}

	// Group: New Nanomsg
	// ==============================================================
	tmpGroup = tmpKeyValues[GROUP_NNG];

	if (tmpGroup.is_null() == false) {
		// BUSES and General
		if (tmpGroup[KEY_MCC_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_MCC_SERVER_ADDRESS] = tmpGroup[KEY_MCC_SERVER_ADDRESS].string_value();

		if(tmpGroup[KEY_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_SERVER_ADDRESS] = tmpGroup[KEY_SERVER_ADDRESS].string_value();

		if(tmpGroup[KEY_BUS_ADDRESS].is_null() == false)
			keyValues[KEY_BUS_ADDRESS] = tmpGroup[KEY_BUS_ADDRESS].string_value();

		if(tmpGroup[KEY_LOG_BUS_ADDRESS].is_null() == false)
			keyValues[KEY_LOG_BUS_ADDRESS] = tmpGroup[KEY_LOG_BUS_ADDRESS].string_value();

		if(tmpGroup[KEY_EVENT_BUS_ADDRESS].is_null() == false)
			keyValues[KEY_EVENT_BUS_ADDRESS] = tmpGroup[KEY_EVENT_BUS_ADDRESS].string_value();

		if (tmpGroup[KEY_RECV_TIMEOUT].is_null() == false)
			keyValues[KEY_RECV_TIMEOUT] = tmpGroup[KEY_RECV_TIMEOUT].string_value();



		// GS Manager
		if (tmpGroup[KEY_GS_TM_PROCESSOR_ADDRESS].is_null() == false)
			keyValues[KEY_GS_TM_PROCESSOR_ADDRESS]  = tmpGroup[KEY_GS_TM_PROCESSOR_ADDRESS].string_value();

	}

	// HTTP group
	tmpGroup = tmpKeyValues[GROUP_HTTP];

	if (tmpGroup.is_null() == false) {
		// BUSES and General
		if (tmpGroup[KEY_HTTP_SERVER_ADDRESS].is_null() == false)
			keyValues[KEY_HTTP_SERVER_ADDRESS] = tmpGroup[KEY_HTTP_SERVER_ADDRESS].string_value();
	}

}

string ConfigurationManager::getValue(const string &inKey)
{
	string output{""};

	//cout << "DEBUG:   inKey = " << inKey << endl;

	if (inKey.empty() == false) {
		output = keyValues[ inKey ];

		//LogManager::getInstance().debug("keyValues[ " + inKey + " ] = " + keyValues[ inKey ] );
		//cout << "DEBUG:    keyValues[ " << inKey << " ] = " << keyValues[ inKey ] << endl;
	} else {
		throw GSException("Configruation parameter not found: " + inKey);
	}

	return output;
}

// It returns the list of strings contained in the value part
vector<string> ConfigurationManager::getListValues(const string &inKey)
{
	vector<string>   output;

	if (inKey.empty() == false) {
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
