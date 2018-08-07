#include "String.h"
#include <cstring>
#include <iostream>

String::String()
{
	m_Size = 0;
	m_String = new char[m_Size + 1];
	m_String[0] = '\0';
}
String::String(const char* rhs)
{
	m_Size = strlen(rhs);
	m_String = new char[m_Size + 1];
	strcpy(m_String, rhs);
}
String::String(const String& rhs)
{
	m_Size = rhs.m_Size;
	m_String = new char[m_Size + 1];
	strcpy(m_String, rhs.m_String);
}
String::~String()
{
	delete[] m_String;
}



String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		delete[] m_String;
		m_Size = rhs.m_Size;
		m_String = new char[m_Size + 1];
		strcpy(m_String, rhs.m_String);
	}
	return *this;
}

String& String::operator=(const char* rhs)
{
	String a = String(rhs);
	this->operator=(a);
	return *this;
}

String& String::operator+=(const String& rhs)
{
	this->append(rhs);
	return *this;
}

String& String::operator+=(const char* rhs)
{
	this->append(rhs);
	return *this;
}

String String::operator+(const String& rhs)const
{
	this->concat(rhs);
	return *this;
}

String String::operator+(const char* rhs)const
{
	this->concat(rhs);
	return *this;
}

//not in the String scope
String operator + (const char* lhs, const String& rhs)
{
	return rhs.concat(lhs);
}

bool String::operator==(const String&rhs)const
{
	if (this != &rhs)
	{
		for (int i = 0; i < this->m_Size; i++)
		{
			if (this->m_String[i] != rhs.m_String[i])
				return false;
		}
	}
	return true;
}

bool String::operator==(const char* rhs)const
{
	String a = rhs;
	return this->operator==(a);
}

bool operator==(const char* lhs, const String& rhs)
{
	return rhs.operator==(lhs);
}

bool operator!=(const char*lhs, const String& rhs)
{
	return rhs.operator!=(lhs);
}

bool String::operator!=(const String& rhs)const
{
	return !(this->operator==(rhs));
}
bool String::operator!=(const char* rhs)const
{
	String a = rhs;
	return !(this->operator==(a));
}
char String::operator[](int rhs)const
{
	return this->m_String[rhs];
}

std::ostream& operator<<(std::ostream& str, const String& rhs)
{
	str << rhs.getCString();
	return str;
}


std::istream& operator>>(std::istream& str, String& rhs)
{
	rhs = "";
	char ch;
	str >> ch;
	str.clear();
	rhs.append(ch);
	while (str.get(ch) && ch != '\n')
	{
		rhs.append(ch);
	}
	return str;
}

bool String::empty()const
{
	return m_Size||m_String[m_Size]!='\0';
}

const char* String::getCString() const
{
	return m_String;
}

unsigned int String::getSize() const
{
	return m_Size;
}

void String::setString(const char* rhs)
{
	delete[] m_String;
	m_Size = strlen(rhs);
	m_String = new char[m_Size + 1];
	strcpy(m_String, rhs);
}



void String::append(const char* rhs)
{
	int newSize = m_Size + strlen(rhs);
	char* oldString = m_String;
	m_String = new char[newSize + 1];
	strcpy(m_String, oldString);
	delete[] oldString;
	strcpy(m_String + m_Size, rhs);
	m_Size = newSize;
}

void String::append(const String& rhs)
{
	append(rhs.m_String);
}

void String::append(const char rhs)
{
	char* a = new char[2];
	a[0] = rhs;
	a[1] = '\0';
	this->append(a);
	delete[] a;
}

String String::concat(const String& rhs) const
{
	String newString(*this);
	newString.append(rhs);
	return newString;
}
String String::concat(const char* rhs) const
{
	String newString(*this);
	newString.append(rhs);
	return newString;
}




