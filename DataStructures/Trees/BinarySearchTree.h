#pragma once
#include "..\Lists\LinkedLists\LinkedList2.h"

template <class T>
class BinarySearchTree
{
	BinarySearchTree(const BinarySearchTree<T>&);
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>&);

	//overload helpers
	T& GetByKeyOverloadHelper(const int);
public:
	BinarySearchTree();

	//ElementAccess
	T& GetByKey(const int);
	const T& GetByKey(const int) const;


	//Modifiers

	//if Erase() return false the binary search tree will know that the root was the last element
	//left and it was destroyed and after that the tree is empty
	void Erase(const int);
	void Insert(const int, const T&);
private:
	bool m_Empty;
	LinkedList2<T> m_Branches;
};

template<class T>
inline BinarySearchTree<T> & BinarySearchTree<T>::operator=(const BinarySearchTree<T>&)
{
	return *this;
}

template<class T>
inline T & BinarySearchTree<T>::GetByKeyOverloadHelper(const int numb)
{
	try
	{
		if (!this->m_Empty)
		{
			return this->m_Branches.GetByKey(numb);
		}
		else
		{
			throw std::invalid_argument("The tree is empty\n");
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << ia.what();
	}
}

template<class T>
inline BinarySearchTree<T>::BinarySearchTree() : m_Empty(true), m_Branches()
{
}

template<class T>
inline T & BinarySearchTree<T>::GetByKey(const int numb)
{
	return GetByKeyOverloadHelper(numb);
}

template<class T>
inline const T & BinarySearchTree<T>::GetByKey(const int numb) const
{
	return GetByKeyOverloadHelper(numb);
}

template<class T>
inline void BinarySearchTree<T>::Erase(const int numb)
{
	if (!this->m_Empty)
	{
		if (!this->m_Branches.Erase(numb))//if LinkedList2<T>::Erase() returns false, then there are no elements in the tree
		{
			this->m_Empty = true;
		}
	}
	else
	{
		std::cerr << "The tree is empty\n";
	}
}

template<class T>
inline void BinarySearchTree<T>::Insert(const int numb, const T & val)
{
	if (this->m_Empty)
	{
		this->m_Branches.SetRoot(numb, val);
		this->m_Empty = false;
	}
	else
	{
		this->m_Branches.Insert(numb, val);
	}
}
