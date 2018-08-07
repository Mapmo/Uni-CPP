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
	void eraseNextElement(LinearList2<T, keyType>&);
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
	void erase(const keyType&);
	void erase(LinearList2<T, keyType>&);
	void pop_back();
	void pop_front();
	void push_back(LinearList2<T, keyType>&);
	void push_front(LinearList2<T, keyType>&);


	//Operations

	void merge(LinearList2&);


	//non-member functions

	template <class T2, class keyType2>
	friend bool operator==(const LinearList2<T2, keyType2>&, const LinearList2<T2, keyType2>&);
	template <class T2, class keyType2>
	friend bool operator!=(const LinearList2<T2, keyType2>&, const LinearList2<T2, keyType2>&);
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
inline void LinearList2<T, keyType>::erase(const keyType & rhs)
{
	if (this->m_Next != nullptr)
	{
		if (this->m_Key == rhs)
		{
			pop_front();
			return;
		}
		else
		{
			LinearList2<T, keyType> * tmp = this;
			if (tmp->m_Key == rhs)
			{
				eraseNextElement(*tmp);
				return;
			}
			tmp = tmp->m_Next;
			if (tmp->m_Next != nullptr)
			{

				while (tmp->m_Next->m_Next != nullptr)
				{
					if (tmp->m_Key == rhs)
					{
						eraseNextElement(*tmp);
						return;
					}
					tmp = tmp->m_Next;
				}
				if (tmp->m_Next->m_Key == rhs)
				{
					pop_back();
					return;
				}
			}
			else if (tmp->m_Key == rhs)//in case this->m_Next is nullptr
			{
				pop_back();
				return;
			}
		}
	}
	else if (this->m_Key == rhs)
	{
		std::cerr << "Cannot delete the first elemment, because the list is empty\n";
		return;
	}
	std::cerr << "Element not found\n";
}

template<class T, class keyType>
inline void LinearList2<T, keyType>::erase(LinearList2<T, keyType>& rhs)
{
	if (this->m_Next != nullptr)
	{
		if (*this == rhs)
		{
			pop_front();
			return;
		}
		else
		{
			LinearList2<T, keyType> * tmp = this;
			do
			{
				if (*tmp == rhs)
				{
					eraseNextElement(*tmp);
					return;
				}
				tmp = tmp->m_Next;
			} while (tmp->m_Next->m_Next != nullptr);
			if (*(tmp->m_Next) == rhs)
			{
				pop_back();
				return;
			}
		}
	}
	else if (*this == rhs)
	{
		std::cerr << "Cannot delete the first elemment, because the list is empty\n";
		return;
	}
	std::cerr << "Element not found\n";
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
inline void LinearList2<T, keyType>::pop_front()
{
	if (this->m_Next == nullptr)
	{
		std::cerr << "Cannot erase the front element because the list is empty\n";
	}
	else
	{
		this->m_Data = this->m_Next->m_Data;
		this->m_Key = this->m_Next->m_Key;
		LinearList2<T, keyType> *  tmp = this->m_Next;
		this->m_Next = tmp->m_Next;
		tmp->m_Next = nullptr;
	}
}

template<class T, class keyType>
inline void LinearList2<T, keyType>::push_back(LinearList2<T, keyType>& rhs)
{
	if (ValidateListsNeverCross(*this, rhs))
	{
		LinearList2<T, keyType> * tmp = this;
		while (tmp->m_Next != nullptr)
		{
			tmp = tmp->m_Next;
		}
		tmp->m_Next = &rhs;
	}
	else
	{
		std::cerr << "push_back operation failed, because the two lists are linked and this will cause an infinite loop\n";
	}
}

template<class T, class keyType>
inline void LinearList2<T, keyType>::push_front(LinearList2<T, keyType>& rhs)
{
	if (ValidateListsNeverCross(*this, rhs))
	{
		LinearList2<T, keyType> * tmp = this->m_Next;
		this->m_Next = &rhs;
		push_back(*tmp);
	}
	else
	{
		std::cerr << "push_front operation failed, because the two lists are linked and this will cause an infinite loop\n";
	}
}

template<class T, class keyType>
inline void LinearList2<T, keyType>::merge(LinearList2 & rhs)
{
	if (ValidateListsNeverCross(*this, rhs))
	{
		this->m_Next = &rhs;
	}
	else
	{
		std::cerr << "Function merge() cannot proceed, because the lists cross somewhere\n";
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

template<class T, class keyType>
inline void LinearList2<T, keyType>::eraseNextElement(LinearList2<T, keyType>& rhs)
{
	LinearList2<T, keyType> * tmp2 = rhs.m_Next;
	rhs.m_Next = tmp2->m_Next;
	tmp2->m_Next = nullptr;
}

template<class T2, class keyType2>
inline bool operator==(const LinearList2<T2, keyType2>& lhs, const LinearList2<T2, keyType2>& rhs)
{
	return (lhs.m_Data == rhs.m_Data && lhs.m_Key == rhs.m_Key);
}

template<class T2, class keyType2>
inline bool operator!=(const LinearList2<T2, keyType2>& lhs, const LinearList2<T2, keyType2>& rhs)
{
	return !operator==(lhs, rhs);
}
