/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <chrono>


using namespace std;

#include "TimeUtils.h"

const string TimeUtils::DATE_FORMAT_YYYYMMDDTHHmmSSZ  { "%Y-%m-%dT%H:%M:%SZ" };
const string TimeUtils::DATE_FORMAT_YYYYMMDDTHHmmSS  { "%Y-%m-%dT%H:%M:%S" };
const string TimeUtils::TIME_FORMAT_HHmmSS { "%H:%M:%S" };
const string TimeUtils::DATE_FORMAT_YYYYMMDD_HHmmSS { "%Y/%m/%d %H:%M:%S" };


TimeUtils::TimeUtils()
{
}

TimeUtils::~TimeUtils()
{
}

// Converts UTC time string to a time_t value.
time_t TimeUtils::getTimeFromString(const string &inFormat, const string& inDateTime)
{
   // Let's consider we are getting all the input in
   // this format: '2014-07-25T20:17:22Z' (T denotes
   // start of Time part, Z denotes UTC zone).
   // A better approach would be to pass in the format as well.
   //static const string dateTimeFormat { L"%Y-%m-%dT%H:%M:%SZ" };

   // Create a stream which we will use to parse the string,
   // which we provide to constructor of stream to fill the buffer.
   istringstream ss{ inDateTime };

   // Create a tm object to store the parsed date and time.
   std::tm dt;

   // Now we read from buffer using get_time manipulator
   // and formatting the input appropriately.
   ss >> get_time(&dt, inFormat.c_str());

   // Convert the tm structure to time_t value and return.
   return mktime(&dt);
}

int TimeUtils::getDurationSeconds(const string &inFormat, const string& inTime)
{
    int output {0};

    if (inTime.empty() == false) {
        time_t tmpTime = getTimeFromString(TIME_FORMAT_HHmmSS, inTime);

        output = tmpTime;
    }

    return output;
}

unsigned long TimeUtils::getCurrentTimeMilliseconds()
{
    unsigned long output = 0;

    chrono::system_clock::time_point now = chrono::system_clock::now();

    chrono::system_clock::duration tmpDuration = now.time_since_epoch();

    auto tp2 = chrono::duration_cast<chrono::milliseconds>(tmpDuration);

    output = tp2.count();

    return output;
}

unsigned long TimeUtils::now()
{
    return TimeUtils::getCurrentTimeMilliseconds();
}

string TimeUtils::getCurrentTimeString(const string& inFormat)
{ 
    // Get current time
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    // Format output string
    std::ostringstream oss;
    
    oss << std::put_time(&tm, inFormat.c_str());
    
    return oss.str();
}
