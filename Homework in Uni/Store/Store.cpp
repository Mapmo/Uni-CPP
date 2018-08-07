#include "Store.h"
#include <iostream>

Store::Store()
{
	this->m_Counter = 0;
	this->m_SKUIncrementer = 0;
	this->m_Size = 5;
	this->m_Products = new Product[this->m_Size];
}

Store::Store(const Store& old)
{
	this->m_Counter = old.m_Counter;
	this->m_SKUIncrementer = old.m_SKUIncrementer;
	this->m_Size = old.m_Size;
	this->m_Products = new Product[m_Size];
	for (int i = 0; i < this->m_Counter; i++)
	{
		this->m_Products[i] = old.m_Products[i];
	}
}

Store::~Store()
{
	delete[] this->m_Products;
}

Product Store::CreateProduct()
{
	std::cout << "Insert Product Brand: ";
	char*f = new char[50];
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.getline(f, 50);
	std::cout << std::endl;

	std::cout << "Insert Product Model: ";
	char*g = new char[50];
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.getline(g, 50);
	std::cout << std::endl;

	std::cout << "Insert Product Price: ";
	int c = 0;
	std::cin >> c;
	std::cout << std::endl;

	std::cout << "Insert Product Year: ";
	int e = 0;
	std::cin >> e;
	std::cout << std::endl;

	std::cout << "Insert Product RAM: ";
	int d = 0;
	std::cin >> d;
	std::cout << std::endl;

	std::cout << "Insert Product HDD Memory: ";
	int b = 0;
	std::cin >> b;
	std::cout << std::endl;

	std::cout << "Insert Product Count: ";
	int a = 0;
	std::cin >> a;
	std::cout << std::endl;

	std::cout << "Does The Product Have Bluetooth(0/1): ";
	int h = 0;
	std::cin >> h;
	std::cout << std::endl;

	std::cout << "Is The Product Suitable For Gaming (0/1): ";
	int i = 0;
	std::cin >> i;
	std::cout << std::endl;

	
	Product u(a,b,c,d,e,f,g,h,i);
	delete[]f;
	delete[]g;
	return u;
}

void Store::AddProduct(const Product& a)
{
	if (this->m_Counter == m_Size)
	{
		IncreaseArray();
	}

	this->m_Products[this->m_Counter] = a;
	this->m_Products[this->m_Counter].SetSKU(this->m_SKUIncrementer); //the SKU is explicitly put in order to be unique
	this->m_Counter++;
	this->m_SKUIncrementer++;
}

void Store::ChangeProduct(int a)
{
	this->m_Products[a].ChangeProduct();
}

void Store::DeleteProduct(int a)
{
	for (int i = 0; i < m_Counter; i++)
	{
		if (this->m_Products[i].GetSKU() == a)
		{
			m_Counter--;
			if (i != m_Counter)
			{
				m_Products[i] = m_Products[m_Counter];
				m_Products[i].SetSKU(m_Products[m_Counter].GetSKU());
			}
		}
	}
}

void Store::IncreaseArray()
{
	this->m_Size *= 2;
	Product * old = new Product[m_Size];
	for (int i = 0; i < m_Counter; i++)
	{
		old[i] = this->m_Products[i];
		old[i].SetSKU(i);
	}
	delete[] this->m_Products;
	this->m_Products = old;
}

void Store::PrintAvailableProducts()const
{
	for (int i = 0; i < this->m_Counter; i++)
	{
		this->m_Products[i].PrintProduct();
		std::cout << std::endl;
	}
}