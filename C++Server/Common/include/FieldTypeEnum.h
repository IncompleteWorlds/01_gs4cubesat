/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#ifndef __FIELD_TYPE_ENUM__
#define __FIELD_TYPE_ENUM__

//  None - 0, 
//    Boolean - 1, 
//    Enumerated - 2, 
//    Unsigned Integer - 3, 
//    Signed Integer - 4
//  Real - 5, 
//    Bit-String - 6, 
//    Octet-String - 7, 
//    Character-String (ASCII) - 8
//  Absolute Time - 9,
//    Relative Time - 10, 
//    Deduced - 11
//
enum class FieldTypeEnum
{
    NONE = 0,

    BOOLEAN = 1,
    ENUMERATED = 2,
    UNSIGED_INTEGER = 3,
    SIGNED_INTEGER = 4,
    DOUBLE = 5,
    BIT_STRING = 6,
    OCTET_STRING = 7,
    STRING = 8,
    ABSOLUTE_DATE = 9,
    RELATIVE_TIME = 10,
    DEDUCED = 11,
};


//  Int8, Int16, Int32, Int64, UInt8, Uint16, Uint32, UInt64
//
enum class FieldSubTypeEnum
{
    INT8 = 0,
    INT16 = 1,
    INT32 = 2,
    INT64 = 3,
    
    UINT8 = 4,
    UINT16 = 5,
    UINT32 = 6,
    UINT64 = 7,
};

#endif // __FIELD_TYPE_ENUM__

