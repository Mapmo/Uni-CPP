#include "String2.h"

void String2::ValidatePos(int & numb) const
{
	if (numb == -1)
	{
		numb = this->m_Counter - 1;
	}
}

String2::String2() :Vector<char>()
{
}

String2::String2(const int numb, const char val) : Vector<char>(numb, val)
{
}

String2::String2(const char * rhs)
{
	unsigned rhsLen = ownStrlen(rhs);
	this->m_Counter = rhsLen;
	CalculateMaxSize();
	ConstructorAlloc();
	ownStrcpy(this->m_Data, rhs);
	this->m_Data[m_Counter] = '\0';
}

String2::String2(const String2 & rhs) : Vector<char>(rhs)
{
}

String2 & String2::append(const String2 & rhs)
{
	return append(rhs.data(), rhs.size());
}

String2 & String2::append(const String2 & rhs, const unsigned int subpos, const unsigned int sublen)
{
	if (subpos > rhs.size())
	{
		std::cerr << "append out of range\n";
	}
	else
	{
		char * tmp = new char[sublen + 1];
		unsigned int i = 0;
		while (i < sublen && i < rhs.size())
		{
			tmp[i] = rhs[subpos + i];
			++i;
		}
		if (i == sublen)
		{
			tmp[sublen] = '\0';
		}
		else
		{
			tmp[i--] = '\0';
		}
		append(tmp, i);
		delete[] tmp;
	}

	return *this;
}

String2 & String2::append(const char* rhs)
{
	return append(rhs, ownStrlen(rhs));
}

String2 & String2::append(const char * rhs, const unsigned int numb)
{
	this->m_Counter += numb;
	while (this->m_Counter >= this->m_Size)
	{
		if (!Resize(1))
		{
			std::cerr << "append operation failed, due to unavailable space\n";
			this->m_Counter -= ownStrlen(rhs);
			return *this;
		}
	}

	for (unsigned int i = 0; i < numb; ++i)
	{
		this->m_Data[i + m_Counter - numb] = rhs[i];
	}
	this->m_Data[m_Counter] = '\0';
	return *this;
}

String2 & String2::append(const unsigned int numb, const char val)
{
	char * tmp = new char[numb];
	for (int i = 0; i < numb; ++i)
	{
		tmp[i] = val;
	}
	append(tmp, numb);
	delete[] tmp;
	return *this;
}

String2 & String2::operator+=(const String2 & rhs)
{
	return append(rhs);
}

String2 & String2::operator+=(const char * rhs)
{
	return append(rhs);
}

String2 & String2::operator+=(const char rhs)
{
	return append(1, rhs);
}

const char * String2::c_str() const
{
	return this->m_Data;
}

int String2::compare(const String2 & rhs) const noexcept
{
	return (*this == rhs) ? 1 : -1;
}

int String2::compare(const unsigned int pos, const unsigned int len, const String2 & str) const
{
	return compare(pos, len, str.c_str());
}

int String2::compare(const unsigned int pos, const unsigned int len, const String2 & str, const unsigned int subpos, const unsigned int sublen) const
{
	if (len != sublen)//a simple check that can save a lot of time and memory, too simple and short for a separate function
	{
		return -1;
	}
	char * tmp = subcharPtr(str.c_str(), subpos, sublen);
	int	i = compare(pos, len, tmp);
	delete[] tmp;
	return i;
}

int String2::compare(const char * s) const
{
	return ::compare(c_str(), s);//in UsefulFunctions.h
}

int String2::compare(const unsigned int pos, const unsigned int len, const char * ptr) const
{
	if (len != ownStrlen(ptr))//a simple check that can save a lot of time and memory, too simple and short for a separate function
	{
		return -1;
	}
	char * tmp = subcharPtr(c_str(), pos, len);
	int i = ::compare(tmp, ptr);
	delete[]tmp;
	return i;
}

bool String2::operator==(const char * rhs)
{
	if (this->m_Data == rhs)
	{
		return true;
	}
	if (this->m_Counter == ownStrlen(rhs))
	{
		int i = 0;
		while (i != this->m_Counter)
		{
			if (this->m_Data[i] != rhs[i++])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool String2::operator!=(const char * rhs)
{
	return !operator==(rhs);
}

int String2::compare(const unsigned int pos, const unsigned int len, const char * ptr, const unsigned int n) const
{
	if (len != n)//a simple check that can save a lot of time and memory, too simple and short for a separate function
	{
		return -1;
	}
	char * tmp = subcharPtr(c_str(), pos, len);
	char * tmp2 = subcharPtr(ptr, 0, n);
	int i = ::compare(tmp, tmp2);
	delete[] tmp;
	delete[] tmp2;
	return i;
}

unsigned int String2::copy(char* ptr, const unsigned int pos, const unsigned int len) const
{
	char * tmp = subcharPtr(c_str(), pos, len);
	ownStrcpy(ptr, tmp);
	delete[]tmp;
	return len;
}

int String2::find(const String2 & str, const unsigned int pos) const noexcept
{
	return find(str.c_str(), pos, this->m_Counter - pos);
}

int String2::find(const char * ptr, const unsigned int pos) const
{
	return find(ptr, pos, this->m_Counter - pos);
}

int String2::find(const char * ptr, const unsigned int pos, const unsigned int numb) const
{
	unsigned int i = pos;
	unsigned int ptrLen = ownStrlen(ptr);
	bool match;
	while (i < this->m_Counter - ptrLen && i < pos + numb)
	{
		match = true;
		for (int j = 0; j < ptrLen; ++j)
		{
			if (ptr[j] != this->m_Data[i + j])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			return i;
		}
		++i;
	}
	return -1;
}

int String2::find(char c, const unsigned int pos) const noexcept
{
	for (unsigned int i = pos; i < this->m_Counter; ++i)
	{
		if (this->m_Data[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int String2::rfind(const String2 & str, int pos) const noexcept
{
	ValidatePos(pos);
	return rfind(str.c_str(), pos, pos + 1);
}

int String2::rfind(const char * ptr, int pos) const
{
	ValidatePos(pos);
	return rfind(ptr, pos, pos + 1);
}

int String2::rfind(const char * ptr, const int pos, const unsigned int numb) const
{
	int i = (pos >= this->m_Counter) ? this->m_Counter - 1 : pos;
	unsigned int ptrLen = ownStrlen(ptr);
	bool match;
	unsigned int numbCounter = 0;
	while (i >= ptrLen && (numbCounter++ + ptrLen - 1) != numb)
	{
		match = true;
		for (unsigned int j = ptrLen; j > 0; --j)
		{
			if (ptr[j - 1] != this->m_Data[i + j - ptrLen])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			return i - ptrLen + 1;
		}
		else
		{
			--i;
		}
	}
	return -1;
}

int String2::rfind(char c, int pos) const noexcept
{
	ValidatePos(pos);
	if (pos < this->m_Counter)
	{
		for (unsigned int i = pos; i >= 0; --i)
		{
			if (this->m_Data[i] == c)
			{
				return i;
			}
		}
	}
	return -1;
}

int String2::find_first_of(const String2 & str, const unsigned int pos) const noexcept
{
	return find_first_of(str.c_str(), pos, this->m_Counter - pos);
}

int String2::find_first_of(const char * ptr, const unsigned int pos) const
{
	return find_first_of(ptr, pos, this->m_Counter - pos);
}

int String2::find_first_of(const char * ptr, const unsigned int pos, const unsigned int numb) const
{
	unsigned int i = pos;
	unsigned int ptrLen = ownStrlen(ptr);
	while (i < this->m_Counter - ptrLen && i < pos + numb)
	{
		for (int j = 0; j < ptrLen; ++j)
		{
			if (ptr[j] == this->m_Data[i])
			{
				return i;
			}
		}
		++i;
	}
	return -1;
}

int String2::find_first_of(const char c, const unsigned int pos) const noexcept
{
	return find(c, pos);
}

int String2::find_last_of(const String2 & str, int pos) const noexcept
{
	ValidatePos(pos);
	return find_last_of(str.c_str(), pos, pos + 1);
}

int String2::find_last_of(const char * ptr, int pos) const
{
	ValidatePos(pos);
	return find_last_of(ptr, pos, pos + 1);
}

int String2::find_last_of(const char * ptr, const int pos, const unsigned int numb) const
{
	int i = (pos >= this->m_Counter) ? this->m_Counter - 1 : pos;
	unsigned int ptrLen = ownStrlen(ptr);
	bool match;
	unsigned int numbCounter = 0;
	while (i >= ptrLen && (numbCounter++ + ptrLen - 1) != numb)
	{
		for (unsigned int j = ptrLen; j > 0; --j)
		{
			if (ptr[j - 1] == this->m_Data[i])
			{
				return i - ptrLen + 1;
			}
		}
		--i;
	}
	return -1;
}

int String2::find_last_of(const char c, int pos) const noexcept
{
	ValidatePos(pos);
	return rfind(c, pos);
}

int String2::find_first_not_of(const String2 & str, const unsigned int pos) const noexcept
{
	return 	find_first_not_of(str.c_str(), pos, this->m_Counter - pos);
}

int String2::find_first_not_of(const char * ptr, const unsigned int pos) const
{
	return 	find_first_not_of(ptr, pos, this->m_Counter - pos);
}

int String2::find_first_not_of(const char * ptr, const unsigned int pos, const unsigned int numb) const
{
	unsigned int i = pos;
	unsigned int ptrLen = ownStrlen(ptr);
	while (i < this->m_Counter - ptrLen && i < pos + numb)
	{
		for (int j = 0; j < ptrLen; ++j)
		{
			if (ptr[j] != this->m_Data[i])
			{
				return i;
			}
		}
		++i;
	}
	return -1;
}

int String2::find_first_not_of(const char c, const unsigned int pos) const noexcept
{
	for (unsigned int i = pos; i < this->m_Counter; ++i)
	{
		if (this->m_Data[i] != c)
		{
			return i;
		}
	}
	return -1;
}

int String2::find_last_not_of(const String2 & str, int pos) const noexcept
{
	ValidatePos(pos);
	return find_last_not_of(str.c_str(), pos, pos + 1);
}

int String2::find_last_not_of(const char * ptr, int pos) const
{
	ValidatePos(pos);
	return find_last_not_of(ptr, pos, pos + 1);
}

int String2::find_last_not_of(const char * ptr, const int pos, const unsigned int numb) const
{
	int i = (pos >= this->m_Counter) ? this->m_Counter - 1 : pos;
	unsigned int ptrLen = ownStrlen(ptr);
	bool match;
	unsigned int numbCounter = 0;
	while (i >= ptrLen && (numbCounter++ + ptrLen - 1) != numb)
	{
		for (unsigned int j = ptrLen; j > 0; --j)
		{
			if (ptr[j - 1] != this->m_Data[i])
			{
				return i - ptrLen + 1;
			}
		}
		--i;
	}
	return -1;
}

int String2::find_last_not_of(const char c, int pos) const noexcept
{
	ValidatePos(pos);
	if (pos < this->m_Counter)
	{
		for (unsigned int i = pos; i >= 0; --i)
		{
			if (this->m_Data[i] != c)
			{
				return i;
			}
		}
	}
	return -1;
}

String2 String2::substr(const int pos, int len) const
{
	if (len == -1)
	{
		len = this->m_Counter;
	}
	return String2(subcharPtr(this->m_Data, pos, len));
}

std::ostream& operator<<(std::ostream& str, const String2& rhs)
{
	str << rhs.c_str();
	return str;
}


std::istream& operator>>(std::istream& str, String2& rhs)
{
	char ch;
	rhs.clear();
	str >> ch;
	str.clear();
	rhs += ch;
	while (str.get(ch) && ch != '\n')
	{
		rhs += ch;
	}
	return str;
}
