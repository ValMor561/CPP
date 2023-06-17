#include "pch.h"
#include "../Task1/TargetFunc.h"


TEST(Task4Tests, Test1)
{
	ASSERT_FALSE(Target(3, 3, 4));
}
TEST(Task4Tests, Test2)
{
	ASSERT_FALSE(Target(-2, -3, 4));
}
TEST(Task4Tests, Test3)
{
	ASSERT_TRUE(Target(2, -1, 4));
}
TEST(Task4Tests, Test4)
{
	ASSERT_TRUE(Target(-2, 3, 4));
}