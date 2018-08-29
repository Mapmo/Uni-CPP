#pragma once
#include "../LinkedLists/LinkedList1.h"

template <class T, class keyType>
class List
{
public:
	List();
	explicit List(LinkedList1<T, keyType>);
	~List();
private:
	LinkedList1<T, keyType> * m_Beg;
	LinkedList1<T, keyType> * m_End;
	LinkedList1<T, keyType> * m_List;
};

template<class T, class keyType>
inline List<T, keyType>::List() : m_List(nullptr), m_Beg(nullptr), m_End(nullptr)
{
}

template<class T, class keyType>
inline List<T, keyType>::List(LinkedList1<T, keyType> rhs) : m_List(new LinkedList1<T, keyType>(rhs))
{
	this->m_Beg = m_List->begin();
	this->m_End = m_List->end();
}

template<class T, class keyType>
inline List<T, keyType>::~List()
{
	delete this->m_List;
}
