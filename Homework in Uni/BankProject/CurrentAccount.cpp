#include "CurrentAccount.h"

CurrentAccount::CurrentAccount() : Account()
{
	SetAccountType(Current);
}

CurrentAccount::CurrentAccount(const double balance, const unsigned int iban, const unsigned int owner) :
	Account(balance, iban, owner)
{
	SetAccountType(Current);
}

Account * CurrentAccount::CloneAccount() const
{
	return new CurrentAccount(*this);
}

void CurrentAccount::Deposit(const double money)
{
	BuffBalance(money);
	std::cout << "Money successfully deposited, " << GetBalance() << " remaining\n";
}

bool CurrentAccount::Withdraw(const double money)
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

void CurrentAccount::Display() const
{
	std::cout << '\n';
	std::cout << "****************\n";
	std::cout << "Account Info:\n";
	std::cout << "Account Type: Current\n";
	std::cout << "IBAN: " << GetIban() << '\n';
	std::cout << "Owner's Id: "<<GetOwnerId()<<'\n';
	std::cout << "Balance: " << GetBalance() << '\n';	
	std::cout << "****************\n";	
	std::cout << '\n';
}
