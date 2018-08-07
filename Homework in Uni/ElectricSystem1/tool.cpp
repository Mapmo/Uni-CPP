#include "tool.h"
#include <iostream>

Tool::Tool()
{
	this->m_Brand = nullptr;
	this->m_Name = nullptr;
	this->m_Date = Date();
	this->m_Power = 0;
}

Tool::Tool(const char * brand, const char * name, int power, Date date)
{
	int l = strlen(brand);
	this->m_Brand = new char[l + 1];
	strcpy(m_Brand, brand);
	 l = strlen(name);
	this->m_Name = new char[l + 1];
	strcpy(m_Name, name);
	this->m_Power = power;
	this->m_Date = date;
}

Tool::Tool(const Tool & rhs)
{
	int l = strlen(rhs.m_Brand);
	this->m_Brand = new char[l + 1];
	strcpy(m_Brand, rhs.m_Brand);
	l = strlen(rhs.m_Name);
	this->m_Name = new char[l + 1];
	strcpy(m_Name, rhs.m_Name);
	this->m_Power = rhs.m_Power;
	this->m_Date = rhs.m_Date;
}

Tool::~Tool()
{
	delete[] this->m_Brand;
	delete[] this->m_Name;
}

Tool & Tool::operator=(const Tool & rhs)
{
	int l = strlen(rhs.m_Brand);
	this->m_Brand = new char[l + 1];
	strcpy(m_Brand, rhs.m_Brand);
	l = strlen(rhs.m_Name);
	this->m_Name = new char[l + 1];
	strcpy(m_Name, rhs.m_Name);
	this->m_Power = rhs.m_Power;
	this->m_Date = rhs.m_Date;
	return *this;
}

int Tool::GetPower() const
{
	return this->m_Power;
}
