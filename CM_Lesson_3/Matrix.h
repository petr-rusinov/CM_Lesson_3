#pragma once
#include <array>
#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
private:
	//array<array<double, 
	size_t m_sizeM, m_sizeN;
	vector<vector<int>> m_array;
public:
	Matrix();
	Matrix(size_t m, size_t n);
	Matrix(size_t m, size_t n, const vector<vector<int>>& arr);
	double Determinant();
	int operator () (const size_t m, const size_t n);
	void SetElement(const size_t m, const size_t n, int value);
	//friend ostream& operator << (ostream& out, const Matrix& matrix);
};

