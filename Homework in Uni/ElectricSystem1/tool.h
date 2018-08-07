#pragma once
#include "date.h"
#include <cstring>
class Tool
{
public:
	Tool();
	Tool(const char*, const char*, int, Date);
	Tool(const Tool&);
	~Tool();
	Tool& operator=(const Tool&);

	int GetPower()const;
private:
	char * m_Brand;
	char * m_Name;
	int m_Power;
	Date m_Date;
};
