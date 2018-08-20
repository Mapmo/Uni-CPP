#pragma once
const short matrixSize = 5;
class Matrix
{
private:
		short ** matrix = new short*[5];
public:
	Matrix();
	short ** MatrixGetter() const;
	void Transponirai();
	void MultiplyScalar(const int);
    void Multiply(const Matrix&);
	friend short ** Multiply(const Matrix&, const Matrix&);
};
