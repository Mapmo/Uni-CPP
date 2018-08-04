#pragma once
template <class T>
class sharedPtrContainer
{
public:
	sharedPtrContainer();
	sharedPtrContainer(const T&);
	~sharedPtrContainer();

	const T& operator *()const;
	void UpdateCount(bool);

	unsigned int GetCount()const;
	T * GetDataAddress();
private:
	sharedPtrContainer(const sharedPtrContainer<T>&);
	unsigned int m_Count;
	T m_Data;
};

template<class T>
inline sharedPtrContainer<T>::sharedPtrContainer() : m_Count(1), m_Data()
{
}

template<class T>
inline sharedPtrContainer<T>::sharedPtrContainer(const T & rhs) : m_Count(1), m_Data(rhs)
{
}

template<class T>
inline sharedPtrContainer<T>::~sharedPtrContainer()
{
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
inline T * sharedPtrContainer<T>::GetDataAddress()
{
	return &(this->m_Data);
}
