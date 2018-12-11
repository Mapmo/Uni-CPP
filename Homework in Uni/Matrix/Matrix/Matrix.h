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
	template <class T2>
	friend Matrix<T2> operator *(const Matrix<T2>&, const Matrix<T2>&);
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
		DeleteMatrix();
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
	Matrix<T2> tmp(m1.ROWS, m2.COLUMNS);
	for (unsigned i = 0; i < m1.ROWS; ++i)
	{
		for (unsigned j = 0; j < m2.COLUMNS; ++j)
		{
			tmp.matrix[i][j] = 0;
			for (unsigned k = 0; k < m1.COLUMNS; ++k)
			{
				tmp.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
			}
		}
	}
	return tmp;
}