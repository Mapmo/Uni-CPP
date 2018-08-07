#include "ElectricNet.h"
#include <iostream>
int main()
{
	ElectricNet net;
	char c;
	String input1;
	int input2;

	while (1)
	{
		std::cout << "A - add device\n";
		std::cout << "R - remove device\n";
		std::cout << "P - print device info\n";
		std::cout << "I - check if the net is empty\n";
		std::cout << "D - double the net power\n";
		std::cout << "H - halve the net power\n";
		std::cout << "E - exit the program\n";
		std::cin >> c;
		switch (c)
		{
		case 'a':
		case 'A':
		{
			std::cout << "Select device name\n";
			std::cin >> input1;
			std::cout << "Select device power\n";
			std::cin >> input2;
			ElectricDevice tmp(input1, input2);
			net += tmp;
			break;
		}
		case 'r':
		case'R':
		{
			std::cout << "Select device name\n";
			std::cin >> input1;
			ElectricDevice tmp(input1, 0);
			net -= tmp;
			break;
		}
		case 'p':
		case 'P':
		{
			std::cout << "Select device name\n";
			std::cin >> input1;
			net[input1];
			break;
		}
		case 'i':
		case 'I':
		{
			!net?std::cout<<"The net is not empty\n":std::cout<<"The net is empty\n";
			break;
		}
		case 'd':
		case 'D':
		{
			++net;
			break;
		}
		case 'h':
		case 'H':
		{
			--net;
			break;
		}
		case 'e':
		case 'E':
		{
			return 0;
		}
		default:
		{
			std::cout << "Key not recognized\n";
		}
		}
	}
}