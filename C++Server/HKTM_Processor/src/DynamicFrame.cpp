/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */


#include "DynamicFrame.h"

DynamicFrame::DynamicFrame(IW::FrameType& inType)
    : frame_{}
{
    createComposite(inType);
}

DynamicFrame::DynamicFrame()
    : frame_{}
{
}

DynamicFrame::~DynamicFrame()
{
}

void DynamicFrame::read(Bitstream& inBs)
{
    frame_.read(inBs);
}

void DynamicFrame::write(OutBitstream& outBs)
{
    frame_.write(outBs);
}

void DynamicFrame::createComposite(IW::FrameType& inFrameType)
{
    if(inFrameType.hktmFlag == true) 
    {
        // Create an item for each field in the frame
        for(auto currentField : inFrameType.tmFields) 
        {
            IComponentFrameSharedPtr newField{ new ComponentLeaf{ static_cast<uint>(currentField.lengthBits) } };

            frame_.add(newField);
        }
        
        // Check the dependent fields. Only for TM
        for(auto currentField : inFrameType.tmFields) 
        {
            // Check it is not the same field. Circular reference
            if (currentField.lengthFieldId != 0 && currentField.lengthFieldId != currentField.identifier) 
            {
                // Look for the linked field. The field that the defines the length
                IComponentFrameSharedPtr fieldIdComposite = getComposite(currentField.lengthFieldId);
                
                // Get this field
                IComponentFrameSharedPtr currentFieldComposite = getComposite(currentField.identifier);
                
                // Set the link
                // Downcast from Base class to Derived class
                ComponentLeafSharedPtr targetField{ dynamic_pointer_cast<ComponentLeaf>(currentFieldComposite) };
                ComponentLeafSharedPtr linkedField{ dynamic_pointer_cast<ComponentLeaf>(fieldIdComposite) };
                
                targetField->setLinkedField(linkedField);
            }
        }
    } 
    else 
    {
        // Create an item for each field in the frame
        for(auto currentField : inFrameType.tcFields) 
        {
            IComponentFrameSharedPtr newField{ new ComponentLeaf{ static_cast<uint>(currentField.lengthBits) } };

            frame_.add(newField);
        }
    }
}

IComponentFrameSharedPtr DynamicFrame::getComposite(int32_t inIdentifier)
{
    IComponentFrameSharedPtr output;

    for(auto currentComposite : frame_.getItems()) 
    {
        if(currentComposite->getFieldId() == inIdentifier) 
        {
            output = currentComposite;
            break;
        }
    }

    return output;
}
