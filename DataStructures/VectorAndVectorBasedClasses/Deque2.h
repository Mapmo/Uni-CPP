#pragma once
#include "Vector.h"

template<class T>
class Deque2 : public Vector<T>
{
public:
	void pop_front();
	void push_front(const T&);
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

