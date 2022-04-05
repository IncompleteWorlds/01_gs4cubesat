/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __BASEMESSAGE_H__
#define __BASEMESSAGE_H__

#include "IMessageProcessor.h"


class BaseMessage : public IMessageProcessor
{
    public:
        BaseMessage() {};
        virtual ~BaseMessage() {};

};

#endif // __BASEMESSAGE_H__

