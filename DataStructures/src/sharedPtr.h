#pragma once
#include "sharedPtrContainer.h"
template <class T>
class sharedPtr
{
public:
	sharedPtr(const T&);
	sharedPtr(const sharedPtr<T>&);
	sharedPtr<T>& operator=(const sharedPtr<T>&);
	~sharedPtr();

	const T & operator*() const;

private:
	sharedPtrContainer<T> * m_Container;
};

template<class T>
inline sharedPtr<T>::sharedPtr(const T & rhs)
{
	this->m_Container = new sharedPtrContainer<T>(rhs);
}

template<class T>
inline sharedPtr<T>::sharedPtr(const sharedPtr<T> & rhs)
{
	this->m_Container = rhs.m_Container;
	this->m_Container->UpdateCount(1);
}

template<class T>
inline sharedPtr<T> & sharedPtr<T>::operator=(const sharedPtr<T> & rhs)
{
	if (this != &rhs)
	{
		this->m_Container->UpdateCount(0);
		if (this->m_Container->GetCount() == 0)
		{
			delete this->m_Container;
		}
		this->m_Container = rhs.m_Container;
		this->m_Container->UpdateCount(1);
	}
	return *this;
}

template<class T>
inline sharedPtr<T>::~sharedPtr()
{
	this->m_Container->UpdateCount(0);
	if (this->m_Container->GetCount() == 0)
	{
		delete this->m_Container;
	}
}

template<class T>
inline const T & sharedPtr<T>::operator*() const
{
	return *(*(this->m_Container));
}

