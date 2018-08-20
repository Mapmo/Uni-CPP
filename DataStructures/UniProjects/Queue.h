#pragma once
#pragma once
template <class T>
class Queue
{
	void grow();
	void push_left();//in case there are many erased elements in the queue, this will push all elemnts left and free some space
public:
	Queue();
	Queue(const Queue<T>&);
	Queue<T>& operator = (const Queue<T>&);
	~Queue();


	//Element Access

	int getLength()const;
	const T& top()const;
	bool empty()const;


	//Modifiers

	T pop();
	void push(T);

private:
	unsigned int m_Left;
	unsigned int m_Right;
	int m_Size;
	T * m_Data;
};

//default constructor
template <class T>
Queue<T>::Queue() : m_Left(0), m_Size(4), m_Right(0)
{
	this->m_Data = new T[m_Size];
}

//copy constructor
template <class T>
Queue<T>::Queue(const Queue<T>& oldStack) : m_Left(oldStack.m_Left), m_Size(oldStack.m_Size), m_Right(oldStack.m_Right)
{
	this->m_Data = new T[m_Size];
	for (int i = m_Left; i < m_Right; i++)
	{
		this->m_Data[i] = oldStack.m_Data[i];
	}
}

template <class T>
Queue<T>::~Queue()
{
	delete[] this->m_Data;
}

//operator =
template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& old)
{
	if (this != &old)
	{
		this->m_Left = old.m_Left;
		this->m_Right = old.m_Right;
		this->m_Size = old.m_Size;

		delete[] this->m_Data;
		this->m_Data = new T[m_Size];

		for (int i = m_Left; i < m_Right; i++)
		{
			this->m_Data[i] = oldStack.m_Data[i];
		}
	}
	return *this;
}

//if the stackSize of the stack is reached, this will increment the limit
template <class T>
void Queue<T>::grow()
{
	this->m_Size *= 2;
	T *newArr = new T[m_Size];
	for (int i = 0; i < m_Size; i++)
	{
		newArr[i] = this->m_Data[i];
	}
	delete[] m_Data;
	m_Data = newArr;
}

template<class T>
inline void Queue<T>::push_left()
{
	int i = 0;
	for (; i < this->m_Size - this->m_Left; ++i)
	{
		this->m_Data[i] = this->m_Data[i + this->m_Left];
	}
	this->m_Left -= i;
	this->m_Right -= i;
}

template <class T>
void Queue<T>::push(T a)
{
	if (this->m_Right == m_Size)
	{
		if (this->m_Left >= m_Size / 2)
		{
			push_left();
		}
		else
		{
			grow();
		}
	}
	this->m_Data[this->m_Right++] = a;
}

//a simple getter
template<class T>
int Queue<T>::getLength() const
{
	return this->m_Right-this->m_Left;
}


//returns the top of the stack and then decrements length
template <class T>
T Queue<T>::pop()
{
	if (empty())
	{
		std::cout << "Error, queue is empty" << std::endl;
		return 0;
	}
	else
	{
		return this->m_Data[this->m_Left++];
	}
}

//returns the top of the array
template <class T>
const T& Queue<T>::top() const
{
	return this->m_Data[m_Right-1];
}

//checks if the stack is empty
template <class T>
bool Queue<T>::empty()const
{
	return  (this->m_Left == this->m_Right) ? 1 : 0;
}