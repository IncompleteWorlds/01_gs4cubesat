/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <unistd.h>   // getcwd

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

#include "AvroTypes.h"

#include "ToolsDatabase.h"
#include "GSException.h"
#include "LogManager.h"
#include "MessageUtils.h"

#include "ImportScDbMessage.h"

ImportScDbMessage::ImportScDbMessage()
{
}

ImportScDbMessage::~ImportScDbMessage()
{
}

//ServerMessage ImportScDbMessage::processMessage(const ServerMessage& inMessage, ServerWorkerZmq& inParent)
ServerMessage ImportScDbMessage::processMessage(const ServerMessage& inMessage)
{
    // Create reply message
    ServerMessage          outputMessage;

    // Check message code
    if (inMessage.getOperationCode() == OperationCodeEnum::CODE_IMPORT_SC_DATABASE)
    {
        // Extract the AVRO message from body
        IW::MsgImportScDatabase      avroInputMessage;

        try
        {
            // ----------------------------------------------------------------------
            extractMessageVector<IW::MsgImportScDatabase>(static_cast<ServerMessage>(inMessage).getData(), avroInputMessage);

            if (avroInputMessage.fileName.empty() == true)
            {
                string errorMessage = "Empty S/C database file name";
                LogManager::getInstance().error(errorMessage);

                createReply(outputMessage, -1, errorMessage);
            }
            else
            {
                // Get current working directory
                char cwd[1024];

                getcwd(cwd, sizeof(cwd));

                string currentDirectory{cwd};
                
                string fileNamePath = currentDirectory + PATH_SEPARATOR + avroInputMessage.fileName;
                LogManager::getInstance().debug("File name: " + fileNamePath);
                
                // Write current chunk of data
                ofstream  outputFile(fileNamePath.c_str(), ios::binary | ios::app);
                
                outputFile.write(avroInputMessage.buffer.c_str(), avroInputMessage.buffer.size());
                outputFile.close();
            
                // If it is the last message, close the file and process it
                if (avroInputMessage.chunkNumber == (avroInputMessage.numberOfChunks - 1))
                {         
                    switch(avroInputMessage.fileType)
                    {
                        case 0: 
                            processExcel(avroInputMessage, outputMessage);
                            break;
                        
                        case 1: 
                            processCsv(avroInputMessage, outputMessage);
                            break;
                        
                        case 2: 
                            processXtce(avroInputMessage, outputMessage);
                            break;
                        
                        default: 
                            processExcel(avroInputMessage, outputMessage);
                            break;
                    }
                }
                else
                {
                    // Continue reading / receiving chunk of data
                    createReply(outputMessage, 0, "");
                }                    
            }
            // ----------------------------------------------------------------------
        } catch(GSException& gsExc)
        {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
            createReply(outputMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
        }
    }
    else
    {
        string errorMessage = "Invalid received message: " + static_cast<ServerMessage>(inMessage).toString();
        LogManager::getInstance().error(errorMessage);

        createReply(outputMessage, -1, errorMessage);
    }

    outputMessage.setCorrelationId(inMessage.getCorrelationId());

    LogManager::getInstance().debug("Import S/C Database response: " + outputMessage.toString());

    return outputMessage;
}

void ImportScDbMessage::processExcel(IW::MsgImportScDatabase  &inMessage, ServerMessage &outMessage)
{
    ExcelFormat::BasicExcel xls;

    // Open the Excel
    if (xls.Load(inMessage.fileName.c_str())==true) {
        
        // Open Tab 0: HK TM
        shared_ptr<ExcelFormat::BasicExcelWorksheet>   hkTmTab(xls.GetWorksheet("TM"));
        
        uint firstLine = 0;
        
        if (hkTmTab.get() != nullptr) {
            for(uint i = 0; i < hkTmTab->GetTotalRows(); i++) {
                // Skip comment lines
                string   tmpString;
                 
                if (hkTmTab->Cell(i, 0)->GetString() != nullptr) {
                    tmpString = hkTmTab->Cell(i, 0)->GetString();
                    if (tmpString[0] == '#') {
                        continue;
                    }
                    
                    firstLine ++;
                }
                
                // First row is the header row
                if (i > firstLine) {
                    IW::TM_Parameter  newParameter;
                    
                    extractTmParameter(hkTmTab, i, newParameter);
                    
                    // Save the new parameter in the DB
                    try {
                        ToolsDatabase::getInstance().createTmParameter(newParameter);
                    } catch(GSException& gsExc) {
                        LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
                        createReply(outMessage, gsExc.getErrorCode(), gsExc.getErrorMessage());
                    }

                    LogManager::getInstance().info("Parameter: " + newParameter.name + " correctly created");
                }
            }
            
        } else {
            string errorMessage = "Telemetry tab 'TM' not found in Excel file: " + inMessage.fileName;
            LogManager::getInstance().error(errorMessage);

            createReply(outMessage, -1, errorMessage);            
        }
        
        
        // Open Tab 1: TC
        
        // Open Tab 2: Frames
        
        // Open Tab 3: Layers
        
        xls.Close();
        
    } else {
        string errorMessage = "Unable to open Excel file: " + inMessage.fileName;
        LogManager::getInstance().error(errorMessage);

        createReply(outMessage, -1, errorMessage);
    }
}

void ImportScDbMessage::extractTmParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet> &inTab, uint inRowIndex, IW::TM_Parameter &outParameter)
{
    int32_t           tmpInt;
    int32_t           tmpInt1;
    string            tmpString;
    
    // identifier
    if (inTab->Cell(inRowIndex, 0)->Get(tmpInt) == true)
        outParameter.identifier = tmpInt;
        
    // node
    if (inTab->Cell(inRowIndex, 2)->Get(tmpInt) == true)
        outParameter.node = tmpInt;

    // channel
    if (inTab->Cell(inRowIndex, 3)->Get(tmpInt) == true)
        outParameter.channel = tmpInt;

    // tmType
    if (inTab->Cell(inRowIndex, 4)->Get(tmpInt) == true) {                        
        outParameter.valueType = static_cast<IW::TmTypeEnum>(tmpInt);
    }

    // name
    if (inTab->Cell(inRowIndex, 6)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, 6)->GetString();
        outParameter.name = tmpString;
    }
    
    // displayName
    if (inTab->Cell(inRowIndex, 7)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, 7)->GetString();
        outParameter.displayName = tmpString;
    }
    
    // description
    if (inTab->Cell(inRowIndex, 8)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, 8)->GetString();
        outParameter.description = tmpString;
    }
    
    // lengthFieldId
    if (inTab->Cell(inRowIndex, 9)->Get(tmpInt) == true)
        outParameter.lengthFieldId = tmpInt;
        
    // lengthBits
    if (inTab->Cell(inRowIndex, 10)->Get(tmpInt) == true)
        outParameter.lengthBits = tmpInt;
        
    // littleEndian
    if (inTab->Cell(inRowIndex, 11)->Get(tmpInt) == true)
        outParameter.lengthBits = tmpInt;
            
    // units
    if (inTab->Cell(inRowIndex, 13)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, 13)->GetString();
        outParameter.units = tmpString;
    }
  
    // radix
    if (inTab->Cell(inRowIndex, 14)->Get(tmpInt) == true) {
        outParameter.radix = static_cast<IW::RadixEnum>(tmpInt);
    }
    
    // valueType
    if (inTab->Cell(inRowIndex, 15)->Get(tmpInt) == true) {
        outParameter.valueType = static_cast<IW::TmTypeEnum>(tmpInt);
    }
    
    // valueSubType
    if (inTab->Cell(inRowIndex, 16)->Get(tmpInt) == true) {
        outParameter.valueSubType = static_cast<IW::TmSubTypeEnum>(tmpInt);
    }
    
    
    // calibrationCoeffIdentifier
    if (inTab->Cell(inRowIndex, 18)->Get(tmpInt) == true) {
        outParameter.calibrationFunction = tmpInt;
    }
    
    // crcFlag
//    if (inTab->Cell(inRowIndex, 19)->Get(tmpInt) == true) {
//        outParameter.crcFlag = tmpInt;
//    }
    
    // crcAlgorithm
//    if (inTab->Cell(inRowIndex, 20)->Get(tmpInt) == true) {
//        outParameter.crcAlgorithm = tmpInt;
//    }
    
    // counterWarning
//    if (inTab->Cell(inRowIndex, 20)->Get(tmpInt) == true) {
//        outParameter.warningLimits.counter = tmpInt;
//    }
    
    // warning minValue
//    if (inTab->Cell(inRowIndex, 21)->Get(tmpInt) == true) {
//        // do nothing;
//    }
    
    // warning maxValue
//    if (inTab->Cell(inRowIndex, 22)->Get(tmpInt1) == true) {
//        outParameter.warningLimits.minValue = tmpInt;
//        outParameter.warningLimits.minValue = tmpInt1;
//    }

    // counterError
//    if (inTab->Cell(inRowIndex, 20)->Get(tmpInt) == true) {
//        outParameter.errorLimits.counter = tmpInt;
//    }
    
    // error minValue
//    if (inTab->Cell(inRowIndex, 23)->Get(tmpInt) == true) {
//        // do nothing;
//    }
    
    // error maxValue
//    if (inTab->Cell(inRowIndex, 24)->Get(tmpInt1) == true) {
//        outParameter.errorLimits.minValue = tmpInt;
//        outParameter.errorLimits.minValue = tmpInt1;
//    }
    
}

void ImportScDbMessage::processCsv(IW::MsgImportScDatabase  &inMessage, ServerMessage &outMessage)
{
}


void ImportScDbMessage::processXtce(IW::MsgImportScDatabase  &inMessage, ServerMessage &outMessage)
{
}