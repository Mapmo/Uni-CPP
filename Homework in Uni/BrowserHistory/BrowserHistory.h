#pragma once
#include "Structures.h"
class BrowserHistory
{
private:
	int m_Counter;//tells how many elements there are in m_HistoryEntry
	int m_Memory;
	HistoryEntry * m_HistoryEntry;
public:
	BrowserHistory(const int);
	BrowserHistory(const BrowserHistory &);
	BrowserHistory& operator = (const BrowserHistory&);
	~BrowserHistory();

	void AddSite();
	void AddSite(const HistoryEntry&);
	void PrintAllSites() const;
	void PrintMostVisited(const bool*)const;		//uses the FindMostVisitedMonth method to print months with most visits
	void PrintMonthName(const int) const;				//prints the name of the given month
	void RemoveLastAdded();
	void SetCounter(const int);
	void SetHistoryEntry(const int);
	void SetHistoryEntryDate(const int, const int);
	void SetHistoryEntryUrl(const int, const int);	//the double int function is for initializing the array elements
	void SetHistoryEntryUrl(const int, const int, const char);			//assigns chars to the arr elements
	void SetMemory(const int);
	const char*GetHistoryEntrtyUrl(const int) const;	//getter used to get the name of the url from the struct
	int FindMonthCount(const int) const;				//method returning the number of sites visited in the given month
	bool*FindMostVisitedMonth() const;			//returns the number of the most visited month
	int GetCounter() const;						//returns the m_Counter of a class
	int GetHistoryEntryDate(const int) const;			//getter used to get the browserEntry.date of a struct
	int GetMemory()const;						//returns the m_Memory of a browser class
	BrowserHistory ConcatHistories(const BrowserHistory&);//returns 1 object as concatination of two others
};
