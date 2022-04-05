/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "CommonTypes.h"




string vectorToString(VectorUint8& inVector)
{
    string output;

    output.resize(inVector.size());

    for(uint i = 0; i < inVector.size(); i ++)
    {
        output[i] = inVector[i];
    }

    return output;
}

VectorUint8 stringToVector(string& inString)
{
    VectorUint8 output;

    output.resize(inString.size());
    for(uint i = 0; i < inString.size(); i ++)
    {
        output[i] = inString[i];
    }

    return output;
}


string vectorToHexString(VectorUint8& inVector, bool inCompactFlag)
{
    stringstream ss;

    ss << hex;
    ss << setw(2) << setfill('0');

    for(uint32_t i = 0; i < inVector.size(); i ++)
    {
        if (inCompactFlag == false)
        {
            ss << "0x";
        }

        ss << static_cast<uint>(inVector[i]);

        if (inCompactFlag == false)
        {
            ss << " ";
        }
    }    

    return ss.str();
}

string toString(IW::TM_FrameField& inField)
{
    stringstream ss;

    ss << "Frame Name: " << inField.frameName;
    ss << " Parameter Name: " << inField.parameterName;
    ss << " Seq. Number: " << inField.sequenceNumber;
    ss << " Rel. Position: " << inField.relativePosition;
    ss << endl;

    return ss.str();
}

string toString(IW::TM_Frame& inFrame)
{
    stringstream ss;

    ss << "Name: " << inFrame.name;
    ss << " Layer Id: " << inFrame.layerName;
    ss << " Description: " << inFrame.description;
    ss << " Type " << inFrame.flag << endl;
    ss << " Expected Interval: " << inFrame.expectedInterval << endl;
    ss << " Length: " << inFrame.lengthBits << endl;
    ss << endl;

    for(IW::TM_FrameCondition currentCondition : inFrame.frameConditions.get_array()) {
        ss << "   ";
        ss << toString(currentCondition);
    }

    for(IW::TM_FrameField currentField : inFrame.tmFields) {
        ss << "   ";
        ss << toString(currentField);
    }

    return ss.str();
}

string toString(IW::TM_FrameCondition& inField)
{
    stringstream ss;

    ss << "Frame Id: " << inField.frameName;
    ss << " Parameter Name: " << inField.parameterName;
    ss << " Parameter Value: " << inField.parameterValue;

    return ss.str();
}

string toString(IW::ListFrameTypes& inList)
{
    stringstream ss;

    for(IW::TM_Frame current : inList.listFrameTypes) {
        ss << "   ";
        ss << toString(current);
    }

    return ss.str();
}

string toString(IW::ProcessedField& inField)
{
    stringstream ss;

    ss << "Index: " << inField.index;
    ss << " Type: " << inField.fieldTypeId;
    ss << " Name: " << inField.fieldName;
    ss << " Value: " << inField.value;
    ss << endl;

    return ss.str();
}

string toString(IW::GroupProcessedField& inGroup)
{
    stringstream ss;

    ss << "Id: " << inGroup.id;
    ss << " Fields: " << endl;

    for(IW::ProcessedField current : inGroup.fields) {
        ss << "   ";
        ss << toString(current);
    }

    ss << " OOL: " << inGroup.oolFlag;
    ss << " OOL fields: " << endl;

    for(int32_t current : inGroup.oolFields.get_array()) {
        ss << "   ";
        ss << std::to_string(current);
    }

    return ss.str();
}

string toString(IW::ProcessedFrame& inFrame)
{
    stringstream ss;

    ss << "Id: " << inFrame.id;
    ss << " Type: " << inFrame.frameTypeId;
    ss << " Time: " << inFrame.creationTime;
    ss << " Groups: " << endl;

    for(IW::GroupProcessedField current : inFrame.groups.get_array()) {
        ss << "   ";
        ss << toString(current);
    }

    return ss.str();
}

string toString(IW::ConfigurationParameter& inParameter)
{
    stringstream ss;

    ss << "Identifier: " << inParameter.identifier;
    ss << " Name: " << inParameter.name;
    ss << " Value: " << inParameter.value;
    ss << " Description: " << inParameter.description;
    ss << " Type: " << inParameter.type;
    ss << endl;

    return ss.str();
}

string toString(IW::ListParameters& inList)
{
    stringstream ss;

    for(IW::ConfigurationParameter current : inList.listParameters) {
        ss << "   ";
        ss << toString(current);
    }

    return ss.str();
}
