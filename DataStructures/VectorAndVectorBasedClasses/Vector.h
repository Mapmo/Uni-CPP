#pragma once
#include <iostream>
#include "..\src\UsefulFunctions.h"

const unsigned int MAXBYTES = 1073741824; //2^30

template <class T>
class Vector
{
	static_assert(!std::is_const<T>::value,			//the stl library does the same when T is const
		"The C++ Standard forbids containers of const elements because allocator<const T> is ill-formed.");
	T& atOverloadHelper(const unsigned int)const;
	T& frontOverloadHelper()const;
	T& backOverloadHelper()const;
	T* dataOverloadHelper()const;
public:


	//Essentials

	Vector();
	Vector(const int, const T&);
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	void assign(const unsigned int, const T&);
	~Vector();


	//ElementAccess

	T& at(const unsigned int);
	const T& at(const unsigned int) const;
	T& operator [](const int);
	const T& operator [](const int)const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	T* data() noexcept;//error prone, but such is the original vector
	const T* data() const noexcept;


	//Capacity

	bool empty() const noexcept;
	bool full()const noexcept;
	unsigned int size()const  noexcept;//actually it's GetCounter()
	unsigned int max_size() const noexcept;
	unsigned int capacity() const noexcept;
	void shrink_to_fit();


	//Modifiers

	void clear() noexcept;
	Vector<T>& erase(const unsigned int);
	Vector<T>& insert(const unsigned int, const T&);
	Vector<T>& insert(const unsigned int, const unsigned int, const T&);
	Vector<T>& pop_back();
	Vector<T>& push_back(const T&);
	void swap(Vector<T>&);


	//non-member functions

	template<class T1>
	friend void swap(Vector<T1>&, Vector<T1>&);
	template<class T2>
	friend bool operator==(const Vector<T2>&, const Vector<T2>&);
	template<class J>
	friend bool operator!=(const Vector<J>&, const Vector<J>&);

protected:

	//functions

	void AdaptSize(const unsigned int);
	void CalculateMaxSize();
	void ConstructorAlloc();
	bool Resize(const bool);

	//members
	unsigned int m_Counter;
	unsigned int m_Size;
	T * m_Data;
private:
	unsigned int m_MaxSize;
};

template<class T>
inline Vector<T>::Vector() : m_Counter(0)
{
	CalculateMaxSize();
	ConstructorAlloc();
}

template<class T>
inline Vector<T>::Vector(const int repeat, const T& data) : m_Counter(repeat)
{
	CalculateMaxSize();
	ConstructorAlloc();

	for (unsigned int i = 0; i < repeat; ++i)
	{
		this->m_Data[i] = data;
	}
}

template<class T>
inline Vector<T>::Vector(const Vector<T> & rhs) : m_Counter(rhs.m_Counter)
{
	CalculateMaxSize();
	ConstructorAlloc();
	for (unsigned int i = 0; i < rhs.m_Counter; ++i)
	{
		this->m_Data[i] = rhs.m_Data[i];
	}
}

template<class T>
inline Vector<T> & Vector<T>::operator=(const Vector<T> & rhs)
{
	if (this != &rhs)
	{
		delete[] this->m_Data;
		this->m_Counter = rhs.m_Counter;
		ConstructorAlloc();
		for (unsigned int i = 0; i < rhs.m_Counter; ++i)
		{
			this->m_Data[i] = rhs.m_Data[i];
		}
	}
	return *this;
}

template<class T>
inline Vector<T>::~Vector<T>()
{
	delete[] this->m_Data;
}

template<class T>
inline T & Vector<T>::at(const unsigned int pos)
{
	return atOverloadHelper(pos);
}

template<class T>
inline const T & Vector<T>::at(const unsigned int pos) const
{
	return atOverloadHelper(pos);
}

template<class T>
inline void Vector<T>::assign(const unsigned int count, const T & value)
{
	delete[] this->m_Data;
	this->m_Counter = count;
	ConstructorAlloc();
	for (unsigned int i = 0; i < count; ++i)
	{
		this->m_Data[i] = value;
	}
}

template<class T>
inline bool Vector<T>::empty() const noexcept
{
	return !this->m_Counter;
}

template<class T>
inline bool Vector<T>::full() const noexcept
{
	return this->m_Counter == this->m_MaxSize;
}

template<class T>
inline unsigned int Vector<T>::size() const noexcept
{
	return this->m_Counter;
}

template<class T>
inline unsigned int Vector<T>::max_size() const noexcept
{
	return this->m_MaxSize;
}

template<class T>
inline unsigned int Vector<T>::capacity() const noexcept
{
	return this->m_Size;
}

template<class T>
inline void Vector<T>::shrink_to_fit()
{
	T* tmp = new T[this->m_Size];
	for (unsigned int i = 0; i < this->m_Counter; ++i)
	{
		tmp[i] = this->m_Data[i];
	}
	delete[] this->m_Data;
	this->m_Data = tmp;
}

template<class T>
inline Vector<T>& Vector<T>::push_back(const T & rhs)
{
	if (full())
	{
		std::cerr << "Vector is full\n";
	}
	else
	{
		this->m_Data[this->m_Counter++] = rhs;
		if (this->m_Counter == this->m_Size)
		{
			Resize(1);
		}
	}
	return *this;
}

template<class T>
inline void Vector<T>::swap(Vector<T>&rhs)
{
	std::swap(this->m_Counter, rhs.m_Counter);
	std::swap(this->m_Size, rhs.m_Size);
	T * tmp = this->m_Data;
	this->m_Data = rhs.m_Data;
	rhs.m_Data = tmp;
}

template<class T>
inline bool operator==(const Vector <T> & lhs, const Vector <T> & rhs)
{
	if (&lhs == &rhs)
	{
		return true;
	}
	else if (lhs.m_Counter != rhs.m_Counter)
	{
		return false;
	}
	else
	{
		for (unsigned int i = 0; i < lhs.m_Counter; ++i)
		{
			if (lhs.m_Data[i] != rhs.m_Data[i])
			{
				return false;
			}
		}
	}
	return true;
}

template<class T>
inline bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
{
	return !operator==(lhs, rhs);
}

template<class T>
inline void swap(Vector<T>& lhs, Vector<T>& rhs)
{
	std::swap(lhs.m_Counter, rhs.m_Counter);
	std::swap(lhs.m_Size, rhs.m_Size);
	T * tmp = lhs.m_Data;
	lhs.m_Data = rhs.m_Data;
	rhs.m_Data = tmp;
}

template<class T>
inline void Vector<T>::clear() noexcept
{
	this->m_Counter = 0;
	delete[] this->m_Data;
	ConstructorAlloc();
}

template<class T>
inline Vector<T>& Vector<T>::erase(const unsigned int rhs)
{
	if (rhs >= this->m_Counter)
	{
		std::cerr << "Index out of range\n";
	}
	else
	{
		for (unsigned int i = rhs; i < this->m_Counter - 1; ++i)
		{
			this->m_Data[i] = m_Data[i + 1];
		}
		if (--this->m_Counter == this->m_Size / 4)
		{
			Resize(0);
		}
	}
	return *this;
}

template<class T>
inline Vector<T>& Vector<T>::insert(const unsigned int pos, const T & val)
{
	insert(pos, 1, val);
	return *this;
}

template<class T>
inline Vector<T>& Vector<T>::insert(const unsigned int pos, const unsigned int times, const T & val)
{
	if (full())
	{
		std::cerr << "Vector is full\n";
	}
	else if (pos > this->m_Counter)
	{
		std::cerr << "Cannot insert out of range of the vector\n";
	}
	else
	{
		this->m_Counter += times;
		while (this->m_Counter >= this->m_Size)
		{
			if (!Resize(1))
			{
				std::cerr << "insert failed due to unavailable space\n";
				return *this;
			}
		}
		for (unsigned int i = this->m_Counter - 1; i > pos; --i)
		{
			this->m_Data[i] = this->m_Data[i - times];
		}
		for (int i = 0; i < times; ++i)
		{
			this->m_Data[pos + i] = val;
		}
	}
	return *this;
}

template<class T>
inline Vector<T>& Vector<T>::pop_back()//returning a refference to the object seems reasonable, although the original function is void
{
	if (empty())//although std::vector has undefined behaviour in this case, i still do this check 
	{
		std::cerr << "pop_back failed, because vector is empty.\n";
	}
	else
	{
		if (--this->m_Counter == this->m_Size / 4)
		{
			Resize(0);
		}
	}
	return *this;
}

template<class T>
inline T & Vector<T>::operator[](const int numb)
{
	return atOverloadHelper(numb);
}

template<class T>
inline const T & Vector<T>::operator[](const int numb) const
{
	return atOverloadHelper(numb);
}

template<class T>
inline T & Vector<T>::front()
{
	return frontOverloadHelper();
}

template<class T>
inline const T & Vector<T>::front() const
{
	return frontOverloadHelper();
}

template<class T>
inline T & Vector<T>::back()
{
	return backOverloadHelper();
}

template<class T>
inline const T& Vector<T>::back() const
{
	return backOverloadHelper();
}

template<class T>
inline T * Vector<T>::data() noexcept
{
	return dataOverloadHelper();
}

template<class T>
inline const T * Vector<T>::data() const noexcept
{
	return dataOverloadHelper();
}

template<class T>
inline void Vector<T>::AdaptSize(const unsigned int numb)
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
inline void Vector<T>::CalculateMaxSize()
{
	this->m_MaxSize = FindClosestPowerOf2toNumber(MAXBYTES / sizeof(T));
}

template<class T>
inline bool Vector<T>::Resize(const bool rhs)
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

template<class T>
inline void Vector<T>::ConstructorAlloc()
{
	AdaptSize(this->m_Counter);
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
inline T & Vector<T>::atOverloadHelper(const unsigned int pos) const
{
	try
	{
		if (!(pos < size()))
		{
			throw std::out_of_range("in function Vector::at(const unsigned int)");
		}
	return this->m_Data[pos];
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range" << oor.what() << std::endl;
	}
	return this->m_Data[size()-1];
}

template<class T>
inline T& Vector<T>::frontOverloadHelper() const
{
	try
	{
		if (empty())
		{
			throw std::out_of_range("the vector is empty");
		}
	}
	catch (std::out_of_range & oor)
	{
		std::cerr << "Out of Range exception thrown " << oor.what() << std::endl;
	}
	return this->m_Data[0];
}

template<class T>
inline T & Vector<T>::backOverloadHelper() const
{
	try
	{
		if (empty())
		{
			throw std::out_of_range("the vector is empty");
		}
	}
	catch (std::out_of_range & oor)
	{
		std::cerr << "Out of Range exception thrown " << oor.what() << std::endl;
	}
	return this->m_Data[this->m_Counter - 1];
}

template<class T>
inline T * Vector<T>::dataOverloadHelper() const
{
	if (empty())
	{
		return nullptr;
	}
	else
	{
		return this->m_Data;
	}
}

