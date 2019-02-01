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

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod2)
		{
			point x1 = { 1,7 };
			point y1 = { 1,1 };

			point x2 = { 1,6 };
			point y2 = { 1,5 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(1.0, foo(line1, line2));
			Assert::AreEqual(1.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod3)
		{
			point x1 = { 1,7 };
			point y1 = { 1,9 };

			point x2 = { 1,16 };
			point y2 = { 1,5 };
			
			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;
			
			line line1 = { x1,y1 };
			line line2 = { x2,y2 };
			
			Assert::AreEqual(2.0, foo(line1, line2));			
			Assert::AreEqual(2.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}

		TEST_METHOD(TestMethod4)
		{
			point x1 = { 7,7 };
			point y1 = { 7,9 };

			point x2 = { -7,7 };
			point y2 = { -7,7 };
			
			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;
			
			line line1 = { x1,y1 };
			line line2 = { x2,y2 };
			
			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod5)
		{
			point x1 = { 1,7 };
			point y1 = { 1,9 };

			point x2 = { 1,16 };
			point y2 = { 1,-15 };
			
			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };
			Assert::AreEqual(2.0, foo(line1, line2));
			Assert::AreEqual(2.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod6)
		{
			point x1 = { 1,7 };
			point y1 = { 1,-19 };
			point x2 = { 1,16 };
			point y2 = { 1,-15 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };
			
			Assert::AreEqual(22.0, foo(line1, line2));
			Assert::AreEqual(22.0, foo(line2, line1));
		}
		TEST_METHOD(TestMethod7)
		{
			point x1 = { 1,7 };
			point y1 = { 1,-19 };
			point x2 = { 1,6 };
			point y2 = { 1,-15 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(21.0, foo(line1, line2));
			Assert::AreEqual(21.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod8)
		{
			point x1 = { 1,0 };
			point y1 = { 1,0 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod9)
		{
			point x1 = { 11,0 };
			point y1 = { 1,0 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(9.0, foo(line1, line2));
			Assert::AreEqual(9.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod10)
		{
			point x1 = { 11,0 };
			point y1 = { 1,10 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod11)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,0 };
			point y2 = { 1,0 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod12)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,10 };
			point y2 = { 1,0 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(-1.0, foo(line1, line2));
			Assert::AreEqual(-1.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod13)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,10 };
			point y2 = { 11,10 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(1.0, foo(line1, line2));
			Assert::AreEqual(1.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod14)
		{
			point x1 = { 11,10 };
			point y1 = { 1,10 };

			point x2 = { 10,10 };
			point y2 = { 5,10 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line2 = { x2,y2 };
			line line1 = { x1,y1 };
			Assert::AreEqual(5.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod15)
		{
			point x1 = { 6,10 };
			point y1 = { 8,10 };

			point x2 = { 10,10 };
			point y2 = { 5,10 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(2.0, foo(line1, line2));
			Assert::AreEqual(2.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod16)
		{
			point x1 = { 6.5,10 };
			point y1 = { 8,10 };

			point x2 = { 10,10 };
			point y2 = { 5,10 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(1.50, foo(line1, line2));
			Assert::AreEqual(1.50, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod17)
		{
			point x1 = { 6.5,10 };
			point y1 = { 8,10 };

			point x2 = { 10,10 };
			point y2 = { 6.51,10 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line2, line1));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
		TEST_METHOD(TestMethod18)
		{
			point x1 = { 10,10 };
			point y1 = { 10,10 };

			point x2 = { 10,10 };
			point y2 = { 10,10 };

			point tmpX1 = x1, tmpX2 = x2, tmpY1 = y1, tmpY2 = y2;

			line line1 = { x1,y1 };
			line line2 = { x2,y2 };

			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line1, line2));
			Assert::AreEqual(0.0, foo(line1, line1));
			Assert::AreEqual(0.0, foo(line2, line2));

			Assert::AreEqual(x1, tmpX1);
			Assert::AreEqual(x1, tmpX2);
			Assert::AreEqual(y1, tmpY1);
			Assert::AreEqual(y2, tmpY2);
		}
	};
}