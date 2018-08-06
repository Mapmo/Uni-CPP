#pragma once

template <class T, class keyType>
class LinearList1
{
	T& frontOverloadHelper();
	T& backOverloadHelper();

	//used for operator= and insert() to make sure that the 2 lists are not part of the same list,
	//as it is unknown which element may be first, then both elements' m_Next sequences are inspected
	//it is not expected to be triggered if the class is used correctly, but it is still a useful protection from undefined behavior
	bool ValidateListsNeverCross(const LinearList1<T, keyType> &, const LinearList1<T, keyType> &)const;

	void InsertCodeReusing(LinearList1<T, keyType>* tmp, LinearList1<T, keyType>&val);
public:
	LinearList1();
	LinearList1(const T&, const keyType&);
	LinearList1(const T&, const keyType&, LinearList1&);
	LinearList1(const LinearList1&);
	LinearList1<T, keyType> & operator=(const LinearList1<T, keyType>&);
	~LinearList1();


	//Element Access

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;


	//Capacity

	bool empty()const;//the list is considered empty if it doesn't point to another list
	unsigned int size()const;//the amount of lists that are linked to the list


	//Modifiers

	void clear()noexcept;
	void insert(const keyType& srPos, LinearList1<T, keyType>& val);
	void insert(const keyType& srPo, const keyType& trPos, const T& val);
	void pop_back();
private:
	T m_Data;
	keyType m_Key;
	LinearList1<T, keyType>* m_Next;
};

template<class T, class keyType>
inline T& LinearList1<T, keyType>::frontOverloadHelper()
{
	return this->m_Data;
}

template<class T, class keyType>
inline T & LinearList1<T, keyType>::backOverloadHelper()
{
	if (this->m_Next != nullptr)
	{
		LinearList1 * ptr = this->m_Next;

		while (ptr->m_Next != nullptr)
		{
			ptr = ptr->m_Next;
		}
		return ptr->m_Data;
	}
	return this->m_Data;
}

template<class T, class keyType>
inline bool LinearList1<T, keyType>::ValidateListsNeverCross(const LinearList1<T, keyType>& lhs, const LinearList1<T, keyType>& rhs) const
{
	LinearList1<T, keyType> * tmp = lhs.m_Next;
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

template<class T, class keyType>
inline void LinearList1<T, keyType>::InsertCodeReusing(LinearList1<T, keyType>* tmp, LinearList1<T, keyType>&val)
{
	LinearList1<T, keyType> * tmp2 = new LinearList1<T, keyType>(val);
	LinearList1<T, keyType> * tmp3 = tmp->m_Next;
	tmp->m_Next = tmp2;
	while (tmp->m_Next != nullptr)
	{
		tmp = tmp->m_Next;
	}
	tmp->m_Next = tmp3;
}

template<class T, class keyType>
inline LinearList1<T, keyType>::LinearList1() : m_Key(), m_Data(), m_Next(nullptr)
{
}

template<class T, class keyType>
inline LinearList1<T, keyType>::LinearList1(const T & data, const keyType & key) : m_Data(data), m_Key(key), m_Next(nullptr)
{
}

template<class T, class keyType>
inline LinearList1<T, keyType>::LinearList1(const T& data, const keyType & key, LinearList1<T, keyType>& next) : m_Data(data), m_Key(key)
{
	this->m_Next = new LinearList1<T, keyType>(next);
}

template<class T, class keyType>
inline LinearList1<T, keyType>::LinearList1(const LinearList1<T, keyType> & rhs) : m_Data(rhs.m_Data), m_Key(rhs.m_Key)
{
	if (rhs.m_Next != nullptr)
	{
		this->m_Next = new LinearList1<T, keyType>(*(rhs.m_Next));
	}
	else
	{
		this->m_Next = nullptr;
	}
}

template<class T, class keyType>
inline LinearList1<T, keyType> & LinearList1<T, keyType>::operator=(const LinearList1<T, keyType> & rhs)
{
	if (ValidateListsNeverCross(*this, rhs))
	{
		if (this != &rhs)
		{
			this->m_Key = rhs.m_Key;
			this->m_Data = rhs.m_Data;
			if (rhs.m_Next != nullptr)
			{
				this->m_Next = new LinearList1<T, keyType>(*(rhs.m_Next));
			}
			else
			{
				this->m_Next = nullptr;
			}
		}
	}
	else
	{
		std::cerr << "Operator = failed, because the two lists cross somewhere\n";
	}
	return *this;
}

template<class T, class keyType>
inline LinearList1<T, keyType>::~LinearList1()
{
	delete this->m_Next;
}

template<class T, class keyType>
inline T& LinearList1<T, keyType>::front()
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline const T & LinearList1<T, keyType>::front() const
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline T & LinearList1<T, keyType>::back()
{
	return backOverloadHelper();
}

template<class T, class keyType>
inline const T & LinearList1<T, keyType>::back() const
{
	return backOverloadHelper();
}

template<class T, class keyType>
inline bool LinearList1<T, keyType>::empty() const
{
	return this->m_Next == nullptr;
}

template<class T, class keyType>
inline unsigned int LinearList1<T, keyType>::size() const
{
	LinearList1<T, keyType> * tmp = this->m_Next;
	unsigned int i = 0;
	while (tmp != nullptr)
	{
		++i;
		tmp = tmp->m_Next;
	}
	return i;
}

template<class T, class keyType>
inline void LinearList1<T, keyType>::clear() noexcept
{
	delete this->m_Next;
	this->m_Next = nullptr;
}

template<class T, class keyType>
inline void LinearList1<T, keyType>::insert(const keyType & srKey, LinearList1<T, keyType>& val)
{
	if (ValidateListsNeverCross(*this, val))
	{
		LinearList1<T, keyType> * tmp = this;
		if (this->m_Key == srKey)
		{
			InsertCodeReusing(tmp, val);
			return;
		}
		while (tmp->m_Next != nullptr)
		{
			if (tmp->m_Next->m_Key == srKey)
			{
				InsertCodeReusing(tmp, val);
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
inline void LinearList1<T, keyType>::insert(const keyType & srKey, const keyType & valKey, const T & val)
{
	LinearList1<T, keyType> * tmp = this;
	if (this->m_Key == srKey)
	{
		LinearList1<T, keyType> * tmp2 = new LinearList1<T, keyType>(val, valKey);
		InsertCodeReusing(tmp, *tmp2);
		return;
	}
	while (tmp->m_Next != nullptr)
	{
		if (tmp->m_Next->m_Key == srKey)
		{
			LinearList1<T, keyType> * tmp2 = new LinearList1<T, keyType>(val, valKey);
			InsertCodeReusing(tmp, *tmp2);
			return;
		}
		tmp = tmp->m_Next;
	}
	std::cerr << "Insert operation failed, no such key has been found\n";
}

template<class T, class keyType>
inline void LinearList1<T, keyType>::pop_back()
{
	if (this->m_Next == nullptr)
	{
		std::cerr << "List is already empty\n";
	}
	else
	{
		LinearList1<T, keyType> * tmp = this;
		while (tmp->m_Next->m_Next != nullptr)
		{
			tmp = tmp->m_Next;
		}
		delete tmp->m_Next;
		tmp->m_Next = nullptr;
	}
}
