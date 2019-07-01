#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Project3/Cell.h"

namespace CellTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			std::string name = "example";
			Cell a(name);

			Assert::AreEqual(a.GetValue(), name);
		}

		TEST_METHOD(SetValue)
		{
			std::string name = "example";
			Cell a(name);

			Assert::AreNotEqual(a.GetValue(), name);

			a.SetValue(name);

			Assert::AreEqual(a.GetValue(), name);

		}
	};
}