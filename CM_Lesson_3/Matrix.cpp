#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix():Matrix(1, 1)
{
}

Matrix::Matrix(size_t m, size_t n) : m_sizeM(m), m_sizeN(n)
{

}

Matrix::Matrix(size_t m, size_t n, const vector<vector<int>>& arr)
{
	m_sizeM = m;
	m_sizeN = n;
	m_array.resize(m_sizeM);
	m_array[0].resize(m_sizeN);
	m_array[1].resize(m_sizeN);
	m_array[2].resize(m_sizeN);
	for (size_t m = 0; m < m_sizeM; m++)
		for (size_t n = 0; n < m_sizeN; n++)
		{
			m_array[m][n] = arr[m][n];
		}
}

double Matrix::Determinant()
{
	return 0.0;
}

int Matrix::operator()(const size_t m, const size_t n)
{
	return m_array[m][n];
}

void Matrix::SetElement(const size_t m, const size_t n, int value)
{
	m_array[m][n] = value;
}

//ostream& operator << (ostream& out, const Matrix& matrix)
//{
//	for (size_t m = 0; m < 3; m++)
//	{
//		for (size_t n = 0; n < 3; n++)
//			out << matrix(m, n) << " ";
//		out << endl;
//	}
//	return out;
//}