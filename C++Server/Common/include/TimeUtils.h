/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __TIMEUTILS_H__
#define __TIMEUTILS_H__


class TimeUtils
{
    public:
        TimeUtils();
        ~TimeUtils();

        static const string DATE_FORMAT_YYYYMMDDTHHmmSSZ;
        static const string DATE_FORMAT_YYYYMMDDTHHmmSS;
        static const string DATE_FORMAT_YYYYMMDD_HHmmSS;
        static const string TIME_FORMAT_HHmmSS;

        static time_t getTimeFromString(const string &inFormat, const string& inDateTime);

        static int getDurationSeconds(const string &inFormat, const string& inTime);

        static unsigned long getCurrentTimeMilliseconds();

        // Same as getCurrentTimeMilliseconds();
        static unsigned long now();
        
        static string getCurrentTimeString(const string& inFormat = TimeUtils::DATE_FORMAT_YYYYMMDDTHHmmSS);

    protected:

    private:
};

#endif // __TIMEUTILS_H__
