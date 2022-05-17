// Michael Meindl, 23.05.2019
#ifndef CIMUDATA_H
#define CIMUDATA_H
#include "Global.h"

class CIMUData
{
public:
	Int16 mW_x;
	Int16 mW_y;
	Int16 mW_z;
	Int16 mA_x;
	Int16 mA_y;
	Int16 mA_z;
public:
	void display();
public:
	CIMUData();
	CIMUData& operator=(const CIMUData&) = default;
	CIMUData(const CIMUData&)            = default;
	~CIMUData()                          = default;
};

#endif
