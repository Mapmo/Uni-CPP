#include "Systemr.h"
#include <iostream>
System::System(int a)
{
	this->m_Counter = 0;
	this->m_Size = 5;
	this->m_Storage = a;
	this->m_StorageLeft = a;
	this->m_System = new Tool[m_Size];
}

System::System(const System & rhs)
{
	this->m_Counter = rhs.m_Counter;
	this->m_Size = rhs.m_Size;
	this->m_Storage = rhs.m_Storage;
	this->m_StorageLeft = rhs.m_StorageLeft;
	this->m_System = new Tool[this->m_Size + 1];
	for (int i = 0; i < rhs.m_Size; i++)
	{
		m_System[i] = rhs.m_System[i];
	}
}

System::~System()
{
	delete[] this->m_System;
}

System & System::operator=(const System & rhs)
{
	this->m_Counter = rhs.m_Counter;
	this->m_Size = rhs.m_Size;
	this->m_Storage = rhs.m_Storage;
	this->m_StorageLeft = rhs.m_StorageLeft;
	this->m_System = new Tool[this->m_Size + 1];
	for (int i = 0; i < rhs.m_Size; i++)
	{
		m_System[i] = rhs.m_System[i];
	}
	return *this;
}

void System::AddTool(const Tool & rhs)
{
	if (rhs.GetPower() > this->m_StorageLeft)
	{
		std::cout << "Sorry, no storage left :(";
		return;
	}
	else
	{
		if (this->m_Counter == this->m_Size)
		{
			grow();
		}
		
		this->m_System[this->m_Counter] = rhs;
		this->m_StorageLeft -= rhs.GetPower();
	}
}

void System::grow()
{
	this->m_Size *= 2;
	Tool * temp = new Tool[m_Size];
	for (int i = 0; i < this -> m_Counter; i++)
	{
		temp[i] = this->m_System[i];
	}
	delete[] this->m_System;
	this->m_System = temp;
}
