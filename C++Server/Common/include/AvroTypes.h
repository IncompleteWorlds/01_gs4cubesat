/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef AVROTYPES_H_2613985595__H_
#define AVROTYPES_H_2613985595__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace IW {
enum TmTypeEnum {
    TM_TYPE_NONE,
    TM_TYPE_BOOLEAN,
    TM_TYPE_ENUMERATED,
    TM_TYPE_UNSIGNED_INTEGER,
    TM_TYPE_SIGNED_INTEGER,
    TM_TYPE_DOUBLE,
    TM_TYPE_BIT_STRING,
    TM_TYPE_OCTET_STRING,
    TM_TYPE_STRING,
    TM_TYPE_ABSOLUTE_DATE,
    TM_TYPE_RELATIVE_TIME,
    TM_TYPE_DEDUCED,
    TM_TYPE_FIXED_STRING,
    TM_TYPE_TERMINATE_STRING,
    TM_TYPE_PREPEND_STRING,
    TM_TYPE_BYTE_STREAM,
};

enum TmSubTypeEnum {
    TM_SUBTYPE_NONE,
    TM_SUBTYPE_INT8,
    TM_SUBTYPE_INT16,
    TM_SUBTYPE_INT32,
    TM_SUBTYPE_INT64,
    TM_SUBTYPE_UINT8,
    TM_SUBTYPE_UINT16,
    TM_SUBTYPE_UINT32,
    TM_SUBTYPE_UINT64,
};

enum TmEngTypeEnum {
    TM_ENGTYPE_NONE,
    TM_ENGTYPE_UNSIGNED_INTEGER,
    TM_ENGTYPE_UNSIGNED_INTEGER64,
    TM_ENGTYPE_SIGNED_INTEGER,
    TM_ENGTYPE_SIGNED_INTEGER64,
    TM_ENGTYPE_ENUMERATED,
    TM_ENGTYPE_FLOAT,
    TM_ENGTYPE_DOUBLE,
    TM_ENGTYPE_BOOLEAN,
    TM_ENGTYPE_STRING,
    TM_ENGTYPE_BINARY,
};

enum RadixEnum {
    RADIX_NONE,
    RADIX_DECIMAL,
    RADIX_HEXADECIMAL,
};

enum ModuleTypeEnum {
    EXTERNAL_MODULE,
    INTERNAL_MODULE,
};

struct Subsystem {
    std::string name;
    std::string description;
    std::string satelliteName;
    Subsystem() :
        name(std::string()),
        description(std::string()),
        satelliteName(std::string())
        { }
};

struct AvroTypes_proc_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<Subsystem > get_array() const;
    void set_array(const std::vector<Subsystem >& v);
    AvroTypes_proc_Union__0__();
};

struct Satellite {
    typedef AvroTypes_proc_Union__0__ listSubsystems_t;
    std::string name;
    std::string missionName;
    std::string description;
    std::string code;
    std::string launchDate;
    listSubsystems_t listSubsystems;
    Satellite() :
        name(std::string()),
        missionName(std::string()),
        description(std::string()),
        code(std::string()),
        launchDate(std::string()),
        listSubsystems(listSubsystems_t())
        { }
};

struct AvroTypes_proc_Union__1__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<Satellite > get_array() const;
    void set_array(const std::vector<Satellite >& v);
    AvroTypes_proc_Union__1__();
};

struct Mission {
    typedef AvroTypes_proc_Union__1__ listSatellites_t;
    std::string name;
    std::string description;
    std::string country;
    std::string owner;
    std::string creationTime;
    int32_t adminIdentifier;
    std::string emailAddress;
    std::string phoneNumber;
    listSatellites_t listSatellites;
    Mission() :
        name(std::string()),
        description(std::string()),
        country(std::string()),
        owner(std::string()),
        creationTime(std::string()),
        adminIdentifier(int32_t()),
        emailAddress(std::string()),
        phoneNumber(std::string()),
        listSatellites(listSatellites_t())
        { }
};

enum WatchTriggerTypeEnum {
    Low,
    High,
    State,
};

enum AlarmReportTypeEnum {
    ALARM_REPORT_ON_VALUE_CHANGE,
    ALARM_REPORT_ON_SEVERITY_CHANGE,
};

struct AlarmContext {
    std::string parameterName;
    AlarmReportTypeEnum reportType;
    int32_t minimumViolations;
    WatchTriggerTypeEnum watchTriggerType;
    std::string watchTriggerValue;
    WatchTriggerTypeEnum warningTriggerType;
    std::string warningTriggerValue;
    WatchTriggerTypeEnum distressTriggerType;
    std::string distressTriggerValue;
    WatchTriggerTypeEnum criticalTriggerType;
    std::string criticalTriggerValue;
    WatchTriggerTypeEnum severeTriggerType;
    std::string severeTriggerValue;
    AlarmContext() :
        parameterName(std::string()),
        reportType(AlarmReportTypeEnum()),
        minimumViolations(int32_t()),
        watchTriggerType(WatchTriggerTypeEnum()),
        watchTriggerValue(std::string()),
        warningTriggerType(WatchTriggerTypeEnum()),
        warningTriggerValue(std::string()),
        distressTriggerType(WatchTriggerTypeEnum()),
        distressTriggerValue(std::string()),
        criticalTriggerType(WatchTriggerTypeEnum()),
        criticalTriggerValue(std::string()),
        severeTriggerType(WatchTriggerTypeEnum()),
        severeTriggerValue(std::string())
        { }
};

struct Alarm {
    std::string parameterName;
    std::vector<AlarmContext > listAlarmContext;
    Alarm() :
        parameterName(std::string()),
        listAlarmContext(std::vector<AlarmContext >())
        { }
};

struct AlgorithmParameter {
    std::string algorithmName;
    std::string parameterName;
    std::string parameterValue;
    int32_t inputOutputType;
    std::string nameInAlgorithm;
    bool mandatoryFlag;
    std::string subsystem;
    AlgorithmParameter() :
        algorithmName(std::string()),
        parameterName(std::string()),
        parameterValue(std::string()),
        inputOutputType(int32_t()),
        nameInAlgorithm(std::string()),
        mandatoryFlag(bool()),
        subsystem(std::string())
        { }
};

enum AlgorithmLanguageEnum {
    ALGORITHM_JAVASCRIPT,
    ALGORITHM_PYTHON,
    ALGORITHM_JAVA,
};

enum TriggerEnum {
    ALGORITHM_TRIGGER_NONE,
    ALGORITHM_ON_PARAMETER_UPDATE,
    ALGORITHM_ON_INPUT_PARAMETER_UPDATE,
    ALGORITHM_ON_PERIODIC_RATE,
};

struct Algorithm {
    std::string algorithmName;
    AlgorithmLanguageEnum algorithmLanguage;
    std::string sourceCode;
    TriggerEnum trigger;
    std::vector<AlgorithmParameter > listAlgVariables;
    std::string subsystem;
    Algorithm() :
        algorithmName(std::string()),
        algorithmLanguage(AlgorithmLanguageEnum()),
        sourceCode(std::string()),
        trigger(TriggerEnum()),
        listAlgVariables(std::vector<AlgorithmParameter >()),
        subsystem(std::string())
        { }
};

struct CalibrationItem {
    std::string calibration1;
    std::string calibration2;
    std::string calibration2_text;
    CalibrationItem() :
        calibration1(std::string()),
        calibration2(std::string()),
        calibration2_text(std::string())
        { }
};

enum TmCalibrationTypeEnum {
    TM_CALIBRATION_ENUMERATION,
    TM_CALIBRATION_POLYNOMIAL,
    TM_CALIBRATION_SPLINE,
    TM_CALIBRATION_EXPRESSION,
};

struct Calibration {
    std::string name;
    std::string description;
    TmCalibrationTypeEnum calibrationType;
    std::string subsystem;
    std::vector<CalibrationItem > listCalibrationItems;
    Calibration() :
        name(std::string()),
        description(std::string()),
        calibrationType(TmCalibrationTypeEnum()),
        subsystem(std::string()),
        listCalibrationItems(std::vector<CalibrationItem >())
        { }
};

struct ConfigurationParameter {
    int32_t identifier;
    std::string name;
    std::string description;
    int32_t type;
    std::string value;
    int32_t userId;
    std::string missionName;
    std::string layerName;
    ConfigurationParameter() :
        identifier(int32_t()),
        name(std::string()),
        description(std::string()),
        type(int32_t()),
        value(std::string()),
        userId(int32_t()),
        missionName(std::string()),
        layerName(std::string())
        { }
};

struct Derived_TM_Parameter {
    int32_t identifier;
    std::string name;
    std::string displayName;
    std::string description;
    int32_t lengthBits;
    int32_t prependSize;
    std::string stringTerminator;
    bool littleEndian;
    TmTypeEnum valueType;
    TmSubTypeEnum valueSubType;
    TmEngTypeEnum engType;
    std::string units;
    std::string calibrationFunction;
    std::string subsystem;
    Derived_TM_Parameter() :
        identifier(int32_t()),
        name(std::string()),
        displayName(std::string()),
        description(std::string()),
        lengthBits(int32_t()),
        prependSize(int32_t()),
        stringTerminator(std::string()),
        littleEndian(bool()),
        valueType(TmTypeEnum()),
        valueSubType(TmSubTypeEnum()),
        engType(TmEngTypeEnum()),
        units(std::string()),
        calibrationFunction(std::string()),
        subsystem(std::string())
        { }
};

struct Event {
    int32_t type;
    int64_t eventTime;
    std::vector<uint8_t> data;
    int32_t dataLength;
    Event() :
        type(int32_t()),
        eventTime(int64_t()),
        data(std::vector<uint8_t>()),
        dataLength(int32_t())
        { }
};

struct FdsModule {
    int32_t identifier;
    std::string name;
    std::string description;
    ModuleTypeEnum type;
    std::string binary_file;
    FdsModule() :
        identifier(int32_t()),
        name(std::string()),
        description(std::string()),
        type(ModuleTypeEnum()),
        binary_file(std::string())
        { }
};

enum ConnectionTypeEnum {
    NONE,
    TCP,
    SERIAL,
    USB,
};

struct GroundStation {
    int32_t identifier;
    std::string name;
    std::string description;
    std::string code;
    std::string owner;
    float latitude;
    float longitude;
    float altitude;
    ConnectionTypeEnum connectionType;
    std::string url;
    int32_t port;
    std::string comPort;
    float speed;
    float parity;
    float controlBits;
    GroundStation() :
        identifier(int32_t()),
        name(std::string()),
        description(std::string()),
        code(std::string()),
        owner(std::string()),
        latitude(float()),
        longitude(float()),
        altitude(float()),
        connectionType(ConnectionTypeEnum()),
        url(std::string()),
        port(int32_t()),
        comPort(std::string()),
        speed(float()),
        parity(float()),
        controlBits(float())
        { }
};

struct KeyValue {
    std::string key;
    std::string value;
    KeyValue() :
        key(std::string()),
        value(std::string())
        { }
};

struct AvroTypes_proc_Union__2__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<ConfigurationParameter > get_array() const;
    void set_array(const std::vector<ConfigurationParameter >& v);
    AvroTypes_proc_Union__2__();
};

struct Layer {
    typedef AvroTypes_proc_Union__2__ listParameters_t;
    int32_t identifier;
    std::string name;
    std::string description;
    int32_t sequenceNumber;
    bool defaultFlag;
    std::string missionName;
    listParameters_t listParameters;
    Layer() :
        identifier(int32_t()),
        name(std::string()),
        description(std::string()),
        sequenceNumber(int32_t()),
        defaultFlag(bool()),
        missionName(std::string()),
        listParameters(listParameters_t())
        { }
};

struct Node {
    int32_t identifier;
    std::string name;
    std::string description;
    std::string subsystemName;
    Node() :
        identifier(int32_t()),
        name(std::string()),
        description(std::string()),
        subsystemName(std::string())
        { }
};

struct Pass {
    int32_t identifier;
    std::string AOS;
    std::string LOS;
    int32_t duration;
    float maxElevation;
    Pass() :
        identifier(int32_t()),
        AOS(std::string()),
        LOS(std::string()),
        duration(int32_t()),
        maxElevation(float())
        { }
};

struct TC_Argument {
    std::string name;
    std::string description;
    std::string tcName;
    int32_t relativePosition;
    int32_t lengthBits;
    int32_t argType;
    int32_t argSubType;
    int32_t engType;
    std::string units;
    int32_t prependSize;
    std::string stringTerminator;
    int32_t littleEndian;
    std::string functionName;
    std::string defaultValue;
    std::string rangeLow;
    std::string rangeHigh;
    TC_Argument() :
        name(std::string()),
        description(std::string()),
        tcName(std::string()),
        relativePosition(int32_t()),
        lengthBits(int32_t()),
        argType(int32_t()),
        argSubType(int32_t()),
        engType(int32_t()),
        units(std::string()),
        prependSize(int32_t()),
        stringTerminator(std::string()),
        littleEndian(int32_t()),
        functionName(std::string()),
        defaultValue(std::string()),
        rangeLow(std::string()),
        rangeHigh(std::string())
        { }
};

struct TC_ArgumentAssignment {
    std::string tcName;
    std::string argument;
    std::string value;
    TC_ArgumentAssignment() :
        tcName(std::string()),
        argument(std::string()),
        value(std::string())
        { }
};

struct TC_ParameterOptions {
    std::string tcName;
    int32_t significance;
    std::string significanceReason;
    TC_ParameterOptions() :
        tcName(std::string()),
        significance(int32_t()),
        significanceReason(std::string())
        { }
};

struct TC_ParameterOptConstraints {
    std::string tcName;
    std::string constraint;
    int32_t timeout;
    TC_ParameterOptConstraints() :
        tcName(std::string()),
        constraint(std::string()),
        timeout(int32_t())
        { }
};

enum TcStageEnum {
    TC_STAGE_TRANSFERRED,
    TC_STAGE_SENT,
    TC_STAGE_RECEIVED,
    TC_STAGE_ACCEPTED,
    TC_STAGE_QUEUED,
    TC_STAGE_EXECUTION,
    TC_STAGE_COMPLETED,
    TC_STAGE_FAILED,
};

struct TC_ParameterVerifier {
    std::string tcName;
    TcStageEnum tcStage;
    int32_t verifierType;
    std::string verifierText;
    int32_t startTimeCheckWindow;
    int32_t stopTimeCheckWindow;
    int32_t checkWindow;
    int32_t onSuccess;
    int32_t onFail;
    int32_t onTimeout;
    TC_ParameterVerifier() :
        tcName(std::string()),
        tcStage(TcStageEnum()),
        verifierType(int32_t()),
        verifierText(std::string()),
        startTimeCheckWindow(int32_t()),
        stopTimeCheckWindow(int32_t()),
        checkWindow(int32_t()),
        onSuccess(int32_t()),
        onFail(int32_t()),
        onTimeout(int32_t())
        { }
};

struct TC_Parameter {
    int32_t identifier;
    std::string name;
    std::string displayName;
    std::string description;
    std::string parentName;
    std::string subsystem;
    int32_t node;
    int32_t channel;
    int32_t lengthBits;
    int32_t abstractFlag;
    std::vector<TC_Argument > listArgument;
    std::vector<TC_ArgumentAssignment > listArgumentAssignment;
    std::vector<TC_ParameterOptions > listOptions;
    std::vector<TC_ParameterOptConstraints > listOptConstraints;
    std::vector<TC_ParameterVerifier > listVerifications;
    TC_Parameter() :
        identifier(int32_t()),
        name(std::string()),
        displayName(std::string()),
        description(std::string()),
        parentName(std::string()),
        subsystem(std::string()),
        node(int32_t()),
        channel(int32_t()),
        lengthBits(int32_t()),
        abstractFlag(int32_t()),
        listArgument(std::vector<TC_Argument >()),
        listArgumentAssignment(std::vector<TC_ArgumentAssignment >()),
        listOptions(std::vector<TC_ParameterOptions >()),
        listOptConstraints(std::vector<TC_ParameterOptConstraints >()),
        listVerifications(std::vector<TC_ParameterVerifier >())
        { }
};

struct Limit {
    int32_t identifier;
    int32_t status;
    int32_t counter;
    double minValue;
    double maxValue;
    Limit() :
        identifier(int32_t()),
        status(int32_t()),
        counter(int32_t()),
        minValue(double()),
        maxValue(double())
        { }
};

struct AvroTypes_proc_Union__3__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<Alarm > get_array() const;
    void set_array(const std::vector<Alarm >& v);
    AvroTypes_proc_Union__3__();
};

struct TM_Parameter {
    typedef AvroTypes_proc_Union__3__ listAlarms_t;
    int32_t identifier;
    std::string name;
    std::string displayName;
    std::string description;
    int32_t node;
    int32_t channel;
    int32_t lengthBits;
    TmTypeEnum valueType;
    TmSubTypeEnum valueSubType;
    TmEngTypeEnum engType;
    std::string units;
    int32_t prependSize;
    std::string stringTerminator;
    bool littleEndian;
    std::string calibrationFunction;
    int32_t lengthFieldId;
    RadixEnum radix;
    listAlarms_t listAlarms;
    std::string subsystem;
    TM_Parameter() :
        identifier(int32_t()),
        name(std::string()),
        displayName(std::string()),
        description(std::string()),
        node(int32_t()),
        channel(int32_t()),
        lengthBits(int32_t()),
        valueType(TmTypeEnum()),
        valueSubType(TmSubTypeEnum()),
        engType(TmEngTypeEnum()),
        units(std::string()),
        prependSize(int32_t()),
        stringTerminator(std::string()),
        littleEndian(bool()),
        calibrationFunction(std::string()),
        lengthFieldId(int32_t()),
        radix(RadixEnum()),
        listAlarms(listAlarms_t()),
        subsystem(std::string())
        { }
};

struct ProcessedField {
    int32_t index;
    int32_t fieldTypeId;
    std::string fieldName;
    std::string value;
    ProcessedField() :
        index(int32_t()),
        fieldTypeId(int32_t()),
        fieldName(std::string()),
        value(std::string())
        { }
};

struct AvroTypes_proc_Union__4__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<int32_t > get_array() const;
    void set_array(const std::vector<int32_t >& v);
    AvroTypes_proc_Union__4__();
};

struct GroupProcessedField {
    typedef AvroTypes_proc_Union__4__ oolFields_t;
    int32_t id;
    std::vector<ProcessedField > fields;
    bool oolFlag;
    oolFields_t oolFields;
    GroupProcessedField() :
        id(int32_t()),
        fields(std::vector<ProcessedField >()),
        oolFlag(bool()),
        oolFields(oolFields_t())
        { }
};

struct AvroTypes_proc_Union__5__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<GroupProcessedField > get_array() const;
    void set_array(const std::vector<GroupProcessedField >& v);
    AvroTypes_proc_Union__5__();
};

struct TM_ProcessedFrame {
    typedef AvroTypes_proc_Union__5__ groups_t;
    int32_t id;
    int32_t frameTypeId;
    int64_t creationTime;
    groups_t groups;
    TM_ProcessedFrame() :
        id(int32_t()),
        frameTypeId(int32_t()),
        creationTime(int64_t()),
        groups(groups_t())
        { }
};

struct User {
    int32_t userId;
    std::string userName;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    std::string missionName;
    int32_t roleId;
    User() :
        userId(int32_t()),
        userName(std::string()),
        password(std::string()),
        firstName(std::string()),
        lastName(std::string()),
        emailAddress(std::string()),
        missionName(std::string()),
        roleId(int32_t())
        { }
};

struct AvroTypes_proc_Union__6__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<GroupProcessedField > get_array() const;
    void set_array(const std::vector<GroupProcessedField >& v);
    AvroTypes_proc_Union__6__();
};

struct XTCE_ProcessedFrame {
    typedef AvroTypes_proc_Union__6__ groups_t;
    int32_t id;
    std::string containerName;
    int64_t creationTime;
    groups_t groups;
    XTCE_ProcessedFrame() :
        id(int32_t()),
        containerName(std::string()),
        creationTime(int64_t()),
        groups(groups_t())
        { }
};

struct TM_FrameField {
    std::string frameName;
    std::string parameterName;
    int32_t relativePosition;
    int32_t sequenceNumber;
    TM_FrameField() :
        frameName(std::string()),
        parameterName(std::string()),
        relativePosition(int32_t()),
        sequenceNumber(int32_t())
        { }
};

struct TM_FrameCondition {
    std::string frameName;
    std::string parameterName;
    std::string parameterValue;
    TM_FrameCondition() :
        frameName(std::string()),
        parameterName(std::string()),
        parameterValue(std::string())
        { }
};

enum TmFrameFlagEnum {
    TM_FRAME_ARCHIVE,
    TM_FRAME_LITTLE_ENDIAN,
};

struct AvroTypes_proc_Union__7__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::vector<TM_FrameCondition > get_array() const;
    void set_array(const std::vector<TM_FrameCondition >& v);
    AvroTypes_proc_Union__7__();
};

struct TM_Frame {
    typedef AvroTypes_proc_Union__7__ frameConditions_t;
    std::string name;
    std::string description;
    int32_t expectedInterval;
    int32_t lengthBits;
    TmFrameFlagEnum flag;
    frameConditions_t frameConditions;
    std::vector<TM_FrameField > tmFields;
    std::string layerName;
    TM_Frame() :
        name(std::string()),
        description(std::string()),
        expectedInterval(int32_t()),
        lengthBits(int32_t()),
        flag(TmFrameFlagEnum()),
        frameConditions(frameConditions_t()),
        tmFields(std::vector<TM_FrameField >()),
        layerName(std::string())
        { }
};

struct ListFrameTypes {
    std::vector<TM_Frame > listFrameTypes;
    ListFrameTypes() :
        listFrameTypes(std::vector<TM_Frame >())
        { }
};

struct ListGroundStations {
    std::string numberGroundStations;
    std::vector<GroundStation > listGroundStations;
    ListGroundStations() :
        numberGroundStations(std::string()),
        listGroundStations(std::vector<GroundStation >())
        { }
};

struct ListKeyValues {
    std::vector<KeyValue > listKeyValues;
    ListKeyValues() :
        listKeyValues(std::vector<KeyValue >())
        { }
};

struct ListParameters {
    std::vector<ConfigurationParameter > listParameters;
    ListParameters() :
        listParameters(std::vector<ConfigurationParameter >())
        { }
};

struct ListLayers {
    std::vector<Layer > listLayers;
    ListLayers() :
        listLayers(std::vector<Layer >())
        { }
};

struct ListPasses {
    std::string spacecraftIdentifier;
    std::string groundStationIdentifier;
    int32_t numberPasses;
    std::vector<Pass > listPasses;
    ListPasses() :
        spacecraftIdentifier(std::string()),
        groundStationIdentifier(std::string()),
        numberPasses(int32_t()),
        listPasses(std::vector<Pass >())
        { }
};

struct ListSatellites {
    std::vector<Satellite > listSatellites;
    ListSatellites() :
        listSatellites(std::vector<Satellite >())
        { }
};

struct ListTC_Parameters {
    std::vector<TC_Parameter > listTC_Parameters;
    ListTC_Parameters() :
        listTC_Parameters(std::vector<TC_Parameter >())
        { }
};

struct ListTM_Parameters {
    std::vector<TM_Parameter > listTM_Parameters;
    ListTM_Parameters() :
        listTM_Parameters(std::vector<TM_Parameter >())
        { }
};

struct MsgAddGroundStation {
    std::string authorizationToken;
    GroundStation groundStation;
    MsgAddGroundStation() :
        authorizationToken(std::string()),
        groundStation(GroundStation())
        { }
};

struct MsgAddMission {
    std::string authorizationToken;
    Mission mission;
    MsgAddMission() :
        authorizationToken(std::string()),
        mission(Mission())
        { }
};

struct MsgAddMissionLayer {
    std::string authorizationToken;
    std::string missionName;
    Layer layer;
    MsgAddMissionLayer() :
        authorizationToken(std::string()),
        missionName(std::string()),
        layer(Layer())
        { }
};

struct MsgAddNode {
    std::string authorizationToken;
    int32_t subsystemId;
    Node node;
    MsgAddNode() :
        authorizationToken(std::string()),
        subsystemId(int32_t()),
        node(Node())
        { }
};

struct MsgAddRawFrame {
    std::string authorizationToken;
    int64_t timestamp;
    std::vector<uint8_t> data;
    int32_t dataLength;
    MsgAddRawFrame() :
        authorizationToken(std::string()),
        timestamp(int64_t()),
        data(std::vector<uint8_t>()),
        dataLength(int32_t())
        { }
};

struct MsgAddSatellite {
    std::string authorizationToken;
    std::string missionName;
    Satellite satellite;
    MsgAddSatellite() :
        authorizationToken(std::string()),
        missionName(std::string()),
        satellite(Satellite())
        { }
};

struct MsgAddSubsystem {
    std::string authorizationToken;
    std::string satelliteName;
    Subsystem subsystem;
    MsgAddSubsystem() :
        authorizationToken(std::string()),
        satelliteName(std::string()),
        subsystem(Subsystem())
        { }
};

struct MsgAddTcParameter {
    std::string authorizationToken;
    TC_Parameter tcParameter;
    MsgAddTcParameter() :
        authorizationToken(std::string()),
        tcParameter(TC_Parameter())
        { }
};

struct MsgAddTmParameter {
    std::string authorizationToken;
    TM_Parameter tmParameter;
    MsgAddTmParameter() :
        authorizationToken(std::string()),
        tmParameter(TM_Parameter())
        { }
};

struct MsgCheckLicence {
    std::string componentId;
    std::string componentSignature;
    std::vector<std::string > componentFunction;
    MsgCheckLicence() :
        componentId(std::string()),
        componentSignature(std::string()),
        componentFunction(std::vector<std::string >())
        { }
};

struct MsgCheckLicenceResponse {
    std::string componentId;
    std::string componentSignature;
    std::vector<std::string > componentFunctions;
    std::vector<std::string > licenceFunction;
    MsgCheckLicenceResponse() :
        componentId(std::string()),
        componentSignature(std::string()),
        componentFunctions(std::vector<std::string >()),
        licenceFunction(std::vector<std::string >())
        { }
};

struct MsgConnectGroundStation {
    std::string authorizationToken;
    int32_t groundStationId;
    MsgConnectGroundStation() :
        authorizationToken(std::string()),
        groundStationId(int32_t())
        { }
};

struct MsgDisconnectGroundStation {
    std::string authorizationToken;
    std::string connectionId;
    MsgDisconnectGroundStation() :
        authorizationToken(std::string()),
        connectionId(std::string())
        { }
};

struct MsgEndModuleExecution {
    std::string authorizationToken;
    std::string module_name;
    std::string execution_id;
    int32_t errorCode;
    std::string errorMessage;
    MsgEndModuleExecution() :
        authorizationToken(std::string()),
        module_name(std::string()),
        execution_id(std::string()),
        errorCode(int32_t()),
        errorMessage(std::string())
        { }
};

struct MsgFds {
    std::string authorizationToken;
    std::string module_name;
    std::string execution_id;
    ListKeyValues parameters;
    MsgFds() :
        authorizationToken(std::string()),
        module_name(std::string()),
        execution_id(std::string()),
        parameters(ListKeyValues())
        { }
};

struct MsgGetDefaultMissionLayers {
    std::string authorizationToken;
    MsgGetDefaultMissionLayers() :
        authorizationToken(std::string())
        { }
};

struct MsgGetFrameTypes {
    std::string authorizationToken;
    std::string layerName;
    MsgGetFrameTypes() :
        authorizationToken(std::string()),
        layerName(std::string())
        { }
};

struct MsgGetGroundStation {
    std::string authorizationToken;
    std::string groundStationName;
    std::string groundStationCode;
    MsgGetGroundStation() :
        authorizationToken(std::string()),
        groundStationName(std::string()),
        groundStationCode(std::string())
        { }
};

struct MsgGetLayerParameters {
    std::string authorizationToken;
    std::string missionName;
    std::string layerName;
    MsgGetLayerParameters() :
        authorizationToken(std::string()),
        missionName(std::string()),
        layerName(std::string())
        { }
};

struct MsgGetMission {
    std::string authorizationToken;
    std::string missionName;
    MsgGetMission() :
        authorizationToken(std::string()),
        missionName(std::string())
        { }
};

struct MsgGetMissionLayers {
    std::string authorizationToken;
    std::string missionName;
    MsgGetMissionLayers() :
        authorizationToken(std::string()),
        missionName(std::string())
        { }
};

struct MsgGetNode {
    std::string authorizationToken;
    int32_t subsystemId;
    int32_t nodeId;
    MsgGetNode() :
        authorizationToken(std::string()),
        subsystemId(int32_t()),
        nodeId(int32_t())
        { }
};

struct MsgGetPasses {
    std::string authorizationToken;
    int32_t userRole;
    int32_t missionId;
    int32_t satelliteId;
    int32_t groundStationId;
    std::string startTime;
    std::string stopTime;
    MsgGetPasses() :
        authorizationToken(std::string()),
        userRole(int32_t()),
        missionId(int32_t()),
        satelliteId(int32_t()),
        groundStationId(int32_t()),
        startTime(std::string()),
        stopTime(std::string())
        { }
};

struct MsgGetSatellite {
    std::string authorizationToken;
    std::string missionName;
    std::string satelliteName;
    std::string satelliteCode;
    MsgGetSatellite() :
        authorizationToken(std::string()),
        missionName(std::string()),
        satelliteName(std::string()),
        satelliteCode(std::string())
        { }
};

struct MsgGetStatus {
    std::string componentId;
    MsgGetStatus() :
        componentId(std::string())
        { }
};

enum IntComponentStatusEnum {
    MODE_NONE,
    STARTED,
    NOT_RUNNING,
    RUNNING,
    COMPLETE,
    FAILED,
};

struct MsgGetStatusResponse {
    std::string componentId;
    IntComponentStatusEnum ComponentStatusEnum;
    MsgGetStatusResponse() :
        componentId(std::string()),
        ComponentStatusEnum(IntComponentStatusEnum())
        { }
};

struct MsgGetSubsystem {
    std::string authorizationToken;
    std::string satelliteName;
    std::string subsystemName;
    MsgGetSubsystem() :
        authorizationToken(std::string()),
        satelliteName(std::string()),
        subsystemName(std::string())
        { }
};

struct MsgGetTcParameter {
    std::string authorizationToken;
    int32_t tcParameterId;
    int32_t nodeId;
    int32_t channelId;
    MsgGetTcParameter() :
        authorizationToken(std::string()),
        tcParameterId(int32_t()),
        nodeId(int32_t()),
        channelId(int32_t())
        { }
};

struct MsgGetTmParameter {
    std::string authorizationToken;
    int32_t tmParameterId;
    int32_t nodeId;
    int32_t channelId;
    MsgGetTmParameter() :
        authorizationToken(std::string()),
        tmParameterId(int32_t()),
        nodeId(int32_t()),
        channelId(int32_t())
        { }
};

struct AvroTypes_proc_Union__8__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    int32_t get_int() const;
    void set_int(const int32_t& v);
    AvroTypes_proc_Union__8__();
};

struct AvroTypes_proc_Union__9__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    int32_t get_int() const;
    void set_int(const int32_t& v);
    AvroTypes_proc_Union__9__();
};

struct MsgHeader {
    typedef AvroTypes_proc_Union__8__ expirationTime_t;
    typedef AvroTypes_proc_Union__9__ sequenceId_t;
    int32_t messageId;
    int32_t correlationId;
    int32_t service;
    std::string URIfrom;
    std::string URIto;
    std::string generationTime;
    expirationTime_t expirationTime;
    sequenceId_t sequenceId;
    int32_t positionId;
    int32_t sequenceSize;
    MsgHeader() :
        messageId(int32_t()),
        correlationId(int32_t()),
        service(int32_t()),
        URIfrom(std::string()),
        URIto(std::string()),
        generationTime(std::string()),
        expirationTime(expirationTime_t()),
        sequenceId(sequenceId_t()),
        positionId(int32_t()),
        sequenceSize(int32_t())
        { }
};

struct MsgImportScDatabase {
    std::string authorizationToken;
    std::string fileName;
    int32_t fileType;
    int32_t fileSize;
    int32_t numberOfChunks;
    int32_t chunkNumber;
    std::string buffer;
    MsgImportScDatabase() :
        authorizationToken(std::string()),
        fileName(std::string()),
        fileType(int32_t()),
        fileSize(int32_t()),
        numberOfChunks(int32_t()),
        chunkNumber(int32_t()),
        buffer(std::string())
        { }
};

struct MsgLogin {
    std::string userName;
    std::string hashPassword;
    MsgLogin() :
        userName(std::string()),
        hashPassword(std::string())
        { }
};

struct MsgLoginResponse {
    User userData;
    std::string authorizationToken;
    MsgLoginResponse() :
        userData(User()),
        authorizationToken(std::string())
        { }
};

struct MsgLogout {
    std::string authorizationToken;
    std::string userId;
    std::string userName;
    MsgLogout() :
        authorizationToken(std::string()),
        userId(std::string()),
        userName(std::string())
        { }
};

struct MsgProcessRawFrame {
    std::string authorizationToken;
    std::string missionName;
    std::string containerName;
    std::vector<uint8_t> rawFrame;
    MsgProcessRawFrame() :
        authorizationToken(std::string()),
        missionName(std::string()),
        containerName(std::string()),
        rawFrame(std::vector<uint8_t>())
        { }
};

struct MsgPublishEvent {
    std::string authorizationToken;
    Event event;
    MsgPublishEvent() :
        authorizationToken(std::string()),
        event(Event())
        { }
};

struct MsgRegisterUserOld {
    std::string firstName;
    std::string lastName;
    std::string userName;
    std::string hashPassword;
    std::string emailAddress;
    std::string missionName;
    std::string missionDescription;
    std::string missionCountry;
    std::string missionOwner;
    MsgRegisterUserOld() :
        firstName(std::string()),
        lastName(std::string()),
        userName(std::string()),
        hashPassword(std::string()),
        emailAddress(std::string()),
        missionName(std::string()),
        missionDescription(std::string()),
        missionCountry(std::string()),
        missionOwner(std::string())
        { }
};

struct MsgRegisterUser {
    User user;
    Mission mission;
    MsgRegisterUser() :
        user(User()),
        mission(Mission())
        { }
};

struct MsgRemoveGroundStation {
    std::string authorizationToken;
    std::string groundStationName;
    MsgRemoveGroundStation() :
        authorizationToken(std::string()),
        groundStationName(std::string())
        { }
};

struct MsgRemoveMissionLayer {
    std::string authorizationToken;
    std::string missionName;
    std::string layerName;
    MsgRemoveMissionLayer() :
        authorizationToken(std::string()),
        missionName(std::string()),
        layerName(std::string())
        { }
};

struct MsgRemoveMission {
    std::string authorizationToken;
    std::string missionName;
    MsgRemoveMission() :
        authorizationToken(std::string()),
        missionName(std::string())
        { }
};

struct MsgRemoveNode {
    std::string authorizationToken;
    int32_t subsystemId;
    int32_t nodeId;
    MsgRemoveNode() :
        authorizationToken(std::string()),
        subsystemId(int32_t()),
        nodeId(int32_t())
        { }
};

struct MsgRemoveSatellite {
    std::string authorizationToken;
    std::string missionName;
    std::string satelliteName;
    MsgRemoveSatellite() :
        authorizationToken(std::string()),
        missionName(std::string()),
        satelliteName(std::string())
        { }
};

struct MsgRemoveSubsystem {
    std::string authorizationToken;
    std::string satelliteName;
    std::string subsystemName;
    MsgRemoveSubsystem() :
        authorizationToken(std::string()),
        satelliteName(std::string()),
        subsystemName(std::string())
        { }
};

struct MsgRemoveTcParameter {
    std::string authorizationToken;
    int32_t tcParameterId;
    int32_t nodeId;
    int32_t channelId;
    MsgRemoveTcParameter() :
        authorizationToken(std::string()),
        tcParameterId(int32_t()),
        nodeId(int32_t()),
        channelId(int32_t())
        { }
};

struct MsgRemoveTmParameter {
    std::string authorizationToken;
    int32_t tmParameterId;
    int32_t nodeId;
    int32_t channelId;
    MsgRemoveTmParameter() :
        authorizationToken(std::string()),
        tmParameterId(int32_t()),
        nodeId(int32_t()),
        channelId(int32_t())
        { }
};

struct MsgReturnData {
    int32_t errorCode;
    std::string errorMessage;
    MsgReturnData() :
        errorCode(int32_t()),
        errorMessage(std::string())
        { }
};

struct MsgSendFrameGroundStation {
    std::string authorizationToken;
    std::string connectionId;
    std::vector<uint8_t> data;
    int32_t dataLength;
    MsgSendFrameGroundStation() :
        authorizationToken(std::string()),
        connectionId(std::string()),
        data(std::vector<uint8_t>()),
        dataLength(int32_t())
        { }
};

struct MsgShutdown {
    MsgShutdown()
        { }
};

struct MsgStartModuleExecution {
    std::string authorizationToken;
    std::string module_name;
    std::string execution_id;
    ListKeyValues parameters;
    MsgStartModuleExecution() :
        authorizationToken(std::string()),
        module_name(std::string()),
        execution_id(std::string()),
        parameters(ListKeyValues())
        { }
};

struct MsgStartup {
    std::string message;
    MsgStartup() :
        message(std::string())
        { }
};

struct MsgUpdateGroundStation {
    std::string authorizationToken;
    GroundStation groundStation;
    MsgUpdateGroundStation() :
        authorizationToken(std::string()),
        groundStation(GroundStation())
        { }
};

struct MsgUpdateMission {
    std::string authorizationToken;
    Mission mission;
    MsgUpdateMission() :
        authorizationToken(std::string()),
        mission(Mission())
        { }
};

struct MsgUpdateNode {
    std::string authorizationToken;
    int32_t subsystemId;
    Node node;
    MsgUpdateNode() :
        authorizationToken(std::string()),
        subsystemId(int32_t()),
        node(Node())
        { }
};

struct MsgUpdateSatellite {
    std::string authorizationToken;
    Satellite satellite;
    MsgUpdateSatellite() :
        authorizationToken(std::string()),
        satellite(Satellite())
        { }
};

struct MsgUpdateSubsystem {
    std::string authorizationToken;
    Subsystem subsystem;
    MsgUpdateSubsystem() :
        authorizationToken(std::string()),
        subsystem(Subsystem())
        { }
};

struct MsgUpdateTcParameter {
    std::string authorizationToken;
    TC_Parameter tcParameter;
    MsgUpdateTcParameter() :
        authorizationToken(std::string()),
        tcParameter(TC_Parameter())
        { }
};

struct MsgUpdateTmParameter {
    std::string authorizationToken;
    TM_Parameter tmParameter;
    MsgUpdateTmParameter() :
        authorizationToken(std::string()),
        tmParameter(TM_Parameter())
        { }
};

struct AvroNone {
    int32_t none_field;
    AvroNone() :
        none_field(int32_t())
        { }
};

struct AvroTypes_proc_Union__10__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    TmTypeEnum get_TmTypeEnum() const;
    void set_TmTypeEnum(const TmTypeEnum& v);
    TmSubTypeEnum get_TmSubTypeEnum() const;
    void set_TmSubTypeEnum(const TmSubTypeEnum& v);
    TmEngTypeEnum get_TmEngTypeEnum() const;
    void set_TmEngTypeEnum(const TmEngTypeEnum& v);
    RadixEnum get_RadixEnum() const;
    void set_RadixEnum(const RadixEnum& v);
    ModuleTypeEnum get_ModuleTypeEnum() const;
    void set_ModuleTypeEnum(const ModuleTypeEnum& v);
    Subsystem get_Subsystem() const;
    void set_Subsystem(const Subsystem& v);
    Satellite get_Satellite() const;
    void set_Satellite(const Satellite& v);
    Mission get_Mission() const;
    void set_Mission(const Mission& v);
    WatchTriggerTypeEnum get_WatchTriggerTypeEnum() const;
    void set_WatchTriggerTypeEnum(const WatchTriggerTypeEnum& v);
    AlarmContext get_AlarmContext() const;
    void set_AlarmContext(const AlarmContext& v);
    Alarm get_Alarm() const;
    void set_Alarm(const Alarm& v);
    AlgorithmParameter get_AlgorithmParameter() const;
    void set_AlgorithmParameter(const AlgorithmParameter& v);
    Algorithm get_Algorithm() const;
    void set_Algorithm(const Algorithm& v);
    CalibrationItem get_CalibrationItem() const;
    void set_CalibrationItem(const CalibrationItem& v);
    Calibration get_Calibration() const;
    void set_Calibration(const Calibration& v);
    ConfigurationParameter get_ConfigurationParameter() const;
    void set_ConfigurationParameter(const ConfigurationParameter& v);
    Derived_TM_Parameter get_Derived_TM_Parameter() const;
    void set_Derived_TM_Parameter(const Derived_TM_Parameter& v);
    Event get_Event() const;
    void set_Event(const Event& v);
    FdsModule get_FdsModule() const;
    void set_FdsModule(const FdsModule& v);
    GroundStation get_GroundStation() const;
    void set_GroundStation(const GroundStation& v);
    KeyValue get_KeyValue() const;
    void set_KeyValue(const KeyValue& v);
    Layer get_Layer() const;
    void set_Layer(const Layer& v);
    Node get_Node() const;
    void set_Node(const Node& v);
    Pass get_Pass() const;
    void set_Pass(const Pass& v);
    TC_Argument get_TC_Argument() const;
    void set_TC_Argument(const TC_Argument& v);
    TC_ArgumentAssignment get_TC_ArgumentAssignment() const;
    void set_TC_ArgumentAssignment(const TC_ArgumentAssignment& v);
    TC_ParameterOptions get_TC_ParameterOptions() const;
    void set_TC_ParameterOptions(const TC_ParameterOptions& v);
    TC_ParameterOptConstraints get_TC_ParameterOptConstraints() const;
    void set_TC_ParameterOptConstraints(const TC_ParameterOptConstraints& v);
    TC_ParameterVerifier get_TC_ParameterVerifier() const;
    void set_TC_ParameterVerifier(const TC_ParameterVerifier& v);
    TC_Parameter get_TC_Parameter() const;
    void set_TC_Parameter(const TC_Parameter& v);
    Limit get_Limit() const;
    void set_Limit(const Limit& v);
    TM_Parameter get_TM_Parameter() const;
    void set_TM_Parameter(const TM_Parameter& v);
    ProcessedField get_ProcessedField() const;
    void set_ProcessedField(const ProcessedField& v);
    GroupProcessedField get_GroupProcessedField() const;
    void set_GroupProcessedField(const GroupProcessedField& v);
    TM_ProcessedFrame get_TM_ProcessedFrame() const;
    void set_TM_ProcessedFrame(const TM_ProcessedFrame& v);
    User get_User() const;
    void set_User(const User& v);
    XTCE_ProcessedFrame get_XTCE_ProcessedFrame() const;
    void set_XTCE_ProcessedFrame(const XTCE_ProcessedFrame& v);
    TM_FrameField get_TM_FrameField() const;
    void set_TM_FrameField(const TM_FrameField& v);
    TM_FrameCondition get_TM_FrameCondition() const;
    void set_TM_FrameCondition(const TM_FrameCondition& v);
    TM_Frame get_TM_Frame() const;
    void set_TM_Frame(const TM_Frame& v);
    ListFrameTypes get_ListFrameTypes() const;
    void set_ListFrameTypes(const ListFrameTypes& v);
    ListGroundStations get_ListGroundStations() const;
    void set_ListGroundStations(const ListGroundStations& v);
    ListKeyValues get_ListKeyValues() const;
    void set_ListKeyValues(const ListKeyValues& v);
    ListParameters get_ListParameters() const;
    void set_ListParameters(const ListParameters& v);
    ListLayers get_ListLayers() const;
    void set_ListLayers(const ListLayers& v);
    ListPasses get_ListPasses() const;
    void set_ListPasses(const ListPasses& v);
    ListSatellites get_ListSatellites() const;
    void set_ListSatellites(const ListSatellites& v);
    ListTC_Parameters get_ListTC_Parameters() const;
    void set_ListTC_Parameters(const ListTC_Parameters& v);
    ListTM_Parameters get_ListTM_Parameters() const;
    void set_ListTM_Parameters(const ListTM_Parameters& v);
    MsgAddGroundStation get_MsgAddGroundStation() const;
    void set_MsgAddGroundStation(const MsgAddGroundStation& v);
    MsgAddMission get_MsgAddMission() const;
    void set_MsgAddMission(const MsgAddMission& v);
    MsgAddMissionLayer get_MsgAddMissionLayer() const;
    void set_MsgAddMissionLayer(const MsgAddMissionLayer& v);
    MsgAddNode get_MsgAddNode() const;
    void set_MsgAddNode(const MsgAddNode& v);
    MsgAddRawFrame get_MsgAddRawFrame() const;
    void set_MsgAddRawFrame(const MsgAddRawFrame& v);
    MsgAddSatellite get_MsgAddSatellite() const;
    void set_MsgAddSatellite(const MsgAddSatellite& v);
    MsgAddSubsystem get_MsgAddSubsystem() const;
    void set_MsgAddSubsystem(const MsgAddSubsystem& v);
    MsgAddTcParameter get_MsgAddTcParameter() const;
    void set_MsgAddTcParameter(const MsgAddTcParameter& v);
    MsgAddTmParameter get_MsgAddTmParameter() const;
    void set_MsgAddTmParameter(const MsgAddTmParameter& v);
    MsgCheckLicence get_MsgCheckLicence() const;
    void set_MsgCheckLicence(const MsgCheckLicence& v);
    MsgCheckLicenceResponse get_MsgCheckLicenceResponse() const;
    void set_MsgCheckLicenceResponse(const MsgCheckLicenceResponse& v);
    MsgConnectGroundStation get_MsgConnectGroundStation() const;
    void set_MsgConnectGroundStation(const MsgConnectGroundStation& v);
    MsgDisconnectGroundStation get_MsgDisconnectGroundStation() const;
    void set_MsgDisconnectGroundStation(const MsgDisconnectGroundStation& v);
    MsgEndModuleExecution get_MsgEndModuleExecution() const;
    void set_MsgEndModuleExecution(const MsgEndModuleExecution& v);
    MsgFds get_MsgFds() const;
    void set_MsgFds(const MsgFds& v);
    MsgGetDefaultMissionLayers get_MsgGetDefaultMissionLayers() const;
    void set_MsgGetDefaultMissionLayers(const MsgGetDefaultMissionLayers& v);
    MsgGetFrameTypes get_MsgGetFrameTypes() const;
    void set_MsgGetFrameTypes(const MsgGetFrameTypes& v);
    MsgGetGroundStation get_MsgGetGroundStation() const;
    void set_MsgGetGroundStation(const MsgGetGroundStation& v);
    MsgGetLayerParameters get_MsgGetLayerParameters() const;
    void set_MsgGetLayerParameters(const MsgGetLayerParameters& v);
    MsgGetMission get_MsgGetMission() const;
    void set_MsgGetMission(const MsgGetMission& v);
    MsgGetMissionLayers get_MsgGetMissionLayers() const;
    void set_MsgGetMissionLayers(const MsgGetMissionLayers& v);
    MsgGetNode get_MsgGetNode() const;
    void set_MsgGetNode(const MsgGetNode& v);
    MsgGetPasses get_MsgGetPasses() const;
    void set_MsgGetPasses(const MsgGetPasses& v);
    MsgGetSatellite get_MsgGetSatellite() const;
    void set_MsgGetSatellite(const MsgGetSatellite& v);
    MsgGetStatus get_MsgGetStatus() const;
    void set_MsgGetStatus(const MsgGetStatus& v);
    MsgGetStatusResponse get_MsgGetStatusResponse() const;
    void set_MsgGetStatusResponse(const MsgGetStatusResponse& v);
    MsgGetSubsystem get_MsgGetSubsystem() const;
    void set_MsgGetSubsystem(const MsgGetSubsystem& v);
    MsgGetTcParameter get_MsgGetTcParameter() const;
    void set_MsgGetTcParameter(const MsgGetTcParameter& v);
    MsgGetTmParameter get_MsgGetTmParameter() const;
    void set_MsgGetTmParameter(const MsgGetTmParameter& v);
    MsgHeader get_MsgHeader() const;
    void set_MsgHeader(const MsgHeader& v);
    MsgImportScDatabase get_MsgImportScDatabase() const;
    void set_MsgImportScDatabase(const MsgImportScDatabase& v);
    MsgLogin get_MsgLogin() const;
    void set_MsgLogin(const MsgLogin& v);
    MsgLoginResponse get_MsgLoginResponse() const;
    void set_MsgLoginResponse(const MsgLoginResponse& v);
    MsgLogout get_MsgLogout() const;
    void set_MsgLogout(const MsgLogout& v);
    MsgProcessRawFrame get_MsgProcessRawFrame() const;
    void set_MsgProcessRawFrame(const MsgProcessRawFrame& v);
    MsgPublishEvent get_MsgPublishEvent() const;
    void set_MsgPublishEvent(const MsgPublishEvent& v);
    MsgRegisterUserOld get_MsgRegisterUserOld() const;
    void set_MsgRegisterUserOld(const MsgRegisterUserOld& v);
    MsgRegisterUser get_MsgRegisterUser() const;
    void set_MsgRegisterUser(const MsgRegisterUser& v);
    MsgRemoveGroundStation get_MsgRemoveGroundStation() const;
    void set_MsgRemoveGroundStation(const MsgRemoveGroundStation& v);
    MsgRemoveMissionLayer get_MsgRemoveMissionLayer() const;
    void set_MsgRemoveMissionLayer(const MsgRemoveMissionLayer& v);
    MsgRemoveMission get_MsgRemoveMission() const;
    void set_MsgRemoveMission(const MsgRemoveMission& v);
    MsgRemoveNode get_MsgRemoveNode() const;
    void set_MsgRemoveNode(const MsgRemoveNode& v);
    MsgRemoveSatellite get_MsgRemoveSatellite() const;
    void set_MsgRemoveSatellite(const MsgRemoveSatellite& v);
    MsgRemoveSubsystem get_MsgRemoveSubsystem() const;
    void set_MsgRemoveSubsystem(const MsgRemoveSubsystem& v);
    MsgRemoveTcParameter get_MsgRemoveTcParameter() const;
    void set_MsgRemoveTcParameter(const MsgRemoveTcParameter& v);
    MsgRemoveTmParameter get_MsgRemoveTmParameter() const;
    void set_MsgRemoveTmParameter(const MsgRemoveTmParameter& v);
    MsgReturnData get_MsgReturnData() const;
    void set_MsgReturnData(const MsgReturnData& v);
    MsgSendFrameGroundStation get_MsgSendFrameGroundStation() const;
    void set_MsgSendFrameGroundStation(const MsgSendFrameGroundStation& v);
    MsgShutdown get_MsgShutdown() const;
    void set_MsgShutdown(const MsgShutdown& v);
    MsgStartModuleExecution get_MsgStartModuleExecution() const;
    void set_MsgStartModuleExecution(const MsgStartModuleExecution& v);
    MsgStartup get_MsgStartup() const;
    void set_MsgStartup(const MsgStartup& v);
    MsgUpdateGroundStation get_MsgUpdateGroundStation() const;
    void set_MsgUpdateGroundStation(const MsgUpdateGroundStation& v);
    MsgUpdateMission get_MsgUpdateMission() const;
    void set_MsgUpdateMission(const MsgUpdateMission& v);
    MsgUpdateNode get_MsgUpdateNode() const;
    void set_MsgUpdateNode(const MsgUpdateNode& v);
    MsgUpdateSatellite get_MsgUpdateSatellite() const;
    void set_MsgUpdateSatellite(const MsgUpdateSatellite& v);
    MsgUpdateSubsystem get_MsgUpdateSubsystem() const;
    void set_MsgUpdateSubsystem(const MsgUpdateSubsystem& v);
    MsgUpdateTcParameter get_MsgUpdateTcParameter() const;
    void set_MsgUpdateTcParameter(const MsgUpdateTcParameter& v);
    MsgUpdateTmParameter get_MsgUpdateTmParameter() const;
    void set_MsgUpdateTmParameter(const MsgUpdateTmParameter& v);
    AvroNone get_AvroNone() const;
    void set_AvroNone(const AvroNone& v);
    AvroTypes_proc_Union__10__();
};

inline
std::vector<Subsystem > AvroTypes_proc_Union__0__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<Subsystem > >(value_);
}

inline
void AvroTypes_proc_Union__0__::set_array(const std::vector<Subsystem >& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::vector<Satellite > AvroTypes_proc_Union__1__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<Satellite > >(value_);
}

inline
void AvroTypes_proc_Union__1__::set_array(const std::vector<Satellite >& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::vector<ConfigurationParameter > AvroTypes_proc_Union__2__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<ConfigurationParameter > >(value_);
}

inline
void AvroTypes_proc_Union__2__::set_array(const std::vector<ConfigurationParameter >& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::vector<Alarm > AvroTypes_proc_Union__3__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<Alarm > >(value_);
}

inline
void AvroTypes_proc_Union__3__::set_array(const std::vector<Alarm >& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::vector<int32_t > AvroTypes_proc_Union__4__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<int32_t > >(value_);
}

inline
void AvroTypes_proc_Union__4__::set_array(const std::vector<int32_t >& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::vector<GroupProcessedField > AvroTypes_proc_Union__5__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<GroupProcessedField > >(value_);
}

inline
void AvroTypes_proc_Union__5__::set_array(const std::vector<GroupProcessedField >& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::vector<GroupProcessedField > AvroTypes_proc_Union__6__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<GroupProcessedField > >(value_);
}

inline
void AvroTypes_proc_Union__6__::set_array(const std::vector<GroupProcessedField >& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::vector<TM_FrameCondition > AvroTypes_proc_Union__7__::get_array() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::vector<TM_FrameCondition > >(value_);
}

inline
void AvroTypes_proc_Union__7__::set_array(const std::vector<TM_FrameCondition >& v) {
    idx_ = 1;
    value_ = v;
}

inline
int32_t AvroTypes_proc_Union__8__::get_int() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<int32_t >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_int(const int32_t& v) {
    idx_ = 1;
    value_ = v;
}

inline
int32_t AvroTypes_proc_Union__9__::get_int() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<int32_t >(value_);
}

inline
void AvroTypes_proc_Union__9__::set_int(const int32_t& v) {
    idx_ = 1;
    value_ = v;
}

inline
TmTypeEnum AvroTypes_proc_Union__10__::get_TmTypeEnum() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TmTypeEnum >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TmTypeEnum(const TmTypeEnum& v) {
    idx_ = 0;
    value_ = v;
}

inline
TmSubTypeEnum AvroTypes_proc_Union__10__::get_TmSubTypeEnum() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TmSubTypeEnum >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TmSubTypeEnum(const TmSubTypeEnum& v) {
    idx_ = 1;
    value_ = v;
}

inline
TmEngTypeEnum AvroTypes_proc_Union__10__::get_TmEngTypeEnum() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TmEngTypeEnum >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TmEngTypeEnum(const TmEngTypeEnum& v) {
    idx_ = 2;
    value_ = v;
}

inline
RadixEnum AvroTypes_proc_Union__10__::get_RadixEnum() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<RadixEnum >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_RadixEnum(const RadixEnum& v) {
    idx_ = 3;
    value_ = v;
}

inline
ModuleTypeEnum AvroTypes_proc_Union__10__::get_ModuleTypeEnum() const {
    if (idx_ != 4) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ModuleTypeEnum >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ModuleTypeEnum(const ModuleTypeEnum& v) {
    idx_ = 4;
    value_ = v;
}

inline
Subsystem AvroTypes_proc_Union__10__::get_Subsystem() const {
    if (idx_ != 5) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Subsystem >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Subsystem(const Subsystem& v) {
    idx_ = 5;
    value_ = v;
}

inline
Satellite AvroTypes_proc_Union__10__::get_Satellite() const {
    if (idx_ != 6) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Satellite >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Satellite(const Satellite& v) {
    idx_ = 6;
    value_ = v;
}

inline
Mission AvroTypes_proc_Union__10__::get_Mission() const {
    if (idx_ != 7) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Mission >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Mission(const Mission& v) {
    idx_ = 7;
    value_ = v;
}

inline
WatchTriggerTypeEnum AvroTypes_proc_Union__10__::get_WatchTriggerTypeEnum() const {
    if (idx_ != 8) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<WatchTriggerTypeEnum >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_WatchTriggerTypeEnum(const WatchTriggerTypeEnum& v) {
    idx_ = 8;
    value_ = v;
}

inline
AlarmContext AvroTypes_proc_Union__10__::get_AlarmContext() const {
    if (idx_ != 9) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AlarmContext >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_AlarmContext(const AlarmContext& v) {
    idx_ = 9;
    value_ = v;
}

inline
Alarm AvroTypes_proc_Union__10__::get_Alarm() const {
    if (idx_ != 10) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Alarm >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Alarm(const Alarm& v) {
    idx_ = 10;
    value_ = v;
}

inline
AlgorithmParameter AvroTypes_proc_Union__10__::get_AlgorithmParameter() const {
    if (idx_ != 11) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AlgorithmParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_AlgorithmParameter(const AlgorithmParameter& v) {
    idx_ = 11;
    value_ = v;
}

inline
Algorithm AvroTypes_proc_Union__10__::get_Algorithm() const {
    if (idx_ != 12) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Algorithm >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Algorithm(const Algorithm& v) {
    idx_ = 12;
    value_ = v;
}

inline
CalibrationItem AvroTypes_proc_Union__10__::get_CalibrationItem() const {
    if (idx_ != 13) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<CalibrationItem >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_CalibrationItem(const CalibrationItem& v) {
    idx_ = 13;
    value_ = v;
}

inline
Calibration AvroTypes_proc_Union__10__::get_Calibration() const {
    if (idx_ != 14) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Calibration >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Calibration(const Calibration& v) {
    idx_ = 14;
    value_ = v;
}

inline
ConfigurationParameter AvroTypes_proc_Union__10__::get_ConfigurationParameter() const {
    if (idx_ != 15) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ConfigurationParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ConfigurationParameter(const ConfigurationParameter& v) {
    idx_ = 15;
    value_ = v;
}

inline
Derived_TM_Parameter AvroTypes_proc_Union__10__::get_Derived_TM_Parameter() const {
    if (idx_ != 16) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Derived_TM_Parameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Derived_TM_Parameter(const Derived_TM_Parameter& v) {
    idx_ = 16;
    value_ = v;
}

inline
Event AvroTypes_proc_Union__10__::get_Event() const {
    if (idx_ != 17) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Event >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Event(const Event& v) {
    idx_ = 17;
    value_ = v;
}

inline
FdsModule AvroTypes_proc_Union__10__::get_FdsModule() const {
    if (idx_ != 18) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<FdsModule >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_FdsModule(const FdsModule& v) {
    idx_ = 18;
    value_ = v;
}

inline
GroundStation AvroTypes_proc_Union__10__::get_GroundStation() const {
    if (idx_ != 19) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<GroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_GroundStation(const GroundStation& v) {
    idx_ = 19;
    value_ = v;
}

inline
KeyValue AvroTypes_proc_Union__10__::get_KeyValue() const {
    if (idx_ != 20) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<KeyValue >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_KeyValue(const KeyValue& v) {
    idx_ = 20;
    value_ = v;
}

inline
Layer AvroTypes_proc_Union__10__::get_Layer() const {
    if (idx_ != 21) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Layer >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Layer(const Layer& v) {
    idx_ = 21;
    value_ = v;
}

inline
Node AvroTypes_proc_Union__10__::get_Node() const {
    if (idx_ != 22) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Node >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Node(const Node& v) {
    idx_ = 22;
    value_ = v;
}

inline
Pass AvroTypes_proc_Union__10__::get_Pass() const {
    if (idx_ != 23) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Pass >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Pass(const Pass& v) {
    idx_ = 23;
    value_ = v;
}

inline
TC_Argument AvroTypes_proc_Union__10__::get_TC_Argument() const {
    if (idx_ != 24) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TC_Argument >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TC_Argument(const TC_Argument& v) {
    idx_ = 24;
    value_ = v;
}

inline
TC_ArgumentAssignment AvroTypes_proc_Union__10__::get_TC_ArgumentAssignment() const {
    if (idx_ != 25) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TC_ArgumentAssignment >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TC_ArgumentAssignment(const TC_ArgumentAssignment& v) {
    idx_ = 25;
    value_ = v;
}

inline
TC_ParameterOptions AvroTypes_proc_Union__10__::get_TC_ParameterOptions() const {
    if (idx_ != 26) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TC_ParameterOptions >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TC_ParameterOptions(const TC_ParameterOptions& v) {
    idx_ = 26;
    value_ = v;
}

inline
TC_ParameterOptConstraints AvroTypes_proc_Union__10__::get_TC_ParameterOptConstraints() const {
    if (idx_ != 27) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TC_ParameterOptConstraints >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TC_ParameterOptConstraints(const TC_ParameterOptConstraints& v) {
    idx_ = 27;
    value_ = v;
}

inline
TC_ParameterVerifier AvroTypes_proc_Union__10__::get_TC_ParameterVerifier() const {
    if (idx_ != 28) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TC_ParameterVerifier >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TC_ParameterVerifier(const TC_ParameterVerifier& v) {
    idx_ = 28;
    value_ = v;
}

inline
TC_Parameter AvroTypes_proc_Union__10__::get_TC_Parameter() const {
    if (idx_ != 29) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TC_Parameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TC_Parameter(const TC_Parameter& v) {
    idx_ = 29;
    value_ = v;
}

inline
Limit AvroTypes_proc_Union__10__::get_Limit() const {
    if (idx_ != 30) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Limit >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_Limit(const Limit& v) {
    idx_ = 30;
    value_ = v;
}

inline
TM_Parameter AvroTypes_proc_Union__10__::get_TM_Parameter() const {
    if (idx_ != 31) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TM_Parameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TM_Parameter(const TM_Parameter& v) {
    idx_ = 31;
    value_ = v;
}

inline
ProcessedField AvroTypes_proc_Union__10__::get_ProcessedField() const {
    if (idx_ != 32) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ProcessedField >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ProcessedField(const ProcessedField& v) {
    idx_ = 32;
    value_ = v;
}

inline
GroupProcessedField AvroTypes_proc_Union__10__::get_GroupProcessedField() const {
    if (idx_ != 33) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<GroupProcessedField >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_GroupProcessedField(const GroupProcessedField& v) {
    idx_ = 33;
    value_ = v;
}

inline
TM_ProcessedFrame AvroTypes_proc_Union__10__::get_TM_ProcessedFrame() const {
    if (idx_ != 34) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TM_ProcessedFrame >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TM_ProcessedFrame(const TM_ProcessedFrame& v) {
    idx_ = 34;
    value_ = v;
}

inline
User AvroTypes_proc_Union__10__::get_User() const {
    if (idx_ != 35) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<User >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_User(const User& v) {
    idx_ = 35;
    value_ = v;
}

inline
XTCE_ProcessedFrame AvroTypes_proc_Union__10__::get_XTCE_ProcessedFrame() const {
    if (idx_ != 36) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<XTCE_ProcessedFrame >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_XTCE_ProcessedFrame(const XTCE_ProcessedFrame& v) {
    idx_ = 36;
    value_ = v;
}

inline
TM_FrameField AvroTypes_proc_Union__10__::get_TM_FrameField() const {
    if (idx_ != 37) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TM_FrameField >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TM_FrameField(const TM_FrameField& v) {
    idx_ = 37;
    value_ = v;
}

inline
TM_FrameCondition AvroTypes_proc_Union__10__::get_TM_FrameCondition() const {
    if (idx_ != 38) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TM_FrameCondition >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TM_FrameCondition(const TM_FrameCondition& v) {
    idx_ = 38;
    value_ = v;
}

inline
TM_Frame AvroTypes_proc_Union__10__::get_TM_Frame() const {
    if (idx_ != 39) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<TM_Frame >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_TM_Frame(const TM_Frame& v) {
    idx_ = 39;
    value_ = v;
}

inline
ListFrameTypes AvroTypes_proc_Union__10__::get_ListFrameTypes() const {
    if (idx_ != 40) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListFrameTypes >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListFrameTypes(const ListFrameTypes& v) {
    idx_ = 40;
    value_ = v;
}

inline
ListGroundStations AvroTypes_proc_Union__10__::get_ListGroundStations() const {
    if (idx_ != 41) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListGroundStations >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListGroundStations(const ListGroundStations& v) {
    idx_ = 41;
    value_ = v;
}

inline
ListKeyValues AvroTypes_proc_Union__10__::get_ListKeyValues() const {
    if (idx_ != 42) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListKeyValues >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListKeyValues(const ListKeyValues& v) {
    idx_ = 42;
    value_ = v;
}

inline
ListParameters AvroTypes_proc_Union__10__::get_ListParameters() const {
    if (idx_ != 43) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListParameters >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListParameters(const ListParameters& v) {
    idx_ = 43;
    value_ = v;
}

inline
ListLayers AvroTypes_proc_Union__10__::get_ListLayers() const {
    if (idx_ != 44) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListLayers >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListLayers(const ListLayers& v) {
    idx_ = 44;
    value_ = v;
}

inline
ListPasses AvroTypes_proc_Union__10__::get_ListPasses() const {
    if (idx_ != 45) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListPasses >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListPasses(const ListPasses& v) {
    idx_ = 45;
    value_ = v;
}

inline
ListSatellites AvroTypes_proc_Union__10__::get_ListSatellites() const {
    if (idx_ != 46) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListSatellites >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListSatellites(const ListSatellites& v) {
    idx_ = 46;
    value_ = v;
}

inline
ListTC_Parameters AvroTypes_proc_Union__10__::get_ListTC_Parameters() const {
    if (idx_ != 47) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListTC_Parameters >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListTC_Parameters(const ListTC_Parameters& v) {
    idx_ = 47;
    value_ = v;
}

inline
ListTM_Parameters AvroTypes_proc_Union__10__::get_ListTM_Parameters() const {
    if (idx_ != 48) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListTM_Parameters >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_ListTM_Parameters(const ListTM_Parameters& v) {
    idx_ = 48;
    value_ = v;
}

inline
MsgAddGroundStation AvroTypes_proc_Union__10__::get_MsgAddGroundStation() const {
    if (idx_ != 49) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddGroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddGroundStation(const MsgAddGroundStation& v) {
    idx_ = 49;
    value_ = v;
}

inline
MsgAddMission AvroTypes_proc_Union__10__::get_MsgAddMission() const {
    if (idx_ != 50) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddMission >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddMission(const MsgAddMission& v) {
    idx_ = 50;
    value_ = v;
}

inline
MsgAddMissionLayer AvroTypes_proc_Union__10__::get_MsgAddMissionLayer() const {
    if (idx_ != 51) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddMissionLayer >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddMissionLayer(const MsgAddMissionLayer& v) {
    idx_ = 51;
    value_ = v;
}

inline
MsgAddNode AvroTypes_proc_Union__10__::get_MsgAddNode() const {
    if (idx_ != 52) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddNode >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddNode(const MsgAddNode& v) {
    idx_ = 52;
    value_ = v;
}

inline
MsgAddRawFrame AvroTypes_proc_Union__10__::get_MsgAddRawFrame() const {
    if (idx_ != 53) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddRawFrame >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddRawFrame(const MsgAddRawFrame& v) {
    idx_ = 53;
    value_ = v;
}

inline
MsgAddSatellite AvroTypes_proc_Union__10__::get_MsgAddSatellite() const {
    if (idx_ != 54) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddSatellite >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddSatellite(const MsgAddSatellite& v) {
    idx_ = 54;
    value_ = v;
}

inline
MsgAddSubsystem AvroTypes_proc_Union__10__::get_MsgAddSubsystem() const {
    if (idx_ != 55) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddSubsystem >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddSubsystem(const MsgAddSubsystem& v) {
    idx_ = 55;
    value_ = v;
}

inline
MsgAddTcParameter AvroTypes_proc_Union__10__::get_MsgAddTcParameter() const {
    if (idx_ != 56) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddTcParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddTcParameter(const MsgAddTcParameter& v) {
    idx_ = 56;
    value_ = v;
}

inline
MsgAddTmParameter AvroTypes_proc_Union__10__::get_MsgAddTmParameter() const {
    if (idx_ != 57) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgAddTmParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgAddTmParameter(const MsgAddTmParameter& v) {
    idx_ = 57;
    value_ = v;
}

inline
MsgCheckLicence AvroTypes_proc_Union__10__::get_MsgCheckLicence() const {
    if (idx_ != 58) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgCheckLicence >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgCheckLicence(const MsgCheckLicence& v) {
    idx_ = 58;
    value_ = v;
}

inline
MsgCheckLicenceResponse AvroTypes_proc_Union__10__::get_MsgCheckLicenceResponse() const {
    if (idx_ != 59) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgCheckLicenceResponse >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgCheckLicenceResponse(const MsgCheckLicenceResponse& v) {
    idx_ = 59;
    value_ = v;
}

inline
MsgConnectGroundStation AvroTypes_proc_Union__10__::get_MsgConnectGroundStation() const {
    if (idx_ != 60) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgConnectGroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgConnectGroundStation(const MsgConnectGroundStation& v) {
    idx_ = 60;
    value_ = v;
}

inline
MsgDisconnectGroundStation AvroTypes_proc_Union__10__::get_MsgDisconnectGroundStation() const {
    if (idx_ != 61) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgDisconnectGroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgDisconnectGroundStation(const MsgDisconnectGroundStation& v) {
    idx_ = 61;
    value_ = v;
}

inline
MsgEndModuleExecution AvroTypes_proc_Union__10__::get_MsgEndModuleExecution() const {
    if (idx_ != 62) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgEndModuleExecution >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgEndModuleExecution(const MsgEndModuleExecution& v) {
    idx_ = 62;
    value_ = v;
}

inline
MsgFds AvroTypes_proc_Union__10__::get_MsgFds() const {
    if (idx_ != 63) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgFds >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgFds(const MsgFds& v) {
    idx_ = 63;
    value_ = v;
}

inline
MsgGetDefaultMissionLayers AvroTypes_proc_Union__10__::get_MsgGetDefaultMissionLayers() const {
    if (idx_ != 64) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetDefaultMissionLayers >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetDefaultMissionLayers(const MsgGetDefaultMissionLayers& v) {
    idx_ = 64;
    value_ = v;
}

inline
MsgGetFrameTypes AvroTypes_proc_Union__10__::get_MsgGetFrameTypes() const {
    if (idx_ != 65) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetFrameTypes >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetFrameTypes(const MsgGetFrameTypes& v) {
    idx_ = 65;
    value_ = v;
}

inline
MsgGetGroundStation AvroTypes_proc_Union__10__::get_MsgGetGroundStation() const {
    if (idx_ != 66) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetGroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetGroundStation(const MsgGetGroundStation& v) {
    idx_ = 66;
    value_ = v;
}

inline
MsgGetLayerParameters AvroTypes_proc_Union__10__::get_MsgGetLayerParameters() const {
    if (idx_ != 67) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetLayerParameters >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetLayerParameters(const MsgGetLayerParameters& v) {
    idx_ = 67;
    value_ = v;
}

inline
MsgGetMission AvroTypes_proc_Union__10__::get_MsgGetMission() const {
    if (idx_ != 68) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetMission >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetMission(const MsgGetMission& v) {
    idx_ = 68;
    value_ = v;
}

inline
MsgGetMissionLayers AvroTypes_proc_Union__10__::get_MsgGetMissionLayers() const {
    if (idx_ != 69) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetMissionLayers >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetMissionLayers(const MsgGetMissionLayers& v) {
    idx_ = 69;
    value_ = v;
}

inline
MsgGetNode AvroTypes_proc_Union__10__::get_MsgGetNode() const {
    if (idx_ != 70) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetNode >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetNode(const MsgGetNode& v) {
    idx_ = 70;
    value_ = v;
}

inline
MsgGetPasses AvroTypes_proc_Union__10__::get_MsgGetPasses() const {
    if (idx_ != 71) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetPasses >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetPasses(const MsgGetPasses& v) {
    idx_ = 71;
    value_ = v;
}

inline
MsgGetSatellite AvroTypes_proc_Union__10__::get_MsgGetSatellite() const {
    if (idx_ != 72) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetSatellite >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetSatellite(const MsgGetSatellite& v) {
    idx_ = 72;
    value_ = v;
}

inline
MsgGetStatus AvroTypes_proc_Union__10__::get_MsgGetStatus() const {
    if (idx_ != 73) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetStatus >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetStatus(const MsgGetStatus& v) {
    idx_ = 73;
    value_ = v;
}

inline
MsgGetStatusResponse AvroTypes_proc_Union__10__::get_MsgGetStatusResponse() const {
    if (idx_ != 74) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetStatusResponse >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetStatusResponse(const MsgGetStatusResponse& v) {
    idx_ = 74;
    value_ = v;
}

inline
MsgGetSubsystem AvroTypes_proc_Union__10__::get_MsgGetSubsystem() const {
    if (idx_ != 75) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetSubsystem >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetSubsystem(const MsgGetSubsystem& v) {
    idx_ = 75;
    value_ = v;
}

inline
MsgGetTcParameter AvroTypes_proc_Union__10__::get_MsgGetTcParameter() const {
    if (idx_ != 76) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetTcParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetTcParameter(const MsgGetTcParameter& v) {
    idx_ = 76;
    value_ = v;
}

inline
MsgGetTmParameter AvroTypes_proc_Union__10__::get_MsgGetTmParameter() const {
    if (idx_ != 77) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetTmParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgGetTmParameter(const MsgGetTmParameter& v) {
    idx_ = 77;
    value_ = v;
}

inline
MsgHeader AvroTypes_proc_Union__10__::get_MsgHeader() const {
    if (idx_ != 78) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgHeader >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgHeader(const MsgHeader& v) {
    idx_ = 78;
    value_ = v;
}

inline
MsgImportScDatabase AvroTypes_proc_Union__10__::get_MsgImportScDatabase() const {
    if (idx_ != 79) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgImportScDatabase >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgImportScDatabase(const MsgImportScDatabase& v) {
    idx_ = 79;
    value_ = v;
}

inline
MsgLogin AvroTypes_proc_Union__10__::get_MsgLogin() const {
    if (idx_ != 80) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgLogin >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgLogin(const MsgLogin& v) {
    idx_ = 80;
    value_ = v;
}

inline
MsgLoginResponse AvroTypes_proc_Union__10__::get_MsgLoginResponse() const {
    if (idx_ != 81) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgLoginResponse >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgLoginResponse(const MsgLoginResponse& v) {
    idx_ = 81;
    value_ = v;
}

inline
MsgLogout AvroTypes_proc_Union__10__::get_MsgLogout() const {
    if (idx_ != 82) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgLogout >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgLogout(const MsgLogout& v) {
    idx_ = 82;
    value_ = v;
}

inline
MsgProcessRawFrame AvroTypes_proc_Union__10__::get_MsgProcessRawFrame() const {
    if (idx_ != 83) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgProcessRawFrame >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgProcessRawFrame(const MsgProcessRawFrame& v) {
    idx_ = 83;
    value_ = v;
}

inline
MsgPublishEvent AvroTypes_proc_Union__10__::get_MsgPublishEvent() const {
    if (idx_ != 84) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgPublishEvent >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgPublishEvent(const MsgPublishEvent& v) {
    idx_ = 84;
    value_ = v;
}

inline
MsgRegisterUserOld AvroTypes_proc_Union__10__::get_MsgRegisterUserOld() const {
    if (idx_ != 85) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRegisterUserOld >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRegisterUserOld(const MsgRegisterUserOld& v) {
    idx_ = 85;
    value_ = v;
}

inline
MsgRegisterUser AvroTypes_proc_Union__10__::get_MsgRegisterUser() const {
    if (idx_ != 86) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRegisterUser >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRegisterUser(const MsgRegisterUser& v) {
    idx_ = 86;
    value_ = v;
}

inline
MsgRemoveGroundStation AvroTypes_proc_Union__10__::get_MsgRemoveGroundStation() const {
    if (idx_ != 87) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveGroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveGroundStation(const MsgRemoveGroundStation& v) {
    idx_ = 87;
    value_ = v;
}

inline
MsgRemoveMissionLayer AvroTypes_proc_Union__10__::get_MsgRemoveMissionLayer() const {
    if (idx_ != 88) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveMissionLayer >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveMissionLayer(const MsgRemoveMissionLayer& v) {
    idx_ = 88;
    value_ = v;
}

inline
MsgRemoveMission AvroTypes_proc_Union__10__::get_MsgRemoveMission() const {
    if (idx_ != 89) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveMission >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveMission(const MsgRemoveMission& v) {
    idx_ = 89;
    value_ = v;
}

inline
MsgRemoveNode AvroTypes_proc_Union__10__::get_MsgRemoveNode() const {
    if (idx_ != 90) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveNode >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveNode(const MsgRemoveNode& v) {
    idx_ = 90;
    value_ = v;
}

inline
MsgRemoveSatellite AvroTypes_proc_Union__10__::get_MsgRemoveSatellite() const {
    if (idx_ != 91) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveSatellite >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveSatellite(const MsgRemoveSatellite& v) {
    idx_ = 91;
    value_ = v;
}

inline
MsgRemoveSubsystem AvroTypes_proc_Union__10__::get_MsgRemoveSubsystem() const {
    if (idx_ != 92) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveSubsystem >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveSubsystem(const MsgRemoveSubsystem& v) {
    idx_ = 92;
    value_ = v;
}

inline
MsgRemoveTcParameter AvroTypes_proc_Union__10__::get_MsgRemoveTcParameter() const {
    if (idx_ != 93) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveTcParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveTcParameter(const MsgRemoveTcParameter& v) {
    idx_ = 93;
    value_ = v;
}

inline
MsgRemoveTmParameter AvroTypes_proc_Union__10__::get_MsgRemoveTmParameter() const {
    if (idx_ != 94) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRemoveTmParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgRemoveTmParameter(const MsgRemoveTmParameter& v) {
    idx_ = 94;
    value_ = v;
}

inline
MsgReturnData AvroTypes_proc_Union__10__::get_MsgReturnData() const {
    if (idx_ != 95) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgReturnData >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgReturnData(const MsgReturnData& v) {
    idx_ = 95;
    value_ = v;
}

inline
MsgSendFrameGroundStation AvroTypes_proc_Union__10__::get_MsgSendFrameGroundStation() const {
    if (idx_ != 96) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgSendFrameGroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgSendFrameGroundStation(const MsgSendFrameGroundStation& v) {
    idx_ = 96;
    value_ = v;
}

inline
MsgShutdown AvroTypes_proc_Union__10__::get_MsgShutdown() const {
    if (idx_ != 97) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgShutdown >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgShutdown(const MsgShutdown& v) {
    idx_ = 97;
    value_ = v;
}

inline
MsgStartModuleExecution AvroTypes_proc_Union__10__::get_MsgStartModuleExecution() const {
    if (idx_ != 98) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgStartModuleExecution >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgStartModuleExecution(const MsgStartModuleExecution& v) {
    idx_ = 98;
    value_ = v;
}

inline
MsgStartup AvroTypes_proc_Union__10__::get_MsgStartup() const {
    if (idx_ != 99) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgStartup >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgStartup(const MsgStartup& v) {
    idx_ = 99;
    value_ = v;
}

inline
MsgUpdateGroundStation AvroTypes_proc_Union__10__::get_MsgUpdateGroundStation() const {
    if (idx_ != 100) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgUpdateGroundStation >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgUpdateGroundStation(const MsgUpdateGroundStation& v) {
    idx_ = 100;
    value_ = v;
}

inline
MsgUpdateMission AvroTypes_proc_Union__10__::get_MsgUpdateMission() const {
    if (idx_ != 101) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgUpdateMission >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgUpdateMission(const MsgUpdateMission& v) {
    idx_ = 101;
    value_ = v;
}

inline
MsgUpdateNode AvroTypes_proc_Union__10__::get_MsgUpdateNode() const {
    if (idx_ != 102) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgUpdateNode >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgUpdateNode(const MsgUpdateNode& v) {
    idx_ = 102;
    value_ = v;
}

inline
MsgUpdateSatellite AvroTypes_proc_Union__10__::get_MsgUpdateSatellite() const {
    if (idx_ != 103) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgUpdateSatellite >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgUpdateSatellite(const MsgUpdateSatellite& v) {
    idx_ = 103;
    value_ = v;
}

inline
MsgUpdateSubsystem AvroTypes_proc_Union__10__::get_MsgUpdateSubsystem() const {
    if (idx_ != 104) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgUpdateSubsystem >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgUpdateSubsystem(const MsgUpdateSubsystem& v) {
    idx_ = 104;
    value_ = v;
}

inline
MsgUpdateTcParameter AvroTypes_proc_Union__10__::get_MsgUpdateTcParameter() const {
    if (idx_ != 105) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgUpdateTcParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgUpdateTcParameter(const MsgUpdateTcParameter& v) {
    idx_ = 105;
    value_ = v;
}

inline
MsgUpdateTmParameter AvroTypes_proc_Union__10__::get_MsgUpdateTmParameter() const {
    if (idx_ != 106) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgUpdateTmParameter >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_MsgUpdateTmParameter(const MsgUpdateTmParameter& v) {
    idx_ = 106;
    value_ = v;
}

inline
AvroNone AvroTypes_proc_Union__10__::get_AvroNone() const {
    if (idx_ != 107) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroNone >(value_);
}

inline
void AvroTypes_proc_Union__10__::set_AvroNone(const AvroNone& v) {
    idx_ = 107;
    value_ = v;
}

inline AvroTypes_proc_Union__0__::AvroTypes_proc_Union__0__() : idx_(0) { }
inline AvroTypes_proc_Union__1__::AvroTypes_proc_Union__1__() : idx_(0) { }
inline AvroTypes_proc_Union__2__::AvroTypes_proc_Union__2__() : idx_(0) { }
inline AvroTypes_proc_Union__3__::AvroTypes_proc_Union__3__() : idx_(0) { }
inline AvroTypes_proc_Union__4__::AvroTypes_proc_Union__4__() : idx_(0) { }
inline AvroTypes_proc_Union__5__::AvroTypes_proc_Union__5__() : idx_(0) { }
inline AvroTypes_proc_Union__6__::AvroTypes_proc_Union__6__() : idx_(0) { }
inline AvroTypes_proc_Union__7__::AvroTypes_proc_Union__7__() : idx_(0) { }
inline AvroTypes_proc_Union__8__::AvroTypes_proc_Union__8__() : idx_(0) { }
inline AvroTypes_proc_Union__9__::AvroTypes_proc_Union__9__() : idx_(0) { }
inline AvroTypes_proc_Union__10__::AvroTypes_proc_Union__10__() : idx_(0), value_(TmTypeEnum()) { }
}
namespace avro {
template<> struct codec_traits<IW::TmTypeEnum> {
    static void encode(Encoder& e, IW::TmTypeEnum v) {
		if (v < IW::TM_TYPE_NONE || v > IW::TM_TYPE_BYTE_STREAM)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::TmTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::TmTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::TM_TYPE_NONE || index > IW::TM_TYPE_BYTE_STREAM)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::TmTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::TmTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::TmSubTypeEnum> {
    static void encode(Encoder& e, IW::TmSubTypeEnum v) {
		if (v < IW::TM_SUBTYPE_NONE || v > IW::TM_SUBTYPE_UINT64)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::TmSubTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::TmSubTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::TM_SUBTYPE_NONE || index > IW::TM_SUBTYPE_UINT64)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::TmSubTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::TmSubTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::TmEngTypeEnum> {
    static void encode(Encoder& e, IW::TmEngTypeEnum v) {
		if (v < IW::TM_ENGTYPE_NONE || v > IW::TM_ENGTYPE_BINARY)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::TmEngTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::TmEngTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::TM_ENGTYPE_NONE || index > IW::TM_ENGTYPE_BINARY)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::TmEngTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::TmEngTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::RadixEnum> {
    static void encode(Encoder& e, IW::RadixEnum v) {
		if (v < IW::RADIX_NONE || v > IW::RADIX_HEXADECIMAL)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::RadixEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::RadixEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::RADIX_NONE || index > IW::RADIX_HEXADECIMAL)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::RadixEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::RadixEnum>(index);
    }
};

template<> struct codec_traits<IW::ModuleTypeEnum> {
    static void encode(Encoder& e, IW::ModuleTypeEnum v) {
		if (v < IW::EXTERNAL_MODULE || v > IW::INTERNAL_MODULE)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::ModuleTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::ModuleTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::EXTERNAL_MODULE || index > IW::INTERNAL_MODULE)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::ModuleTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::ModuleTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::Subsystem> {
    static void encode(Encoder& e, const IW::Subsystem& v) {
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.satelliteName);
    }
    static void decode(Decoder& d, IW::Subsystem& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.name);
                    break;
                case 1:
                    avro::decode(d, v.description);
                    break;
                case 2:
                    avro::decode(d, v.satelliteName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.satelliteName);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__0__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<IW::Subsystem > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::Satellite> {
    static void encode(Encoder& e, const IW::Satellite& v) {
        avro::encode(e, v.name);
        avro::encode(e, v.missionName);
        avro::encode(e, v.description);
        avro::encode(e, v.code);
        avro::encode(e, v.launchDate);
        avro::encode(e, v.listSubsystems);
    }
    static void decode(Decoder& d, IW::Satellite& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.name);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.description);
                    break;
                case 3:
                    avro::decode(d, v.code);
                    break;
                case 4:
                    avro::decode(d, v.launchDate);
                    break;
                case 5:
                    avro::decode(d, v.listSubsystems);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.name);
            avro::decode(d, v.missionName);
            avro::decode(d, v.description);
            avro::decode(d, v.code);
            avro::decode(d, v.launchDate);
            avro::decode(d, v.listSubsystems);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__1__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__1__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__1__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<IW::Satellite > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::Mission> {
    static void encode(Encoder& e, const IW::Mission& v) {
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.country);
        avro::encode(e, v.owner);
        avro::encode(e, v.creationTime);
        avro::encode(e, v.adminIdentifier);
        avro::encode(e, v.emailAddress);
        avro::encode(e, v.phoneNumber);
        avro::encode(e, v.listSatellites);
    }
    static void decode(Decoder& d, IW::Mission& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.name);
                    break;
                case 1:
                    avro::decode(d, v.description);
                    break;
                case 2:
                    avro::decode(d, v.country);
                    break;
                case 3:
                    avro::decode(d, v.owner);
                    break;
                case 4:
                    avro::decode(d, v.creationTime);
                    break;
                case 5:
                    avro::decode(d, v.adminIdentifier);
                    break;
                case 6:
                    avro::decode(d, v.emailAddress);
                    break;
                case 7:
                    avro::decode(d, v.phoneNumber);
                    break;
                case 8:
                    avro::decode(d, v.listSatellites);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.country);
            avro::decode(d, v.owner);
            avro::decode(d, v.creationTime);
            avro::decode(d, v.adminIdentifier);
            avro::decode(d, v.emailAddress);
            avro::decode(d, v.phoneNumber);
            avro::decode(d, v.listSatellites);
        }
    }
};

template<> struct codec_traits<IW::WatchTriggerTypeEnum> {
    static void encode(Encoder& e, IW::WatchTriggerTypeEnum v) {
		if (v < IW::Low || v > IW::State)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::WatchTriggerTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::WatchTriggerTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::Low || index > IW::State)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::WatchTriggerTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::WatchTriggerTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::AlarmReportTypeEnum> {
    static void encode(Encoder& e, IW::AlarmReportTypeEnum v) {
		if (v < IW::ALARM_REPORT_ON_VALUE_CHANGE || v > IW::ALARM_REPORT_ON_SEVERITY_CHANGE)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::AlarmReportTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::AlarmReportTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::ALARM_REPORT_ON_VALUE_CHANGE || index > IW::ALARM_REPORT_ON_SEVERITY_CHANGE)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::AlarmReportTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::AlarmReportTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::AlarmContext> {
    static void encode(Encoder& e, const IW::AlarmContext& v) {
        avro::encode(e, v.parameterName);
        avro::encode(e, v.reportType);
        avro::encode(e, v.minimumViolations);
        avro::encode(e, v.watchTriggerType);
        avro::encode(e, v.watchTriggerValue);
        avro::encode(e, v.warningTriggerType);
        avro::encode(e, v.warningTriggerValue);
        avro::encode(e, v.distressTriggerType);
        avro::encode(e, v.distressTriggerValue);
        avro::encode(e, v.criticalTriggerType);
        avro::encode(e, v.criticalTriggerValue);
        avro::encode(e, v.severeTriggerType);
        avro::encode(e, v.severeTriggerValue);
    }
    static void decode(Decoder& d, IW::AlarmContext& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.parameterName);
                    break;
                case 1:
                    avro::decode(d, v.reportType);
                    break;
                case 2:
                    avro::decode(d, v.minimumViolations);
                    break;
                case 3:
                    avro::decode(d, v.watchTriggerType);
                    break;
                case 4:
                    avro::decode(d, v.watchTriggerValue);
                    break;
                case 5:
                    avro::decode(d, v.warningTriggerType);
                    break;
                case 6:
                    avro::decode(d, v.warningTriggerValue);
                    break;
                case 7:
                    avro::decode(d, v.distressTriggerType);
                    break;
                case 8:
                    avro::decode(d, v.distressTriggerValue);
                    break;
                case 9:
                    avro::decode(d, v.criticalTriggerType);
                    break;
                case 10:
                    avro::decode(d, v.criticalTriggerValue);
                    break;
                case 11:
                    avro::decode(d, v.severeTriggerType);
                    break;
                case 12:
                    avro::decode(d, v.severeTriggerValue);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.parameterName);
            avro::decode(d, v.reportType);
            avro::decode(d, v.minimumViolations);
            avro::decode(d, v.watchTriggerType);
            avro::decode(d, v.watchTriggerValue);
            avro::decode(d, v.warningTriggerType);
            avro::decode(d, v.warningTriggerValue);
            avro::decode(d, v.distressTriggerType);
            avro::decode(d, v.distressTriggerValue);
            avro::decode(d, v.criticalTriggerType);
            avro::decode(d, v.criticalTriggerValue);
            avro::decode(d, v.severeTriggerType);
            avro::decode(d, v.severeTriggerValue);
        }
    }
};

template<> struct codec_traits<IW::Alarm> {
    static void encode(Encoder& e, const IW::Alarm& v) {
        avro::encode(e, v.parameterName);
        avro::encode(e, v.listAlarmContext);
    }
    static void decode(Decoder& d, IW::Alarm& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.parameterName);
                    break;
                case 1:
                    avro::decode(d, v.listAlarmContext);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.parameterName);
            avro::decode(d, v.listAlarmContext);
        }
    }
};

template<> struct codec_traits<IW::AlgorithmParameter> {
    static void encode(Encoder& e, const IW::AlgorithmParameter& v) {
        avro::encode(e, v.algorithmName);
        avro::encode(e, v.parameterName);
        avro::encode(e, v.parameterValue);
        avro::encode(e, v.inputOutputType);
        avro::encode(e, v.nameInAlgorithm);
        avro::encode(e, v.mandatoryFlag);
        avro::encode(e, v.subsystem);
    }
    static void decode(Decoder& d, IW::AlgorithmParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.algorithmName);
                    break;
                case 1:
                    avro::decode(d, v.parameterName);
                    break;
                case 2:
                    avro::decode(d, v.parameterValue);
                    break;
                case 3:
                    avro::decode(d, v.inputOutputType);
                    break;
                case 4:
                    avro::decode(d, v.nameInAlgorithm);
                    break;
                case 5:
                    avro::decode(d, v.mandatoryFlag);
                    break;
                case 6:
                    avro::decode(d, v.subsystem);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.algorithmName);
            avro::decode(d, v.parameterName);
            avro::decode(d, v.parameterValue);
            avro::decode(d, v.inputOutputType);
            avro::decode(d, v.nameInAlgorithm);
            avro::decode(d, v.mandatoryFlag);
            avro::decode(d, v.subsystem);
        }
    }
};

template<> struct codec_traits<IW::AlgorithmLanguageEnum> {
    static void encode(Encoder& e, IW::AlgorithmLanguageEnum v) {
		if (v < IW::ALGORITHM_JAVASCRIPT || v > IW::ALGORITHM_JAVA)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::AlgorithmLanguageEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::AlgorithmLanguageEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::ALGORITHM_JAVASCRIPT || index > IW::ALGORITHM_JAVA)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::AlgorithmLanguageEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::AlgorithmLanguageEnum>(index);
    }
};

template<> struct codec_traits<IW::TriggerEnum> {
    static void encode(Encoder& e, IW::TriggerEnum v) {
		if (v < IW::ALGORITHM_TRIGGER_NONE || v > IW::ALGORITHM_ON_PERIODIC_RATE)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::TriggerEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::TriggerEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::ALGORITHM_TRIGGER_NONE || index > IW::ALGORITHM_ON_PERIODIC_RATE)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::TriggerEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::TriggerEnum>(index);
    }
};

template<> struct codec_traits<IW::Algorithm> {
    static void encode(Encoder& e, const IW::Algorithm& v) {
        avro::encode(e, v.algorithmName);
        avro::encode(e, v.algorithmLanguage);
        avro::encode(e, v.sourceCode);
        avro::encode(e, v.trigger);
        avro::encode(e, v.listAlgVariables);
        avro::encode(e, v.subsystem);
    }
    static void decode(Decoder& d, IW::Algorithm& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.algorithmName);
                    break;
                case 1:
                    avro::decode(d, v.algorithmLanguage);
                    break;
                case 2:
                    avro::decode(d, v.sourceCode);
                    break;
                case 3:
                    avro::decode(d, v.trigger);
                    break;
                case 4:
                    avro::decode(d, v.listAlgVariables);
                    break;
                case 5:
                    avro::decode(d, v.subsystem);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.algorithmName);
            avro::decode(d, v.algorithmLanguage);
            avro::decode(d, v.sourceCode);
            avro::decode(d, v.trigger);
            avro::decode(d, v.listAlgVariables);
            avro::decode(d, v.subsystem);
        }
    }
};

template<> struct codec_traits<IW::CalibrationItem> {
    static void encode(Encoder& e, const IW::CalibrationItem& v) {
        avro::encode(e, v.calibration1);
        avro::encode(e, v.calibration2);
        avro::encode(e, v.calibration2_text);
    }
    static void decode(Decoder& d, IW::CalibrationItem& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.calibration1);
                    break;
                case 1:
                    avro::decode(d, v.calibration2);
                    break;
                case 2:
                    avro::decode(d, v.calibration2_text);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.calibration1);
            avro::decode(d, v.calibration2);
            avro::decode(d, v.calibration2_text);
        }
    }
};

template<> struct codec_traits<IW::TmCalibrationTypeEnum> {
    static void encode(Encoder& e, IW::TmCalibrationTypeEnum v) {
		if (v < IW::TM_CALIBRATION_ENUMERATION || v > IW::TM_CALIBRATION_EXPRESSION)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::TmCalibrationTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::TmCalibrationTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::TM_CALIBRATION_ENUMERATION || index > IW::TM_CALIBRATION_EXPRESSION)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::TmCalibrationTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::TmCalibrationTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::Calibration> {
    static void encode(Encoder& e, const IW::Calibration& v) {
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.calibrationType);
        avro::encode(e, v.subsystem);
        avro::encode(e, v.listCalibrationItems);
    }
    static void decode(Decoder& d, IW::Calibration& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.name);
                    break;
                case 1:
                    avro::decode(d, v.description);
                    break;
                case 2:
                    avro::decode(d, v.calibrationType);
                    break;
                case 3:
                    avro::decode(d, v.subsystem);
                    break;
                case 4:
                    avro::decode(d, v.listCalibrationItems);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.calibrationType);
            avro::decode(d, v.subsystem);
            avro::decode(d, v.listCalibrationItems);
        }
    }
};

template<> struct codec_traits<IW::ConfigurationParameter> {
    static void encode(Encoder& e, const IW::ConfigurationParameter& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.type);
        avro::encode(e, v.value);
        avro::encode(e, v.userId);
        avro::encode(e, v.missionName);
        avro::encode(e, v.layerName);
    }
    static void decode(Decoder& d, IW::ConfigurationParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.description);
                    break;
                case 3:
                    avro::decode(d, v.type);
                    break;
                case 4:
                    avro::decode(d, v.value);
                    break;
                case 5:
                    avro::decode(d, v.userId);
                    break;
                case 6:
                    avro::decode(d, v.missionName);
                    break;
                case 7:
                    avro::decode(d, v.layerName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.type);
            avro::decode(d, v.value);
            avro::decode(d, v.userId);
            avro::decode(d, v.missionName);
            avro::decode(d, v.layerName);
        }
    }
};

template<> struct codec_traits<IW::Derived_TM_Parameter> {
    static void encode(Encoder& e, const IW::Derived_TM_Parameter& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.displayName);
        avro::encode(e, v.description);
        avro::encode(e, v.lengthBits);
        avro::encode(e, v.prependSize);
        avro::encode(e, v.stringTerminator);
        avro::encode(e, v.littleEndian);
        avro::encode(e, v.valueType);
        avro::encode(e, v.valueSubType);
        avro::encode(e, v.engType);
        avro::encode(e, v.units);
        avro::encode(e, v.calibrationFunction);
        avro::encode(e, v.subsystem);
    }
    static void decode(Decoder& d, IW::Derived_TM_Parameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.displayName);
                    break;
                case 3:
                    avro::decode(d, v.description);
                    break;
                case 4:
                    avro::decode(d, v.lengthBits);
                    break;
                case 5:
                    avro::decode(d, v.prependSize);
                    break;
                case 6:
                    avro::decode(d, v.stringTerminator);
                    break;
                case 7:
                    avro::decode(d, v.littleEndian);
                    break;
                case 8:
                    avro::decode(d, v.valueType);
                    break;
                case 9:
                    avro::decode(d, v.valueSubType);
                    break;
                case 10:
                    avro::decode(d, v.engType);
                    break;
                case 11:
                    avro::decode(d, v.units);
                    break;
                case 12:
                    avro::decode(d, v.calibrationFunction);
                    break;
                case 13:
                    avro::decode(d, v.subsystem);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.displayName);
            avro::decode(d, v.description);
            avro::decode(d, v.lengthBits);
            avro::decode(d, v.prependSize);
            avro::decode(d, v.stringTerminator);
            avro::decode(d, v.littleEndian);
            avro::decode(d, v.valueType);
            avro::decode(d, v.valueSubType);
            avro::decode(d, v.engType);
            avro::decode(d, v.units);
            avro::decode(d, v.calibrationFunction);
            avro::decode(d, v.subsystem);
        }
    }
};

template<> struct codec_traits<IW::Event> {
    static void encode(Encoder& e, const IW::Event& v) {
        avro::encode(e, v.type);
        avro::encode(e, v.eventTime);
        avro::encode(e, v.data);
        avro::encode(e, v.dataLength);
    }
    static void decode(Decoder& d, IW::Event& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.type);
                    break;
                case 1:
                    avro::decode(d, v.eventTime);
                    break;
                case 2:
                    avro::decode(d, v.data);
                    break;
                case 3:
                    avro::decode(d, v.dataLength);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.type);
            avro::decode(d, v.eventTime);
            avro::decode(d, v.data);
            avro::decode(d, v.dataLength);
        }
    }
};

template<> struct codec_traits<IW::FdsModule> {
    static void encode(Encoder& e, const IW::FdsModule& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.type);
        avro::encode(e, v.binary_file);
    }
    static void decode(Decoder& d, IW::FdsModule& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.description);
                    break;
                case 3:
                    avro::decode(d, v.type);
                    break;
                case 4:
                    avro::decode(d, v.binary_file);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.type);
            avro::decode(d, v.binary_file);
        }
    }
};

template<> struct codec_traits<IW::ConnectionTypeEnum> {
    static void encode(Encoder& e, IW::ConnectionTypeEnum v) {
		if (v < IW::NONE || v > IW::USB)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::ConnectionTypeEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::ConnectionTypeEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::NONE || index > IW::USB)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::ConnectionTypeEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::ConnectionTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::GroundStation> {
    static void encode(Encoder& e, const IW::GroundStation& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.code);
        avro::encode(e, v.owner);
        avro::encode(e, v.latitude);
        avro::encode(e, v.longitude);
        avro::encode(e, v.altitude);
        avro::encode(e, v.connectionType);
        avro::encode(e, v.url);
        avro::encode(e, v.port);
        avro::encode(e, v.comPort);
        avro::encode(e, v.speed);
        avro::encode(e, v.parity);
        avro::encode(e, v.controlBits);
    }
    static void decode(Decoder& d, IW::GroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.description);
                    break;
                case 3:
                    avro::decode(d, v.code);
                    break;
                case 4:
                    avro::decode(d, v.owner);
                    break;
                case 5:
                    avro::decode(d, v.latitude);
                    break;
                case 6:
                    avro::decode(d, v.longitude);
                    break;
                case 7:
                    avro::decode(d, v.altitude);
                    break;
                case 8:
                    avro::decode(d, v.connectionType);
                    break;
                case 9:
                    avro::decode(d, v.url);
                    break;
                case 10:
                    avro::decode(d, v.port);
                    break;
                case 11:
                    avro::decode(d, v.comPort);
                    break;
                case 12:
                    avro::decode(d, v.speed);
                    break;
                case 13:
                    avro::decode(d, v.parity);
                    break;
                case 14:
                    avro::decode(d, v.controlBits);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.code);
            avro::decode(d, v.owner);
            avro::decode(d, v.latitude);
            avro::decode(d, v.longitude);
            avro::decode(d, v.altitude);
            avro::decode(d, v.connectionType);
            avro::decode(d, v.url);
            avro::decode(d, v.port);
            avro::decode(d, v.comPort);
            avro::decode(d, v.speed);
            avro::decode(d, v.parity);
            avro::decode(d, v.controlBits);
        }
    }
};

template<> struct codec_traits<IW::KeyValue> {
    static void encode(Encoder& e, const IW::KeyValue& v) {
        avro::encode(e, v.key);
        avro::encode(e, v.value);
    }
    static void decode(Decoder& d, IW::KeyValue& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.key);
                    break;
                case 1:
                    avro::decode(d, v.value);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.key);
            avro::decode(d, v.value);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__2__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__2__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__2__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<IW::ConfigurationParameter > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::Layer> {
    static void encode(Encoder& e, const IW::Layer& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.sequenceNumber);
        avro::encode(e, v.defaultFlag);
        avro::encode(e, v.missionName);
        avro::encode(e, v.listParameters);
    }
    static void decode(Decoder& d, IW::Layer& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.description);
                    break;
                case 3:
                    avro::decode(d, v.sequenceNumber);
                    break;
                case 4:
                    avro::decode(d, v.defaultFlag);
                    break;
                case 5:
                    avro::decode(d, v.missionName);
                    break;
                case 6:
                    avro::decode(d, v.listParameters);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.sequenceNumber);
            avro::decode(d, v.defaultFlag);
            avro::decode(d, v.missionName);
            avro::decode(d, v.listParameters);
        }
    }
};

template<> struct codec_traits<IW::Node> {
    static void encode(Encoder& e, const IW::Node& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.subsystemName);
    }
    static void decode(Decoder& d, IW::Node& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.description);
                    break;
                case 3:
                    avro::decode(d, v.subsystemName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.subsystemName);
        }
    }
};

template<> struct codec_traits<IW::Pass> {
    static void encode(Encoder& e, const IW::Pass& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.AOS);
        avro::encode(e, v.LOS);
        avro::encode(e, v.duration);
        avro::encode(e, v.maxElevation);
    }
    static void decode(Decoder& d, IW::Pass& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.AOS);
                    break;
                case 2:
                    avro::decode(d, v.LOS);
                    break;
                case 3:
                    avro::decode(d, v.duration);
                    break;
                case 4:
                    avro::decode(d, v.maxElevation);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.AOS);
            avro::decode(d, v.LOS);
            avro::decode(d, v.duration);
            avro::decode(d, v.maxElevation);
        }
    }
};

template<> struct codec_traits<IW::TC_Argument> {
    static void encode(Encoder& e, const IW::TC_Argument& v) {
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.tcName);
        avro::encode(e, v.relativePosition);
        avro::encode(e, v.lengthBits);
        avro::encode(e, v.argType);
        avro::encode(e, v.argSubType);
        avro::encode(e, v.engType);
        avro::encode(e, v.units);
        avro::encode(e, v.prependSize);
        avro::encode(e, v.stringTerminator);
        avro::encode(e, v.littleEndian);
        avro::encode(e, v.functionName);
        avro::encode(e, v.defaultValue);
        avro::encode(e, v.rangeLow);
        avro::encode(e, v.rangeHigh);
    }
    static void decode(Decoder& d, IW::TC_Argument& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.name);
                    break;
                case 1:
                    avro::decode(d, v.description);
                    break;
                case 2:
                    avro::decode(d, v.tcName);
                    break;
                case 3:
                    avro::decode(d, v.relativePosition);
                    break;
                case 4:
                    avro::decode(d, v.lengthBits);
                    break;
                case 5:
                    avro::decode(d, v.argType);
                    break;
                case 6:
                    avro::decode(d, v.argSubType);
                    break;
                case 7:
                    avro::decode(d, v.engType);
                    break;
                case 8:
                    avro::decode(d, v.units);
                    break;
                case 9:
                    avro::decode(d, v.prependSize);
                    break;
                case 10:
                    avro::decode(d, v.stringTerminator);
                    break;
                case 11:
                    avro::decode(d, v.littleEndian);
                    break;
                case 12:
                    avro::decode(d, v.functionName);
                    break;
                case 13:
                    avro::decode(d, v.defaultValue);
                    break;
                case 14:
                    avro::decode(d, v.rangeLow);
                    break;
                case 15:
                    avro::decode(d, v.rangeHigh);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.tcName);
            avro::decode(d, v.relativePosition);
            avro::decode(d, v.lengthBits);
            avro::decode(d, v.argType);
            avro::decode(d, v.argSubType);
            avro::decode(d, v.engType);
            avro::decode(d, v.units);
            avro::decode(d, v.prependSize);
            avro::decode(d, v.stringTerminator);
            avro::decode(d, v.littleEndian);
            avro::decode(d, v.functionName);
            avro::decode(d, v.defaultValue);
            avro::decode(d, v.rangeLow);
            avro::decode(d, v.rangeHigh);
        }
    }
};

template<> struct codec_traits<IW::TC_ArgumentAssignment> {
    static void encode(Encoder& e, const IW::TC_ArgumentAssignment& v) {
        avro::encode(e, v.tcName);
        avro::encode(e, v.argument);
        avro::encode(e, v.value);
    }
    static void decode(Decoder& d, IW::TC_ArgumentAssignment& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.tcName);
                    break;
                case 1:
                    avro::decode(d, v.argument);
                    break;
                case 2:
                    avro::decode(d, v.value);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.tcName);
            avro::decode(d, v.argument);
            avro::decode(d, v.value);
        }
    }
};

template<> struct codec_traits<IW::TC_ParameterOptions> {
    static void encode(Encoder& e, const IW::TC_ParameterOptions& v) {
        avro::encode(e, v.tcName);
        avro::encode(e, v.significance);
        avro::encode(e, v.significanceReason);
    }
    static void decode(Decoder& d, IW::TC_ParameterOptions& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.tcName);
                    break;
                case 1:
                    avro::decode(d, v.significance);
                    break;
                case 2:
                    avro::decode(d, v.significanceReason);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.tcName);
            avro::decode(d, v.significance);
            avro::decode(d, v.significanceReason);
        }
    }
};

template<> struct codec_traits<IW::TC_ParameterOptConstraints> {
    static void encode(Encoder& e, const IW::TC_ParameterOptConstraints& v) {
        avro::encode(e, v.tcName);
        avro::encode(e, v.constraint);
        avro::encode(e, v.timeout);
    }
    static void decode(Decoder& d, IW::TC_ParameterOptConstraints& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.tcName);
                    break;
                case 1:
                    avro::decode(d, v.constraint);
                    break;
                case 2:
                    avro::decode(d, v.timeout);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.tcName);
            avro::decode(d, v.constraint);
            avro::decode(d, v.timeout);
        }
    }
};

template<> struct codec_traits<IW::TcStageEnum> {
    static void encode(Encoder& e, IW::TcStageEnum v) {
		if (v < IW::TC_STAGE_TRANSFERRED || v > IW::TC_STAGE_FAILED)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::TcStageEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::TcStageEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::TC_STAGE_TRANSFERRED || index > IW::TC_STAGE_FAILED)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::TcStageEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::TcStageEnum>(index);
    }
};

template<> struct codec_traits<IW::TC_ParameterVerifier> {
    static void encode(Encoder& e, const IW::TC_ParameterVerifier& v) {
        avro::encode(e, v.tcName);
        avro::encode(e, v.tcStage);
        avro::encode(e, v.verifierType);
        avro::encode(e, v.verifierText);
        avro::encode(e, v.startTimeCheckWindow);
        avro::encode(e, v.stopTimeCheckWindow);
        avro::encode(e, v.checkWindow);
        avro::encode(e, v.onSuccess);
        avro::encode(e, v.onFail);
        avro::encode(e, v.onTimeout);
    }
    static void decode(Decoder& d, IW::TC_ParameterVerifier& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.tcName);
                    break;
                case 1:
                    avro::decode(d, v.tcStage);
                    break;
                case 2:
                    avro::decode(d, v.verifierType);
                    break;
                case 3:
                    avro::decode(d, v.verifierText);
                    break;
                case 4:
                    avro::decode(d, v.startTimeCheckWindow);
                    break;
                case 5:
                    avro::decode(d, v.stopTimeCheckWindow);
                    break;
                case 6:
                    avro::decode(d, v.checkWindow);
                    break;
                case 7:
                    avro::decode(d, v.onSuccess);
                    break;
                case 8:
                    avro::decode(d, v.onFail);
                    break;
                case 9:
                    avro::decode(d, v.onTimeout);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.tcName);
            avro::decode(d, v.tcStage);
            avro::decode(d, v.verifierType);
            avro::decode(d, v.verifierText);
            avro::decode(d, v.startTimeCheckWindow);
            avro::decode(d, v.stopTimeCheckWindow);
            avro::decode(d, v.checkWindow);
            avro::decode(d, v.onSuccess);
            avro::decode(d, v.onFail);
            avro::decode(d, v.onTimeout);
        }
    }
};

template<> struct codec_traits<IW::TC_Parameter> {
    static void encode(Encoder& e, const IW::TC_Parameter& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.displayName);
        avro::encode(e, v.description);
        avro::encode(e, v.parentName);
        avro::encode(e, v.subsystem);
        avro::encode(e, v.node);
        avro::encode(e, v.channel);
        avro::encode(e, v.lengthBits);
        avro::encode(e, v.abstractFlag);
        avro::encode(e, v.listArgument);
        avro::encode(e, v.listArgumentAssignment);
        avro::encode(e, v.listOptions);
        avro::encode(e, v.listOptConstraints);
        avro::encode(e, v.listVerifications);
    }
    static void decode(Decoder& d, IW::TC_Parameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.displayName);
                    break;
                case 3:
                    avro::decode(d, v.description);
                    break;
                case 4:
                    avro::decode(d, v.parentName);
                    break;
                case 5:
                    avro::decode(d, v.subsystem);
                    break;
                case 6:
                    avro::decode(d, v.node);
                    break;
                case 7:
                    avro::decode(d, v.channel);
                    break;
                case 8:
                    avro::decode(d, v.lengthBits);
                    break;
                case 9:
                    avro::decode(d, v.abstractFlag);
                    break;
                case 10:
                    avro::decode(d, v.listArgument);
                    break;
                case 11:
                    avro::decode(d, v.listArgumentAssignment);
                    break;
                case 12:
                    avro::decode(d, v.listOptions);
                    break;
                case 13:
                    avro::decode(d, v.listOptConstraints);
                    break;
                case 14:
                    avro::decode(d, v.listVerifications);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.displayName);
            avro::decode(d, v.description);
            avro::decode(d, v.parentName);
            avro::decode(d, v.subsystem);
            avro::decode(d, v.node);
            avro::decode(d, v.channel);
            avro::decode(d, v.lengthBits);
            avro::decode(d, v.abstractFlag);
            avro::decode(d, v.listArgument);
            avro::decode(d, v.listArgumentAssignment);
            avro::decode(d, v.listOptions);
            avro::decode(d, v.listOptConstraints);
            avro::decode(d, v.listVerifications);
        }
    }
};

template<> struct codec_traits<IW::Limit> {
    static void encode(Encoder& e, const IW::Limit& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.status);
        avro::encode(e, v.counter);
        avro::encode(e, v.minValue);
        avro::encode(e, v.maxValue);
    }
    static void decode(Decoder& d, IW::Limit& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.status);
                    break;
                case 2:
                    avro::decode(d, v.counter);
                    break;
                case 3:
                    avro::decode(d, v.minValue);
                    break;
                case 4:
                    avro::decode(d, v.maxValue);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.status);
            avro::decode(d, v.counter);
            avro::decode(d, v.minValue);
            avro::decode(d, v.maxValue);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__3__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__3__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__3__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<IW::Alarm > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::TM_Parameter> {
    static void encode(Encoder& e, const IW::TM_Parameter& v) {
        avro::encode(e, v.identifier);
        avro::encode(e, v.name);
        avro::encode(e, v.displayName);
        avro::encode(e, v.description);
        avro::encode(e, v.node);
        avro::encode(e, v.channel);
        avro::encode(e, v.lengthBits);
        avro::encode(e, v.valueType);
        avro::encode(e, v.valueSubType);
        avro::encode(e, v.engType);
        avro::encode(e, v.units);
        avro::encode(e, v.prependSize);
        avro::encode(e, v.stringTerminator);
        avro::encode(e, v.littleEndian);
        avro::encode(e, v.calibrationFunction);
        avro::encode(e, v.lengthFieldId);
        avro::encode(e, v.radix);
        avro::encode(e, v.listAlarms);
        avro::encode(e, v.subsystem);
    }
    static void decode(Decoder& d, IW::TM_Parameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.identifier);
                    break;
                case 1:
                    avro::decode(d, v.name);
                    break;
                case 2:
                    avro::decode(d, v.displayName);
                    break;
                case 3:
                    avro::decode(d, v.description);
                    break;
                case 4:
                    avro::decode(d, v.node);
                    break;
                case 5:
                    avro::decode(d, v.channel);
                    break;
                case 6:
                    avro::decode(d, v.lengthBits);
                    break;
                case 7:
                    avro::decode(d, v.valueType);
                    break;
                case 8:
                    avro::decode(d, v.valueSubType);
                    break;
                case 9:
                    avro::decode(d, v.engType);
                    break;
                case 10:
                    avro::decode(d, v.units);
                    break;
                case 11:
                    avro::decode(d, v.prependSize);
                    break;
                case 12:
                    avro::decode(d, v.stringTerminator);
                    break;
                case 13:
                    avro::decode(d, v.littleEndian);
                    break;
                case 14:
                    avro::decode(d, v.calibrationFunction);
                    break;
                case 15:
                    avro::decode(d, v.lengthFieldId);
                    break;
                case 16:
                    avro::decode(d, v.radix);
                    break;
                case 17:
                    avro::decode(d, v.listAlarms);
                    break;
                case 18:
                    avro::decode(d, v.subsystem);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.identifier);
            avro::decode(d, v.name);
            avro::decode(d, v.displayName);
            avro::decode(d, v.description);
            avro::decode(d, v.node);
            avro::decode(d, v.channel);
            avro::decode(d, v.lengthBits);
            avro::decode(d, v.valueType);
            avro::decode(d, v.valueSubType);
            avro::decode(d, v.engType);
            avro::decode(d, v.units);
            avro::decode(d, v.prependSize);
            avro::decode(d, v.stringTerminator);
            avro::decode(d, v.littleEndian);
            avro::decode(d, v.calibrationFunction);
            avro::decode(d, v.lengthFieldId);
            avro::decode(d, v.radix);
            avro::decode(d, v.listAlarms);
            avro::decode(d, v.subsystem);
        }
    }
};

template<> struct codec_traits<IW::ProcessedField> {
    static void encode(Encoder& e, const IW::ProcessedField& v) {
        avro::encode(e, v.index);
        avro::encode(e, v.fieldTypeId);
        avro::encode(e, v.fieldName);
        avro::encode(e, v.value);
    }
    static void decode(Decoder& d, IW::ProcessedField& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.index);
                    break;
                case 1:
                    avro::decode(d, v.fieldTypeId);
                    break;
                case 2:
                    avro::decode(d, v.fieldName);
                    break;
                case 3:
                    avro::decode(d, v.value);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.index);
            avro::decode(d, v.fieldTypeId);
            avro::decode(d, v.fieldName);
            avro::decode(d, v.value);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__4__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__4__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__4__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<int32_t > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::GroupProcessedField> {
    static void encode(Encoder& e, const IW::GroupProcessedField& v) {
        avro::encode(e, v.id);
        avro::encode(e, v.fields);
        avro::encode(e, v.oolFlag);
        avro::encode(e, v.oolFields);
    }
    static void decode(Decoder& d, IW::GroupProcessedField& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.id);
                    break;
                case 1:
                    avro::decode(d, v.fields);
                    break;
                case 2:
                    avro::decode(d, v.oolFlag);
                    break;
                case 3:
                    avro::decode(d, v.oolFields);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.id);
            avro::decode(d, v.fields);
            avro::decode(d, v.oolFlag);
            avro::decode(d, v.oolFields);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__5__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__5__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__5__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<IW::GroupProcessedField > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::TM_ProcessedFrame> {
    static void encode(Encoder& e, const IW::TM_ProcessedFrame& v) {
        avro::encode(e, v.id);
        avro::encode(e, v.frameTypeId);
        avro::encode(e, v.creationTime);
        avro::encode(e, v.groups);
    }
    static void decode(Decoder& d, IW::TM_ProcessedFrame& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.id);
                    break;
                case 1:
                    avro::decode(d, v.frameTypeId);
                    break;
                case 2:
                    avro::decode(d, v.creationTime);
                    break;
                case 3:
                    avro::decode(d, v.groups);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.id);
            avro::decode(d, v.frameTypeId);
            avro::decode(d, v.creationTime);
            avro::decode(d, v.groups);
        }
    }
};

template<> struct codec_traits<IW::User> {
    static void encode(Encoder& e, const IW::User& v) {
        avro::encode(e, v.userId);
        avro::encode(e, v.userName);
        avro::encode(e, v.password);
        avro::encode(e, v.firstName);
        avro::encode(e, v.lastName);
        avro::encode(e, v.emailAddress);
        avro::encode(e, v.missionName);
        avro::encode(e, v.roleId);
    }
    static void decode(Decoder& d, IW::User& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.userId);
                    break;
                case 1:
                    avro::decode(d, v.userName);
                    break;
                case 2:
                    avro::decode(d, v.password);
                    break;
                case 3:
                    avro::decode(d, v.firstName);
                    break;
                case 4:
                    avro::decode(d, v.lastName);
                    break;
                case 5:
                    avro::decode(d, v.emailAddress);
                    break;
                case 6:
                    avro::decode(d, v.missionName);
                    break;
                case 7:
                    avro::decode(d, v.roleId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.userId);
            avro::decode(d, v.userName);
            avro::decode(d, v.password);
            avro::decode(d, v.firstName);
            avro::decode(d, v.lastName);
            avro::decode(d, v.emailAddress);
            avro::decode(d, v.missionName);
            avro::decode(d, v.roleId);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__6__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__6__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__6__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<IW::GroupProcessedField > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::XTCE_ProcessedFrame> {
    static void encode(Encoder& e, const IW::XTCE_ProcessedFrame& v) {
        avro::encode(e, v.id);
        avro::encode(e, v.containerName);
        avro::encode(e, v.creationTime);
        avro::encode(e, v.groups);
    }
    static void decode(Decoder& d, IW::XTCE_ProcessedFrame& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.id);
                    break;
                case 1:
                    avro::decode(d, v.containerName);
                    break;
                case 2:
                    avro::decode(d, v.creationTime);
                    break;
                case 3:
                    avro::decode(d, v.groups);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.id);
            avro::decode(d, v.containerName);
            avro::decode(d, v.creationTime);
            avro::decode(d, v.groups);
        }
    }
};

template<> struct codec_traits<IW::TM_FrameField> {
    static void encode(Encoder& e, const IW::TM_FrameField& v) {
        avro::encode(e, v.frameName);
        avro::encode(e, v.parameterName);
        avro::encode(e, v.relativePosition);
        avro::encode(e, v.sequenceNumber);
    }
    static void decode(Decoder& d, IW::TM_FrameField& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.frameName);
                    break;
                case 1:
                    avro::decode(d, v.parameterName);
                    break;
                case 2:
                    avro::decode(d, v.relativePosition);
                    break;
                case 3:
                    avro::decode(d, v.sequenceNumber);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.frameName);
            avro::decode(d, v.parameterName);
            avro::decode(d, v.relativePosition);
            avro::decode(d, v.sequenceNumber);
        }
    }
};

template<> struct codec_traits<IW::TM_FrameCondition> {
    static void encode(Encoder& e, const IW::TM_FrameCondition& v) {
        avro::encode(e, v.frameName);
        avro::encode(e, v.parameterName);
        avro::encode(e, v.parameterValue);
    }
    static void decode(Decoder& d, IW::TM_FrameCondition& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.frameName);
                    break;
                case 1:
                    avro::decode(d, v.parameterName);
                    break;
                case 2:
                    avro::decode(d, v.parameterValue);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.frameName);
            avro::decode(d, v.parameterName);
            avro::decode(d, v.parameterValue);
        }
    }
};

template<> struct codec_traits<IW::TmFrameFlagEnum> {
    static void encode(Encoder& e, IW::TmFrameFlagEnum v) {
		if (v < IW::TM_FRAME_ARCHIVE || v > IW::TM_FRAME_LITTLE_ENDIAN)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::TmFrameFlagEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::TmFrameFlagEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::TM_FRAME_ARCHIVE || index > IW::TM_FRAME_LITTLE_ENDIAN)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::TmFrameFlagEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::TmFrameFlagEnum>(index);
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__7__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__7__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_array());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__7__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::vector<IW::TM_FrameCondition > vv;
                avro::decode(d, vv);
                v.set_array(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::TM_Frame> {
    static void encode(Encoder& e, const IW::TM_Frame& v) {
        avro::encode(e, v.name);
        avro::encode(e, v.description);
        avro::encode(e, v.expectedInterval);
        avro::encode(e, v.lengthBits);
        avro::encode(e, v.flag);
        avro::encode(e, v.frameConditions);
        avro::encode(e, v.tmFields);
        avro::encode(e, v.layerName);
    }
    static void decode(Decoder& d, IW::TM_Frame& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.name);
                    break;
                case 1:
                    avro::decode(d, v.description);
                    break;
                case 2:
                    avro::decode(d, v.expectedInterval);
                    break;
                case 3:
                    avro::decode(d, v.lengthBits);
                    break;
                case 4:
                    avro::decode(d, v.flag);
                    break;
                case 5:
                    avro::decode(d, v.frameConditions);
                    break;
                case 6:
                    avro::decode(d, v.tmFields);
                    break;
                case 7:
                    avro::decode(d, v.layerName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.name);
            avro::decode(d, v.description);
            avro::decode(d, v.expectedInterval);
            avro::decode(d, v.lengthBits);
            avro::decode(d, v.flag);
            avro::decode(d, v.frameConditions);
            avro::decode(d, v.tmFields);
            avro::decode(d, v.layerName);
        }
    }
};

template<> struct codec_traits<IW::ListFrameTypes> {
    static void encode(Encoder& e, const IW::ListFrameTypes& v) {
        avro::encode(e, v.listFrameTypes);
    }
    static void decode(Decoder& d, IW::ListFrameTypes& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.listFrameTypes);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.listFrameTypes);
        }
    }
};

template<> struct codec_traits<IW::ListGroundStations> {
    static void encode(Encoder& e, const IW::ListGroundStations& v) {
        avro::encode(e, v.numberGroundStations);
        avro::encode(e, v.listGroundStations);
    }
    static void decode(Decoder& d, IW::ListGroundStations& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.numberGroundStations);
                    break;
                case 1:
                    avro::decode(d, v.listGroundStations);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.numberGroundStations);
            avro::decode(d, v.listGroundStations);
        }
    }
};

template<> struct codec_traits<IW::ListKeyValues> {
    static void encode(Encoder& e, const IW::ListKeyValues& v) {
        avro::encode(e, v.listKeyValues);
    }
    static void decode(Decoder& d, IW::ListKeyValues& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.listKeyValues);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.listKeyValues);
        }
    }
};

template<> struct codec_traits<IW::ListParameters> {
    static void encode(Encoder& e, const IW::ListParameters& v) {
        avro::encode(e, v.listParameters);
    }
    static void decode(Decoder& d, IW::ListParameters& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.listParameters);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.listParameters);
        }
    }
};

template<> struct codec_traits<IW::ListLayers> {
    static void encode(Encoder& e, const IW::ListLayers& v) {
        avro::encode(e, v.listLayers);
    }
    static void decode(Decoder& d, IW::ListLayers& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.listLayers);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.listLayers);
        }
    }
};

template<> struct codec_traits<IW::ListPasses> {
    static void encode(Encoder& e, const IW::ListPasses& v) {
        avro::encode(e, v.spacecraftIdentifier);
        avro::encode(e, v.groundStationIdentifier);
        avro::encode(e, v.numberPasses);
        avro::encode(e, v.listPasses);
    }
    static void decode(Decoder& d, IW::ListPasses& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.spacecraftIdentifier);
                    break;
                case 1:
                    avro::decode(d, v.groundStationIdentifier);
                    break;
                case 2:
                    avro::decode(d, v.numberPasses);
                    break;
                case 3:
                    avro::decode(d, v.listPasses);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.spacecraftIdentifier);
            avro::decode(d, v.groundStationIdentifier);
            avro::decode(d, v.numberPasses);
            avro::decode(d, v.listPasses);
        }
    }
};

template<> struct codec_traits<IW::ListSatellites> {
    static void encode(Encoder& e, const IW::ListSatellites& v) {
        avro::encode(e, v.listSatellites);
    }
    static void decode(Decoder& d, IW::ListSatellites& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.listSatellites);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.listSatellites);
        }
    }
};

template<> struct codec_traits<IW::ListTC_Parameters> {
    static void encode(Encoder& e, const IW::ListTC_Parameters& v) {
        avro::encode(e, v.listTC_Parameters);
    }
    static void decode(Decoder& d, IW::ListTC_Parameters& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.listTC_Parameters);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.listTC_Parameters);
        }
    }
};

template<> struct codec_traits<IW::ListTM_Parameters> {
    static void encode(Encoder& e, const IW::ListTM_Parameters& v) {
        avro::encode(e, v.listTM_Parameters);
    }
    static void decode(Decoder& d, IW::ListTM_Parameters& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.listTM_Parameters);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.listTM_Parameters);
        }
    }
};

template<> struct codec_traits<IW::MsgAddGroundStation> {
    static void encode(Encoder& e, const IW::MsgAddGroundStation& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.groundStation);
    }
    static void decode(Decoder& d, IW::MsgAddGroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.groundStation);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.groundStation);
        }
    }
};

template<> struct codec_traits<IW::MsgAddMission> {
    static void encode(Encoder& e, const IW::MsgAddMission& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.mission);
    }
    static void decode(Decoder& d, IW::MsgAddMission& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.mission);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.mission);
        }
    }
};

template<> struct codec_traits<IW::MsgAddMissionLayer> {
    static void encode(Encoder& e, const IW::MsgAddMissionLayer& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
        avro::encode(e, v.layer);
    }
    static void decode(Decoder& d, IW::MsgAddMissionLayer& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.layer);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
            avro::decode(d, v.layer);
        }
    }
};

template<> struct codec_traits<IW::MsgAddNode> {
    static void encode(Encoder& e, const IW::MsgAddNode& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.subsystemId);
        avro::encode(e, v.node);
    }
    static void decode(Decoder& d, IW::MsgAddNode& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.subsystemId);
                    break;
                case 2:
                    avro::decode(d, v.node);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.subsystemId);
            avro::decode(d, v.node);
        }
    }
};

template<> struct codec_traits<IW::MsgAddRawFrame> {
    static void encode(Encoder& e, const IW::MsgAddRawFrame& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.timestamp);
        avro::encode(e, v.data);
        avro::encode(e, v.dataLength);
    }
    static void decode(Decoder& d, IW::MsgAddRawFrame& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.timestamp);
                    break;
                case 2:
                    avro::decode(d, v.data);
                    break;
                case 3:
                    avro::decode(d, v.dataLength);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.timestamp);
            avro::decode(d, v.data);
            avro::decode(d, v.dataLength);
        }
    }
};

template<> struct codec_traits<IW::MsgAddSatellite> {
    static void encode(Encoder& e, const IW::MsgAddSatellite& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
        avro::encode(e, v.satellite);
    }
    static void decode(Decoder& d, IW::MsgAddSatellite& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.satellite);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
            avro::decode(d, v.satellite);
        }
    }
};

template<> struct codec_traits<IW::MsgAddSubsystem> {
    static void encode(Encoder& e, const IW::MsgAddSubsystem& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.satelliteName);
        avro::encode(e, v.subsystem);
    }
    static void decode(Decoder& d, IW::MsgAddSubsystem& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.satelliteName);
                    break;
                case 2:
                    avro::decode(d, v.subsystem);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.satelliteName);
            avro::decode(d, v.subsystem);
        }
    }
};

template<> struct codec_traits<IW::MsgAddTcParameter> {
    static void encode(Encoder& e, const IW::MsgAddTcParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tcParameter);
    }
    static void decode(Decoder& d, IW::MsgAddTcParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tcParameter);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tcParameter);
        }
    }
};

template<> struct codec_traits<IW::MsgAddTmParameter> {
    static void encode(Encoder& e, const IW::MsgAddTmParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tmParameter);
    }
    static void decode(Decoder& d, IW::MsgAddTmParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tmParameter);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tmParameter);
        }
    }
};

template<> struct codec_traits<IW::MsgCheckLicence> {
    static void encode(Encoder& e, const IW::MsgCheckLicence& v) {
        avro::encode(e, v.componentId);
        avro::encode(e, v.componentSignature);
        avro::encode(e, v.componentFunction);
    }
    static void decode(Decoder& d, IW::MsgCheckLicence& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.componentId);
                    break;
                case 1:
                    avro::decode(d, v.componentSignature);
                    break;
                case 2:
                    avro::decode(d, v.componentFunction);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.componentId);
            avro::decode(d, v.componentSignature);
            avro::decode(d, v.componentFunction);
        }
    }
};

template<> struct codec_traits<IW::MsgCheckLicenceResponse> {
    static void encode(Encoder& e, const IW::MsgCheckLicenceResponse& v) {
        avro::encode(e, v.componentId);
        avro::encode(e, v.componentSignature);
        avro::encode(e, v.componentFunctions);
        avro::encode(e, v.licenceFunction);
    }
    static void decode(Decoder& d, IW::MsgCheckLicenceResponse& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.componentId);
                    break;
                case 1:
                    avro::decode(d, v.componentSignature);
                    break;
                case 2:
                    avro::decode(d, v.componentFunctions);
                    break;
                case 3:
                    avro::decode(d, v.licenceFunction);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.componentId);
            avro::decode(d, v.componentSignature);
            avro::decode(d, v.componentFunctions);
            avro::decode(d, v.licenceFunction);
        }
    }
};

template<> struct codec_traits<IW::MsgConnectGroundStation> {
    static void encode(Encoder& e, const IW::MsgConnectGroundStation& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.groundStationId);
    }
    static void decode(Decoder& d, IW::MsgConnectGroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.groundStationId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.groundStationId);
        }
    }
};

template<> struct codec_traits<IW::MsgDisconnectGroundStation> {
    static void encode(Encoder& e, const IW::MsgDisconnectGroundStation& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.connectionId);
    }
    static void decode(Decoder& d, IW::MsgDisconnectGroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.connectionId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.connectionId);
        }
    }
};

template<> struct codec_traits<IW::MsgEndModuleExecution> {
    static void encode(Encoder& e, const IW::MsgEndModuleExecution& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.module_name);
        avro::encode(e, v.execution_id);
        avro::encode(e, v.errorCode);
        avro::encode(e, v.errorMessage);
    }
    static void decode(Decoder& d, IW::MsgEndModuleExecution& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.module_name);
                    break;
                case 2:
                    avro::decode(d, v.execution_id);
                    break;
                case 3:
                    avro::decode(d, v.errorCode);
                    break;
                case 4:
                    avro::decode(d, v.errorMessage);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.module_name);
            avro::decode(d, v.execution_id);
            avro::decode(d, v.errorCode);
            avro::decode(d, v.errorMessage);
        }
    }
};

template<> struct codec_traits<IW::MsgFds> {
    static void encode(Encoder& e, const IW::MsgFds& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.module_name);
        avro::encode(e, v.execution_id);
        avro::encode(e, v.parameters);
    }
    static void decode(Decoder& d, IW::MsgFds& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.module_name);
                    break;
                case 2:
                    avro::decode(d, v.execution_id);
                    break;
                case 3:
                    avro::decode(d, v.parameters);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.module_name);
            avro::decode(d, v.execution_id);
            avro::decode(d, v.parameters);
        }
    }
};

template<> struct codec_traits<IW::MsgGetDefaultMissionLayers> {
    static void encode(Encoder& e, const IW::MsgGetDefaultMissionLayers& v) {
        avro::encode(e, v.authorizationToken);
    }
    static void decode(Decoder& d, IW::MsgGetDefaultMissionLayers& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
        }
    }
};

template<> struct codec_traits<IW::MsgGetFrameTypes> {
    static void encode(Encoder& e, const IW::MsgGetFrameTypes& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.layerName);
    }
    static void decode(Decoder& d, IW::MsgGetFrameTypes& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.layerName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.layerName);
        }
    }
};

template<> struct codec_traits<IW::MsgGetGroundStation> {
    static void encode(Encoder& e, const IW::MsgGetGroundStation& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.groundStationName);
        avro::encode(e, v.groundStationCode);
    }
    static void decode(Decoder& d, IW::MsgGetGroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.groundStationName);
                    break;
                case 2:
                    avro::decode(d, v.groundStationCode);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.groundStationName);
            avro::decode(d, v.groundStationCode);
        }
    }
};

template<> struct codec_traits<IW::MsgGetLayerParameters> {
    static void encode(Encoder& e, const IW::MsgGetLayerParameters& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
        avro::encode(e, v.layerName);
    }
    static void decode(Decoder& d, IW::MsgGetLayerParameters& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.layerName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
            avro::decode(d, v.layerName);
        }
    }
};

template<> struct codec_traits<IW::MsgGetMission> {
    static void encode(Encoder& e, const IW::MsgGetMission& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
    }
    static void decode(Decoder& d, IW::MsgGetMission& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
        }
    }
};

template<> struct codec_traits<IW::MsgGetMissionLayers> {
    static void encode(Encoder& e, const IW::MsgGetMissionLayers& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
    }
    static void decode(Decoder& d, IW::MsgGetMissionLayers& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
        }
    }
};

template<> struct codec_traits<IW::MsgGetNode> {
    static void encode(Encoder& e, const IW::MsgGetNode& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.subsystemId);
        avro::encode(e, v.nodeId);
    }
    static void decode(Decoder& d, IW::MsgGetNode& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.subsystemId);
                    break;
                case 2:
                    avro::decode(d, v.nodeId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.subsystemId);
            avro::decode(d, v.nodeId);
        }
    }
};

template<> struct codec_traits<IW::MsgGetPasses> {
    static void encode(Encoder& e, const IW::MsgGetPasses& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.userRole);
        avro::encode(e, v.missionId);
        avro::encode(e, v.satelliteId);
        avro::encode(e, v.groundStationId);
        avro::encode(e, v.startTime);
        avro::encode(e, v.stopTime);
    }
    static void decode(Decoder& d, IW::MsgGetPasses& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.userRole);
                    break;
                case 2:
                    avro::decode(d, v.missionId);
                    break;
                case 3:
                    avro::decode(d, v.satelliteId);
                    break;
                case 4:
                    avro::decode(d, v.groundStationId);
                    break;
                case 5:
                    avro::decode(d, v.startTime);
                    break;
                case 6:
                    avro::decode(d, v.stopTime);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.userRole);
            avro::decode(d, v.missionId);
            avro::decode(d, v.satelliteId);
            avro::decode(d, v.groundStationId);
            avro::decode(d, v.startTime);
            avro::decode(d, v.stopTime);
        }
    }
};

template<> struct codec_traits<IW::MsgGetSatellite> {
    static void encode(Encoder& e, const IW::MsgGetSatellite& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
        avro::encode(e, v.satelliteName);
        avro::encode(e, v.satelliteCode);
    }
    static void decode(Decoder& d, IW::MsgGetSatellite& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.satelliteName);
                    break;
                case 3:
                    avro::decode(d, v.satelliteCode);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
            avro::decode(d, v.satelliteName);
            avro::decode(d, v.satelliteCode);
        }
    }
};

template<> struct codec_traits<IW::MsgGetStatus> {
    static void encode(Encoder& e, const IW::MsgGetStatus& v) {
        avro::encode(e, v.componentId);
    }
    static void decode(Decoder& d, IW::MsgGetStatus& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.componentId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.componentId);
        }
    }
};

template<> struct codec_traits<IW::IntComponentStatusEnum> {
    static void encode(Encoder& e, IW::IntComponentStatusEnum v) {
		if (v < IW::MODE_NONE || v > IW::FAILED)
		{
			std::ostringstream error;
			error << "enum value " << v << " is out of bound for IW::IntComponentStatusEnum and cannot be encoded";
			throw avro::Exception(error.str());
		}
        e.encodeEnum(v);
    }
    static void decode(Decoder& d, IW::IntComponentStatusEnum& v) {
		size_t index = d.decodeEnum();
		if (index < IW::MODE_NONE || index > IW::FAILED)
		{
			std::ostringstream error;
			error << "enum value " << index << " is out of bound for IW::IntComponentStatusEnum and cannot be decoded";
			throw avro::Exception(error.str());
		}
        v = static_cast<IW::IntComponentStatusEnum>(index);
    }
};

template<> struct codec_traits<IW::MsgGetStatusResponse> {
    static void encode(Encoder& e, const IW::MsgGetStatusResponse& v) {
        avro::encode(e, v.componentId);
        avro::encode(e, v.ComponentStatusEnum);
    }
    static void decode(Decoder& d, IW::MsgGetStatusResponse& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.componentId);
                    break;
                case 1:
                    avro::decode(d, v.ComponentStatusEnum);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.componentId);
            avro::decode(d, v.ComponentStatusEnum);
        }
    }
};

template<> struct codec_traits<IW::MsgGetSubsystem> {
    static void encode(Encoder& e, const IW::MsgGetSubsystem& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.satelliteName);
        avro::encode(e, v.subsystemName);
    }
    static void decode(Decoder& d, IW::MsgGetSubsystem& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.satelliteName);
                    break;
                case 2:
                    avro::decode(d, v.subsystemName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.satelliteName);
            avro::decode(d, v.subsystemName);
        }
    }
};

template<> struct codec_traits<IW::MsgGetTcParameter> {
    static void encode(Encoder& e, const IW::MsgGetTcParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tcParameterId);
        avro::encode(e, v.nodeId);
        avro::encode(e, v.channelId);
    }
    static void decode(Decoder& d, IW::MsgGetTcParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tcParameterId);
                    break;
                case 2:
                    avro::decode(d, v.nodeId);
                    break;
                case 3:
                    avro::decode(d, v.channelId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tcParameterId);
            avro::decode(d, v.nodeId);
            avro::decode(d, v.channelId);
        }
    }
};

template<> struct codec_traits<IW::MsgGetTmParameter> {
    static void encode(Encoder& e, const IW::MsgGetTmParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tmParameterId);
        avro::encode(e, v.nodeId);
        avro::encode(e, v.channelId);
    }
    static void decode(Decoder& d, IW::MsgGetTmParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tmParameterId);
                    break;
                case 2:
                    avro::decode(d, v.nodeId);
                    break;
                case 3:
                    avro::decode(d, v.channelId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tmParameterId);
            avro::decode(d, v.nodeId);
            avro::decode(d, v.channelId);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__8__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__8__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_int());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__8__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                int32_t vv;
                avro::decode(d, vv);
                v.set_int(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__9__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__9__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_int());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__9__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                int32_t vv;
                avro::decode(d, vv);
                v.set_int(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::MsgHeader> {
    static void encode(Encoder& e, const IW::MsgHeader& v) {
        avro::encode(e, v.messageId);
        avro::encode(e, v.correlationId);
        avro::encode(e, v.service);
        avro::encode(e, v.URIfrom);
        avro::encode(e, v.URIto);
        avro::encode(e, v.generationTime);
        avro::encode(e, v.expirationTime);
        avro::encode(e, v.sequenceId);
        avro::encode(e, v.positionId);
        avro::encode(e, v.sequenceSize);
    }
    static void decode(Decoder& d, IW::MsgHeader& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.messageId);
                    break;
                case 1:
                    avro::decode(d, v.correlationId);
                    break;
                case 2:
                    avro::decode(d, v.service);
                    break;
                case 3:
                    avro::decode(d, v.URIfrom);
                    break;
                case 4:
                    avro::decode(d, v.URIto);
                    break;
                case 5:
                    avro::decode(d, v.generationTime);
                    break;
                case 6:
                    avro::decode(d, v.expirationTime);
                    break;
                case 7:
                    avro::decode(d, v.sequenceId);
                    break;
                case 8:
                    avro::decode(d, v.positionId);
                    break;
                case 9:
                    avro::decode(d, v.sequenceSize);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.messageId);
            avro::decode(d, v.correlationId);
            avro::decode(d, v.service);
            avro::decode(d, v.URIfrom);
            avro::decode(d, v.URIto);
            avro::decode(d, v.generationTime);
            avro::decode(d, v.expirationTime);
            avro::decode(d, v.sequenceId);
            avro::decode(d, v.positionId);
            avro::decode(d, v.sequenceSize);
        }
    }
};

template<> struct codec_traits<IW::MsgImportScDatabase> {
    static void encode(Encoder& e, const IW::MsgImportScDatabase& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.fileName);
        avro::encode(e, v.fileType);
        avro::encode(e, v.fileSize);
        avro::encode(e, v.numberOfChunks);
        avro::encode(e, v.chunkNumber);
        avro::encode(e, v.buffer);
    }
    static void decode(Decoder& d, IW::MsgImportScDatabase& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.fileName);
                    break;
                case 2:
                    avro::decode(d, v.fileType);
                    break;
                case 3:
                    avro::decode(d, v.fileSize);
                    break;
                case 4:
                    avro::decode(d, v.numberOfChunks);
                    break;
                case 5:
                    avro::decode(d, v.chunkNumber);
                    break;
                case 6:
                    avro::decode(d, v.buffer);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.fileName);
            avro::decode(d, v.fileType);
            avro::decode(d, v.fileSize);
            avro::decode(d, v.numberOfChunks);
            avro::decode(d, v.chunkNumber);
            avro::decode(d, v.buffer);
        }
    }
};

template<> struct codec_traits<IW::MsgLogin> {
    static void encode(Encoder& e, const IW::MsgLogin& v) {
        avro::encode(e, v.userName);
        avro::encode(e, v.hashPassword);
    }
    static void decode(Decoder& d, IW::MsgLogin& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.userName);
                    break;
                case 1:
                    avro::decode(d, v.hashPassword);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.userName);
            avro::decode(d, v.hashPassword);
        }
    }
};

template<> struct codec_traits<IW::MsgLoginResponse> {
    static void encode(Encoder& e, const IW::MsgLoginResponse& v) {
        avro::encode(e, v.userData);
        avro::encode(e, v.authorizationToken);
    }
    static void decode(Decoder& d, IW::MsgLoginResponse& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.userData);
                    break;
                case 1:
                    avro::decode(d, v.authorizationToken);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.userData);
            avro::decode(d, v.authorizationToken);
        }
    }
};

template<> struct codec_traits<IW::MsgLogout> {
    static void encode(Encoder& e, const IW::MsgLogout& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.userId);
        avro::encode(e, v.userName);
    }
    static void decode(Decoder& d, IW::MsgLogout& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.userId);
                    break;
                case 2:
                    avro::decode(d, v.userName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.userId);
            avro::decode(d, v.userName);
        }
    }
};

template<> struct codec_traits<IW::MsgProcessRawFrame> {
    static void encode(Encoder& e, const IW::MsgProcessRawFrame& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
        avro::encode(e, v.containerName);
        avro::encode(e, v.rawFrame);
    }
    static void decode(Decoder& d, IW::MsgProcessRawFrame& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.containerName);
                    break;
                case 3:
                    avro::decode(d, v.rawFrame);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
            avro::decode(d, v.containerName);
            avro::decode(d, v.rawFrame);
        }
    }
};

template<> struct codec_traits<IW::MsgPublishEvent> {
    static void encode(Encoder& e, const IW::MsgPublishEvent& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.event);
    }
    static void decode(Decoder& d, IW::MsgPublishEvent& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.event);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.event);
        }
    }
};

template<> struct codec_traits<IW::MsgRegisterUserOld> {
    static void encode(Encoder& e, const IW::MsgRegisterUserOld& v) {
        avro::encode(e, v.firstName);
        avro::encode(e, v.lastName);
        avro::encode(e, v.userName);
        avro::encode(e, v.hashPassword);
        avro::encode(e, v.emailAddress);
        avro::encode(e, v.missionName);
        avro::encode(e, v.missionDescription);
        avro::encode(e, v.missionCountry);
        avro::encode(e, v.missionOwner);
    }
    static void decode(Decoder& d, IW::MsgRegisterUserOld& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.firstName);
                    break;
                case 1:
                    avro::decode(d, v.lastName);
                    break;
                case 2:
                    avro::decode(d, v.userName);
                    break;
                case 3:
                    avro::decode(d, v.hashPassword);
                    break;
                case 4:
                    avro::decode(d, v.emailAddress);
                    break;
                case 5:
                    avro::decode(d, v.missionName);
                    break;
                case 6:
                    avro::decode(d, v.missionDescription);
                    break;
                case 7:
                    avro::decode(d, v.missionCountry);
                    break;
                case 8:
                    avro::decode(d, v.missionOwner);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.firstName);
            avro::decode(d, v.lastName);
            avro::decode(d, v.userName);
            avro::decode(d, v.hashPassword);
            avro::decode(d, v.emailAddress);
            avro::decode(d, v.missionName);
            avro::decode(d, v.missionDescription);
            avro::decode(d, v.missionCountry);
            avro::decode(d, v.missionOwner);
        }
    }
};

template<> struct codec_traits<IW::MsgRegisterUser> {
    static void encode(Encoder& e, const IW::MsgRegisterUser& v) {
        avro::encode(e, v.user);
        avro::encode(e, v.mission);
    }
    static void decode(Decoder& d, IW::MsgRegisterUser& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.user);
                    break;
                case 1:
                    avro::decode(d, v.mission);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.user);
            avro::decode(d, v.mission);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveGroundStation> {
    static void encode(Encoder& e, const IW::MsgRemoveGroundStation& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.groundStationName);
    }
    static void decode(Decoder& d, IW::MsgRemoveGroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.groundStationName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.groundStationName);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveMissionLayer> {
    static void encode(Encoder& e, const IW::MsgRemoveMissionLayer& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
        avro::encode(e, v.layerName);
    }
    static void decode(Decoder& d, IW::MsgRemoveMissionLayer& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.layerName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
            avro::decode(d, v.layerName);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveMission> {
    static void encode(Encoder& e, const IW::MsgRemoveMission& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
    }
    static void decode(Decoder& d, IW::MsgRemoveMission& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveNode> {
    static void encode(Encoder& e, const IW::MsgRemoveNode& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.subsystemId);
        avro::encode(e, v.nodeId);
    }
    static void decode(Decoder& d, IW::MsgRemoveNode& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.subsystemId);
                    break;
                case 2:
                    avro::decode(d, v.nodeId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.subsystemId);
            avro::decode(d, v.nodeId);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveSatellite> {
    static void encode(Encoder& e, const IW::MsgRemoveSatellite& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.missionName);
        avro::encode(e, v.satelliteName);
    }
    static void decode(Decoder& d, IW::MsgRemoveSatellite& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.missionName);
                    break;
                case 2:
                    avro::decode(d, v.satelliteName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.missionName);
            avro::decode(d, v.satelliteName);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveSubsystem> {
    static void encode(Encoder& e, const IW::MsgRemoveSubsystem& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.satelliteName);
        avro::encode(e, v.subsystemName);
    }
    static void decode(Decoder& d, IW::MsgRemoveSubsystem& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.satelliteName);
                    break;
                case 2:
                    avro::decode(d, v.subsystemName);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.satelliteName);
            avro::decode(d, v.subsystemName);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveTcParameter> {
    static void encode(Encoder& e, const IW::MsgRemoveTcParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tcParameterId);
        avro::encode(e, v.nodeId);
        avro::encode(e, v.channelId);
    }
    static void decode(Decoder& d, IW::MsgRemoveTcParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tcParameterId);
                    break;
                case 2:
                    avro::decode(d, v.nodeId);
                    break;
                case 3:
                    avro::decode(d, v.channelId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tcParameterId);
            avro::decode(d, v.nodeId);
            avro::decode(d, v.channelId);
        }
    }
};

template<> struct codec_traits<IW::MsgRemoveTmParameter> {
    static void encode(Encoder& e, const IW::MsgRemoveTmParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tmParameterId);
        avro::encode(e, v.nodeId);
        avro::encode(e, v.channelId);
    }
    static void decode(Decoder& d, IW::MsgRemoveTmParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tmParameterId);
                    break;
                case 2:
                    avro::decode(d, v.nodeId);
                    break;
                case 3:
                    avro::decode(d, v.channelId);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tmParameterId);
            avro::decode(d, v.nodeId);
            avro::decode(d, v.channelId);
        }
    }
};

template<> struct codec_traits<IW::MsgReturnData> {
    static void encode(Encoder& e, const IW::MsgReturnData& v) {
        avro::encode(e, v.errorCode);
        avro::encode(e, v.errorMessage);
    }
    static void decode(Decoder& d, IW::MsgReturnData& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.errorCode);
                    break;
                case 1:
                    avro::decode(d, v.errorMessage);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.errorCode);
            avro::decode(d, v.errorMessage);
        }
    }
};

template<> struct codec_traits<IW::MsgSendFrameGroundStation> {
    static void encode(Encoder& e, const IW::MsgSendFrameGroundStation& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.connectionId);
        avro::encode(e, v.data);
        avro::encode(e, v.dataLength);
    }
    static void decode(Decoder& d, IW::MsgSendFrameGroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.connectionId);
                    break;
                case 2:
                    avro::decode(d, v.data);
                    break;
                case 3:
                    avro::decode(d, v.dataLength);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.connectionId);
            avro::decode(d, v.data);
            avro::decode(d, v.dataLength);
        }
    }
};

template<> struct codec_traits<IW::MsgShutdown> {
    static void encode(Encoder& e, const IW::MsgShutdown& v) {
    }
    static void decode(Decoder& d, IW::MsgShutdown& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                default:
                    break;
                }
            }
        } else {
        }
    }
};

template<> struct codec_traits<IW::MsgStartModuleExecution> {
    static void encode(Encoder& e, const IW::MsgStartModuleExecution& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.module_name);
        avro::encode(e, v.execution_id);
        avro::encode(e, v.parameters);
    }
    static void decode(Decoder& d, IW::MsgStartModuleExecution& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.module_name);
                    break;
                case 2:
                    avro::decode(d, v.execution_id);
                    break;
                case 3:
                    avro::decode(d, v.parameters);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.module_name);
            avro::decode(d, v.execution_id);
            avro::decode(d, v.parameters);
        }
    }
};

template<> struct codec_traits<IW::MsgStartup> {
    static void encode(Encoder& e, const IW::MsgStartup& v) {
        avro::encode(e, v.message);
    }
    static void decode(Decoder& d, IW::MsgStartup& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.message);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.message);
        }
    }
};

template<> struct codec_traits<IW::MsgUpdateGroundStation> {
    static void encode(Encoder& e, const IW::MsgUpdateGroundStation& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.groundStation);
    }
    static void decode(Decoder& d, IW::MsgUpdateGroundStation& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.groundStation);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.groundStation);
        }
    }
};

template<> struct codec_traits<IW::MsgUpdateMission> {
    static void encode(Encoder& e, const IW::MsgUpdateMission& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.mission);
    }
    static void decode(Decoder& d, IW::MsgUpdateMission& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.mission);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.mission);
        }
    }
};

template<> struct codec_traits<IW::MsgUpdateNode> {
    static void encode(Encoder& e, const IW::MsgUpdateNode& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.subsystemId);
        avro::encode(e, v.node);
    }
    static void decode(Decoder& d, IW::MsgUpdateNode& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.subsystemId);
                    break;
                case 2:
                    avro::decode(d, v.node);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.subsystemId);
            avro::decode(d, v.node);
        }
    }
};

template<> struct codec_traits<IW::MsgUpdateSatellite> {
    static void encode(Encoder& e, const IW::MsgUpdateSatellite& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.satellite);
    }
    static void decode(Decoder& d, IW::MsgUpdateSatellite& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.satellite);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.satellite);
        }
    }
};

template<> struct codec_traits<IW::MsgUpdateSubsystem> {
    static void encode(Encoder& e, const IW::MsgUpdateSubsystem& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.subsystem);
    }
    static void decode(Decoder& d, IW::MsgUpdateSubsystem& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.subsystem);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.subsystem);
        }
    }
};

template<> struct codec_traits<IW::MsgUpdateTcParameter> {
    static void encode(Encoder& e, const IW::MsgUpdateTcParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tcParameter);
    }
    static void decode(Decoder& d, IW::MsgUpdateTcParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tcParameter);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tcParameter);
        }
    }
};

template<> struct codec_traits<IW::MsgUpdateTmParameter> {
    static void encode(Encoder& e, const IW::MsgUpdateTmParameter& v) {
        avro::encode(e, v.authorizationToken);
        avro::encode(e, v.tmParameter);
    }
    static void decode(Decoder& d, IW::MsgUpdateTmParameter& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.authorizationToken);
                    break;
                case 1:
                    avro::decode(d, v.tmParameter);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.authorizationToken);
            avro::decode(d, v.tmParameter);
        }
    }
};

template<> struct codec_traits<IW::AvroNone> {
    static void encode(Encoder& e, const IW::AvroNone& v) {
        avro::encode(e, v.none_field);
    }
    static void decode(Decoder& d, IW::AvroNone& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.none_field);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.none_field);
        }
    }
};

template<> struct codec_traits<IW::AvroTypes_proc_Union__10__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__10__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_TmTypeEnum());
            break;
        case 1:
            avro::encode(e, v.get_TmSubTypeEnum());
            break;
        case 2:
            avro::encode(e, v.get_TmEngTypeEnum());
            break;
        case 3:
            avro::encode(e, v.get_RadixEnum());
            break;
        case 4:
            avro::encode(e, v.get_ModuleTypeEnum());
            break;
        case 5:
            avro::encode(e, v.get_Subsystem());
            break;
        case 6:
            avro::encode(e, v.get_Satellite());
            break;
        case 7:
            avro::encode(e, v.get_Mission());
            break;
        case 8:
            avro::encode(e, v.get_WatchTriggerTypeEnum());
            break;
        case 9:
            avro::encode(e, v.get_AlarmContext());
            break;
        case 10:
            avro::encode(e, v.get_Alarm());
            break;
        case 11:
            avro::encode(e, v.get_AlgorithmParameter());
            break;
        case 12:
            avro::encode(e, v.get_Algorithm());
            break;
        case 13:
            avro::encode(e, v.get_CalibrationItem());
            break;
        case 14:
            avro::encode(e, v.get_Calibration());
            break;
        case 15:
            avro::encode(e, v.get_ConfigurationParameter());
            break;
        case 16:
            avro::encode(e, v.get_Derived_TM_Parameter());
            break;
        case 17:
            avro::encode(e, v.get_Event());
            break;
        case 18:
            avro::encode(e, v.get_FdsModule());
            break;
        case 19:
            avro::encode(e, v.get_GroundStation());
            break;
        case 20:
            avro::encode(e, v.get_KeyValue());
            break;
        case 21:
            avro::encode(e, v.get_Layer());
            break;
        case 22:
            avro::encode(e, v.get_Node());
            break;
        case 23:
            avro::encode(e, v.get_Pass());
            break;
        case 24:
            avro::encode(e, v.get_TC_Argument());
            break;
        case 25:
            avro::encode(e, v.get_TC_ArgumentAssignment());
            break;
        case 26:
            avro::encode(e, v.get_TC_ParameterOptions());
            break;
        case 27:
            avro::encode(e, v.get_TC_ParameterOptConstraints());
            break;
        case 28:
            avro::encode(e, v.get_TC_ParameterVerifier());
            break;
        case 29:
            avro::encode(e, v.get_TC_Parameter());
            break;
        case 30:
            avro::encode(e, v.get_Limit());
            break;
        case 31:
            avro::encode(e, v.get_TM_Parameter());
            break;
        case 32:
            avro::encode(e, v.get_ProcessedField());
            break;
        case 33:
            avro::encode(e, v.get_GroupProcessedField());
            break;
        case 34:
            avro::encode(e, v.get_TM_ProcessedFrame());
            break;
        case 35:
            avro::encode(e, v.get_User());
            break;
        case 36:
            avro::encode(e, v.get_XTCE_ProcessedFrame());
            break;
        case 37:
            avro::encode(e, v.get_TM_FrameField());
            break;
        case 38:
            avro::encode(e, v.get_TM_FrameCondition());
            break;
        case 39:
            avro::encode(e, v.get_TM_Frame());
            break;
        case 40:
            avro::encode(e, v.get_ListFrameTypes());
            break;
        case 41:
            avro::encode(e, v.get_ListGroundStations());
            break;
        case 42:
            avro::encode(e, v.get_ListKeyValues());
            break;
        case 43:
            avro::encode(e, v.get_ListParameters());
            break;
        case 44:
            avro::encode(e, v.get_ListLayers());
            break;
        case 45:
            avro::encode(e, v.get_ListPasses());
            break;
        case 46:
            avro::encode(e, v.get_ListSatellites());
            break;
        case 47:
            avro::encode(e, v.get_ListTC_Parameters());
            break;
        case 48:
            avro::encode(e, v.get_ListTM_Parameters());
            break;
        case 49:
            avro::encode(e, v.get_MsgAddGroundStation());
            break;
        case 50:
            avro::encode(e, v.get_MsgAddMission());
            break;
        case 51:
            avro::encode(e, v.get_MsgAddMissionLayer());
            break;
        case 52:
            avro::encode(e, v.get_MsgAddNode());
            break;
        case 53:
            avro::encode(e, v.get_MsgAddRawFrame());
            break;
        case 54:
            avro::encode(e, v.get_MsgAddSatellite());
            break;
        case 55:
            avro::encode(e, v.get_MsgAddSubsystem());
            break;
        case 56:
            avro::encode(e, v.get_MsgAddTcParameter());
            break;
        case 57:
            avro::encode(e, v.get_MsgAddTmParameter());
            break;
        case 58:
            avro::encode(e, v.get_MsgCheckLicence());
            break;
        case 59:
            avro::encode(e, v.get_MsgCheckLicenceResponse());
            break;
        case 60:
            avro::encode(e, v.get_MsgConnectGroundStation());
            break;
        case 61:
            avro::encode(e, v.get_MsgDisconnectGroundStation());
            break;
        case 62:
            avro::encode(e, v.get_MsgEndModuleExecution());
            break;
        case 63:
            avro::encode(e, v.get_MsgFds());
            break;
        case 64:
            avro::encode(e, v.get_MsgGetDefaultMissionLayers());
            break;
        case 65:
            avro::encode(e, v.get_MsgGetFrameTypes());
            break;
        case 66:
            avro::encode(e, v.get_MsgGetGroundStation());
            break;
        case 67:
            avro::encode(e, v.get_MsgGetLayerParameters());
            break;
        case 68:
            avro::encode(e, v.get_MsgGetMission());
            break;
        case 69:
            avro::encode(e, v.get_MsgGetMissionLayers());
            break;
        case 70:
            avro::encode(e, v.get_MsgGetNode());
            break;
        case 71:
            avro::encode(e, v.get_MsgGetPasses());
            break;
        case 72:
            avro::encode(e, v.get_MsgGetSatellite());
            break;
        case 73:
            avro::encode(e, v.get_MsgGetStatus());
            break;
        case 74:
            avro::encode(e, v.get_MsgGetStatusResponse());
            break;
        case 75:
            avro::encode(e, v.get_MsgGetSubsystem());
            break;
        case 76:
            avro::encode(e, v.get_MsgGetTcParameter());
            break;
        case 77:
            avro::encode(e, v.get_MsgGetTmParameter());
            break;
        case 78:
            avro::encode(e, v.get_MsgHeader());
            break;
        case 79:
            avro::encode(e, v.get_MsgImportScDatabase());
            break;
        case 80:
            avro::encode(e, v.get_MsgLogin());
            break;
        case 81:
            avro::encode(e, v.get_MsgLoginResponse());
            break;
        case 82:
            avro::encode(e, v.get_MsgLogout());
            break;
        case 83:
            avro::encode(e, v.get_MsgProcessRawFrame());
            break;
        case 84:
            avro::encode(e, v.get_MsgPublishEvent());
            break;
        case 85:
            avro::encode(e, v.get_MsgRegisterUserOld());
            break;
        case 86:
            avro::encode(e, v.get_MsgRegisterUser());
            break;
        case 87:
            avro::encode(e, v.get_MsgRemoveGroundStation());
            break;
        case 88:
            avro::encode(e, v.get_MsgRemoveMissionLayer());
            break;
        case 89:
            avro::encode(e, v.get_MsgRemoveMission());
            break;
        case 90:
            avro::encode(e, v.get_MsgRemoveNode());
            break;
        case 91:
            avro::encode(e, v.get_MsgRemoveSatellite());
            break;
        case 92:
            avro::encode(e, v.get_MsgRemoveSubsystem());
            break;
        case 93:
            avro::encode(e, v.get_MsgRemoveTcParameter());
            break;
        case 94:
            avro::encode(e, v.get_MsgRemoveTmParameter());
            break;
        case 95:
            avro::encode(e, v.get_MsgReturnData());
            break;
        case 96:
            avro::encode(e, v.get_MsgSendFrameGroundStation());
            break;
        case 97:
            avro::encode(e, v.get_MsgShutdown());
            break;
        case 98:
            avro::encode(e, v.get_MsgStartModuleExecution());
            break;
        case 99:
            avro::encode(e, v.get_MsgStartup());
            break;
        case 100:
            avro::encode(e, v.get_MsgUpdateGroundStation());
            break;
        case 101:
            avro::encode(e, v.get_MsgUpdateMission());
            break;
        case 102:
            avro::encode(e, v.get_MsgUpdateNode());
            break;
        case 103:
            avro::encode(e, v.get_MsgUpdateSatellite());
            break;
        case 104:
            avro::encode(e, v.get_MsgUpdateSubsystem());
            break;
        case 105:
            avro::encode(e, v.get_MsgUpdateTcParameter());
            break;
        case 106:
            avro::encode(e, v.get_MsgUpdateTmParameter());
            break;
        case 107:
            avro::encode(e, v.get_AvroNone());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__10__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 108) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                IW::TmTypeEnum vv;
                avro::decode(d, vv);
                v.set_TmTypeEnum(vv);
            }
            break;
        case 1:
            {
                IW::TmSubTypeEnum vv;
                avro::decode(d, vv);
                v.set_TmSubTypeEnum(vv);
            }
            break;
        case 2:
            {
                IW::TmEngTypeEnum vv;
                avro::decode(d, vv);
                v.set_TmEngTypeEnum(vv);
            }
            break;
        case 3:
            {
                IW::RadixEnum vv;
                avro::decode(d, vv);
                v.set_RadixEnum(vv);
            }
            break;
        case 4:
            {
                IW::ModuleTypeEnum vv;
                avro::decode(d, vv);
                v.set_ModuleTypeEnum(vv);
            }
            break;
        case 5:
            {
                IW::Subsystem vv;
                avro::decode(d, vv);
                v.set_Subsystem(vv);
            }
            break;
        case 6:
            {
                IW::Satellite vv;
                avro::decode(d, vv);
                v.set_Satellite(vv);
            }
            break;
        case 7:
            {
                IW::Mission vv;
                avro::decode(d, vv);
                v.set_Mission(vv);
            }
            break;
        case 8:
            {
                IW::WatchTriggerTypeEnum vv;
                avro::decode(d, vv);
                v.set_WatchTriggerTypeEnum(vv);
            }
            break;
        case 9:
            {
                IW::AlarmContext vv;
                avro::decode(d, vv);
                v.set_AlarmContext(vv);
            }
            break;
        case 10:
            {
                IW::Alarm vv;
                avro::decode(d, vv);
                v.set_Alarm(vv);
            }
            break;
        case 11:
            {
                IW::AlgorithmParameter vv;
                avro::decode(d, vv);
                v.set_AlgorithmParameter(vv);
            }
            break;
        case 12:
            {
                IW::Algorithm vv;
                avro::decode(d, vv);
                v.set_Algorithm(vv);
            }
            break;
        case 13:
            {
                IW::CalibrationItem vv;
                avro::decode(d, vv);
                v.set_CalibrationItem(vv);
            }
            break;
        case 14:
            {
                IW::Calibration vv;
                avro::decode(d, vv);
                v.set_Calibration(vv);
            }
            break;
        case 15:
            {
                IW::ConfigurationParameter vv;
                avro::decode(d, vv);
                v.set_ConfigurationParameter(vv);
            }
            break;
        case 16:
            {
                IW::Derived_TM_Parameter vv;
                avro::decode(d, vv);
                v.set_Derived_TM_Parameter(vv);
            }
            break;
        case 17:
            {
                IW::Event vv;
                avro::decode(d, vv);
                v.set_Event(vv);
            }
            break;
        case 18:
            {
                IW::FdsModule vv;
                avro::decode(d, vv);
                v.set_FdsModule(vv);
            }
            break;
        case 19:
            {
                IW::GroundStation vv;
                avro::decode(d, vv);
                v.set_GroundStation(vv);
            }
            break;
        case 20:
            {
                IW::KeyValue vv;
                avro::decode(d, vv);
                v.set_KeyValue(vv);
            }
            break;
        case 21:
            {
                IW::Layer vv;
                avro::decode(d, vv);
                v.set_Layer(vv);
            }
            break;
        case 22:
            {
                IW::Node vv;
                avro::decode(d, vv);
                v.set_Node(vv);
            }
            break;
        case 23:
            {
                IW::Pass vv;
                avro::decode(d, vv);
                v.set_Pass(vv);
            }
            break;
        case 24:
            {
                IW::TC_Argument vv;
                avro::decode(d, vv);
                v.set_TC_Argument(vv);
            }
            break;
        case 25:
            {
                IW::TC_ArgumentAssignment vv;
                avro::decode(d, vv);
                v.set_TC_ArgumentAssignment(vv);
            }
            break;
        case 26:
            {
                IW::TC_ParameterOptions vv;
                avro::decode(d, vv);
                v.set_TC_ParameterOptions(vv);
            }
            break;
        case 27:
            {
                IW::TC_ParameterOptConstraints vv;
                avro::decode(d, vv);
                v.set_TC_ParameterOptConstraints(vv);
            }
            break;
        case 28:
            {
                IW::TC_ParameterVerifier vv;
                avro::decode(d, vv);
                v.set_TC_ParameterVerifier(vv);
            }
            break;
        case 29:
            {
                IW::TC_Parameter vv;
                avro::decode(d, vv);
                v.set_TC_Parameter(vv);
            }
            break;
        case 30:
            {
                IW::Limit vv;
                avro::decode(d, vv);
                v.set_Limit(vv);
            }
            break;
        case 31:
            {
                IW::TM_Parameter vv;
                avro::decode(d, vv);
                v.set_TM_Parameter(vv);
            }
            break;
        case 32:
            {
                IW::ProcessedField vv;
                avro::decode(d, vv);
                v.set_ProcessedField(vv);
            }
            break;
        case 33:
            {
                IW::GroupProcessedField vv;
                avro::decode(d, vv);
                v.set_GroupProcessedField(vv);
            }
            break;
        case 34:
            {
                IW::TM_ProcessedFrame vv;
                avro::decode(d, vv);
                v.set_TM_ProcessedFrame(vv);
            }
            break;
        case 35:
            {
                IW::User vv;
                avro::decode(d, vv);
                v.set_User(vv);
            }
            break;
        case 36:
            {
                IW::XTCE_ProcessedFrame vv;
                avro::decode(d, vv);
                v.set_XTCE_ProcessedFrame(vv);
            }
            break;
        case 37:
            {
                IW::TM_FrameField vv;
                avro::decode(d, vv);
                v.set_TM_FrameField(vv);
            }
            break;
        case 38:
            {
                IW::TM_FrameCondition vv;
                avro::decode(d, vv);
                v.set_TM_FrameCondition(vv);
            }
            break;
        case 39:
            {
                IW::TM_Frame vv;
                avro::decode(d, vv);
                v.set_TM_Frame(vv);
            }
            break;
        case 40:
            {
                IW::ListFrameTypes vv;
                avro::decode(d, vv);
                v.set_ListFrameTypes(vv);
            }
            break;
        case 41:
            {
                IW::ListGroundStations vv;
                avro::decode(d, vv);
                v.set_ListGroundStations(vv);
            }
            break;
        case 42:
            {
                IW::ListKeyValues vv;
                avro::decode(d, vv);
                v.set_ListKeyValues(vv);
            }
            break;
        case 43:
            {
                IW::ListParameters vv;
                avro::decode(d, vv);
                v.set_ListParameters(vv);
            }
            break;
        case 44:
            {
                IW::ListLayers vv;
                avro::decode(d, vv);
                v.set_ListLayers(vv);
            }
            break;
        case 45:
            {
                IW::ListPasses vv;
                avro::decode(d, vv);
                v.set_ListPasses(vv);
            }
            break;
        case 46:
            {
                IW::ListSatellites vv;
                avro::decode(d, vv);
                v.set_ListSatellites(vv);
            }
            break;
        case 47:
            {
                IW::ListTC_Parameters vv;
                avro::decode(d, vv);
                v.set_ListTC_Parameters(vv);
            }
            break;
        case 48:
            {
                IW::ListTM_Parameters vv;
                avro::decode(d, vv);
                v.set_ListTM_Parameters(vv);
            }
            break;
        case 49:
            {
                IW::MsgAddGroundStation vv;
                avro::decode(d, vv);
                v.set_MsgAddGroundStation(vv);
            }
            break;
        case 50:
            {
                IW::MsgAddMission vv;
                avro::decode(d, vv);
                v.set_MsgAddMission(vv);
            }
            break;
        case 51:
            {
                IW::MsgAddMissionLayer vv;
                avro::decode(d, vv);
                v.set_MsgAddMissionLayer(vv);
            }
            break;
        case 52:
            {
                IW::MsgAddNode vv;
                avro::decode(d, vv);
                v.set_MsgAddNode(vv);
            }
            break;
        case 53:
            {
                IW::MsgAddRawFrame vv;
                avro::decode(d, vv);
                v.set_MsgAddRawFrame(vv);
            }
            break;
        case 54:
            {
                IW::MsgAddSatellite vv;
                avro::decode(d, vv);
                v.set_MsgAddSatellite(vv);
            }
            break;
        case 55:
            {
                IW::MsgAddSubsystem vv;
                avro::decode(d, vv);
                v.set_MsgAddSubsystem(vv);
            }
            break;
        case 56:
            {
                IW::MsgAddTcParameter vv;
                avro::decode(d, vv);
                v.set_MsgAddTcParameter(vv);
            }
            break;
        case 57:
            {
                IW::MsgAddTmParameter vv;
                avro::decode(d, vv);
                v.set_MsgAddTmParameter(vv);
            }
            break;
        case 58:
            {
                IW::MsgCheckLicence vv;
                avro::decode(d, vv);
                v.set_MsgCheckLicence(vv);
            }
            break;
        case 59:
            {
                IW::MsgCheckLicenceResponse vv;
                avro::decode(d, vv);
                v.set_MsgCheckLicenceResponse(vv);
            }
            break;
        case 60:
            {
                IW::MsgConnectGroundStation vv;
                avro::decode(d, vv);
                v.set_MsgConnectGroundStation(vv);
            }
            break;
        case 61:
            {
                IW::MsgDisconnectGroundStation vv;
                avro::decode(d, vv);
                v.set_MsgDisconnectGroundStation(vv);
            }
            break;
        case 62:
            {
                IW::MsgEndModuleExecution vv;
                avro::decode(d, vv);
                v.set_MsgEndModuleExecution(vv);
            }
            break;
        case 63:
            {
                IW::MsgFds vv;
                avro::decode(d, vv);
                v.set_MsgFds(vv);
            }
            break;
        case 64:
            {
                IW::MsgGetDefaultMissionLayers vv;
                avro::decode(d, vv);
                v.set_MsgGetDefaultMissionLayers(vv);
            }
            break;
        case 65:
            {
                IW::MsgGetFrameTypes vv;
                avro::decode(d, vv);
                v.set_MsgGetFrameTypes(vv);
            }
            break;
        case 66:
            {
                IW::MsgGetGroundStation vv;
                avro::decode(d, vv);
                v.set_MsgGetGroundStation(vv);
            }
            break;
        case 67:
            {
                IW::MsgGetLayerParameters vv;
                avro::decode(d, vv);
                v.set_MsgGetLayerParameters(vv);
            }
            break;
        case 68:
            {
                IW::MsgGetMission vv;
                avro::decode(d, vv);
                v.set_MsgGetMission(vv);
            }
            break;
        case 69:
            {
                IW::MsgGetMissionLayers vv;
                avro::decode(d, vv);
                v.set_MsgGetMissionLayers(vv);
            }
            break;
        case 70:
            {
                IW::MsgGetNode vv;
                avro::decode(d, vv);
                v.set_MsgGetNode(vv);
            }
            break;
        case 71:
            {
                IW::MsgGetPasses vv;
                avro::decode(d, vv);
                v.set_MsgGetPasses(vv);
            }
            break;
        case 72:
            {
                IW::MsgGetSatellite vv;
                avro::decode(d, vv);
                v.set_MsgGetSatellite(vv);
            }
            break;
        case 73:
            {
                IW::MsgGetStatus vv;
                avro::decode(d, vv);
                v.set_MsgGetStatus(vv);
            }
            break;
        case 74:
            {
                IW::MsgGetStatusResponse vv;
                avro::decode(d, vv);
                v.set_MsgGetStatusResponse(vv);
            }
            break;
        case 75:
            {
                IW::MsgGetSubsystem vv;
                avro::decode(d, vv);
                v.set_MsgGetSubsystem(vv);
            }
            break;
        case 76:
            {
                IW::MsgGetTcParameter vv;
                avro::decode(d, vv);
                v.set_MsgGetTcParameter(vv);
            }
            break;
        case 77:
            {
                IW::MsgGetTmParameter vv;
                avro::decode(d, vv);
                v.set_MsgGetTmParameter(vv);
            }
            break;
        case 78:
            {
                IW::MsgHeader vv;
                avro::decode(d, vv);
                v.set_MsgHeader(vv);
            }
            break;
        case 79:
            {
                IW::MsgImportScDatabase vv;
                avro::decode(d, vv);
                v.set_MsgImportScDatabase(vv);
            }
            break;
        case 80:
            {
                IW::MsgLogin vv;
                avro::decode(d, vv);
                v.set_MsgLogin(vv);
            }
            break;
        case 81:
            {
                IW::MsgLoginResponse vv;
                avro::decode(d, vv);
                v.set_MsgLoginResponse(vv);
            }
            break;
        case 82:
            {
                IW::MsgLogout vv;
                avro::decode(d, vv);
                v.set_MsgLogout(vv);
            }
            break;
        case 83:
            {
                IW::MsgProcessRawFrame vv;
                avro::decode(d, vv);
                v.set_MsgProcessRawFrame(vv);
            }
            break;
        case 84:
            {
                IW::MsgPublishEvent vv;
                avro::decode(d, vv);
                v.set_MsgPublishEvent(vv);
            }
            break;
        case 85:
            {
                IW::MsgRegisterUserOld vv;
                avro::decode(d, vv);
                v.set_MsgRegisterUserOld(vv);
            }
            break;
        case 86:
            {
                IW::MsgRegisterUser vv;
                avro::decode(d, vv);
                v.set_MsgRegisterUser(vv);
            }
            break;
        case 87:
            {
                IW::MsgRemoveGroundStation vv;
                avro::decode(d, vv);
                v.set_MsgRemoveGroundStation(vv);
            }
            break;
        case 88:
            {
                IW::MsgRemoveMissionLayer vv;
                avro::decode(d, vv);
                v.set_MsgRemoveMissionLayer(vv);
            }
            break;
        case 89:
            {
                IW::MsgRemoveMission vv;
                avro::decode(d, vv);
                v.set_MsgRemoveMission(vv);
            }
            break;
        case 90:
            {
                IW::MsgRemoveNode vv;
                avro::decode(d, vv);
                v.set_MsgRemoveNode(vv);
            }
            break;
        case 91:
            {
                IW::MsgRemoveSatellite vv;
                avro::decode(d, vv);
                v.set_MsgRemoveSatellite(vv);
            }
            break;
        case 92:
            {
                IW::MsgRemoveSubsystem vv;
                avro::decode(d, vv);
                v.set_MsgRemoveSubsystem(vv);
            }
            break;
        case 93:
            {
                IW::MsgRemoveTcParameter vv;
                avro::decode(d, vv);
                v.set_MsgRemoveTcParameter(vv);
            }
            break;
        case 94:
            {
                IW::MsgRemoveTmParameter vv;
                avro::decode(d, vv);
                v.set_MsgRemoveTmParameter(vv);
            }
            break;
        case 95:
            {
                IW::MsgReturnData vv;
                avro::decode(d, vv);
                v.set_MsgReturnData(vv);
            }
            break;
        case 96:
            {
                IW::MsgSendFrameGroundStation vv;
                avro::decode(d, vv);
                v.set_MsgSendFrameGroundStation(vv);
            }
            break;
        case 97:
            {
                IW::MsgShutdown vv;
                avro::decode(d, vv);
                v.set_MsgShutdown(vv);
            }
            break;
        case 98:
            {
                IW::MsgStartModuleExecution vv;
                avro::decode(d, vv);
                v.set_MsgStartModuleExecution(vv);
            }
            break;
        case 99:
            {
                IW::MsgStartup vv;
                avro::decode(d, vv);
                v.set_MsgStartup(vv);
            }
            break;
        case 100:
            {
                IW::MsgUpdateGroundStation vv;
                avro::decode(d, vv);
                v.set_MsgUpdateGroundStation(vv);
            }
            break;
        case 101:
            {
                IW::MsgUpdateMission vv;
                avro::decode(d, vv);
                v.set_MsgUpdateMission(vv);
            }
            break;
        case 102:
            {
                IW::MsgUpdateNode vv;
                avro::decode(d, vv);
                v.set_MsgUpdateNode(vv);
            }
            break;
        case 103:
            {
                IW::MsgUpdateSatellite vv;
                avro::decode(d, vv);
                v.set_MsgUpdateSatellite(vv);
            }
            break;
        case 104:
            {
                IW::MsgUpdateSubsystem vv;
                avro::decode(d, vv);
                v.set_MsgUpdateSubsystem(vv);
            }
            break;
        case 105:
            {
                IW::MsgUpdateTcParameter vv;
                avro::decode(d, vv);
                v.set_MsgUpdateTcParameter(vv);
            }
            break;
        case 106:
            {
                IW::MsgUpdateTmParameter vv;
                avro::decode(d, vv);
                v.set_MsgUpdateTmParameter(vv);
            }
            break;
        case 107:
            {
                IW::AvroNone vv;
                avro::decode(d, vv);
                v.set_AvroNone(vv);
            }
            break;
        }
    }
};

}
#endif
