﻿#include "Matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < matrixSize; i++)
	{
		matrix[i] = new short[5];
		for (int j = 0; j < matrixSize; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

short ** Matrix::MatrixGetter()const
{
	return this->matrix;
}

void Matrix::Transponirai()
{
	short temp = 0;
	for (int i = 1; i < matrixSize; i++)
	{
		for (int j = i + 1; j < matrixSize; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

void Matrix::MultiplyScalar(const int a)
{
	for (int i = 0; i < matrixSize; i++)
		this->matrix[i][i] *= a;
}

short ** Multiply(const Matrix& a, const Matrix& b)
{
	short ** mult = new short*[5];
	for (int i = 0; i < matrixSize; i++)
	{
		mult[i] = new short[5];
		for (int j = 0; j < matrixSize; j++)
		{
			mult[i][j] = 0;
		}
	}

	// Multiplying matrix a and b and storing in an array mult.
	for (short i = 0; i < matrixSize; ++i)
		for (int j = 0; j < matrixSize; ++j)
			for (int k = 0; k < matrixSize; ++k)
			{
				mult[i][j] += a.matrix[i][k] * b.matrix[k][j];
			}
	return mult;
}

    void Matrix::Multiply(const Matrix& a)
    {
        short ** tmp = this->matrix;
        this->matrix = ::Multiply(*this, a);
        delete tmp;
    }
