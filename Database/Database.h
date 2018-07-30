#pragma once
#include "Table.h"
class Database
{
	Database();//singleton
	Database(const Database&);
	Database& operator=(const Database&);
	void AddTable(const Table&);
	void ParseFileToTableColumns(std::ifstream&, Table&, std::string&)const; //used to make the Load function easier for reading
	std::string ParseTableColumnsToString(const std::string&)const;

	//the name describes it, returns m_Tables.size() if table is not found, used in many functions of the class to convert the table name to its index
	unsigned int GetTableIndexByName(bool&, const std::string&)const;
	
	//used for InnerJoin() to validate that the 2 table names are actual tables from the database
	bool InnerJoinProcessTwoBooleans(const bool, const std::string&, const bool, const std::string&)const;

	//validates that the two columns' names and types match
	bool InnerJoinValidateColumns(const Table&, const unsigned int, const Table&, const unsigned int)const;

	//will add all the columns of the two tables into the new temp table(no repeation of the inner join column)
	void InnerJoinAddJoinedColumns(Table&, const Table&, const Table&, const unsigned int)const;

	//used by InnerJoin() to blend the two tables, well described in definition
	void RealInnerJoin(Table&, const Table&, const unsigned int, const Table&, const unsigned int)const;
	Type GetTypeByChar(const char)const;//converts a char I, D or S into the specific type, used for loading a table from file
public:
	static Database * instance()
	{
		static Database instance;
		return &instance;
	}
	void Load(const std::string&);//loads a table from a file
	void ShowTables()const;//prints the names of all tables loaded in the database
	void Describe(const std::string&)const;//uses GetTableIndexById() to find the table and then uses Table::PrintColumnsTypes() on it
	void Print(const std::string&)const;//uses GetTableIndexById() to find the table and then calls Table::Print()

	//uses GetTableIndexById() to find the table, then opens a file with the name gives as parameter, and then calls Table::ParseTableColumnsToString() to create a huge string, then it inserts the huge string in the opened file
	void Save(const std::string&, const std::string&) const;
	void AddColumn(const std::string&, const std::string&, const Type);//uses GetTableIndexById() to find the table and then calls Table::AddColumn()
	void Update(const std::string&, const unsigned int, const std::string&, const unsigned int, const std::string&);//uses GetTableIndexById() to find the table and then calls Table::Update()
	void Delete(const std::string&, const unsigned int, const std::string&);//uses GetTableIndexById() to find the table and then calls Table::Delete()
	void Insert(const std::string&, const char *, ...);//same like Table::Insert(), but takes 1 extra parameter to represent the name of the table via GetTableIndexById()
	
	//uses GetTableIndexById() to find the two tables, then uses the 3 InnerJoin... functions that are in the private section of the class to combine the 2 tables into 1 if possible
	void InnerJoin(const std::string&, const unsigned int, const std::string&, const unsigned int);
	void Rename(const std::string&, const std::string&);//uses GetTableIndexById() to find the table and then calls Table::Rename()
	void Count(const std::string&, const unsigned int, const std::string&)const;//uses GetTableIndexById() to find the table and then calls Table::Count()
	void Aggregate(const std::string&, const unsigned int, const std::string&, const unsigned int, const Operation);//uses GetTableIndexById() to find the table and then calls Table::Aggregate()
private:
	std::vector<Table> m_Tables;
};