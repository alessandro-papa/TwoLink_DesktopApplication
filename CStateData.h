/*
 * CStateData.h
 *
 *  Created on: 27.06.2019
 *      Author: Michael Meindl
 */

#ifndef CONTROLLIBRARY_CSTATEDATA_H_
#define CONTROLLIBRARY_CSTATEDATA_H_
#include "Global.h"

class CStateData
{
public:
    float mTime;
    float mTheta;
    float mThetaInt;
    float mTheta_d;
    float mS;
    float mS_d;
    float mU;
public:
    CStateData();
    CStateData& operator=(const CStateData&) = default;
    CStateData(const CStateData&)            = default;
    ~CStateData()                            = default;
};

#endif /* CONTROLLIBRARY_CSTATEDATA_H_ */
