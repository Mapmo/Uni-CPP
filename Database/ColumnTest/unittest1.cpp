#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Project3/Column.h"

namespace ColumnTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AddCell)
		{
			Column a(0, "cost", Double, 0);
			std::string pi = "3.14";

			a.AddCell(pi);
			Assert::AreEqual(a.GetCellValue(0), pi);
		}

		TEST_METHOD(SetCell)
		{
			Column a(0, "cost", Double, 0);
			std::string pi = "3.14", null = "0";

			a.AddCell(pi);
			a.SetCellValue(0, null);

			Assert::AreEqual(a.GetCellValue(0), null);
		}

		TEST_METHOD(ParseToString)
		{
			Column a(0, "cost", Double, 0);
			std::string tmp;
			
			a.ConvertToString(tmp);

			std::string expectedResult = "D cost\n-----";
		}
	};
}