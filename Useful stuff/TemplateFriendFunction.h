#pragma once

//friend function in a template class requires a separate template declaration
template<class T>
class A
{
public:
	A(T a = 0) : m_a(a) {}

	template<class U>
	friend A<U> foo(A<U>& a);
	//if you use friend A<T> foo (A<T>&a); you will receive an unresolved external
private:
	T m_a;
};