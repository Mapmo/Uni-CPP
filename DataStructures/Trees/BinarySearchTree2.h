#pragma once

template <class T>
struct Branch
{
	Branch(const int = 0, const T& = T(), Branch<T>* = nullptr);
	~Branch();

	int key;
	T val;

	Branch<T> * left;
	Branch<T> * right;
	Branch<T> * parent;
};

template <class T>
class BinarySearchTree2
{
	BinarySearchTree2(const BinarySearchTree2&) = delete;
	const BinarySearchTree2<T>& operator=(const BinarySearchTree2&) = delete;

	//OverloadHelpers
	T& GetByKeyOverloadHelper(const int);
	Branch<T>* FindBranchOverloadHelper(const int);
public:
	//Essentials

	BinarySearchTree2(const int = 0, const T & = T());
	virtual ~BinarySearchTree2();


	//Element Access
	T& GetByKey(const int);
	const T& GetByKey(const int)const;
	Branch<T> * FindBranch(const int);//returns nullptr if element was not found
	const Branch<T> * FindBranch(const int)const;


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
inline T & BinarySearchTree2<T>::GetByKeyOverloadHelper(const int numb)
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
inline Branch<T>* BinarySearchTree2<T>::FindBranchOverloadHelper(const int numb)
{
	Branch<T> * tmp = this->m_Root;
	while (tmp != nullptr)
	{
		if (tmp->key == numb)
		{
			return tmp;
		}
		else if (tmp->key > numb)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}
	return tmp;
}

template<class T>
inline BinarySearchTree2<T>::BinarySearchTree2(const int k, const T & v) : m_Root(new Branch<T>(k, v))
{
}

template<class T>
inline BinarySearchTree2<T>::~BinarySearchTree2()
{
	delete this->m_Root;
}

template<class T>
inline T & BinarySearchTree2<T>::GetByKey(const int numb)
{
	return GetByKeyOverloadHelper(numb);
}

template<class T>
inline const T & BinarySearchTree2<T>::GetByKey(const int numb) const
{
	return GetByKeyOverloadHelper(numb);
}

template<class T>
inline Branch<T>* BinarySearchTree2<T>::FindBranch(const int numb)
{
	return FindBranchOverloadHelper(numb);
}

template<class T>
inline const Branch<T>* BinarySearchTree2<T>::FindBranch(const int numb) const
{
	return FindBranchOverloadHelper(numb);
}

