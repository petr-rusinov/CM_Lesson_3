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
	vector<vector<double>> m_array;
public:
	Matrix(size_t m, size_t n, const vector<vector<double>>& arr);
	double Determinant();
	double operator () (const size_t m, const size_t n);
	void SetElement(const size_t m, const size_t n, double value);
	friend ostream& operator << (ostream& out, Matrix& matrix);
};

