#include "pch.h"
#include "../Task5/Convert.h"


TEST(ConvertToDoubleTests, Test1)
{
	const char* str = "0d27\0";
	ASSERT_EQ(2962, ConvertToDouble(str, 15));
}

// Почему ASSERT_NEAR? ASSERT_DOUBLE_EQ не срабатывает?
//Да
TEST(ConvertToDoubleTests, Test2)
{
	const char* str = "0d27.a17\0";
	ASSERT_NEAR(2962.67318, ConvertToDouble(str, 15), 1e-5);
}

TEST(ConvertToDoubleTests, Test3)
{
	const char* str = "0.0\0";
	ASSERT_NEAR(0, ConvertToDouble(str, 15), 1e-5);
}

TEST(ConvertToDoubleTests, Test4)
{
	const char* str = "-1ed7.0e7\0";
	ASSERT_NEAR(-6727.06429, ConvertToDouble(str, 15), 1e-5);
}

TEST(ConvertToDoubleTests, Test5)
{
	const char* str = "f21\0";
	ASSERT_EQ(-1, ConvertToDouble(str, 15));
}