#include "Database.h"

Database::Database() : m_Tables()
{
}

Database & Database::operator=(const Database &)
{
	return *this;//fake
}

void Database::AddTable(const Table & rhs)
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs.GetName());
	if (isSafe)
	{
		std::cerr << "Operation AddTable Failed Due To Table With Such A Name Already In The Database:" << rhs.GetName() << std::endl;
	}
	else
	{
		this->m_Tables.push_back(rhs);
		std::cout << rhs.GetName() << " successfully loaded in the database\n";
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

std::string Database::ParseTableColumnsToString(const std::string &rhs) const
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		return this->m_Tables[i].ParseColumnsToString();
	}
	else
	{
		std::cerr << "Operation ParseTableColumnsToString Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
		return "NULL";
	}
}

unsigned int Database::GetTableIndexByName(bool& isSafe, const std::string & rhs) const
{
	isSafe = false;
	unsigned int i = 0;
	while (i < this->m_Tables.size())
	{
		if (this->m_Tables[i].GetName() == rhs)
		{
			isSafe = true;
			break;
		}
		++i;
	}
	return i;
}

bool Database::InnerJoinProcessTwoBooleans(const bool isSafe1, const std::string& rhs1, const bool isSafe2, const std::string& rhs2) const
{
	if (isSafe1 && isSafe2)
	{
		return true;
	}
	else if (isSafe2)
	{
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << rhs1 << std::endl;
	}
	else if (isSafe1)
	{
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << rhs2 << std::endl;
	}
	else
	{
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << rhs1 << std::endl;
		std::cerr << "Operation InnerJoin Failed Due To Failure To Find a Table With Such Name: " << rhs2 << std::endl;
	}
	return false;
}

bool Database::InnerJoinValidateColumns(const Table & rhs1, const unsigned int numb1, const Table & rhs2, const unsigned int numb2) const
{
	if (numb1 >= rhs1.GetColumnsSize())
	{
		std::cerr << "Operation InnerJoin Failed Due To Out of Range Problem With Table " << rhs1.GetName() << "\n";
	}
	else if (numb2 >= rhs2.GetColumnsSize())
	{
		std::cerr << "Operation InnerJoin Failed Due To Out of Range Problem With Table " << rhs1.GetName() << "\n";
	}
	else
	{
		if (rhs1.GetColumnName(numb1) == rhs2.GetColumnName(numb2))
		{
			if (rhs1.GetColumnType(numb1) == rhs2.GetColumnType(numb2))
			{
				return true;
			}
			else
			{
				std::cerr << "Operation InnerJoin Failed Due Unmatching Column Types "
					<< rhs1.GetColumnType(numb1) << " and " << rhs2.GetColumnType(numb2) << "\n";
			}
		}
		else
		{
			std::cerr << "Operation InnerJoin Failed Due Unmatching Column Names "
				<< rhs1.GetColumnName(numb1) << " and " << rhs2.GetColumnName(numb2) << "\n";
		}
	}
	return false;
}

void Database::InnerJoinAddJoinedColumns(Table & tmp, const Table & table1, const Table & table2, const unsigned int numb2) const
{
	for (unsigned int i = 0; i < table1.GetColumnsSize(); ++i)
	{
		tmp.AddColumn(table1.GetColumnName(i), table1.GetColumnType(i));
	}
	for (unsigned int i = 0; i < table2.GetColumnsSize(); ++i)
	{
		if (i != numb2)
		{
			tmp.AddColumn(table2.GetColumnName(i), table2.GetColumnType(i));
		}
	}
}

void Database::RealInnerJoin(Table & tmp, const Table & table1, const unsigned int table1Col, const Table & table2, const unsigned int table2Col) const
{
	//iterates through the column of table 1
	for (unsigned int colNumber1Row = 0; colNumber1Row < table1.GetRows(); ++colNumber1Row)
	{
		//iterates through the column of table 2
		for (unsigned int colNumber2Row = 0; colNumber2Row < table2.GetRows(); ++colNumber2Row)
		{
			//if the values of two coulmns match
			if (table1.GetColumnCellValue(table1Col, colNumber1Row) == table2.GetColumnCellValue(table2Col, colNumber2Row))
			{
				//will insert the row of table1 that contains the matching cells into tmp
				for (unsigned int i = 0; i < table1.GetColumnsSize(); ++i)
				{
					tmp.AddColumnCell(i, table1.GetColumnCellValue(i, colNumber1Row));
				}
				//will insert the row of table2 that contains the matching cells into tmp, escaping the repeating column 
				unsigned int counter = 0;//used to escape the repeating columns
				for (unsigned int i = 0; i < table2.GetColumnsSize(); ++i)
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

Type Database::GetTypeByChar(const char rhs) const
{
	switch (rhs)
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
		std::cerr << "Unknown Type Passed By The Database " << rhs;
		return Error;
	}
}

void Database::Load(const std::string & fileName)
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

void Database::ShowTables() const
{
	for (unsigned int i = 0; i < this->m_Tables.size(); ++i)
	{
		std::cout << this->m_Tables[i].GetName() << std::endl;
	}
}

void Database::Describe(const std::string & rhs) const
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		this->m_Tables[i].PrintColumnsTypes();
	}
	else
	{
		std::cerr << "Operation Describe Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}
}

void Database::Print(const std::string & rhs) const
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		this->m_Tables[i].Print();
	}
	else
	{
		std::cerr << "Operation Print Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}
}

void Database::Save(const std::string &tableName, const std::string & FileName) const
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, tableName);
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
		std::cerr << "Operation Save Failed Due To Failure To Find a Table With Such Name: " << tableName << std::endl;
	}
}

void Database::AddColumn(const std::string & rhs, const std::string & name, const Type type)
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		this->m_Tables[i].AddColumn(name, type);
	}
	else
	{
		std::cerr << "Operation AddColumn Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}
}

void Database::Update(const std::string & rhs, const unsigned int numb1, const std::string & val1, const unsigned int numb2, const std::string & val2)
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		this->m_Tables[i].Update(numb1, val1, numb2, val2);
	}
	else
	{
		std::cerr << "Operation Update Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}
}

void Database::Delete(const std::string & rhs, const unsigned int numb, const std::string & val)
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		this->m_Tables[i].Delete(numb, val);
	}
	else
	{
		std::cerr << "Operation Delete Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}
}

void Database::Insert(const std::string& name, const char* rhs, ...)
{
	bool isSafe = false;
	unsigned int tableNumb = GetTableIndexByName(isSafe, name);
	if (isSafe)
	{
		va_list args;
		va_start(args, rhs);
		std::string tmp = rhs;

		//the code below validates that all data's type matches the column type 
		for (unsigned int i = 0; i < this->m_Tables[tableNumb].GetColumnsSize(); ++i)
		{
			if (!this->m_Tables[tableNumb].ValidateDataType(tmp, this->m_Tables[tableNumb].GetColumnType(i)))
			{
				std::cout << tmp << "\n";
				std::cout << this->m_Tables[tableNumb].GetColumnType(i) << "\n";
				std::cout << "\n";
				std::cerr << "Insert Operation Impossible Due To Bad Input\n";
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
		va_start(args2, rhs);
		std::string tmp2 = rhs;
		for (unsigned int i = 0; i < this->m_Tables[tableNumb].GetColumnsSize(); ++i)
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
		std::cerr << "Operation Insert Failed Due To Failure To Find a Table With Such Name: " << name << std::endl;
	}
}

void Database::InnerJoin(const std::string & rhs1, const unsigned int numb1, const std::string & rhs2, const unsigned int numb2)
{
	std::string newTableName = "InnerJoin" + rhs1 + '+' + rhs2;
	Table tmp(newTableName);
	bool isSafe1 = false;
	bool isSafe2 = false;
	unsigned int table1 = GetTableIndexByName(isSafe1, rhs1);
	unsigned int table2 = GetTableIndexByName(isSafe2, rhs2);

	if (InnerJoinProcessTwoBooleans(isSafe1, rhs1, isSafe2, rhs2))//validates that InnerJoin() is possible
	{
		InnerJoinAddJoinedColumns(tmp, this->m_Tables[table1], this->m_Tables[table2], numb2);//combines the columns of the 2 tables into 1 table
		RealInnerJoin(tmp, this->m_Tables[table1], numb1, this->m_Tables[table2], numb2);//copies the info of the two columns into the new one
		AddTable(tmp);//adds the new table to the db
	}
}

void Database::Rename(const std::string & rhs, const std::string & val)
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		unsigned int j = GetTableIndexByName(isSafe, val);
		if (isSafe)
		{
			std::cerr << "Operation Rename Failed Because Name " << val << " is already taken\n";
		}
		else
		{
			this->m_Tables[i].Rename(val);
		}
	}
	else
	{
		std::cerr << "Operation Rename Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}
}

void Database::Count(const std::string & rhs, const unsigned int numb, const std::string & val) const
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		std::cout << "In Table " << rhs << "In Cell No: " << numb << " The Amount Of Cells With Value " << val
			<< " is: " << this->m_Tables[i].Count(numb, val) << "\n";
	}
	else
	{
		std::cerr << "Operation Count Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}

}

void Database::Aggregate(const std::string & rhs, const unsigned int srNumb, const std::string & srVal, const unsigned int trNumb, const Operation opera)
{
	bool isSafe = false;
	unsigned int i = GetTableIndexByName(isSafe, rhs);
	if (isSafe)
	{
		this->m_Tables[i].Aggregate(srNumb, srVal, trNumb, opera);
	}
	else
	{
		std::cerr << "Operation Aggregate Failed Due To Failure To Find a Table With Such Name: " << rhs << std::endl;
	}
}
