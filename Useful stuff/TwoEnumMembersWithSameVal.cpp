#include <iostream>
enum age { Medieval, ModernTimes = 0 };
//Medieval == 0 and ModernTimes == 0
int main()
{
	age before = Medieval;
	age now = ModernTimes;

	std::cout << (before == now ? 1 : 2);//will cout 1

	//it is perfectly valid to have 2 enum members with the same value
	return 0;
}