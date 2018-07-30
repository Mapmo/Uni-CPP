#include "PageToPrint.h"

PageToPrint::PageToPrint(const unsigned int beg, const unsigned int end) : m_Begin(beg), m_End(end)
{
}

const unsigned int PageToPrint::GetBegin() const
{
	return this->m_Begin;
}

const unsigned int PageToPrint::GetEnd() const
{
	return this->m_End;
}
