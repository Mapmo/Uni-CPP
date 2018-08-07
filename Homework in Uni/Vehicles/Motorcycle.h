#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	void details()const;
	Motorcycle();
	Motorcycle(const String&, const String&, const String&, const int&, const int&, const String&);
private:
	String m_Type;
};