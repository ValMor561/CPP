#include "pch.h"
#include "../Task2/Log.h"

TEST(LogTests, PowFourIstwo)
{
	ASSERT_EQ(2 , Logarifm(4));
}
TEST(LogTests, ZeroNotInScopeFunc)
{
	ASSERT_EQ(-2 , Logarifm(0));
}
TEST(LogTests, MinusHungredNotInScopeFunc)
{
	ASSERT_EQ(-2 , Logarifm(-100));
}
TEST(LogTests, PowOneThousandTwentyFourIsTen)
{
	ASSERT_EQ(10 , Logarifm(1024));
}
TEST(LogTests, NineIsNotPowOfTwo)
{
	ASSERT_EQ(-1 , Logarifm(9));
}
