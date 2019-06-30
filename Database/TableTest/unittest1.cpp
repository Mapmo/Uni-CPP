#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Project3/Table.h"
#include "../Project3/Table.cpp"

namespace TableTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(GetName)
		{
			std::string name = "test";
			Table a(name);
			Assert::AreEqual(a.GetName(), name);
		}

		TEST_METHOD(Rename)
		{
			std::string name = "test", name2 = "changed";
			Table a(name);
			a.Rename(name2);

			Assert::AreEqual(a.GetName(), name2);
		}

		TEST_METHOD(AddColumn)
		{
			Table a("test");
			std::string b = "name";
			a.AddColumn(b, String);

			Assert::AreEqual(a.GetColumnName(0), b);
		}

		TEST_METHOD(Insert)
		{
			Table a("test");
			std::string b = "name";
			a.AddColumn(b, String);
			std::string c = "Ivan";

			a.Insert(c.c_str);

			Assert::AreEqual(a.GetColumnCellValue(0, 0), c);
		}

		TEST_METHOD(Update)
		{
			Table a("test");
			std::string first = "col1", second = "col2";
			a.AddColumn(first, String);
			a.AddColumn(second, String);
			std::string b = "Peter", c = "Ivan";

			a.Insert(b.c_str, c.c_str);
			a.Update(0, b, 1, c);

			Assert::AreEqual(a.GetColumnCellValue(0, 0), c);
		}

		TEST_METHOD(Delete)
		{
			Table a("test");
			std::string b = "name";
			a.AddColumn(b, String);
			std::string c = "Ivan";

			a.Insert(c.c_str);
			a.Delete(0, c);

			Assert::AreEqual(a.GetColumnsSize(), 0u);
		}

		TEST_METHOD(Count)
		{
			Table a("test");
			std::string b = "name";
			a.AddColumn(b, String);
			std::string c = "Ivan";

			a.Insert(c.c_str);

			Assert::AreEqual(a.Count(0, "Nasko"), 0);
			Assert::AreEqual(a.Count(0, c), 1);
		}

		TEST_METHOD(Count)
		{
			Table a("test");
			std::string b = "name";
			a.AddColumn(b, String);
	
			Assert::AreEqual(a.GetColumnType(), String);
		}
	};
}