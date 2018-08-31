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
public:
	BinarySearchTree2(const int = 0, const T & = T());
	virtual ~BinarySearchTree2();
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
inline BinarySearchTree2<T>::BinarySearchTree2(const int k, const T & v) : m_Root(new Branch<T>(k, v))
{
}

template<class T>
inline BinarySearchTree2<T>::~BinarySearchTree2()
{
	delete this->m_Root;
}
