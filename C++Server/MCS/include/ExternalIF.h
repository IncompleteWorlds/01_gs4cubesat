/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __MCS_EXTERNALIF_H__
#define __MCS_EXTERNALIF_H__

#include "CommonTypes.h"



/**
 * This class is the entry point of the component.
 * It will be used by other protocol adapters like REST, QPID
 *
 */
class ExternalIF
{
    public:
        ExternalIF();
        virtual ~ExternalIF();

        void newFrame(const RawFrameType& inFrame, const int32_t inFrameSize);

        void newFrame(const std::string& inFrame, const int32_t inFrameSize);

    protected:

    private:
};

#endif // __MCS_EXTERNALIF_H__
