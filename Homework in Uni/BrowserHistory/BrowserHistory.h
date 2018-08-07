#pragma once
#include "Structures.h"
class BrowserHistory
{
private:
	int m_Counter;								//tells how many elements there are in the m_HistoryArray
	int m_Memory;
	HistoryEntry * m_HistoryEntry;
public:
	BrowserHistory(int);						//the required constructor
	BrowserHistory(const BrowserHistory &);		//copy constructor
	~BrowserHistory();							//destructor
	BrowserHistory& operator = (const BrowserHistory&); //please work
	void AddSite();								//no param adding method
	void AddSite(const HistoryEntry&);			//param addding method
	void PrintAllSites() const;					//prins all the sites
	void PrintMostVisited(int[12])const;		//uses the FindMostVisitedMonth method to print months with most visits
	void PrintMonthName(int) const;				//prins the name of the given month
	void RemoveLastAdded();						//removes the last added site
	void SetCounter(int);
	void SetHistoryEntry(int);					//names are obvious
	void SetHistoryEntryDate(int, int);
	void SetHistoryEntryUrl(int, int);			//the double int function is for initializing the array elements
	void SetHistoryEntryUrl(int, int, char);			//assigns chars to the arr elements
	void SetMemory(int);
	char GetHistoryEntrtyUrl(int, int) const;	//getter used to get the name of the url from the struct, returning char by char
	int FindMonthCount(int) const;				//method returning the number of sites visited in the given month
	int * FindMostVisitedMonth() const;			//returns the number of the most visited month
	int GetCounter() const;						//returns the m_Counter of a class
	int GetHistoryEntryDate(int) const;			//getter used to get the browserEntry.date of a struct
	int GetMemory()const;						//returns the m_Memory of a browser class
	BrowserHistory ConcatHistories(const BrowserHistory&);//returns 1 object as concatination of two others
};