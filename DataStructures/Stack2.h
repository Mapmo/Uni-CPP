#pragma once
#include "Vector.h"

template <class T, class Container = Vector<T>>
class Stack2
{
	T& topOverloadHelper();
public:
	//Element access

	T & top();
	const T& top()const;


	//Capacity

	bool empty() const;
	unsigned int size() const;


	//Modifiers
	
	void push(T&&);
	void pop();
	void swap(Stack2& other) noexcept;


	//Non-member functions
	template< class T1, class Container1 >
	friend bool operator==(const Stack2<T1, Container1>& lhs, const Stack2<T1, Container1>& rhs);

	template< class T2, class Container2 >
	friend bool operator!=(const Stack2<T2, Container2>& lhs, const Stack2<T2, Container2>& rhs);

private:
	Container m_Container;
};

template<class T, class Container>
inline T & Stack2<T, Container>::topOverloadHelper()
{
	return this->m_Container.back();
}

template<class T, class Container>
inline T & Stack2<T, Container>::top()
{
	return topOverloadHelper();
}

template<class T, class Container>
inline const T & Stack2<T, Container>::top() const
{
	return topOverloadHelper()
}

template<class T, class Container>
inline bool Stack2<T, Container>::empty() const
{
	return m_Container.empty();
}

template<class T, class Container>
inline unsigned int Stack2<T, Container>::size() const
{
	return m_Container.size();
}

template<class T, class Container>
inline void Stack2<T, Container>::push(T && val)
{
	this->m_Container.push_back(val);
}

template<class T, class Container>
inline void Stack2<T, Container>::pop()
{
	this->m_Container.pop_back();
}

template<class T, class Container>
inline void Stack2<T, Container>::swap(Stack2 & other) noexcept
{
	Container tmp = this->m_Container;
	this->m_Container = other.m_Container;
	other.m_Container = tmp;
}

template<class T1, class Container1>
inline bool operator==(const Stack2<T1, Container1>& lhs, const Stack2<T1, Container1>& rhs)
{
	return lhs.m_Container == rhs.m_Container;
}

template<class T2, class Container2>
inline bool operator!=(const Stack2<T2, Container2>& lhs, const Stack2<T2, Container2>& rhs)
{
	return !operator==(lhs,rhs);
}
