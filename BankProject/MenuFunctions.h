#pragma once
#include "Bank.h"

//purely cosmetic function that displays the main menu
void DisplayMenu()
{
	std::cout << "1 List customers\n";
	std::cout << "2 Add new customer\n";
	std::cout << "3 Delete customer\n";
	std::cout << "4 List all accounts\n";
	std::cout << "5 List customer accounts\n";
	std::cout << "6 Add new account\n";
	std::cout << "7 Delete account\n";
	std::cout << "8 Withdraw from account\n";
	std::cout << "9 Deposit to account\n";
	std::cout << "10 Transfer\n";
	std::cout << "11 Display info for the bank\n";
	std::cout << "12 Quit\n";
	std::cout << '\n';
}

//used to validate the user's input about account type
bool ValidateAccountType(const short int type)
{
	if (type >= 0 && type < 4)
		return true;
	return false;
}

//this function has the functionality of the main menu
void ExecuteCommand(int input, double input1, std::string& input2, std::string& input3, unsigned int input4, short int input5,
	AccountType input6, unsigned int input7, Bank & bank)
{
	switch (input)
	{
	case 1:
		bank.ListCustomers();
		break;
	case 2:
		std::cout << "Customer's id: ";
		std::cin >> input4;
		std::cout << "Customer's Adress: ";
		std::cin >> input2;
		std::cout << "Customer's Name: ";
		std::cin >> input3;
		bank.AddCustomer(input4, input2, input3);
		std::cout << '\n';
		break;
	case 3:
		std::cout << "Customer's id: ";
		std::cin >> input4;
		bank.DeleteCustomer(input4);
		std::cout << '\n';
		break;
	case 4:
		bank.ListAccounts();
		std::cout << '\n';
		break;
	case 5:
		std::cout << "User's Id To Inspect: ";
		std::cin >> input7;
		bank.ListCustomerAccounts(input7);
		std::cout << '\n';
		break;
	case 6:
		std::cout << "Select Account type:\n";
		std::cout << "0 - Current\n";
		std::cout << "1 - Savings\n";
		std::cout << "2 - Privilege\n";
		std::cin >> input5;
		std::cout << '\n';
		if (!ValidateAccountType(input5))
		{
			std::cout << "Unknown Account Type!\n";
			std::cout << "Operation Failed\n";
			break;
		}
		else
		{
			input6 = static_cast<AccountType>(input5);
		}
		std::cout << "Select Account IBAN: ";
		std::cin >> input4;
		std::cout << "Select Customer's ID: ";
		std::cin >> input7;
		std::cout << "Select Amount: ";
		std::cin >> input1;
		bank.AddAccount(input6, input4, input7, input1);
		std::cout << '\n';
		break;
	case 7:
		std::cout << "Select The IBAN Of The Account For Removal: ";
		std::cin >> input7;
		bank.DeleteAccount(input7);
		std::cout << '\n';
		break;
	case 8:
		std::cout << "Select The IBAN Of The Account For Withdrawal: ";
		std::cin >> input7;
		std::cout << "Select Amount To Withdraw: ";
		std::cin >> input1;
		bank.Withdraw(input7, input1);
		std::cout << '\n';
		break;
	case 9:
		std::cout << "Select The IBAN Of The Account For Deposition: ";
		std::cin >> input7;
		std::cout << "Select Amount To Deposit: ";
		std::cin >> input1;
		bank.Deposit(input7, input1);
		std::cout << '\n';
		break;
	case 10:
		std::cout << "Select From IBAN: ";
		std::cin >> input4;
		std::cout << "Select In IBAN: ";
		std::cin >> input7;
		std::cout << "Select Amount:";
		std::cin >> input1;
		std::cout << '\n';
		bank.Transfer(input4, input7, input1);
		break;
	case 11:
		bank.Display();
		break;
	case 12:
		break;
	default:
		std::cout << "Unknown character inserted\n";
		break;
	}
}