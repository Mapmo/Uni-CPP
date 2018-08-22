#pragma once

template <class T>
class Deque
{
public:
	static_assert(!std::is_const<T>::value,			//the stl library does the same when T is const
		"The C++ Standard forbids containers of const elements because allocator<const T> is ill-formed.");
	T& atOverloadHelper(const unsigned int)const;
	T& frontOverloadHelper()const;
	T& backOverloadHelper()const;
	T* dataOverloadHelper()const;
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
	void CalculateMaxSize();
	void ConstructorAlloc();
	bool Resize(const bool);


	//members

	unsigned int m_Left;
	unsigned int m_Right;
	unsigned int m_Size;
	T * m_Data;
private:
	unsigned int m_MaxSize;
};