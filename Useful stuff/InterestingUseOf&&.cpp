#include <iostream>

int main()
{
	int * a = nullptr;
	int b;
	/*some people don't know that && will break if the first is false, they think that both sides of && will be executed
	and therefore they don't understand that statements like the one below are absolutely valid and safe

	under normal circumstances round(*a) will explode, because a is nullptr, but as we have a statement a!=nullptr,
	the round function will not be executed and the program won't crash
	*/
	if (a != nullptr && round(*a) <10)
		b = *a;
	else
		b = 1;
	std::cout << b;//b == 1
	return 0;
}