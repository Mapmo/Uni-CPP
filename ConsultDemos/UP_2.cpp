#include <iostream>
#include <vector>

void Demo1Helper1(const std::vector<long long>a)
{
}
void Demo1Helper2(const std::vector<long long>&a)
{
}
void Demo1()
{
	std::vector<long long> bigData;//dinamichna versiq na masiv
	char a;
	for (unsigned i = 0; i < 100000; ++i)
		bigData.push_back(i);

	std::cout << "Press any button to start Demo1Helper1\n";
	std::cin >> a;
	for(unsigned i =0; i<10000; ++i)
	Demo1Helper1(bigData);
	std::cout << "Operation 1 Finished\n";

	std::cout << "Press any button to start Demo1Helper2\n";
	std::cin >> a;
	for (unsigned i = 0; i < 100000; ++i)
	Demo1Helper2(bigData);
	std::cout << "Operation 2 Finished\n";

	std::cout << "Even though DemoHelper2 is called 10 times more than DemoHelper1, it is still much faster, because it doesn't copy the data of the vector\n\n";
}


void swap1(double & a, double & b)
{
	double c = a;
	a = b;
	b = c;
}

int main()
{
	Demo1();
	return 0;
}