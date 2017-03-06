#include "DynArray.h"

 void main()
 {
	 DynArray m;
 }

 DynArray::DynArray() : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ 0 },m_data{ nullptr }
 {
	 m_data = new int[ DYN_ARRAY_DEFAULT_SIZE ];
 }

 DynArray::DynArray(size_t size, const int &value) : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ size }
 {
	m_data = new int[ DYN_ARRAY_DEFAULT_SIZE ];
	for(int i=0;i<m_size;i++)
	{
		m_data[i] = value;
	}
 }

 DynArray::~DynArray(void)
 {
	 delete[] m_data;
	 m_data=nullptr;
 }

 int* DynArray::begin(void) const
 {
	 return &m_data[0];
 }

 int* DynArray::end(void) const
 {
	 return &m_data[m_size-1];
 }

 int& DynArray:: operator[](size_t n) const
 {
	 return m_data[n];
 }

 bool operator== (const DynArray& lhs, const DynArray& rhs)
 {
	for(int i=0;i++;i<m_size)
	{
		for(int j=0;j++;j<m_size)
		{
			if(&lhs[i]!=&rhs[j])
			{
				return false;
			}
		}
	}
	return true;
 }

 void DynArray::fill(int *first, int *last, int value)
 {
	int *c = first;
	while(c!=last)
	{
		*c = value;
		c++;
	}
 }
