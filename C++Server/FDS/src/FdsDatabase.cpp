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

#include "FdsDatabase.h"




FdsDatabase::FdsDatabase()
    : db{}
{
}

FdsDatabase::~FdsDatabase()
{
}

void FdsDatabase::open()
{
    auto dbName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_FDS_DATABASE);
    
    open(dbName);
}

void FdsDatabase::open(const string &inDbName)
{
    if (inDbName.empty() == false) 
    {
        LogManager::getInstance().info("Opening Fds database: " + inDbName );

        shared_ptr<SQLite::Database> tmpDB{ new SQLite::Database(inDbName, SQLite::OPEN_READWRITE) };

        db = std::move(tmpDB);        
    } 
    else 
    {
        string tmpMessage = "Fds database name is empty";
        
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

// -- LOG  ---------------------------------------------------
// ----------------------------------------------------------------


int64_t FdsDatabase::addMessage(const uint64_t& inTimestamp, const uint8_t inLevel, const string& inMessage, const string& inSource, 
    const string& inWorkspace, const string& inModule)
{
    int64_t output;

    SQLite::Statement   query(*this->db, "INSERT INTO t_log_message (" \
                              "date, time, level, message, source, workspace, module" \
                              ") values (?, ?, ?, ?, ?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, static_cast<long long>(inTimestamp));
    query.bind(2, static_cast<long long>(inTimestamp));
    query.bind(3, inLevel);
    query.bind(4, inMessage);
    query.bind(5, inSource);
    query.bind(6, inWorkspace);
    query.bind(7, inModule);

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
        string tmpMessage = "Unable to add new Log message. SQL Error: " + string{query.getErrorMsg()};
        
        LogManager::getInstance().error(tmpMessage);
        throw GSException(tmpMessage);
    }

    return output;
}

// TODO
IW::FdsModule FdsDatabase::getModuleByName(const string& inModuleName)
{
    IW::FdsModule  output;
    
    return output;
}