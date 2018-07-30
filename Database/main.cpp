#include "Database.h"
int main()
{
	Database * harry = Database::instance();
	harry->Load("Tables/test.txt");
	harry->Load("Tables/tester.txt");
	harry->Load("Tables/InnerJointest+tester.txt");
	/*
	harry->ShowTables();
	harry->Save("test", "Tables/test.txt");
	harry->Update("test", 1, "SpiderMan", 1, "Toni");
	harry->Print("InnerJointest+tester");
	harry->InnerJoin("test", 1, "tester", 0);
	harry->Delete("test", 1, "SpideMan");
	harry->Aggregate("test", 2, "11", 0, PRODUCT);
	*/
	harry->Describe("test");
	return 0;
}