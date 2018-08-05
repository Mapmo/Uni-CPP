#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount() : Account()
{
	SetAccountType(Privilege);
}

PrivilegeAccount::PrivilegeAccount(const double balance, double overdraft, const unsigned int iban, const unsigned int owner) :
	Account(balance, iban,owner), m_Overdraft(overdraft)
{
	SetAccountType(Privilege);
}

double PrivilegeAccount::GetOverdraft() const
{
	return this->m_Overdraft;
}

Account * PrivilegeAccount::CloneAccount() const
{
	return new PrivilegeAccount(*this);
}

void PrivilegeAccount::Deposit(const double money)
{
	BuffBalance(money);
	std::cout << "Money successfully deposited, " << GetBalance() << " remaining\n";
}

bool PrivilegeAccount::Withdraw(const double money)
{
	if (money < 0)
	{
		std::cout << "Bad Input\n";
		return false;
	}

	if (GetBalance() + GetOverdraft() >= money)
	{
		SetBalance(GetBalance() - money);
		std::cout << "Money successfully witdrawn, " << GetBalance() << " remaining\n";
		return true;
	}
	else
	{
		std::cout << "Money not successfully witdrawn, " << GetBalance() << " remaining\n";
		return false;
	}
}

void PrivilegeAccount::Display() const
{
	std::cout << '\n';
	std::cout << "****************\n";
	std::cout << "Account Info:\n";
	std::cout << "Account Type: Privilege\n";
	std::cout << "IBAN: " << GetIban() << '\n';
	std::cout << "Owner's Id: " << GetOwnerId() << '\n';
	std::cout << "Balance: " << GetBalance() << '\n';
	std::cout << "Overdraft Allowed: " << GetOverdraft() << '\n';
	std::cout << "****************\n";
	std::cout << '\n';
}
