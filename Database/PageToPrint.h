#pragma once
//class used to represent a console page filled with rows from a table
//a page consist of one or more rows of a table
//the two parameters of this class represent the row of the table that will be first in the page
//, and the row of the table that will be first in the next page
class PageToPrint
{
public:
	PageToPrint(const unsigned int, const unsigned int);
	const unsigned int GetBegin()const;
	const unsigned int GetEnd()const;
private:
	const unsigned int m_Begin;
	const unsigned int m_End;
};