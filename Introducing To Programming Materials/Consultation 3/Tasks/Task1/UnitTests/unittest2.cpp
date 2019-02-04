#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/Task1.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod01)
		{
			unsigned n = 6;
			int arr[] = { 0, 1, 2, 4, 3, 5 };
			Assert::AreEqual(Task1(arr, n), 27);
		}
		TEST_METHOD(TestMethod02)
		{
			unsigned n = 4;
			int arr[] = { -1, 1, 2, 3 };
			Assert::AreEqual(Task1(arr, n), 6);
		}
		TEST_METHOD(TestMethod03)
		{
			unsigned n = 1;
			int arr[] = { -1 };
			Assert::AreEqual(Task1(arr, n), -1);
		}
		TEST_METHOD(TestMethod04)
		{
			unsigned n = 3;
			int arr[] = { -1, 1, 0 };
			Assert::AreEqual(Task1(arr, n), 1);
		}
		TEST_METHOD(TestMethod05)
		{
			unsigned n = 1;
			int arr[] = {  0 };
			Assert::AreEqual(Task1(arr, n), 0);
		}
		TEST_METHOD(TestMethod06)
		{
			unsigned n = 2;
			int arr[] = { 0, 0 };
			Assert::AreEqual(Task1(arr, n), 0);
		}
		TEST_METHOD(TestMethod07)
		{
			unsigned n = 1;
			int arr[] = { -1000 };
			Assert::AreEqual(Task1(arr, n), -1000);
		}
		TEST_METHOD(TestMethod08)
		{
			unsigned n = 4;
			int arr[] = { -1000, -1000, 1000, 1000 };
			Assert::AreEqual(Task1(arr, n), 2000000);
		}
		TEST_METHOD(TestMethod09)
		{
			unsigned n = 4;
			int arr[] = { -1000, 0, 1000, 1000 };
			Assert::AreEqual(Task1(arr, n), 1000000);
		}
		TEST_METHOD(TestMethod10)
		{
			unsigned n = 5;
			int arr[] = { 0, -1000, -1000, 1000, 1000 };
			Assert::AreEqual(Task1(arr, n), 2000000);
		}
		TEST_METHOD(TestMethod11)
		{
			unsigned n = 6;
			int arr[] = { 0, -1000, -1000, 0, 1000, 1000 };
			Assert::AreEqual(Task1(arr, n), 2000000);
		}
		TEST_METHOD(TestMethod12)
		{
			unsigned n = 3;
			int arr[] = { 0, 3, 2 };
			Assert::AreEqual(Task1(arr, n), 6);
		}
		TEST_METHOD(TestMethod13)
		{
			unsigned n = 3;
			int arr[] = { 1, 1, 1 };
			Assert::AreEqual(Task1(arr, n), 3);
		}
		TEST_METHOD(TestMethod14)
		{
			unsigned n = 3;
			int arr[] = { 1, -1, 1 };
			Assert::AreEqual(Task1(arr, n), 1);
		}
		TEST_METHOD(TestMethod15)
		{
			unsigned n = 3;
			int arr[] = { -1, -1, -1 };
			Assert::AreEqual(Task1(arr, n), 0);
		}
		TEST_METHOD(TestMethod16)
		{
			unsigned n = 3;
			int arr[] = { 0, 3, 2 };
			Assert::AreEqual(Task1(arr, n), 6);
		}
		TEST_METHOD(TestMethod17)
		{
			unsigned n = 3;
			int arr[] = { 0, -3, -2 };
			Assert::AreEqual(Task1(arr, n), 6);
		}
		TEST_METHOD(TestMethod18)
		{
			unsigned n = 3;
			int arr[] = { 0, -3, -2 };
			Assert::AreEqual(Task1(arr, n), 6);
		}
		TEST_METHOD(TestMethod19)
		{
			unsigned n = 15;
			int arr[] = { -400, -500, - 900, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 999, 999 };
			Assert::AreEqual(Task1(arr, n), 1448011);
		}
		TEST_METHOD(TestMethod20)
		{
			unsigned n = 6;
			int arr[] = { -1,  0,  1, - 2, - 3,  0 };
			Assert::AreEqual(Task1(arr, n), 7);
		}
		TEST_METHOD(TestMethod21)
		{
			unsigned n = 7;
			int arr[] = { -1,  0,  1, -2, -3,  0, -1 };
			Assert::AreEqual(Task1(arr, n), 8);
		}
		TEST_METHOD(TestMethod22)
		{
			unsigned n = 4;
			int arr[] = { -1, 1, -2, -3};
			Assert::AreEqual(Task1(arr, n), 6);
		}
		TEST_METHOD(TestMethod23)
		{
			unsigned n = 6;
			int arr[] = { 1, 1, 1, -1, -1, -1 };
			Assert::AreEqual(Task1(arr, n), 3);
		}
	};
}