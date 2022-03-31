#include <iostream>
#include <map>
#include <map>
#include <string>
#include <vector>

using namespace std;

#include "AvroTypes.h"
#include "BasicExcel.hpp"
#include "ConfigurationManager.h"
#include "ExcelFormat.h"
#include "GSException.h"
#include "LogManager.h"
#include "ToolsDatabase.h"

using SharedPtrWorksheet = shared_ptr<ExcelFormat::BasicExcelWorksheet>;

void processExcel(const string& inFileName);
void processTmParameters(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab);
void processTmDerivedParameters(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab);
void processCalibrations(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab);
void processAlgorithms(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab);
void processAlarms(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab);
void processContainers(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab);

void extractTmParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::TM_Parameter& outParameter);
void extractTmDerivedParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::TM_Parameter& outParameter);
void extractAlgorithm(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::Algorithm& outAlgorithm);
void extractAlarm(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::Alarm& outAlarm);
void extractContainerHeader(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::TM_Frame& outContainer, string& outParentContainer);
void extractContainerParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::TM_FrameField& outParameter);
void extractCalibration(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::Calibration& outCalibration);
void extractConditions(IW::TM_Frame& inContainer, const string& inConditionsText);

map<string, IW::TM_Parameter> parametersList;
map<string, IW::Derived_TM_Parameter> derivedParametersList;
map<string, IW::Calibration> calibrationList;

void extractTmParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab,
    uint inRowIndex,
    IW::TM_Parameter& outParameter)
{
    int32_t tmpInt;
    string tmpString;
    int i = 0;

    // Subsystem
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.name = tmpString;
    } else {
        std::string errorMessage = "No parameter name has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // Parameter name
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.name = tmpString;
    } else {
        std::string errorMessage = "No parameter name has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // lengthBits
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        if(tmpInt < 0) {
            std::string errorMessage = "Length in bits cannot be negative";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
        outParameter.lengthBits = tmpInt;
    } else {
        outParameter.lengthBits = 0;
    }
    i++;

    // littleEndian
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        if(tmpInt != 0 && tmpInt != 1) {
            std::string errorMessage = "Little Endian flag has an incorrect value";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
        outParameter.littleEndian = tmpInt;
    } else {
        outParameter.littleEndian = false;
    }
    i++;

    // Prepend size
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true)
        outParameter.prependSize = tmpInt;
    else
        outParameter.prependSize = 0;
    i++;

    // string terminator
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.stringTerminator = tmpString;
    } else {
        outParameter.stringTerminator = "";
    }
    i++;

    // valueType - raw type
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();

        if(tmpString == "uint") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_UNSIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_UINT32;
        }
        if(tmpString == "uint64") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_UNSIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_UINT64;
        }
        if(tmpString == "int") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_SIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_INT32;
        }
        if(tmpString == "int64") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_SIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_INT64;
        }
        if(tmpString == "float") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_DOUBLE;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
        if(tmpString == "boolean") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_BOOLEAN;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
        if(tmpString == "string") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_STRING;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
        if(tmpString == "binary") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_BIT_STRING;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
    } else {
        std::string errorMessage = "No Raw type has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // engType - eng type
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();

        if(tmpString == "uint" || tmpString == "uint32") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_UNSIGNED_INTEGER;
        }

        if(tmpString == "uint64") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_UNSIGNED_INTEGER64;
        }

        if(tmpString == "int" || tmpString == "int32") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_SIGNED_INTEGER;
        }

        if(tmpString == "int64") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_SIGNED_INTEGER64;
        }

        if(tmpString == "enumerated") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_ENUMERATED;

            // NOTE: It has to have an Calibration function associated to it
            if(outParameter.calibrationFunction.empty() == true) {
                std::string errorMessage = "Eng type Enumerated has to have a Calibration function associated to it";
                LogManager::getInstance().error(errorMessage);
                throw GSException(errorMessage);
            }
        }

        if(tmpString == "double") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_DOUBLE;
        }
        if(tmpString == "float") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_FLOAT;
        }

        if(tmpString == "boolean") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_BOOLEAN;
        }

        if(tmpString == "string") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_STRING;
        }

        if(tmpString == "binary") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_BINARY;
        }
    } else {
        std::string errorMessage = "No Engineering type has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // units
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.units = tmpString;
    }
    i++;

    // Calibration function. Needed for checking Eng type
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.calibrationFunction = tmpString;
    } else {
        outParameter.calibrationFunction = "";
    }
    i++;

    // description
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.description = tmpString;
    }
    i++;

    // Do some checkings
    if(outParameter.valueType == IW::TmTypeEnum::TM_TYPE_UNSIGNED_INTEGER ||
        outParameter.valueType == IW::TmTypeEnum::TM_TYPE_SIGNED_INTEGER ||
        outParameter.valueType == IW::TmTypeEnum::TM_TYPE_DOUBLE ||
        outParameter.valueType == IW::TmTypeEnum::TM_TYPE_BIT_STRING) {
        if(outParameter.lengthBits <= 0) {
            std::string errorMessage = "Raw type of numeric type has to have specify a length in bits";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
    }
}

void extractTmDerivedParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab,
    uint inRowIndex,
    IW::Derived_TM_Parameter& outParameter)
{
    int32_t tmpInt;
    string tmpString;
    int i = 0;

    // Subsystem
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.name = tmpString;
    } else {
        std::string errorMessage = "No parameter name has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // Parameter name
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.name = tmpString;
    } else {
        std::string errorMessage = "No parameter name has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // lengthBits
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        if(tmpInt < 0) {
            std::string errorMessage = "Length in bits cannot be negative";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
        outParameter.lengthBits = tmpInt;
    } else {
        outParameter.lengthBits = 0;
    }
    i++;

    // littleEndian
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        if(tmpInt != 0 && tmpInt != 1) {
            std::string errorMessage = "Little Endian flag has an incorrect value";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
        outParameter.littleEndian = tmpInt;
    } else {
        outParameter.littleEndian = false;
    }
    i++;

    // Prepend size
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true)
        outParameter.prependSize = tmpInt;
    else
        outParameter.prependSize = 0;
    i++;

    // string terminator
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.stringTerminator = tmpString;
    } else {
        outParameter.stringTerminator = "";
    }
    i++;

    // valueType - raw type
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();

        if(tmpString == "uint") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_UNSIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_UINT32;
        }
        if(tmpString == "uint64") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_UNSIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_UINT64;
        }
        if(tmpString == "int") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_SIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_INT32;
        }
        if(tmpString == "int64") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_SIGNED_INTEGER;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_INT64;
        }
        if(tmpString == "float") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_DOUBLE;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
        if(tmpString == "boolean") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_BOOLEAN;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
        if(tmpString == "string") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_STRING;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
        if(tmpString == "binary") {
            outParameter.valueType = IW::TmTypeEnum::TM_TYPE_BIT_STRING;
            outParameter.valueSubType = IW::TmSubTypeEnum::TM_SUBTYPE_NONE;
        }
    } else {
        std::string errorMessage = "No Raw type has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // engType - eng type
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();

        if(tmpString == "uint" || tmpString == "uint32") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_UNSIGNED_INTEGER;
        }

        if(tmpString == "uint64") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_UNSIGNED_INTEGER64;
        }

        if(tmpString == "int" || tmpString == "int32") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_SIGNED_INTEGER;
        }

        if(tmpString == "int64") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_SIGNED_INTEGER64;
        }

        if(tmpString == "enumerated") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_ENUMERATED;

            // NOTE: It has to have an Calibration function associated to it
            if(outParameter.calibrationFunction.empty() == true) {
                std::string errorMessage = "Eng type Enumerated has to have a Calibration function associated to it";
                LogManager::getInstance().error(errorMessage);
                throw GSException(errorMessage);
            }
        }

        if(tmpString == "double") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_DOUBLE;
        }
        if(tmpString == "float") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_FLOAT;
        }

        if(tmpString == "boolean") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_BOOLEAN;
        }

        if(tmpString == "string") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_STRING;
        }

        if(tmpString == "binary") {
            outParameter.engType = IW::TmEngTypeEnum::TM_ENGTYPE_BINARY;
        }
    } else {
        std::string errorMessage = "No Engineering type has been specified";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // units
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.units = tmpString;
    }
    i++;

    // Calibration function
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.calibrationFunction = tmpString;
    } else {
        outParameter.calibrationFunction = "";
    }
    i++;

    // description
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.description = tmpString;
    }
    i++;

    // Do some checkings
    if(outParameter.valueType == IW::TmTypeEnum::TM_TYPE_UNSIGNED_INTEGER ||
        outParameter.valueType == IW::TmTypeEnum::TM_TYPE_SIGNED_INTEGER ||
        outParameter.valueType == IW::TmTypeEnum::TM_TYPE_DOUBLE ||
        outParameter.valueType == IW::TmTypeEnum::TM_TYPE_BIT_STRING) {
        if(outParameter.lengthBits <= 0) {
            std::string errorMessage = "Raw type of numeric type has to have specify a length in bits";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
    }
}

void extractAlgorithm(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::Algorithm& outAlgorithm)
{
    int32_t tmpInt;
    int32_t tmpInt1;
    string tmpString;
    int i = 0;

    // Algorithm name
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outAlgorithm.algorithmName = tmpString;
    }
    i++;

    // Algorithm language
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        if(tmpString == "Javascript") {
            outAlgorithm.algorithmLanguage = IW::AlgorithmLanguageEnum::ALGORITHM_JAVASCRIPT;
        }
        if(tmpString == "Python") {
            outAlgorithm.algorithmLanguage = IW::AlgorithmLanguageEnum::ALGORITHM_PYTHON;
        }
        if(tmpString == "Java") {
            outAlgorithm.algorithmLanguage = IW::AlgorithmLanguageEnum::ALGORITHM_JAVA;
        }
    }
    i++;

    // Source code
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outAlgorithm.sourceCode = tmpString;
    }
    i++;

    // Trigger
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();

        if(tmpString == "OnParameterUpdate") {
            outAlgorithm.trigger = IW::TriggerEnum::ALGORITHM_ON_PARAMETER_UPDATE;
        }

        if(tmpString == "OnInputParameterUpdate") {
            outAlgorithm.trigger = IW::TriggerEnum::ALGORITHM_ON_INPUT_PARAMETER_UPDATE;
        }

        if(tmpString == "OnPeriodicRate") {
            outAlgorithm.trigger = IW::TriggerEnum::ALGORITHM_ON_PERIODIC_RATE;
        }

        if(tmpString == "None") {
            outAlgorithm.trigger = IW::TriggerEnum::ALGORITHM_TRIGGER_NONE;
        }
    }
    i++;

    // In/out Flag

    // Parameter name

    // Instance

    // Name used in the Algorithm

    // Flags

    // Subsystem
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outAlgorithm.subsystem = tmpString;
    }
    i++;
}

void extractAlarm(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab, uint inRowIndex, IW::Alarm& outAlarm)
{
    int32_t tmpInt;
    int32_t tmpInt1;
    string tmpString;
    int i = 0;

    // Algorithm name
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outAlarm.parameterName = tmpString;
    }
}

void extractContainerHeader(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab,
    uint inRowIndex,
    IW::TM_Frame& outContainer,
    string& outParentContainer)
{
    int32_t tmpInt;
    // int32_t           tmpInt1;
    string tmpString;
    int i = 0;

    // Containter name
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outContainer.name = tmpString;
    } else {
        std::string errorMessage = "Container name cannot be null";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // Read type
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
    } else {
        std::string errorMessage = "Container row type cannot be null";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }

    if(tmpString != "header") {
        std::string errorMessage = "Invalid Container row type value: " + tmpString;
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // Parent
    outParentContainer = "";
    
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        outParentContainer = inTab->Cell(inRowIndex, i)->GetString();
    }
    i++;

    // Conditions
    string tmpConditions{ "" };

    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpConditions = inTab->Cell(inRowIndex, i)->GetString();

        extractConditions(outContainer, tmpConditions);
    }
    i++;

    // Time interval
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        if(tmpInt < 0) {
            std::string errorMessage = "Expected Interval cannot be negative";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
        outContainer.expectedInterval = tmpInt;
    } else {
        outContainer.expectedInterval = 0;
    }
    i++;

    // Length in bits
    if(inTab->Cell(inRowIndex, i)->Get(tmpInt) == true) {
        if(tmpInt < 0) {
            std::string errorMessage = "Length in bits cannot be negative";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }
        outContainer.lengthBits = tmpInt;
    } else {
        outContainer.lengthBits = 0;
    }
    i++;

    // Description
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outContainer.description = tmpString;
    }
    i++;

    // Flags
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();

        if(tmpString == "a" || tmpString == "A") {
            outContainer.flag = IW::TmFrameFlagEnum::TM_FRAME_ARCHIVE;
        }
        if(tmpString == "l" || tmpString == "L") {
            outContainer.flag = IW::TmFrameFlagEnum::TM_FRAME_LITTLE_ENDIAN;
        }
    }
}

void extractConditions(IW::TM_Frame& inContainer, const string& inConditionsText)
{
    string tmpCondition{inConditionsText};
    
    // Look for next condition
    string::size_type i = tmpCondition.find(';');
        
    while (i != string::npos) {
        // Extract current condition
        string tmpBuffer = tmpCondition.substr(0, i);
        
        // Extract the rest of the input text
        tmpCondition = tmpCondition.substr(i + 1);
            
        string::size_type j = tmpBuffer.find('=');
        
        if (j != string::npos) {
            IW::TM_FrameCondition newCondition;
            
            // Extract parameter
            string parameterName = tmpBuffer.substr(0, j);
            
            // Extract value
            string parameterValue = tmpBuffer.substr(i+1);
            
            newCondition.frameName      = inContainer.name;
            newCondition.parameterName  = parameterName;
            newCondition.parameterValue = parameterValue;

            // Add the condition to the Container
            inContainer.frameConditions.push_back(newCondition);            
        }            

        // Look for next condition
        i = tmpCondition.find(";");
    }
}

void extractContainerParameter(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab,
    uint inRowIndex,
    IW::TM_FrameField& outParameter)
{
    int32_t tmpInt;
    // int32_t    tmpInt1;
    string tmpString;
    int i = 0;

    // Containter name
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
        outParameter.frameName = tmpString;
    } else {
        std::string errorMessage = "Container name cannot be null";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // Read type
    if(inTab->Cell(inRowIndex, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(inRowIndex, i)->GetString();
    } else {
        std::string errorMessage = "Container row type cannot be null";
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }

    if(tmpString != "parameter") {
        std::string errorMessage = "Invalid Container row type value: " + tmpString;
        LogManager::getInstance().error(errorMessage);
        throw GSException(errorMessage);
    }
    i++;

    // Parameter Name
    if(inTab->Cell(inRowIndex, 7)->GetString() != nullptr) {
        outParameter.parameterName = inTab->Cell(i, 7)->GetString();
    }

    // Relative position
    if(inTab->Cell(inRowIndex, 8)->Get(tmpInt) == true) {
        if(tmpInt < 0) {
            LogManager::getInstance().warning("Relative position of parameter: " + outParameter.parameterName + " is negative. Set to 0");
            outParameter.relativePosition = 0;
        } else {
            outParameter.relativePosition = tmpInt;
        }
    }

    // Dummy sequence number
    outParameter.sequenceNumber = 0;
}

void extractCalibration(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab,
    uint inRowIndex,
    IW::Calibration& outCalibration)
{
    int32_t tmpInt;
    int32_t tmpInt1;
    string tmpString;
    int i = 0;
    int32_t currentRow = inRowIndex;

    // Calibration name
    if(inTab->Cell(currentRow, i)->GetString() != nullptr) {
        tmpString = inTab->Cell(currentRow, i)->GetString();
        outCalibration.name = tmpString;
    }
    i++;

    while(true) {
        IW::CalibrationItem newItem;

        // Type
        if(inTab->Cell(currentRow, i)->GetString() != nullptr) {
            tmpString = inTab->Cell(currentRow, i)->GetString();

            if(tmpString == "polynomial" || tmpString == "POLYNOMIAL")
                outCalibration.calibrationType = IW::TmCalibrationTypeEnum::TM_CALIBRATION_POLYNOMIAL;

            if(tmpString == "spline" || tmpString == "SPLINE")
                outCalibration.calibrationType = IW::TmCalibrationTypeEnum::TM_CALIBRATION_SPLINE;

            if(tmpString == "expression" || tmpString == "EXPRESSION")
                outCalibration.calibrationType = IW::TmCalibrationTypeEnum::TM_CALIBRATION_EXPRESSION;

            if(tmpString == "enumeration" || tmpString == "ENUMERATION")
                outCalibration.calibrationType = IW::TmCalibrationTypeEnum::TM_CALIBRATION_ENUMERATION;
        }
        i++;

        // Calibration value 1
        if(inTab->Cell(currentRow, i)->GetString() != nullptr) {
            tmpString = inTab->Cell(currentRow, i)->GetString();
            newItem.calibration1 = tmpString;
        } else {
            newItem.calibration1 = "";
        }
        i++;

        // Calibraiton value 2
        if(inTab->Cell(currentRow, i)->GetString() != nullptr) {
            tmpString = inTab->Cell(currentRow, i)->GetString();
            newItem.calibration2 = tmpString;
        } else {
            newItem.calibration2 = "";
        }
        i++;

//        // Subsystem
//        if(inTab->Cell(currentRow, i)->GetString() != nullptr) {
//            tmpString = inTab->Cell(currentRow, i)->GetString();
//            newItem.subsystem = tmpString;
//        }
//        i++;

        // Next row
        currentRow++;
        if(currentRow >= inTab->GetTotalRows()) {
            break;
        }

        // Calibration name
        i = 0;
        if(inTab->Cell(currentRow, i)->GetString() != nullptr) {
            tmpString = inTab->Cell(currentRow, i)->GetString();
        }
        i++;

        if(tmpString != outCalibration.name) {
            break;
        }
    }
}

//=======================================================================================================
//=======================================================================================================

void processTmParameters(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab)
{
    // Skip header
    for(int i = 1; i < inTab->GetTotalRows(); i++) {
        // Skip comment lines
        string tmpString;

        if(inTab->Cell(i, 0)->GetString() != nullptr) {
            tmpString = inTab->Cell(i, 0)->GetString();

            if(tmpString[0] == '#') {
                continue;
            }
        }

        // First row is the header row
        IW::TM_Parameter newParameter;

        extractTmParameter(inTab, i, newParameter);

        // Add to the map
        parametersList[newParameter.name] = newParameter;

        // Save the new parameter in the DB
        try {
            ToolsDatabase::getInstance().createTmParameter(newParameter);
        } catch(GSException& gsExc) {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        }

        LogManager::getInstance().info("Parameter: " + newParameter.name + " correctly created");
    }
}

void processTmDerivedParameters(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab)
{
    // Skip header
    for(int i = 1; i < inTab->GetTotalRows(); i++) {
        // Skip comment lines
        string tmpString;

        if(inTab->Cell(i, 0)->GetString() != nullptr) {
            tmpString = inTab->Cell(i, 0)->GetString();

            if(tmpString[0] == '#') {
                //    firstLine ++;
                continue;
            }
        }

        IW::Derived_TM_Parameter newParameter;

        extractTmDerivedParameter(inTab, i, newParameter);

        // Add to the map
        derivedParametersList[newParameter.name] = newParameter;

        // Save the new parameter in the DB
        try {
            ToolsDatabase::getInstance().createTmDerivedParameter(newParameter);
        } catch(GSException& gsExc) {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        }

        LogManager::getInstance().info("Parameter: " + newParameter.name + " correctly created");
    }
}

void processCalibrations(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab)
{
    // Skip header
    for(int i = 1; i < inTab->GetTotalRows(); i++) {
        // Skip comment lines
        string tmpString;

        if(inTab->Cell(i, 0)->GetString() != nullptr) {
            tmpString = inTab->Cell(i, 0)->GetString();

            if(tmpString[0] == '#') {
                //    firstLine ++;
                continue;
            }
        }

        IW::Calibration newCalibration;

        extractCalibration(inTab, i, newCalibration);

        // Add to the map
        calibrationList[newCalibration.name] = newCalibration;

        // Save the new parameter in the DB
        try {
            ToolsDatabase::getInstance().createCalibration(newCalibration);
        } catch(GSException& gsExc) {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        }

        LogManager::getInstance().info("Calibration function: " + newCalibration.name + " correctly created");
    }
}

void processAlgorithms(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab)
{
    // int firstLine = 0;

    // Skip header
    for(int i = 1; i < inTab->GetTotalRows(); i++) {
        // Skip comment lines
        string tmpString;

        if(inTab->Cell(i, 0)->GetString() != nullptr) {
            tmpString = inTab->Cell(i, 0)->GetString();

            if(tmpString[0] == '#') {
                //    firstLine ++;
                continue;
            }
        }

        // First row is the header row
        // if (i > firstLine) {
        IW::Algorithm newAlgorithm;

        extractAlgorithm(inTab, i, newAlgorithm);

        // Save the new parameter in the DB
        try {
            ToolsDatabase::getInstance().createAlgorithm(newAlgorithm);
        } catch(GSException& gsExc) {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        }

        LogManager::getInstance().info("Algorithm: " + newAlgorithm.algorithmName + " correctly created");
        //}
    }
}

void processAlarms(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab)
{
    // int firstLine = 0;

    // Skip header
    for(int i = 1; i < inTab->GetTotalRows(); i++) {
        // Skip comment lines
        string tmpString;

        if(inTab->Cell(i, 0)->GetString() != nullptr) {
            tmpString = inTab->Cell(i, 0)->GetString();

            if(tmpString[0] == '#') {
                //    firstLine ++;
                continue;
            }
        }

        // First row is the header row
        IW::Alarm newAlarm;

        extractAlarm(inTab, i, newAlarm);

        // Save the new parameter in the DB
        try {
            ToolsDatabase::getInstance().createAlarm(newAlarm);
        } catch(GSException& gsExc) {
            LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
        }

        LogManager::getInstance().info("Alarm: " + newAlarm.parameterName + " correctly created");
    }
}

void processContainers(shared_ptr<ExcelFormat::BasicExcelWorksheet>& inTab)
{
    //std::map<string, SequenceContainer> containers;
    //std::map<string, string> parents;

    string tmpString{ "" };
    int32_t tmpInt;

    // Skip the header row
    int currentRow = 1;

    while(currentRow < inTab->GetTotalRows()) {

        // Skip comment lines
        if(inTab->Cell(currentRow, 0)->GetString() != nullptr) {
            tmpString = inTab->Cell(currentRow, 0)->GetString();

            if(tmpString.empty() == true || tmpString[0] == '#') {
                currentRow++;
                continue;
            }
        } else {
            currentRow++;
            continue;
        }

        IW::TM_Frame newContainer;
        vector<IW::TM_FrameField> frameParameters;

        // Read first container
        string currentContainer{ "" };

        // Read first containter name
        if(inTab->Cell(currentRow, 0)->GetString() != nullptr) {
            currentContainer = inTab->Cell(currentRow, 0)->GetString();
        } else {
            std::string errorMessage = "Container name cannot be null";
            LogManager::getInstance().error(errorMessage);
            throw GSException(errorMessage);
        }

        // we mark the start of the command and advance to the next line, to get to the first argument (if there is one)
        // int start = currentRow ++;

        // now, we start processing the parameters (or references to aggregate containers)
        bool end = false;

        // sequence number of the SequenceEntrys in the SequenceContainer
        int counter = 0;

        while(end == false && currentRow < inTab->GetTotalRows()) {
            // Get row type
            if(inTab->Cell(currentRow, 1)->GetString() != nullptr) {
                tmpString = inTab->Cell(currentRow, 1)->GetString();
            } else {
                std::string errorMessage = "Container row type cannot be null";
                LogManager::getInstance().error(errorMessage);
                throw GSException(errorMessage);
            }
            
            string parentContainer{""};
            
            if(tmpString == "header") {
                // Read header
                extractContainerHeader(inTab, currentRow, newContainer, parentContainer);
            } else if(tmpString == "parameter") {
                // Read parameter
                IW::TM_FrameField tmpNewParameter;

                extractContainerParameter(inTab, currentRow, tmpNewParameter);

                frameParameters.push_back(tmpNewParameter);
            } else {
                std::string errorMessage = "Invalid Container row type: " + tmpString;
                LogManager::getInstance().error(errorMessage);
                throw GSException(errorMessage);
            }

            // we add the relative position to the absoluteOffset, to specify the location of the new parameter.
            // We only do this if the absoluteOffset is not equal to -1,
            //  because that would mean that we cannot and should not use absolute positions anymore
//            if(absoluteOffset != -1) {
//                absoluteOffset += relativePosition;
//            }

            // the repeat string will contain the number of times a measurement (or aggregate container) should be
            // repeated. It is a String because at this point it can be either a number or a reference to another
            // measurement
            string repeat{ "" };

            // Absolute offset of the first parameter of the container
            int absoluteOffset = -1;

            if(parentContainer.empty() == true) {
                absoluteOffset = 0;
            } else {
                std::size_t found = parentContainer.find(":");

                if(found != std::string::npos) {
                    string tmpOffset = parentContainer.substr(found + 1);
                    absoluteOffset = std::atoi(tmpOffset.c_str());
                    parentContainer = parentContainer.substr(0, found);
                }
            }

            /*
                        AQUI
                            // we check whether the measurement (or aggregate container) has a '*' inside it, meaning
               that it is a
                            // repeat measurement/aggregate
                            Matcher m = Pattern.compile("(.*)[*](.*)").matcher(paraname);
                        if (m.matches())
                        {
                            repeat = m.group(1);
                            paraname = m.group(2);
                        }

                        // check whether this measurement/aggregate actually has an entry in the parameters table
                        // first we check if it is a measurement by trying to retrieve it from the parameters map. If
               this succeeds
                        // we add it as a new parameterentry,
                        // otherwise, we search for it in the containersmap, as it is probably an aggregate. If it is
               not, we
                        // encountered an error
                        // note that one of the next 2 lines will return null, but this does not pose a problem, it
               makes
                        // programming easier along the way
                        Parameter param = parameters.get(paraname);
                        SequenceContainer sc = containers.get(paraname);
                        // if the sequenceentry is repeated a fixed number of times, this number is recorded in the
               'repeated'
                        // variable and used to calculate the next absoluteoffset (done below)
                        int repeated = -1;

                        if (param != null)
                        {
                            SequenceEntry se;
                            if (flags.contains("L") || flags.contains("l"))
                            {
                                if (param.parameterType instanceof IntegerParameterType)
                                {
                                    ((IntegerParameterType)param.parameterType).encoding.byteOrder =
               ByteOrder.LITTLE_ENDIAN;
                                }
                                else if (param.parameterType instanceof FloatParameterType)
                                {
                                    ((FloatParameterType)param.parameterType).encoding.byteOrder =
               ByteOrder.LITTLE_ENDIAN;
                                }
                                else if (param.parameterType instanceof EnumeratedParameterType)
                                {
                                    ((EnumeratedParameterType)param.parameterType).encoding.byteOrder =
               ByteOrder.LITTLE_ENDIAN;
                                }
                                else
                                {
                                    throw new SpreadsheetLoadException(ctx, "Little endian not supported for parameter "
               + param);
                                }
                            }

                            // if absoluteoffset is -1, somewhere along the line we came across a measurement or
               aggregate that had
                            // as a result that the absoluteoffset could not be determined anymore; hence, a relative
               position is
                            // added
                            if (absoluteoffset == -1)
                            {
                                se = new ParameterEntry(counter, container, relpos, ReferenceLocationType.previousEntry,
               param);
                            }
                            else
                            {
                                se = new ParameterEntry(
                                    counter, container, absoluteoffset, ReferenceLocationType.containerStart, param);
                            }
                            // also check if the parameter should be added multiple times, and if so, do so
                            repeated = addRepeat(se, repeat);
                            container.entryList.add(se);
                        }
                        else
                        {
                            if (sc != null)
                            {
                                // ok, we found it as an aggregate, so we add it to the entryList of container, as a new
                                // ContainerEntry
                                // if absoluteoffset is -1, somewhere along the line we came across a measurement or
               aggregate that
                                // had as a result that the absoluteoffset could not be determined anymore; hence, a
               relative
                                // position is added
                                SequenceEntry se;
                                if (absoluteoffset == -1)
                                {
                                    se = new ContainerEntry(counter, container, relpos,
               ReferenceLocationType.previousEntry, sc);
                                }
                                else
                                {
                                    se = new ContainerEntry(
                                        counter, container, absoluteoffset, ReferenceLocationType.containerStart, sc);
                                }
                                // also check if the parameter should be added multiple times, and if so, do so
                                repeated = addRepeat(se, repeat);
                                container.entryList.add(se);
                            }
                            else
                            {
                                throw new SpreadsheetLoadException(ctx, "The measurement/container '" + paraname +
                                                                            "' was not found in the parameters or
               containers map");
                            }
                        }

                        // after adding this measurement, we need to update the absoluteoffset for the next one. For
               this, we add
                        // the size of the current SequenceEntry to the absoluteoffset
                        int size = getSize(param, sc);
                        if ((repeated != -1) && (size != -1) && (absoluteoffset != -1))
                        {
                            absoluteoffset += repeated * size;
                        }
                        else
                        {
                            // from this moment on, absoluteoffset is set to -1, meaning that all subsequent
               SequenceEntries must be
                            // relative
                            absoluteoffset = -1;
                        }

                        // increment the counters;
                        i++;
                        counter++;
                    }

                    // at this point, we have added all the parameters and aggregate containers to the current packets.
               What remains
                    // to be done is link it with its base
                    if (parent != null)
                    {
                        parents.put(name, parent);
                        // the condition is parsed and used to create the container.restrictionCriteria
                        // 1) get the parent, from the same sheet
                        SequenceContainer sc = containers.get(parent);
                        // the parent is not in the same sheet, try to get from the Xtcedb
                        if (sc == null)
                        {
                            sc = spaceSystem.getSequenceContainer(parent);
                        }
                        if (sc != null)
                        {
                            container.setBaseContainer(sc);
                            if (("5.2".compareTo(fileFormatVersion) > 0) && (!parents.containsKey(parent)))
                            {
                                // prior to version 5.2 of the format, the second level of containers were used as
               archive
                                // partitions
                                // TODO: remove when switching to 6.x format
                                container.useAsArchivePartition(true);
                            }
                        }
                        else
                        {
                            final SequenceContainer c = container;
                            NameReference nr = new NameReference(parent, Type.SEQUENCE_CONTAINTER, new ResolvedAction()
               {
                                @Override public boolean resolved(NameDescription nd)
                                {
                                    SequenceContainer sc = (SequenceContainer)nd;
                                    c.setBaseContainer(sc);
                                    if ("5.2".compareTo(fileFormatVersion) > 0)
                                    {
                                        if (sc.getBaseContainer() == null)
                                        {
                                            c.useAsArchivePartition(true);
                                        }
                                    }

                                    return true;
                                }
                            });
                            spaceSystem.addUnresolvedReference(nr);
                        }

                        // 2) extract the condition and create the restrictioncriteria
                        if (!"".equals(condition.trim()))
                        {
                            container.restrictionCriteria = toMatchCriteria(condition);
                            MatchCriteria.printParsedMatchCriteria(log, container.restrictionCriteria, "");
                        }
                    }
                    else
                    {
                        if (spaceSystem.getRootSequenceContainer() == null)
                        {
                            spaceSystem.setRootSequenceContainer(container);
                        }
                    }

                    HASTA AQUI
                    */

            // Save new container
            try {
                ToolsDatabase::getInstance().createTmFrame(newContainer);
            } catch(GSException& gsExc) {
                LogManager::getInstance().error("Exception: " + gsExc.getErrorMessage());
            }
        }

        LogManager::getInstance().info("Container: " + newContainer.name + " correctly created");
    }
}

// ======================================================================================
// ======================================================================================

void processExcel(const string& inFileName)
{
    ExcelFormat::BasicExcel xls;

    //xls.setEncoding("Cp1252");

    // Open the Excel
    if(xls.Load(inFileName.c_str()) == true) {

        // Tab: Parameters
        // --------------------
        shared_ptr<ExcelFormat::BasicExcelWorksheet> parametersTab(xls.GetWorksheet("Parameters"));

        if(parametersTab.get() != nullptr) {
            processTmParameters(parametersTab);
        } else {
            string errorMessage = "Telemetry tab 'Parameters' not found in Excel file: " + inFileName;
            LogManager::getInstance().error(errorMessage);
        }

        // Tab: Derived Parameters
        // --------------------------
        shared_ptr<ExcelFormat::BasicExcelWorksheet> derivedParametersTab(xls.GetWorksheet("DerivedParameters"));

        if(derivedParametersTab.get() != nullptr) {
            processTmDerivedParameters(derivedParametersTab);
        } else {
            string errorMessage = "Telemetry tab 'DerivedParameters' not found in Excel file: " + inFileName;
            LogManager::getInstance().error(errorMessage);
        }

        // Tab: Calibration
        // --------------------------
        shared_ptr<ExcelFormat::BasicExcelWorksheet> calibrationTab(xls.GetWorksheet("Calibration"));

        if(calibrationTab.get() != nullptr) {
            processCalibrations(calibrationTab);
        } else {
            string errorMessage = "Telemetry tab 'Calibration' not found in Excel file: " + inFileName;
            LogManager::getInstance().error(errorMessage);
        }

        // Tab: Algorithms
        // --------------------------
        shared_ptr<ExcelFormat::BasicExcelWorksheet> algorithmTab(xls.GetWorksheet("Algorithms"));

        if(algorithmTab.get() != nullptr) {
            processAlgorithms(algorithmTab);
        } else {
            string errorMessage = "Telemetry tab 'Algorithms' not found in Excel file: " + inFileName;
            LogManager::getInstance().error(errorMessage);
        }

        // Tab: Alarms
        // --------------------------
        shared_ptr<ExcelFormat::BasicExcelWorksheet> alarmTab(xls.GetWorksheet("Alarms"));

        if(alarmTab.get() != nullptr) {
            processAlarms(alarmTab);
        } else {
            string errorMessage = "Telemetry tab 'Alarms' not found in Excel file: " + inFileName;
            LogManager::getInstance().error(errorMessage);
        }

        // Tab: Containers
        // --------------------------
        shared_ptr<ExcelFormat::BasicExcelWorksheet> containerTab(xls.GetWorksheet("Containers"));

        if(containerTab.get() != nullptr) {
            processContainers(containerTab);
        } else {
            string errorMessage = "Telemetry tab 'Containers' not found in Excel file: " + inFileName;
            LogManager::getInstance().error(errorMessage);
        }

        // Telecommands section

        xls.Close();
    } else {
        string errorMessage = "Unable to open Excel file: " + inFileName;
        LogManager::getInstance().error(errorMessage);
    }
}

void processCsv(const string& inFileName, const string& inDatabaseName)
{
}

void processXtce(const string& inFileName, const string& inDatabaseName)
{
}

/**
 * @brief Import a S/C Database. It is composed of
 * Satellite, Subsystem, Node, TM, TC, Frame, Layer
 *
 * @param argc
 * @param argv - Name of input file, file type (CSV, Excel, XTCE), SQLite database
 * @return
 */
int main(int argc, char** argv)
{
    if(argc < 3) {
        cout << "ERROR: Invalid number of arguments" << endl;
        cout << "Usage: " << endl;
        cout << "       Import_Database    input_file_name    file_type" << endl;
        cout << "Where: " << endl;
        cout << "   input_file_name - File name and path of the file containing the database" << endl;
        cout << "   file_type - Type of input file; excel, csv, xtce" << endl;
        cout << endl;
    } else {
        string dataFileName = argv[1];
        string fileType = argv[2];

        cout << "Debug: data file: " << dataFileName << endl;
        cout << "       file type: " << fileType << endl;

        // Read the Tools configuration from a JSON config file
        // Throws and exception if an error is found
        ConfigurationManager::getInstance().load("resources/config.json");

        // Initialize the Log Manager
        LogManager& logMng = LogManager::getInstance();

        logMng.init(ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_GEN_LOG_FILE));

        logMng.info("Configuration correctly loaded");

        ToolsDatabase::getInstance().open();

        if(fileType == "excel") {
            processExcel(dataFileName);
        }
    }

    return 0;
}
