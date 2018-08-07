#include "Dry.h"



Dry::Dry() : Animal(), m_DryType(Human)
{
}

Dry::Dry(const int age, const std::string & name, const bool male, const DryType dryType)
	:Animal( age, name, male), m_DryType(dryType)
{
}

void Dry::Details() const
{
	std::cout << "Ich bin lazy\n";
}

DryType Dry::GetDryType() const
{
	return this->m_DryType;
}

Type Dry::GetType() const
{
	return dry;
}

Animal * Dry::CloneAnimal() const
{
	return new Dry(*this);
}
