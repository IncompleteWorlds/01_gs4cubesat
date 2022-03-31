/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __COMMON_TYPES_H__
#define __COMMON_TYPES_H__

#include <vector>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

#include "AvroTypes.h"

#include "RadixEnum.h"
#include "FieldTypeEnum.h"
#include "TmTypeEnum.h"
#include "MagnitudeTypeEnum.h"



// Forward declaration
class IMessageProcessor;

using VectorUint8 = vector<uint8_t>;

using MessageProcessorSharedPtr = std::shared_ptr<IMessageProcessor>;

using RawFrameType = vector<uint8_t>;



// -- Constants ---------------------
static const ushort CRC_INITIAL_VALUE = 0xFFFF;

// Default Frame size received from a ground station
static const size_t DEFAULT_FRAME_SIZE = 4096;

static const string EVENT_PREFIX = "EVT:";


/*
struct Limit
{
    double    minValue_;
    double    maxValue_;

    bool isInside(const double inValue)
    {
        bool output = true;

        if (inValue < minValue_ || inValue > maxValue_)
            output = false;

        return output;
    }
};

struct CalibrationCoefficient
{
    uint32_t         id_;

    uint16_t         numberCoefficients_;
    vector<double>   listCoefficients_;

};


// This structure will define a TM point in the database
struct TC_ParameterType
{
    uint32_t          id_;
    uint32_t          parentId_;     // Where it is included. Parent identifier

    string            name_;
    string            displayName_;    // Name on a screen / display
    string            description_;

    uint16_t          node_;         
    uint16_t          channel_;

    uint32_t          lengthBits_;      // Length of field in bits
    bool              littleEndian_;   // Little Endian - true, Big Endian - false

    FieldTypeEnum     type_;    // None, String, Integer, Double, Bool, Date, Time, Date/Time
    FieldSubTypeEnum  subtype_;  // Int8, Int16, ...
};



// This structure will define a TM point in the database
struct TM_ParameterType
{
    uint32_t          id_;
    uint32_t          parentId_;     // Where it is included. Parent identifier

    uint16_t          node_;         
    uint16_t          channel_;
    TmTypeEnum        tmType_;     // Values; 0 - None, 1 - Current, 2 - Voltage, 3 - Power, 4 - Temperature
    MagnitudeTypeEnum magnitudeType_;   //  0 - None, 1 - Analogue, 2 - Digital

    string            name_;
    string            displayName_;    // Name on a screen / display
    string            description_;
    uint32_t          lengthBits_;      // Length of field in bits

    bool              littleEndian_;   // Little Endian - true, Big Endian - false

    string            defaultValue_;   // TBC

    string            units_;
    RadixEnum         radix_;   // None, Decimal, Hexadecimal
    FieldTypeEnum     type_;    // None, String, Integer, Double, Bool, Date, Time, Date/Time
    FieldSubTypeEnum  subtype_;  // Int8, Int16, ...

    bool              rawFlag_;    // Raw or engineering value. Raw - true, Engineering - false
    uint32_t          calibrationCoeffId_;  // Function

    bool              crcFlag_;
    string            crcAlgorithm_;   // Name of the CRC algorithm

    // Check OOL
    Limit             warninglimits_;
    Limit             errorLimits_;
};




// This structure will define a field of a frame; TC or TM
struct IntFieldType 
{
    uint32_t frameId_;
    uint32_t fieldId_;
    uint16_t sequenceNumber_; // Index of the field inside of the sequence that
                              // that composes the frame

    // DO NOT REMOVE
    // Not in Avro counterpart
    
};

// This structure defines a frame; either a telecommand or a telemetry point
struct IntFrameType 
{
    uint32_t     id_;
    uint32_t     parent_;     // It is contained in another frame, as a subframe
    uint32_t     layerId_;    // Layer this frame belongs to

    string       name_;
    string       description_;

    bool         hktmFlag_;

    uint32_t     lengthBytes_;   // Length of frame in bytes. Padding to the right

    // Frame is delimited by delimiters. These fields identify the field types of the identifiers
    uint32_t     startDelimiterId_;
    uint32_t     endDelimiterId_;

    uint32_t     identificationField_;  // Identifier of the field which value defines the type of the
                                        // frame
    string       identificationValue_;  // Value for discriminating the Frame. I.e. field 3 shall be 0x11

    vector<IntFieldType>  fields;    // List of field types that composes this frame
};


struct IntListFrameTypes {
    std::vector<IntFrameType > listFrameTypes;

    IntListFrameTypes() :
        IW::ListFrameTypes(), listFrameTypes(std::vector<IntFrameType >())
        { }

    // DO NOT REMOVE
    // Not in Avro counterpart
    
};


// Copy of the Avro structure
// Both structures shall be aligned
struct IntProcessedField {
    int32_t index_;
    int32_t fieldTypeId_;
    string fieldName_;
    string value_;

    IntProcessedField() :
        index_(int32_t()),
        fieldTypeId_(int32_t()),
        fieldName_(std::string()),
        value_(std::string())
        { }

    IntProcessedField():
        IW::ProcessedField() {}

    IntProcessedField(int32_t inIndex, int32_t inFieldTypeId, string inName) 
        index(inIndex),
        fieldTypeId(inFieldTypeId),
        fieldName(inName),
        value_(std::string())
    { }

    IntProcessedField(int32_t inIndex, int32_t inFieldTypeId, string inName, string inValue) 
        index(inIndex),
        fieldTypeId(inFieldTypeId),
        fieldName(inName),
        value(inValue)
        { }
    
    // DO NOT REMOVE
    // Not in Avro counterpart
    
};


struct IntGroupProcessedField {
//    // It can be a group or a layer
    int32_t id_;
    std::vector<IntProcessedField > fields;
    bool oolFlag_;
    std::vector<int32_t > oolFields;
   
    IntGroupProcessedField() :
        IW::GroupProcessedField(), fields{}
        id_(int32_t()),
        fields_(std::vector<IntProcessedField >()),
        oolFlag_(bool()),
        oolFields_(std::vector<int32_t >())
    {}

    // DO NOT REMOVE
    // Not in Avro counterpart
    
};

struct IntProcessedFrame {
    int32_t id_;
    int32_t frameTypeId_;
    int64_t creationTime_;
    std::vector<IntGroupProcessedField > groups;
    
    IntProcessedFrame() :
        IW::ProcessedFrame(), groups{}
        id_(int32_t()),
        frameTypeId_(int32_t()),
        creationTime_(int64_t()),
        groups_(std::vector<IntGroupProcessedField >())
    { }

    // DO NOT REMOVE
    // Not in Avro counterpart
 };



// Copy of Avro structure.
// They shall be equal

struct IntParameter {
    std::string identifier_;
    std::string name_;
    std::string description_;
    int32_t type_;
    std::string value_;
    int32_t radix_;
   
    IntParameter() : 
        IW::Parameter()
        identifier_(std::string()),
        name_(std::string()),
        description_(std::string()),
        type_(int32_t()),
        value_(std::string()),
        radix_(int32_t())
        { }

    // DO NOT REMOVE
    // Not in Avro counterpart
    
};

struct IntListParameters  {
    std::vector<IntParameter > listParameters;

    IntListParameters() :
        IW::ListParameters(),
        listParameters_(std::vector<IntParameter >())
        { }

    // DO NOT REMOVE
    // Not in Avro counterpart
    
};
*/

// -- FUNCTION DEFINITIONS  ------------------------------
// -------------------------------------------------------

string vectorToString(VectorUint8& inVector);

string vectorToHexString(VectorUint8& inVector, bool inCompactFlag = true);

VectorUint8 stringToVector(string& inString);

template<typename T>
string toHexString(T inValue)
{
    stringstream ss;

    ss << hex << inValue;
    return ss.str();
}

string toString(IW::TM_FrameField& inField);
string toString(IW::TM_FrameCondition& inField);
string toString(IW::TM_Frame& inFrame);
string toString(IW::ListFrameTypes& inList);
string toString(IW::ProcessedField& inField);
string toString(IW::GroupProcessedField& inGroup);
string toString(IW::TM_ProcessedFrame& inFrame);
string toString(IW::ConfigurationParameter& inParameter);
string toString(IW::ListParameters& inList);

string toString(IW::MsgReturnData& inData);


const char PATH_SEPARATOR =
#if defined _WIN32 || defined __CYGWIN__
    '\\';
#else
    '/';
#endif


#endif // __COMMONTYPES_H__

