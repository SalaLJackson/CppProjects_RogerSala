#include "DynArray.h"


 DynArray::DynArray() : m_capacity{ DYN_ARRAY_DEFAULT_SIZE }, m_size{ 0 }, m_data { new int[m_capacity] } 
// Al fer-ho fora dels claud�tors i amb els corchetes, no estem assignan valors, sin� que c
//estem cridant el "constructor de variables". Gracies a aix�, es diu que obtenim millor efici�ncia per el nostre programa tot i que el resultat es el mateix que el d'una assignaci� normal.
 {
 }

 DynArray::DynArray(size_t size, const int &value) : m_capacity{ size }, m_size{ size }, m_data{ new int[size] } 
// Param�tros o Par. Formals: S�n les dades necessaries per a la funci�; s�n expresades en la seva cap�elera.
// Atributs o Par. Reals: S�n les dades que nosaltres fiquem substituint als par�metres.
 {
	for(int i=0;i<m_size;i++)  // Tamb� podem utilitzar fill(begin(),end(),value), per� al ser tant simple, surt molt m�s a compte utilitzar un loop;
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
	for(int i=0;i<lhs.m_size;i++)
	{
		for(int j=0;j<rhs.m_size;j++)
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
	while(first!=last)
	{
		*first = value; // Asterisc, contingut del first.
		++first;        // Sense asterisc, direcci� del first.
	}
 }

 void DynArray::push(const int &val)
 {
	if(m_size==m_capacity)
	{
		int *tmp;
		// Copy
		tmp= new int[m_capacity + 1];
		for(int j=0;j<m_size;j++)
		{
			tmp[j] = m_data[j];
		}
		// Push
		delete m_data;
		m_data = tmp;
		m_capacity++;
	}
	m_data[m_size++] = val;
 }
