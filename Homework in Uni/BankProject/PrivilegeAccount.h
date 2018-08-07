#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(const double, const double, const unsigned int, const unsigned int);

	double GetOverdraft()const;
	Account*CloneAccount()const override;

	void Deposit(const double) override;
	bool Withdraw(const double) override;
	void Display()const override;
private:
	double m_Overdraft;
};