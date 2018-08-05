#include "Account.h"

Account::Account() : m_Balance(0), m_Iban(0), m_OwnerId(0)
{
}

Account::Account(const double balance, const unsigned int iban, const unsigned int owner) :
	m_Balance(balance), m_Iban(iban), m_OwnerId(owner)
{
}

Account::~Account()
{
}

AccountType Account::GetAccountType() const
{
	return this->m_AccountType;
}

double Account::GetBalance() const
{
	return this->m_Balance;
}

unsigned int Account::GetIban() const
{
	return this->m_Iban;
}

unsigned int Account::GetOwnerId() const
{
	return this->m_OwnerId;
}

void Account::SetAccountType(const AccountType type)
{
	this->m_AccountType = type;
}

void Account::SetBalance(const double money)
{
	this->m_Balance = money;
}

void Account::BuffBalance(const double money)
{
	if (money < 0)
	{
		std::cout << "Bad Input\n";
		return;
	}
	this->m_Balance += money;
}

bool Account::NerfBalance(const double money)
{
	if (money < 0)
	{
		std::cout << "Bad Input\n";
		return false;
	}
	if (this->m_Balance >= money)
	{
		this->m_Balance -= money;
		return true;
	}
	return false;
}
