/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __TOOLS_DATABASE_H__
#define __TOOLS_DATABASE_H__

#include <vector>
#include <memory>
#include <string>

using namespace std;

#include "SQLiteCpp/Database.h"

#include "AvroTypes.h"



class ToolsDatabase
{
public:
    // Singleton
    static ToolsDatabase& getInstance()
    {
        static ToolsDatabase instance;

        return instance;
    }

    virtual ~ToolsDatabase();

    void open();
    void open(const string &inDbName);

    // Mission
    // ------------------------------------------------------
    int64_t createMission(const IW::Mission& inNewMission);
    void removeMission(const string& inId);
    void updateMission(const IW::Mission &inMission);
    IW::Mission getMissionByName(const string &inName);
    vector<IW::Mission> getMissions();

    // Satellite
    // ------------------------------------------------------
    int64_t createSatellite(const IW::Satellite& inNewSatellite);
    void removeSatellite(const string& inId);
    void updateSatellite(const IW::Satellite &inSatellite);
    IW::Satellite getSatelliteByName(const string& inMissionName, const string &inName);
    IW::Satellite getSatelliteByCode(const string& inMissionName, const string &inCode);
    vector<IW::Satellite> getSatellites(string& inMissionName);
    
    // Subsystem
    // -------------------------------------------------------
    int64_t createSubsystem(const IW::Subsystem& inNewSubsystem);
    void removeSubsystem(const string& inId);
    void updateSubsystem(const IW::Subsystem &inSubsystem);
    IW::Subsystem getSubsystemByName(const string& inSatelliteName, const string& inName);
    vector<IW::Subsystem> getSubsystemsBySatellite(const string& inSatellite);
    vector<IW::Subsystem> getSubsystems();

    // Node
    // -------------------------------------------------------
    int64_t createNode(const IW::Node& inNewNode);
    void removeNode(const int64_t inId);
    IW::Node getNodeById(const int64_t inId);
    vector<IW::Node> getNodes();
   
    // Layers
    // ------------------------------------------------------
    int64_t createLayer(const IW::Layer& inNewLayer);
    IW::Layer getLayerById(const string& inLayerName);
    IW::ListKeyValues getLayerParameters(const string& inLayerName);
    IW::ListLayers getMissionLayers(const string& inMissionName);
    IW::ListLayers getDefaultMissionLayers();
    void removeLayer(const string& inLayerName);
    
    // TM Parameters
    // ------------------------------------------------------
    int64_t createTmParameter(const IW::TM_Parameter &inNewParameter);
    int64_t createTmParameterRange(const uint inRangeType, const int64_t inParameterId, const IW::Limit& inRange);
    void removeTmParameter(const int64_t inId);
    IW::TM_Parameter getTmParameterById(const int64_t inId);
    
    int64_t createTmDerivedParameter(const IW::Derived_TM_Parameter &inNewParameter);
    
    // TC Parameters
    // ------------------------------------------------------
    int64_t createTcParameter(const IW::TC_Parameter &inNewParameter);    
    void removeTcParameter(const int64_t inId);
    IW::TC_Parameter getTcParameterById(const int64_t inId);

 
    // Users
    // ------------------------------------------------------
    int64_t createUser(const string& inUserName, const string& inHashPassword,
                       const string& inFirstName, const string& inLastName, 
                       const string& inEmailAddress,
                       const string& inMissionName, const int32_t& inRoleId);
                       
    int64_t createUser(const IW::User& inUser);


    IW::User getUserById(const int64_t inId);    
    IW::User getUserByName(const string &inName);


    // Configuration parameters
    // ------------------------------------------------------
    int64_t createParameter(const IW::ConfigurationParameter &inNewParameter);  
    IW::ListKeyValues getMissionParameters(const string &inId);
    IW::ListKeyValues getUserParameters(const string &inId);
    
    // Frame Types = Container
    // ------------------------------------------------------
    IW::ListFrameTypes getFrameTypesByLayer(const string& inLayerName);
    IW::TM_Frame getFrameByName(const string &inFrameName);
    
    int64_t createTmFrame(const IW::TM_Frame& inNewTmFrame);
    
    // Calibration
    // ------------------------------------------------------
    int64_t createCalibration(const IW::Calibration& inNewCalibration);
    
    // Algorithm
    // ------------------------------------------------------
    int64_t createAlgorithm(const IW::Algorithm& inNewAlgorithm);

    // Alarm
    // ------------------------------------------------------
    int64_t createAlarm(const IW::Alarm& inNewAlarm);
        
    

protected:
    shared_ptr<SQLite::Database> db;

    ToolsDatabase();

    void removeById(const string& inTableName, const int64_t inId);
    void removeByName(const string& inTableName, const string& inId);
    void removeAll(const string& inTableName);

    void extractMissionData(SQLite::Statement &inQuery, IW::Mission& outMission);

    void extractSatelliteData(SQLite::Statement &inQuery, IW::Satellite& outSatellite);

    void extractUserData(SQLite::Statement &inQuery, IW::User& outUser);

    void extractFrameDefinitionData(SQLite::Statement &inQuery, IW::TM_Frame& outFrame);

    void extractFrameFieldTypeData(SQLite::Statement &inQuery, IW::TM_FrameField& outField);
    
    void extractParameters(SQLite::Statement &inQuery, IW::KeyValue& outField);
            
    void getFrameConditions(const string& inFrameName, std::vector<IW::TM_FrameCondition>& outConditions);

    void getFrameFieldTypes(const string& inFrameName, std::vector<IW::TM_FrameField> &outParameters);
    
    void getTMFields(std::vector<IW::TM_FrameField >& inFrameFields, std::vector<IW::TM_Parameter> &outVector);
    
    void getTCFields(std::vector<IW::TM_FrameField >& inFrameFields, std::vector<IW::TC_Parameter> &outVector);
    
    void extractTmParameterData(SQLite::Statement &inQuery, IW::TM_Parameter& outParameter);

    void extractTcParameterData(SQLite::Statement &inQuery, IW::TC_Parameter& outParameter);
    void getTmParameterLimitData(const int64_t inId, const uint inLimitType, IW::Limit& outLimit);
    
    void extractNodeData(SQLite::Statement &inQuery, IW::Node& outNode);
    
    void extractSubsystemData(SQLite::Statement &inQuery, IW::Subsystem& outSubsystem);

    void extractLayer(SQLite::Statement &inQuery, IW::Layer& outLayer);

};

#endif // __TOOLS_DATABASE_H__
