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
		int c = a.beg.y;
		a.beg.y = a.end.y;
		a.end.y = c;
	}
}

void swap_if_X(line& a)
{
	if (a.beg.x > a.end.x)
	{
		int c = a.beg.x;
		a.beg.x = a.end.x;
		a.end.x = c;
	}
}

double foo(line line1, line line2)
{
	const double NONE = -1.0;
	if (line1.beg.x == line1.end.x && line2.beg.x == line2.end.x && line1.beg.x == line2.beg.x)//if true then they are -|- 
	{
		//now will invert the lines so line.beg is the higher point
		swap_if_Y(line1);
		swap_if_Y(line2);

		//now we make some tests
		if (line1.beg.y > line2.beg.y)
		{
			if (line1.end.y > line2.beg.y)
			{
				return NONE;
			}
			if (line1.end.y <= line2.end.y)
			{
				return line2.length();
			}
			line tmp = { line2.beg, line1.end };
			return tmp.length();
		}
		else
		{
			if (line2.end.y > line1.beg.y)
			{
				return NONE;
			}
			if (line2.end.y <= line1.end.y)
			{
				return line1.length();
			}
			line tmp = { line1.beg, line2.end };
			return tmp.length();
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
			if (line1.end.x < line2.beg.x)
			{
				return NONE;
			}
			if (line1.end.x >= line2.end.x)
			{
				return line2.length();
			}
			line tmp = { line2.beg, line1.end };
			return tmp.length();
		}
		else//line2 is first
		{
			if (line2.end.x < line1.beg.x)
			{
				return NONE;
			}
			if (line2.end.x >= line1.end.x)
			{
				return line1.length();
			}
			line tmp = { line1.beg, line2.end };
			return tmp.length();
		}
	}
	return NONE;
}