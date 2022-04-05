/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <string>

using namespace std;

#include "SQLiteCpp/Statement.h"

#include "Constants.h"
#include "GSException.h"
#include "LogManager.h"
#include "ConfigurationManager.h"

#include "ToolsDatabase.h"




ToolsDatabase::ToolsDatabase()
    : db{}
{
}

ToolsDatabase::~ToolsDatabase()
{
}

void ToolsDatabase::open()
{
    auto dbName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_TOOLS_DATABASE);
    
    open(dbName);
}

void ToolsDatabase::open(const string &inDbName)
{
    if (inDbName.empty() == false) {
        LogManager::getInstance().info("Opening Tools database: " + inDbName );

        shared_ptr<SQLite::Database> tmpDB{ new SQLite::Database(inDbName, SQLite::OPEN_READWRITE) };

        db = std::move(tmpDB);        
    } else {
        string tmpMessage = "Tools database name is empty";
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }


    // TODO: Check if tables exist, if not, create them
    /*
    if (db->tableExists("mission") == false)
    {
        // Create the table
    }
    */

    /*
     * CREATE TABLE "mission" (
    `identifier`	INTEGER PRIMARY KEY AUTOINCREMENT,
    `name`	TEXT NOT NULL,
    `description`	TEXT,
    `country`	TEXT,
    `owner`	TEXT NOT NULL,
    `creation_date`	TEXT NOT NULL
)
*/

//    SQLite::Statement   query(this->db, tmpCreateStatement);

    // SELECT name FROM sqlite_master WHERE type='table' AND name='table_name';

    //create table if not exists TableName (col1 typ1, ..., colN typN)
    // drop table if exists TableName


}

// -- MISSIONS ----------------------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createMission(const IW::Mission &inNewMission)
{
    int64_t output;

    string tmpQuery{"INSERT INTO t_mission (" \
                    "name, description,country,owner,creation_date, admin_identifier, email_address, phone_number" \
                    ") values (?, ?, ?, ?, ?, ?, ?, ?)"};

    // If creation time is empty, we will use the current time
    if (inNewMission.creationTime.empty() == true) 
    {
        tmpQuery = "INSERT INTO t_mission (" \
                              "name, description,country,owner,creation_date, admin_identifier, email_address, phone_number" \
                              ") values (?, ?, ?, ?, ?, ?, ?)";
    }

    SQLite::Statement   query(*this->db, tmpQuery);
    
    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewMission.name);
    query.bind(2, inNewMission.description);
    query.bind(3, inNewMission.country);
    query.bind(4, inNewMission.owner);
    
    if (inNewMission.creationTime.empty() == true) 
    {
        query.bind(5, inNewMission.adminIdentifier);
        query.bind(6, inNewMission.emailAddress);
        query.bind(7, inNewMission.phoneNumber);
    }
    else
    {
        query.bind(5, inNewMission.creationTime);        
        query.bind(6, inNewMission.adminIdentifier);
        query.bind(7, inNewMission.emailAddress);
        query.bind(8, inNewMission.phoneNumber);
    }

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new mission. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    // It returns the new mission identifier
    return output;
}

void ToolsDatabase::removeMission(const string& inId)
{
    removeByName("t_mission", inId);
}

void ToolsDatabase::updateMission(const IW::Mission &inMission)
{
    removeByName("t_mission", inMission.name);

    createMission(inMission);
}

IW::Mission ToolsDatabase::getMissionByName(const string &inName)
{
    IW::Mission output;

    if (inName.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_mission WHERE name = ?");

        // Bind the first parameter
        query.bind(1, inName);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            extractMissionData(query, output);
        }
        else
        {
            string tmpMessage = "Mission not found. Name: " + inName;
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());

            throw GSException(tmpMessage);
        }
    }

    return output;
}

vector<IW::Mission> ToolsDatabase::getMissions()
{
    vector<IW::Mission>  output;

    SQLite::Statement   query(*this->db, "SELECT * FROM t_mission");

    // We only retrieve the first value
    while (query.executeStep() == true)
    {
        IW::Mission tmpMission;

        extractMissionData(query, tmpMission);

        output.push_back(tmpMission);
    }

    return output;
}

void ToolsDatabase::extractMissionData(SQLite::Statement &inQuery, IW::Mission& outMission)
{
    outMission.name             = inQuery.getColumn(1).getString();
    outMission.description      = inQuery.getColumn(2).getString();
    outMission.country          = inQuery.getColumn(3).getString();
    outMission.owner            = inQuery.getColumn(4).getString();
    outMission.creationTime     = inQuery.getColumn(5).getString();
    outMission.adminIdentifier  = inQuery.getColumn(6).getInt();
    outMission.emailAddress     = inQuery.getColumn(7).getString();
    outMission.phoneNumber      = inQuery.getColumn(8).getString();
}

// -- SATELLITE ---------------------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createSatellite(const IW::Satellite &inNewSatellite)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_satellite (" \
                              "name, description, code, launch_date, mission_name" \
                              ") values (?, ?, ?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewSatellite.name);
    query.bind(2, inNewSatellite.description);
    query.bind(3, inNewSatellite.code);
    query.bind(4, inNewSatellite.launchDate);
    query.bind(5, inNewSatellite.missionName);
    
    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
        
        // TODO: Add the list of subsystems
        for(IW::Subsystem  current: inNewSatellite.listSubsystems.get_array())
        {
            createSubsystem(current);
        }
    }
    else
    {
        string tmpMessage = "Unable to create new satellite";
        LogManager::getInstance().error(tmpMessage);
        LogManager::getInstance().error(query.getErrorMsg());

        throw GSException(tmpMessage);
    }

    // It returns the new satellite id
    return output;
}

void ToolsDatabase::removeSatellite(const string& inId)
{
    removeByName("t_satellite", inId);
}

void ToolsDatabase::updateSatellite(const IW::Satellite &inSatellite)
{
    removeByName("t_satellite", inSatellite.name);

    createSatellite(inSatellite);
}

IW::Satellite ToolsDatabase::getSatelliteByName(const string& inMissionName, const string &inName)
{
    IW::Satellite output;

    if (inMissionName.empty() == false && inName.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_satellite WHERE mission_name = ? AND name = ?");

        // Bind the first parameter
        query.bind(1, inMissionName);
        query.bind(2, inName);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            extractSatelliteData(query, output);
            
            output.listSubsystems.set_array( getSubsystemsBySatellite(output.name) );
        }
        else
        {
            string tmpMessage = "Satellite not found. Name: " + inName;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());

            throw GSException(tmpMessage);
        }
    }
    else
    {
        LogManager::getInstance().error("Mission name or Satellite name is null");
    }

    return output;
}

IW::Satellite ToolsDatabase::getSatelliteByCode(const string& inMissionName, const string &inCode)
{
    IW::Satellite output;

    if (inMissionName.empty() == false && inCode.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_satellite WHERE mission_name = ? AND code = ?");

        // Bind the first parameter
        query.bind(1, inMissionName);
        query.bind(2, inCode);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            extractSatelliteData(query, output);
            
            output.listSubsystems.set_array( getSubsystemsBySatellite(output.name) );
        }
        else
        {
            string tmpMessage = "Satellite not found. Code: " + inCode;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());

            throw GSException(tmpMessage);
        }
    }
    else
    {
        LogManager::getInstance().error("Mission name or Satellite code is null");
    }

    return output;
}

vector<IW::Satellite> ToolsDatabase::getSatellites(string& inMissionName)
{
    vector<IW::Satellite>  output;

    if (inMissionName.empty() == false)
    {
        string tmpTextQuery {"SELECT * FROM t_satellite WHERE mission_name = ?"};
        
        // If Mission is empty, it will retrieve all satellites
        if (inMissionName.empty() == true)
        {
            tmpTextQuery = "SELECT * FROM t_satellite";
        }
        
        SQLite::Statement   query(*this->db, tmpTextQuery);
        
        if (inMissionName.empty() == false)
        {
            query.bind(1, inMissionName);
        }

        // We only retrieve the first value
        while (query.executeStep() == true)
        {
            IW::Satellite tmpSatellite;
            
            extractSatelliteData(query, tmpSatellite);
            
            tmpSatellite.listSubsystems.set_array( getSubsystemsBySatellite(tmpSatellite.name) );

            output.push_back(tmpSatellite);
        }
    }
    else
    {
        LogManager::getInstance().error("Mission name is null");
    }

    return output;
}

void ToolsDatabase::extractSatelliteData(SQLite::Statement &inQuery, IW::Satellite& outSatellite)
{
    outSatellite.name         = inQuery.getColumn(0).getString();
    outSatellite.description  = inQuery.getColumn(1).getString();
    outSatellite.code         = inQuery.getColumn(2).getString();
    outSatellite.launchDate   = inQuery.getColumn(3).getString();
    outSatellite.missionName  = inQuery.getColumn(4).getString();
}

// -- SUBSYSTEM ---------------------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createSubsystem(const IW::Subsystem& inNewSubsystem)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_subsystem (" \
                              "name, description, satellite_name" \
                              ") values (?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewSubsystem.name);
    query.bind(2, inNewSubsystem.description);
    query.bind(3, inNewSubsystem.satelliteName);

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new Subsystem. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    return output;
}

void ToolsDatabase::removeSubsystem(const string& inId)
{
    removeByName("t_subsystem", inId);
}

void ToolsDatabase::updateSubsystem(const IW::Subsystem &inSubsystem)
{
    removeByName("t_subsystem", inSubsystem.name);

    createSubsystem(inSubsystem);
}

IW::Subsystem ToolsDatabase::getSubsystemByName(const string& inSatelliteName, const string& inName)
{
    IW::Subsystem output;

    if (inName.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_subsystem WHERE name = ? and satellite_name = ?");

        // Bind the first parameter
        query.bind(1, inName);
        query.bind(2, inSatelliteName);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            extractSubsystemData(query, output);
        }
        else
        {
            string tmpMessage = "Subsystem not found. Name: " + inName;
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());

            throw GSException(tmpMessage);
        }        
    }
    else
    {
        LogManager::getInstance().error("Subsystem name is null");
    }

    return output;    
}

vector<IW::Subsystem> ToolsDatabase::getSubsystemsBySatellite(const string& inSatellite)
{
    vector<IW::Subsystem>  output;

    if (inSatellite.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_subsystem WHERE satellite_name = ?");

        // Bind the first parameter
        query.bind(1, inSatellite);

        // We only retrieve the first value
        while (query.executeStep() == true)
        {
            IW::Subsystem tmpSubsystem;

            extractSubsystemData(query, tmpSubsystem);

            output.push_back(tmpSubsystem);
        }
    }
    else
    {
        LogManager::getInstance().error("Satellite name is null");
    }

    return output;
}

vector<IW::Subsystem> ToolsDatabase::getSubsystems()
{
    vector<IW::Subsystem>  output;

    SQLite::Statement   query(*this->db, "SELECT * FROM t_subsystem");

    // We only retrieve the first value
    while (query.executeStep() == true)
    {
        IW::Subsystem tmpSubsystem;

        extractSubsystemData(query, tmpSubsystem);

        output.push_back(tmpSubsystem);
    }

    return output;
}

void ToolsDatabase::extractSubsystemData(SQLite::Statement &inQuery, IW::Subsystem& outSubsystem)
{
    outSubsystem.name          = inQuery.getColumn(0).getString();
    outSubsystem.description   = inQuery.getColumn(1).getString();
    outSubsystem.satelliteName = inQuery.getColumn(2).getString();
}

// -- NODE --------------------------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createNode(const IW::Node& inNewNode)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_node (" \
                              "name, description, subsystem_id" \
                              ") values (?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewNode.name);
    query.bind(2, inNewNode.description);
    query.bind(3, inNewNode.subsystemName);

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new Node. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    return output;
}

void ToolsDatabase::removeNode(const int64_t inId)
{
    removeById("t_node", inId);
}

IW::Node ToolsDatabase::getNodeById(const int64_t inId)
{
    IW::Node output;

    SQLite::Statement   query(*this->db, "SELECT * FROM t_node WHERE identifier = ?");

    // Bind the first parameter
    query.bind(1, std::to_string(inId));

    // We only retrieve the first value
    if (query.executeStep() == true)
    {
        extractNodeData(query, output);
    }
    else
    {
        string tmpMessage = "Node not found. Id: " + inId;
        LogManager::getInstance().error(tmpMessage);
        LogManager::getInstance().error(query.getErrorMsg());

        throw GSException(tmpMessage);
    }

    return output;
}

vector<IW::Node> ToolsDatabase::getNodes()
{
    vector<IW::Node>  output;

    SQLite::Statement   query(*this->db, "SELECT * FROM t_node");

    // We only retrieve the first value
    while (query.executeStep() == true)
    {
        IW::Node tmpNode;

        extractNodeData(query, tmpNode);

        output.push_back(tmpNode);
    }

    return output;
}


void ToolsDatabase::extractNodeData(SQLite::Statement &inQuery, IW::Node& outNode)
{
    outNode.identifier    = inQuery.getColumn(0).getInt64();
    outNode.name          = inQuery.getColumn(1).getString();
    outNode.description   = inQuery.getColumn(2).getString();
    outNode.subsystemName = inQuery.getColumn(3).getString();
}
    

// -- USER ---------------------------------------------------
// ----------------------------------------------------------------

IW::User ToolsDatabase::getUserById(const int64_t inId)
{
    IW::User output;

    if (inId > 0)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_user WHERE identifier = ?");

        // Bind the first parameter
        query.bind(1, std::to_string(inId));

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            extractUserData(query, output);
        }
        else
        {
            string tmpMessage = "User not found. Id: " + inId;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());
            
            throw GSException(tmpMessage);
        }
    }

    return output;
}

IW::User ToolsDatabase::getUserByName(const string &inName)
{
    IW::User output;

    if (inName.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_user WHERE user_name = ?");

        // Bind the first parameter
        query.bind(1, inName);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            extractUserData(query, output);
        }
        else
        {
            string tmpMessage = "User not found. Name: " + inName;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());            
            throw GSException(tmpMessage);
        }
    }

    return output;
}

int64_t ToolsDatabase::createUser(const string& inUserName, const string& inHashPassword,
    const string& inFirstName, const string& inLastName, const string& inEmailAddress,
    const string& inMissionName, const int32_t& inRoleId)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_user (" \
                              "user_name, password, first_name, last_name, email_address, mission_name, role_id" \
                              ") values (?, ?, ?, ?, ?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inUserName);
    query.bind(2, inHashPassword);
    query.bind(3, inFirstName);
    query.bind(4, inLastName);
    query.bind(5, inEmailAddress);
    query.bind(6, inMissionName);
    query.bind(7, inRoleId);

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new user. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    return output;
}


int64_t ToolsDatabase::createUser(const IW::User& inUser)
{
    return createUser(inUser.userName, 
                      inUser.password, 
                      inUser.firstName, 
                      inUser.lastName, 
                      inUser.emailAddress, 
                      inUser.missionName,   
                      inUser.roleId );
}

void ToolsDatabase::extractUserData(SQLite::Statement &inQuery, IW::User& outUser)
{
    outUser.userId       = inQuery.getColumn(0).getInt();
    outUser.userName     = inQuery.getColumn(1).getString();
    outUser.password     = inQuery.getColumn(2).getString();
    outUser.firstName    = inQuery.getColumn(3).getString();
    outUser.lastName     = inQuery.getColumn(4).getString();
    outUser.emailAddress = inQuery.getColumn(5).getString();
    outUser.missionName  = inQuery.getColumn(6).getString();
    outUser.roleId       = inQuery.getColumn(7).getInt();
}

// -- CONFIGURATION PARAMETERS ----------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createParameter(const IW::ConfigurationParameter &inNewParameter)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_configuration_parameters (" \
                              "name, description, value, type, user_id, mission_name, layer_name" \
                              ") values (?, ?, ?, ?, ?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewParameter.name);
    query.bind(2, inNewParameter.description);
    query.bind(3, inNewParameter.value);
    query.bind(4, inNewParameter.type);
    query.bind(5, inNewParameter.userId);
    query.bind(6, inNewParameter.missionName);
    query.bind(7, inNewParameter.layerName);
    
    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new Configuration Parameter";
        LogManager::getInstance().error(tmpMessage);
        LogManager::getInstance().error(query.getErrorMsg());

        throw GSException(tmpMessage);
    }

    // It returns the new satellite id
    return output;
}

IW::ListKeyValues ToolsDatabase::getMissionParameters(const string &inId)
{
    IW::ListKeyValues output;

    if (inId.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_configuration_parameters WHERE mission_id = ?");

        // Bind the first parameter
        query.bind(1, inId);

        // We only retrieve the first value
        while (query.executeStep() == true)
        {
            IW::KeyValue  tmpParameter;

            extractParameters(query, tmpParameter);

            output.listKeyValues.push_back(tmpParameter);
        }
    }

    return output;
}

IW::ListKeyValues ToolsDatabase::getUserParameters(const string &inId)
{
    IW::ListKeyValues output;

    if (inId.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_configuration_parameters WHERE user_id = ?");

        // Bind the first parameter
        query.bind(1, inId);

        // We only retrieve the first value
        while (query.executeStep() == true)
        {
            IW::KeyValue  tmpParameter;

            extractParameters(query, tmpParameter);

            output.listKeyValues.push_back(tmpParameter);
        }
    }

    return output;
}

void ToolsDatabase::extractParameters(SQLite::Statement &inQuery, IW::KeyValue& outField)
{
    // Name = Value
    outField.key     = inQuery.getColumn(1).getString();
    outField.value   = inQuery.getColumn(2).getString();
}

// -- LAYERS ------------------------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createLayer(const IW::Layer& inNewLayer)
{
    int64_t output;

    string tmpQuery{"INSERT INTO t_mission_comms_layer (" \
                              "name, description, sequence_number, default_flag, mission_name" \
                              ") values (?, ?, ?, ?, ?)"};

    

    SQLite::Statement   query(*this->db, tmpQuery);
    
    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewLayer.name);
    query.bind(2, inNewLayer.description);
    query.bind(3, inNewLayer.sequenceNumber);
    query.bind(4, inNewLayer.defaultFlag);
    query.bind(5, inNewLayer.missionName);        

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
            
            // Add the parameters
            if (inNewLayer.listParameters.is_null() == false) {
                for(IW::ConfigurationParameter  current: inNewLayer.listParameters.get_array()) {
                    createParameter(current);
                }
            }
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new mission. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    // It returns the new mission identifier
    return output;
}

IW::ListKeyValues ToolsDatabase::getLayerParameters(const string& inLayerName)
{
    IW::ListKeyValues output;

    if (inLayerName.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT l.identifier, c.name, c.value " \
                                  "FROM l.t_mission_comms_layer, c.t_configuration_parameters " \
                                  "WHERE l.name = ? AND l.identifier = c.layer_id");

        // Bind the first parameter
        query.bind(1, inLayerName);

        // We only retrieve the first value
        while (query.executeStep() == true)
        {
            IW::KeyValue  tmpParameter;

            // Name = Value
            tmpParameter.key     = query.getColumn(2).getString();
            tmpParameter.value   = query.getColumn(3).getString();

            output.listKeyValues.push_back(tmpParameter);
        }
    }

    return output;
}

IW::Layer ToolsDatabase::getLayerById(const string& inLayerName)
{
    IW::Layer output;

    if (inLayerName.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_mission_comms_layer WHERE name = ? ORDER BY sequence_number");

        if (inLayerName.empty() == false) {
            // Bind the first parameter
            query.bind(1, inLayerName);

            // We only retrieve the first value
            if (query.executeStep() == true)
            {
                extractLayer(query, output);
            }            
        } 
        else 
        {
            LogManager::getInstance().error("Layer name is empty");
        }
    }

    return output;
}

IW::ListLayers ToolsDatabase::getMissionLayers(const string& inMissionName)
{
    IW::ListLayers  output;

    SQLite::Statement   query(*this->db, "SELECT * FROM t_mission_comms_layer where mission_name = ? ORDER BY sequence_number");

    query.bind(1, inMissionName);

    while (query.executeStep() == true)
    {
        IW::Layer tmpLayer;

        extractLayer(query, tmpLayer);

        output.listLayers.push_back(tmpLayer);
    }

    return output;
}

IW::ListLayers ToolsDatabase::getDefaultMissionLayers()
{
    IW::ListLayers  output;

    SQLite::Statement   query(*this->db, "SELECT * FROM t_mission_comms_layer WHERE default_flag=1");

    while (query.executeStep() == true)
    {
        IW::Layer tmpLayer;

        extractLayer(query, tmpLayer);

        output.listLayers.push_back(tmpLayer);
    }

    return output;
}

void ToolsDatabase::removeLayer(const string& inLayerName)
{
    removeByName("t_mission_comms_layer", inLayerName);
}

void ToolsDatabase::extractLayer(SQLite::Statement &inQuery, IW::Layer& outLayer)
{
    outLayer.name             = inQuery.getColumn(0).getString();
    outLayer.description      = inQuery.getColumn(1).getString();
    outLayer.sequenceNumber   = inQuery.getColumn(2).getInt();
    outLayer.defaultFlag      = inQuery.getColumn(3).getInt();
    outLayer.missionName      = inQuery.getColumn(4).getString();
}

// -- FRAME TYPES, FIELD TYPES ------------------------------------
// ----------------------------------------------------------------

// Return all the frame definitions of a Layer
IW::TM_Frame ToolsDatabase::getFrameByName(const string &inFrameName)
{
    IW::TM_Frame output;

    if (inFrameName.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_frame WHERE name = ?");

        // Bind the first parameter
        query.bind(1, inFrameName);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            extractFrameDefinitionData(query, output);
            
            // Get conditions of a Frame
            std::vector<IW::TM_FrameCondition>   tmpConditions;
            
            getFrameConditions(output.name, tmpConditions);
            if (tmpConditions.size() > 0) {
                output.frameConditions.set_array(tmpConditions);
            }
            
            // Get parameters
            std::vector<IW::TM_FrameField>  tmpParameters;
            
            getFrameFieldTypes(output.name, tmpParameters);
            if (tmpParameters.size() > 0) {
                output.tmFields = tmpParameters;
            }
        }
        else
        {
            string tmpMessage = "TM Frame not found. Name: " + inFrameName;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());

            throw GSException(tmpMessage);
        }
    }

    return output;
}

// Return all the frame definitions of a Layer
IW::ListFrameTypes ToolsDatabase::getFrameTypesByLayer(const string& inLayerName)
{
    IW::ListFrameTypes output;

    if (inLayerName.empty() == false)
    {
        // Read the list of frames of the layer
        SQLite::Statement   query(*this->db, "SELECT * FROM t_frame_layer WHERE layer_name = ? ");
        
        // Bind the first parameter
        query.bind(1, inLayerName);
        
        // We only retrieve the first value
        while (query.executeStep() == true)
        {
            IW::TM_Frame  currentFrame;

            // Get Frame
            currentFrame = getFrameByName( query.getColumn(0) );
            
            // Add to the output
            output.listFrameTypes.push_back(currentFrame);
        }
    }
        
    return output;
}

void ToolsDatabase::getFrameFieldTypes(const string& inFrameName, std::vector<IW::TM_FrameField> &outParameters)
{
    SQLite::Statement query(*this->db, "SELECT * FROM t_tm_parameter WHERE frame_id = ?");
    
    query.bind(1, inFrameName);

    // We only retrieve the first value
    while(query.executeStep() == true) 
    {
        IW::TM_FrameField currentField;

        extractFrameFieldTypeData(query, currentField);
        
        // Add the fields to the frame
        outParameters.push_back(currentField);
    }
}


void ToolsDatabase::getFrameConditions(const string& inFrameName, std::vector<IW::TM_FrameCondition> &outConditions)
{
//    SQLite::Statement query(*this->db, "SELECT * FROM t_tm_parameter WHERE frame_id = ?");
//    
//    query.bind(1, inFrameName);
//
//    // We only retrieve the first value
//    while(query.executeStep() == true) 
//    {
//        IW::TM_FrameField currentField;
//
//        extractFrameFieldTypeData(query, currentField);
//        
//        // Add the fields to the frame
//        outParameters.push_back(currentField);
//    }

    string tmpMessage = "unimplemented method: getFrameConditions";
            
    LogManager::getInstance().error(tmpMessage);
    throw GSException(tmpMessage);    
}

int64_t ToolsDatabase::createTmFrame(const IW::TM_Frame& inNewTmFrame)
{
    string tmpMessage = "unimplemented method: createTmFrame";
            
    LogManager::getInstance().error(tmpMessage);
    throw GSException(tmpMessage);    
}


void ToolsDatabase::extractFrameDefinitionData(SQLite::Statement &inQuery, IW::TM_Frame& outFrame)
{   
    outFrame.name             = inQuery.getColumn(0).getString();
    outFrame.description      = inQuery.getColumn(1).getString();
    outFrame.expectedInterval = inQuery.getColumn(2).getInt();
    outFrame.lengthBits       = inQuery.getColumn(3).getInt();
    outFrame.flag             = static_cast<IW::TmFrameFlagEnum>(inQuery.getColumn(4).getInt());
    outFrame.layerName        = inQuery.getColumn(5).getInt();
    
}

void ToolsDatabase::extractFrameFieldTypeData(SQLite::Statement &inQuery, IW::TM_FrameField& outField)
{
    outField.frameName        = inQuery.getColumn(0).getString();
    outField.parameterName    = inQuery.getColumn(1).getString();
    outField.relativePosition = inQuery.getColumn(2).getInt();
    outField.sequenceNumber   = inQuery.getColumn(3).getInt();
}


// -- TM PARAMETER ------------------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createTmParameter(const IW::TM_Parameter& inNewParameter)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_tm_parameter (" \
                              "node_id, channel_id, name, display_name," \
                              "description, tm_type, length_field_id, length_bits, little_endian, " \
                              "type, subtype, radix, units, magnitude_type, function_id, crc_flag, crc_algorithm" \
                              ") values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewParameter.node);
    query.bind(2, inNewParameter.channel);
    query.bind(3, inNewParameter.name);
    query.bind(4, inNewParameter.displayName);
    query.bind(5, inNewParameter.description);
    //query.bind(6, inNewParameter.tmType);
    query.bind(7, inNewParameter.lengthFieldId);
    query.bind(8, inNewParameter.lengthBits);
    query.bind(9, inNewParameter.littleEndian);
    query.bind(10, inNewParameter.valueType);
    query.bind(11, inNewParameter.valueSubType);
    query.bind(12, inNewParameter.radix);
    query.bind(13, inNewParameter.units);

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
        
        // Insert Warning Limits
        //createTmParameterRange(0, output, inNewParameter.warningLimits);
        
        // Insert Error Limits
        //createTmParameterRange(1, output, inNewParameter.errorLimits);
    }
    else
    {
        string tmpMessage = "Unable to create new TM Parameter. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    return output;
}

int64_t ToolsDatabase::createTmParameterRange(const uint inRangeType, const int64_t inParameterId, const IW::Limit& inRange)
{
    int64_t output;
    
    SQLite::Statement   query(*this->db, "INSERT INTO t_tm_definition_range (" \
                              "status, counter, range_type, value_type, min_value, max_value, parameter_id" \
                              ") values (?, ?, ?, ?, ?, ?, ?)");

    // Status;      1 - Enabled, 0 - Disabled
    // Range type;  0 - Warning, 1 - Error

    // Bind the first parameter
    // Identifier it is auto generated
    // By default all range are active
    query.bind(1, 1);
    query.bind(2, inRange.counter);
    query.bind(3, inRangeType);
    query.bind(4, 0);
    query.bind(5, inRange.minValue);
    query.bind(6, inRange.maxValue);
    query.bind(7, static_cast<long long int>(inParameterId));

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new TM Parameter Range. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    return output;
}

void ToolsDatabase::removeTmParameter(const int64_t inId)
{
    removeById("t_tm_parameter", inId);
}

IW::TM_Parameter ToolsDatabase::getTmParameterById(const int64_t inId)
{
    IW::TM_Parameter output;

    // Get Frame Type
    SQLite::Statement query(*this->db, "SELECT * FROM t_tm_parameter WHERE identifier = ?");

    // Bind the first parameter
    query.bind(1, std::to_string(inId));

    // We only retrieve the first value
    if (query.executeStep() == true) 
    {
        extractTmParameterData(query, output);
        
        // Get limits
        //getTmParameterLimitData(inId, 0, output.warningLimits);
        //getTmParameterLimitData(inId, 1, output.errorLimits);        
    }
    else
    {
        string tmpMessage = "TM Parameter not found. Id: " + inId;
        LogManager::getInstance().error(tmpMessage);
        LogManager::getInstance().error(query.getErrorMsg());

        throw GSException(tmpMessage);
    }

    return output;
}

void ToolsDatabase::getTmParameterLimitData(const int64_t inId, const uint inLimitType, IW::Limit& outLimit)
{
    if (inLimitType == 0 || inLimitType == 1)
    {
        // Read ranges / limits
        SQLite::Statement queryLimits(*this->db, "SELECT * FROM t_tm_definition_range WHERE parameter_id = ? AND range_type = ?");

        queryLimits.bind(1, std::to_string(inId));
        // 0 - Warning, 1 - Error
        queryLimits.bind(2, inLimitType);

        if(queryLimits.executeStep() == true) 
        {
            outLimit.maxValue = queryLimits.getColumn(0).getDouble();
            outLimit.minValue = queryLimits.getColumn(1).getDouble();
        } 
        else 
        {
            string tmpMessage = "Limits for TM Parameter not found. Id: " + inId;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(queryLimits.getErrorMsg());            
            throw GSException(tmpMessage);
        }    
    }
}

void ToolsDatabase::extractTmParameterData(SQLite::Statement &inQuery, IW::TM_Parameter& outParameter)
{   
    outParameter.identifier       = inQuery.getColumn(0).getInt();
    //outParameter.parentIdentifier = inQuery.getColumn(1).getInt();
    outParameter.node             = inQuery.getColumn(2).getInt();
    outParameter.channel          = inQuery.getColumn(3).getInt();
    //outParameter.tmType           = static_cast<IW::TmTypeEnum>( inQuery.getColumn(4).getInt() );
    //outParameter.magnitudeType    = static_cast<IW::MagnitudeTypeEnum>( inQuery.getColumn(5).getInt() );
    outParameter.name             = inQuery.getColumn(6).getString();
    outParameter.displayName      = inQuery.getColumn(7).getString();
    outParameter.description      = inQuery.getColumn(8).getString();
    outParameter.lengthBits       = inQuery.getColumn(9).getInt();
    outParameter.littleEndian     = inQuery.getColumn(10).getInt();
    //outParameter.defaultValue     = inQuery.getColumn(11).getString();
    outParameter.units            = inQuery.getColumn(12).getString();
    outParameter.radix            = static_cast<IW::RadixEnum>( inQuery.getColumn(13).getInt() ); 
    //outParameter.valueType        = static_cast<IW::TmFieldTypeEnum>( inQuery.getColumn(14).getInt() );
    //outParameter.valueSubType     = static_cast<IW::TmFieldSubTypeEnum>( inQuery.getColumn(15).getInt() );;
    //outParameter.calibrationCoeffIdentifier = inQuery.getColumn(17).getInt();
}

int64_t ToolsDatabase::createTmDerivedParameter(const IW::Derived_TM_Parameter &inNewParameter)
{
    string tmpMessage = "unimplemented method: createTmDerivedParameter";
            
    LogManager::getInstance().error(tmpMessage);
    throw GSException(tmpMessage);
}


// -- TC PARAMETER ------------------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createTcParameter(const IW::TC_Parameter& inNewParameter)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_tc_parameter (" \
                              "name, display_name, description, node_id, length_bits, little_endian, " \
                              "type, subtype" \
                              ") values (?, ?, ?, ?, ?, ?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewParameter.name);
    query.bind(2, inNewParameter.displayName);
    query.bind(3, inNewParameter.description);
    query.bind(4, inNewParameter.parentName);
    query.bind(5, inNewParameter.node);
    query.bind(6, inNewParameter.channel);
    query.bind(7, inNewParameter.lengthBits);
    query.bind(8, inNewParameter.abstractFlag);
    query.bind(9, inNewParameter.subsystem);
    
    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = lastId;
        } catch(...)
        {
            // Do nothing
        }        
    }
    else
    {
        string tmpMessage = "Unable to create new TM Parameter. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    return output;
}

void ToolsDatabase::removeTcParameter(const int64_t inId)
{
    removeById("t_tc_parameter", inId);
}

IW::TC_Parameter ToolsDatabase::getTcParameterById(const int64_t inId)
{
    IW::TC_Parameter output;

    // Get Frame Type
    SQLite::Statement query(*this->db, "SELECT * FROM t_tc_parameter WHERE identifier = ?");

    // Bind the first parameter
    query.bind(1, std::to_string(inId));

    // We only retrieve the first value
    if (query.executeStep() == true) 
    {
        extractTcParameterData(query, output);       
    }
    else
    {
        string tmpMessage = "TC Parameter not found. Id: " + inId;
        LogManager::getInstance().error(tmpMessage);
        LogManager::getInstance().error(query.getErrorMsg());

        throw GSException(tmpMessage);
    }

    return output;
}

void ToolsDatabase::extractTcParameterData(SQLite::Statement &inQuery, IW::TC_Parameter& outParameter)
{
    outParameter.identifier        = inQuery.getColumn(0).getInt();
    outParameter.name              = inQuery.getColumn(1).getString();
    outParameter.displayName       = inQuery.getColumn(2).getString();
    outParameter.description       = inQuery.getColumn(3).getString();
    outParameter.parentName        = inQuery.getColumn(4).getString();
    outParameter.node              = inQuery.getColumn(5).getInt();
    outParameter.channel           = inQuery.getColumn(6).getInt();
    outParameter.lengthBits        = inQuery.getColumn(7).getInt();
    outParameter.abstractFlag      = inQuery.getColumn(8).getInt();
    outParameter.subsystem         = inQuery.getColumn(9).getString();
}    

// -- CALIBRATION FUNCTION ----------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createCalibration(const IW::Calibration& inNewCalibration)
{
    string tmpMessage = "unimplemented method: createCalibration";
            
    LogManager::getInstance().error(tmpMessage);
    throw GSException(tmpMessage);
}


// -- ALGORITHM FUNCTION ----------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createAlgorithm(const IW::Algorithm& inNewAlgorithm)
{
    string tmpMessage = "unimplemented method: createAlgorithm";
            
    LogManager::getInstance().error(tmpMessage);
    throw GSException(tmpMessage);    
}

// -- ALARM FUNCTION ----------------------------------------
// ----------------------------------------------------------------

int64_t ToolsDatabase::createAlarm(const IW::Alarm& inNewAlarm)
{
    string tmpMessage = "unimplemented method: createAlarm";
            
    LogManager::getInstance().error(tmpMessage);
    throw GSException(tmpMessage);    
}



// -- GENERIC ---------------------------------------------------
// ----------------------------------------------------------------

void ToolsDatabase::removeById(const string& inTableName, const int64_t inId)
{
    if (inId > 0)
    {
        string tmpTextSQL = "DELETE FROM " + inTableName + " WHERE identifier = ?";
        SQLite::Statement   query(*this->db, tmpTextSQL);

        // Bind parameters
        query.bind(1, std::to_string(inId));

        // We only retrieve the first value
        if (query.exec() == 0)
        {
            string tmpMessage = "Item not found. Id: " + std::to_string(inId) + " in table: " + inTableName;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());            
            throw GSException(tmpMessage);
        }
    }
}

void ToolsDatabase::removeByName(const string& inTableName, const string& inId)
{
    if (inId.empty() == false)
    {
        string tmpTextSQL = "DELETE FROM " + inTableName + " WHERE name = ?";
        SQLite::Statement   query(*this->db, tmpTextSQL);

        // Bind parameters
        query.bind(1, inId);

        // We only retrieve the first value
        if (query.exec() == 0)
        {
            string tmpMessage = "Item not found. Name: " + inId + " in table: " + inTableName;
            
            LogManager::getInstance().error(tmpMessage);
            LogManager::getInstance().error(query.getErrorMsg());            
            throw GSException(tmpMessage);
        }
    }
}

void ToolsDatabase::removeAll(const string& inTableName)
{
    string tmpTextSQL = "DELETE FROM " + inTableName;
    SQLite::Statement   query(*this->db, tmpTextSQL);

    query.exec();
}
