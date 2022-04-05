/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __GS_DATABASE_H__
#define __GS_DATABASE_H__

#include <vector>
#include <memory>

using namespace std;

#include "SQLiteCpp/Database.h"

#include "AvroTypes.h"



class GsDatabase
{
public:
    // Singleton
    static GsDatabase& getInstance()
    {
        static GsDatabase instance;

        return instance;
    }

    virtual ~GsDatabase();

    void open();

    string create(const IW::GroundStation& inNewGS);

    void remove(const int64_t &inGsId);

    void update(const IW::GroundStation &inStation);

    IW::GroundStation getById(const string &inGsId);

    IW::GroundStation getByCode(const string &inGsCode);

    vector<IW::GroundStation> getAll();

protected:
    shared_ptr<SQLite::Database> db;

    GsDatabase();

    IW::GroundStation extractData(SQLite::Statement &inQuery);
};

#endif // __GS_DATABASE_H__
