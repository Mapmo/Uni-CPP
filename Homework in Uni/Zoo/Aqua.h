#pragma once
#include "Animal.h"
enum AquaType{ Fish, Mammal, Ariel };
class Aqua : virtual public Animal
{
public:
	Aqua();
	Aqua(const int, const std::string&, const bool, AquaType);
	void Details() const override;
	AquaType GetAquaType()const;
	Type GetType()const override;
	Animal * CloneAnimal() const override;
private:
	AquaType m_AquaType;
};

