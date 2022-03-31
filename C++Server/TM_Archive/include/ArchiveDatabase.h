/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __ARCHIVE_DATABASE_H__
#define __ARCHIVE_DATABASE_H__


#include <vector>
#include <memory>

using namespace std;

#include "SQLiteCpp/Database.h"

#include "AvroTypes.h"



class ArchiveDatabase
{
public:
    // Singleton
    static ArchiveDatabase& getInstance()
    {
        static ArchiveDatabase instance;

        return instance;
    }

    virtual ~ArchiveDatabase();

    void open();

    // Create a new record containing either a raw frame or a processed frame
    // Frames are stored as a sequence of bytes
    void create(IW::Event& inEvent);


protected:
    shared_ptr<SQLite::Database> db;

    ArchiveDatabase();
};


#endif // ARCHIVEDATABASE_H
