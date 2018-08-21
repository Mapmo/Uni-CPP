#pragma once

template <class T, class keyType>
class LinkedList1
{
	T& frontOverloadHelper();
	T& backOverloadHelper();
	void insertOverloadHelper(LinkedList1<T, keyType>* tmp, LinkedList1<T, keyType>&val);

	void eraseNextElement(LinkedList1<T, keyType>&);//as there is no m_Prev class member, it needs to track and delete elements one step earlier
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


	//Capacity

	bool empty()const;//the list is considered empty if it doesn't point to another list
	unsigned int size()const;//the amount of lists that are linked to the list


	//Modifiers

	void clear()noexcept;
	void insert(const keyType& srPos, LinkedList1<T, keyType>& val);
	void insert(const keyType& srPo, const keyType& trPos, const T& val);
	void erase(const keyType&);
	void erase(LinkedList1<T, keyType>&);
	void pop_back();
	void pop_front();
	void push_back(LinkedList1<T, keyType>&);
	void push_front(LinkedList1<T, keyType>&);


	//Operations

	void merge(LinkedList1<T, keyType>&);
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
	LinkedList1<T, keyType> * tmp = this;
	while (tmp->m_Prev != nullptr)
	{
		tmp = tmp->m_Prev;
	}
	return tmp->m_Data;
}

template<class T, class keyType>
inline T & LinkedList1<T, keyType>::backOverloadHelper()
{
	LinkedList1<T, keyType> * tmp = this;
	while (tmp->m_Next != nullptr)
	{
		tmp = tmp->m_Next;
	}
	return tmp->m_Data;
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
inline bool LinkedList1<T, keyType>::empty() const
{
	return (this->m_Next == nullptr && this->m_Prev == nullptr);
}

template<class T, class keyType>
inline unsigned int LinkedList1<T, keyType>::size() const
{
	int i = 0;
	LinkedList1<T, keyType> * tmp = this;
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

