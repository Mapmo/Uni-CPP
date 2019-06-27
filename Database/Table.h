#pragma once
#include "Column.h"
#include "PageToPrint.h"

enum Operation {SUM, PRODUCT, MAXIMUM, MINIMUM}; //used for AggregateTable() and PerformOperation()

class Table
{
	std::vector<int> GetCellPositions(const unsigned, const std::string&)const;
	bool CheckNameAvailability(const std::string&) const;
	void DeleteRow(const int);
	template <class T>
	T PerformOperation(const T, const T, const Operation);//works with double and int and returns the given operation with the 2 T parameters 
	unsigned GetRowLength(const unsigned)const;//returns how many lines a row will need to be printed + 1
	unsigned RoundTo80(const unsigned)const;//used by GetRowLength() to convert the number of chars neeeded by the row into console lines
	void CreatePages(std::vector<PageToPrint>&)const;//calls CreatePage() until all rolls have a page
	PageToPrint CreatePage(const unsigned)const; //calls GetRowLength() as many times as need to create pages for all rows
	void PrintRow(const unsigned)const;//prints the info of the row that the parameter represents with some decoration
	void PrintPage(const unsigned, const unsigned)const;//calls PrintRow() as many times as the difference between the 2 parameters is
	void PrintMenu(const char,unsigned&, const unsigned)const;//used to display the menu for page swapping of Print()
public:
	explicit Table(const std::string&);
	void AddColumn(const std::string&, Type);
	void Select(const int, const std::string&)const; //prints all row numbers that match the select info
	void Update(const int, const std::string&, const int, const std::string&);//uses GetCellPositions() and then updated value
	void Delete( const int, const std::string&);//uses GetCellPositions() and then deletes the given rows, calling DeleteRow()
	void Insert(const char*, ...);//take as many parameters as columns there are in the table, uses variadic parameters, well commented definition
	void Rename(const std::string&);
	int Count(const int, const std::string&)const;//uses GetCellPositions()
	void Aggregate(const int, const std::string&, const int, const Operation);//uses GetCellPositions(), then uses PerformOperation on the selected items, and then uses Column::SetCellValue() to update the value of the target column's cell that were selected by GetCellPositions()
	void Print()const;//masterpiece that prints the table info

	Type GetColumnType(const unsigned)const;
	unsigned GetColumnsSize()const;
	const std::string& GetColumnName(const unsigned)const;
	std::string GetColumnCellValue(const unsigned, const unsigned)const;
	const std::string& GetName()const;
	unsigned GetRows()const;

	void SetColumnCellValue(const unsigned, const unsigned, const std::string&);

	void AddColumnCell(const unsigned, const std::string&);
	void IncrementRows();
	std::string ParseColumnsToString()const;//calls Column::ParseToString() for each column in the table and returns a huge string
	void PrintColumnsTypes() const;
	bool ValidateDataType(const std::string&, const Type)const;//checks if the string can be converted to the given type
private:
	std::vector<Column> m_Columns;
	unsigned m_Rows;
	std::string m_Name;
};

template<class T>
inline T Table::PerformOperation(const T searchValue, const T targetValue, const Operation operation)
{
	if (operation == SUM)
	{
		return searchValue + targetValue;
	}
	else if (operation == PRODUCT)
	{
		return searchValue * targetValue;
	}
	else if (operation == MAXIMUM)
	{
		return (searchValue < targetValue) ? targetValue : searchValue;
	}
	else
	{
		return (searchValue > targetValue) ? targetValue : searchValue;
	}
}