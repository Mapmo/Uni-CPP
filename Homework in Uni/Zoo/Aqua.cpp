#include "Aqua.h"

Aqua::Aqua() : Animal(), m_AquaType(Ariel)
{
}

Aqua::Aqua( const int age, const std::string & name, const bool male, AquaType aquaType)
	:Animal( age, name, male), m_AquaType(aquaType)
{
}

void Aqua::Details() const
{
	std::cout << "Lazy like aquaman\n";
}

AquaType Aqua::GetAquaType() const
{
	return this->m_AquaType;
}

Type Aqua::GetType() const
{
	return aqua;
}

Animal * Aqua::CloneAnimal() const
{
	return new Aqua(*this);
}
