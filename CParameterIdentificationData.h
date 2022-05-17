/**
 * @author Michael Meindl
 * @date   07.06.2019
 * @brief  Data class for paramter identification.
 */
#ifndef CPARAMETERIDENTIFICATIONDATA_H
#define CPARAMETERIDENTIFICATIONDATA_H
#include "Global.h"

class CParameterIdentificationData
{
public:
	float mTime;
	float mPsi;
	float mTorque;
public:
	CParameterIdentificationData();
	CParameterIdentificationData& operator=(const CParameterIdentificationData&) = default;
	CParameterIdentificationData(const CParameterIdentificationData&)            = default;
	~CParameterIdentificationData()                                              = default;
};


#endif
