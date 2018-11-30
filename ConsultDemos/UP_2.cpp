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
	for (unsigned i = 0; i < 10000; ++i)
		Demo1Helper1(bigData);
	std::cout << "Operation 1 Finished\n";

	std::cout << "Press any button to start Demo1Helper2\n";
	std::cin >> a;
	for (unsigned i = 0; i < 100000; ++i)
		Demo1Helper2(bigData);
	std::cout << "Operation 2 Finished\n";

	std::cout << "Even though DemoHelper2 is called 10 times more than DemoHelper1, it is still much faster, because it doesn't copy the data of the vector\n\n";
}


void Demo2Helper(int & a, int & b)//equivalent to swap
{
	int c = a;
	a = b;
	b = c;
}
void Demo2(int left, int right)
{
	Demo2Helper(left, right);
	std::cout << left << ',' << right << "\n";
}
int & Demo3Helper(int & a)//will return a reference to a
{
	return a;
}
void Demo3()
{
	int a = 5;
	std::cout << "Print the value of the variable: a is " << Demo3Helper(a) << '\n';
	Demo3Helper(a) += 3;
	std::cout << "Alternate the value of the variable: a is " << a << '\n';
	int b = Demo3Helper(a);
	std::cout << "Create a new object that has the same value as the variable: b is " << b << '\n';
	b += 4;
	std::cout << "Alternate the new object without alternating the original: a is " << a << " and b is " << b << '\n';
	int & c = Demo3Helper(a);
	std::cout << "Create a new reference to a: c is " << c << '\n';
	c++;
	std::cout << "Alternate the new reference to alternate the original variable as well and not change the new object: a is " << a << ", b is " << b << " and c is " << c << '\n';
	std::cout << "Demo 3 is over\n";
}
int main()
{
	//Demo1();
	//Demo2(4,5);
	Demo3();
	return 0;
}