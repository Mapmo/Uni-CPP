#pragma once
#include "Vector.h"
class String2 :public Vector<char>
{
	void ValidatePos(int&)const;//used for the rfind functions instead of npos
public:
	String2();
	String2(const int, const char);
	explicit String2(const char*);
	String2(const String2&);


	//Modifiers

	String2& append(const String2&);
	String2& append(const String2&, const unsigned int, const unsigned int);
	String2& append(const char*);
	String2& append(const char*, const unsigned int);
	String2& append(const unsigned int, const char);
	String2& operator+=(const String2&);
	String2& operator+=(const char*);
	String2& operator+=(const char);


	//String operations

	const char* c_str() const;
	
	//calls subcharPtr() to create 2 new cjar* and then calls the function with 2 const char* that is in UsefulFunctions.h
	int compare(const unsigned int pos, const unsigned int len, const char* s, const unsigned int n) const;
	unsigned int copy(char *, const unsigned int, const unsigned int)const;
	int find(const String2&, const unsigned int = 0) const noexcept;
	int find(const char*, const unsigned int = 0) const;
	int find(const char*, const unsigned int, const unsigned int) const;
	int find(char, const unsigned int= 0) const noexcept;
	int rfind(const String2&, int = -1) const noexcept;
	int rfind(const char*, int = -1) const;
	int rfind(const char*, const int, const unsigned int) const;
	int rfind(char, int = -1) const noexcept;
	int find_first_of(const String2&, const unsigned int = 0) const noexcept;
	int find_first_of(const char*, const unsigned int = 0) const;
	int find_first_of(const char*, const unsigned int, const unsigned int) const;
	int find_first_of(const char , const unsigned int= 0) const noexcept;
	int find_last_of(const String2&, int = -1) const noexcept;
	int find_last_of(const char*, int = -1) const;
	int find_last_of(const char*, const int, const unsigned int) const;
	int find_last_of(const char, int = -1) const noexcept;
	int find_first_not_of(const String2&, const unsigned int= 0) const noexcept;
	int find_first_not_of(const char*, const unsigned int = 0) const;
	int find_first_not_of(const char*, const unsigned int, const unsigned int) const;
	int find_first_not_of(const char, const unsigned int = 0) const noexcept;
	int find_last_not_of(const String2& str, int pos = -1) const noexcept;
	int find_last_not_of(const char* s, int pos = -1) const;
	int find_last_not_of(const char* s, const int pos, const unsigned int n) const;
	int find_last_not_of(const char, int = -1) const noexcept;
	 String2 substr(const int pos = 0, int len = -1) const;
	 int compare(const String2&)const noexcept;//too simple therefore independent from the other compare functions

	 //calls the compare function with substring and const char*, not using substr, because creating new objects is slow and unnecessary
	 int compare(const unsigned int, const unsigned int, const String2&) const;

	 //validates and converts the 2nd substring to char* and calls the compare function with substring and const char*
	 int compare(const unsigned int, const unsigned int, const String2&, const unsigned int, const unsigned int) const;
	 int compare(const char*) const;//calls the function with 2 const char* that is in UsefulFunctions.h
	 int compare(const unsigned int, const unsigned int, const char*) const;//calls the function with 2 const char* that is in UsefulFunctions.h
	 bool operator==(const char*);
};

std::istream& operator>>(std::istream&, String2&);
std::ostream& operator<<(std::ostream&, const String2&);