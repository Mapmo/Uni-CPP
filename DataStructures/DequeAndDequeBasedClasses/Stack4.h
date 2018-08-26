#pragma once
#include "Deque.h"

template <class T>
class Stack4 : private Deque<T>
{
	T& topOverloadHelper();
public:
	//Element access

	T & top();
	const T& top()const;


	//Capacity

	bool empty() const;
	unsigned int size() const;


	//Modifiers

	void push(T&&);
	void pop();
	void swap(Stack2& other) noexcept;


	//Non-member functions
	template< class T1, class Container1 >
	friend bool operator==(const Stack2<T1, Container1>& lhs, const Stack2<T1, Container1>& rhs);

	template< class T2, class Container2 >
	friend bool operator!=(const Stack2<T2, Container2>& lhs, const Stack2<T2, Container2>& rhs);
};