#include "ElectricNet.h"

ElectricNet::ElectricNet()
{
	this->m_NetSize = 5;
	this->m_NetCounter = 0;
	this->m_ElectricNet = new ElectricDevice[m_NetSize];
	this->m_MaxUsage = 5000;
	this->m_CurUsage = 0;
}

ElectricNet::ElectricNet(const ElectricNet & rhs)
{
	this->m_NetSize = rhs.m_NetSize;
	this->m_NetCounter = rhs.m_NetCounter;
	this->m_ElectricNet = new ElectricDevice[this->m_NetSize];
	for (int i = 0; i < this->m_NetSize; i++)
	{
		this->m_ElectricNet[i] = rhs.m_ElectricNet[i];
	}
	this->m_MaxUsage = rhs.m_MaxUsage;
	this->m_CurUsage = rhs.m_CurUsage;
}

ElectricNet & ElectricNet::operator=(const ElectricNet &rhs)
{
	if (this != &rhs)
	{
		delete[] this->m_ElectricNet;
		this->m_NetSize = rhs.m_NetSize;
		this->m_NetCounter = rhs.m_NetCounter;
		this->m_ElectricNet = new ElectricDevice[this->m_NetSize];
		for (int i = 0; i < this->m_NetSize; i++)
		{
			this->m_ElectricNet[i] = rhs.m_ElectricNet[i];
		}
		this->m_MaxUsage = rhs.m_MaxUsage;
		this->m_CurUsage = rhs.m_CurUsage;
	}
	return *this;
}

ElectricNet::~ElectricNet()
{
	delete[]m_ElectricNet;
}

//doubles the size of the net, used in the += operator
void ElectricNet::BuffNet()
{
	this->m_NetSize *= 2;
	ElectricDevice * temp = new ElectricDevice[this->m_NetSize];
	for (int i = 0; i < this->m_NetCounter; i++)
	{
		temp[i] = this->m_ElectricNet[i];
	}
	delete[] this->m_ElectricNet;
	this->m_ElectricNet = temp;
}

ElectricNet ElectricNet::operator+(const ElectricDevice & rhs)const
{
	ElectricNet temp(*this);
	return temp += rhs;
}

ElectricNet & ElectricNet::operator+=(const ElectricDevice &rhs)
{
	if (this->m_MaxUsage - this->m_CurUsage < rhs.GetPowerUsed())
	{
		std::cout << "Not enough Power, operation failed";
	}
	else
	{
		if (this->m_NetCounter == this->m_NetSize)
		{
			BuffNet();
		}
		this->m_ElectricNet[m_NetCounter++] = rhs;
		this->m_CurUsage += rhs.GetPowerUsed();
		std::cout << "Device successfully inserted in the net\n";
		std::cout << "Power remaining: " << this->m_MaxUsage - this->m_CurUsage << std::endl;
	}
	return *this;
}

ElectricNet ElectricNet::operator-(const ElectricDevice &rhs) const
{
	ElectricNet temp(*this);
	return temp -= rhs;
}

//removes devices from the net, by comparing their names with the rhs, it will remove all devices with this name
ElectricNet & ElectricNet::operator-=(const ElectricDevice &rhs)
{
	for (int i = 0; i < this->m_NetCounter; i++)
	{
		if (this->m_ElectricNet[i].GetName() == rhs.GetName())
		{
			this->m_CurUsage -= this->m_ElectricNet[i].GetPowerUsed();
			for (int j = i; j < this->m_NetCounter - 1; j++)
			{
				this->m_ElectricNet[j] = this->m_ElectricNet[j + 1];
			}
			this->m_NetCounter--;
			i--;
			std::cout << "Device successfully removed from the net\n";
			std::cout << "Power remaining: " << this->m_MaxUsage - this->m_CurUsage << std::endl;
		}
	}
	return *this;
}

bool ElectricNet::operator!() const
{
	return this->m_NetCounter;
}

ElectricNet& ElectricNet::operator++()
{
	if (this->m_MaxUsage == 0)
	{
		this->m_MaxUsage += 1;
	}
	this->m_MaxUsage *= 2;
	std::cout << "The net max usage is set to " << this->m_MaxUsage << '\n';
	return *this;
}

ElectricNet& ElectricNet::operator--()
{
	if (this->m_MaxUsage / 2 >= this->m_CurUsage)
	{
		this->m_MaxUsage /= 2;
		std::cout << "The net max usage is set to " << this->m_MaxUsage << '\n';
	}
	else
	{
		std::cout << "The system cannot have its max usage halved" << std::endl;
	}
	return *this;
}

//as the task is not clear i print the info of all objects with the given name
void ElectricNet::operator[](const String &rhs)const
{
	bool found = false;
	for (int i = 0; i < this->m_NetCounter; i++)
	{
		if (this->m_ElectricNet[i].GetName() == rhs)
		{
			std::cout << rhs << " consumes " << this->m_ElectricNet[i].GetPowerUsed() << " power\n";
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "No item found\n";
	}
}
