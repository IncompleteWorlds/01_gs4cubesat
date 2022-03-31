/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __COMPOSITE_FRAME_H__
#define __COMPOSITE_FRAME_H__

#include <bitset>
#include <climits>
#include <vector>

using namespace std;

#include <boost/bitstream/iob.hpp>
#include "boost/dynamic_bitset.hpp"
#include "boost/bitstream/bstream.hpp"

using Bitstream = boost::bitstream::ibitstream;
using OutBitstream = boost::bitstream::obitstream;

// This is a hack
class IComponentFrame;
class ComponentLeaf;

using IComponentFrameSharedPtr = shared_ptr<IComponentFrame>;
using ComponentLeafSharedPtr = shared_ptr<ComponentLeaf>;


// Basically, an interface
class IComponentFrame
{
public:
    IComponentFrame()
        : fieldId_{0} {};
        
    IComponentFrame(int32_t  inId)
        : fieldId_{inId} {};
        
    virtual void read(Bitstream& inBs) = 0;
    
    virtual void write(OutBitstream& inBs) = 0;
    
    virtual size_t getLengthBits() = 0;
    
    void setFieldId(int32_t inFieldId)
    {
        this->fieldId_ = inFieldId;
    }
    
    int32_t getFieldId()
    {
        return fieldId_;
    }
    
protected:
    int32_t    fieldId_;
};


class CompositeFrame : public IComponentFrame
{
public:
    CompositeFrame()
        : IComponentFrame{}, items_{} {}
        
    ~CompositeFrame() {}
    
    virtual void read(Bitstream& inBs)
    {
        for(IComponentFrameSharedPtr currentChild : items_)
        {
            currentChild->read(inBs);
        }
    }
    
    virtual void write(OutBitstream& inBs)
    {
        for(IComponentFrameSharedPtr currentChild : items_)
        {
            currentChild->write(inBs);
        }
    }
    
    virtual size_t getLengthBits()
    {
        size_t output = 0;
        
        for(IComponentFrameSharedPtr currentChild : items_)
        {
            output += currentChild->getLengthBits();
        }
        
        return output;
    }
    
    void add(IComponentFrameSharedPtr& inNewComponent)
    {
        items_.push_back(inNewComponent);
    }
    
    vector< IComponentFrameSharedPtr >  getItems()
    {
        return items_;
    }
    
protected:
    vector< IComponentFrameSharedPtr >  items_;
    
};

class ComponentLeaf : public IComponentFrame
{
public:
    ComponentLeaf(uint inNumberBits)
        : IComponentFrame{}, fieldValue_{inNumberBits}, linkedField_{} 
    {
    }
    
    ~ComponentLeaf() {}
    
    virtual size_t getLengthBits()
    {
        return fieldValue_.size();
    }
    
    void read(Bitstream& inBs)
    {
        // Linked field
        if (this->linkedField_.get() != nullptr)
        {
            // If it is linked, reset the length
            fieldValue_.set(linkedField_->getValue());
        }
        
        if (inBs.good() == true)
        {
            inBs >> fieldValue_;
        }
    }
    
    void write(OutBitstream& inBs)
    {
        if (inBs.good() == true)
        {     
            int j = 0;
            std::bitset<8>  aChar;
            
            for(size_t i = 0; fieldValue_.size(); i ++)
            {
                // Clean
                aChar.reset();
                
                // Next char
                for(j = 0; j < CHAR_BIT && i < fieldValue_.size(); j ++, i++)
                {
                    aChar[j] = fieldValue_[i];
                }
                
                // Write char
                inBs << aChar;
            }
        }
    }
    
    ulong getValue()
    {
        return fieldValue_.to_ulong();
    }
    
    // A linked Field is a field which value is the length in bits of this field
    void setLinkedField(ComponentLeafSharedPtr inComposite)
    {
        linkedField_ = inComposite;
    }
    
    ComponentLeafSharedPtr getLinkedField()
    {
        return linkedField_;
    }
    
protected:
    boost::dynamic_bitset<>  fieldValue_;
    
    // A field which value is the length in bits of this fiedl
    ComponentLeafSharedPtr  linkedField_;
};


#endif  //  __COMPOSITE_FRAME_H__
