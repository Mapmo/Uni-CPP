#include "AquaDry.h"

AquaDry::AquaDry() : Animal(), Dry(), Aqua()
{
}

AquaDry::AquaDry(const int age, const std::string &name, const bool isMale, AquaType aType, DryType dType)
	: Animal(age, name, isMale), Dry(age, name, isMale, dType), Aqua(age, name, isMale, aType)
{
}

void AquaDry::Details() const
{
	std::cout << "AquaType:" << GetAquaType() << " and DryType: " << GetDryType() << "\n";
}

Type AquaDry::GetType() const
{
	return aquaDry;
}

Animal * AquaDry::CloneAnimal() const
{
	return new AquaDry(*this);
}
