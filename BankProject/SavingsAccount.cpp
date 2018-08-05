#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(): Account()
{
	SetAccountType(Savings);
}

SavingsAccount::SavingsAccount(const double balance, const double rate ,const unsigned int iban, const unsigned int owner) :
	Account(balance, iban, owner), m_InterestRate(rate)
{
	SetAccountType(Savings);
}

double SavingsAccount::GetInterestRate() const
{
	return this->m_InterestRate;
}

Account * SavingsAccount::CloneAccount() const
{
	return new SavingsAccount(*this);
}

void SavingsAccount::Deposit(const double money)
{
	BuffBalance(money);
	std::cout << "Money successfully deposited, " << GetBalance() << " remaining\n";
}

bool SavingsAccount::Withdraw(const double money)
{
	bool isOk = NerfBalance(money);
	if (isOk)
	{
		std::cout << "Money successfully witdrawn, " << GetBalance() << " remaining\n";
	}
	else
	{
		std::cout << "Money not successfully witdrawn, " << GetBalance() << " remaining\n";
	}
	return isOk;
}

void SavingsAccount::Display() const
{
	std::cout << '\n';
	std::cout << "****************\n";
	std::cout << "Account Info:\n";
	std::cout << "Account Type: Savings\n";
	std::cout << "IBAN: " << GetIban() << '\n';
	std::cout << "Owner's Id: " << GetOwnerId() << '\n';
	std::cout << "Balance: " << GetBalance() << '\n';
	std::cout << "Interest Rate: " << GetInterestRate() << '\n';
	std::cout << "****************\n";
	std::cout << '\n';
}
