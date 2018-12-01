#include <iostream>
#include <vector>

void Task1(const int arr[], const unsigned size)
{
	//Print the sum of the members of the array
}
void Task2(const int arr[], const unsigned size)
{
	//Print the sum of the even members of the array
}
void Task3(const int arr[], const unsigned size)
{
	//Print the biggest member of the array
}
void Task4(const int arr[], const unsigned size)
{
	//Print the biggest uneven member of the array
}
void Task5(const int arr[], const unsigned size)
{
	//Print the smallest even member of the array
}
void Task6(const int arr[], const unsigned size)
{
	//Print the sum of the even members of the array
}
void Task7(const int arr[], const unsigned size)
{
	//Print the biggest member with even index in the array
}
void Task8(const int arr[], const unsigned size)
{
	//Print the sum of the members with uneven indexes in the array
}
void Task9(const int arr[], const unsigned size)
{
	//Print the array in reverse
}
void Task10(const int arr[], const unsigned size)
{
	//Print "Yes" if there are 2 equal adjacent members and "No" if there aren't
}
void Task11(int arr[], const unsigned size)
{
	//Reverse the signs of the members of the array
}
void Task12(const int arr[], const unsigned size)
{
	//Compare whether there are more even than uneven members in the array
}
void Task13(int arr[], const unsigned size)
{
	//Increment the uneven members of the array
}
void Task14(int arr[], const unsigned size)
{
	//Reverse the sign of the positive members of the array
}
void Task15(const int arr[], const unsigned size, const unsigned numb)
{
	//Print "Yes" if numb is a member of the array or "No" if it isn't
}
unsigned Task16(const char arr[])
{
	//implement strlen
}
void Task17(char arr[], const unsigned)
{
	//replace all l symbols with 1(one)
}
void Task18(const char arr[], const unsigned)
{
	//Print "Yes" if the array contains U & P
}
void Task19(char arr[], const unsigned)
{
	//go to lowercase
}
void Task20(char arr[], const unsigned)
{
	//go to uppercase
}
int main()
{
	int arr[] = { 2, -4, 11, 5, 10, -2, 3, 4, -1, -3, 5, 5 };

	unsigned size = sizeof(arr) / sizeof(arr[0]);
	Task1(arr, size);
	Task2(arr, size);
	Task3(arr, size);
	Task4(arr, size);
	Task5(arr, size);
	Task6(arr, size);
	Task7(arr, size);
	Task8(arr, size);
	Task9(arr, size);
	Task10(arr, size);
	Task11(arr, size);
	Task12(arr, size);
	Task13(arr, size);
	Task14(arr, size);
	int numb = 5;
	Task15(arr, size, numb);

	char cstr[] = "Algebra is the coolest subject ever!!!";
	unsigned size2 = Task16(cstr);
	Task17(cstr, size2);
	Task18(cstr, size2);
	Task19(cstr, size2);
	Task20(cstr, size2);

	return 0;
}