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
	void DeleteElement(LinkedList2<T>*);
	void RotateCentreLeft();
	void RotateCenterRight();
	void swap(LinkedList2<T>&);
public:
	//Essentials
	LinkedList2(const int = 0, const T& = T());
	~LinkedList2();

	//ElementAccess
	T& GetByKey(const int);
	const T& GetByKey(const int) const;


	//Modifiers

	//if Erase() return false the binary search tree will know that the root was the last element
	//left and it was destroyed and after that the tree is empty
	bool Erase(const int);
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
inline void LinkedList2<T>::DeleteElement(LinkedList2<T>* tmp)
{
	try
	{
		if (tmp == this)
		{
			throw std::invalid_argument("cannot erase this!!!\n");
		}
		else
		{
			if (tmp->m_Left != nullptr)
			{
				tmp->m_Left->m_Right = tmp->m_Right;
			}
			if (tmp->m_Right != nullptr)
			{
				tmp->m_Right->m_Left = tmp->m_Left;
			}
			tmp->m_Left = nullptr;
			tmp->m_Right = nullptr;
			delete tmp;
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "trying to delete this!!! this messege is not expected to appear ever!!!'n";
	}
}

template<class T>
inline void LinkedList2<T>::RotateCentreLeft()
{
	try
	{
		if (this->m_Right == nullptr)
		{
			throw std::invalid_argument("cannot rotate left");
		}
		else
		{
			//first swaps the values of the root and its right child, and then changes their childs so that rotation is complete
			swap(*(this->m_Right));
			LinkedList2<T> * tmp = this->m_Right;
			LinkedList2<T> * tmp2 = this->m_Left;
			this->m_Right = this->m_Right->m_Right;
			this->m_Left = tmp;
			this->m_Left->m_Right = this->m_Left->m_Left;
			this->m_Left->m_Left = tmp2;
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "trying to rotate left, but the right element is nullptr!!! this messege is not expected to appear ever!!!'n";
	}
}

template<class T>
inline void LinkedList2<T>::RotateCenterRight()
{
	try
	{
		if (this->m_Left == nullptr)
		{
			throw std::invalid_argument("cannot rotate left");
		}
		else
		{
			//first swaps the values of the root and its right child, and then changes their childs so that rotation is complete
			swap(*(this->m_Left));
			LinkedList2<T> * tmp = this->m_Left;
			LinkedList2<T> * tmp2 = this->m_Right;
			this->m_Left = this->m_Left->m_Left;
			this->m_Right = tmp;
			this->m_Right->m_Left = this->m_Right->m_Right;
			this->m_Right->m_Right = tmp2;
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "trying to rotate left, but the right element is nullptr!!! this messege is not expected to appear ever!!!'n";
	}
}

template<class T>
inline void LinkedList2<T>::swap(LinkedList2<T>& rhs)
{
	std::swap(this->m_Key, rhs.m_Key);
	std::swap(this->m_Data, rhs.m_Data);
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
inline bool LinkedList2<T>::Erase(const int numb)
{
	LinkedList2<T> * tmp = FindElement(numb);
	if (tmp != nullptr)
	{
		if (tmp == this)
		{
			if (this->m_Left == nullptr && this->m_Right == nullptr)
			{
				return false;
			}
			else
			{
				if (this->m_Left != nullptr)
				{
					RotateCenterRight();
					DeleteElement(this->m_Left);
				}
				else
				{
					RotateCentreLeft();
					DeleteElement(this->m_Right);
				}
			}
		}
		else
		{
			DeleteElement(tmp);
			return true;
		}
	}
}
