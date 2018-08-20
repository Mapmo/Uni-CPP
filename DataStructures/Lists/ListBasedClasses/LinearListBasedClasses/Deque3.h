#pragma once
#pragma once
#include "..\..\LinearLists\LinearList2.h"

template<class T, class keyType = int>
class Deque3 : private LinearList1<T, keyType>
{
public:

	//ElementAccess

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;


	//Capacity

	bool empty()const;
	unsigned int size()const;//the amount of lists that are linked to the list


	//Modifiers

	void clear()noexcept;
	T pop_back();
	T pop_front();
	void push_back(const T&);
	void push_back(LinearList1<T, keyType>&);
	void push_front(const T&);
	void push_front(LinearList1<T, keyType>&);
};

template<class T, class keyType>
inline T & Deque3<T, keyType>::front()
{
	return LinearList1<T, keyType>::front();
}

template<class T, class keyType>
inline const T & Deque3<T, keyType>::front() const
{
	return LinearList1<T, keyType>::front();
}

template<class T, class keyType>
inline T & Deque3<T, keyType>::back()
{
	return LinearList1<T, keyType>::back();
}

template<class T, class keyType>
inline const T & Deque3<T, keyType>::back() const
{
	return LinearList1<T, keyType>::back();
}

template<class T, class keyType>
inline bool Deque3<T, keyType>::empty() const
{
	return LinearList1<T, keyType>::empty();
}

template<class T, class keyType>
inline unsigned int Deque3<T, keyType>::size() const
{
	return LinearList1<T, keyType>::size();
}

template<class T, class keyType>
inline void Deque3<T, keyType>::clear() noexcept
{
	LinearList1<T, keyType>::clear();
}

template<class T, class keyType>
inline T Deque3<T, keyType>::pop_back()
{
	T tmp = back();
	LinearList1<T, keyType>::pop_back();
	return tmp;
}

template<class T, class keyType>
inline T Deque3<T, keyType>::pop_front()
{
	T tmp = front();
	LinearList1<T, keyType>::pop_front();
	return tmp;
}

template<class T, class keyType>
inline void Deque3<T, keyType>::push_back(const T & rhs)
{
	LinearList1<T, keyType> tmp(rhs);
	LinearList1<T, keyType>::push_back(tmp);
}

template<class T, class keyType>
inline void Deque3<T, keyType>::push_back(LinearList1<T, keyType>& rhs)
{
	LinearList1<T, keyType>::push_back(rhs);
}

template<class T, class keyType>
inline void Deque3<T, keyType>::push_front(const T & rhs)
{
	LinearList1<T, keyType> tmp(rhs);
	LinearList1<T, keyType>::push_front(tmp);
}

template<class T, class keyType>
inline void Deque3<T, keyType>::push_front(LinearList1<T, keyType>& rhs)
{
	LinearList1<T, keyType>::push_front(rhs);
}
