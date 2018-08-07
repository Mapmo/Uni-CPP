#pragma once
#include <iostream>
#include <string>
#include <vector>

class Customer
{
public:
	Customer();
	Customer(const unsigned int,const std::string&, const std::string&);
	
	unsigned int GetId() const;
	std::string GetAddress()const;
	std::string GetName()const;
	std::vector<unsigned int> GetCustomersAccounts()const;

	void Display()const;
	void ListCustomerAccounts()const;

	void AddAccount(const unsigned int);
	void RemoveAllAccounts();
	void RemoveAccount(const unsigned int);
private:
	std::string m_Address;
	std::string m_Name;
	unsigned int m_Id;
	std::vector<unsigned int> m_Accounts; /*contains the ibans of the customer's accounts, a link between customer and account 
										  from the UML graph. Mot sure that, if 2 objects are associated with each other, they have
										  to be linked this way, I hope not to be executed for this if i am wrong*/
};