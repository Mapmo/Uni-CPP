#pragma once
int strlen(char * a)
{
	int i = 0;
	if (a != nullptr)
	{
		a[i];
		while (a[i] != '\0')
		{
			i++;
		}
	}
	
	return i;
}

void PrintCharArr(const char * a)
{
	int i = 0;
	if (a != nullptr)
	{
		while (a[i] != '\0')
		{
			std::cout << a[i++];
		}
	}
		std::cout << std::endl;
}