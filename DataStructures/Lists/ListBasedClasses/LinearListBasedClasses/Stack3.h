#pragma once
#pragma once
#include "..\..\LinearLists\LinearList2.h"

template<class T, class keyType = int>
class Stack3 : private LinearList1<T, keyType>
{
public:

	//Element access

	T & top();
	const T& top()const;

	//Capacity

	bool empty()const;
	unsigned int size()const;//the amount of lists that are linked to the list


	//Modifiers

	void clear()noexcept;
	T pop();
	void push(const T&);
	void push(LinearList1<T, keyType>&);
};

template<class T, class keyType>
inline T & Stack3<T, keyType>::top()
{
	return LinearList1<T, keyType>::back();
}

template<class T, class keyType>
inline const T & Stack3<T, keyType>::top() const
{
	return LinearList1<T, keyType>::back();
}

template<class T, class keyType>
inline bool Stack3<T, keyType>::empty() const
{
	return LinearList1<T, keyType>::empty();
}

template<class T, class keyType>
inline unsigned int Stack3<T, keyType>::size() const
{
	return LinearList1<T, keyType>::size();
}

template<class T, class keyType>
inline void Stack3<T, keyType>::clear() noexcept
{
	LinearList1<T, keyType>::clear();
}

template<class T, class keyType>
inline T Stack3<T, keyType>::pop()
{
	T tmp = top();
	LinearList1<T, keyType>::pop_back();
	return tmp;
}

template<class T, class keyType>
inline void Stack3<T, keyType>::push(const T & rhs)
{
	LinearList1<T, keyType> tmp(rhs);
	LinearList1<T, keyType>::push_back(tmp);
}

template<class T, class keyType>
inline void Stack3<T, keyType>::push(LinearList1<T, keyType>& rhs)
{
	LinearList1<T, keyType>::push_back(rhs);
}
