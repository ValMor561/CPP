#include "pch.h"
#include "../Task9/SecondTask.h"
#include <string>

TEST(SecondTaskTests, Test1)
{
	ASSERT_EQ(5, Sum(2, 3));
}
TEST(SecondTaskTests, Test2)
{
	ASSERT_EQ(5, Sum(2.5, 3.2));
}

TEST(SecondTaskTests, Test3)
{
	std::string a = "2.5";
	std::string b = "5.5";
	std::string c = "2";
	ASSERT_EQ(10, Sum(a, b,c));
}

TEST(SecondTaskTests, Test4)
{
	const char* a = "2.5";
	const char* b = "5.5";
	const char* c = "2";
	ASSERT_EQ(10, Sum(a, b, c));
}