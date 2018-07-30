#include "Table.h"

std::vector<int> Table::HiddenSelect(const unsigned int numb, const std::string & val) const
{
	std::vector<int> temp;
	//if the index is oor it will return vector with -1 so the other functions know not to proceed
	if (numb >= this->m_Columns.size())
	{
		std::cerr << "Operation Select is Out of Range, ";
		std::cerr << "Operation Select Failed, Before Started\n";
		temp.push_back(-1);
	}
	else
	{
		for (unsigned int i = 0; i < m_Rows; ++i)
		{
			if (this->m_Columns[numb].GetCellValue(i) == val)
			{
				temp.push_back(i);
			}
		}
	}
	return temp;
}

bool Table::CheckNameAvailability(const std::string & rhs) const
{
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		if (rhs == this->m_Columns[i].GetName())
			return false;
	}
	return true;
}

bool Table::ValidateDataType(const std::string & val, const Type type) const
{
	if (type == String)
	{
		return true;
	}
	bool dotUsed = false;
	if (type == Int)
	{
		dotUsed = true;
	}
	for (unsigned int i = 0; i < val.size(); ++i)
	{
		if (val[i]<'0' || val[i]>'9')
		{
			if (val[i] == '.' && !dotUsed)
			{
				dotUsed = true;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

void Table::DeleteRow(const int numb)
{
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		this->m_Columns[i].DeleteCell(numb);
	}
}

unsigned int Table::GetRowLength(const unsigned int rhs) const
{
	unsigned int numb = 0;
	//for every column get the size of the column name + the length of the cell value for that row in every column + 4  for the decorations | : ' ' | 
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		numb += this->m_Columns[i].GetName().size() + this->m_Columns[i].GetCellValue(rhs).size() + 4;
	}
	//round it to lines and have 1 line for separation betweeen different rows
	return RoundTo80(numb);
}

unsigned int Table::RoundTo80(const unsigned int rhs) const
{
	unsigned int i = 1;
	while (i * 80 < rhs)
		++i;
	return i + 1;
}

void Table::CreatePages(std::vector<PageToPrint>& tmp) const
{
	unsigned int next = 0;
	while (next < this->m_Rows)//next indicates the index of the row that will be first on the next page
	{
		tmp.push_back(CreateAPage(next));
		next = tmp[tmp.size() - 1].GetEnd();
	}
}

PageToPrint Table::CreateAPage(const unsigned int beg) const
{
	//function that calls GetRowLength as many times as it needs to fill up the console(26 is the max, cuz the last line of every row is used to separate it from the line below)
	//end is actually the beginning of the next page and it is not part of this page, it is easy for loops later e.g while( i< a.GetEnd() )
	unsigned int i = 0;
	unsigned int end = beg;
	while (i < 20 && end < this->m_Rows)
	{
		i += GetRowLength(end++);
	}
	return PageToPrint(beg, end);
}

void Table::PrintAPage(const unsigned int beg, const unsigned int end) const
{
	for (unsigned int i = beg; i < end; ++i)
	{
		PrintARow(i);
	}
}

void Table::PrintMenu(const char command, unsigned int & pointer, const unsigned int pageSize) const
{
	//takes the unsigned int pointer from Print() by refference and modifies its value if it is possible 
	switch (command)
	{
	case 'p':
	case 'P':
	{
		if (pointer == 0)
		{
			std::cerr << "This Is The First Page, Can't Go Before That\n";
		}
		else
		{
			--pointer;
		}
		break;
	}
	case 'n':
	case 'N':
	{
		if (pointer == pageSize - 1)
		{
			std::cerr << "This Is The Last Page, Can't Go After That\n";
		}
		else
		{
			++pointer;
		}
		break;
	}
	case 'e':
	case 'E':
		break;
	default:
		std::cerr << "Unknown Command\n";
	}
}

void Table::PrintARow(const unsigned int numb) const
{
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		std::cout << '|' << this->m_Columns[i].GetName() << ": " << this->m_Columns[i].GetCellValue(numb) << '|';
	}
	//decorative line separator
	std::cout << std::endl;
	for (int i = 0; i < 80; ++i)
		std::cout << '-';
}

Table::Table(const std::string & name) : m_Name(name), m_Columns(), m_Rows(0)
{
}

void Table::AddColumn(const std::string & name, Type type)
{
	int number = m_Columns.size();
	if (CheckNameAvailability(name))
	{
		this->m_Columns.push_back(Column(number, name, type, this->m_Rows));
	}
	else
	{
		std::cerr << "Name unavailable, try again\n";
	}
}

void Table::Select(const int numb, const std::string & val) const
{
	std::vector<int> selected = HiddenSelect(numb, val);
	if (selected.size() != 0)
	{
		if (selected[0] == -1)
			return;
	}
	std::cout << "The rows whose column " << numb << " contains " << val << " are:\n";
	for (unsigned int i = 0; i < selected.size(); ++i)
	{
		std::cout << selected[i] << "\n";
	}
}

void Table::Update(const int srNumb, const std::string &srVal, const int upNumb, const std::string & upVal)
{
	std::vector<int> selected = HiddenSelect(srNumb, srVal);//rows to be updated
	if (selected.size() != 0)
	{
		if (selected[0] == -1)
			return;
	}
	for (unsigned int i = 0; i < selected.size(); ++i)
	{
		this->m_Columns[upNumb].SetCellValue(selected[i], upVal);
	}
}

void Table::Delete(const int numb, const std::string & val)
{
	std::vector<int> selected = HiddenSelect(numb, val);
	if (selected.size() != 0)
	{
		if (selected[0] == -1)
			return;
	}
	for (int i = selected.size() - 1; i >= 0; --i)//moves backwards so that it avoids heap corruption due to vector resize
	{
		DeleteRow(selected[i]);
	}
}

void Table::Insert(const char* rhs, ...)
{
	//c++ is completely helpless to guarantee that enough parameters have been passed, so I cannot prevent access violation due to 
	//bad argument input, if the arguments are not enough, then the program will explode!!!
	//i wanted to have a separate function to validate the data for insert, but i was unable to find a way to pass variable arguments
	va_list args;
	va_start(args, rhs);//this means that rhs is the last known argument


	std::string tmp = rhs;//will be used to contain the value of va_arg

	//tmp starts with rhs and va_arg() starts with the argument after rhs, so this means that va_arg will always be 1 parameter ahead 
	//and needs to stop 1 step earlier in the for loop

	//the code below validates that all data's type matches the column type 
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		if (!ValidateDataType(tmp, this->m_Columns[i].GetType()))
		{
			std::cerr << "Insert Operation Impossible Due To Bad Input\n";
			va_end(args);
			return;
		}
		if (i != this->m_Columns.size() - 1)//tmp moves one step ahed, so it needs to stop earlier
		{
			tmp = va_arg(args, const char*);
		}
	}
	va_end(args);
	//validation complete


	//now inserting the row in the table
	++this->m_Rows;
	va_list args2;
	va_start(args2, rhs);
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		this->m_Columns[i].AddCell(tmp);
		if (i != this->m_Columns.size() - 1)
		{
			tmp = va_arg(args2, const char*);//tmp2 moves one step ahed, so it needs to stop earlier
		}
	}
}

void Table::Rename(const std::string & rhs)
{
	this->m_Name = rhs;
}

int Table::Count(const int numb, const std::string & val) const
{
	std::vector<int> selected = HiddenSelect(numb, val);
	if (selected.size() != 0)
	{
		if (selected[0] == -1)
			return -1;
	}
	return selected.size();
}

void Table::Aggregate(const int srNumb, const std::string & srVal, const int trNumb, const Operation opera)
{
	if (this->m_Columns[trNumb].GetType() != String && this->m_Columns[srNumb].GetType() != String)
	{
		std::vector<int> selected = HiddenSelect(srNumb, srVal);
		if (selected.size() != 0)
		{
			if (selected[0] == -1)
				return;
		}
		std::string UpdatedValue;
		for (unsigned int i = 0; i < selected.size(); ++i)
		{
			if (this->m_Columns[trNumb].GetType() == Int)
			{
				int tmp1 = stoi(srVal);
				int tmp2 = stoi(this->m_Columns[trNumb].GetCellValue(selected[i]));
				int valueAfterOpera = Opera(tmp1, tmp2, opera);
				UpdatedValue = std::to_string(valueAfterOpera);
			}
			else
			{
				double tmp1 = stod(srVal);
				double tmp2 = stod(this->m_Columns[trNumb].GetCellValue(selected[i]));
				double newTrVal = Opera(tmp2, tmp2, opera);
				UpdatedValue = std::to_string(newTrVal);
			}
			this->m_Columns[trNumb].SetCellValue(selected[i], UpdatedValue);
		}
	}
	else
	{
		std::cout << "Aggregate does not support operations with string values\n";
		return;
	}
}

void Table::Print() const
{
	std::vector<PageToPrint> pages;//look at PageToPrint.h to understand the idea of PageToPrint
	CreatePages(pages);//create the pages and insert them in the pages vector above, after that it allows the user to swap between the pages
	unsigned int pointer = 0;
	char command = '0';
	while (command != 'e' && command != 'E')
	{
		PrintAPage(pages[pointer].GetBegin(), pages[pointer].GetEnd());
		std::cout << "Press n for next page\nPress p for previous page\nPress e to exit\n";
		std::cin >> command;
		PrintMenu(command, pointer, pages.size());
	}
}

const std::string & Table::GetName() const
{
	return this->m_Name;
}

void Table::PrintColumnsTypes() const
{
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		std::cout << "Column name: " << this->m_Columns[i].GetName() << " is ";
		m_Columns[i].CoutType();
	}
}

Type Table::GetColumnType(const unsigned int numb) const
{
	return this->m_Columns[numb].GetType();
}

unsigned int Table::GetColumnsSize() const
{
	return this->m_Columns.size();
}

const std::string & Table::GetColumnName(const unsigned int numb) const
{
	return this->m_Columns[numb].GetName();
}

std::string Table::GetColumnCellValue(const unsigned int numb, const unsigned int numb2) const
{
	return this->m_Columns[numb].GetCellValue(numb2);
}

void Table::SetColumnCellValue(const unsigned int colNumb, const unsigned int cellNumb, const std::string & val)
{
	this->m_Columns[colNumb].SetCellValue(cellNumb, val);
}

void Table::AddColumnCell(const unsigned int numb, const std::string & rhs)
{
	this->m_Columns[numb].AddCell(rhs);
}

int Table::GetRows() const
{
	return this->m_Rows;
}

void Table::IncrementRows()
{
	++this->m_Rows;
}

std::string Table::ParseColumnsToString() const
{
	std::string stringRef;
	for (unsigned int i = 0; i < this->m_Columns.size(); ++i)
	{
		this->m_Columns[i].ParseToString(stringRef);
		if (i != this->m_Columns.size() - 1)
		{
			stringRef += "\n";
		}
	}
	return stringRef;
}
