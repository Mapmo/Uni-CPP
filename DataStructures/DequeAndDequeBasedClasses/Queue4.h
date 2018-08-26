#pragma once
#include "Deque.h"
template<class T>
class Queue4<T> : protected Deque<T>
{
public:
	//Element access

	T & front();
	const T& front()const;
	T& back();
	const T& back()const;


	//	Capacity

	bool empty()const;
	unsigned int size()const;


	//Modifiers

	void push(const T&);
	void pop();


	//Non - member functions

	bool operator==(const Queue2<T>&);
	bool operator!=(const Queue2<T>&);
	template <class T1>
	friend void swap(Queue2<T1>&, Queue2<T1>&);
};