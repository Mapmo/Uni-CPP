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
	Deque(const Deque<T>&);
	Deque<T>& operator=(const Deque<T>&);
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
	void ConstructorAlloc();//used to properly allocate memory during construction(only for construction!)
	bool Resize(const bool);


	//members

	unsigned int m_Left;//index of the first element, will be 0 even if the array is empty, so it needs an empty() check before being used
	unsigned int m_Right;//1 index after last element
	unsigned int m_Size;//size of the current array
	T * m_Data;
private:
	const unsigned int m_MAX_SIZE;
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
inline T & Deque<T>::atOverloadHelper(const unsigned int numb) const
{
	try
	{
		if (numb < this->m_Left || numb>= this->m_Right)
		{
			throw std::out_of_range("in function Vector::at(const unsigned int)");
		}
		return this->m_Data[numb];
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range" << oor.what() << std::endl;
	}
	return this->m_Data[this->m_Left];
}

template<class T>
inline Deque<T>::Deque() : m_Left(0), m_Right(0), m_MAX_SIZE(CalculateMaxSize())
{
	ConstructorAlloc();
}

template<class T>
inline Deque<T>::Deque(const int repeat, const T & data) : m_Left(0), m_Right(repeat), m_MAX_SIZE(CalculateMaxSize())
{
	ConstructorAlloc();

	for (unsigned int i = 0; i < repeat; ++i)
	{
		this->m_Data[i] = data;
	}
}

template<class T>
inline Deque<T>::Deque(const Deque<T>& rhs) : m_Left(rhs.m_Left), m_Right(rhs.m_Right), m_MAX_SIZE(rhs.m_MAX_SIZE)
{
	ConstructorAlloc();

	for (unsigned int i = this->m_Left; i <= this->m_Right; ++i)
	{
		this->m_Data[i] = rhs.m_Data[i];
	}

}

template<class T>
inline Deque<T>& Deque<T>::operator=(const Deque<T>& rhs)
{
	if (this != &rhs)
	{
		delete[] this->m_Data;

		this->m_Left = rhs.m_Left;
		this->m_Right = rhs.m_Right;
		ConstructorAlloc();

		for (unsigned int i = this->m_Left; i <= this->m_Right; ++i)
		{
			this->m_Data[i] = rhs.m_Data[i];
		}
	}
	return *this;
}

template<class T>
inline Deque<T>::~Deque()
{
	delete[] this->m_Data;
}

template<class T>
inline T & Deque<T>::at(const unsigned int numb)
{
	return atOverloadHelper(numb);
}

template<class T>
inline const T & Deque<T>::at(const unsigned int numb) const
{
	return atOverloadHelper(numb);
}

template<class T>
inline T & Deque<T>::operator[](const int numb)
{
	return atOverloadHelper(numb);
}

template<class T>
inline const T & Deque<T>::operator[](const int) const
{
	return atOverloadHelper();
}

template<class T>
inline void Deque<T>::AdaptSize(const unsigned int numb)
{
	if (numb == 0)
	{
		this->m_Size = 2;
	}
	else if (numb <= this->m_MAX_SIZE / 2)
	{
		this->m_Size = FindClosestPowerOf2toNumber(numb) * 2;
	}
	else if (numb <= this->m_MAX_SIZE)
	{
		this->m_Size = FindClosestPowerOf2toNumber(numb);
	}
	else
	{
		this->m_Size = m_MAX_SIZE + 1;//exception will be handled by ConstructorAlloc
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
		if (this->m_Size > this->m_MAX_SIZE)
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
	(rhs && this->m_Size < this->m_MAX_SIZE) ? this->m_Size *= 2 : this->m_Size /= 2;
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
