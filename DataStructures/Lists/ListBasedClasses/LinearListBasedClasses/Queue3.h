#pragma once
#include "..\..\LinearLists\LinearList2.h"

template<class T, class keyType = int>
class Queue3 : private LinearList1<T, keyType>
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
	void pop();
	void push(const T&);
	void push(LinearList1<T, keyType>&);
};

template<class T, class keyType>
inline T & Queue3<T, keyType>::front()
{
	return LinearList1<T, keyType>::front();
}

template<class T, class keyType>
inline const T & Queue3<T, keyType>::front() const
{
	return LinearList1<T, keyType>::front();
}

template<class T, class keyType>
inline T & Queue3<T, keyType>::back()
{
	return return LinearList2<T, keyType>::back();
}

template<class T, class keyType>
inline const T & Queue3<T, keyType>::back() const
{
	return LinearList1<T, keyType>::back();
}

template<class T, class keyType>
inline bool Queue3<T, keyType>::empty() const
{
	return LinearList1<T, keyType>::empty();
}

template<class T, class keyType>
inline unsigned int Queue3<T, keyType>::size() const
{
	return LinearList1<T, keyType>::size();
}

template<class T, class keyType>
inline void Queue3<T, keyType>::clear() noexcept
{
	LinearList1<T, keyType>::clear();
}

template<class T, class keyType>
inline void Queue3<T, keyType>::pop()
{
	LinearList1<T, keyType>::pop_front();
}

template<class T, class keyType>
inline void Queue3<T, keyType>::push(const T & rhs)
{
	LinearList1<T, keyType> tmp(rhs);
	LinearList1<T, keyType>::push_back(tmp);
}

template<class T, class keyType>
inline void Queue3<T, keyType>::push(LinearList1<T, keyType>& rhs)
{
	LinearList1<T, keyType>::push_back(rhs);
}
