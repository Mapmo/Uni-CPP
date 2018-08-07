#include "Animal.h"
#include <vector>

Animal::Animal() : m_Age(0), m_Name("Unknown"), m_IsMale(0)
{
}

Animal::Animal(const int age, const std::string & name, const bool male)
	:  m_Age(age), m_Name(name), m_IsMale(male)
{
}

Animal::~Animal()
{
}
