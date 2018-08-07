#pragma once
#include "Aqua.h"
#include "Dry.h"

class AquaDry : virtual public Animal, public Aqua, public Dry
{
public:
	AquaDry();
	AquaDry(const int, const std::string&, const bool, AquaType, DryType);
	void Details() const override;
	Type GetType()const override;
	Animal * CloneAnimal() const override;

};

