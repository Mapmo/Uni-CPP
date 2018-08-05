#include "MenuFunctions.h"

int main()
{
	//variables used for test cases
	Bank KTB("Prajka Prolet", "KTB");
	short int input = 0;
	double input1 = 0;
	std::string input2;
	std::string input3;
	unsigned int input4 = 0;
	short int input5 = 0;
	AccountType input6 = Current;
	unsigned int input7 = 0;
	
	while (input != 12)
	{
		DisplayMenu();
		std::cin >> input;
		ExecuteCommand(input, input1, input2, input3, input4,input5,input6,input7 ,KTB);
	}
	
	return 0;
}