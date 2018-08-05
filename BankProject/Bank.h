#pragma once
#include "Customer.h"//also contains string and vector
#include "CurrentAccount.h"//also contains account and iostream
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

class Bank
{
public:
	Bank();
	Bank(const std::string&, const std::string&);
	Bank(const Bank&);
	Bank& operator = (const Bank&);
	~Bank();

	std::string GetAddress()const;
	std::string GetName()const;
	void Display()const;
	//CUSTOMER FUNCTIONS


	//used to find if there is a customer with that Id in m_Customers, returns false if there isn't such
	bool CheckCustomerId(const unsigned int)const;

	//adds a customer if the given id is not in the bank
	void AddCustomer(const unsigned int, const std::string &, const std::string &);

	void DeleteCustomer(const unsigned int);

	//will use the Customer->m_Accounts and the function DeleteAccount to delete all the customers' accounts
	void DeleteCustomersAccounts(const Customer &);

	//will call the Customer->Display() for all the members of m_Customers
	void ListCustomers()const;

	unsigned int CustomersCount()const;

	//ACCOUNT FUNCTIONS


	//checks if there is an account with that iban
	bool CheckAccountIban(const unsigned int)const;

	//returns the amount of accounts in the bank
	int AccountsCount()const;

	//adds an account to a customer, first checks if the customer exists and then checks if the another account has the same number
	//if everything is ok it will create a new account int the bank and in Customer->m_Accounts
	void AddAccount(const AccountType, const unsigned int, const unsigned int, const double);

	//will add the account iban to Customer->m_Accounts
	void AddAccountToCustomer(const unsigned int, const unsigned int);

	//loops thrtough the m_Accounts vector and if it finds a member with the given id, it erases it and breaks
	void DeleteAccount(const unsigned int);

	//will remove the account iban from Customer->m_Accounts
	void DeleteAccountFromCustomer(const unsigned int iban, const unsigned int ownerId);

	//prints out all accounts in the bank
	void ListAccounts()const;

	//dispalys info for all the accounts that match the given owner id
	void ListCustomerAccounts(const unsigned int)const;

	//these 2 functions use the ->Account functions and just navigate in the bank->vectors
	void Deposit(const unsigned int, const double);
	bool Withdraw(const unsigned int, const double);

	//a  combination of deposit and withdraw
	void Transfer(const unsigned int, const unsigned int, const double);
private:
	std::string m_Address;
	std::string m_Name;
	std::vector<Customer> m_Customers;
	std::vector<Account*> m_Accounts;
};