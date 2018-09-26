#pragma once

//during my implementation process I noticed an interesting concept with some of the member-functions and how they were implemented:
template<class T>
class A
{
	T& dataOverloadHelper()const;
public:
	T & data();
	const T& data()const;
	//what happens here and why this is great
private:
	T m_a;
};

/*
To review the overload resolution process, first, both are listed as "candidate" functions as they are in the correct scope and have the correct name.

In the const case, only the const member function gets to the next step (called "viability"), so it's automatically the best choice. The non-const member function is not viable because you can't convert a const reference into a non-const reference.

In the non-const case, both the const and non-const versions are viable, but the non-const one is "better" because of the fifth rule of 13.3.3.2 paragraph 3, quoted below.

(The credits for this text should go to rmcclellan(stackoverflow nickname))
*/

/*
In general, I use an overloadHelperFunction() that does something like: */
template <class T>
T& A::dataOverloadHelper()const
{
	return this->m_a;
}
/*and that's all, the reason behind the 2 functions is that
if the object is non-constant I will get a normal reference to its data and I will be able to edit it, and when the object is constant, I will get a const
reference to its data and I will not be able to edit it.

Probable questions:
1)but the code inside the first function does not change the object, so it must have const in the end 
-Wrong, the overload helper function is const itself, and as it is the whole body of both functions, we can be sure that there won't be any changes to the members of the object

2)why not have 1 data() function that is like the overload helper function, it is const => so the object won't be changed
-Wrong, just because the function treats the object as const during its execution doesn't mean that we won't be able to change it after function is over,
because we will have a non-constant reference to its class-member
(stupid question, but it was actually asked)
*/