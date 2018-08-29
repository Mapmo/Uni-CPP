#pragma once
#include "../LinkedLists/LinkedList1.h"

template <class T, class keyType>
class List
{
	void CopyListData(const LinkedList1<T, keyType>*);//the function is 20 lines code, but there are a lot of comments
	void CopyListData(const List<T, keyType>&);
public:
	List();
	explicit List(const LinkedList1<T, keyType>&);
	List(const List<T, keyType>&);
	~List();
private:
	LinkedList1<T, keyType> * m_Beg;
	LinkedList1<T, keyType> * m_End;
	LinkedList1<T, keyType> * m_List;
};

template<class T, class keyType>
inline void List<T, keyType>::CopyListData(const LinkedList1<T, keyType> * rhs)
{
	this->m_List = new LinkedList1<T, keyType>(*rhs);
	//now m_List points to a new List that has the same data as rhs.m_List, but does not point anywhere,
	//because LinkedList1's cpy ctor and operator= only copies the data of the element it points to
	//therefore now I need to manually iterate the whole rhs and copy its data into this one

	const LinkedList1<T, keyType> * tmp = rhs;//iterates through rhs
	LinkedList1<T, keyType> * tmp2 = this->m_List;//links the new elements in this
	LinkedList1<T, keyType> * tmp3 = nullptr;//used for updates, because I cannot directly update the return of the function
	while (tmp->Prev() != nullptr)
	{
		tmp = tmp->Prev();

		//e.g tmp2->m_Prev = new...
		tmp3 = tmp2->Prev();
		tmp3= new LinkedList1<T, keyType>(*tmp);

		//e.g tmp2->m_Prev->m_Next = tmp2
		tmp3 = tmp2->Prev()->Next();
		tmp = tmp2;
		tmp2 = tmp2->Prev();
	}
	this->m_Beg = tmp3;//the last created element, which is ironicly the first element in the sequence
	tmp = rhs;
	tmp2 = this->m_List;
	while (tmp->Next() != nullptr)
	{
		tmp = tmp->Next();

		//e.g tmp2->m_Next() = new....
		tmp3 = tmp2->Next();
		tmp3 = new LinkedList1<T, keyType>(*tmp);

		//e.g tmp2->m_Next->m_Prev = tmp2
		tmp3 = tmp2->Next()->Prev();
		tmp3 = tmp2;

		tmp2 = tmp2->Next();
	}
	this->m_End = tmp3;//the last created element
}

template<class T, class keyType>
inline void List<T, keyType>::CopyListData(const List<T, keyType>& rhs)
{
	CopyListData(rhs.m_List);
}

template<class T, class keyType>
inline List<T, keyType>::List() : m_List(nullptr), m_Beg(nullptr), m_End(nullptr)
{
}

template<class T, class keyType>
inline List<T, keyType>::List(const LinkedList1<T, keyType>&rhs)
{
	CopyListData(&rhs);
}

template<class T, class keyType>
inline List<T, keyType>::List(const List<T, keyType>& rhs)
{
	CopyListData(rhs);
}

template<class T, class keyType>
inline List<T, keyType>::~List()
{
	delete this->m_List;
}
