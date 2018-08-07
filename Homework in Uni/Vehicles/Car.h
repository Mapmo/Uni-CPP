#pragma once
#include "Vehicle.h"
class Car : public Vehicle
{
public:
	Car();
	Car(const String&, const String&, const String&, const int&, const int&);
	void details()const;
};