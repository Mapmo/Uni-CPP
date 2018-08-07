#pragma once
#include <iostream>
#include <string>

enum Type { aqua, aquaDry, dry, Unknown };

class Animal
{
public:
	Animal();
	Animal(const int, const std::string&, const bool);
	virtual ~Animal();

	virtual void Details()const = 0;
	virtual Type GetType()const = 0;
	virtual Animal * CloneAnimal() const = 0;
private:
	int m_Age;
	std::string m_Name;
	bool m_IsMale;
};

