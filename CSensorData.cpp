/**
 *  @author	Michael Meindl
 *  @date   06.06.2019
 *  @brief  Method definitions for CSensorData.
 */
#include "CSensorData.h"
#include <iostream>

CSensorData::CSensorData() : mTime{0.0F}
{

}
void CSensorData::display()
{
	std::cout << "Time: " << mTime << std::endl;
	std::cout << "----- IMU1-Data -----" << std::endl;
	mIMU1Data.display();
	std::cout << "----- IMU2-Data -----" << std::endl;
	mIMU2Data.display();
	std::cout << "----- Left-Encoder-Data -----" << std::endl;
	mEncoder1Data.display();
	std::cout << "----- Right-Encoder-Data -----" << std::endl;
	mEncoder2Data.display();
}
