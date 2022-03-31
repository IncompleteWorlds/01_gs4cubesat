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


#ifndef KK_H_227032657__H_
#define KK_H_227032657__H_


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
    std::string