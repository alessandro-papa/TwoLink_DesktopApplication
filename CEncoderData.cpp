// Michael Meindl, 23.05.2019
#include "CEncoderData.h"
#include <iostream>

CEncoderData::CEncoderData() : mNumberOfTicks{0U}
{

}
void CEncoderData::display()
{
	std::cout << "Number of Ticks: " << mNumberOfTicks << std::endl;
}
