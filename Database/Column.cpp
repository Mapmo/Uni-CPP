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

Column::Column(const int numb, const std::string& name, const Type type, const int cells)
	: m_Number(numb), m_Name(name), m_Type(type), m_Cells(cells)
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

void Column::CoutType() const
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

void Column::AddCell(const std::string & val)
{
	this->m_Cells.push_back(Cell(val));
}

std::string Column::GetCellValue(const unsigned int numb) const
{
	std::string temp;
	if (numb >= m_Cells.size())
	{
		std::cerr << "Out of range\n";
		return temp;
	}
	else
	{
		temp = this->m_Cells[numb].GetValue();
		return temp;
	}
}

void Column::SetCellValue(const unsigned int numb, const std::string & val)
{
	if (numb >= m_Cells.size())
	{
		std::cerr << "Out of range\n";
	}
	else
	{
		this->m_Cells[numb].SetValue(val);
	}
}

void Column::DeleteCell(const unsigned int id)
{
	if (id >= m_Cells.size())
	{
		std::cerr << "Out of range\n";
	}
	else
	{
		this->m_Cells.erase(m_Cells.begin() + id);
	}
}

void Column::ParseToString(std::string & stringRef) const
{
	char type = ConvertTypeToChar();
	stringRef.push_back(type);
	stringRef += " " + this->m_Name+"\n";
	for (unsigned int i = 0; i < this->m_Cells.size(); ++i)
	{
		stringRef += this->m_Cells[i].GetValue() + "\n";
	}
	stringRef += "-----";
}
