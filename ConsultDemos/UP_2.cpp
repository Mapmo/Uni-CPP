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

void Demo4()
{
	//it's important to note that if we compile it in x64, the pointers will have 2 times bigger size
	int a[5] = { 5, 10 , 15, 20, 25 };
	int * b = a + 1;
	std::cout << "After creating a pointer to an element of an array, it points only to that element and it doesn't know it is in an array\n";
	std::cout << "The size of the \"new array\" is actually: " << sizeof(b) / sizeof(int);
	std::cout << "\n\nEven if we create a constant pointer to the beginning of the array, we won't make it behave like a real array\n";
	int *const c = a;
	std::cout << "The size of the \"new array\"  is again: " << sizeof(c) / sizeof(int);

	std::cout << "\n\nAprart from that we can do basicly everything that we want with a pointer: \n";

	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
		std::cout << *(b + i - 1) << ' ';

	std::cout << "\n\nAs you can see pointers have the cool ability to recognize negative index:\n";
	std::cout << b[-1];
}

void Demo5Helper(const int * arr, const unsigned size)
{
	for (unsigned i = 0; i < size; ++i)
	{
		std::cout << "arr[" << i << "] is " << arr[i] << '\n';
	}
}
void Demo5()//shows you how to pass an array as parameter
{
	int arr[4] = { 4,3,2,1 };
	Demo5Helper(arr, sizeof(arr) / sizeof(arr[0]));//the practice of sizeof(arr[0]) is sometimes better because you may forget what type arr is
}

void Demo6()//this is dangerous as there is no guarantee that the second arrays will be neighbours in the memory!
{
	int a[2][2];
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;

	for (unsigned i = 0; i < 4; ++i)
		std::cout << a[0][i] << ' ';
}

void Demo7Helper(int tmpArray[][10], const unsigned rowSize, const unsigned colSize)//takes a 2 dimensional array 10x10 and fills it with the multiplication table
{
	for (unsigned row = 1; row <= rowSize; ++row)
	{
		for (unsigned col = 1; col <= colSize; ++col)
		{
			tmpArray[row - 1][col - 1] = row * col;
		}
	}
	std::cout << "  |";
	for (unsigned i = 0; i < colSize; ++i)
		std::cout << i + 1 << "  ";
	std::cout << '\n';
	std::cout << "__|";
	for (unsigned i = 0; i < colSize*1.5; ++i)
		std::cout << "__";
	std::cout << '\n';

	for (unsigned i = 0; i < rowSize; ++i)
	{

		if (i + 1 < 10)
			std::cout << i + 1 << " |";
		else
			std::cout << i + 1 << '|';
		for (unsigned j = 0; j < colSize; ++j)
		{
			if (tmpArray[i][j] < 10)
				std::cout << tmpArray[i][j] << "  ";
			else
				std::cout << tmpArray[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
void Demo7()//creates an empty 2 dimensional array
{
	int a[9][10];
	Demo7Helper(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]) / sizeof(a[0][0]));
	//std::cout << sizeof(a) / sizeof(a[0])<<' '<<sizeof(a[0]) / sizeof(a[0][0]);
}
int main()
{
	//Demo1();
	//Demo2(4,5);
	//Demo3();
	//Demo4();
	//Demo5();
	//Demo6();
	//Demo7();

	return 0;
}