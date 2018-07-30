class Account
{
public:
	Account();
	virtual ~Account();

	virtual Account * CloneAccount()const = 0;//used in Bank->Bank(const bank&) and Bank->operator=

private:
};

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(const double, const double, const unsigned int, const unsigned int);

	Account*CloneAccount()const override;

};

Account * CurrentAccount::CloneAccount() const
{
	return new CurrentAccount(*this);
}


class Bank
{
public:
	Bank();
	Bank(const Bank&);
	Bank& operator = (const Bank&);
	~Bank();
private:
	std::vector<Account*> m_Accounts;
};

Bank::Bank(const Bank & rhs) : m_Address(rhs.m_Address), m_Name(rhs.m_Name), m_Accounts(), m_Customers(rhs.m_Customers)
{
	for (std::vector<Account*>::const_iterator it = rhs.m_Accounts.begin(); it != rhs.m_Accounts.end(); ++it)
	{
		this->m_Accounts.push_back((*(*it)).CloneAccount());
	}
}

Bank & Bank::operator=(const Bank & rhs)
{
	if (this != &rhs)
	{
		for (std::vector<Account * >::iterator it = this->m_Accounts.begin(); it != this->m_Accounts.end();)
		{
			delete (*it);
			this->m_Accounts.erase(it);
			it = this->m_Accounts.begin();
		}
		for (std::vector<Account*>::const_iterator it = rhs.m_Accounts.begin(); it != rhs.m_Accounts.end(); ++it)
		{
			this->m_Accounts.push_back((*(*it)).CloneAccount());
		}
		this->m_Name = rhs.m_Name;
		this->m_Address = rhs.m_Address;
		this->m_Customers = rhs.m_Customers;
	}
	return *this;
}