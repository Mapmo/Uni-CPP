#pragma once
#include "Deque.h"

template<class T>
class Queue4 : protected Deque<T>
{
	//although front() and back() are one line long, i still prefer to have functions in order to be able to edit both overloads at once if needed
	T& frontOverloadHelper();
	T& backOverloadHelper();
public:
	//Constructors
	Queue4();
	Queue4(const int, const T&);


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
inline T & Queue4<T>::backOverloadHelper()
{
	return Deque<T>::back();
}

template<class T>
inline Queue4<T>::Queue4() : Deque<T>()
{
}

template<class T>
inline Queue4<T>::Queue4(const int repeat, const T & val) : Deque<T>(repeat, val)
{
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

template<class T>
inline T & Queue4<T>::back()
{
	return backOverloadHelper();
}

template<class T>
inline const T & Queue4<T>::back() const
{
	return backOverloadHelper();
}
