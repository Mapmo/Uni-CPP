#pragma once
#include "..\src\UsefulFunctions.h"

template <class T>
class Deque
{
	static_assert(!std::is_const<T>::value,			//the stl library does the same when T is const
		"The C++ Standard forbids containers of const elements because allocator<const T> is ill-formed.");

	void push_left();//in case there is enough space in the Deque, this will push all elemnts left and free some space
	void push_right();//in case there is enough space in the Deque, this will push all elemnts right and free some space
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
	void shrink_to_fit();//push_left and then delete everything else


	//Modifiers

	void clear() noexcept;
	Deque<T>& erase(const unsigned int);

	//The rule for adding is that there is always place to add, 
	//and after every adding a check is done to ensure that it will be save to add next time
	Deque<T>& insert(const unsigned int, const T&);
	Deque<T>& insert(const unsigned int, const unsigned int, const T&);
	void pop_back();
	void pop_front();
	void push_back(const T&);
	void push_front(const T&);
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
	void ConstructorAlloc();//used to properly allocate memory during construction(does not release previously allocated memory!)
	bool Resize();


	//members

	unsigned int m_Left;//index of the first element, will be 0 even if the array is empty, so it needs an empty() check before being used
	unsigned int m_Right;//1 index after last element
	unsigned int m_Size;//size of the current array
	T * m_Data;
private:
	const unsigned int m_MAX_SIZE;
};

template<class T>
inline void Deque<T>::push_left()//if called then m_Left>m_Size/2, so it's safe to presume that m_Data[m_Size/4] will be free to overwrite
{
	unsigned int counter = 0;
	for (unsigned int i = m_Size / 4; counter < size(); ++counter)
	{
		this->m_Data[i + counter] = this->m_Data[counter + this->m_Left];//will move all elements several places left
	}
	this->m_Left -= counter;
	this->m_Right -= counter;
}

template<class T>
inline void Deque<T>::push_right()//if called then m_Right<m_Size/2, so it's safe to presume that m_Data[3*m_Size/4] will be free to overwrite
{
	unsigned int counter = 0;
	for (unsigned int i = (3 * m_Size) / 4; counter < size(); ++counter)
	{
		this->m_Data[i - counter] = this->m_Data[counter + this->m_Right - 1];//will move all elements several places left
	}
	this->m_Left += counter;
	this->m_Right += counter;
}

template<class T>
inline T & Deque<T>::atOverloadHelper(const unsigned int numb) const
{
	try
	{
		if (numb < this->m_Left || numb >= this->m_Right)
		{
			throw std::out_of_range("in function Vector::at(const unsigned int)");
		}
		return this->m_Data[this->m_Left + numb];
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range" << oor.what() << std::endl;
	}
}

template<class T>
inline T & Deque<T>::frontOverloadHelper() const
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
	return this->m_Data[m_Left];
}

template<class T>
inline T & Deque<T>::backOverloadHelper() const
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
	return this->m_Data[this->m_Right - 1];
}

template<class T>
inline Deque<T>::Deque() : m_Left(2), m_Right(2), m_MAX_SIZE(CalculateMaxSize())
{
	ConstructorAlloc();
}

template<class T>
inline Deque<T>::Deque(const int repeat, const T & data) : m_Left(1), m_Right(repeat), m_MAX_SIZE(CalculateMaxSize())
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

	for (unsigned int i = this->m_Left; i < this->m_Right; ++i)
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
inline T & Deque<T>::front()
{
	return frontOverloadHelper();
}

template<class T>
inline const T & Deque<T>::front() const
{
	return frontOverloadHelper();
}

template<class T>
inline T & Deque<T>::back()
{
	return backOverloadHelper();
}

template<class T>
inline const T & Deque<T>::back() const
{
	return backOverloadHelper();
}

template<class T>
inline void Deque<T>::AdaptSize(const unsigned int numb)
{
	if (numb == 0)
	{
		this->m_Size = 4;
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
inline bool Deque<T>::Resize() //if Resize() is called we know that m_Left is smaller than m_Size/2 and m_Right is greater or equal to m_Size/2
{
	try
	{
		AdaptSize(size());
		if (this->m_Size == this->m_MAX_SIZE + 1)
		{
			throw std::bad_alloc();
		}
		T* temp = new T[this->m_Size];
		unsigned int counter = 0;
		for (unsigned int i = this->m_Size / 4; counter < size(); ++counter)
		{
			temp[i + counter] = this->m_Data[counter + this->m_Left];
		}
		delete[] this->m_Data;
		this->m_Data = temp;
		this->m_Right = this->m_Size / 4 + size();
		this->m_Left = this->m_Size / 4;
		return true;
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		--this->m_Size /= 2;//reverses alteration
		return false;
	}
}

template<class T>
inline bool Deque<T>::empty() const noexcept
{
	return this->m_Right == this->m_Left;
}

template<class T>
inline bool Deque<T>::full() const noexcept
{
	return (this->m_Left == 0 && this->m_Right == this->m_Size);
}

template<class T>
inline unsigned int Deque<T>::size() const noexcept
{
	return this->m_Right - this->m_Left;
}

template<class T>
inline unsigned int Deque<T>::max_size() const noexcept
{
	return this->m_MAX_SIZE;
}

template<class T>
inline void Deque<T>::shrink_to_fit()
{
	T* tmp = new T[this->m_Size];

	for (unsigned int i = this->m_Left; i < this->m_Right; ++i)
	{
		tmp[i - this->m_Left] = this->m_Data[i];
	}
	delete[] this->m_Data;
	this->m_Data = tmp;
}

template<class T>
inline void Deque<T>::clear() noexcept
{
	delete[] this->m_Data;
	this->m_Left = 0;
	this->m_Right = 0;
	ConstructorAlloc();
}

template<class T>
inline Deque<T>& Deque<T>::erase(const unsigned int numb)
{
	try
	{
		if (numb < 0 || numb >= size())
		{
			throw std::out_of_range("Erase index oor");
		}
		else if (numb == 0)
		{
			pop_front();
		}
		else if (numb == size() - 1)
		{
			pop_back();
		}
		else if (numb < size()/2)//this is used to optimize the erase operation and make fewer operations to erase an element
		{
			for (int i = numb + this->m_Left; i > this->m_Left; --i)
			{
				std::swap(this->m_Data[i], this->m_Data[i - 1]);
			}
			//after the loop, the element to delete becomes first in the array
			pop_front();
		}
		else
		{
			for (int i = numb+ this->m_Left; i < this->m_Right - 1; ++i)
			{
				std::swap(this->m_Data[i], this->m_Data[i + 1]);
			}
			//after the loop, the element to delete becomes last in the array
			pop_back();
		}
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range exception caught: " << oor.what() << std::endl;
	}
	return *this;
}

template<class T>
inline void Deque<T>::pop_back()
{
	try
	{
		if (empty())
		{
			throw std::out_of_range("pop_back cannot remove from an empty array");
		}
		else
		{
			--this->m_Right;
			if (size() == this->m_Size / 4)
			{
				if (this->m_Left > this->m_Size / 2)
				{
					push_left();
				}
				else if (this->m_Right < this->m_Size / 2)
				{
					push_right();
				}
				else
				{
					Resize();
				}
			}
		}
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range exception caught: " << oor.what() << std::endl;
	}
}
template<class T>
inline void Deque<T>::pop_front()
{
	try
	{
		if (empty())
		{
			throw std::out_of_range("pop_front cannot remove from an empty array");
		}
		else
		{
			++this->m_Left;
			if (size() == this->m_Size / 4)
			{
				if (this->m_Left > this->m_Size / 2)
				{
					push_left();
				}
				else if (this->m_Right < this->m_Size / 2)
				{
					push_right();
				}
				else
				{
					Resize();
				}
			}
		}
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range exception caught: " << oor.what() << std::endl;
	}
}
template<class T>
inline void Deque<T>::push_back(const T & rhs)
{
	try
	{
		if (this->m_Right == this->m_MAX_SIZE)//means that adding is impossible
		{
			throw std::out_of_range("push_back cannot add anymore");
		}
		else
		{
			this->m_Data[this->m_Right++] = rhs;//it's always safe to insert elements
			if (this->m_Right == this->m_Size)
			{
				if (this->m_Left > this->m_Size / 2)
				{
					push_left();
				}
				else
				{
					Resize();
				}
			}
		}
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range exception caught: " << oor.what() << std::endl;
	}
}

template<class T>
inline void Deque<T>::push_front(const T & rhs)
{

	try
	{
		if (this->m_Right == this->m_MAX_SIZE)//means that adding is impossible
		{
			throw std::out_of_range("push_front cannot add anymore");
		}
		else
		{
			if (this->m_Left == 0)
			{
				if (this->m_Right < this->m_Size / 2)
				{
					push_right();
				}
				else
				{
					Resize();
				}
			}
			this->m_Data[--this->m_Left] = rhs;//safe 
		}
	}
	catch (std::out_of_range& oor)
	{
		std::cerr << "Out of range exception caught: " << oor.what() << std::endl;
	}
}
