#include "date.h"

Date::Date()
{
	this->m_Date = 0;
	this->m_Month = 0;
	this->m_Year = 0;
}

Date::Date(int d, int m, int y)
{
	this->m_Date = d;
	this->m_Month = m;
	this->m_Year = y;
}
