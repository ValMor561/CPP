#include "pch.h"
#include "../Task1/Trigonometry.hpp"


TEST(Task1Tests, Test1)
{
	double z1 = Func1(3);
	double z2 = Func2(3);
	ASSERT_DOUBLE_EQ(z1, z2);
}
TEST(Task1Tests, Test2)
{
	double z1 = Func1(0);
	double z2 = Func2(0);
	ASSERT_DOUBLE_EQ(z1, z2);
}
TEST(Task1Tests, Test3)
{
	double z1 = Func1(90);
	double z2 = Func2(90);
	ASSERT_DOUBLE_EQ(z1, z2);
}
