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
	//used to find elements' parents in the tree, in order to escape code repetition, only used after FindElement returned a pointer different from nullptr
	LinkedList2<T>* FindElementParent(const int);
	void DeleteElement(LinkedList2<T>*);
	bool isChildLeft(LinkedList2<T>*, LinkedList2<T>*)const;//takes 2 params that are supposed to be child and parent and returns true if the child is left
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
	void SetRoot(const int, const T&);
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
			throw(std::invalid_argument("element not found"));
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "GetByKey invalid_argument exception thrown: " << ia.what();
	}
}

template<class T>
inline LinkedList2<T> * LinkedList2<T>::FindElement(const int numb)
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
	return nullptr;
}

template<class T>
inline LinkedList2<T>* LinkedList2<T>::FindElementParent(const int numb)
{
	LinkedList2<T> * tmp = this;//this pointer iterates through the tree
	LinkedList2<T> * tmp2 = nullptr;//this pointer preserves the last value of the pointer above
	while (tmp != nullptr)
	{
		if (tmp->m_Key == numb)
		{
			return tmp2;
		}
		else
		{
			tmp2 = tmp;
		}

		if (tmp->m_Key > numb)
		{
			tmp = tmp->m_Left;
		}
		else
		{
			tmp = tmp->m_Right;
		}
	}
	return nullptr;
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
			LinkedList2<T>* tmp2 = FindElementParent(tmp->m_Key);
			bool isLeft = isChildLeft(tmp2, tmp);
			if (tmp->m_Left != nullptr)
			{
				tmp->m_Left->m_Right = tmp->m_Right;
				if (isLeft)
				{
					tmp2->m_Left = tmp->m_Left;
				}
				else
				{
					tmp2->m_Right = tmp->m_Left;
				}
				tmp->m_Left = nullptr;
				if (tmp->m_Right != nullptr)
				{
					tmp->m_Right = nullptr;
				}
			}
			else if (tmp->m_Right != nullptr)
			{
				tmp->m_Right->m_Left = tmp->m_Left;
				if (isLeft)
				{
					tmp2->m_Left = tmp->m_Right;
				}
				else
				{
					tmp2->m_Right = tmp->m_Right;
				}
				tmp->m_Right = nullptr;
			}
			delete tmp;
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "trying to delete this!!! this messege is not expected to appear ever!!!'n";
	}
}

template<class T>
inline bool LinkedList2<T>::isChildLeft(LinkedList2<T>*parent, LinkedList2<T>*child) const
{
	if (parent->m_Key > child->m_Key)
	{
		return true;
	}
	else
	{
		return false;
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
		std::cerr << "trying to rotate right, but the left element is nullptr!!! this messege is not expected to appear ever!!!'n";
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
					DeleteElement(this->m_Right);
				}
				else
				{
					RotateCentreLeft();
					DeleteElement(this->m_Left);
				}
			}
		}
		else
		{
			DeleteElement(tmp);
			return true;
		}
	}
	else
	{
		std::cerr << "No element found for delete\n";
	}
}

template<class T>
inline void LinkedList2<T>::Insert(const int numb, const T & val)
{
	try
	{
		LinkedList2<T> * tmp = FindElement(numb);//checks if there is an element with such a key
		if (tmp == nullptr)
		{
			tmp = this;
			do
			{
				if (numb > tmp->m_Key)
				{
					if (tmp->m_Right == nullptr)
					{
						tmp->m_Right = new LinkedList2(numb, val);
						return;
					}
					tmp = tmp->m_Right;
				}
				else
				{
					if (tmp->m_Left == nullptr)
					{
						tmp->m_Left = new LinkedList2(numb, val);
						return;
					}
					tmp = tmp->m_Left;
				}
			} while (tmp != nullptr);
		}
		else
		{
			throw std::invalid_argument("element already there");
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "Insert invalid argument thrown: " << ia.what();
	}
}

template<class T>
inline void LinkedList2<T>::SetRoot(const int numb, const T & val)
{
	this->m_Key = numb;
	this->m_Data = val;
}
