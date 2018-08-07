#pragma once

class Product
{
	//the product is a laptop
private:
	int m_Count;
	int m_DiskMemory;					//hdd memory
	int m_Price;
	int m_RamMemory;					//RAM memory
	int m_SKU;
	int m_Year;							//year of creation
	char * m_Brand;
	char * m_Model;
	bool m_HasBluetooth;					//does the laptop have bluetooth
	bool m_IsGaming;						//is it suitable for gaming
public:
	Product();								//default constructor with all values set 0, false by default
	Product(int);							//constrctor with id  with all other values set 0, false by default
	Product(int, char*);					//constructor with id and Brand with all other values set 0, false and by default
	Product(int, int, int, int, int, char*, char*, bool, bool); //massive constructor used in the store class to add a product
	Product(const Product&);				//copy constructor
	Product operator = (const Product&);	//predefined operator used in Store, doesn't change SKU, !SKU must be changed explicitly
	~Product();								//destructor

	//getters
	int GetCount()const;
	int GetDiskMemory()const;
	int GetPrice()const;
	int GetRamMemory()const;
	int GetSKU()const;
	int GetYear()const;
	char * GetBrand()const;
	char * GetModel()const;
	bool GethasBluetooth()const;
	bool GetisGaming()const;

	void ChangeProduct();
	void PrintProduct() const;
	//setters
	void SetCount(const int);
	void SetDiskMemory(const int);
	void SetPrice(const int);
	void SetRamMemory(const int);
	void SetSKU(const int);
	void SetYear(const int);
	void SetBrand(char*);
	void SetModel(char*);
	void SetHasBluetooth(const bool);
	void SetIsGaming(const bool);

	//continue after store is ready
	void SaveInStore();
};