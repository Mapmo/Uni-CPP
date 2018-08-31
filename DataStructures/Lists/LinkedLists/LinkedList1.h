#pragma once

template <class T, class keyType>
class LinkedList1
{
	T& frontOverloadHelper();
	T& backOverloadHelper();

	void EraseElement(LinkedList1<T, keyType>*);//after an element is found by eraseOverloadHelper, this will try to delete it
	LinkedList1<T, keyType> * ChangeCore(LinkedList1<T, keyType>*);//swaps the core with another list if possible and returns if the operation was successful
	void eraseOverloadHelper(const keyType&);
	
public:
	LinkedList1();
	LinkedList1(const T&, const keyType&);
	LinkedList1(const T&, const keyType&, LinkedList1&);
	explicit LinkedList1(const T&);
	LinkedList1(const  LinkedList1<T, keyType>&);
	LinkedList1<T, keyType> & operator=(const LinkedList1<T, keyType>&);
	~LinkedList1();


	//Element Access

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	LinkedList1<T, keyType> * Next();//returns m_Next that can be updated
	LinkedList1<T, keyType> * Prev();//returns m_Prev that can be updated
	const LinkedList1<T, keyType> * Next()const;//returns m_Next that cant be updated
	const LinkedList1<T, keyType> * Prev()const;//returns m_Prev that cant be updated
	T& Data();
	const T& Data()const;
	const keyType& Key()const;

	//iterator-like functions

	//will always calculate the first or last elements, but I didn't intend to use iterators for this project
	LinkedList1<T, keyType> * begin();//returns the first element
	LinkedList1<T, keyType> * end();//returns the last element


	//Capacity

	bool empty()const;//the list is considered empty if it doesn't point to another list
	unsigned int size()const;//the amount of lists that are linked to the list


	//Modifiers

	void clear()noexcept;
	void insert(const keyType&, LinkedList1<T, keyType>&);
	void insert(const keyType&, const keyType&, const T&);
	void erase(const keyType&);
	void erase(LinkedList1<T, keyType>&);
	void pop_back();
	void pop_front();
	void push_back(LinkedList1<T, keyType>&);
	void push_front(LinkedList1<T, keyType>&);
	void swap(LinkedList1<T, keyType>&);

	//Operations

	void reverse();

	//non-member functions

	template <class T2, class keyType2>
	friend bool operator==(const LinkedList1<T2, keyType2>&, const LinkedList1<T2, keyType2>&);
	template <class T2, class keyType2>
	friend bool operator!=(const LinkedList1<T2, keyType2>&, const LinkedList1<T2, keyType2>&);
	template <class T2, class keyType2>
	friend void swap(LinkedList1<T2, keyType2>&, LinkedList1<T2, keyType2>&);
private:
	T m_Data;
	keyType m_Key;
	LinkedList1<T, keyType>* m_Next;
	LinkedList1<T, keyType>* m_Prev;
};

template<class T, class keyType>
inline T & LinkedList1<T, keyType>::frontOverloadHelper()
{
	LinkedList1<T, keyType> * tmp = begin();
	return tmp->m_Data;
}

template<class T, class keyType>
inline T & LinkedList1<T, keyType>::backOverloadHelper()
{
	LinkedList1<T, keyType> * tmp = end();
	return tmp->m_Data;
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::EraseElement(LinkedList1<T, keyType>* tmp)
{
	if (tmp == this)
	{
		tmp = ChangeCore(tmp);//tries to change the core and tmp will point to the new location of the object if the operation was successful
		if (tmp == this)
		{
			std::cerr << "Cannot erase the core\n";
			return;
		}
	}
	if (tmp->m_Prev != nullptr)
	{
		tmp->m_Prev->m_Next = tmp->m_Next;
	}
	if (tmp->m_Next != nullptr)
	{
		tmp->m_Next->m_Prev = tmp->m_Prev;
	}
	tmp->m_Next = nullptr;
	tmp->m_Prev = nullptr;
	delete tmp;
}

template<class T, class keyType>
inline LinkedList1<T, keyType> * LinkedList1<T, keyType>::ChangeCore(LinkedList1<T, keyType>* tmp)
{
	if (tmp->m_Next == nullptr)
	{
		if (tmp->m_Prev != nullptr)
		{
			swap(*(tmp->m_Prev));//swap the values of the objects(except the pointers) so we can delete an element that is not the core
			tmp = tmp->m_Prev;//now tmp points to an object that is not the core
		}
	}
	else
	{
		swap(*(tmp->m_Next));
		tmp = tmp->m_Next;
	}
	return tmp;
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::eraseOverloadHelper(const keyType & srPos)
{
	LinkedList1<T, keyType> * tmp = this;
	while (tmp != nullptr)
	{
		if (tmp->m_Key = srPos)
		{
			EraseElement(tmp);
			return;
		}
		else
		{
			tmp = tmp->m_Prev;
		}
	}
	tmp = this;
	while (tmp != nullptr)
	{
		if (tmp->m_Key = srPos)
		{
			EraseElement(tmp);
			return;
		}
		else
		{
			tmp = tmp->m_Next;
		}
	}
	std::cerr << "No such element found\n";
}

template<class T, class keyType>
inline LinkedList1<T, keyType>* LinkedList1<T, keyType>::begin()
{
	LinkedList1<T, keyType> * leftBorder = this;
	while (leftBorder->m_Prev != nullptr)
	{
		leftBorder = leftBorder->m_Prev;
	}
	return leftBorder;
}

template<class T, class keyType>
inline LinkedList1<T, keyType>* LinkedList1<T, keyType>::end()
{
	LinkedList1<T, keyType> * rightBorder = this;
	while (rightBorder->m_Next != nullptr)
	{
		rightBorder = rightBorder->m_Next;
	}
	return rightBorder;
}

template<class T, class keyType>
inline LinkedList1<T, keyType>::LinkedList1() : m_Data(), m_Key(), m_Next(nullptr), m_Prev(nullptr)
{
}

template<class T, class keyType>
inline LinkedList1<T, keyType>::LinkedList1(const T & data, const keyType & key) : m_Data(data), m_Key(key), m_Next(nullptr), m_Prev(nullptr)
{
}

template<class T, class keyType>
inline LinkedList1<T, keyType>::LinkedList1(const T & data, const keyType & key, LinkedList1<T, keyType> & next) : m_Data(data), m_Key(key), m_Prev(nullptr)
{
	m_Next = new LinkedList1(next);
}

template<class T, class keyType>
inline LinkedList1<T, keyType>::LinkedList1(const T & data) : m_Data(data), m_Key(), m_Next(nullptr), m_Prev(nullptr)
{
}

template<class T, class keyType>
inline LinkedList1<T, keyType>::LinkedList1(const LinkedList1<T, keyType> & rhs) : m_Data(rhs.m_Data), m_Key(rhs.m_Key), m_Next(nullptr), m_Prev(nullptr)
{
}

template<class T, class keyType>
inline LinkedList1<T, keyType>& LinkedList1<T, keyType>::operator=(const LinkedList1<T, keyType>&)
{
	if (this != &rhs)
	{
		this->m_Data = rhs.m_Data;
		this->m_Key = rhs.m_Key;
	}
	return *this;
}

template<class T, class keyType>
inline LinkedList1<T, keyType>::~LinkedList1()
{
	if (this->m_Prev != nullptr)
	{
		this->m_Prev->m_Next = nullptr;
	}
	if (this->m_Next != nullptr)
	{
		this->m_Next->m_Prev = nullptr;
	}
	delete m_Next;
	delete m_Prev;
}

template<class T, class keyType>
inline T & LinkedList1<T, keyType>::front()
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline const T & LinkedList1<T, keyType>::front() const
{
	return frontOverloadHelper();
}

template<class T, class keyType>
inline T & LinkedList1<T, keyType>::back()
{
	return backOverloadHelper();
}

template<class T, class keyType>
inline const T & LinkedList1<T, keyType>::back() const
{
	return backOverloadHelper();
}

template<class T, class keyType>
inline LinkedList1<T, keyType>* LinkedList1<T, keyType>::Next()
{
	return this->m_Next;
}

template<class T, class keyType>
inline LinkedList1<T, keyType>* LinkedList1<T, keyType>::Prev()
{
	return this->m_Prev;
}

template<class T, class keyType>
inline const LinkedList1<T, keyType>* LinkedList1<T, keyType>::Next() const
{
	return this->m_Next;
}

template<class T, class keyType>
inline const LinkedList1<T, keyType>* LinkedList1<T, keyType>::Prev() const
{
	return this->m_Prev;
}

template<class T, class keyType>
inline T & LinkedList1<T, keyType>::Data()
{
	return this->m_Data;
}

template<class T, class keyType>
inline const T & LinkedList1<T, keyType>::Data() const
{
	return this->m_Data;
}

template<class T, class keyType>
inline const keyType & LinkedList1<T, keyType>::Key() const
{
	return this->m_Key;
}

template<class T, class keyType>
inline bool LinkedList1<T, keyType>::empty() const
{
	return (this->m_Next == nullptr && this->m_Prev == nullptr);
}

template<class T, class keyType>
inline unsigned int LinkedList1<T, keyType>::size() const
{
	int i = 0;
	const LinkedList1<T, keyType> * tmp = this;
	while (tmp->m_Prev != nullptr)
	{
		++i;
		tmp = tmp->m_Prev;
	}
	tmp = this;
	while (tmp->m_Next != nullptr)
	{
		++i;
		tmp = tmp->m_Next;
	}
	return i;
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::clear() noexcept
{
	delete this->m_Next;
	delete this->m_Prev;
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::insert(const keyType & srPos, LinkedList1<T, keyType>& val)
{
	LinkedList1<T, keyType> * tmp = this;
	while (tmp != nullptr)
	{
		if (tmp->m_Key == srPos)
		{
			LinkedList1<T, keyType> * tmp2 = new LinkedList1<T, keyType>(val);
			tmp2->m_Prev = tmp->m_Prev;
			tmp2->m_Next = tmp;
			if (tmp->m_Prev != nullptr)
			{
				tmp->m_Prev->m_Next = tmp2;
			}
			tmp->m_Prev = tmp2;
			return;
		}
		tmp = tmp->m_Prev;
	}
	while (tmp != nullptr)
	{
		if (tmp->m_Key == srPos)
		{
			LinkedList1<T, keyType> * tmp2 = new LinkedList1<T, keyType>(val);
			tmp2->m_Prev = tmp->m_Prev;
			tmp2->m_Next = tmp;
			if (tmp->m_Prev != nullptr)
			{
				tmp->m_Prev->m_Next = tmp2;
			}
			tmp->m_Prev = tmp2;
			return;
		}
		tmp = tmp->m_Next;
	}
	std::cerr << "No position found for insert\n";
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::insert(const keyType & srPos, const keyType & trPos, const T & val)
{
	LinkedList1<T, keyType> tmp(val, trPos);
	insert(srPos, tmp);
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::erase(const keyType & srPos)
{
	eraseOverloadHelper(srPos);
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::erase(LinkedList1<T, keyType>& rhs)
{
	eraseOverloadHelper(rhs.m_Key);
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::pop_back()
{
	if (empty())
	{
		std::cerr << "List is empty\n";
	}
	else
	{
		if (this->m_Next == nullptr)
		{
			erase(this->m_Key);//using erase() to remove it because there isn't an easier way
		}
		else
		{
			LinkedList1<T, keyType> * tmp = end();
			tmp->m_Prev->m_Next = nullptr;//this is faster than using erase()
			delete tmp;
		}
	}
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::pop_front()
{
	if (empty())
	{
		std::cerr << "List is empty\n";
	}
	else
	{
		if (this->m_Prev == nullptr)
		{
			erase(this->m_Key);//using erase() to remove it because there isn't an easier way
		}
		else
		{
			LinkedList1<T, keyType> * tmp = begin();
			tmp->m_Next->m_Prev = nullptr;//this is faster than using erase()
			delete tmp;
		}
	}
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::push_back(LinkedList1<T, keyType>& rhs)
{
	LinkedList1<T, keyType> * tmp = end();
	LinkedList1<T, keyType> * tmp2 = new LinkedList1<T, keyType>(rhs);
	tmp->m_Next = tmp2;
	tmp2->m_Prev = tmp;
	tmp2->m_Next = nullptr;//just in case
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::push_front(LinkedList1<T, keyType>& rhs)
{
	LinkedList1<T, keyType> * tmp = begin();
	LinkedList1<T, keyType> * tmp2 = new LinkedList1<T, keyType>(rhs);
	tmp->m_Prev = tmp2;
	tmp2->m_Next = tmp;
	tmp2->m_Prev = nullptr;//just in case
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::swap(LinkedList1<T, keyType>& rhs)
{
	LinkedList1<T, keyType> tmp = *this;
	this->m_Key = rhs.m_Key;
	this->m_Data = rhs.m_Data;
	rhs.m_Key = tmp.m_Key;
	rhs.m_Data = tmp.m_Data;
}

template<class T, class keyType>
inline void LinkedList1<T, keyType>::reverse()
{
	LinkedList1<T, keyType> * leftBorder = begin();
	LinkedList1<T, keyType> * rightBorder = end();

	while (leftBorder != rightBorder && leftBorder->m_Prev != rightBorder)//if one of these conditions is met, then the reverse is complete
	{
		leftBorder->swap(*rightBorder);
		leftBorder = leftBorder->m_Next;
		rightBorder = rightBorder->m_Prev;
	}
}

template<class T2, class keyType2>
inline bool operator==(const LinkedList1<T2, keyType2>& lhs, const LinkedList1<T2, keyType2>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	const LinkedList1<T2, keyType2> * tmp = &lhs;
	const LinkedList1<T2, keyType2> * tmp2 = &rhs;
	while (tmp != nullptr && tmp2 != nullptr)
	{
		if (tmp->m_Data != tmp2->m_Data)
		{
			return false;
		}
		else
		{
			tmp = tmp->m_Prev;
			tmp2 = tmp2->m_Prev;
		}
	}
	tmp = &lhs;
	tmp2 = &rhs;
	while (tmp != nullptr && tmp2 != nullptr)
	{
		if (tmp->m_Data != tmp2->m_Data)
		{
			return false;
		}
		else
		{
			tmp = tmp->m_Next;
			tmp2 = tmp2->m_Next;
		}
	}
	return true;
}

template<class T2, class keyType2>
inline bool operator!=(const LinkedList1<T2, keyType2>& lhs, const LinkedList1<T2, keyType2>& rhs)
{
	return !operator==(lhs, rhs);
}

template<class T2, class keyType2>
inline void swap(LinkedList1<T2, keyType2>& lhs, LinkedList1<T2, keyType2>& rhs)
{
	lhs.swap(rhs);
}
