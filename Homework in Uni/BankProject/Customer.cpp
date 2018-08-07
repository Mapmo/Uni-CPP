#include "Customer.h"

Customer::Customer() :m_Id(0), m_Address(), m_Name(), m_Accounts()
{
}

Customer::Customer(const unsigned int id,const std::string & address, const std::string& name) :
	m_Id(id), m_Address(address), m_Name(name), m_Accounts()
{
}

unsigned int Customer::GetId() const
{
	return this->m_Id;
}

std::string Customer::GetAddress() const
{
	return this->m_Address;
}

std::string Customer::GetName() const
{
	return this->m_Name;
}

std::vector<unsigned int> Customer::GetCustomersAccounts() const
{
	return this->m_Accounts;
}

//prints all the available information about the customer
void Customer::Display() const
{
	std::cout << '\n';
	std::cout << "**********************\n";
	std::cout << "Account Information About Customer No: " << this->m_Id << '\n';
	std::cout << "Customer's Name: " << this->m_Name << '\n';
	std::cout << "Customer's Address: " << this->m_Address << '\n';
	ListCustomerAccounts(); //prints all the accounts of the customer in a separate function because it is later used in the bank class
	std::cout << "**********************\n";
	std::cout << '\n';
}

void Customer::ListCustomerAccounts() const
{
	std::cout << "Customer's Accounts:\n";
	for (std::vector<unsigned>::const_iterator i = this->m_Accounts.begin(); i != m_Accounts.end(); ++i)
	{
		std::cout << *i << '\n';
	}
}


//adds an account to m_CustomerAccounts
void Customer::AddAccount(const unsigned int a)
{
	this->m_Accounts.push_back(a);
	std::cout <<"IBAN "<< a << " Successfully Added To The Customer's Accounts List\n";
}

void Customer::RemoveAllAccounts()
{
	this->m_Accounts.clear();
}

//removes an account to m_CustomerAccounts
void Customer::RemoveAccount(const unsigned int a)
{
	for (std::vector<unsigned int>::iterator i = this->m_Accounts.begin(); i != m_Accounts.end(); ++i)
	{
		if (*i == a)
		{
			this->m_Accounts.erase(i);
			std::cout<<"Account Number " << a << " Successfully Removed From The Customer's Accounts List\n";
			return;
		}
	}
	std::cout << "The user has no such account\n";
}
