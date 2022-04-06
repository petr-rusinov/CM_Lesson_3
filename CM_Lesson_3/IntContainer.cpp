#include "IntContainer.h"

ostream& operator<< (ostream& out, const IntContainer& ic)
{
	for (size_t i = 0; i < ic.m_size; ++i)
		out << ic.m_array[i] << " ";
	return out;
}
