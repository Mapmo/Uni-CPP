#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	Truck(const String&, const String&, const String&, const int&, const int&,const int&);
	void details()const;
private:
	int m_Size;
};