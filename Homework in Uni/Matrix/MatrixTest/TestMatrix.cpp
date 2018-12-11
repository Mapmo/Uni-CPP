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

		TEST_METHOD(Multiplication)
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

			//this code tests whether the code throws correct exceptions
			//time to remined tmp is 2x2 and tmp2 is 2x3
			flag = false;
			try
			{
				tmp2*tmp;
			}
			catch (const std::length_error& le)
			{
				Assert::AreEqual(le.what(), "Matrices that cannot be multiplied given\n");
				flag = true;
			}
			Assert::IsTrue(flag);

			flag = false;
			try
			{
				tmp*=tmp2;
			}
			catch (const std::length_error& le)
			{
				Assert::AreEqual(le.what(), "This Matrix implementation does not support *= that canges the size of the original matrix\n");
				flag = true;
			}
			Assert::IsTrue(flag);

			//this code will test whether *= works correctly
			
			//reminding that tmp is 
			//11	3
			//7		11

			Matrix <int> tmp4(ROWS, COLUMNS);
			a[0][0] = 2; a[0][1] = 3;
			a[1][0] = 5; a[1][1] = 9;
			tmp4.SetData(a);

			//expected return
			a[0][0] = 37; a[0][1] = 60;
			a[1][0] = 69; a[1][1] = 120;

			flag = true;
			tmp *= tmp4;
			for (unsigned i = 0; i < COLUMNS && flag; ++i)
			{
				for (unsigned j = 0; j < ROWS; ++j)
				{
					if (tmp.GetCell(i, j) != a[i][j])
					{
						flag = false;
						break;
					}
				}
			}
			Assert::IsTrue(flag);
		}
		TEST_METHOD(Power)
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
			tmp.Pow(2);

			//expected return
			a[0][0] = 142; a[0][1] = 66;
			a[1][0] = 154; a[1][1] = 142;

			bool flag = true;
			for (unsigned i = 0; i < COLUMNS && flag; ++i)
			{
				for (unsigned j = 0; j < ROWS; ++j)
				{
					if (tmp.GetCell(i, j) != a[i][j])
					{
						flag = false;
						break;
					}
				}
			}
			Assert::IsTrue(flag);

			tmp.Pow(1);
			flag = true;
			for (unsigned i = 0; i < COLUMNS && flag; ++i)
			{
				for (unsigned j = 0; j < ROWS; ++j)
				{
					if (tmp.GetCell(i, j) != a[i][j])
					{
						flag = false;
						break;
					}
				}
			}
			Assert::IsTrue(flag);

			tmp.Pow(3);
			//expected return
			a[0][0] = 7193152; a[0][1] = 4663296;
			a[1][0] = 10881024; a[1][1] = 7193152;
			flag = true;
			for (unsigned i = 0; i < COLUMNS && flag; ++i)
			{
				for (unsigned j = 0; j < ROWS; ++j)
				{
					if (tmp.GetCell(i, j) != a[i][j])
					{
						flag = false;
						break;
					}
				}
			}
			Assert::IsTrue(flag);


			tmp.Pow(0);
			//expected return
			a[0][0] = 1; a[0][1] = 0;
			a[1][0] = 0; a[1][1] = 1;

			flag = true;
			for (unsigned i = 0; i < COLUMNS && flag; ++i)
			{
				for (unsigned j = 0; j < ROWS; ++j)
				{
					if (tmp.GetCell(i, j) != a[i][j])
					{
						flag = false;
						break;
					}
				}
			}
			Assert::IsTrue(flag);
		}
		TEST_METHOD(Transpose)
		{
			const unsigned ROWS2 = 2;
			const unsigned COLUMNS2 = 3;
			Matrix<int> tmp(ROWS2, COLUMNS2);
			int  * * a = new int *[ROWS2];
			for (unsigned i = 0; i < ROWS2; ++i)
			{
				a[i] = new int[COLUMNS2];
			}
			a[0][0] = 8; a[0][1] = 0; a[0][2] = 1;
			a[1][0] = 0; a[1][1] = 3; a[1][2] = 5;
			tmp.SetData(a);

			Matrix<int> tmp2 = tmp.Transpose();

			int  * * b = new int *[COLUMNS2];
			for (unsigned i = 0; i < COLUMNS2; ++i)
			{
				b[i] = new int[ROWS2];
			}
			b[0][0] = 8; b[0][1] = 0;
			b[1][0] = 0; b[1][1] = 3;
			b[2][0] = 1; b[2][1] = 5;

			bool flag = true;
			for (unsigned i = 0; i < COLUMNS2 && flag; ++i)
			{
				for (unsigned j = 0; j < ROWS2; ++j)
				{
					if (tmp2.GetCell(i, j) != b[i][j])
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