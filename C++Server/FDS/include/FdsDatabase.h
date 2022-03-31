/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __FDS_DATABASE_H__
#define __FDS_DATABASE_H__

#include <vector>
#include <memory>
#include <string>

using namespace std;

#include "SQLiteCpp/Database.h"

#include "AvroTypes.h"



class FdsDatabase
{
public:
    // Singleton
    static FdsDatabase& getInstance()
    {
        static FdsDatabase instance;

        return instance;
    }

    virtual ~FdsDatabase();

    void open();
    void open(const string &inDbName);
    
    // Event / Log Messages
    // ------------------------------------------------------
    int64_t addMessage(const uint64_t &inTimestamp, const uint8_t inLevel, const string &inMessage, 
                       const string &inSource, const string &inWorkspace, const string &inModule);
                       
    IW::FdsModule getModuleByName(const string& inModuleName);


protected:
    shared_ptr<SQLite::Database> db;

    FdsDatabase();
};

#endif // __FDS_DATABASE_H__
