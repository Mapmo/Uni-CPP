#include "Motorcycle.h"

void Motorcycle::details() const
{
	std::cout << "This is a motorcycle\nIt's a " << this->GetColor() << " " << this->GetBrand() << " - " << this->GetModel() << " from " << this->GetYear();
	std::cout << ". The motorcycle has travelled " << this->GetMileage() << " miles and it is a " << this->m_Type << "\n";
}

Motorcycle::Motorcycle() : Vehicle()
{
	this->m_Type = "";
}

Motorcycle::Motorcycle(const String& brand, const String& model, const String& color, const int& year, const int& mileage,const String& type) : Vehicle(brand, model, color, year, mileage)
{
	this->m_Type = type;
}
