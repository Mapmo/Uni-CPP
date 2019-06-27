#include "Cell.h"

Cell::Cell(const std::string & value):m_Value(value)
{
}

const std::string & Cell::GetValue()const
{
	return this->m_Value;
}

void Cell::SetValue(const std::string & value)
{
	this->m_Value = value;
}
