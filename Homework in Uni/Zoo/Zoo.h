#pragma once
#include "AquaDry.h"
#include <vector>

class Zoo
{
public:
	Zoo();
	Zoo(const Zoo&);
	Zoo& operator=(const Zoo&);
	~Zoo();
private:
	std::vector<Animal*> m_Animals;
};

