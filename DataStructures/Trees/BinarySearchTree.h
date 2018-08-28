#pragma once
#include "..\Lists\LinkedLists\LinkedList2.h"

template <class T>
class BinarySearchTree
{
	BinarySearchTree(const BinarySearchTree<T>&);
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>&);
public:
	BinarySearchTree();

	//ElementAccess
	T& GetByKey(const int);
	const T& GetByKey(const int) const;


	//Modifiers

	//if Erase() return false the binary search tree will know that the root was the last element
	//left and it was destroyed and after that the tree is empty
	bool Erase(const int);
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
inline BinarySearchTree<T>::BinarySearchTree() : m_Empty(1), m_Branches()
{
}

template<class T>
inline T & BinarySearchTree<T>::GetByKey(const int numb)
{
	return m_Branches.GetByKey(numb);
}

template<class T>
inline const T & BinarySearchTree<T>::GetByKey(const int numb) const
{
	return GetByKey(numb);
}
