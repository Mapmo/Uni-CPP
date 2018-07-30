#include "Cell.h"

Cell::Cell(const std::string & val) : m_Value(val)
{
}


const std::string & Cell::GetValue()const
{
	return this->m_Value;
}

void Cell::SetValue(const std::string & val)
{
	this->m_Value = val;
}
