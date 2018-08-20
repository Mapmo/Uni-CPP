#include "Product.h"
#include <iostream>
#include "Functions.h"
Product::Product()
{
	this->m_Count = 0;
	this->m_DiskMemory = 0;
	this->m_Price = 0;
	this->m_RamMemory = 0;
	this->m_SKU = 0;
	this->m_Year = 0;
	this->m_Brand = nullptr;
	this->m_Model = nullptr;
	this->m_HasBluetooth = false;
	this->m_IsGaming = false;
}

Product::Product(int a)
{
	this->m_Count = 0;
	this->m_DiskMemory = 0;
	this->m_Price = 0;
	this->m_RamMemory = 0;
	this->m_SKU = a;
	this->m_Year = 0;
	this->m_Brand = nullptr;
	this->m_Model = nullptr;
	this->m_HasBluetooth = false;
	this->m_IsGaming = false;
}

Product::Product(int a, char*b)
{
	this->m_Count = 0;
	this->m_DiskMemory = 0;
	this->m_Price = 0;
	this->m_RamMemory = 0;
	this->m_SKU = a;
	this->m_Year = 0;
	this->m_Brand = nullptr;
	SetBrand(b);
	this->m_Model = nullptr;
	this->m_HasBluetooth = false;
	this->m_IsGaming = false;
}

Product::Product(int a, int b, int c, int d, int e, char* f, char* g, bool h, bool i)
{
	this->m_Count = a;
	this->m_DiskMemory = b;
	this->m_Price = c;
	this->m_RamMemory = d;
	this->m_Year = e;
	this->m_Brand = nullptr;
	SetBrand(f);
	this->m_Model = nullptr;
	SetModel(g);
	this->m_HasBluetooth = h;
	this->m_IsGaming = i;
}

Product::Product(const Product & old)
{
	this->m_Count = old.m_Count;
	this->m_DiskMemory = old.m_DiskMemory;
	this->m_Price = old.m_Price;
	this->m_RamMemory = old.m_RamMemory;
	this->m_SKU = old.m_SKU;
	this->m_Year = old.m_Year;
	this->m_Brand = nullptr;
	SetBrand(old.m_Brand);
	this->m_Model = nullptr;
	SetModel(old.m_Model);
	this->m_HasBluetooth = old.m_HasBluetooth;
	this->m_IsGaming = old.m_IsGaming;
}

Product Product::operator = (const Product&old) //SKU is intentionally skipped
{
	if (this != &old)
	{
		this->m_Count = old.m_Count;
		this->m_DiskMemory = old.m_DiskMemory;
		this->m_Price = old.m_Price;
		this->m_RamMemory = old.m_RamMemory;
		this->m_Year = old.m_Year;
		SetBrand(old.m_Brand);
		SetModel(old.m_Model);
		this->m_HasBluetooth = old.m_HasBluetooth;
		this->m_IsGaming = old.m_IsGaming;
	}
	return *this;
}

Product::~Product()
{
	delete[] this->m_Brand;
	delete[] this->m_Model;
}

//getters
int Product::GetSKU() const
{
	return this->m_SKU;
}

void Product::ChangeProduct()
{
	int input = 0;
	std::cout << "What detail of the product do you want to change?" << std::endl;
	std::cout << "1-Brand" << std::endl;
	std::cout << "2-Model" << std::endl;
	std::cout << "3-Price" << std::endl;
	std::cout << "4-RAM Memory" << std::endl;
	std::cout << "5-HDD Memory" << std::endl;
	std::cout << "6-Year" << std::endl;
	std::cout << "7-Count" << std::endl;
	std::cout << "8-Bluetooth Availability" << std::endl;
	std::cout << "9-Gaming Suitability" << std::endl;
	std::cin >> input;
	std::cout << "Please insert the new data";
	if (input > 2 && input < 8)
	{
		std::cout << ::std::endl;
		int newData = 0;
		std::cin >> newData;

		switch (input)
		{

		case 3: SetPrice(newData);
			break;
		case 4: SetRamMemory(newData);
			break;
		case 5: SetDiskMemory(newData);
			break;
		case 6: SetYear(newData);
			break;
		case 7: SetCount(newData);
			break;
		default:
			break;
		}
	}

	else if (input == 1 || input == 2)
	{
		std::cout << std::endl;
		char * newData = new char[50];
		std::cin.ignore();
		std::cin.getline(newData, 50);

		if (input == 1)
		{
			SetBrand(newData);
		}
		else
		{
			SetModel(newData);
		}

		delete[] newData;
	}
	else if (input == 8 || input == 9)
	{
		std::cout << " (0 - false, 1 - true)" << std::endl;
		bool newData = 0;
		std::cin >> newData;
		if (input == 8)
		{
			SetHasBluetooth(newData);
		}
		else
		{
			SetIsGaming(newData);
		}
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Invalid input" << std::endl;
	}
}

void Product::PrintProduct()const
{
	std::cout << "Product SKU is: " << this->m_SKU << std::endl;
	std::cout << "Product Brand is: " << this->m_Brand;
	std::cout << "Product Model is: " << this->m_Model;
	std::cout << "The amount of remaining items is: " << this->m_Count << std::endl;
	std::cout << "Product price is: " << this->m_Price << std::endl;
	std::cout << "Product has: " << this->m_RamMemory << " GB RAM Memory" << std::endl;
	std::cout << "Product has: " << this->m_DiskMemory << " HDD Memory" << std::endl;
	std::cout << "Product's year of manufacturing is: " << this->m_Year << " AC" << std::endl;
	std::cout << "There are " << this->m_Count << " Products left" << std::endl;
	(this->m_HasBluetooth) ? std::cout << "The product has bluetooth" : std::cout << "The product has no bluetooth";
	std::cout << std::endl;
	(this->m_IsGaming) ? std::cout << "The product is suitable for games" : std::cout << "The product is not suitable for gaming";
	std::cout << std::endl;
}
//setters
void Product::SetCount(const int a)
{
	this->m_Count = a;
}

void Product::SetDiskMemory(const int a)
{
	this->m_DiskMemory = a;
}

void Product::SetPrice(const int a)
{
	this->m_Price = a;
}

void Product::SetRamMemory(const int a)
{
	this->m_RamMemory = a;
}

void Product::SetSKU(const int a)
{
	this->m_SKU = a;
}

void Product::SetYear(const int a)
{
	this->m_Year = a;
}

void Product::SetBrand(char * a)
{
	delete[] this->m_Brand;
	int i = strlen(a);
	if (i == 0)
	{
		this->m_Brand = nullptr;
	}
	else
	{
		this->m_Brand = new char[i + 1];
		for (int j = 0; j < i; j++)
		{
			this->m_Brand[j] = a[j];
		}
		this->m_Brand[i] = '\0';
	}
}

void Product::SetModel(char*a)
{
	delete[] this->m_Model;
	int i = strlen(a);
	if (i == 0)
	{
		this->m_Model = nullptr;
	}
	else
	{
		this->m_Model = new char[i + 1];
		for (int j = 0; j < i; j++)
		{
			this->m_Model[j] = a[j];
		}
		this->m_Model[i] = '\0';
	}
}

void Product::SetHasBluetooth(const bool a)
{
	this->m_HasBluetooth = a;
}

void Product::SetIsGaming(const bool a)
{
	this->m_IsGaming = a;
}
