#include "pch.h"
#include "../Task13/Point.h"

TEST(PointTests, Test1)
{
	Point a;
	ASSERT_DOUBLE_EQ(0, a.GetX());
	ASSERT_DOUBLE_EQ(0, a.GetY());
	ASSERT_DOUBLE_EQ(0, a.GetZ());
}


TEST(PointTests, Test2)
{
	Point a(1,5,2.6);
	ASSERT_DOUBLE_EQ(1, a.GetX());
	ASSERT_DOUBLE_EQ(5, a.GetY());
	ASSERT_DOUBLE_EQ(2.6, a.GetZ());
}

TEST(PointTests, Test3)
{
	Point a(1, 5, 2.6);

	Point b(a);

	ASSERT_TRUE(a == b);
}

TEST(PointTests, Test4)
{
	Point a(1, 5, 2.6);

	Point b;

	b = a;

	ASSERT_TRUE(a == b);
}