#include "pch.h"
#include "../Task4/ShortestsGroup.h"



TEST(ShortestGroupTests, TestWithNullStr)
{
	const char* str = nullptr;
	ASSERT_STREQ(ShortestGroup(str), nullptr);
}

TEST(ShortestGroupTests, TestWithLastGroup)
{
	const char* str = "1101  001 10 1";
	ASSERT_STREQ(ShortestGroup(str), "1");
}

TEST(ShortestGroupTests, TestWithSpaceInBegin)
{
	const char* str = "  1101  001 10 1";
	ASSERT_STREQ(ShortestGroup(str), "1");
}
TEST(ShortestGroupTests, TestWithAllSimbolsAreNumber)
{
	const char* str = "  0  1 1 1";
	ASSERT_STREQ(ShortestGroup(str), "0");
}