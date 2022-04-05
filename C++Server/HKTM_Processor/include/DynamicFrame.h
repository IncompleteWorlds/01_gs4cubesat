/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __DYNAMIC_FRAME_H__
#define __DYNAMIC_FRAME_H__

#include <memory>
#include <climits>

using namespace std;


#include <boost/bitstream/iob.hpp>
#include "boost/dynamic_bitset.hpp"
#include "boost/bitstream/bstream.hpp"

using Bitstream = boost::bitstream::ibitstream;
using OutBitstream = boost::bitstream::obitstream;


#include "AvroTypes.h"
#include "CompositeFrame.h"


class DynamicFrame
{
public:
    DynamicFrame(IW::FrameType& inType);
    
    DynamicFrame();
    
    ~DynamicFrame();
    
    void read(Bitstream& inBs);
    
    void write(OutBitstream& outBs);
    
protected:   
    CompositeFrame     frame_;
    
    void createComposite(IW::FrameType& inFrameType);
    
    IComponentFrameSharedPtr getComposite(int32_t inIdentifier);
    
private:
    
    
};

#endif   // __DYNAMICFRAME_H__
