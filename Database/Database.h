#pragma once
#include "Table.h"
class Database
{
	Database();//singleton
	Database(const Database&);
	Database& operator=(const Database&);
	void AddTable(const Table&);
	void ParseFileToTableColumns(std::ifstream&, Table&, std::string&)const;
	//used to make the LoadTable function easier for reading
	std::string ParseTableColumnsToString(const std::string&)const;

	//the name describes it, returns m_Tables.size() if table is not found, used in many functions of the class to convert the table name to its index
	unsigned GetTableIndexByName(bool&, const std::string&)const;
	
	//used for InnerJoin() to validate that the 2 table names are actual tables from the database
	bool InnerJoinProcessTwoBooleans(const bool, const std::string&, const bool, const std::string&)const;

	//validates that the two columns' names and types match
	bool InnerJoinValidateColumns(const Table&, const unsigned, const Table&, const unsigned)const;

	//will add all the columns of the two tables into the new temp table(no repeation of the inner join column)
	void InnerJoinAddJoinedColumns(Table&, const Table&, const Table&, const unsigned)const;

	//used by InnerJoin() to blend the two tables, well described in definition
	void RealInnerJoin(Table&, const Table&, const unsigned, const Table&, const unsigned)const;
	Type GetTypeByChar(const char)const;//converts a char I, D or S into the specific type, used for loading a table from file
public:
	static Database * instance()
	{
		static Database instance;
		return &instance;
	}
	void LoadTable(const std::string&);
	void PrintLoadedTables()const;
	void PrintTableColumnsTypes(const std::string&)const;//uses GetTableIndexById() to find the table and then uses Table::PrintColumnsTypes() on it
	void PrintTable(const std::string&)const;//uses GetTableIndexById() to find the table and then calls Table::Print()

	//uses GetTableIndexById() to find the table, then opens a file with the name gives as parameter, and then calls Table::ParseTableColumnsToString() to create a huge string, then it inserts the huge string in the opened file
	void SaveTable(const std::string&, const std::string&) const;
	void AddColumnToTable(const std::string&, const std::string&, const Type);//uses GetTableIndexById() to find the table and then calls Table::AddColumnToTable()
	void UpdateTable(const std::string&, const unsigned, const std::string&, const unsigned, const std::string&);//uses GetTableIndexById() to find the table and then calls Table::UpdateTable()
	void DeleteTable(const std::string&, const unsigned, const std::string&);//uses GetTableIndexById() to find the table and then calls Table::DeleteTable()
	void InsertIntoTable(const std::string&, const char *, ...);//same like Table::InsertIntoTable(), but takes 1 extra parameter to represent the name of the table via GetTableIndexById()
	
	//uses GetTableIndexById() to find the two tables, then uses the 3 InnerJoin... functions that are in the private section of the class to combine the 2 tables into 1 if possible
	void InnerJoin(const std::string&, const unsigned, const std::string&, const unsigned);
	void RenameTable(const std::string&, const std::string&);//uses GetTableIndexById() to find the table and then calls Table::RenameTable()
	void CountTable(const std::string&, const unsigned, const std::string&)const;//uses GetTableIndexById() to find the table and then calls Table::CountTable()
	void AggregateTable(const std::string&, const unsigned, const std::string&, const unsigned, const Operation);//uses GetTableIndexById() to find the table and then calls Table::AggregateTable()
private:
	std::vector<Table> m_Tables;
};