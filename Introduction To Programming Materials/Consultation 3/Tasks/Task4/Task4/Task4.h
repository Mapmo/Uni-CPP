#pragma once
const unsigned EnglishLetters = 26;

unsigned Strlen(const char * arr)
{
	unsigned counter = 0;
	while (arr[counter] != '\0')
	{
		++counter;
	}
	return counter;
}

void counting(const char * first, const char * second, int * firstLetters, int * secondLetters)
{
	for (unsigned i = 0; i < EnglishLetters; ++i)
	{
		firstLetters[i] = 0;
	}
	unsigned firstLength = Strlen(first);
	for (unsigned i = 0; i < firstLength; ++i)
	{
		++firstLetters[first[i] - 97];
	}

	for (unsigned i = 0; i < EnglishLetters; ++i)
	{
		secondLetters[i] = 0;
	}
	unsigned secondLength = Strlen(second);
	for (unsigned i = 0; i < secondLength; ++i)
	{
		++secondLetters[second[i] - 97];
	}
}
unsigned Task4(const char * first, const char * second)
{
	int firstLetters[EnglishLetters];
	int secondLetters[EnglishLetters];
	counting(first, second, firstLetters, secondLetters);

	unsigned sum = 0;
	int tmp = 0;

	for (unsigned i = 0; i < EnglishLetters; ++i)
	{
		tmp = firstLetters[i] - secondLetters[i];
		sum += tmp < 0 ? -tmp : tmp;
	}

	return sum;
}