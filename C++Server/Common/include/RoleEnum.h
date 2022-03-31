/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __ROLE__ENUM_H_INCLUDED__
#define __ROLE__ENUM_H_INCLUDED__

enum class RoleEnum {
    ROLE_READ_ONLY  = 0,
    ROLE_NORMAL = 1,
    ROLE_ADMINISTRATOR = 2,
    
    ROLE_MISSION_OPERATOR =10,
    ROLE_MISSION_ADMINISTRATOR = 11
};


#endif // __ROLE__ENUM_H_INCLUDED__
