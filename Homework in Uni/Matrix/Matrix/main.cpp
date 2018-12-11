#include "Matrix.h"

int main()
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
	return 0;
}