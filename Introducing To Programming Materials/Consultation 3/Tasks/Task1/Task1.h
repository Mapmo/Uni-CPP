#pragma once
#include <iostream>

void ownSwap(int & a, int & b)
{
	if (a != b)
	{
		int swapper = a;
		a = b;
		b = swapper;
	}
}

void selectionSort(int * const arr, const int beg, const int size)
{
	for (unsigned i = beg; i < size; ++i)
	{
		int minInd = i;
		for (unsigned j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minInd])
			{
				minInd = j;
			}
		}
		ownSwap(arr[minInd], arr[i]);
	}
}
void Task1()
{
	int e;
	std::cin >> e;
	while (e--)
	{
		int n, tmp;
		std::cin >> n;
		int * const arr = new int[n];
		for (unsigned i = 0; i < n; ++i)
		{
			std::cin >> tmp;
			arr[i] = tmp;
		}
		selectionSort(arr, 0, n);
		unsigned negativeEnd = 0;
		while (arr[negativeEnd] < 0 && negativeEnd < n)
		{
			++negativeEnd;
		}
		unsigned positiveBegin = negativeEnd;
		while (arr[positiveBegin] == 0 && positiveBegin<n)
		{
			++positiveBegin;
		}
		int zerosCount = positiveBegin - negativeEnd; //if positiveBegin == negativeEnd, then there are 0 zeros, else there is at least 1

		int sum = 0;
		if (negativeEnd % 2 == 1 && negativeEnd != 0)
		{
			if (!zerosCount)
			{
				sum += arr[negativeEnd - 1];
			}
			--negativeEnd;
		}
		for (unsigned i = 0; i < negativeEnd; i += 2)
		{
			sum += arr[i] * arr[i + 1];
		}
		while (arr[positiveBegin] == 1)
		{
			++sum;
			++positiveBegin;
		}
		if ((n - positiveBegin) % 2 == 1 && positiveBegin < n)
		{
			sum += arr[positiveBegin];
			++positiveBegin;
		}
		for (unsigned i = positiveBegin; i < n; i += 2)
		{
			sum += arr[i] * arr[i + 1];
		}
		std::cout << sum << '\n';
		delete[] arr;
	}
}
