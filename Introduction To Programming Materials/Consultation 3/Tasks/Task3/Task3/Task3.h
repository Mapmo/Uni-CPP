#pragma once
#include <math.h>
struct point
{
	double x;
	double y;
};

struct line
{
	point beg;
	point end;
	double length()const;
};

double line::length()const
{
	double xDistance = (beg.x - end.x) * (beg.x - end.x);
	double yDistance = (beg.y - end.y) * (beg.y - end.y);

	return sqrt(xDistance + yDistance);//may armyanov not kill me
}

void swap_if_Y(line& a)
{
	if (a.beg.y < a.end.y)
	{
		double c = a.beg.y;
		a.beg.y = a.end.y;
		a.end.y = c;
	}
}

void swap_if_X(line& a)
{
	if (a.beg.x > a.end.x)
	{
		double c = a.beg.x;
		a.beg.x = a.end.x;
		a.end.x = c;
	}
}

double FindLengthOfVertical(const line& a, const line& b)//a::begin must be higher than b::begin
{
	if (a.end.y > b.beg.y)
	{
		return false;
	}
	if (a.end.y <= b.end.y)
	{
		return b.length();
	}
	line tmp = { b.beg, a.end };
	return tmp.length();
}

double FindLengthOfHorizontal(const line& a, const line& b) //a::begin must be lower than b::begin
{
	if (a.end.x < b.beg.x)
	{
		return false;
	}
	if (a.end.x >= b.end.x)
	{
		return b.length();
	}
	line tmp = { b.beg, a.end };
	return tmp.length();
}

double foo(line line1, line line2)
{
	if (line1.beg.x == line1.end.x && line2.beg.x == line2.end.x && line1.beg.x == line2.beg.x)//if true then they are -|- 
	{
		//now will invert the lines so line.beg is the higher point
		swap_if_Y(line1);
		swap_if_Y(line2);

		//now we make some tests
		if (line1.beg.y > line2.beg.y)
		{
			return FindLengthOfVertical(line1, line2);
		}
		else
		{
			return FindLengthOfVertical(line2, line1);
		}
	}
	else if (line1.beg.y == line1.end.y && line2.beg.y == line2.end.y && line1.beg.y == line2.beg.y)//------
	{
		//now will invert the lines so line.beg is the higher point
		swap_if_X(line1);
		swap_if_X(line2);

		//now we make some tests
		if (line1.beg.x < line2.beg.x)//line1 is lefter
		{
			return FindLengthOfHorizontal(line1, line2);
		}
		else//line2 is first
		{
			return FindLengthOfHorizontal(line2, line1);
		}
	}
	const double NONE = -1.0;
	return NONE;
}