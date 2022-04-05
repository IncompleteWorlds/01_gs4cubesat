/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iostream>
#include <string>


#include "EventTypeEnum.h"
#include "Constants.h"
#include "GSException.h"
#include "ConfigurationManager.h"

#include "SQLiteCpp/Statement.h"

#include "ArchiveDatabase.h"

using namespace std;



ArchiveDatabase::ArchiveDatabase()
    : db{}
{
}

ArchiveDatabase::~ArchiveDatabase()
{
}

void ArchiveDatabase::open()
{
    auto dbName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_ARCHIVE_DATABASE);

    cout << "INFO: Opening TM Archive database: " << dbName << endl;

    shared_ptr<SQLite::Database> tmpDB{ new SQLite::Database(dbName, SQLite::OPEN_READWRITE) };

    db = std::move(tmpDB);


    // TODO: Check if tables exist, if not, create them
//    if (db->tableExists(GS_MANAGER_DB_NAME) == false)
//    {
//        // Create the table
//    }

//    string tmpCreateStatement = "CREATE TABLE ground_stations (" \
//    "    'identifier'	TEXT," \
//    "    'name'	TEXT NOT NULL," \
//    "    'description'	TEXT," \
//    "    'code'	TEXT NOT NULL," \
//    "    'owner'	TEXT," \
//    "    PRIMARY KEY(identifier)" \
//    ")";
    /*
     * CREATE TABLE `ground_station` (
    `identifier`	INTEGER PRIMARY KEY AUTOINCREMENT,
    `name`	TEXT NOT NULL,
    `description`	TEXT,
    `code`	TEXT NOT NULL,
    `owner`	TEXT,
    `latitude`	DOUBLE NOT NULL,
    `longitude`	DOUBLE NOT NULL,
    `altitude`	DOUBLE NOT NULL,
    `connectionType`	INTEGER,
    `url`	TEXT,
    `port`	INTEGER,
    `comPort`	TEXT,
    `speed`	INTEGER,
    `parity`	BOOLEAN,
    `controlBits`	INTEGER
);
*/

//    SQLite::Statement   query(this->db, tmpCreateStatement);

    // SELECT name FROM sqlite_master WHERE type='table' AND name='table_name';

    //create table if not exists TableName (col1 typ1, ..., colN typN)
    // drop table if exists TableName
}

// Create a new event that contains either a raw frame or a processed frame
/*
 * struct Event {
    int32_t type;
    int64_t eventTime;
    std::vector<uint8_t> data;
    int32_t dataLength;

 */
void ArchiveDatabase::create(IW::Event& inEvent)
{
    SQLite::Statement   query(*this->db, "INSERT INTO t_raw_frame" \
                              "(event_time, data_length, data)" \
                              "values (?, ?, ?)");

    string tableName{"raw_frame"};

    if (inEvent.type == static_cast<int>(EventTypeEnum::EVT_NEW_PROCESSED_FRAME))
    {
        tableName = "processed_frame";
    }

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, static_cast<long long int>(inEvent.eventTime));
    query.bind(2, inEvent.dataLength);
    query.bind(3, static_cast<void*>(inEvent.data.data()), inEvent.data.size());


    if (query.exec() == 0)
    {
        string tmpMessage = "Unable to create new event";
        cout << "ERROR: " << tmpMessage << endl;
        cout << "SQL ERROR: " << query.getErrorMsg() << endl;
        throw GSException(tmpMessage);
    }
}

