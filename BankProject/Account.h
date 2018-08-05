#pragma once
#include <iostream>

//used as parameter for the functions related to polymorphic accounts
enum AccountType { Current, Savings, Privilege };

class Account
{
public:
	Account();
	Account(const double, const unsigned int, const unsigned int);
	virtual ~Account();

	AccountType GetAccountType()const;
	double GetBalance()const;
	unsigned int GetIban()const;
	unsigned int GetOwnerId()const;
	void SetAccountType(const AccountType);
	void SetBalance(const double);
	void BuffBalance(const double); //increases m_Balance (used in the deposit functions of derived classes
	virtual Account * CloneAccount()const = 0;//used in Bank->Bank(const bank&) and Bank->operator=

	//decrements the balance if possible, else returns false, 
	//I use it because the withdraw method is the same for current and savings acc and I try not to repeat code
	bool NerfBalance(const double);

	virtual void Deposit(const double) = 0;
	virtual bool Withdraw(const double) = 0;
	virtual void Display()const = 0;

private:
	AccountType m_AccountType;
	double m_Balance; //renaming task name so it matches the getter from the task requirement
	unsigned int m_Iban;
	unsigned int m_OwnerId;
};