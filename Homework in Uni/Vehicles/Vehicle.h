#pragma once
#include "String.h"
#include <iostream>
class Vehicle
{
public:
	Vehicle();
	Vehicle(const String&, const String&, const String&, const int&, const int&);
	virtual ~Vehicle();
	//getters
	String GetBrand()const;
	String GetModel()const;
	String GetColor()const;
	int GetYear()const;
	int GetMileage()const;

	//setters
	void SetBrand(const String&);
	void SetModel(const String&);
	void SetColor(const String&);
	void SetYear(const int&);
	void SetMileage(const int&);

	void virtual details() const;

private:
	String m_Brand;
	String m_Model;
	String m_Color;
	int m_Year;
	int m_Mileage;
};
