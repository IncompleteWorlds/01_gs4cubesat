/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __PASS_PREDICTION_LOAD_H__
#define __PASS_PREDICTION_LOAD_H__

#include <string>

using namespace std;

class PassPredictionLoad
{
    public:
        PassPredictionLoad();
        virtual ~PassPredictionLoad();

        void loadOrbitron(const string &inFileName);

    protected:

    private:
};

#endif // __PASS_PREDICTION_LOAD_H__
