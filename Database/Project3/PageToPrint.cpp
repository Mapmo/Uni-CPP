#include "PageToPrint.h"

PageToPrint::PageToPrint(const unsigned beg, const unsigned end) : m_Begin(beg), m_End(end)
{
}

const unsigned PageToPrint::GetBegin() const
{
	return this->m_Begin;
}

const unsigned PageToPrint::GetEnd() const
{
	return this->m_End;
}
