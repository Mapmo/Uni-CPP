#pragma once
#include "BinarySearchTree.h"

template <class T>
class RedBlackTree : public BinarySearchTree<T>
{

	//void erase(const int)override;
	//void Balance(Branch<T>*);
public:
	RedBlackTree(const int = 0, const T & = T());

	void insert(const int, const T&) override;//altough it matches 90% of the original function it still needs to be override
	void insert(const Branch<T>&)override;
};

template<class T>
inline RedBlackTree<T>::RedBlackTree(const int numb, const T &val) : BinarySearchTree<T>(numb, val)
{
	this->m_Root->color = black;
}

template<class T>
inline void RedBlackTree<T>::insert(const int numb, const T & val)
{
	if (this->m_Root == nullptr)
	{
		this->m_Root = new Branch<T>(numb, val);
		this->m_Root->color = black;//rule number 1 root is always black
	}
	else
	{
		Branch<T> * tmp = BinarySearchTree<T>::FindBranchParent(numb);
		bool isRight = tmp->key < numb;
		if (BinarySearchTree<T>::GetChild(isRight, tmp) != nullptr)
		{
			std::cerr << "Operation insert failed, because there is already an element with such a key\n";
		}
		else
		{
			if (isRight)
			{
				tmp->right = new Branch<T>(numb, val, tmp);
				//Balance(tmp->right);
			}
			else
			{
				tmp->left = new Branch<T>(numb, val, tmp);
				//Balance(tmp->left);
			}
		}
	}
}

template<class T>
inline void RedBlackTree<T>::insert(const Branch<T>& rhs)
{
	insert(rhs.key, rhs.val);
}
