#include "Column.h"

char Column::ConvertTypeToChar() const
{
	switch (this->m_Type)
	{
	case String:
		return 'S';
		break;
	case Int:
		return 'I';
		break;
	case Double:
		return 'D';
		break;
	defalt:
		return 'E';
		break;
	}
}

Column::Column(const int number, const std::string& name, const Type type, const int cells)
	: m_Number(number), m_Name(name), m_Type(type), m_Cells(cells)
{
}

int Column::GetNumber() const
{
	return this->m_Number;
}

const std::string & Column::GetName() const
{
	return this->m_Name;
}

Type Column::GetType() const
{
	return this->m_Type;
}

void Column::CoutTypeName() const
{
	switch (this->m_Type)
	{
	case Int:
		std::cout << "int\n";
		break;
	case Double:
		std::cout << "double\n";
		break;
	case String:
		std::cout << "string\n";
		break;
	}
}

void Column::AddCell(const std::string & value)
{
	this->m_Cells.push_back(Cell(value));
}

std::string Column::GetCellValue(const unsigned position) const
{
	std::string temp;
	if (position >= m_Cells.size())
	{
		std::cerr << "Out of range\n";
		return temp;
	}
	else
	{
		temp = this->m_Cells[position].GetValue();
		return temp;
	}
}

void Column::SetCellValue(const unsigned position, const std::string & value)
{
	if (position >= m_Cells.size())
	{
		std::cerr << "Out of range\n";
	}
	else
	{
		this->m_Cells[position].SetValue(value);
	}
}

void Column::DeleteCell(const unsigned position)
{
	if (position >= m_Cells.size())
	{
		std::cerr << "Out of range\n";
	}
	else
	{
		this->m_Cells.erase(m_Cells.begin() + position);
	}
}

void Column::ConvertToString(std::string & targetReference) const
{
	char type = ConvertTypeToChar();
	targetReference.push_back(type);
	targetReference += " " + this->m_Name+"\n";
	for (unsigned i = 0; i < this->m_Cells.size(); ++i)
	{
		targetReference += this->m_Cells[i].GetValue() + "\n";
	}
	targetReference += "-----";
}
