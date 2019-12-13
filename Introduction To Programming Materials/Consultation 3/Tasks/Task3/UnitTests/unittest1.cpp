#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Task3/Task3.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			point x1 = { 1,7 };
			point y1 = { 1,9 };

			point x2 = { 1,6 };
			point y2 = { 1,5 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod2)
		{
			point x1 = { 1,7 };
			point y1 = { 1,1 };

			point x2 = { 1,6 };
			point y2 = { 1,5 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(1.0, foo(line1, line2));
			Assert::AreEqual(1.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod3)
		{
			point x1 = { 1,7 };
			point y1 = { 1,9 };

			point x2 = { 1,16 };
			point y2 = { 1,5 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(2.0, foo(line1, line2));
			Assert::AreEqual(2.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}

		TEST_METHOD(TestMethod4)
		{
			point x1 = { 7,7 };
			point y1 = { 7,9 };

			point x2 = { -7,7 };
			point y2 = { -7,7 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod5)
		{
			point x1 = { 1,7 };
			point y1 = { 1,9 };

			point x2 = { 1,16 };
			point y2 = { 1,-15 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };
			Assert::AreEqual(2.0, foo(line1, line2));
			Assert::AreEqual(2.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod6)
		{
			point x1 = { 1,7 };
			point y1 = { 1,-19 };
			point x2 = { 1,16 };
			point y2 = { 1,-15 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(22.0, foo(line1, line2));
			Assert::AreEqual(22.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod7)
		{
			point x1 = { 1,7 };
			point y1 = { 1,-19 };
			point x2 = { 1,6 };
			point y2 = { 1,-15 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(21.0, foo(line1, line2));
			Assert::AreEqual(21.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod8)
		{
			point x1 = { 1,0 };
			point y1 = { 1,0 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod9)
		{
			point x1 = { 11,0 };
			point y1 = { 1,0 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(9.0, foo(line1, line2));
			Assert::AreEqual(9.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod10)
		{
			point x1 = { 11,0 };
			point y1 = { 1,10 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod11)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod12)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,10 };
			point y2 = { 1,0 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod13)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,10 };
			point y2 = { 11,10 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(1.0, foo(line1, line2));
			Assert::AreEqual(1.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod14)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,10 };
			point y2 = { 5,10 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line2 = { x2,y2 };
			line line1 = { x1,y1 };
			Assert::AreEqual(5.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod15)
		{
			point x1 = { 6,10 };
			point y1 = { 8,10 };

			point x2 = { 10,10 };
			point y2 = { 5,10 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(2.0, foo(line1, line2));
			Assert::AreEqual(2.0, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod16)
		{
			point x1 = { 6.5,10 };
			point y1 = { 8,10 };

			point x2 = { 10,10 };
			point y2 = { 5,10 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(1.50, foo(line1, line2));
			Assert::AreEqual(1.50, foo(line2, line1));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod17)
		{
			point x1 = { 6.5,10 };
			point y1 = { 8,10 };

			point x2 = { 10,10 };
			point y2 = { 6.52,10 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			std::string a = "1.480000";
			std::string b = std::to_string(foo(line1, line2));
			std::string c = std::to_string(foo(line2, line1));
			Assert::AreEqual(a, b);
			Assert::AreEqual(a, c);

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
		TEST_METHOD(TestMethod18)
		{
			point x1 = { 10,10 };
			point y1 = { 10,10 };

			point x2 = { 10,10 };
			point y2 = { 10,10 };

			double tmpX1X = x1.x, tmpX2X = x2.x, tmpY1X = y1.x, tmpY2X = y2.x;
			double tmpX1Y = x1.y, tmpX2Y = x2.y, tmpY1Y = y1.y, tmpY2Y = y2.y;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line1, line1));
			Assert::AreEqual(0.0, foo(line2, line2));

			Assert::AreEqual(x1.x, tmpX1X);
			Assert::AreEqual(x2.x, tmpX2X);
			Assert::AreEqual(y1.x, tmpY1X);
			Assert::AreEqual(y2.x, tmpY2X);
			Assert::AreEqual(x1.y, tmpX1Y);
			Assert::AreEqual(x2.y, tmpX2Y);
			Assert::AreEqual(y1.y, tmpY1Y);
			Assert::AreEqual(y2.y, tmpY2Y);
		}
	};
}