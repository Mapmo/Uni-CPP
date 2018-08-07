#include "Zoo.h"



Zoo::Zoo() : m_Animals()
{
}

Zoo::Zoo(const Zoo & rhs)
{
	for (int i = 0; i < rhs.m_Animals.size(); ++i)
	{
		this->m_Animals.push_back(rhs.m_Animals[i]->CloneAnimal());
	}
}

Zoo & Zoo::operator=(const Zoo & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < this->m_Animals.size();)
		{
			delete this->m_Animals[i];
			this->m_Animals.erase(m_Animals.begin());
		}
		for (int i = 0; i < rhs.m_Animals.size(); ++i)
		{
			this->m_Animals.push_back(rhs.m_Animals[i]->CloneAnimal());
		}
	}
	return *this;
}


Zoo::~Zoo()
{
	for (int i = 0; i < this->m_Animals.size();)
	{
		delete this->m_Animals[i];
	}
}
