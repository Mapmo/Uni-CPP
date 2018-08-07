#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount();
	CurrentAccount(const double, const unsigned int, const unsigned int);

	Account * CloneAccount()const override;

	void Deposit(const double) override;
	bool Withdraw(const double) override;
	void Display()const override;
};
