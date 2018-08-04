#pragma once

template <class T>
class sharedPtrContainer
{
public:
	sharedPtrContainer(const T&);
	~sharedPtrContainer();

	const T * operator->()const;
	const T& operator *()const;
	void UpdateCount(bool);

	unsigned int GetCount()const;
private:
	sharedPtrContainer(const sharedPtrContainer<T>&);
	sharedPtrContainer<T>& operator=(const sharedPtrContainer<T>&);
	unsigned int m_Count;
	const T * m_Data;
};

template<class T>
inline sharedPtrContainer<T>::sharedPtrContainer(const T & rhs) : m_Count(1)
{
	this->m_Data = new T(rhs);
}

template<class T>
inline sharedPtrContainer<T>::~sharedPtrContainer()
{
	delete this->m_Data;
	std::cout << "Data erased\n";
}

template<class T>
inline const T * sharedPtrContainer<T>::operator->() const
{
	return *(this->m_Data);
}

template<class T>
inline const T & sharedPtrContainer<T>::operator*() const
{
	return this->m_Data;
}

template<class T>
inline void sharedPtrContainer<T>::UpdateCount(bool increment)
{
	this->m_Count += (increment) ? 1 : -1;
}

template<class T>
inline unsigned int sharedPtrContainer<T>::GetCount() const
{
	return this->m_Count;
}

template<class T>
inline sharedPtrContainer<T> & sharedPtrContainer<T>::operator=(const sharedPtrContainer<T> &)
{
	return *this;
}
