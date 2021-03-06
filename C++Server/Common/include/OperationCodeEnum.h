/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __OPERATION_CODE_ENUM_H__
#define __OPERATION_CODE_ENUM_H__

/**
 * This enum has to be aligned with Java counterpart
 */
enum class OperationCodeEnum {
    CODE_NONE = 0,

    // GENERAL
    // It contains an error code; 0 - No error
    CODE_REPLY_MESSAGE = 10,
    CODE_END_PROCESSING = 11,
    CODE_START_UP = 12,              // A system has just started up
    CODE_START_UP_RESPONSE = 13,
    CODE_SHUTDOWN = 14,
    CODE_SHUTDOWN_RESPONSE = 15,



    // M_C
    CODE_START_M_C = 100,

    CODE_LOGIN = 101,
    CODE_LOGIN_RESPONSE = 102,
    CODE_LOGOUT = 103,
    CODE_PUBLISH_EVENT = 104,         // A system wishes to publish an event in the data bus
    CODE_REGISTER_USER = 105,

    CODE_END_M_C = 199,


    // TOOLS
    CODE_START_TOOLS = 200,

    CODE_GET_MISSION_LAYERS = 201,
    CODE_GET_MISSION_LAYERS_RESPONSE = 202,
    CODE_GET_LAYER_PARAMETERS = 203,              // Retrieve the parameters related to a Comm Layer
    CODE_GET_LAYER_PARAMETERS_RESPONSE = 204,
    CODE_GET_LAYER_FRAME_TYPES = 205,             // Retrieve the Frame Types definitions a layer will use
    CODE_GET_LAYER_FRAME_TYPES_RESPONSE = 206,
    
    CODE_IMPORT_SC_DATABASE = 207,
    
    CODE_ADD_MISSION = 208,
    CODE_ADD_MISSION_RESPONSE = 209,
    CODE_GET_MISSION = 210,
    CODE_GET_MISSION_RESPONSE = 211,
    CODE_UPDATE_MISSION = 212,
    CODE_UPDATE_MISSION_RESPONSE = 213,
    CODE_DELETE_MISSION = 214,
    CODE_DELETE_MISSION_RESPONSE = 215,
    
    CODE_ADD_SATELLITE = 216,
    CODE_ADD_SATELLITE_RESPONSE = 217,
    CODE_GET_SATELLITE = 218,
    CODE_GET_SATELLITE_RESPONSE = 219,
    CODE_UPDATE_SATELLITE = 220,
    CODE_UPDATE_SATELLITE_RESPONSE = 221,
    CODE_DELETE_SATELLITE = 222,
    CODE_DELETE_SATELLITE_RESPONSE = 223,
    
    CODE_ADD_SUBSYSTEM = 224,
    CODE_ADD_SUBSYSTEM_RESPONSE = 225,
    CODE_GET_SUBSYSTEM = 226,
    CODE_GET_SUBSYSTEM_RESPONSE = 227,
    CODE_UPDATE_SUBSYSTEM = 228,
    CODE_UPDATE_SUBSYSTEM_RESPONSE = 229,
    CODE_DELETE_SUBSYSTEM = 230,
    CODE_DELETE_SUBSYSTEM_RESPONSE = 231,
    
    CODE_ADD_NODE = 232,
    CODE_ADD_NODE_RESPONSE = 233,
    CODE_GET_NODE = 234,
    CODE_GET_NODE_RESPONSE = 235,
    CODE_UPDATE_NODE = 236,
    CODE_UPDATE_NODE_RESPONSE = 237,
    CODE_DELETE_NODE = 238,
    CODE_DELETE_NODE_RESPONSE = 239,
    
    CODE_ADD_TC = 240,
    CODE_ADD_TC_RESPONSE = 241,
    CODE_GET_TC = 242,
    CODE_GET_TC_RESPONSE = 243,
    CODE_UPDATE_TC = 244,
    CODE_UPDATE_TC_RESPONSE = 245,
    CODE_DELETE_TC = 246,
    CODE_DELETE_TC_RESPONSE = 247,
    
    CODE_ADD_TM = 248,
    CODE_ADD_TM_RESPONSE = 249,
    CODE_GET_TM = 250,
    CODE_GET_TM_RESPONSE = 251,
    CODE_UPDATE_TM = 252,
    CODE_UPDATE_TM_RESPONSE = 253,
    CODE_DELETE_TM = 254,
    CODE_DELETE_TM_RESPONSE = 255,
    
    CODE_ADD_FRAME = 256,
    CODE_ADD_FRAME_RESPONSE = 257,
    CODE_GET_FRAME = 258,
    CODE_GET_FRAME_RESPONSE = 259,
    CODE_UPDATE_FRAME = 260,
    CODE_UPDATE_FRAME_RESPONSE = 261,
    CODE_DELETE_FRAME = 262,
    CODE_DELETE_FRAME_RESPONSE = 263,
    
    CODE_GET_DEFAULT_MISSION_LAYERS = 264,
    CODE_GET_DEFAULT_MISSION_LAYERS_RESPONSE = 265,
    CODE_ADD_MISSION_LAYER = 266,
    CODE_ADD_MISSION_LAYER_RESPONSE = 267,
    CODE_DELETE_MISSION_LAYER = 268,
    CODE_DELETE_MISSION_LAYER_RESPONSE = 269,
    
    CODE_END_TOOLS = 299,


    // MCS
    CODE_START_MCS = 300,

    CODE_NEW_RAW_FRAME=301,       // Message send to dispatcher. TBC
                                  // Message from GS Manager to HK TM Processor containing a new raw data frame

    CODE_END_MCS = 399,


    // FDS
    CODE_START_FDS = 400,

    CODE_GET_PASSES = 401,
    CODE_GET_PASSES_RESPONSE = 402,

    CODE_END_FDS = 499,


    // GS MANAGER
    CODE_START_GS_MANAGER = 500,

    CODE_CONNECT_GROUND_STATION = 501,
    CODE_CONNECT_GROUND_STATION_RESPONSE = 502,
    CODE_DISCONNECT_GROUND_STATION = 503,
    CODE_DISCONNECT_GROUND_STATION_RESPONSE = 504,
    CODE_SEND_FRAME_GROUND_STATION = 505,
    CODE_SEND_FRAME_GROUND_STATION_RESPONSE = 506,
    CODE_ADD_GROUND_STATION  = 507,
    CODE_ADD_GROUND_STATION_RESPONSE = 508,
    CODE_REMOVE_GROUND_STATION = 509,
    CODE_REMOVE_GROUND_STATION_RESPONSE = 510,
    CODE_UPDATE_GROUND_STATION = 511,
    CODE_UPDATE_GROUND_STATION_RESPONSE = 512,
    CODE_GET_GROUND_STATION = 513,
    CODE_GET_GROUND_STATION_RESPONSE = 514,

    CODE_END_GS_MANAGER = 599,


    CODE_MAXIMUM
};


#endif // __OPERATION_CODE_ENUM_H__
