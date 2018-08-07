#pragma once
#include "tool.h"
class System 
{
public:
	System(int);
	System(const System&);
	~System();
	System& operator = (const System&);

	void AddTool(const Tool&);
	void grow();
private:
	int m_Counter;
	int m_Size;
	int m_Storage;
	int m_StorageLeft;
	Tool * m_System;
};