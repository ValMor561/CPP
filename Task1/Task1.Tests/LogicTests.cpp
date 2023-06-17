#include "pch.h"
#include "../Task1/Logic.h"


TEST(Task2Tests, Test1)
{
	int count = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	while (count != 8)
	{
		bool z1 = Func1(a, b, c);
		bool z2 = Func2(a, b, c);
		ASSERT_EQ(z1, z2);
		++c;
		if (count % 2 != 0)
			++b;
		if (count == 3)
			a = 1;
		if (c == 2)
			c = 0;
		if (b == 2)
			b = 0;
		++count;
	}
}

