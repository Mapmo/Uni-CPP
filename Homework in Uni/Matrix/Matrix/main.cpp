#include "Matrix.h"

int main()
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

	Matrix<int> tmp3 = tmp * tmp2;
	tmp3.Print();
	return 0;
}