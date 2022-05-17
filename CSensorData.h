/**
 *  @author	Alessandro Papa
 *  @date	13.08.2020
 *  @brief	Data class to store all sensor values. Change name to mEncoder1Data, mEncoder2Data
 */
#ifndef CSENSORDATA_H
#define CSENSORDATA_H
#include "CIMUData.h"
#include "CEncoderData.h"
#include "CADCData.h"
//#include "CCalibratedSensorData.h"

class CSensorData
{
public:
	float        mTime;
	CIMUData     mIMU1Data;
	CIMUData     mIMU2Data;
    CIMUData	 mIMU3Data;
    CEncoderData mEncoder1Data;
    CEncoderData mEncoder2Data;
    CADCData	 mADCData;
//    CCalibratedSensorData mCalibData;

public:
	void display();
public:
	CSensorData();
	CSensorData& operator=(const CSensorData&) = default;
	CSensorData(const CSensorData&)            = default;
	~CSensorData()                             = default;
};

#endif
