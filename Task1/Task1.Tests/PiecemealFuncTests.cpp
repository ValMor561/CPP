#include "pch.h"
#include "../Task1/PiecemealFunc.h"

TEST(Task3Tests, Test1)
{
	ASSERT_DOUBLE_EQ(f(12), 0);
}
TEST(Task3Tests, Test2)
{
	ASSERT_DOUBLE_EQ(f(-6), -1);
}
TEST(Task3Tests, Test3)
{
	ASSERT_DOUBLE_EQ(f(6), 3);
}
TEST(Task3Tests, Test4)
{
	ASSERT_DOUBLE_EQ(f(3), 0);
}
TEST(Task3Tests, Test5)
{
	ASSERT_DOUBLE_EQ(f(2), -2*sqrt(3));
}
TEST(Task3Tests, Test6)
{
	ASSERT_DOUBLE_EQ(f(-9), -3);
}
