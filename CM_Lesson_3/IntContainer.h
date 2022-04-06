#pragma once
#include <iostream>

using namespace std;

class IntContainer
{
private:
	int* m_array;
	size_t m_size;

public:
	class Iterator;

	IntContainer(size_t size = 1) : m_size(size)
	{
		m_array = new int[size];
	}
	~IntContainer()
	{
		delete[] m_array;
	}

	int& operator[] (const size_t& n)
	{
		if (n > 0 && n < m_size)
			return m_array[n];
		return m_array[0];
	}
	
	Iterator begin() { return m_array; }
	Iterator end() { return m_array + m_size; }
	friend ostream& operator<< (ostream& out, const IntContainer& ic);
	class Iterator
	{
	private:
		int* currentIt;
	public:
		Iterator(int* it) : currentIt(it) {}
		int& operator+ (size_t n) { return *(currentIt + n); }


		bool operator!= (const Iterator& it) { return currentIt != it.currentIt; }
		bool operator== (const Iterator& it) { return currentIt == it.currentIt; }
		int& operator++ () { return *currentIt++; }
		int& operator* () { return *currentIt; }
	};

};
