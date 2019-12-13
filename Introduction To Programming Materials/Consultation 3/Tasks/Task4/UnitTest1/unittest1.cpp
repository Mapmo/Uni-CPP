#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Task4/Task4.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			unsigned tmp = Task4("hellp", "help");
			Assert::AreEqual(tmp, 1u);
		}
		TEST_METHOD(TestMethod2)
		{
			unsigned tmp = Task4("help", "help");
			Assert::AreEqual(tmp, 0u);
		}
		TEST_METHOD(TestMethod3)
		{
			unsigned tmp = Task4("help", "pleh");
			Assert::AreEqual(tmp, 0u);
		}
		TEST_METHOD(TestMethod4)
		{
			unsigned tmp = Task4("aaa", "rap");
			Assert::AreEqual(tmp, 4u);
		}
		TEST_METHOD(TestMethod5)
		{
			unsigned tmp = Task4("dark", "park");
			Assert::AreEqual(tmp, 2u);
		}
		TEST_METHOD(TestMethod6)
		{
			unsigned tmp = Task4("abcd", "efg");
			Assert::AreEqual(tmp, 7u);
		}
		TEST_METHOD(TestMethod7)
		{
			unsigned tmp = Task4("", "efg");
			Assert::AreEqual(tmp, 3u);
		}
		TEST_METHOD(TestMethod8)
		{
			unsigned tmp = Task4("", "");
			Assert::AreEqual(tmp, 0u);
		}
		TEST_METHOD(TestMethod9)
		{
			unsigned tmp = Task4("leee", "llle");
			Assert::AreEqual(tmp, 4u);
		}
		TEST_METHOD(TestMethod10)
		{
			unsigned tmp = Task4("rain", "zapdor");
			Assert::AreEqual(tmp, 6u);
		}
	};
}