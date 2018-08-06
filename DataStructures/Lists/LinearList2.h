#pragma once

template <class T, class keyType>
class LinearList2
{
	T& frontOverloadHelper();
	T& backOverloadHelper();

	//used insert() to make sure that the 2 lists are not part of the same list,
	//as it is unknown which element may be first, then both elements' m_Next sequences are inspected
	//it is not expected to be triggered if the class is used correctly, but it is still a useful protection from undefined behavior
	bool ValidateListsNeverCross(const LinearList2<T, keyType> &, const LinearList2<T, keyType> &)const;
public:
	LinearList2();
	LinearList2(const T&, const keyType&);
	LinearList2(const T&, const keyType&, LinearList2&);
	LinearList2(const LinearList2&);
	LinearList2<T, keyType> & operator=(const LinearList2<T, keyType>&);
	~LinearList2();
	//ElementAccess

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;


	//Capacity

	bool empty()const;//the list is considered empty if it doesn't point to another list
	unsigned int size()const;//the amount of lists that are linked to the list


	//Modifiers

	void clear()noexcept;
	void insert(const keyType&, LinearList2<T, keyType>&);
	void pop_back();
private:
	T m_Data;
	keyType m_Key;
	LinearList2<T, keyType> * m_Next;
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
inline LinearList2<T, keyType>::~LinearList2()
{
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

template<class T, class keyType>
inline bool LinearList2<T, keyType>::empty() const
{
	return this->m_Next == nullptr;
}

template<class T, class keyType>
inline unsigned int LinearList2<T, keyType>::size() const
{
	LinearList2<T, keyType> * tmp = this->m_Next;
	unsigned int i = 0;
	while (tmp != nullptr)
	{
		++i;
		tmp = tmp->m_Next;
	}
	return i;
}

template<class T, class keyType>
inline void LinearList2<T, keyType>::clear() noexcept
{
	this->m_Next = nullptr;
}

template<class T, class keyType>
void LinearList2 <T, keyType>::insert(const keyType & srPos, LinearList2<T, keyType>& val)
{
	if (ValidateListsNeverCross(*this, val))
	{
		if (this->m_Key == srPos)
		{
			LinearList2<T, keyType> * tmp = this->m_Next;//not using a separate function because saving 3 lines is not worth losing the logic
			this->m_Next = &val;
			val.m_Next = tmp;
			return;
		}
		LinearList2<T, keyType> * tmp = this;
		while (tmp->m_Next != nullptr)
		{
			if (tmp->m_Next->m_Key == srPos)
			{
				LinearList2<T, keyType> * tmp2 = tmp->m_Next;
				tmp->m_Next = &val;
				val.m_Next = tmp2;
				return;
			}
			tmp = tmp->m_Next;
		}
		std::cerr << "Insert operation failed, no such key has been found\n";
	}
	else
	{
		std::cerr << "Insert operation failed, because the two lists are linked and this will cause an infinite loop\n";
	}
}

template<class T, class keyType>
inline void LinearList2<T, keyType>::pop_back()
{
	if (this->m_Next == nullptr)
	{
		std::cerr << "List is already empty\n";
	}
	else
	{
		LinearList2<T, keyType> * tmp = this;
		while (tmp->m_Next->m_Next != nullptr)
		{
			tmp = tmp->m_Next;
		}
		tmp->m_Next = nullptr;
	}
}

template<class T, class keyType>
inline bool LinearList2<T, keyType>::ValidateListsNeverCross(const LinearList2<T, keyType>& lhs, const LinearList2<T, keyType>& rhs) const
{
	LinearList2<T, keyType> * tmp = lhs.m_Next;
	while (tmp != nullptr)
	{
		if (tmp == &rhs)
		{
			return false;
		}
		tmp = tmp->m_Next;
	}
	tmp = rhs.m_Next;
	while (tmp != nullptr)
	{
		if (tmp == &lhs)
		{
			return false;
		}
		tmp = tmp->m_Next;
	}
	return true;
}