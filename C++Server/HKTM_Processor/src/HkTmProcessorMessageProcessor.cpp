/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <memory>
#include <thread>

using namespace std;

#include "AvroTypes.h"

#include "HkTmProcessorModuleManager.h"
#include "HkTmProcessorFactoryMessage.h"

#include "GSException.h"

#include "TimeUtils.h"
#include "MessageUtils.h"

#include "HkTmProcessorMessageProcessor.h"


HkTmProcessorMessageProcessor::HkTmProcessorMessageProcessor()
    : BaseMessage{}, frameCounter_{0}
{
}

HkTmProcessorMessageProcessor::~HkTmProcessorMessageProcessor()
{
}

/**
 * Process received messages. They are received as an external component
 * requesting a service or as a response
 */
ServerMessage HkTmProcessorMessageProcessor::processMessage(const ServerMessage &inMessage, ServerWorker& inParent)
{
    ServerMessage  firstOutputMessage;

    // Process the message
    cout << "log.DEBUG  Message Processor. Process Msg: " << inMessage.getOperationCodeAsInt() << endl;

    // Special case
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_NEW_RAW_FRAME)
    {
        // A new frame has been received from the GS Manager
        // Process the frame without creating a new message
        processNewRawFrame(inMessage);

        // Reply; no error
        createReply(firstOutputMessage, 0, "");
    }
    else
    {
        // Create and store the message
        shared_ptr<BaseMessage> currentMessage = HkTmProcessorFactoryMessage::createMessage(inMessage);

        if (currentMessage.get() != nullptr)
        {
            // It is a bit redundant, but we are reusing IMessageProcessor interface
            firstOutputMessage = currentMessage->processMessage(inMessage, inParent);
        }
        else
        {
            createReply(firstOutputMessage, -1, "ERROR: Unknown message. IGNORED");
            // Unknown message
            cout << "ERROR: Unknown message. IGNORED" << endl;
        }
    }

    return firstOutputMessage;
}

void HkTmProcessorMessageProcessor::processNewRawFrame(const ServerMessage &inMessage)
{
    // Encode link  -->  Valid range  -->  Calibration --> Host data  -->  Alarm
    // Data type         check             step            type            check


    try
    {
        // Send the raw frame to the Archive.
        HkTmProcessorModuleManager::getInstance().publishEvent(inMessage, EventTypeEnum::EVT_NEW_RAW_FRAME);


        // Decommute frame
        shared_ptr<BaseLayer>  currentLayer;
        IW::ProcessedFrame     processedFrame;
        RawFrameType           currentDataField{ static_cast<ServerMessage>(inMessage).getData() };
    
        // Set frame details
        processedFrame.id = frameCounter_;
        processedFrame.frameTypeId = 0;
        processedFrame.creationTime = TimeUtils::now();

        for(uint i = 0; i < HkTmProcessorModuleManager::getInstance().getNumLayers(); i ++)
        {
            currentLayer = HkTmProcessorModuleManager::getInstance().getLayer(i);

            // Process using next protocol
            processedFrame = currentLayer->indication(currentDataField);

            // Empty?
            if (processedFrame.groups.size() > 0)
            {
                // Extract data field
                uint groupId = currentLayer->getDataGroupIndex();
                uint fieldId = currentLayer->getDataFieldIndex();
                
                IW::ProcessedField  tmpField = processedFrame.groups[groupId].fields[fieldId];

                currentDataField = stringToVector(tmpField.value);
            }
        }

        // Emtpy?
        if (processedFrame.groups.size() > 0)
        {
            /*
            // Convert between Avro and internal format
            IW::ProcessedFrame  avroProcessedFrame;

            avroProcessedFrame.id            = processedFrame.id_;
            avroProcessedFrame.frameTypeId   = processedFrame.frameTypeId_;
            avroProcessedFrame.creationTime  = processedFrame.creationTime_;
            
            // Copy groups
            for(IntGroupProcessedField currentGroup: processedFrame.groups_)
            {
                IW::GroupProcessedField  avroGroup;
                
                avroGroup.id = currentGroup.id_;
                avroGroup.oolFields = currentGroup.oolFields_;
                avroGroup.oolFlag = currentGroup.oolFlag_;
                              
                // Copy fields
                for(IntProcessedField  currentField: currentGroup.fields_)
                {
                    IW::ProcessedField   avroField;

                    avroField.index        = currentField.index_;
                    avroField.fieldTypeId  = currentField.fieldTypeId_;
                    avroField.fieldName    = currentField.fieldName_;
                    avroField.value        = currentField.value_;

                    // Add field to group
                    avroGroup.fields.push_back(avroField);
                }
                
                // Add group to frame
                avroProcessedFrame.groups.push_back(avroGroup);
            }
            */

            VectorUint8  avroOutputMessage = buildMessageVector<IW::ProcessedFrame>(processedFrame);

            // Retrieve last processed frame. Send to the TM Archive
            ServerMessage tmpProcessedMessage;

            tmpProcessedMessage.setData(avroOutputMessage);

            HkTmProcessorModuleManager::getInstance().publishEvent(tmpProcessedMessage, EventTypeEnum::EVT_NEW_PROCESSED_FRAME);
        }
    } catch(GSException& exc)
    {
        // Frame rejected. Write an error message
        cout << "ERROR: Rejected frame. Invalid format" << endl;
    }
}

