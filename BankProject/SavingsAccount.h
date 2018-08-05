#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount();
	SavingsAccount(const double, const double, const unsigned int, const unsigned int);

	double GetInterestRate()const;
	Account * CloneAccount()const override;

	void Deposit(const double) override;
	bool Withdraw(const double) override;
	void Display()const override;

private:
	double m_InterestRate;
};

