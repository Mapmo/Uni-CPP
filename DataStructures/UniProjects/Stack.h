#pragma once
template <class T>
class Stack
{
private:
	int length;
	int stackSize;
	T * arr;
public:
	Stack();
	Stack(const Stack<T>&);
	~Stack();

	Stack<T>& operator = (const Stack<T>&);

	void grow();
	void push(T);
	int getLength()const;
	T pop();
	T top()const;
	bool isEmpty()const;
};

//default constructor
template <class T>
Stack<T>::Stack()
{
	this->length = -1;
	this->stackSize = 10;
	this->arr = new T[stackSize];
	for (int i = 0; i < stackSize; i++)
	{
		arr[i] = 0;
	}
}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack<T>& oldStack)
{
	this->stackSize = oldStack.stackSize;
	this->length = oldStack.length;
	this->arr = new T[stackSize];

	for (int i = 0; i < stackSize; i++)
	{
		this->arr[i] = oldStack.arr[i];
	}
}

template <class T>
Stack<T>::~Stack()
{
	delete[] this->arr;
}

//operator =
template <class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& old)
{
	if (this != &old)
	{
		this->length = old.length;
		this->stackSize = old.stackSize;

		delete[] this->arr;
		this->arr = new T[stackSize];

		for (int i = 0; i < stackSize; i++)
		{
			this->arr[i] = old.arr[i];
		}
	}
	return *this;
}

//if the stackSize of the stack is reached, this will increment the limit
template <class T>
void Stack<T>::grow()
{
	this->stackSize *= 2;
	T *newArr = new T[stackSize];
	for (int i = 0; i < stackSize; i++)
	{
		newArr[i] = this->arr[i];
	}
	delete[] arr;
	arr = newArr;
}

//increments length and adds a new member to the stack or changes an existing member
//will call for the grow() function if the stackSize is reached
template <class T>
void Stack<T>::push(T a)
{
	if (length == stackSize - 1)
	{
		grow();
	}

	this->length++;
	this->arr[this->length] = a;
}

//a simple getter
template<class T>
int Stack<T>::getLength() const
{
return this->length;
}


//returns the top of the stack and then decrements length
template <class T>
T Stack<T>::pop()
{
	if (this->length == -1)
	{
		std::cout << "Error, stack is empty" << std::endl;
		return 0;
	}
	else
	{
		return this->arr[this->length--];
	}
}

//returns the top of the array
template <class T>
T Stack<T>::top() const
{
	return this->arr[length];
}

//checks if the stack is empty
template <class T>
bool Stack<T>::isEmpty()const
{
	if (this->length == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}