/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include "SecurityAccessIF.h"

#include "HKTM_Dispatcher.h"
#include "ExternalIF.h"

ExternalIF::ExternalIF()
{
    //ctor
}

ExternalIF::~ExternalIF()
{
    //dtor
}

void ExternalIF::newFrame(const std::string& inFrame, const int32_t inFrameSize)
{
    RawFrameType  newFrame{inFrameSize};

    for(int i = 0; i < inFrameSize; ++i)
    {
        newFrame[i] = inFrame[i];
    }
}

void newFrame(const RawFrameType& inFrame, const int32_t inFrameSize)
{
    // Authorize operation
    //SecurityAccessIF::getInstance().authorize(const OperationCodeEnum& inOperCode, const RoleEnum &inRole);

    // Check parameters
    if (inFrameSize != 0 && inFrameSize == inFrame.size())
    {
        // Send the frame to the dispatcher
        HKTM_Dispatcher::getInstance().addRawFrame(inFrame);

        // Process the frame

        // Send the processed frame to the dispatcher
        HKTM_Dispatcher::getInstance().addProcessedFrame(inFrame);
    }
}
