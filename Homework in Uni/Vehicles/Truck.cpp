#include "Truck.h"

Truck::Truck() : Vehicle()
{
	this->m_Size = 0;
}

Truck::Truck(const String& brand, const String& model, const String& color, const int& year, const int& mileage, const int& size) : Vehicle(brand, model, color, year, mileage)
{
	this->m_Size = size;
}

void Truck::details()const
{
	std::cout << "This is a truck\nIt's a " << this->GetColor()<<" " << this->GetBrand() << " - " << this->GetModel() << " from " << this->GetYear();
	std::cout << ". The truck has travelled " << this->GetMileage() << " miles and is "<<this->m_Size<<" meters long.\n";
}