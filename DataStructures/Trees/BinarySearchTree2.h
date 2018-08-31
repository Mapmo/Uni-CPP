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
public:
	//Essentials

	BinarySearchTree2(const int = 0, const T & = T());
	virtual ~BinarySearchTree2();


	//Element Access
	T& GetByKey(const int);
	const T& GetByKey(const int)const;
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
		Branch<T> * tmp = this->m_Root;
		while (tmp != nullptr)
		{
			if (tmp->key == numb)
			{
				return tmp->val;
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
		throw std::invalid_argument("no element with such a key found\n");
	}
	catch (std::invalid_argument& ia)
	{
		std::cerr << "GetByKey() threw an exception: " << ia.what();
	}
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
