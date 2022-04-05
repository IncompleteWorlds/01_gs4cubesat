/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "AvroTypes.h"


#include "BaseLayer.h"


void BaseLayer::setFrameTypes(IW::ListFrameTypes& inListFrameTypes)
{
    // Process all frames
    for(IW::FrameType currentFrame: inListFrameTypes.listFrameTypes)
    {
        // Create Dynamic Frame. Add to the list
        DynamicFrame df{ currentFrame };
        
        frames_.push_back(df);
    }
}