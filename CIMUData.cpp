// Michael Meindl, 23.05.2019
#include "CIMUData.h"
#include <iostream>

CIMUData::CIMUData() : mW_x{0}, mW_y{0}, mW_z{0},
                       mA_x{0}, mA_y{0}, mA_z{0}
{

}
void CIMUData::display()
{
	std::cout << "W_x: "  << mW_x;
	std::cout << " W_y: " << mW_y;
	std::cout << " W_z: " << mW_z << std::endl;
	std::cout << "A_x: "  << mA_x;
	std::cout << " A_y: " << mA_y;
	std::cout << " A_z: " << mA_z << std::endl;
}
