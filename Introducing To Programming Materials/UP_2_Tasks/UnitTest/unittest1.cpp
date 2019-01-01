#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\prep\Tasks.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int arr1[] = { 2, -4, 15, -3, -1, 5, 10, -2, 3, 4, -1, -3, 5, 5 };
unsigned size1 = sizeof(arr1) / sizeof(arr1[0]);

int arr2[] = { 2, -4, 11, 5, 10, -2, 3, 4, -1, -3, -5, -5, -5, -8, 8 };
unsigned size2 = sizeof(arr2) / sizeof(arr2[0]);

int arr3[] = { 2, -4, -5 };
unsigned size3 = sizeof(arr3) / sizeof(arr3[0]);
int arr[] = { 5 };

char str1[] = "We love C++";
char str2[] = "pop";
char str3[] = "graph";
char str4[] = "We love UP";
char str5[] = "U and P";
namespace UnitTest
{
	TEST_CLASS(task01)
	{
	public:
		TEST_METHOD(test1)
		{
			int a = Task1(arr1, size1);
			Assert::AreEqual(a, 35);
		}

		TEST_METHOD(test2)
		{
			int a = Task1(arr2, size2);
			Assert::AreEqual(a, 10);
		}

		TEST_METHOD(test3)
		{
			int a = Task1(arr3, size3);
			Assert::AreEqual(a, -7);
		}
	};
	TEST_CLASS(task02)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task2(arr1, size1);
			Assert::AreEqual(a, 10);
		}

		TEST_METHOD(test2)
		{
			int a = Task2(arr2, size2);
			Assert::AreEqual(a, 10);
		}

		TEST_METHOD(test3)
		{
			int a = Task2(arr3, size3);
			Assert::AreEqual(a, -2);
		}
	};
	TEST_CLASS(task03)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task3(arr1, size1);
			Assert::AreEqual(a, 15);
		}

		TEST_METHOD(test2)
		{
			int a = Task3(arr2, size2);
			Assert::AreEqual(a, 11);
		}

		TEST_METHOD(test3)
		{
			int a = Task3(arr3, size3);
			Assert::AreEqual(a, 2);
		}
	};
	TEST_CLASS(task04)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task4(arr1, size1);
			Assert::AreEqual(a, 15);
		}

		TEST_METHOD(test2)
		{
			int a = Task4(arr2, size2);
			Assert::AreEqual(a, 11);
		}

		TEST_METHOD(test3)
		{
			int a = Task4(arr3, size3);
			Assert::AreEqual(a, 0);
		}
	};
	TEST_CLASS(task05)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task5(arr1, size1);
			Assert::AreEqual(a, -4);
		}

		TEST_METHOD(test2)
		{
			int a = Task5(arr2, size2);
			Assert::AreEqual(a, -8);
		}

		TEST_METHOD(test3)
		{
			int a = Task5(arr3, size3);
			Assert::AreEqual(a, -4);
		}
	};
	TEST_CLASS(task06)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task6(arr1, size1);
			Assert::AreEqual(a, 16);
		}

		TEST_METHOD(test2)
		{
			int a = Task6(arr2, size2);
			Assert::AreEqual(a, 24);
		}

		TEST_METHOD(test3)
		{
			int a = Task6(arr3, size3);
			Assert::AreEqual(a, 2);
		}
	};
	TEST_CLASS(task07)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task7(arr1, size1);
			Assert::AreEqual(a, 15);
		}

		TEST_METHOD(test2)
		{
			int a = Task7(arr2, size2);
			Assert::AreEqual(a, 11);
		}

		TEST_METHOD(test3)
		{
			int a = Task7(arr3, size3);
			Assert::AreEqual(a, 2);
		}
	};
	TEST_CLASS(task08)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task8(arr1, size1);
			Assert::AreEqual(a, 2);
		}

		TEST_METHOD(test2)
		{
			int a = Task8(arr2, size2);
			Assert::AreEqual(a, -13);
		}

		TEST_METHOD(test3)
		{
			int a = Task8(arr3, size3);
			Assert::AreEqual(a, -4);
		}

		TEST_METHOD(test4)
		{
			int a = Task8(arr, 1);
			Assert::AreEqual(a, 0);
		}
	};
	TEST_CLASS(task09)
	{
	public:
		TEST_METHOD(test1)
		{

			int a = Task9(arr1, size1);
			Assert::AreEqual(a, 7);
		}

		TEST_METHOD(test2)
		{
			int a = Task9(arr2, size2);
			Assert::AreEqual(a, 10);
		}

		TEST_METHOD(test3)
		{
			int a = Task9(arr3, size3);
			Assert::AreEqual(a, -3);
		}

		TEST_METHOD(test4)
		{
			int a = Task9(arr, 1);
			Assert::AreEqual(a, 10);
		}
	};
	TEST_CLASS(task10)
	{
	public:
		TEST_METHOD(test1)
		{
			int a = Task10(arr1, size1);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test2)
		{
			int a = Task10(arr2, size2);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test3)
		{
			int a = Task10(arr3, size3);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test4)
		{
			int a = Task10(arr, 1);
			Assert::AreEqual(a, 0);
		}
	};
	TEST_CLASS(task11)
	{
	public:
		TEST_METHOD(test1)
		{
			int _arr1[] = { -2, 4, -15, 3, 1, -5, -10, 2, -3, -4, 1, 3, -5, -5 };
			Task11(_arr1, size1);
			for (unsigned i = 0; i < size1; ++i)
			{
				Assert::AreEqual(arr1[i], _arr1[i]);
			}
		}

		TEST_METHOD(test2)
		{
			int _arr2[] = { -2, 4, -11, -5, -10, 2, -3, -4, 1, 3, 5, 5, 5, 8, -8 };
			Task11(_arr2, size2);
			for (unsigned i = 0; i < size2; ++i)
			{
				Assert::AreEqual(arr2[i], _arr2[i]);
			}
		}

		TEST_METHOD(test3)
		{
			int _arr3[] = { -2, 4, 5 };
			Task11(_arr3, size3);
			for (unsigned i = 0; i < size3; ++i)
			{
				Assert::AreEqual(arr3[i], _arr3[i]);
			}
		}

		TEST_METHOD(test4)
		{
			int _arr[] = { -5 };
			Task11(_arr, 1);
			Assert::AreEqual(arr[0], _arr[0]);
		}
	};
	TEST_CLASS(task12)
	{
	public:
		TEST_METHOD(test1)
		{
			int a = Task12(arr1, size1);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test2)
		{
			int a = Task12(arr2, size2);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test3)
		{
			int a = Task12(arr3, size3);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test4)
		{
			int a = Task12(arr, 1);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test5)
		{
			int arr4[] = { 1,2 };
			int a = Task12(arr4, 2);
			Assert::AreEqual(a, 0);
		}
	};
	TEST_CLASS(task13)
	{
	public:
		TEST_METHOD(test1)
		{
			int a = Task13(arr1, size1);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test2)
		{
			int a = Task13(arr2, size2);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test3)
		{
			int a = Task13(arr3, size3);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test4)
		{
			int a = Task13(arr, 1);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test5)
		{
			int arr4[] = { 1,2 };
			int a = Task13(arr4, 2);
			Assert::AreEqual(a, 1);
		}
	};
	TEST_CLASS(task14)
	{
	public:
		TEST_METHOD(test1)
		{
			int a = Task14(arr1, size1);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test2)
		{
			int a = Task14(arr2, size2);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test3)
		{
			int a = Task14(arr3, size3);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test4)
		{
			int a = Task14(arr, 1);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test5)
		{
			int arr4[] = { 1,2 };
			int a = Task14(arr4, 2);
			Assert::AreEqual(a, 0);
		}
	};

	TEST_CLASS(task15)
	{
	public:
		TEST_METHOD(test1)
		{
			int a = Task15(arr1, size1, 90);
			Assert::AreEqual(a, 0);
			a = Task15(arr1, size1, -12);
			Assert::AreEqual(a, 0);
			a = Task15(arr1, size1, -42);
			Assert::AreEqual(a, 0);
			a = Task15(arr1, size1, -22);
			Assert::AreEqual(a, 0);
			a = Task15(arr1, size1, 5);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test2)
		{
			int a = Task15(arr2, size2, -44);
			Assert::AreEqual(a, 0);
		}

		TEST_METHOD(test3)
		{
			int a = Task15(arr3, size3, -5);
			Assert::AreEqual(a, 1);
		}

		TEST_METHOD(test4)
		{
			int a = Task15(arr, 1, 5);
			Assert::AreEqual(a, 1);
		}
	};
	TEST_CLASS(task16)
	{
		TEST_METHOD(test1)
		{
			Assert::AreEqual(strlen(str1), Task16(str1));
		}
		TEST_METHOD(test2)
		{
			Assert::AreEqual(strlen(str2), Task16(str2));
		}
		TEST_METHOD(test3)
		{
			Assert::AreEqual(strlen(str3), Task16(str3));
		}
	};
	TEST_CLASS(task17)
	{
		TEST_METHOD(test1)
		{
			Task17(str1);
			Assert::AreEqual(str1[strlen(str1) - 1], '-');
			Assert::AreEqual(str1[strlen(str1) - 2], '-');
			Assert::AreNotEqual(str1[strlen(str1) - 3], '-');
		}
	};
	TEST_CLASS(task18)
	{
		TEST_METHOD(test1)
		{
			int a = Task18(str1);
			Assert::AreEqual(a, 0);
		}
		TEST_METHOD(test2)
		{
			int a = Task18(str2);
			Assert::AreEqual(a, 0);
		}
		TEST_METHOD(test3)
		{
			int a = Task18(str3);
			Assert::AreEqual(a, 0);
		}
		TEST_METHOD(test4)
		{
			int a = Task18(str4);
			Assert::AreEqual(a, 1);
		}
		TEST_METHOD(test5)
		{
			int a = Task18(str5);
			Assert::AreEqual(a, 1);
		}
	};
	TEST_CLASS(task19)
	{
		TEST_METHOD(test1)
		{
			char str2[] = "pop";
			char _str2[] = "POP";
			Task19(_str2);
			for (unsigned i = 0; i < strlen(str2); ++i)
			{
				Assert::AreEqual(str2[i], _str2[i]);
			}
		}
		TEST_METHOD(test2)
		{
			char str3[] = "graph";
			char _str3[] = "GRAPH";
			Task19(_str3);
			for (unsigned i = 0; i < strlen(str2); ++i)
			{
				Assert::AreEqual(str3[i], _str3[i]);
			}
		}
	};
	TEST_CLASS(task20)
	{
		TEST_METHOD(test1)
		{
			char _str1[] = "wE LOVE c++";
			Task20(str1);
			for (unsigned i = 0; i < strlen(str1); ++i)
			{
				Assert::AreEqual(str1[i], _str1[i]);
			}
		}
		TEST_METHOD(test2)
		{
			char _str2[] = "POP";
			Task20(str2);
			for (unsigned i = 0; i < strlen(str2); ++i)
			{
				Assert::AreEqual(str2[i], _str2[i]);
			}
		}
		TEST_METHOD(test3)
		{
			char _str3[] = "GRAPH";
			Task20(str3);
			for (unsigned i = 0; i < strlen(str2); ++i)
			{
				Assert::AreEqual(str3[i], _str3[i]);
			}
		}
	};

	TEST_CLASS(task21)
	{
		TEST_METHOD(test1)
		{
			std::ostringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Task21(10);

			std::cout.rdbuf(p_cout_streambuf); // restore

			// test your oss content...
			Assert::IsTrue(oss && oss.str() == "00:00");
		}
		TEST_METHOD(test2)
		{
			std::ostringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Task21(119);

			std::cout.rdbuf(p_cout_streambuf); // restore

			// test your oss content...
			Assert::IsTrue(oss && oss.str() == "00:01");
		}
		TEST_METHOD(test3)
		{
			std::ostringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Task21(5656);

			std::cout.rdbuf(p_cout_streambuf); // restore

			// test your oss content...
			Assert::IsTrue(oss && oss.str() == "01:34");
		}
		TEST_METHOD(test4)
		{
			std::ostringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Task21(75656);

			std::cout.rdbuf(p_cout_streambuf); // restore

			// test your oss content...
			Assert::IsTrue(oss && oss.str() == "21:00");
		}
		TEST_METHOD(test5)
		{
			std::ostringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Task21(59);

			std::cout.rdbuf(p_cout_streambuf); // restore

			// test your oss content...
			Assert::IsTrue(oss && oss.str() == "00:00");
		}
		TEST_METHOD(test6)
		{
			std::ostringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Task21(76296);

			std::cout.rdbuf(p_cout_streambuf); // restore

			// test your oss content...
			Assert::IsTrue(oss && oss.str() == "21:11");
		}
	};
	TEST_CLASS(task22)
	{
		TEST_METHOD(test1)
		{
			Assert::AreEqual(Task22(22), 2.0);
		}
		TEST_METHOD(test2)
		{
			Assert::AreEqual(Task22(23), 2.5);
		}
		TEST_METHOD(test3)
		{
			Assert::AreEqual(Task22(0), 0.0);
		}
		TEST_METHOD(test4)
		{
			Assert::AreEqual(Task22(123), 2.0);
		}
	};
}