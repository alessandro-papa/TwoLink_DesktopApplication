// Michael Meindl, 23.05.2019
#ifndef CENCODERDATA_H
#define CENCODERDATA_H
#include "Global.h"

class CEncoderData
{
public:
    Int32 mNumberOfTicks;
public:
	void display();
public:
	CEncoderData();
	CEncoderData& operator=(const CEncoderData&) = default;
	CEncoderData(const CEncoderData&)            = default;
	~CEncoderData()                              = default;
};

#endif
