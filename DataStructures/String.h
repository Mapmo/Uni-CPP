#pragma once
#include <iostream>
class String
{
private:
	char* m_String;
	unsigned int m_Size;
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	//overloaded operators
	String& operator=(const String&);
	String& operator=(const char *);
	String& operator+=(const String&);
	String& operator+=(const char *);
	String operator+(const String&)const;	
	String operator+(const char*)const;
	friend String operator + (const char*, const String&);
	char operator[](const int)const;
	bool operator==(const String&)const;
	bool operator==(const char*)const;
	friend bool operator ==(const char*, const String&);
	bool operator!=(const String&)const;
	bool operator!=(const char*)const;
	friend bool operator !=(const char*, const String&);
	friend std::istream& operator>>(std::istream&, String&);
	friend std::ostream& operator<<(std::ostream&, const String&);

	bool empty()const;
	const char* getCString() const;
	unsigned int getSize() const;
	void setString(const char*);

	void append(const char*);
	void append(const char);
	void append(const String&);
	String concat(const String&) const;
	String concat(const char*) const;
};