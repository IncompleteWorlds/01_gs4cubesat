/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __EVENT_TYPE_ENUM_H__
#define __EVENT_TYPE_ENUM_H__

enum class EventTypeEnum {
    EVT_NONE = 0,

    // MCS
    EVT_NEW_RAW_FRAME,
    EVT_NEW_PROCESSED_FRAME,


    EVT_MAXIMUM
};

#endif // __EVENT_TYPE_ENUM_H__

