#pragma once
#include "Deque.h"

template<class T>
class Queue4 : protected Deque<T>
{
	T& frontOverloadHelper();
	T& backOverloadHelper();
public:
	//Element access

	T & front();
	const T& front()const;
	T & back();
	const T& back()const;


	//	Capacity

	bool empty()const;
	unsigned int size()const;


	//Modifiers

	void push(const T&);
	void pop();


	//Non - member functions

	template <class T1>
	friend bool operator==(const Queue4<T1>&, const Queue4<T1>&);

	template <class T1>
	friend bool operator!=(const Queue4<T1>&, const Queue4<T1>&);

	template <class T1>
	friend void swap(Queue4<T1>&, Queue4<T1>&);
};

template<class T>
inline T & Queue4<T>::frontOverloadHelper()
{
	return Deque<T>::front();
}

template<class T>
inline T & Queue4<T>::front()
{
	return frontOverloadHelper();
}

template<class T>
inline const T & Queue4<T>::front() const
{
	return frontOverloadHelper();
}
