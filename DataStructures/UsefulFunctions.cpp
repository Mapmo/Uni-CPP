#include "UsefulFunctions.h"
unsigned int FindClosestPowerOf2toNumber(unsigned int repeat)
{
	repeat--;
	repeat |= repeat >> 1;
	repeat |= repeat >> 2;
	repeat |= repeat >> 4;
	repeat |= repeat >> 8;
	repeat |= repeat >> 16;
	repeat++;
	return repeat;
}

unsigned int ownStrlen(const char * rhs)
{
	unsigned int i = -1;
	while (rhs[++i] != '\0');
	return i;
}

int compare(const char * lhs, const char * rhs)
{
	int i = ownStrlen(lhs);//max length is 2^30 which can be handled by int
	if (i == ownStrlen(rhs))
	{
		while (--i > 0)
		{
			if (lhs[i] != rhs[i])
			{
				break;
			}
		}
		return (lhs[i] == rhs[i]) ? 1 : -1;
	}
	return -1;
}

char * subcharPtr(const char* ptr, unsigned int subpos, unsigned int sublen)
{
	try
	{
		const unsigned int ptrLen = ownStrlen(ptr);
		if (subpos > ptrLen)
		{
			throw std::out_of_range("pos of the string to compare is oor\n");
		}
		else
		{
			char * tmp = new char[sublen + 1];
			tmp[sublen] = '\0';
			int i = 0;
			while (i < sublen && i + subpos < ptrLen)
			{
				tmp[i] = ptr[i++ + subpos];
			}
			return tmp;
		}
	}
	catch (std::out_of_range & oor)
	{
		std::cerr << "std::out_of_range thrown " << oor.what();
		exit(1);
	}
}

void ownStrcpy(char * lhs, const char * rhs)
{
	try
	{
		int i = ownStrlen(rhs);
		if (i > ownStrlen(lhs))
		{
			throw std::out_of_range("not enough space for ownStrcpy\n");
		}
		while (--i >= 0)
		{
			lhs[i] = rhs[i];
		}
	}
	catch (std::out_of_range & oor)
	{
		std::cerr << "std::out_of_range thrown " << oor.what();
		exit(1);
	}
}

