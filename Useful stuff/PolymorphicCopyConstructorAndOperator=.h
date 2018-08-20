//The base class

class Account
{
public:
	Account();
	virtual ~Account();

	virtual Account * CloneAccount()const = 0;

private:
};


//the inheriting class
class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(const double, const double, const unsigned int, const unsigned int);

	Account*CloneAccount()const override;

};

//the magic used for the big 4, this function uses the class' copy constructor and then
//dynamicly allocates the new object, and then returns a pointer to it
Account * CurrentAccount::CloneAccount() const
{
	return new CurrentAccount(*this);
}


//the container of pointers to the base class

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


//here is how simple it is to use the function
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
	    //first delete the previous members!
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
