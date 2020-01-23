#include "Database.h"

int main()
{
	Database * harry = Database::instance();
	/*harry->LoadTable("Tables/test.txt");
	harry->LoadTable("Tables/tester.txt");
	harry->LoadTable("Tables/InnerJointest+tester.txt");
	/*
	harry->PrintLoadedTables();
	harry->SaveTable("test", "Tables/test.txt");
	harry->UpdateTable("test", 1, "SpiderMan", 1, "Toni");
	harry->PrintTable("InnerJointest+tester");
	harry->InnerJoin("test", 1, "tester", 0);
	harry->DeleteTable("test", 1, "SpideMan");
	harry->AggregateTable("test", 2, "11", 0, PRODUCT);
	
	harry->PrintTableColumnsTypes("test");
	*/
	return 0;
}