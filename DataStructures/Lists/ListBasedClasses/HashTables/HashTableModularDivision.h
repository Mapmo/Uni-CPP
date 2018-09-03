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

	//Split function
	unsigned int FindIndex(const keyType&)const;
public:
	//Essentials

	explicit HashTableModularDivision(const unsigned int);
	~HashTableModularDivision();

	void insert(const T&,const keyType&);
	const T& get(const keyType&);
	void erase(const keyType&);
private:
	const unsigned int m_Modul;
	LinkedList1<T, keyType> * m_Collisions;
};

template<class T, class keyType>
inline HashTableModularDivision<T, keyType>::HashTableModularDivision(const unsigned int numb) : m_Modul(numb), m_Collisions(new LinkedList1<T, keyType>[numb])
{
}

template<class T, class keyType>
inline HashTableModularDivision<T, keyType>::~HashTableModularDivision()
{
	delete[] this->m_Collisions;
}

template<class T, class keyType>
inline void HashTableModularDivision<T, keyType>::insert(const T& val, const keyType& key)
{
	LinkedList1<T, keyType> tmp(val, key);
	this->m_Collisions[FindIndex(key)].push_back(tmp);
}

template<class T, class keyType>
inline const T & HashTableModularDivision<T, keyType>::get(const keyType& key)
{
	return this->m_Collisions[FindIndex(key)].at(key);
}

template<class T, class keyType>
inline void HashTableModularDivision<T, keyType>::erase(const keyType & key)
{
	unsigned int i = FindIndex(key);
	if (this->m_Collisions[i].empty() && this->m_Collisions[i].Key() == key)
	{
		this->m_Collisions[i].Key() = keyType();
		return;
	}
	this->m_Collisions[i].erase(key);
}

template<class T, class keyType>
inline unsigned int HashTableModularDivision<T, keyType>::FindIndex(const keyType & key) const
{
	std::string x;//templates are evil, this is the only way to make the code run without compile time errors caused by the difference between the classes
	x += key;
	unsigned int counter = 0;
	for (unsigned int i = 0; i < x.size(); ++i)
		counter += x[i];
	return counter%this->m_Modul;
}
