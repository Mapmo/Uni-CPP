#include <iostream>
#include "BrowserHistory.h"

BrowserHistory::BrowserHistory(int length)
{
	this->m_Counter = 0;
	this->m_Memory = length;
	this->m_HistoryEntry = new HistoryEntry[length];
}

BrowserHistory::BrowserHistory(const BrowserHistory & old)
{
	this->m_Counter = old.m_Counter;
	this->m_Memory = old.m_Memory;
	this->m_HistoryEntry = new HistoryEntry[m_Memory];
	for (int i = 0; i < this->m_Counter; i++)
	{
		this->m_HistoryEntry[i].date = old.m_HistoryEntry[i].date;

		int length = 0;
		for (length; length<50; length++)
		{
			if (old.m_HistoryEntry[i].url[length] == '\0')
				break;
		}
		this->m_HistoryEntry[i].url = new char[length+1];
		this->m_HistoryEntry[i].url[length] = '\0';
		for (int j = 0; j < length; j++)
		{
			this->m_HistoryEntry[i].url[j] = old.m_HistoryEntry[i].url[j];
		}
	}
}

BrowserHistory::~BrowserHistory()
{
	for (int i = 0; i < this->m_Counter; i++)
	{
		delete[] this->m_HistoryEntry[i].url;
	}
	delete[] this->m_HistoryEntry;
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory&old)
{
	if (this != &old)
	{
		for (int i = 0; i < this->m_Counter; i++)
		{
			delete[] this->m_HistoryEntry[i].url;
		}
		delete[] this->m_HistoryEntry;

		this->m_Counter = old.m_Counter;
		this->m_Memory = old.m_Memory;
		this->m_HistoryEntry = new HistoryEntry[m_Memory];
		for (int i = 0; i < this->m_Counter; i++)
		{
			this->m_HistoryEntry[i].date = old.m_HistoryEntry[i].date;

			int length = 0;
			for (length; length<50; length++)
			{
				if (old.m_HistoryEntry[i].url[length] == '\0')
					break;
			}
			this->m_HistoryEntry[i].url = new char[length+1];
			this->m_HistoryEntry[i].url[length] = '\0';
			for (int j = 0; j < length; j++)
			{
				this->m_HistoryEntry[i].url[j] = old.m_HistoryEntry[i].url[j];
			}
		}
	}
	
	return *this;
}

void BrowserHistory::AddSite()
{
	if (this->m_Counter != this->m_Memory)	//if the memory is full it will not add more sites
	{
		HistoryEntry s; //temp struct used for the adding
		std::cout << "Insert Month" << std::endl;
		std::cin >> s.date;
		std::cin.ignore();
		char tempArr[51];	//temp static array used for getline to easily determine the length of the input
		for (int i = 0; i < 50; i++)
			tempArr[i] = ' ';
		std::cout << "Insert URL" << std::endl;
		std::cin.getline(tempArr, 50);
		tempArr[50] = '\0';

		int length = 0;
		for (length; length < 51; ++length)
		{
			if (tempArr[length] == ' ')
			{
				break;
			}
		}

		s.url = new char[length]; //the string we want to insert in the struct array
		for (int i = 0; i < length - 1; i++)
		{
			s.url[i] = tempArr[i];
		}
		s.url[length - 1] = '\0';

		this->m_HistoryEntry[this->m_Counter++] = s;//just inserts the struct in the array and then increments the counter
	}
	else
	{
		std::cout << "Memory Limit Reached" << std::endl;
	}
}

void BrowserHistory::AddSite(const HistoryEntry& s) //a simpler version of the method above
{
	if (this->m_Counter != this->m_Memory)
	{
		this->m_HistoryEntry[this->m_Counter++] = s;
	}
	else
	{
		std::cout << "Memory Limit Reached" << std::endl;
	}
}

void BrowserHistory::PrintAllSites() const //a simple printing method using 2 getters defined below
{
	for (int i = 0; i < m_Counter; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (GetHistoryEntrtyUrl(i, j) == '\0')
				break;
			std::cout << GetHistoryEntrtyUrl(i, j);
		}
		std::cout << " was visited in ";
		PrintMonthName(GetHistoryEntryDate(i));
		std::cout << std::endl;
	}
}

void BrowserHistory::PrintMostVisited(int s[12]) const //uses the method for finding the most visited months and prints it
{
	std::cout << "The most visited months are";
	for (int i = 0; i < 12; i++)
	{
		if (s[i] == 1)
		{
			std::cout << " ";
			PrintMonthName(i + 1);
		}
	}
	std::cout << std::endl;
	delete[] s;
}

void BrowserHistory::PrintMonthName(int s) const
{
	switch (s)
	{
	case 1:
		std::cout << "January";
		break;
	case 2:
		std::cout << "February";
		break;
	case 3:
		std::cout << "March";
		break;
	case 4:
		std::cout << "April";
		break;
	case 5:
		std::cout << "May";
		break;
	case 6:
		std::cout << "June";
		break;
	case 7:
		std::cout << "July";
		break;
	case 8:
		std::cout << "August";
		break;
	case 9:
		std::cout << "September";
		break;
	case 10:
		std::cout << "October";
		break;
	case 11:
		std::cout << "November";
		break;
	case 12:
		std::cout << "December";
		break;
	default:
		std::cout << "Something is wrong with PrintMonthName";
		break;
	}
}

void BrowserHistory::RemoveLastAdded()
{
	delete[] m_HistoryEntry[--m_Counter].url;
}

void BrowserHistory::SetCounter(const int a)
{
	this->m_Counter = a;
}

void BrowserHistory::SetHistoryEntry(const int a)
{
	this->m_HistoryEntry = new HistoryEntry[a];
}

void BrowserHistory::SetHistoryEntryDate(const int i, const int a)
{
	this->m_HistoryEntry[i].date = a;
}

void BrowserHistory::SetHistoryEntryUrl(const int i, const int a)
{
	this->m_HistoryEntry[i].url = new char[a];
}

void BrowserHistory::SetHistoryEntryUrl(const int i, const int j, const char a)
{
	this->m_HistoryEntry[i].url[j] = a;
}

void BrowserHistory::SetMemory(const int a)
{
	this->m_Memory = a;
}

char BrowserHistory::GetHistoryEntrtyUrl(int i, int j) const
{
	return this->m_HistoryEntry[i].url[j];
}

int BrowserHistory::FindMonthCount(int n) const //nothing special here
{
	int counter = 0;
	for (int i = 0; i < this->m_Counter; i++)
	{
		if (this->m_HistoryEntry[i].date == n)
		{
			counter++;
		}
	}
	return counter;
}

int * BrowserHistory::FindMostVisitedMonth() const //pointer because there may be more than 1 months :(
{
	int * mostVisitedMonth = new int[12]; //the arr we return, every index+1 == the month in the calendar
	int mostVisitedMonthCount = 0;

	for (int i = 0; i < 12; i++)
	{
		mostVisitedMonth[i] = 0;
	}
	for (int i = 0; i < 12; i++)
	{
		if (FindMonthCount(i + 1) > mostVisitedMonthCount)
		{
			mostVisitedMonthCount = FindMonthCount(i + 1);
		}
	}
	for (int i = 0; i < 12; i++)		//every month with most sites visited will be returned with value 1 (calendar value -1)
	{
		if (FindMonthCount(i + 1) == mostVisitedMonthCount)
		{
			mostVisitedMonth[i] = 1;
		}
	}
	return mostVisitedMonth;
}

int BrowserHistory::GetCounter() const
{
	return this->m_Counter;
}

int BrowserHistory::GetHistoryEntryDate(int i) const
{
	return this->m_HistoryEntry[i].date;
}

int BrowserHistory::GetMemory()const
{
	return this->m_Memory;
}

BrowserHistory BrowserHistory::ConcatHistories(const BrowserHistory & b)
{
	BrowserHistory c(0);
	c.SetMemory(this->m_Memory + b.m_Memory);
	c.SetCounter(this->m_Counter + b.m_Counter);
	c.SetHistoryEntry(c.GetMemory());
	for (int i = 0; i < this->m_Counter; i++)
	{
		c.SetHistoryEntryDate(i, this->m_HistoryEntry[i].date);
		int length = 0;
		for (int j = 0; j < 50; j++)
		{
			length++;
			if (this->m_HistoryEntry[i].url[j] == '\0')
			{
				break;
			}
		}
		c.SetHistoryEntryUrl(i, length);
		for (int j = 0; j < 50; j++)
		{
			c.SetHistoryEntryUrl(i, j, this->m_HistoryEntry[i].url[j]);
			if (this->m_HistoryEntry[i].url[j] == '\0')
			{
				break;
			}
		}
	}
	for (int i = this->m_Counter; i < c.GetCounter(); i++)
	{
		c.SetHistoryEntryDate(i, b.m_HistoryEntry[i - this->m_Counter].date);
		int length = 0;
		for (int j = 0; j < 50; j++)
		{
			length++;
			if (b.m_HistoryEntry[i - this->m_Counter].url[j] == '\0')
			{
				break;
			}
		}
		c.SetHistoryEntryUrl(i, length);
		for (int j = 0; j < 50; j++)
		{
			c.SetHistoryEntryUrl(i, j, b.m_HistoryEntry[i - this->m_Counter].url[j]);
			if (b.m_HistoryEntry[i - this->m_Counter].url[j] == '\0')
			{
				break;
			}
		}
	}

	return c;
}
