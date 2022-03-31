/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include <iostream>
#include <string>


#include "Constants.h"
#include "GSException.h"
#include "ConfigurationManager.h"

#include "SQLiteCpp/Statement.h"

#include "GsDatabase.h"

using namespace std;



GsDatabase::GsDatabase()
    : db{}
{
}

GsDatabase::~GsDatabase()
{
}

void GsDatabase::open()
{
    auto dbName = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GS_MANAGER_DATABASE);

    cout << "INFO: Opening GS Manager database: " << dbName << endl;

    shared_ptr<SQLite::Database> tmpDB{ new SQLite::Database(dbName, SQLite::OPEN_READWRITE) };

    db = std::move(tmpDB);


    // TODO: Check if tables exist, if not, create them
//    if (db->tableExists(GS_MANAGER_DB_NAME) == false)
//    {
//        // Create the table
//    }

//    string tmpCreateStatement = "CREATE TABLE t_ground_stations (" \
//    "    'identifier'	TEXT," \
//    "    'name'	TEXT NOT NULL," \
//    "    'description'	TEXT," \
//    "    'code'	TEXT NOT NULL," \
//    "    'owner'	TEXT," \
//    "    PRIMARY KEY(identifier)" \
//    ")";
    /*
     * CREATE TABLE `t_ground_station` (
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

/**
 * @brief GsDatabase::create
 * It will return the identifier of the created G/S
 * @param inNewGS
 * @return
 */
string GsDatabase::create(const IW::GroundStation& inNewGS)
{
    string output{""};

    SQLite::Statement   query(*this->db, "INSERT INTO t_ground_station" \
                              "('name', 'description', 'code', 'owner', 'latitude', " \
                              "'longitude', 'altitude', 'connectionType', 'url', 'port'," \
                              "'comPort', 'speed', 'parity', 'controlBits')" \
                              "values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    // Bind the first parameter
    // Identifier it is auto generated
    query.bind(1, inNewGS.name);
    query.bind(2, inNewGS.description);
    query.bind(3, inNewGS.code);
    query.bind(4, inNewGS.owner);
    query.bind(5, inNewGS.latitude);
    query.bind(6, inNewGS.longitude);
    query.bind(7, inNewGS.altitude);
    query.bind(8, static_cast<int>(inNewGS.connectionType));
    query.bind(9, inNewGS.url);
    query.bind(10, inNewGS.port);
    query.bind(11, inNewGS.comPort);
    query.bind(12, inNewGS.speed);
    query.bind(13, inNewGS.parity);
    query.bind(14, inNewGS.controlBits);

    if (query.exec() == 1)
    {
        long long int lastId = db->getLastInsertRowid();

        try
        {
            output = to_string(lastId);
        } catch(...)
        {
            // Do nothing
        }
    }
    else
    {
        string tmpMessage = "Unable to create new ground station";
        cout << "ERROR: " << tmpMessage << endl;
        cout << "SQL ERROR: " << query.getErrorMsg() << endl;
        throw GSException(tmpMessage);
    }

    return output;
}

void GsDatabase::remove(const int64_t &inGsId)
{
    SQLite::Statement   query(*this->db, "DELETE FROM t_ground_station WHERE identifier = ?");

    // Bind the first parameter
    query.bind(1, std::to_string(inGsId));

    // We only retrieve the first value
    if (query.exec() == 0)
    {
        string tmpMessage = "Ground station not found. Id: " + inGsId;
        cout << "ERROR: " << tmpMessage << endl;
        cout << "SQL ERROR: " << query.getErrorMsg() << endl;
        throw GSException(tmpMessage);
    }
}

void GsDatabase::update(const IW::GroundStation &inStation)
{
    remove(inStation.identifier);

    create(inStation);
}

IW::GroundStation GsDatabase::getById(const string &inGsId)
{
    IW::GroundStation output;

    if (inGsId.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_ground_station WHERE identifier = ?");

        // Bind the first parameter
        query.bind(1, inGsId);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            output = extractData(query);
        }
        else
        {
            string tmpMessage = "Ground station not found. Id: " + inGsId;
            cout << "ERROR: " << tmpMessage << endl;
            cout << "SQL ERROR: " << query.getErrorMsg() << endl;
            throw GSException(tmpMessage);
        }
    }

    return output;
}

IW::GroundStation GsDatabase::getByCode(const string &inGsCode)
{
    IW::GroundStation output;

    if (inGsCode.empty() == false)
    {
        SQLite::Statement   query(*this->db, "SELECT * FROM t_ground_station WHERE code = ?");

        // Bind the first parameter
        query.bind(1, inGsCode);

        // We only retrieve the first value
        if (query.executeStep() == true)
        {
            output = extractData(query);
        }
        else
        {
            string tmpMessage = "Ground station not found. Code: " + inGsCode;
            cout << "ERROR: " << tmpMessage << endl;
            cout << "SQL ERROR: " << query.getErrorMsg() << endl;
            throw GSException(tmpMessage);
        }
    }

    return output;
}

vector<IW::GroundStation> GsDatabase::getAll()
{
    vector<IW::GroundStation>  output;

    SQLite::Statement   query(*this->db, "SELECT * FROM t_ground_station");

    // We only retrieve the first value
    while (query.executeStep() == true)
    {
        IW::GroundStation tmpStation = extractData(query);

        output.push_back(tmpStation);
    }

    return output;
}


IW::GroundStation GsDatabase::extractData(SQLite::Statement &inQuery)
{
    IW::GroundStation output;

    output.identifier = inQuery.getColumn(0).getInt();
    output.name = inQuery.getColumn(1).getString();
    output.description = inQuery.getColumn(2).getString();
    output.code = inQuery.getColumn(3).getString();
    output.owner = inQuery.getColumn(4).getString();
    // Position
    output.latitude = inQuery.getColumn(5).getDouble();
    output.longitude = inQuery.getColumn(6).getDouble();
    output.altitude = inQuery.getColumn(7).getDouble();

    // Connection details
    output.connectionType = static_cast<IW::ConnectionTypeEnum>(inQuery.getColumn(8).getInt());

    // TCP connection parameters
    output.url = inQuery.getColumn(9).getString();
    output.port = inQuery.getColumn(10).getInt();

    // Serial connection parameters
    output.comPort = inQuery.getColumn(11).getString();
    output.speed = inQuery.getColumn(12).getInt();
    output.parity = inQuery.getColumn(13).getInt();
    output.controlBits = inQuery.getColumn(14).getInt();

    return output;
}
