#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;


Matrix::Matrix(size_t m, size_t n, const vector<vector<double>>& arr)
{
	m_sizeM = m;
	m_sizeN = n;
	m_array.resize(m_sizeM);
	for (size_t i = 0; i < m_sizeM; ++i)
	{
		m_array[i].resize(m_sizeN);
	}

	for (size_t m = 0; m < m_sizeM; m++)
		copy(arr[m].begin(), arr[m].end(), m_array[m].begin());
}

double computeDet(size_t size, vector <vector<double>>& inputVec)
{
	double det = 0.0;
	if (size == 1)
		return inputVec[0][0];

	if (size == 2)
	{
		det = inputVec[0][0] * inputVec[1][1] - inputVec[0][1] * inputVec[1][0];
		return det;
	}
	if (size == 3)
	{
		//a11 × a22 × a33 + a31 × a12 × a23 + a21 × a32 × a13 − a31 × a22 × a13 − a21 × a12 × a33 − a11 × a23 × a32

		det = inputVec[0][0] * inputVec[1][1] * inputVec[2][2] +
			inputVec[2][0] * inputVec[0][1] * inputVec[1][2] +
			inputVec[1][0] * inputVec[2][1] * inputVec[0][2] -
			inputVec[2][0] * inputVec[1][1] * inputVec[0][2] -
			inputVec[1][0] * inputVec[0][1] * inputVec[2][2] -
			inputVec[0][0] * inputVec[1][2] * inputVec[2][1];
		return det;
	}
	if (size > 3)
	{
		//Разложение по 1-й строке
		vector<vector<double>> tempVec;
		tempVec.resize(size - 1);
		for (size_t m = 0; m < size - 1; ++m)
			tempVec[m].resize(size - 1);
		for (size_t col = 0; col < size; ++col)
		{
			//Создание миноров
			for (size_t row = 1; row < size; ++row)
			{
				copy(inputVec[row].begin(), inputVec[row].begin()+col, tempVec[row - 1].begin());
				copy(inputVec[row].begin() + col + 1, inputVec[row].end(), tempVec[row - 1].begin()  + col );
			}
			//Рекурсивный вызов для определения детерминантов миноров
			det += pow((-1), 1 + (col + 1)) * inputVec[0][col] * computeDet(size - 1, tempVec);
		}
	}
	return det;
}

double Matrix::Determinant()
{
	return computeDet(m_sizeM, m_array);
}

double Matrix::operator()(const size_t m, const size_t n)
{
	return m_array[m][n];
}

void Matrix::SetElement(const size_t m, const size_t n, double value)
{
	m_array[m][n] = value;
}

ostream& operator << (ostream& out, Matrix& matrix)
{
	for (size_t m = 0; m < matrix.m_sizeM; m++)
	{
		for (size_t n = 0; n < matrix.m_sizeN; n++)
			out << matrix(m, n) << " ";
		out << endl;
	}
	return out;
}