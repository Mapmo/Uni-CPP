#pragma once
#include "Animal.h"

enum DryType { mammal, Bird, Human};

class Dry :virtual public Animal
{
public:
	Dry();
	Dry( const int, const std::string&, const bool, DryType);
	void Details()const override;
	DryType GetDryType()const;
	Type GetType()const override;
	Animal * CloneAnimal() const override;
private:
	DryType m_DryType;
};

