#pragma once

template<class T>
class LinkedList2
{
	//forbidden actions
	LinkedList2(const LinkedList2<T>&);
	LinkedList2<T>& operator=(const LinkedList2<T>&);//not working correctly btw

	//overload helpers
	T& GetByKeyOverloadHelper(const int);

	//others
	LinkedList2<T>* FindElement(const int);//used to find elements in the tree, in order to escape code repetition
public:
	//Essentials
	LinkedList2(const int = 0, const T& = T());
	~LinkedList2();

	//ElementAccess
	T& GetByKey(const int);
	const T& GetByKey(const int) const;


	//Modifiers

	void Erase(const int);
	void Insert(const int, const T&);
	void Insert(const LinkedList2<T>&);
private:
	int m_Key;
	T m_Data;
	LinkedList2<T> * m_Right;
	LinkedList2<T> * m_Left;
};

template<class T>
inline LinkedList2<T> & LinkedList2<T>::operator=(const LinkedList2<T>&)
{
	return *this;
}

template<class T>
inline T & LinkedList2<T>::GetByKeyOverloadHelper(const int numb)
{
	try
	{
		LinkedList2<T> * tmp = FindElement(numb);
		if (tmp != nullptr)
		{
			return tmp->m_Data;
		}
		else
		{
			throw(std::out_of_range("sad"));
		}
	}
	catch (std::out_of_range& oor)
	{
	}
}

template<class T>
inline LinkedList2<T> * LinkedList2<T>::FindElement(const int numb)
{
	try
	{
		LinkedList2<T> * tmp = this;
		do
		{
			if (tmp->m_Key == numb)
			{
				return tmp;
			}
			else if (tmp->m_Key > numb)
			{
				tmp = tmp->m_Left;
			}
			else
			{
				tmp = tmp->m_Right;
			}
		} while (tmp != nullptr);
		throw(std::out_of_range("not found"));
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Elelment not found\n";
		return nullptr;
	}
}

template<class T>
inline LinkedList2<T>::LinkedList2(const int key, const T & val) : m_Key(key), m_Data(val), m_Left(nullptr), m_Right(nullptr)
{
}

template<class T>
inline LinkedList2<T>::~LinkedList2()
{
	if (this->m_Left != nullptr)
	{
		this->m_Left->m_Right = nullptr;
	}
	delete m_Left;

	if (this->m_Right != nullptr)
	{
		this->m_Right->m_Left = nullptr;
	}
	delete m_Right;
}

template<class T>
inline T & LinkedList2<T>::GetByKey(const int numb)
{
	return GetByKeyOverloadHelper(numb);
}

template<class T>
inline const T & LinkedList2<T>::GetByKey(const int) const
{
	return GetByKeyOverloadHelper(numb);
}

template<class T>
inline void LinkedList2<T>::Erase(const int)
{
}
