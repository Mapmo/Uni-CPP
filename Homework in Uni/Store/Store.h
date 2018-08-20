#pragma once
#include "Product.h"

class Store
{
	int m_Counter;								//counts the ammount of products in the store
	int m_SKUIncrementer;
	int m_Size;
	Product * m_Products;

    void IncreaseArray();						//increases the arr

public:
	Store();									//default const making arr with size 5
	Store(const Store&);						//copy constr
	~Store();									//destructor

	Product CreateProduct();					//creates a full product by asking the user to insert all the data
	void AddProduct(const Product&);			//adds a Product object to the m_Products arr
	void ChangeProduct(int);					//changes the product with selected id
	void DeleteProduct(int);					//deletes the product with the selected id
	void PrintAvailableProducts() const;		//tbd
};
