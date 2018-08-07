#include "Car.h"

Car::Car() : Vehicle()
{
}

Car::Car(const String& brand, const String& model, const String& color, const int& year, const int& mileage) : Vehicle(brand, model, color, year, mileage)
{
}

void Car::details()const
{
	std::cout << "This is a car\nIt's a " << this->GetColor() << " " << this->GetBrand() << " - " << this->GetModel() << " from " << this->GetYear();
	std::cout << ". The car has travelled " << this->GetMileage() << " miles.\n";
}