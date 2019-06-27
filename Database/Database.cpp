#include "Database.h"

Database::Database() : m_Tables()
{
}

Database & Database::operator=(const Database &)
{
	return *this;
}

void Database::AddTable(const Table & tableName)
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName.GetName());
	if (isSafe)
	{
		std::cerr << "Operation AddTable Failed Due To Table With Such A Name Already In The Database:" << tableName.GetName() << std::endl;
	}
	else
	{
		this->m_Tables.push_back(tableName);
		std::cout << tableName.GetName() << " successfully loaded in the database\n";
	}
}

void Database::ParseFileToTableColumns(std::ifstream& tableFile, Table & tmp, std::string & parser) const
{
	bool RowsIncremented = false;
	bool HasRowsIncrementStarted = false;
	int cellToEdit = 0;
	while (getline(tableFile, parser))
	{
		if (parser == "-----")
		{
			if (HasRowsIncrementStarted)
			{
				RowsIncremented = true;
			}
			getline(tableFile, parser);
			if (tableFile.good())
			{
				char type = parser[0];
				if (type != 'e' && type != 'E')//e is used for exit, a bonus protection from eof
				{
					Type columnType = GetTypeByChar(type);
					parser.erase(0, 2);
					tmp.AddColumn(parser, columnType);
				}
				else
				{
					break;
				}
			}
			cellToEdit = 0;
		}
		else
		{
			if (!RowsIncremented)
			{
				tmp.IncrementRows();
				HasRowsIncrementStarted = true;
				tmp.AddColumnCell(tmp.GetColumnsSize() - 1, parser);
			}
			else
			{
				tmp.SetColumnCellValue(tmp.GetColumnsSize() - 1, cellToEdit++, parser);
			}
		}
	}
}

std::string Database::ParseTableColumnsToString(const std::string &tableName) const
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		return this->m_Tables[i].ParseColumnsToString();
	}
	else
	{
		std::cerr << "Operation ParseTableColumnsToString Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
		return "NULL";
	}
}

unsigned Database::GetTableIndexByName(bool& isSafe, const std::string & tableName) const
{
	isSafe = false;
	unsigned i = 0;
	while (i < this->m_Tables.size())
	{
		if (this->m_Tables[i].GetName() == tableName)
		{
			isSafe = true;
			break;
		}
		++i;
	}
	return i;
}

bool Database::InnerJoinProcessTwoBooleans(const bool isSafe1, const std::string& tableName1, const bool isSafe2, const std::string& tableName2) const
{
	if (isSafe1 && isSafe2)
	{
		return true;
	}
	else if (isSafe2)
	{
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << tableName1 << std::endl;
	}
	else if (isSafe1)
	{
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << tableName2 << std::endl;
	}
	else
	{
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << tableName1 << std::endl;
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << tableName2 << std::endl;
	}
	return false;
}

bool Database::InnerJoinValidateColumns(const Table & tableName1, const unsigned numb1, const Table & tableName2, const unsigned numb2) const
{
	if (numb1 >= tableName1.GetColumnsSize())
	{
		std::cerr << "Operation InnerJoin Failed Due To Out of Range Problem With Table " << tableName1.GetName() << "\n";
	}
	else if (numb2 >= tableName2.GetColumnsSize())
	{
		std::cerr << "Operation InnerJoin Failed Due To Out of Range Problem With Table " << tableName1.GetName() << "\n";
	}
	else
	{
		if (tableName1.GetColumnName(numb1) == tableName2.GetColumnName(numb2))
		{
			if (tableName1.GetColumnType(numb1) == tableName2.GetColumnType(numb2))
			{
				return true;
			}
			else
			{
				std::cerr << "Operation InnerJoin Failed Due Unmatching Column Types "
					<< tableName1.GetColumnType(numb1) << " and " << tableName2.GetColumnType(numb2) << "\n";
			}
		}
		else
		{
			std::cerr << "Operation InnerJoin Failed Due Unmatching Column Names "
				<< tableName1.GetColumnName(numb1) << " and " << tableName2.GetColumnName(numb2) << "\n";
		}
	}
	return false;
}

void Database::InnerJoinAddJoinedColumns(Table & tmp, const Table & table1, const Table & table2, const unsigned numb2) const
{
	for (unsigned i = 0; i < table1.GetColumnsSize(); ++i)
	{
		tmp.AddColumn(table1.GetColumnName(i), table1.GetColumnType(i));
	}
	for (unsigned i = 0; i < table2.GetColumnsSize(); ++i)
	{
		if (i != numb2)
		{
			tmp.AddColumn(table2.GetColumnName(i), table2.GetColumnType(i));
		}
	}
}

void Database::RealInnerJoin(Table & tmp, const Table & table1, const unsigned table1Col, const Table & table2, const unsigned table2Col) const
{
	//iterates through the column of table 1
	for (unsigned colNumber1Row = 0; colNumber1Row < table1.GetRows(); ++colNumber1Row)
	{
		//iterates through the column of table 2
		for (unsigned colNumber2Row = 0; colNumber2Row < table2.GetRows(); ++colNumber2Row)
		{
			//if the values of two coulmns match
			if (table1.GetColumnCellValue(table1Col, colNumber1Row) == table2.GetColumnCellValue(table2Col, colNumber2Row))
			{
				//will insert the row of table1 that contains the matching cells into tmp
				for (unsigned i = 0; i < table1.GetColumnsSize(); ++i)
				{
					tmp.AddColumnCell(i, table1.GetColumnCellValue(i, colNumber1Row));
				}
				//will insert the row of table2 that contains the matching cells into tmp, escaping the repeating column 
				unsigned counter = 0;//used to escape the repeating columns
				for (unsigned i = 0; i < table2.GetColumnsSize(); ++i)
				{
					if (i != table2Col)
					{
						tmp.AddColumnCell(counter + table1.GetColumnsSize(), table2.GetColumnCellValue(i, colNumber2Row));
						++counter;
					}
				}
				//will increment the rows of the table
				tmp.IncrementRows();
			}
		}
	}
}

Type Database::GetTypeByChar(const char tableName) const
{
	switch (tableName)
	{
	case 'I':
	case 'i':
		return Int;
		break;
	case 'D':
	case 'd':
		return Double;
		break;
	case 'S':
	case 's':
		return String;
		break;
	default:
		std::cerr << "Unknown Type Passed By The Database " << tableName;
		return Error;
	}
}

void Database::LoadTable(const std::string & fileName)
{
	std::ifstream tableFile;
	tableFile.open(fileName);
	if (tableFile.is_open())
	{
		std::string parser;
		getline(tableFile, parser);
		Table tmp(parser);
		ParseFileToTableColumns(tableFile, tmp, parser);
		AddTable(tmp);
		tableFile.close();
	}
	else
	{
		std::cout << "Unable to open file" << fileName << "\n";
	}
}

void Database::PrintLoadedTables() const
{
	for (unsigned i = 0; i < this->m_Tables.size(); ++i)
	{
		std::cout << this->m_Tables[i].GetName() << std::endl;
	}
}

void Database::PrintTableColumnsTypes(const std::string & tableName) const
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		this->m_Tables[i].PrintColumnsTypes();
	}
	else
	{
		std::cerr << "Operation PrintTableColumnsTypes Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::PrintTable(const std::string & tableName) const
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		this->m_Tables[i].Print();
	}
	else
	{
		std::cerr << "Operation PrintTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::SaveTable(const std::string &tableName, const std::string & FileName) const
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		std::ofstream tableFile(FileName);
		if (tableFile.is_open())
		{
			tableFile << this->m_Tables[i].GetName() <<"\n";
			tableFile << "-----\n";
			tableFile << ParseTableColumnsToString(tableName) <<"\n";
			tableFile << "E";
			tableFile.close();
		}
		else
		{
			std::cout << "Unable to open file" << FileName << "\n";
		}
	}
	else
	{
		std::cerr << "Operation SaveTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::AddColumnToTable(const std::string & tableName, const std::string & name, const Type type)
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		this->m_Tables[i].AddColumn(name, type);
	}
	else
	{
		std::cerr << "Operation AddColumnToTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::UpdateTable(const std::string & tableName, const unsigned numb1, const std::string & val1, const unsigned numb2, const std::string & val2)
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		this->m_Tables[i].Update(numb1, val1, numb2, val2);
	}
	else
	{
		std::cerr << "Operation UpdateTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::DeleteTable(const std::string & tableName, const unsigned numb, const std::string & val)
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		this->m_Tables[i].Delete(numb, val);
	}
	else
	{
		std::cerr << "Operation DeleteTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::InsertIntoTable(const std::string& name, const char* tableName, ...)
{
	bool isSafe = false;
	unsigned tableNumb = GetTableIndexByName(isSafe, name);
	if (isSafe)
	{
		va_list args;
		va_start(args, tableName);
		std::string tmp = tableName;

		//the code below validates that all data's type matches the column type 
		for (unsigned i = 0; i < this->m_Tables[tableNumb].GetColumnsSize(); ++i)
		{
			if (!this->m_Tables[tableNumb].ValidateDataType(tmp, this->m_Tables[tableNumb].GetColumnType(i)))
			{
				std::cout << tmp << "\n";
				std::cout << this->m_Tables[tableNumb].GetColumnType(i) << "\n";
				std::cout << "\n";
				std::cerr << "InsertIntoTable Operation Impossible Due To Bad Input\n";
				va_end(args);
				return;
			}
			if (i != this->m_Tables[tableNumb].GetColumnsSize() - 1)//tmp2 moves one step ahed, so it needs to stop earlier
			{
				tmp = va_arg(args, const char*);
			}
		}
		va_end(args);
		//validation complete

		//now inserting the row
		this->m_Tables[tableNumb].IncrementRows();
		va_list args2;
		va_start(args2, tableName);
		std::string tmp2 = tableName;
		for (unsigned i = 0; i < this->m_Tables[tableNumb].GetColumnsSize(); ++i)
		{
			this->m_Tables[tableNumb].AddColumnCell(i, tmp2);
			if (i != this->m_Tables[tableNumb].GetColumnsSize() - 1)
			{
				tmp2 = va_arg(args2, const char*);
			}
		}
	}
	else
	{
		std::cerr << "Operation InsertIntoTable Failed Due To Failure To Find a Table With Such Name: " << name << std::endl;
	}
}

void Database::InnerJoin(const std::string & tableName1, const unsigned numb1, const std::string & tableName2, const unsigned numb2)
{
	std::string newTableName = "InnerJoin" + tableName1 + '+' + tableName2;
	Table tmp(newTableName);
	bool isSafe1 = false;
	bool isSafe2 = false;
	unsigned table1 = GetTableIndexByName(isSafe1, tableName1);
	unsigned table2 = GetTableIndexByName(isSafe2, tableName2);

	if (InnerJoinProcessTwoBooleans(isSafe1, tableName1, isSafe2, tableName2))//validates that InnerJoin() is possible
	{
		InnerJoinAddJoinedColumns(tmp, this->m_Tables[table1], this->m_Tables[table2], numb2);//combines the columns of the 2 tables into 1 table
		RealInnerJoin(tmp, this->m_Tables[table1], numb1, this->m_Tables[table2], numb2);//copies the info of the two columns into the new one
		AddTable(tmp);//adds the new table to the db
	}
}

void Database::RenameTable(const std::string & tableName, const std::string & val)
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		unsigned j = GetTableIndexByName(isSafe, val);
		if (isSafe)
		{
			std::cerr << "Operation RenameTable Failed Because Name " << val << " is already taken\n";
		}
		else
		{
			this->m_Tables[i].Rename(val);
		}
	}
	else
	{
		std::cerr << "Operation RenameTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::CountTable(const std::string & tableName, const unsigned numb, const std::string & val) const
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		std::cout << "In Table " << tableName << "In Cell No: " << numb << " The Amount Of Cells With Value " << val
			<< " is: " << this->m_Tables[i].Count(numb, val) << "\n";
	}
	else
	{
		std::cerr << "Operation CountTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}

}

void Database::AggregateTable(const std::string & tableName, const unsigned searchColumn, const std::string & searchValue, const unsigned targetNumber, const Operation operation)
{
	bool isSafe = false;
	unsigned i = GetTableIndexByName(isSafe, tableName);
	if (isSafe)
	{
		this->m_Tables[i].Aggregate(searchColumn, searchValue, targetNumber, operation);
	}
	else
	{
		std::cerr << "Operation AggregateTable Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}
