#pragma once

template <class T, class keyType>
class List
{
	T& frontOverloadHelper();
	T& backOverloadHelper();
	void EraseAllNextPointers();//used in destructor and operator=

	//used for operator= to make sure that the 2 lists are not part of the same list, as it 
	//is unknown which element may be first, then both elements' m_Next sequences are inspected
	bool ValidateListsNeverCross(const List<T, keyType> &, const List<T, keyType> &)const;
public:
	List();
	List(const T&, const keyType&);
	List(const T&, const keyType&, List&);
	List(const List&);
	List<T, keyType> & operator=(const List<T, keyType>&);
	~List();

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

private:
	T m_Data;
	keyType m_Key;
	List<T, keyType>* m_Next;
};

template<class T, class keyType>
inline T& List<T, keyType>::frontOverloadHelper()
{
	return this->m_Data;
}

template<class T, class keyType>
inline T & List<T, keyType>::backOverloadHelper()
{
	if (this->m_Next != nullptr)
	{
		List * ptr = this->m_Next;

		while (ptr->m_Next != nullptr)
		{
			ptr = ptr->m_Next;
		}
		return ptr->m_Data;
	}
	return this->m_Data;
}

template<class T, class keyType>
inline void List<T, keyType>::EraseAllNextPointers()
{
	if (this->m_Next != nullptr)
	{
		List<T, keyType> * ptrToDeleteNow = this->m_Next;
		List<T, keyType> * ptrToDeleteNext = ptrToDeleteNow->m_Next;
		while (ptrToDeleteNext != nullptr)
		{
			delete ptrToDeleteNow;
			ptrToDeleteNow = ptrToDeleteNext;
			ptrToDeleteNext = ptrToDeleteNow->m_Next;
		}
		delete ptrToDeleteNow;
	}
}
template<class T, class keyType>
inline bool List<T, keyType>::ValidateListsNeverCross(const List<T, keyType>& lhs, const List<T, keyType>& rhs) const
{
	List<T, keyType> * tmp = lhs.m_Next;
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
inline List<T, keyType>::List() : m_Key(), m_Data(), m_Next(nullptr)
{
}

template<class T, class keyType>
inline List<T, keyType>::List(const T & data, const keyType & key) : m_Data(data), m_Key(key), m_Next(nullptr)
{
}

template<class T, class keyType>
inline List<T, keyType>::List(const T& data, const keyType & key, List<T, keyType>& next) : m_Data(data), m_Key(key)
{
	this->m_Next = new List<T, keyType>(next);
}

template<class T, class keyType>
inline List<T, keyType>::List(const List<T, keyType> & rhs) : m_Data(rhs.m_Data), m_Key(rhs.m_Key)
{
	if (rhs.m_Next != nullptr)
	{
		List * tmp = rhs.m_Next;
		if (tmp->m_Next == nullptr)
		{
			this->m_Next = new List(tmp->m_Data, tmp->m_Key);
		}
		else
		{
			List * tmp2 = new List<T, keyType>(tmp->m_Data, tmp->m_Key, *(tmp->m_Next));
			tmp = tmp2->m_Next;
			while (tmp != nullptr)
			{
				tmp2 = new List<T, keyType>(tmp->m_Data, tmp->m_Key, *(tmp->m_Next));
				tmp = tmp2->m_Next;
			}
		}
	}
	else
	{
		this->m_Next = nullptr;
	}
}

template<class T, class keyType>
inline List<T, keyType> & List<T, keyType>::operator=(const List<T, keyType> & rhs)
{
	if (ValidateListsNeverCross(*this, rhs))
	{
		if (this != &rhs)
		{
			EraseAllNextPointers();
			this->m_Key = rhs.m_Key;
			this->m_Data = rhs.m_Data;
			if (rhs.m_Next != nullptr)
			{
				this->m_Next = new List<T, keyType>(*(rhs.m_Next));
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
inline List<T, keyType>::~List()
{
	EraseAllNextPointers();
}

template<class T, class keyType>
inline T& List<T, keyType>::front()
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline const T & List<T, keyType>::front() const
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline T & List<T, keyType>::back()
{
	return backOverloadHelper();
}

template<class T, class keyType>
inline const T & List<T, keyType>::back() const
{
	return backOverloadHelper();
}
