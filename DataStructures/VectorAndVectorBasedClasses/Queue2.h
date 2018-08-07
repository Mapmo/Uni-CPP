#pragma once
#include "Vector.h"
template <class T>
class Queue
{
public:
	//Element access

	const T& front()const;
	const T& back()const;


	//	Capacity

	bool empty()const;
	unsigned int size()const;


	//Modifiers

	void push(const T&);
	void pop();


	//Non - member functions

	bool operator==(const Queue<T>&);
	bool operator!=(const Queue<T>&);
	void swap(Queue<T>&, Queue<T>&);

private:
	Vector<T> m_Data;
};