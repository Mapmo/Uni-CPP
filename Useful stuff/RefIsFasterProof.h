#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <vector>

template<typename T>
void CallTimeNeeded(T t, time_t a)
{
}

template<typename T>
void CallTimeNeededRef(T& t, time_t a)
{
}


int main()
{
	time_t a;
	std::vector<int>b;

	for (long long int i = 0; i < 200000; ++i)
	{
		b.push_back(i);
	}
	a = time(NULL);
	for (long long int i = 0; i < 20000; ++i)
	{
		CallTimeNeeded(b, a);
	}
	std::cout << "Time without ref " << time(NULL) - a << '\n';
	a = time(NULL);
	for (long long int i = 0; i < 20000; ++i)
	{
		CallTimeNeededRef(b, a);
	}
	std::cout << "Time with ref " << time(NULL) - a << '\n';


	return 0;
}

