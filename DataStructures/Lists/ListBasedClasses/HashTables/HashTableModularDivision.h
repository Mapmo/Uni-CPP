#pragma once
#include "..\..\LinkedLists\LinkedList1.h"

template <class T, class keyType>
class HashTableModularDivision
{
	static_assert(std::is_same<keyType, std::string>::value || (std::is_arithmetic<keyType>::value && !std::is_floating_point<keyType>::value),
		"Due to technical restrictions, this implementation can only have a key that is either std::string or an arithmetic integer data type\n");
	//not needed
	HashTableModularDivision(const HashTableModularDivision&) = delete;
	HashTableModularDivision& operator==(const HashTableModularDivision&) = delete;
public:
	//Essentials

	explicit HashTableModularDivision(const unsigned int);
	~HashTableModularDivision();
private:
	const unsigned int m_Modul;
	LinkedList1<T, keyType> * m_Collisions;
};

template<class T, class keyType>
inline HashTableModularDivision<T, keyType>::HashTableModularDivision(const unsigned int numb) : m_Modul(numb), m_Collisions(new LinkedList1<T, keyType> [numb])
{
}

template<class T, class keyType>
inline HashTableModularDivision<T, keyType>::~HashTableModularDivision()
{
	delete[] this->m_Collisions;
}
