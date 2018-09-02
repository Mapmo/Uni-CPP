#pragma once
#include <functional>//used for throw bad_function_call()
template <class T>
struct Branch
{
	Branch(const int = 0, const T& = T(), Branch<T>* = nullptr);
	~Branch();
	void swap(Branch<T>*);
	bool isRightChild()const;
	int key;
	bool isRed;//not used in BinarySearchTree
	T val;

	Branch<T> * left;
	Branch<T> * right;
	Branch<T> * parent;
};

template <class T>
class BinarySearchTree
{
	BinarySearchTree(const BinarySearchTree&) = delete;
	const BinarySearchTree<T>& operator=(const BinarySearchTree&) = delete;


	//OverloadHelpers

	T& GetByKeyOverloadHelper(const int);
	Branch<T>* FindBranchOverloadHelper(const int);
	Branch<T>* FindBranchParentOverloadHelper(const int);
	Branch<T>*GetChildOverloadHelper(const bool, const Branch<T>*);


	//functions related to erase

	void SimpleErase(Branch<T>*);//simple erase means that at least one of the children of the branch is nullptr
	void SimpleEraseRoot();
	void SimpleEraseLeftSlip(const bool, Branch<T>*);//means that the left child is not nullptr
	void SimpleEraseRightSlip(const bool, Branch<T>*);//means that the left child is not nullptr
	void ComplicatedErase(Branch<T>*);//complicated erase means that both children of the branch are not nullptr


	//others

	Branch<T>*GetChild(const bool, const Branch<T>*);//if true returns right child
	const Branch<T>*GetChild(const bool, const Branch<T>*)const;
	Branch<T> * FindBiggestLeftChild(Branch<T>*);//returns the biggest child of the ->left branch of the param

protected:
	void RotateRight(Branch<T>*);//the param is the first element that is going to be rotated
	void RotateLeft(Branch<T>*);//the param is the first element that is going to be rotated
public:
	//Essentials

	BinarySearchTree(const int = 0, const T & = T());
	virtual ~BinarySearchTree();


	//Element Access
	T& GetByKey(const int);
	const T& GetByKey(const int)const;
	Branch<T> * FindBranch(const int);//returns nullptr if element was not found
	const Branch<T> * FindBranch(const int)const;
	Branch<T> * FindBranchParent(const int);//if it returns nullptr, then the tree is empty or the searched elements is the root
	const Branch<T> * FindBranchParent(const int)const;

	//Modifiers
	virtual void insert(const int, const T&);
	virtual void insert(const Branch<T>&);
	virtual void erase(const int);
private:
	Branch<T> * m_Root;
};

template<class T>
inline Branch<T>::Branch(const int k, const T & v, Branch<T>* p) : key(k), val(v), parent(p), left(nullptr), right(nullptr)
{
}

template<class T>
inline Branch<T>::~Branch()
{
	delete right;
	delete left;
}

template<class T>
inline void Branch<T>::swap(Branch<T>*rhs)
{
	std::swap(key, rhs->key);
	std::swap(val, rhs->val);
}

template<class T>
inline bool Branch<T>::isRightChild()const
{
	try
	{
		if (parent != nullptr)
			return this == this->parent->right;
		else
			throw std::bad_function_call("trying to find the parent of the root\n");
	}
	catch (std::bad_function_call &bfc)
	{
		std::cerr << "bad_function_call exception thrown: " << bfc.what();
	}
}

template<class T>
inline T & BinarySearchTree<T>::GetByKeyOverloadHelper(const int numb)
{
	try
	{
		Branch<T> * tmp = FindBranch(numb);
		if (tmp == nullptr)
		{
			throw std::invalid_argument("no element with such a key found\n");
		}
		else
		{
			return tmp->val;
		}
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "GetByKey() threw an exception: " << ia.what();
	}
}

template<class T>
inline Branch<T>* BinarySearchTree<T>::FindBranchOverloadHelper(const int numb)
{
	Branch<T> * tmp = FindBranchParentOverloadHelper(numb);//the parent of the searched element
	if (tmp == nullptr)
	{
		return (this->m_Root == nullptr) ? nullptr : this->m_Root;
	}
	return (tmp->key > numb) ? tmp->left : tmp->right;
}

template<class T>
inline Branch<T>* BinarySearchTree<T>::FindBranchParentOverloadHelper(const int numb)
{
	Branch<T> * tmp = this->m_Root;
	Branch<T> * tmp2 = nullptr;
	while (tmp != nullptr)
	{
		if (tmp->key == numb)
		{
			return tmp2;
		}
		else
		{
			tmp2 = tmp;
			if (tmp->key > numb)
			{
				tmp = tmp->left;
			}
			else
			{
				tmp = tmp->right;
			}
		}
	}
	return tmp2;
}

template<class T>
inline Branch<T>* BinarySearchTree<T>::GetChildOverloadHelper(const bool r, const Branch<T>* rhs)
{
	return r ? rhs->right : rhs->left;
}

template<class T>
inline void BinarySearchTree<T>::SimpleErase(Branch<T>*rhs)
{
	if (rhs == this->m_Root)
	{
		SimpleEraseRoot();
	}
	else
	{
		bool isRightChild = rhs == rhs->parent->right;
		if (rhs->left != nullptr)
		{
			SimpleEraseLeftSlip(isRightChild, rhs);
		}
		else if (rhs->right != nullptr)
		{
			SimpleEraseRightSlip(isRightChild, rhs);
		}
		else
		{
			isRightChild ? rhs->parent->right = nullptr : rhs->parent->left = nullptr;
			delete rhs;
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::SimpleEraseRoot()
{
	if (this->m_Root->left != nullptr)
	{
		Branch<T> * tmp = this->m_Root;
		this->m_Root = this->m_Root->left;
		this->m_Root->parent = nullptr;
		tmp->left = nullptr;
		delete tmp;
	}
	else if (this->m_Root->right != nullptr)
	{
		Branch<T> * tmp = this->m_Root;
		this->m_Root = this->m_Root->right;
		this->m_Root->parent = nullptr;
		tmp->right = nullptr;
		delete tmp;
	}
	else
	{
		delete this->m_Root;
		this->m_Root = nullptr;
	}
}

template<class T>
inline void BinarySearchTree<T>::SimpleEraseLeftSlip(const bool isRightChild, Branch<T>* rhs)
{
	isRightChild ? rhs->parent->right = rhs->left : rhs->parent->left = rhs->left;
	rhs->left->parent = rhs->parent;
	rhs->left = nullptr;
	delete rhs;
}

template<class T>
inline void BinarySearchTree<T>::SimpleEraseRightSlip(const bool isRightChild, Branch<T>* rhs)
{
	isRightChild ? rhs->parent->right = rhs->right : rhs->parent->left = rhs->right;
	rhs->right->parent = rhs->parent;
	rhs->right = nullptr;
	delete rhs;
}

template<class T>
inline void BinarySearchTree<T>::ComplicatedErase(Branch<T>* rhs)
{
	Branch<T>* biggestLeftChild = FindBiggestLeftChild(rhs);
	rhs->swap(biggestLeftChild);
	SimpleErase(biggestLeftChild);
}

template<class T>
inline Branch<T>* BinarySearchTree<T>::GetChild(const bool r, const Branch<T>* rhs)
{
	return GetChildOverloadHelper(r, rhs);
}

template<class T>
inline const Branch<T>* BinarySearchTree<T>::GetChild(const bool r, const Branch<T>* rhs) const
{
	return GetChildOverloadHelper(r, rhs);
}

template<class T>
inline Branch<T>* BinarySearchTree<T>::FindBiggestLeftChild(Branch<T> * rhs)
{
	Branch<T> * tmp = rhs->left;
	while (tmp->right != nullptr)
	{
		tmp = tmp->right;
	}
	return tmp;
}

template<class T>
inline void BinarySearchTree<T>::RotateRight(Branch<T>* rhs)
{
	Branch<T>*eldest = rhs->parent;//the original parent of rhs has a very important role, using this to reduce code complexity
	rhs->parent = rhs->left;
	rhs->parent->parent = eldest;
	if (eldest != nullptr)
	{
		rhs->isRightChild() ? eldest->right = rhs->parent : eldest->left = rhs->parent;
	}
	else
	{
		this->m_Root = rhs->parent;
	}
	Branch<T>* tmp = rhs->parent->right;
	rhs->parent->right = rhs;
	rhs->left = tmp;
	tmp->parent = rhs;
}

template<class T>
inline void BinarySearchTree<T>::RotateLeft(Branch<T>*rhs)
{
	Branch<T>*eldest = rhs->parent;//the original parent of rhs has a very important role, using this to reduce code complexity
	rhs->parent = rhs->right;
	rhs->parent->parent = eldest;
	if (eldest != nullptr)
	{
		rhs->isRightChild() ? eldest->right = rhs->parent : eldest->left = rhs->parent;
	}
	else
	{
		this->m_Root = rhs->parent;
	}
	Branch<T>* tmp = rhs->parent->left;
	rhs->parent->left = rhs;
	rhs->right = tmp;
	tmp->parent = rhs;
}

template<class T>
inline BinarySearchTree<T>::BinarySearchTree(const int k, const T & v) : m_Root(new Branch<T>(k, v))
{
}

template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	delete this->m_Root;
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
inline Branch<T>* BinarySearchTree<T>::FindBranch(const int numb)
{
	return FindBranchOverloadHelper(numb);
}

template<class T>
inline const Branch<T>* BinarySearchTree<T>::FindBranch(const int numb) const
{
	return FindBranchOverloadHelper(numb);
}

template<class T>
inline Branch<T>* BinarySearchTree<T>::FindBranchParent(const int numb)
{
	return FindBranchParentOverloadHelper(numb);
}

template<class T>
inline const Branch<T>* BinarySearchTree<T>::FindBranchParent(const int) const
{
	return FindBranchParentOverloadHelper(numb);
}

template<class T>
inline void BinarySearchTree<T>::insert(const int numb, const T & val)
{
	if (this->m_Root == nullptr)
	{
		this->m_Root = new Branch<T>(numb, val);
	}
	else
	{
		Branch<T> * tmp = FindBranchParent(numb);
		bool isRight = tmp->key < numb;
		if (GetChild(isRight, tmp) != nullptr)
		{
			std::cerr << "Operation insert failed, because there is already an element with such a key\n";
		}
		else
		{
			if (isRight)
			{
				tmp->right = new Branch<T>(numb, val, tmp);
			}
			else
			{
				tmp->left = new Branch<T>(numb, val, tmp);
			}
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::insert(const Branch<T>&rhs)
{
	insert(rhs.key, rhs.val);
}

template<class T>
inline void BinarySearchTree<T>::erase(const int numb)
{
	Branch<T> * tmp = FindBranch(numb);
	if (tmp != nullptr)
	{
		if (tmp->left == nullptr || tmp->right == nullptr)
		{
			SimpleErase(tmp);
		}
		else
		{
			ComplicatedErase(tmp);
		}
	}
}
