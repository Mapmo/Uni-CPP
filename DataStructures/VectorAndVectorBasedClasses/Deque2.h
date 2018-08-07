#pragma once
#include "Vector.h"

template<class T>
class Deque2 : public Vector<T>
{
public:
	void pop_front();
	void push_front(const T&);
	//template <class T1>
	//void friend swap(Deque2<T1>&, Deque2<T1>&);
private:
};

template<class T>
inline void Deque2<T>::pop_front()
{
	Vector<T>::erase(0);
}

template<class T>
inline void Deque2<T>::push_front(const T & rhs)
{
	Vector<T>::insert(0, rhs);
}

/*
template<class T1>
inline void swap(Deque2<T1>& lhs, Deque2<T1>& rhs)
{
	Vector<T1>::swap(lhs, rhs);
}
*/
