#pragma once
const short matrixSize = 5;
class Matrix
{
private:
		short ** matrix = new short*[5];
public:
	Matrix();
	short ** MatrixGetter() const;
	void MatrixSetter(short ** newMatrix);
	void Transponirai();
	void MultiplyScalar(int a);
	short ** Multiply(Matrix a, Matrix b);
};