#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "..\Matrix\matrix.h"

namespace MatrixTest
{
	TEST_CLASS(MatrixTest)
	{
	public:
		TEST_METHOD(PrintData)
		{
			const unsigned ROWS = 2;
			const unsigned COLUMNS = 3;
			Matrix<double> tmp(ROWS, COLUMNS);
			double * * a = new double *[ROWS];
			for (unsigned i = 0; i < ROWS; ++i)
			{
				a[i] = new double[COLUMNS];
			}
			a[0][0] = 4.3; a[0][1] = 5.4; a[0][2] = 1.2;
			a[1][0] = 3.1; a[1][1] = 3.2; a[1][2] = 6.8;
			tmp.SetData(a);

			bool flag = true;
			for (unsigned i = 0; i < ROWS && flag; ++i)
			{
				for (unsigned j = 0; j < COLUMNS; ++j)
				{
					if (a[i][j] != tmp.GetCell(i, j))
					{
						flag = false;
						break;
					}
				}
			}
			Assert::IsTrue(flag);
		}

		TEST_METHOD(SetData)//actually tests operator *, but i was unable to put its name here
		{
			const unsigned ROWS = 2;
			const unsigned COLUMNS = 2;
			Matrix<int> tmp(ROWS, COLUMNS);
			int * * a = new int *[ROWS];
			for (unsigned i = 0; i < ROWS; ++i)
			{
				a[i] = new int[COLUMNS];
			}
			a[0][0] = 11; a[0][1] = 3; 
			a[1][0] = 7; a[1][1] = 11;
			tmp.SetData(a);

			const unsigned ROWS2 = 2;
			const unsigned COLUMNS2 = 3;
			Matrix<int> tmp2(ROWS2, COLUMNS2);
			int  * * b = new int *[ROWS2];
			for (unsigned i = 0; i < ROWS2; ++i)
			{
				b[i] = new int[COLUMNS2];
			}
			b[0][0] = 8; b[0][1] = 0; b[0][2] = 1;
			b[1][0] = 0; b[1][1] = 3; b[1][2] = 5;
			tmp2.SetData(b);

			Matrix<int> tmp3 = tmp *  tmp2;
			//correct answer
			b[0][0] = 88; b[0][1] = 9; b[0][2] = 26;
			b[1][0] = 56; b[1][1] = 33; b[1][2] = 62;


			bool flag = true;
			for (unsigned i = 0; i < ROWS && flag; ++i)
			{
				for (unsigned j = 0; j < COLUMNS2; ++j)
				{
					if (tmp3.GetCell(i, j) != b[i][j])
					{
						flag = false;
						break;
					}
				}
			}
			Assert::IsTrue(flag);
		}
	};
}