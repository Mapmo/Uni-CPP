#pragma once
#include "ElectricDevice.h"

class ElectricNet
{
public:
	ElectricNet();
	ElectricNet(const ElectricNet&);
	ElectricNet& operator= (const ElectricNet&);
	~ElectricNet();

	void BuffNet();
	ElectricNet operator +(const ElectricDevice&)const;
	ElectricNet& operator +=(const ElectricDevice&);
	ElectricNet operator -(const ElectricDevice&)const;
	ElectricNet& operator -=(const ElectricDevice&);
	void operator[](const String&)const;
	bool operator!()const;
	ElectricNet& operator++();
	ElectricNet& operator--();
private:
	ElectricDevice * m_ElectricNet;
	int m_CurUsage;
	int m_MaxUsage;
	int m_NetCounter;
	int m_NetSize;
};