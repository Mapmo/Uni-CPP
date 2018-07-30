#pragma once
#include "Cell.h"

class Column
{
	char ConvertTypeToChar()const;//returns a char that represents the type of the column I, D or S
public:
	explicit Column(const int, const std::string&, const Type, const int);

	std::string GetCellValue(const unsigned int)const;//returns the value of the cell at the given position
	int GetNumber()const;
	const std::string& GetName()const;
	Type GetType()const;

	void SetCellValue(const unsigned int, const std::string&);

	void AddCell(const std::string& val= "NULL");
	void CoutType()const;//couts the name of the type
	void DeleteCell(const unsigned int);
	void ParseToString(std::string&)const;//transforms the given parameter to a string that represents the column, used in Table::ParseColumnsToString()
private:
	std::vector<Cell> m_Cells;//row number matches cell index
	int m_Number;
	Type m_Type;
	std::string m_Name;
};