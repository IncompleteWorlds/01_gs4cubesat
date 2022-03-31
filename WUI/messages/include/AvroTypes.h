/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef AVROTYPES_H_1644149178__H_
#define AVROTYPES_H_1644149178__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace IW {
enum class RadixEnum: unsigned {
    RADIX_NONE,
    RADIX_DECIMAL,
    RADIX_HEXADECIMAL,
};

enum class ModuleTypeEnum: unsigned {
    EXTERNAL_MODULE,
    INTERNAL_MODULE,
};

enum class FdsEventEnum: unsigned {
    ANX_EVENT_TYPE,
    DNX_EVENT_TYPE,
    UMBRA_EVENT_TYPE,
    PENUMBRA_EVENT_TYPE,
    ECLIPSE_EVENT_TYPE,
    SUNLIGHT_EVENT_TYPE,
    AOS_EVENT_TYPE,
    LOS_EVENT_TYPE,
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

struct ListSatellites {
    std::vector<Satellite > listSatellites;
    ListSatellites() :
        listSatellites(std::vector<Satellite >())
        { }
};

struct StateVector {
    std::string time;
    std::vector<double > position;
    std::vector<double > velocity;
    StateVector() :
        time(std::string()),
        position(std::vector<double >()),
        velocity(std::vector<double >())
        { }
};

struct FdsEvent {
    std::string time;
    int32_t event_type;
    int32_t counter;
    FdsEvent() :
        time(std::string()),
        event_type(int32_t()),
        counter(int32_t())
        { }
};

struct MsgHeader {
    std::string version;
    std::string msg_id;
    std::string msg_code;
    std::string authentication_key;
    std::string execution_id;
    std::string user_id;
    MsgHeader() :
        version(std::string()),
        msg_id(std::string()),
        msg_code(std::string()),
        authentication_key(std::string()),
        execution_id(std::string()),
        user_id(std::string())
        { }
};

struct MsgReceivedHeader {
    MsgHeader header;
    MsgReceivedHeader() :
        header(MsgHeader())
        { }
};

struct MsgErrorData {
    int32_t error_code;
    std::string error_message;
    MsgErrorData() :
        error_code(int32_t()),
        error_message(std::string())
        { }
};

struct Tle {
    std::string line1;
    std::string line2;
    Tle() :
        line1(std::string()),
        line2(std::string())
        { }
};

struct Sgp4Output {
    std::string reference_frame;
    std::string epoch_format;
    std::string output_format;
    Sgp4Output() :
        reference_frame(std::string()),
        epoch_format(std::string()),
        output_format(std::string())
        { }
};

struct MsgPropagateSGP4 {
    MsgHeader header;
    std::string mission_id;
    std::string satellite_id;
    bool add_to_database;
    std::string epoch_format;
    std::string start_time;
    std::string stop_time;
    int32_t step_size;
    std::vector<double > initial_position;
    std::vector<double > initial_velocity;
    Tle Sgp4Input;
    Sgp4Output output;
    MsgPropagateSGP4() :
        header(MsgHeader()),
        mission_id(std::string()),
        satellite_id(std::string()),
        add_to_database(bool()),
        epoch_format(std::string()),
        start_time(std::string()),
        stop_time(std::string()),
        step_size(int32_t()),
        initial_position(std::vector<double >()),
        initial_velocity(std::vector<double >()),
        Sgp4Input(Tle()),
        output(Sgp4Output())
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
    MsgErrorData get_MsgErrorData() const;
    void set_MsgErrorData(const MsgErrorData& v);
    AvroTypes_proc_Union__2__();
};

struct MsgPropagateSGP4Response {
    typedef AvroTypes_proc_Union__2__ error_data_t;
    MsgHeader header;
    error_data_t error_data;
    std::string mission_id;
    std::string satellite_id;
    std::string reference_frame;
    std::string epoch_format;
    std::string output_format;
    std::vector<StateVector > ephemeris;
    std::string ephemeris_text;
    MsgPropagateSGP4Response() :
        header(MsgHeader()),
        error_data(error_data_t()),
        mission_id(std::string()),
        satellite_id(std::string()),
        reference_frame(std::string()),
        epoch_format(std::string()),
        output_format(std::string()),
        ephemeris(std::vector<StateVector >()),
        ephemeris_text(std::string())
        { }
};

struct MsgRunScript {
    MsgHeader header;
    std::string output_file_name;
    std::string script_text;
    MsgRunScript() :
        header(MsgHeader()),
        output_file_name(std::string()),
        script_text(std::string())
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
    MsgErrorData get_MsgErrorData() const;
    void set_MsgErrorData(const MsgErrorData& v);
    AvroTypes_proc_Union__3__();
};

struct MsgRunScriptResponse {
    typedef AvroTypes_proc_Union__3__ error_data_t;
    MsgHeader header;
    error_data_t error_data;
    std::string output;
    MsgRunScriptResponse() :
        header(MsgHeader()),
        error_data(error_data_t()),
        output(std::string())
        { }
};

struct MsgGetStatus {
    MsgHeader header;
    std::string component_id;
    MsgGetStatus() :
        header(MsgHeader()),
        component_id(std::string())
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
    MsgErrorData get_MsgErrorData() const;
    void set_MsgErrorData(const MsgErrorData& v);
    AvroTypes_proc_Union__4__();
};

enum class IntComponentStatusEnum: unsigned {
    MODE_NONE,
    STARTED,
    NOT_RUNNING,
    RUNNING,
    COMPLETE,
    FAILED,
};

struct MsgGetStatusResponse {
    typedef AvroTypes_proc_Union__4__ error_data_t;
    MsgHeader header;
    error_data_t error_data;
    std::string component_id;
    IntComponentStatusEnum component_status;
    MsgGetStatusResponse() :
        header(MsgHeader()),
        error_data(error_data_t()),
        component_id(std::string()),
        component_status(IntComponentStatusEnum())
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
    MsgErrorData get_MsgErrorData() const;
    void set_MsgErrorData(const MsgErrorData& v);
    AvroTypes_proc_Union__5__();
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
    std::string get_string() const;
    void set_string(const std::string& v);
    AvroTypes_proc_Union__6__();
};

struct MsgErrorResponse {
    typedef AvroTypes_proc_Union__5__ error_data_t;
    typedef AvroTypes_proc_Union__6__ other_info_t;
    MsgHeader header;
    error_data_t error_data;
    other_info_t other_info;
    MsgErrorResponse() :
        header(MsgHeader()),
        error_data(error_data_t()),
        other_info(other_info_t())
        { }
};

struct MsgGetEvents {
    MsgHeader header;
    std::string mission_id;
    std::string satellite_id;
    std::string epoch_format;
    std::string start_time;
    std::string stop_time;
    int32_t ground_station_id;
    int32_t antenna_id;
    double lattitude;
    double longitude;
    double altitude;
    std::vector<FdsEventEnum > event_types;
    MsgGetEvents() :
        header(MsgHeader()),
        mission_id(std::string()),
        satellite_id(std::string()),
        epoch_format(std::string()),
        start_time(std::string()),
        stop_time(std::string()),
        ground_station_id(int32_t()),
        antenna_id(int32_t()),
        lattitude(double()),
        longitude(double()),
        altitude(double()),
        event_types(std::vector<FdsEventEnum >())
        { }
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
    MsgErrorData get_MsgErrorData() const;
    void set_MsgErrorData(const MsgErrorData& v);
    AvroTypes_proc_Union__7__();
};

struct MsgGetEventsResponse {
    typedef AvroTypes_proc_Union__7__ error_data_t;
    MsgHeader header;
    error_data_t error_data;
    std::string mission_id;
    std::string satellite_id;
    int32_t ground_station_id;
    int32_t antenna_id;
    std::vector<FdsEvent > event_types;
    MsgGetEventsResponse() :
        header(MsgHeader()),
        error_data(error_data_t()),
        mission_id(std::string()),
        satellite_id(std::string()),
        ground_station_id(int32_t()),
        antenna_id(int32_t()),
        event_types(std::vector<FdsEvent >())
        { }
};

struct AvroNone {
    int32_t none_field;
    AvroNone() :
        none_field(int32_t())
        { }
};

struct AvroTypes_proc_Union__8__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    RadixEnum get_RadixEnum() const;
    void set_RadixEnum(const RadixEnum& v);
    ModuleTypeEnum get_ModuleTypeEnum() const;
    void set_ModuleTypeEnum(const ModuleTypeEnum& v);
    FdsEventEnum get_FdsEventEnum() const;
    void set_FdsEventEnum(const FdsEventEnum& v);
    Subsystem get_Subsystem() const;
    void set_Subsystem(const Subsystem& v);
    Satellite get_Satellite() const;
    void set_Satellite(const Satellite& v);
    Mission get_Mission() const;
    void set_Mission(const Mission& v);
    User get_User() const;
    void set_User(const User& v);
    ListSatellites get_ListSatellites() const;
    void set_ListSatellites(const ListSatellites& v);
    StateVector get_StateVector() const;
    void set_StateVector(const StateVector& v);
    FdsEvent get_FdsEvent() const;
    void set_FdsEvent(const FdsEvent& v);
    MsgHeader get_MsgHeader() const;
    void set_MsgHeader(const MsgHeader& v);
    MsgReceivedHeader get_MsgReceivedHeader() const;
    void set_MsgReceivedHeader(const MsgReceivedHeader& v);
    MsgErrorData get_MsgErrorData() const;
    void set_MsgErrorData(const MsgErrorData& v);
    MsgPropagateSGP4 get_MsgPropagateSGP4() const;
    void set_MsgPropagateSGP4(const MsgPropagateSGP4& v);
    MsgPropagateSGP4Response get_MsgPropagateSGP4Response() const;
    void set_MsgPropagateSGP4Response(const MsgPropagateSGP4Response& v);
    MsgRunScript get_MsgRunScript() const;
    void set_MsgRunScript(const MsgRunScript& v);
    MsgRunScriptResponse get_MsgRunScriptResponse() const;
    void set_MsgRunScriptResponse(const MsgRunScriptResponse& v);
    MsgGetStatus get_MsgGetStatus() const;
    void set_MsgGetStatus(const MsgGetStatus& v);
    MsgGetStatusResponse get_MsgGetStatusResponse() const;
    void set_MsgGetStatusResponse(const MsgGetStatusResponse& v);
    MsgErrorResponse get_MsgErrorResponse() const;
    void set_MsgErrorResponse(const MsgErrorResponse& v);
    MsgGetEvents get_MsgGetEvents() const;
    void set_MsgGetEvents(const MsgGetEvents& v);
    MsgGetEventsResponse get_MsgGetEventsResponse() const;
    void set_MsgGetEventsResponse(const MsgGetEventsResponse& v);
    AvroNone get_AvroNone() const;
    void set_AvroNone(const AvroNone& v);
    AvroTypes_proc_Union__8__();
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
MsgErrorData AvroTypes_proc_Union__2__::get_MsgErrorData() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgErrorData >(value_);
}

inline
void AvroTypes_proc_Union__2__::set_MsgErrorData(const MsgErrorData& v) {
    idx_ = 1;
    value_ = v;
}

inline
MsgErrorData AvroTypes_proc_Union__3__::get_MsgErrorData() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgErrorData >(value_);
}

inline
void AvroTypes_proc_Union__3__::set_MsgErrorData(const MsgErrorData& v) {
    idx_ = 1;
    value_ = v;
}

inline
MsgErrorData AvroTypes_proc_Union__4__::get_MsgErrorData() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgErrorData >(value_);
}

inline
void AvroTypes_proc_Union__4__::set_MsgErrorData(const MsgErrorData& v) {
    idx_ = 1;
    value_ = v;
}

inline
MsgErrorData AvroTypes_proc_Union__5__::get_MsgErrorData() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgErrorData >(value_);
}

inline
void AvroTypes_proc_Union__5__::set_MsgErrorData(const MsgErrorData& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::string AvroTypes_proc_Union__6__::get_string() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::string >(value_);
}

inline
void AvroTypes_proc_Union__6__::set_string(const std::string& v) {
    idx_ = 1;
    value_ = v;
}

inline
MsgErrorData AvroTypes_proc_Union__7__::get_MsgErrorData() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgErrorData >(value_);
}

inline
void AvroTypes_proc_Union__7__::set_MsgErrorData(const MsgErrorData& v) {
    idx_ = 1;
    value_ = v;
}

inline
RadixEnum AvroTypes_proc_Union__8__::get_RadixEnum() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<RadixEnum >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_RadixEnum(const RadixEnum& v) {
    idx_ = 0;
    value_ = v;
}

inline
ModuleTypeEnum AvroTypes_proc_Union__8__::get_ModuleTypeEnum() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ModuleTypeEnum >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_ModuleTypeEnum(const ModuleTypeEnum& v) {
    idx_ = 1;
    value_ = v;
}

inline
FdsEventEnum AvroTypes_proc_Union__8__::get_FdsEventEnum() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<FdsEventEnum >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_FdsEventEnum(const FdsEventEnum& v) {
    idx_ = 2;
    value_ = v;
}

inline
Subsystem AvroTypes_proc_Union__8__::get_Subsystem() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Subsystem >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_Subsystem(const Subsystem& v) {
    idx_ = 3;
    value_ = v;
}

inline
Satellite AvroTypes_proc_Union__8__::get_Satellite() const {
    if (idx_ != 4) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Satellite >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_Satellite(const Satellite& v) {
    idx_ = 4;
    value_ = v;
}

inline
Mission AvroTypes_proc_Union__8__::get_Mission() const {
    if (idx_ != 5) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<Mission >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_Mission(const Mission& v) {
    idx_ = 5;
    value_ = v;
}

inline
User AvroTypes_proc_Union__8__::get_User() const {
    if (idx_ != 6) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<User >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_User(const User& v) {
    idx_ = 6;
    value_ = v;
}

inline
ListSatellites AvroTypes_proc_Union__8__::get_ListSatellites() const {
    if (idx_ != 7) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<ListSatellites >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_ListSatellites(const ListSatellites& v) {
    idx_ = 7;
    value_ = v;
}

inline
StateVector AvroTypes_proc_Union__8__::get_StateVector() const {
    if (idx_ != 8) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<StateVector >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_StateVector(const StateVector& v) {
    idx_ = 8;
    value_ = v;
}

inline
FdsEvent AvroTypes_proc_Union__8__::get_FdsEvent() const {
    if (idx_ != 9) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<FdsEvent >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_FdsEvent(const FdsEvent& v) {
    idx_ = 9;
    value_ = v;
}

inline
MsgHeader AvroTypes_proc_Union__8__::get_MsgHeader() const {
    if (idx_ != 10) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgHeader >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgHeader(const MsgHeader& v) {
    idx_ = 10;
    value_ = v;
}

inline
MsgReceivedHeader AvroTypes_proc_Union__8__::get_MsgReceivedHeader() const {
    if (idx_ != 11) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgReceivedHeader >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgReceivedHeader(const MsgReceivedHeader& v) {
    idx_ = 11;
    value_ = v;
}

inline
MsgErrorData AvroTypes_proc_Union__8__::get_MsgErrorData() const {
    if (idx_ != 12) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgErrorData >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgErrorData(const MsgErrorData& v) {
    idx_ = 12;
    value_ = v;
}

inline
MsgPropagateSGP4 AvroTypes_proc_Union__8__::get_MsgPropagateSGP4() const {
    if (idx_ != 13) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgPropagateSGP4 >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgPropagateSGP4(const MsgPropagateSGP4& v) {
    idx_ = 13;
    value_ = v;
}

inline
MsgPropagateSGP4Response AvroTypes_proc_Union__8__::get_MsgPropagateSGP4Response() const {
    if (idx_ != 14) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgPropagateSGP4Response >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgPropagateSGP4Response(const MsgPropagateSGP4Response& v) {
    idx_ = 14;
    value_ = v;
}

inline
MsgRunScript AvroTypes_proc_Union__8__::get_MsgRunScript() const {
    if (idx_ != 15) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRunScript >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgRunScript(const MsgRunScript& v) {
    idx_ = 15;
    value_ = v;
}

inline
MsgRunScriptResponse AvroTypes_proc_Union__8__::get_MsgRunScriptResponse() const {
    if (idx_ != 16) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgRunScriptResponse >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgRunScriptResponse(const MsgRunScriptResponse& v) {
    idx_ = 16;
    value_ = v;
}

inline
MsgGetStatus AvroTypes_proc_Union__8__::get_MsgGetStatus() const {
    if (idx_ != 17) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetStatus >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgGetStatus(const MsgGetStatus& v) {
    idx_ = 17;
    value_ = v;
}

inline
MsgGetStatusResponse AvroTypes_proc_Union__8__::get_MsgGetStatusResponse() const {
    if (idx_ != 18) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetStatusResponse >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgGetStatusResponse(const MsgGetStatusResponse& v) {
    idx_ = 18;
    value_ = v;
}

inline
MsgErrorResponse AvroTypes_proc_Union__8__::get_MsgErrorResponse() const {
    if (idx_ != 19) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgErrorResponse >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgErrorResponse(const MsgErrorResponse& v) {
    idx_ = 19;
    value_ = v;
}

inline
MsgGetEvents AvroTypes_proc_Union__8__::get_MsgGetEvents() const {
    if (idx_ != 20) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetEvents >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgGetEvents(const MsgGetEvents& v) {
    idx_ = 20;
    value_ = v;
}

inline
MsgGetEventsResponse AvroTypes_proc_Union__8__::get_MsgGetEventsResponse() const {
    if (idx_ != 21) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<MsgGetEventsResponse >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_MsgGetEventsResponse(const MsgGetEventsResponse& v) {
    idx_ = 21;
    value_ = v;
}

inline
AvroNone AvroTypes_proc_Union__8__::get_AvroNone() const {
    if (idx_ != 22) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroNone >(value_);
}

inline
void AvroTypes_proc_Union__8__::set_AvroNone(const AvroNone& v) {
    idx_ = 22;
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
inline AvroTypes_proc_Union__8__::AvroTypes_proc_Union__8__() : idx_(0), value_(RadixEnum()) { }
}
namespace avro {
template<> struct codec_traits<IW::RadixEnum> {
    static void encode(Encoder& e, IW::RadixEnum v) {
        if (v > IW::RadixEnum::RADIX_HEXADECIMAL)
        {
            std::ostringstream error;
            error << "enum value " << static_cast<unsigned>(v) << " is out of bound for IW::RadixEnum and cannot be encoded";
            throw avro::Exception(error.str());
        }
        e.encodeEnum(static_cast<size_t>(v));
    }
    static void decode(Decoder& d, IW::RadixEnum& v) {
        size_t index = d.decodeEnum();
        if (index > static_cast<size_t>(IW::RadixEnum::RADIX_HEXADECIMAL))
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
        if (v > IW::ModuleTypeEnum::INTERNAL_MODULE)
        {
            std::ostringstream error;
            error << "enum value " << static_cast<unsigned>(v) << " is out of bound for IW::ModuleTypeEnum and cannot be encoded";
            throw avro::Exception(error.str());
        }
        e.encodeEnum(static_cast<size_t>(v));
    }
    static void decode(Decoder& d, IW::ModuleTypeEnum& v) {
        size_t index = d.decodeEnum();
        if (index > static_cast<size_t>(IW::ModuleTypeEnum::INTERNAL_MODULE))
        {
            std::ostringstream error;
            error << "enum value " << index << " is out of bound for IW::ModuleTypeEnum and cannot be decoded";
            throw avro::Exception(error.str());
        }
        v = static_cast<IW::ModuleTypeEnum>(index);
    }
};

template<> struct codec_traits<IW::FdsEventEnum> {
    static void encode(Encoder& e, IW::FdsEventEnum v) {
        if (v > IW::FdsEventEnum::LOS_EVENT_TYPE)
        {
            std::ostringstream error;
            error << "enum value " << static_cast<unsigned>(v) << " is out of bound for IW::FdsEventEnum and cannot be encoded";
            throw avro::Exception(error.str());
        }
        e.encodeEnum(static_cast<size_t>(v));
    }
    static void decode(Decoder& d, IW::FdsEventEnum& v) {
        size_t index = d.decodeEnum();
        if (index > static_cast<size_t>(IW::FdsEventEnum::LOS_EVENT_TYPE))
        {
            std::ostringstream error;
            error << "enum value " << index << " is out of bound for IW::FdsEventEnum and cannot be decoded";
            throw avro::Exception(error.str());
        }
        v = static_cast<IW::FdsEventEnum>(index);
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

template<> struct codec_traits<IW::StateVector> {
    static void encode(Encoder& e, const IW::StateVector& v) {
        avro::encode(e, v.time);
        avro::encode(e, v.position);
        avro::encode(e, v.velocity);
    }
    static void decode(Decoder& d, IW::StateVector& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.time);
                    break;
                case 1:
                    avro::decode(d, v.position);
                    break;
                case 2:
                    avro::decode(d, v.velocity);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.time);
            avro::decode(d, v.position);
            avro::decode(d, v.velocity);
        }
    }
};

template<> struct codec_traits<IW::FdsEvent> {
    static void encode(Encoder& e, const IW::FdsEvent& v) {
        avro::encode(e, v.time);
        avro::encode(e, v.event_type);
        avro::encode(e, v.counter);
    }
    static void decode(Decoder& d, IW::FdsEvent& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.time);
                    break;
                case 1:
                    avro::decode(d, v.event_type);
                    break;
                case 2:
                    avro::decode(d, v.counter);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.time);
            avro::decode(d, v.event_type);
            avro::decode(d, v.counter);
        }
    }
};

template<> struct codec_traits<IW::MsgHeader> {
    static void encode(Encoder& e, const IW::MsgHeader& v) {
        avro::encode(e, v.version);
        avro::encode(e, v.msg_id);
        avro::encode(e, v.msg_code);
        avro::encode(e, v.authentication_key);
        avro::encode(e, v.execution_id);
        avro::encode(e, v.user_id);
    }
    static void decode(Decoder& d, IW::MsgHeader& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.version);
                    break;
                case 1:
                    avro::decode(d, v.msg_id);
                    break;
                case 2:
                    avro::decode(d, v.msg_code);
                    break;
                case 3:
                    avro::decode(d, v.authentication_key);
                    break;
                case 4:
                    avro::decode(d, v.execution_id);
                    break;
                case 5:
                    avro::decode(d, v.user_id);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.version);
            avro::decode(d, v.msg_id);
            avro::decode(d, v.msg_code);
            avro::decode(d, v.authentication_key);
            avro::decode(d, v.execution_id);
            avro::decode(d, v.user_id);
        }
    }
};

template<> struct codec_traits<IW::MsgReceivedHeader> {
    static void encode(Encoder& e, const IW::MsgReceivedHeader& v) {
        avro::encode(e, v.header);
    }
    static void decode(Decoder& d, IW::MsgReceivedHeader& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
        }
    }
};

template<> struct codec_traits<IW::MsgErrorData> {
    static void encode(Encoder& e, const IW::MsgErrorData& v) {
        avro::encode(e, v.error_code);
        avro::encode(e, v.error_message);
    }
    static void decode(Decoder& d, IW::MsgErrorData& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.error_code);
                    break;
                case 1:
                    avro::decode(d, v.error_message);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.error_code);
            avro::decode(d, v.error_message);
        }
    }
};

template<> struct codec_traits<IW::Tle> {
    static void encode(Encoder& e, const IW::Tle& v) {
        avro::encode(e, v.line1);
        avro::encode(e, v.line2);
    }
    static void decode(Decoder& d, IW::Tle& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.line1);
                    break;
                case 1:
                    avro::decode(d, v.line2);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.line1);
            avro::decode(d, v.line2);
        }
    }
};

template<> struct codec_traits<IW::Sgp4Output> {
    static void encode(Encoder& e, const IW::Sgp4Output& v) {
        avro::encode(e, v.reference_frame);
        avro::encode(e, v.epoch_format);
        avro::encode(e, v.output_format);
    }
    static void decode(Decoder& d, IW::Sgp4Output& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.reference_frame);
                    break;
                case 1:
                    avro::decode(d, v.epoch_format);
                    break;
                case 2:
                    avro::decode(d, v.output_format);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.reference_frame);
            avro::decode(d, v.epoch_format);
            avro::decode(d, v.output_format);
        }
    }
};

template<> struct codec_traits<IW::MsgPropagateSGP4> {
    static void encode(Encoder& e, const IW::MsgPropagateSGP4& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.mission_id);
        avro::encode(e, v.satellite_id);
        avro::encode(e, v.add_to_database);
        avro::encode(e, v.epoch_format);
        avro::encode(e, v.start_time);
        avro::encode(e, v.stop_time);
        avro::encode(e, v.step_size);
        avro::encode(e, v.initial_position);
        avro::encode(e, v.initial_velocity);
        avro::encode(e, v.Sgp4Input);
        avro::encode(e, v.output);
    }
    static void decode(Decoder& d, IW::MsgPropagateSGP4& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.mission_id);
                    break;
                case 2:
                    avro::decode(d, v.satellite_id);
                    break;
                case 3:
                    avro::decode(d, v.add_to_database);
                    break;
                case 4:
                    avro::decode(d, v.epoch_format);
                    break;
                case 5:
                    avro::decode(d, v.start_time);
                    break;
                case 6:
                    avro::decode(d, v.stop_time);
                    break;
                case 7:
                    avro::decode(d, v.step_size);
                    break;
                case 8:
                    avro::decode(d, v.initial_position);
                    break;
                case 9:
                    avro::decode(d, v.initial_velocity);
                    break;
                case 10:
                    avro::decode(d, v.Sgp4Input);
                    break;
                case 11:
                    avro::decode(d, v.output);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.mission_id);
            avro::decode(d, v.satellite_id);
            avro::decode(d, v.add_to_database);
            avro::decode(d, v.epoch_format);
            avro::decode(d, v.start_time);
            avro::decode(d, v.stop_time);
            avro::decode(d, v.step_size);
            avro::decode(d, v.initial_position);
            avro::decode(d, v.initial_velocity);
            avro::decode(d, v.Sgp4Input);
            avro::decode(d, v.output);
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
            avro::encode(e, v.get_MsgErrorData());
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
                IW::MsgErrorData vv;
                avro::decode(d, vv);
                v.set_MsgErrorData(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::MsgPropagateSGP4Response> {
    static void encode(Encoder& e, const IW::MsgPropagateSGP4Response& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.error_data);
        avro::encode(e, v.mission_id);
        avro::encode(e, v.satellite_id);
        avro::encode(e, v.reference_frame);
        avro::encode(e, v.epoch_format);
        avro::encode(e, v.output_format);
        avro::encode(e, v.ephemeris);
        avro::encode(e, v.ephemeris_text);
    }
    static void decode(Decoder& d, IW::MsgPropagateSGP4Response& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.error_data);
                    break;
                case 2:
                    avro::decode(d, v.mission_id);
                    break;
                case 3:
                    avro::decode(d, v.satellite_id);
                    break;
                case 4:
                    avro::decode(d, v.reference_frame);
                    break;
                case 5:
                    avro::decode(d, v.epoch_format);
                    break;
                case 6:
                    avro::decode(d, v.output_format);
                    break;
                case 7:
                    avro::decode(d, v.ephemeris);
                    break;
                case 8:
                    avro::decode(d, v.ephemeris_text);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.error_data);
            avro::decode(d, v.mission_id);
            avro::decode(d, v.satellite_id);
            avro::decode(d, v.reference_frame);
            avro::decode(d, v.epoch_format);
            avro::decode(d, v.output_format);
            avro::decode(d, v.ephemeris);
            avro::decode(d, v.ephemeris_text);
        }
    }
};

template<> struct codec_traits<IW::MsgRunScript> {
    static void encode(Encoder& e, const IW::MsgRunScript& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.output_file_name);
        avro::encode(e, v.script_text);
    }
    static void decode(Decoder& d, IW::MsgRunScript& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.output_file_name);
                    break;
                case 2:
                    avro::decode(d, v.script_text);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.output_file_name);
            avro::decode(d, v.script_text);
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
            avro::encode(e, v.get_MsgErrorData());
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
                IW::MsgErrorData vv;
                avro::decode(d, vv);
                v.set_MsgErrorData(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::MsgRunScriptResponse> {
    static void encode(Encoder& e, const IW::MsgRunScriptResponse& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.error_data);
        avro::encode(e, v.output);
    }
    static void decode(Decoder& d, IW::MsgRunScriptResponse& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.error_data);
                    break;
                case 2:
                    avro::decode(d, v.output);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.error_data);
            avro::decode(d, v.output);
        }
    }
};

template<> struct codec_traits<IW::MsgGetStatus> {
    static void encode(Encoder& e, const IW::MsgGetStatus& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.component_id);
    }
    static void decode(Decoder& d, IW::MsgGetStatus& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.component_id);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.component_id);
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
            avro::encode(e, v.get_MsgErrorData());
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
                IW::MsgErrorData vv;
                avro::decode(d, vv);
                v.set_MsgErrorData(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::IntComponentStatusEnum> {
    static void encode(Encoder& e, IW::IntComponentStatusEnum v) {
        if (v > IW::IntComponentStatusEnum::FAILED)
        {
            std::ostringstream error;
            error << "enum value " << static_cast<unsigned>(v) << " is out of bound for IW::IntComponentStatusEnum and cannot be encoded";
            throw avro::Exception(error.str());
        }
        e.encodeEnum(static_cast<size_t>(v));
    }
    static void decode(Decoder& d, IW::IntComponentStatusEnum& v) {
        size_t index = d.decodeEnum();
        if (index > static_cast<size_t>(IW::IntComponentStatusEnum::FAILED))
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
        avro::encode(e, v.header);
        avro::encode(e, v.error_data);
        avro::encode(e, v.component_id);
        avro::encode(e, v.component_status);
    }
    static void decode(Decoder& d, IW::MsgGetStatusResponse& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.error_data);
                    break;
                case 2:
                    avro::decode(d, v.component_id);
                    break;
                case 3:
                    avro::decode(d, v.component_status);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.error_data);
            avro::decode(d, v.component_id);
            avro::decode(d, v.component_status);
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
            avro::encode(e, v.get_MsgErrorData());
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
                IW::MsgErrorData vv;
                avro::decode(d, vv);
                v.set_MsgErrorData(vv);
            }
            break;
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
            avro::encode(e, v.get_string());
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
                std::string vv;
                avro::decode(d, vv);
                v.set_string(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::MsgErrorResponse> {
    static void encode(Encoder& e, const IW::MsgErrorResponse& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.error_data);
        avro::encode(e, v.other_info);
    }
    static void decode(Decoder& d, IW::MsgErrorResponse& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.error_data);
                    break;
                case 2:
                    avro::decode(d, v.other_info);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.error_data);
            avro::decode(d, v.other_info);
        }
    }
};

template<> struct codec_traits<IW::MsgGetEvents> {
    static void encode(Encoder& e, const IW::MsgGetEvents& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.mission_id);
        avro::encode(e, v.satellite_id);
        avro::encode(e, v.epoch_format);
        avro::encode(e, v.start_time);
        avro::encode(e, v.stop_time);
        avro::encode(e, v.ground_station_id);
        avro::encode(e, v.antenna_id);
        avro::encode(e, v.lattitude);
        avro::encode(e, v.longitude);
        avro::encode(e, v.altitude);
        avro::encode(e, v.event_types);
    }
    static void decode(Decoder& d, IW::MsgGetEvents& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.mission_id);
                    break;
                case 2:
                    avro::decode(d, v.satellite_id);
                    break;
                case 3:
                    avro::decode(d, v.epoch_format);
                    break;
                case 4:
                    avro::decode(d, v.start_time);
                    break;
                case 5:
                    avro::decode(d, v.stop_time);
                    break;
                case 6:
                    avro::decode(d, v.ground_station_id);
                    break;
                case 7:
                    avro::decode(d, v.antenna_id);
                    break;
                case 8:
                    avro::decode(d, v.lattitude);
                    break;
                case 9:
                    avro::decode(d, v.longitude);
                    break;
                case 10:
                    avro::decode(d, v.altitude);
                    break;
                case 11:
                    avro::decode(d, v.event_types);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.mission_id);
            avro::decode(d, v.satellite_id);
            avro::decode(d, v.epoch_format);
            avro::decode(d, v.start_time);
            avro::decode(d, v.stop_time);
            avro::decode(d, v.ground_station_id);
            avro::decode(d, v.antenna_id);
            avro::decode(d, v.lattitude);
            avro::decode(d, v.longitude);
            avro::decode(d, v.altitude);
            avro::decode(d, v.event_types);
        }
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
            avro::encode(e, v.get_MsgErrorData());
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
                IW::MsgErrorData vv;
                avro::decode(d, vv);
                v.set_MsgErrorData(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<IW::MsgGetEventsResponse> {
    static void encode(Encoder& e, const IW::MsgGetEventsResponse& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.error_data);
        avro::encode(e, v.mission_id);
        avro::encode(e, v.satellite_id);
        avro::encode(e, v.ground_station_id);
        avro::encode(e, v.antenna_id);
        avro::encode(e, v.event_types);
    }
    static void decode(Decoder& d, IW::MsgGetEventsResponse& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.header);
                    break;
                case 1:
                    avro::decode(d, v.error_data);
                    break;
                case 2:
                    avro::decode(d, v.mission_id);
                    break;
                case 3:
                    avro::decode(d, v.satellite_id);
                    break;
                case 4:
                    avro::decode(d, v.ground_station_id);
                    break;
                case 5:
                    avro::decode(d, v.antenna_id);
                    break;
                case 6:
                    avro::decode(d, v.event_types);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.header);
            avro::decode(d, v.error_data);
            avro::decode(d, v.mission_id);
            avro::decode(d, v.satellite_id);
            avro::decode(d, v.ground_station_id);
            avro::decode(d, v.antenna_id);
            avro::decode(d, v.event_types);
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

template<> struct codec_traits<IW::AvroTypes_proc_Union__8__> {
    static void encode(Encoder& e, IW::AvroTypes_proc_Union__8__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_RadixEnum());
            break;
        case 1:
            avro::encode(e, v.get_ModuleTypeEnum());
            break;
        case 2:
            avro::encode(e, v.get_FdsEventEnum());
            break;
        case 3:
            avro::encode(e, v.get_Subsystem());
            break;
        case 4:
            avro::encode(e, v.get_Satellite());
            break;
        case 5:
            avro::encode(e, v.get_Mission());
            break;
        case 6:
            avro::encode(e, v.get_User());
            break;
        case 7:
            avro::encode(e, v.get_ListSatellites());
            break;
        case 8:
            avro::encode(e, v.get_StateVector());
            break;
        case 9:
            avro::encode(e, v.get_FdsEvent());
            break;
        case 10:
            avro::encode(e, v.get_MsgHeader());
            break;
        case 11:
            avro::encode(e, v.get_MsgReceivedHeader());
            break;
        case 12:
            avro::encode(e, v.get_MsgErrorData());
            break;
        case 13:
            avro::encode(e, v.get_MsgPropagateSGP4());
            break;
        case 14:
            avro::encode(e, v.get_MsgPropagateSGP4Response());
            break;
        case 15:
            avro::encode(e, v.get_MsgRunScript());
            break;
        case 16:
            avro::encode(e, v.get_MsgRunScriptResponse());
            break;
        case 17:
            avro::encode(e, v.get_MsgGetStatus());
            break;
        case 18:
            avro::encode(e, v.get_MsgGetStatusResponse());
            break;
        case 19:
            avro::encode(e, v.get_MsgErrorResponse());
            break;
        case 20:
            avro::encode(e, v.get_MsgGetEvents());
            break;
        case 21:
            avro::encode(e, v.get_MsgGetEventsResponse());
            break;
        case 22:
            avro::encode(e, v.get_AvroNone());
            break;
        }
    }
    static void decode(Decoder& d, IW::AvroTypes_proc_Union__8__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 23) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                IW::RadixEnum vv;
                avro::decode(d, vv);
                v.set_RadixEnum(vv);
            }
            break;
        case 1:
            {
                IW::ModuleTypeEnum vv;
                avro::decode(d, vv);
                v.set_ModuleTypeEnum(vv);
            }
            break;
        case 2:
            {
                IW::FdsEventEnum vv;
                avro::decode(d, vv);
                v.set_FdsEventEnum(vv);
            }
            break;
        case 3:
            {
                IW::Subsystem vv;
                avro::decode(d, vv);
                v.set_Subsystem(vv);
            }
            break;
        case 4:
            {
                IW::Satellite vv;
                avro::decode(d, vv);
                v.set_Satellite(vv);
            }
            break;
        case 5:
            {
                IW::Mission vv;
                avro::decode(d, vv);
                v.set_Mission(vv);
            }
            break;
        case 6:
            {
                IW::User vv;
                avro::decode(d, vv);
                v.set_User(vv);
            }
            break;
        case 7:
            {
                IW::ListSatellites vv;
                avro::decode(d, vv);
                v.set_ListSatellites(vv);
            }
            break;
        case 8:
            {
                IW::StateVector vv;
                avro::decode(d, vv);
                v.set_StateVector(vv);
            }
            break;
        case 9:
            {
                IW::FdsEvent vv;
                avro::decode(d, vv);
                v.set_FdsEvent(vv);
            }
            break;
        case 10:
            {
                IW::MsgHeader vv;
                avro::decode(d, vv);
                v.set_MsgHeader(vv);
            }
            break;
        case 11:
            {
                IW::MsgReceivedHeader vv;
                avro::decode(d, vv);
                v.set_MsgReceivedHeader(vv);
            }
            break;
        case 12:
            {
                IW::MsgErrorData vv;
                avro::decode(d, vv);
                v.set_MsgErrorData(vv);
            }
            break;
        case 13:
            {
                IW::MsgPropagateSGP4 vv;
                avro::decode(d, vv);
                v.set_MsgPropagateSGP4(vv);
            }
            break;
        case 14:
            {
                IW::MsgPropagateSGP4Response vv;
                avro::decode(d, vv);
                v.set_MsgPropagateSGP4Response(vv);
            }
            break;
        case 15:
            {
                IW::MsgRunScript vv;
                avro::decode(d, vv);
                v.set_MsgRunScript(vv);
            }
            break;
        case 16:
            {
                IW::MsgRunScriptResponse vv;
                avro::decode(d, vv);
                v.set_MsgRunScriptResponse(vv);
            }
            break;
        case 17:
            {
                IW::MsgGetStatus vv;
                avro::decode(d, vv);
                v.set_MsgGetStatus(vv);
            }
            break;
        case 18:
            {
                IW::MsgGetStatusResponse vv;
                avro::decode(d, vv);
                v.set_MsgGetStatusResponse(vv);
            }
            break;
        case 19:
            {
                IW::MsgErrorResponse vv;
                avro::decode(d, vv);
                v.set_MsgErrorResponse(vv);
            }
            break;
        case 20:
            {
                IW::MsgGetEvents vv;
                avro::decode(d, vv);
                v.set_MsgGetEvents(vv);
            }
            break;
        case 21:
            {
                IW::MsgGetEventsResponse vv;
                avro::decode(d, vv);
                v.set_MsgGetEventsResponse(vv);
            }
            break;
        case 22:
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
