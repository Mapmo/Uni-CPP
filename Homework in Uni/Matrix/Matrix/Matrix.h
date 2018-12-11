#pragma once
#include <iostream>

template <class T>
class Matrix
{
	void InitializeMatrix(); //used in the big 4
	void CopyDataOfMatrix(const Matrix<T>&);
	void DeleteMatrix();
public:
	//big 4
	Matrix(const unsigned, const unsigned);
	Matrix(const Matrix<T> &);
	Matrix<T> & operator = (const Matrix<T>&);
	~Matrix();

	//Basic Operations
	const T& GetCell(const unsigned, const unsigned);
	void SetData();
	void SetData(T**);//used for Unit testing, use it wisely
	void Print();

	//Matrix Operations
	Matrix<T> Transpose();

	template <class T2>
	friend Matrix<T2> operator *(const Matrix<T2>&, const Matrix<T2>&);
	Matrix<T>& operator *= (const Matrix<T>&);
	Matrix<T>& Pow(const unsigned);//intentionally only for positives
private:
	const unsigned ROWS;
	const unsigned COLUMNS;
	T * * matrix;
};

template<class T>
inline void Matrix<T>::InitializeMatrix()
{
	this->matrix = new T *[ROWS];
	for (unsigned i = 0; i < ROWS; ++i)
	{
		this->matrix[i] = new T[COLUMNS];
	}
}

template<class T>
inline void Matrix<T>::CopyDataOfMatrix(const Matrix<T> & rhs)
{
	for (unsigned i = 0; i < ROWS; ++i)
	{
		for (unsigned j = 0; j < COLUMNS; ++j)
		{
			this->matrix[i][j] = rhs.matrix[i][j];
		}
	}
}

template<class T>
inline void Matrix<T>::DeleteMatrix()
{
	for (unsigned i = 0; i < ROWS; ++i)
	{
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
}

template<class T>
inline Matrix<T>::Matrix(const unsigned row, const unsigned col) : ROWS(row), COLUMNS(col)
{
	InitializeMatrix();
}

template<class T>
inline Matrix<T>::Matrix(const Matrix<T> & rhs) : ROWS(rhs.ROWS), COLUMNS(rhs.COLUMNS)
{
	InitializeMatrix();
	CopyDataOfMatrix(rhs);
}

template<class T>
inline Matrix<T> & Matrix<T>::operator=(const Matrix<T> & rhs)
{
	if (this != &rhs)
	{
		CopyDataOfMatrix(rhs);
	}
	return *this;
}

template<class T>
inline Matrix<T>::~Matrix()
{
	DeleteMatrix();
}

template<class T>
inline const T& Matrix<T>::GetCell(const unsigned row, const unsigned col)
{
	return this->matrix[row][col];
}

template<class T>
inline void Matrix<T>::SetData()
{
	for (unsigned i = 0; i < ROWS; ++i)
	{
		for (unsigned j = 0; j < COLUMNS; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}
}

template<class T>
inline void Matrix<T>::SetData(T ** rhs)
{
	for (unsigned i = 0; i < ROWS; ++i)
	{
		for (unsigned j = 0; j < COLUMNS; ++j)
		{
			matrix[i][j] = rhs[i][j];
		}
	}
}

template<class T>
inline void Matrix<T>::Print()
{
	for (unsigned i = 0; i < ROWS; ++i)
	{
		for (unsigned j = 0; j < COLUMNS; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

template <class T2>
inline Matrix<T2> operator*(const Matrix<T2>&m1, const Matrix<T2>&m2)
{
	if (m1.COLUMNS != m2.ROWS)
	{
		throw std::length_error("Matrices that cannot be multiplied given\n");
	}
	Matrix<T2> tmp(m1.ROWS, m2.COLUMNS);
	T2 buffer = 0;
	for (unsigned i = 0; i < m1.ROWS; ++i)
	{
		for (unsigned j = 0; j < m2.COLUMNS; ++j)
		{
			buffer = 0;
			for (unsigned k = 0; k < m1.COLUMNS; ++k)
			{
				buffer += m1.matrix[i][k] * m2.matrix[k][j];
			}
			tmp.matrix[i][j] = buffer;
		}
	}
	return tmp;
}

template<class T>
inline Matrix<T> & Matrix<T>::operator*=(const Matrix<T>& rhs)
{
	T buffer = 0;
	if (this->ROWS != rhs.COLUMNS)
	{
		throw std::length_error("This Matrix implementation does not support *= that canges the size of the original matrix\n");
	}
	*this = *this * rhs;
	return *this;
}
template<class T>
inline Matrix<T> Matrix<T>::Transpose()
{
	Matrix<T> tmp(COLUMNS, ROWS);
	for (unsigned i = 0; i < ROWS; ++i)
	{
		for (unsigned j = 0; j < COLUMNS; ++j)
		{
			tmp.matrix[j][i] = this->matrix[i][j];
		}
	}
	return tmp;
}

template <class T>
inline Matrix<T>& Matrix<T>::Pow(const unsigned numb)
{
	if (ROWS != COLUMNS)
	{
		throw std::length_error("In order to pow you need a square matrix\n");
	}
	unsigned tmp = numb;
	if (tmp > 1)
	{
		Matrix<T> a = *this;
		while (--tmp)
		{
			a *= *this;
		}
		*this = a;
	}
	else if (tmp == 0)
	{
		for (unsigned i = 0; i < ROWS; ++i)
		{
			for (unsigned j = 0; j < ROWS; ++j)
			{
				matrix[i][j] = (i == j ? 1 : 0);
			}
		}
	}

	return *this;
}