#pragma once
#include "..\src\UsefulFunctions.h"

template <class T>
class Deque
{
	static_assert(!std::is_const<T>::value,			//the stl library does the same when T is const
		"The C++ Standard forbids containers of const elements because allocator<const T> is ill-formed.");

	void push_left();//in case there are many erased elements in the queue, this will push all elemnts left and free some space
	T& atOverloadHelper(const unsigned int)const;
	T& frontOverloadHelper()const;
	T& backOverloadHelper()const;

public:
	//Essentials

	Deque();
	Deque(const int, const T&);
	Deque(const Vector<T>&);
	Deque<T>& operator=(const Deque<T>&);
	void assign(const unsigned int, const T&);
	~Deque();


	//ElementAccess

	T& at(const unsigned int);
	const T& at(const unsigned int) const;
	T& operator [](const int);
	const T& operator [](const int)const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;


	//Capacity

	bool empty() const noexcept;
	bool full()const noexcept;
	unsigned int size()const  noexcept;//actually it's GetCounter()
	unsigned int max_size() const noexcept;
	void shrink_to_fit();


	//Modifiers

	void clear() noexcept;
	Deque<T>& erase(const unsigned int);
	Deque<T>& insert(const unsigned int, const T&);
	Deque<T>& insert(const unsigned int, const unsigned int, const T&);
	Deque<T>& pop_back();
	Deque<T>& push_back(const T&);
	void swap(Deque<T>&);


	//non-member functions

	template<class T1>
	friend void swap(Deque<T1>&, Deque<T1>&);
	template<class T2>
	friend bool operator==(const Deque<T2>&, const Deque<T2>&);
	template<class J>
	friend bool operator!=(const Deque<J>&, const Deque<J>&);
protected:
	//functions

	void AdaptSize(const unsigned int);
	unsigned int CalculateMaxSize();
	void ConstructorAlloc();
	bool Resize(const bool);


	//members

	unsigned int m_Left;//index of the first element
	unsigned int m_Right;//index of the last element
	unsigned int m_Size;//size of the current array
	T * m_Data;
private:
	const unsigned int m_MaxSize;
};

template<class T>
inline void Deque<T>::push_left()
{
	int i = 0;
	for (; i < this->m_Size - this->m_Left; ++i)
	{
		this->m_Data[i] = this->m_Data[i + this->m_Left];
	}
	this->m_Left -= i;
	this->m_Right -= i;
}

template<class T>
inline Deque<T>::Deque() : m_Left(0), m_Right(0), m_MaxSize(CalculateMaxSize())
{
	ConstructorAlloc();
}

template<class T>
inline Deque<T>::~Deque()
{
	delete[] this->m_Data;
}

template<class T>
inline void Deque<T>::AdaptSize(const unsigned int numb)
{
	if (numb == 0)
	{
		this->m_Size = 2;
	}
	else if (numb <= this->m_MaxSize / 2)
	{
		this->m_Size = FindClosestPowerOf2toNumber(numb) * 2;
	}
	else if (numb <= this->m_MaxSize)
	{
		this->m_Size = FindClosestPowerOf2toNumber(numb);
	}
	else
	{
		this->m_Size = m_MaxSize + 1;//exception will be handled by ConstructorAlloc
	}
}

template<class T>
inline unsigned int Deque<T>::CalculateMaxSize()
{
	return FindClosestPowerOf2toNumber(MAXBYTES / sizeof(T));
}

template<class T>
inline void Deque<T>::ConstructorAlloc()
{
	AdaptSize(this->m_Right);
	try
	{
		if (this->m_Size > this->m_MaxSize)
		{
			std::cout << "Vector cannot handle such a big array\n";
			throw std::bad_alloc();
		}
		this->m_Data = new T[this->m_Size];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		exit(1);
	}
}

template<class T>
inline bool Deque<T>::Resize(const bool rhs)
{
	(rhs && this->m_Size < this->m_MaxSize) ? this->m_Size *= 2 : this->m_Size /= 2;
	T* temp;
	try
	{
		temp = new T[this->m_Size];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		(!rhs) ? this->m_Size *= 2 : this->m_Size /= 2;//reverse of the first m_Size alteration
		return false;
	}
	for (unsigned int i = 0; i < this->m_Counter; ++i)
	{
		temp[i] = this->m_Data[i];
	}
	delete[] this->m_Data;
	this->m_Data = temp;
	return true;
}
