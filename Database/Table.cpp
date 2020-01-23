#include "Table.h"

std::vector<int> Table::GetCellPositions(const unsigned column, const std::string & value) const
{
	std::vector<int> temp;
	//if the index is oor it will return vector with -1 so the other functions know not to proceed
	if (column >= this->m_Columns.size())
	{
		std::cerr << "Operation Select is Out of Range\n";
		std::cerr << "Operation Select Failed, Before Started\n";
		temp.push_back(-1);
	}
	else
	{
		for (unsigned i = 0; i < m_Rows; ++i)
		{
			if (this->m_Columns[column].GetCellValue(i) == value)
			{
				temp.push_back(i);
			}
		}
	}
	return temp;
}

bool Table::CheckNameAvailability(const std::string & nameToCheck) const
{
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		if (nameToCheck == this->m_Columns[i].GetName())
		{
			return false;
		}
	}

	return true;
}

bool Table::ValidateDataType(const std::string & value, const Type type) const
{
	if (type != String)
	{
		return true;
	}

	bool dotUsed = (type == Int ? true : false);

	for (unsigned i = 0; i < value.size(); ++i)
	{
		if (value[i]<'0' || value[i]>'9')
		{
			if (value[i] == '.' && dotUsed == false)
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
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		this->m_Columns[i].DeleteCell(numb);
	}
}

unsigned Table::GetRowLength(const unsigned position) const
{
	unsigned length = 0;
	//for every columnNumber get the size of the columnNumber name + the length of the cell value for that rowNumber in every columnNumber + 4  for the decorations | : ' ' | 
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		length += this->m_Columns[i].GetName().size() + this->m_Columns[i].GetCellValue(position).size() + 4;
	}
	//round it to lines and have 1 line for separation betweeen different rows
	return RoundTo80(length) + 1;
}

unsigned Table::RoundTo80(const unsigned length) const
{
	unsigned i = 1;

	while (i * 80 < length)
	{
		++i;
	}

	return i;
}

void Table::CreatePages(std::vector<PageToPrint>& temporalContainer) const
{
	unsigned next = 0;
	while (next < this->m_Rows)//next indicates the index of the rowNumber that will be first on the next page
	{
		temporalContainer.push_back(CreatePage(next));
		next = temporalContainer[temporalContainer.size() - 1].GetEnd();
	}
}

PageToPrint Table::CreatePage(const unsigned beginning) const
{
	//function that calls GetRowLength as many times as it needs to fill up the console(26 is the max, cuz the last line of every rowNumber is used to separate it from the line below)
	//end is actually the beginning of the next page and it is not part of this page, it is easy for loops later e.g while( iterator< a.GetEnd() )
	unsigned iterator = 0;
	unsigned end = beginning;
	while (iterator < 20 && end < this->m_Rows)
	{
		iterator += GetRowLength(end++);
	}
	return PageToPrint(beginning, end);
}

void Table::PrintPage(const unsigned beginning, const unsigned end) const
{
	for (unsigned i = beginning; i < end; ++i)
	{
		PrintRow(i);
	}
}

void Table::PrintMenu(const char command, unsigned & pointer, const unsigned pageSize) const
{
	//takes the unsigned pointer from Print() by refference and modifies its value if it is possible 
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

void Table::PrintRow(const unsigned position) const
{
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		std::cout << '|' << this->m_Columns[i].GetName() << ": " << this->m_Columns[i].GetCellValue(position) << '|';
	}

	//decorative line separator
	std::cout << std::endl;

	for (int i = 0; i < 80; ++i)
	{
		std::cout << '-';
	}
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

void Table::Select(const int number, const std::string & value) const
{
	std::vector<int> selected = GetCellPositions(number, value);
	if (selected.size() != 0)
	{
		if (selected[0] == -1)
		{
			return;
		}
	}

	std::cout << "The rows whose columnNumber " << number << " contains " << value << " are:\n";

	for (unsigned i = 0; i < selected.size(); ++i)
	{
		std::cout << selected[i] << "\n";
	}
}

void Table::Update(const int searchColumn, const std::string &searchValue, const int targetColumn, const std::string & targetValue)
{
	std::vector<int> rowsToUpdate = GetCellPositions(searchColumn, searchValue);

	if (rowsToUpdate.size() != 0)
	{
		if (rowsToUpdate[0] == -1)
		{
			std::cerr << "Update failed due to out of range query\n";
			return;
		}
	}

	for (unsigned i = 0; i < rowsToUpdate.size(); ++i)
	{
		this->m_Columns[targetColumn].SetCellValue(rowsToUpdate[i], targetValue);
	}
}

void Table::Delete(const int number, const std::string & value)
{
	std::vector<int> rowsToDelete = GetCellPositions(number, value);
	if (rowsToDelete.size() != 0)
	{
		if (rowsToDelete[0] == -1)
		{
			std::cerr << "Delete failed due to out of range query\n";
			return;
		}
	}
	for (int i = rowsToDelete.size() - 1; i >= 0; --i) //moves backwards so that it avoids heap corruption due to vector resize
	{
		DeleteRow(rowsToDelete[i]);
	}
}

void Table::Insert(const char* values, ...)
{
	//c++ is completely helpless to guarantee that enough parameters have been passed, so I cannot prevent access violation due to 
	//bad argument input, if the arguments are not enough, then the program will explode!!!
	//iterator wanted to have a separate function to validate the data for insert, but iterator was unable to find a way to pass variable arguments
	va_list args;
	va_start(args, values);//this means that nameToCheck is the last known argument


	std::string tmp = values;//will be used to contain the value of va_arg

	//temporalContainer starts with nameToCheck and va_arg() starts with the argument after nameToCheck, so this means that va_arg will always be 1 parameter ahead 
	//and needs to stop 1 step earlier in the for loop

	//the code below validates that all data's type matches the columnNumber type 
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		if (ValidateDataType(tmp, this->m_Columns[i].GetType()) == false)
		{
			std::cerr << "InsertIntoTable Operation Impossible Due To Bad Input\n";
			va_end(args);
			return;
		}

		if (i != this->m_Columns.size() - 1)//temporalContainer moves one step ahed, so it needs to stop earlier
		{
			tmp = va_arg(args, const char*);
		}
	}
	va_end(args);
	//validation complete


	//now inserting the rowNumber in the table
	++this->m_Rows;
	va_list args2;
	va_start(args2, values);
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		this->m_Columns[i].AddCell(tmp);
		if (i != this->m_Columns.size() - 1)
		{
			tmp = va_arg(args2, const char*);//tmp2 moves one step ahed, so it needs to stop earlier
		}
	}
}

void Table::Rename(const std::string & newName)
{
	this->m_Name = newName;
}

int Table::Count(const int searchColumn, const std::string & searchValue) const
{
	std::vector<int> selected = GetCellPositions(searchColumn, searchValue);
	if (selected.size() != 0)
	{
		if (selected[0] == -1)
		{
			std::cerr << "Count failed due to out of range query\n";
			return -1;
		}
	}
	return selected.size();
}

void Table::Aggregate(const int searchNumber, const std::string & searchValue, const int targetNumber, const Operation operation)
{
	if (this->m_Columns[targetNumber].GetType() != String && this->m_Columns[searchNumber].GetType() != String)
	{
		std::vector<int> selected = GetCellPositions(searchNumber, searchValue);
		if (selected.size() != 0)
		{
			if (selected[0] == -1)
				return;
		}
		std::string UpdatedValue;
		for (unsigned i = 0; i < selected.size(); ++i)
		{
			if (this->m_Columns[targetNumber].GetType() == Int)
			{
				int tmp1 = stoi(searchValue);
				int tmp2 = stoi(this->m_Columns[targetNumber].GetCellValue(selected[i]));
				int valueAfterOpera = PerformOperation(tmp1, tmp2, operation);
				UpdatedValue = std::to_string(valueAfterOpera);
			}
			else
			{
				double tmp1 = stod(searchValue);
				double tmp2 = stod(this->m_Columns[targetNumber].GetCellValue(selected[i]));
				double newTrVal = PerformOperation(tmp2, tmp2, operation);
				UpdatedValue = std::to_string(newTrVal);
			}
			this->m_Columns[targetNumber].SetCellValue(selected[i], UpdatedValue);
		}
	}
	else
	{
		std::cout << "AggregateTable does not support operations with string values\n";
		return;
	}
}

void Table::Print() const
{
	std::vector<PageToPrint> pages;//look at PageToPrint.h to understand the idea of PageToPrint
	CreatePages(pages);//create the pages and insert them in the pages vector above, after that it allows the user to swap between the pages
	unsigned pointer = 0;
	char command = '0';
	while (command != 'e' && command != 'E')
	{
		PrintPage(pages[pointer].GetBegin(), pages[pointer].GetEnd());
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
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		std::cout << "Column name: " << this->m_Columns[i].GetName() << " is ";
		m_Columns[i].CoutTypeName();
	}
}

Type Table::GetColumnType(const unsigned number) const
{
	return this->m_Columns[number].GetType();
}

unsigned Table::GetColumnsSize() const
{
	return this->m_Columns.size();
}

const std::string & Table::GetColumnName(const unsigned number) const
{
	return this->m_Columns[number].GetName();
}

std::string Table::GetColumnCellValue(const unsigned columnNumber, const unsigned rowNumber) const
{
	return this->m_Columns[columnNumber].GetCellValue(rowNumber);
}

void Table::SetColumnCellValue(const unsigned columnNumber, const unsigned rowNumb, const std::string & value)
{
	this->m_Columns[columnNumber].SetCellValue(rowNumb, value);
}

void Table::AddColumnCell(const unsigned position, const std::string & name)
{
	this->m_Columns[position].AddCell(name);
}

unsigned Table::GetRows() const
{
	return this->m_Rows;
}

void Table::IncrementRows()
{
	++this->m_Rows;
}

std::string Table::ParseColumnsToString() const
{
	std::string stringReference;
	for (unsigned i = 0; i < this->m_Columns.size(); ++i)
	{
		this->m_Columns[i].ParseToString(stringReference);
		if (i != this->m_Columns.size() - 1)
		{
			stringReference += "\n";
		}
	}
	return stringReference;
}
