#include "ElectricDevice.h"

ElectricDevice::ElectricDevice()
{
	this->m_Name = "";
	this->m_PowerUsed = 0;
}

ElectricDevice::ElectricDevice(const String & str, const int & pwr)
{
	this->m_Name = str;
	this->m_PowerUsed = pwr;
}

int ElectricDevice::GetPowerUsed() const
{
	return this->m_PowerUsed;
}

String ElectricDevice::GetName() const
{
	return this->m_Name;
}
