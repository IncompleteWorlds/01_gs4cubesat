/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

#include "TimeUtils.h"

#include "PassPredictionLoad.h"

#include "ExternalIF.h"

ExternalIF::ExternalIF()
{
}

ExternalIF::~ExternalIF()
{
}

/** @brief getPasses
  * Return all the passes of a spacecraft over a ground station between
  * start and stop times
  */
void ExternalIF::getPasses(const string& inMission, const string& inSatellite,
                           const string& inGroundStation, const string& inStartTime, const string& inSopTime,
                           IW::List_Passes &outListPasses)
{
    // Temporary
    // NOTE: To read from a DB
    PassPredictionLoad  passLoad;

    passLoad.loadOrbitron("data/passes.txt");


    // Open file
    string passFileName = inGroundStation + "_" + inSatellite + "_passes.txt";

    ifstream  inPassFile;

    inPassFile.open(passFileName);

    if (inPassFile.is_open() == true) {
        // Get passes
        bool endPasses = false;

        string aosDate;
        string aosTime;
        string tcaDate;
        string tcaTime;
        string losDate;
        string losTime;
        string duration;
        string maxElevation;
        string orbit;
        string currentLine;

        //  AOS                  TCA                  LOS                  Duration   Max El Orbit
        //  2016/10/31 23:57:05  2016/11/01 00:03:41  2016/11/01 00:10:18  00:13:13   18.06  120665
        inPassFile >> currentLine;

        while (endPasses == false && inPassFile.eof() == false) {
            // Extract data
            inPassFile >> aosDate;
            inPassFile >> aosTime;

            inPassFile >> tcaDate;
            inPassFile >> tcaTime;

            inPassFile >> losDate;
            inPassFile >> losTime;

            inPassFile >> duration;

            inPassFile >> maxElevation;

            inPassFile >> orbit;

            IW::Pass  newPass;

            newPass.identifier = orbit;
            newPass.AOS = aosDate + "T" + aosTime;
            newPass.LOS = losDate + "T" + losTime;
            newPass.duration = TimeUtils::getDurationSeconds(TimeUtils::TIME_FORMAT_HHmmSS, duration);
            newPass.maxElevation = maxElevation;

            outListPasses.listPasses.push_back(newPass);

            // Next pass
            inPassFile >> currentLine;
        }

        inPassFile.close();

        // Set data
        outListPasses.spacecraftIdentifier = inSatellite;
        outListPasses.groundStationIdentifier = inGroundStation;
        outListPasses.numberPasses = outListPasses.listPasses.size();

    } else {
        cout << "ERROR: Unable to open output pass file: " << passFileName << endl;
        cout << "WARNING: Ignoring passes file: " << passFileName << endl;
    }
}
