#pragma once

class IntRange
{
private:
	const int m_from;
	const int m_to;
public:
	IntRange(int from, int to) : m_from(from), m_to(to) {}

	class iterator
	{
	private:
		int m_num;
	public:
		explicit iterator(int num = 0) : m_num(num) {}
		iterator& operator++() { ++m_num; return *this; }
		bool operator == (iterator it) const { return m_num == it.m_num; }
		bool operator != (iterator it) const { return m_num != it.m_num; }
		int operator* () const { return m_num; }

	};

	iterator begin() { return iterator(m_from); }
	iterator end() { return iterator(m_to+1); }


};

