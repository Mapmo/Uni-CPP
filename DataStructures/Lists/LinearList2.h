#pragma once

template <class T, class keyType>
class LinearList2
{ 
	T& frontOverloadHelper();
	T& backOverloadHelper();
public:
	LinearList2();
	LinearList2(const T&, const keyType&);
	LinearList2(const T&, const keyType&, LinearList2&);
	LinearList2(const LinearList2&);
	LinearList2<T, keyType> & operator=(const LinearList2<T, keyType>&);

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

private:
	T m_Data;
	keyType m_Key;
	LinearList2<T, keyType>* m_Next;
};

template<class T, class keyType>
inline T& LinearList2<T, keyType>::frontOverloadHelper()
{
	return this->m_Data;
}

template<class T, class keyType>
inline T & LinearList2<T, keyType>::backOverloadHelper()
{
	if (this->m_Next != nullptr)
	{
		LinearList2 * ptr = this->m_Next;

		while (ptr->m_Next != nullptr)
		{
			ptr = ptr->m_Next;
		}
		return ptr->m_Data;
	}
	return this->m_Data;
}

template<class T, class keyType>
inline LinearList2<T, keyType>::LinearList2() : m_Key(), m_Data(), m_Next(nullptr)
{
}

template<class T, class keyType>
inline LinearList2<T, keyType>::LinearList2(const T & data, const keyType & key) : m_Data(data), m_Key(key), m_Next(nullptr)
{
}

template<class T, class keyType>
inline LinearList2<T, keyType>::LinearList2(const T& data, const keyType & key, LinearList2<T, keyType>& next) : m_Data(data), m_Key(key)
{
	this->m_Next = &next;
}

template<class T, class keyType>
inline LinearList2<T, keyType>::LinearList2(const LinearList2<T, keyType> & rhs) : m_Data(rhs.m_Data), m_Key(rhs.m_Key), m_Next(nullptr)
{
}

template<class T, class keyType>
inline LinearList2<T, keyType> & LinearList2<T, keyType>::operator=(const LinearList2<T, keyType> & rhs)
{
	if (this != &rhs)
	{
		this->m_Key = rhs.m_Key;
		this->m_Data = rhs.m_Data;
	}
	return *this;
}

template<class T, class keyType>
inline T& LinearList2<T, keyType>::front()
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline const T & LinearList2<T, keyType>::front() const
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline T & LinearList2<T, keyType>::back()
{
	return backOverloadHelper();
}

template<class T, class keyType>
inline const T & LinearList2<T, keyType>::back() const
{
	return backOverloadHelper();
}