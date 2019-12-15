#include <iostream>

unsigned strlen(const char* arr)
{
	int i = 0;
	while(arr[i++] != '\0');
	
	return i -1;
}

bool IsPalindrome(const char* arr, const unsigned size)
{
	for(int i = 0; i < size/2; )
	{
		if(arr[i] != arr[size - ++i])
		{
			return false;
		}
	}
	return true;
}

int CheckSteps(const char* arr, const unsigned start, const unsigned end, const int steps)
{
	if(IsPalindrome(arr + start, end - start + 1))
	{
		return steps;
	}

	int left = CheckSteps(arr, start + 1, end, steps+1);
	int right = CheckSteps(arr, start, end - 1, steps+1);

	return (left < right) ? left : right;
}

int main()
{
	char buffer [100];
	std::cin.getline(buffer, 100);
	std::cout<<CheckSteps(buffer, 0, strlen(buffer) - 1, 0 );

	return 0;

}
