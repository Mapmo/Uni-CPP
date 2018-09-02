#pragma once
#include "BinarySearchTree.h"

template <class T>
class RedBlackTree : public BinarySearchTree<T>
{

	void InsertBalance(Branch<T>*);//used after insert, therefore it presumes that its param has red color
	void InsertBalanceBlackUncle(Branch<T>*);
	void InsertBalanceRedUncle(Branch<T>*, Branch<T>*, Branch<T>*);
public:
	RedBlackTree(const int = 0, const T & = T());

	void insert(const int, const T&) override;//altough it matches 90% of the original function it still needs to be override
	void insert(const Branch<T>&)override;
};

template<class T>
inline void RedBlackTree<T>::InsertBalance(Branch<T>* x)
{
	if (x->parent != this->m_Root)
	{
		if (x->parent->color != black)
		{
			//using these pointers to avoid code reading complexity
			Branch<T> * grandparent = x->parent->parent;//x->parent is not root, so we know that grandparent is not nullptr
			Branch<T> * uncle = x->parent->isRightChild() ? grandparent->left : grandparent->right;

			if (uncle != nullptr)
			{
				if (uncle->color == red)
				{
					InsertBalanceRedUncle(x, grandparent, uncle);
					return;
				}
			}
			InsertBalanceBlackUncle(x);
		}
	}
}

template<class T>
inline void RedBlackTree<T>::InsertBalanceBlackUncle(Branch<T>*x)
{
	if (x->parent->isRightChild() && x->isRightChild())//rr case
	{
		x->parent->parent->color = red;
		x->parent->color = black;
		BinarySearchTree<T>::RotateLeft(x->parent->parent);
	}
	else if (x->parent->isRightChild())//rl case
	{
		x->parent->parent->color = red;
		x->color = black;
		BinarySearchTree<T>::RotateRight(x->parent);
		BinarySearchTree<T>::RotateLeft(x->parent);//x's parent now is his prev grandparent
	}
	else if (x->isRightChild())//lr case
	{
		x->parent->parent->color = red;
		x->color = black;
		BinarySearchTree<T>::RotateLeft(x->parent);
		BinarySearchTree<T>::RotateRight(x->parent);//x's parent now is his prev grandparent
	}
	else//ll case
	{
		x->parent->parent->color = red;
		x->parent->color = black;
		BinarySearchTree<T>::RotateRight(x->parent->parent);
	}
}

template<class T>
inline void RedBlackTree<T>::InsertBalanceRedUncle(Branch<T>*x, Branch<T>*grandparent, Branch<T>* uncle)
{
	x->parent->color = black;
	uncle->color = black;
	if (grandparent != this->m_Root)
	{
		grandparent->color = red;
		InsertBalance(grandparent);
	}
}

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
				InsertBalance(tmp->right);
			}
			else
			{
				tmp->left = new Branch<T>(numb, val, tmp);
				InsertBalance(tmp->left);
			}
		}
	}
}

template<class T>
inline void RedBlackTree<T>::insert(const Branch<T>& rhs)
{
	insert(rhs.key, rhs.val);
}

