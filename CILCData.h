#ifndef CILCDATA_H
#define CILCDATA_H
#include "CStateData.h"
#include "CExperimentData.h"

class CILCData
{
public:
    CExperimentData mState;
    float      mR_Pitch;
    float      mR_Position;
    float      mRj;
    float      mY_Pitch;
    float      mY_Position;
public:
    CILCData();
    CILCData& operator=(const CILCData&) = default;
    CILCData(const CILCData&)            = default;
    ~CILCData()                          = default;
};

#endif
