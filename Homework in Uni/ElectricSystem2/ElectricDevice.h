#pragma once
#include "String.h"
//nothing interesting in this class
class ElectricDevice
{
public:
	ElectricDevice();
	ElectricDevice(const String&, const int&);

	int GetPowerUsed()const;
	String GetName() const;
private:
	String m_Name;
	int m_PowerUsed;
};