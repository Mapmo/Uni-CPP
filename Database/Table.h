#pragma once
#include "Column.h"
#include "PageToPrint.h"

enum Operation {SUM, PRODUCT, MAXIMUM, MINIMUM }; //used for Aggregate() and Opera()

class Table
{
	std::vector<int> HiddenSelect(const unsigned int, const std::string&)const;//returns a vector with all the rows that contain the guven data in the given column
	bool CheckNameAvailability(const std::string&) const;
	void DeleteRow(const int);
	template <class T>
	T Opera(const T, const T, const Operation);//works with double and int and returns the given operation with the 2 T parameters 
	unsigned int GetRowLength(const unsigned int)const;//returns how many lines a row will need to be printed + 1
	unsigned int RoundTo80(const unsigned int)const;//used by GetRowLength() to convert the number of chars neeeded by the row into console lines
	void CreatePages(std::vector<PageToPrint>&)const;//calls CreateAPage() until all rolls have a page
	PageToPrint CreateAPage(const unsigned int)const; //calls GetRowLength() as many times as need to create pages for all rows
	void PrintARow(const unsigned int)const;//prints the info of the row that the parameter represents with some decoration
	void PrintAPage(const unsigned int, const unsigned int)const;//calls PrintARow() as many times as the difference between the 2 parameters is
	void PrintMenu(const char,unsigned int&, const unsigned int)const;//used to display the menu for page swapping of Print()
public:
	explicit Table(const std::string&);
	void AddColumn(const std::string&, Type);
	void Select(const int, const std::string&)const; //prints all row numbers that match the select info
	void Update(const int, const std::string&, const int, const std::string&);//uses HiddenSelect() and then updated value
	void Delete( const int, const std::string&);//uses HiddenSelect() and then deletes the given rows, calling DeleteRow()
	void Insert(const char*, ...);//take as many parameters as columns there are in the table, uses variadic parameters, well commented definition
	void Rename(const std::string&);
	int Count(const int, const std::string&)const;//uses HiddenSelect()
	void Aggregate(const int, const std::string&, const int, const Operation);//uses HiddenSelect(), then uses Opera on the selected items, and then uses Column::SetCellValue() to update the value of the target column's cell that were selected by HiddenSelect()
	void Print()const;//masterpiece that prints the table info

	Type GetColumnType(const unsigned int)const;
	unsigned int GetColumnsSize()const;
	const std::string& GetColumnName(const unsigned int)const;
	std::string GetColumnCellValue(const unsigned int, const unsigned int)const;
	const std::string& GetName()const;
	int GetRows()const;

	void SetColumnCellValue(const unsigned int, const unsigned int, const std::string&);

	void AddColumnCell(const unsigned int, const std::string&);
	void IncrementRows();
	std::string ParseColumnsToString()const;//calls Column::ParseToString() for each column in the table and returns a huge string
	void PrintColumnsTypes() const;
	bool ValidateDataType(const std::string&, const Type)const;//checks if the string can be converted to the given type
private:
	std::vector<Column> m_Columns;
	unsigned int m_Rows;
	std::string m_Name;
};

template<class T>
inline T Table::Opera(const T srVal, const T trVal, const Operation opera)
{
	if (opera == SUM)
	{
		return srVal + trVal;
	}
	else if (opera == PRODUCT)
	{
		return srVal * trVal;
	}
	else if (opera == MAXIMUM)
	{
		return (srVal < trVal) ? trVal : srVal;
	}
	else
	{
		return (srVal > trVal) ? trVal : srVal;
	}
}