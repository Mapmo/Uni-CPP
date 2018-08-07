#include "Vehicle.h"

Vehicle::Vehicle()
{
	m_Brand = "";
	m_Model = "";
	m_Color = "";
	m_Year = 1970;
	m_Mileage = 0;
}

Vehicle::Vehicle(const String& brand, const String& model, const String& color, const int& year, const int& mileage)
{
	this->m_Brand = brand;
	this->m_Model = model;
	this->m_Color = color;
	this->m_Year = year;
	this->m_Mileage = mileage;
}

Vehicle::~Vehicle()
{
}

String Vehicle::GetBrand() const
{
	return this->m_Brand;
}

String Vehicle::GetModel() const
{
	return this->m_Model;
}

String Vehicle::GetColor() const
{
	return this->m_Color;
}

int Vehicle::GetYear() const
{
	return this->m_Year;
}

int Vehicle::GetMileage() const
{
	return this->m_Mileage;
}

void Vehicle::SetBrand(const String& brand)
{
	this->m_Brand = brand;
}

void Vehicle::SetModel(const String& model)
{
	this->m_Model = model;
}

void Vehicle::SetColor(const String& color)
{
	this->m_Color = color;
}

void Vehicle::SetYear(const int& year)
{
	this->m_Year = year;
}

void Vehicle::SetMileage(const int&  mileage)
{
	this->m_Mileage = mileage;
}

void Vehicle::details() const
{
}
