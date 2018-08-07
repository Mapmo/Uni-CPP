#pragma once
#include "Vector.h"
template <class T>
class Queue2
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

	bool operator==(const Queue2<T>&);
	bool operator!=(const Queue2<T>&);
	template <class T1>
	friend void swap(Queue2<T1>&, Queue2<T1>&);

private:
	Vector<T> m_Data;
};

template<class T>
inline const T & Queue2<T>::front() const
{
	return this->m_Data.front();
}

template<class T>
inline const T & Queue2<T>::back() const
{
	return this->m_Data.back();
}

template<class T>
inline bool Queue2<T>::empty() const
{
	return this->m_Data.empty();
}

template<class T>
inline unsigned int Queue2<T>::size() const
{
	return this->m_Data.size();
}

template<class T>
inline void Queue2<T>::push(const T & rhs)
{
	this->m_Data.push_back(rhs);
}

template<class T>
inline void Queue2<T>::pop()
{
	this->m_Data.erase(0);
}

template<class T>
inline bool Queue2<T>::operator==(const Queue2<T>& rhs)
{
	return this->m_Data== rhs.m_Data;
}

template<class T>
inline bool Queue2<T>::operator!=(const Queue2<T>&rhs)
{
	return !operator==(rhs);
}

template <class T1>
inline void swap(Queue2<T1>&lhs, Queue2<T1>&rhs)
{
	swap(lhs.m_Data, rhs.m_Data);
}
