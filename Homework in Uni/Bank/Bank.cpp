#include "Bank.h"

Bank::Bank() : m_Address(), m_Name(), m_Customers(), m_Accounts()
{
}

Bank::Bank(const std::string & address, const std::string & name) : m_Address(address), m_Name(name), m_Accounts(), m_Customers()
{
}

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

Bank::~Bank()
{
	for (std::vector<Account * >::iterator it = this->m_Accounts.begin(); it != this->m_Accounts.end();)
	{
		delete (*it);
		this->m_Accounts.erase(it);
		it = this->m_Accounts.begin();
	}
}

std::string Bank::GetAddress() const
{
	return this->m_Address;
}

std::string Bank::GetName() const
{
	return this->m_Name;
}

void Bank::Display() const
{
	std::cout << '\n';
	std::cout << "****************\n";
	std::cout << "Bank Info:\n";
	std::cout << "Bank Name: " << GetName() << '\n';
	std::cout << "Bank Address: " << GetAddress() << '\n';
	std::cout << "Bank's Customers' Count: " << CustomersCount() << '\n';
	std::cout << "Bank's Accounts' Count: " << AccountsCount() << '\n';
	std::cout << "****************\n";
	std::cout << '\n';
}

bool Bank::CheckCustomerId(const unsigned int idToCheck) const
{
	for (std::vector<Customer>::const_iterator i = this->m_Customers.begin(); i != this->m_Customers.end(); ++i)
	{
		if ((*i).GetId() == idToCheck)
		{
			return 1;
		}
	}
	return 0;
}

void Bank::AddCustomer(const unsigned int id, const std::string & address, const std::string & name)
{
	int customerId = CheckCustomerId(id);//checks if the id is free
	if (customerId == 0)
	{
		this->m_Customers.push_back(Customer(id, address, name));
	}
	else
	{
		std::cout << "\nID is already taken!\n";
	}
}

void Bank::DeleteCustomer(const unsigned int id)
{
	if (CheckCustomerId(id))
	{
		//will iterate until it finds a customer with id matching with the parameter of the function 
		for (std::vector<Customer>::iterator i = this->m_Customers.begin(); i != this->m_Customers.end(); ++i)
		{
			if ((*i).GetId() == id)
			{
				std::cout << "The Following Customer has been erased:\n";
				(*i).Display();
				DeleteCustomersAccounts(*i);//will first delete the accounts of the customer
				this->m_Customers.erase(i);
				return;
			}
		}
	}
	else
	{
		std::cout << "No Such Customer Exists\n";
	}
}

void Bank::DeleteCustomersAccounts(const Customer& customer) 
{
	for (std::vector<Customer>::iterator i = this->m_Customers.begin(); i != this->m_Customers.end(); ++i) //*i is a customer
	{
		//iterates through the m_Customers vector, till it finds a customer with the same id as that of the parameter of the function
		//then it will iterate through the Customer->m_Accounts of the found customer and will delete all bank 
		//accounts whose IBANs are in the Customer->m_Accounts vector
		//after all accounts are deleted, it will clear the Customer->m_Accounts
		if ((*i).GetId() == customer.GetId()) //*it is an unsigned int
		{
			std::vector<unsigned int> customerList = (*i).GetCustomersAccounts();
			for (std::vector<unsigned int>::iterator it = customerList.begin(); it != customerList.end(); ++it)
			{
				DeleteAccount(*it);
			}
			(*i).RemoveAllAccounts();
			return;
		}
		
	}
}

void Bank::ListCustomers() const
{
	for (std::vector<Customer>::const_iterator i = this->m_Customers.begin(); i != this->m_Customers.end(); ++i)
	{
		(*i).Display();
	}
}

//used in the Bank->Display function
unsigned int Bank::CustomersCount() const
{
	return this->m_Customers.size();
}

//will iterate through the m_Accounts vector and tries to find an account with Iban matching that of the function parameter
bool Bank::CheckAccountIban(const unsigned int iban) const
{
	for (std::vector<Account*>::const_iterator i = this->m_Accounts.begin(); i != this->m_Accounts.end(); ++i)
	{
		if ((*(*i)).GetIban() == iban)
		{
			return 1;
		}
	}
	return 0;
}

//used in Bank->Display
int Bank::AccountsCount() const
{
	return this->m_Accounts.size();
}

//makes two validations and if everything is ok will ask the user for the type of the account, the POLYMORPHISM :)))
void Bank::AddAccount(const AccountType type, const unsigned int iban, const unsigned int ownerId, const double amount)
{
	if (!CheckCustomerId(ownerId))
	{
		std::cout << "There Is No Customer With Such ID\n";
	}
	else if (CheckAccountIban(iban))
	{
		std::cout << "There Is Already An Account With Such IBAN\n";
	}
	else
	{
		AddAccountToCustomer(iban, ownerId);//will add the IBAN to the Customer->m_Accounts
		switch (type)
		{
		case Privilege:
		{
			this->m_Accounts.push_back(new PrivilegeAccount(amount, 0, iban, ownerId));
			break;
		}
		case Savings:
		{
			this->m_Accounts.push_back(new SavingsAccount(amount, 0, iban, ownerId));
			break;
		}
		case Current:
		{
			this->m_Accounts.push_back(new CurrentAccount(amount, iban, ownerId));
			break;
		}
		}
	}
}

//finds the customer from the parameter and adds the acccount iban from the parameter to the Customer->m_Accounts
void Bank::AddAccountToCustomer(const unsigned int iban, const unsigned int ownerId)
{
	for (std::vector<Customer>::iterator i = this->m_Customers.begin(); i != this->m_Customers.end(); ++i)
	{
		if ((*i).GetId() == ownerId)
		{
			(*i).AddAccount(iban);
		}
	}
}

//will iterate through the m_Accounts until it finds the iban from the parameter
void Bank::DeleteAccount(const unsigned int iban)
{
	for (std::vector<Account*>::const_iterator i = this->m_Accounts.begin(); i != this->m_Accounts.end(); ++i)
	{
		if ((*(*i)).GetIban() == iban)
		{
		DeleteAccountFromCustomer(iban, (*(*i)).GetOwnerId());//will delete the account iban in the Customer->m_Accounts
		delete *i;
		 this->m_Accounts.erase(i); //will Remove the account from the bank vector
		 return;
		}
	}
	std::cout << "No Such Account Found\n";
}

void Bank::DeleteAccountFromCustomer(const unsigned int iban, const unsigned int ownerId)
{
	//will iterate through the m_Customers until it finds the ownerId of the given customer and then it will try do delete 
	//iban number of the account in the Customer->m_Accounts vector, using the Customer->RemoveAccount function
	for (std::vector<Customer>::iterator i = this->m_Customers.begin(); i != this->m_Customers.end(); ++i)
	{
		if ((*i).GetId() == ownerId)
		{
			(*i).RemoveAccount(iban);
			return;
		}
	}
}

//iterates through m_Accounts and calls Account*->Display for every single account in it
void Bank::ListAccounts() const
{
	for (std::vector<Account*>::const_iterator i = this->m_Accounts.begin(); i != this->m_Accounts.end(); ++i)
	{
		(*(*i)).Display();
	}
}

//receives an ownerId as a parameter and iterates through m_Accounts, 
//if it finds an account of the parameter customer, it will call Account->Display()
void Bank::ListCustomerAccounts(const unsigned int ownerId) const
{
	for (std::vector<Account*>::const_iterator i = this->m_Accounts.begin(); i != this->m_Accounts.end(); ++i)
	{
		if ((*(*i)).GetOwnerId() == ownerId)
		{
			(*(*i)).Display();
		}
	}
}

//will iterate through m_Account until it finds iban parameter and then it will use Account*->Deposit() on it
void Bank::Deposit(const unsigned int iban, const double amount)
{
	for (std::vector<Account*>::const_iterator i = this->m_Accounts.begin(); i != this->m_Accounts.end(); ++i)
	{
		if ((*(*i)).GetIban() == iban)
		{
			(*(*i)).Deposit(amount);
		}
	}
}

//iterates m_Accounts till it finds the right account and then uses Account*->Withdraw(), ok reprents the success of the operation
bool Bank::Withdraw(const unsigned int iban, const double amount)
{
	bool ok = false;
	for (std::vector<Account*>::const_iterator i = this->m_Accounts.begin(); i != this->m_Accounts.end(); ++i)
	{
		if ((*(*i)).GetIban() == iban)
		{
			ok = (*(*i)).Withdraw(amount);
		}
	}
	return ok;
}

//uses directly the functinos Withdraw and Deposit, and won't proceed to deposit if Withdraw has failed
void Bank::Transfer(const unsigned int from, const unsigned int to, const double sum)
{
	bool ok = Withdraw(from, sum);
	if (ok)
	{
	Deposit(to, sum);
	}
	else
	{
		std::cout << "Transfer Not Possible";
	}
}

