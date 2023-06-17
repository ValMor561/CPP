#include "pch.h"
#include "../Task2/GCD.h"

TEST(GCDTests, TwoThousendandNineIsSimple)
{
	ASSERT_EQ(1, GCDRecurs(2000, 9));
	ASSERT_EQ(1, GCDUnRecurs(2000, 9));
}

TEST(GCDTests, GCDEigtAndFourIsFour)
{
	ASSERT_EQ(4 , GCDRecurs(8, 4));
	ASSERT_EQ(4, GCDUnRecurs(8, 4));
}
TEST(GCDTests, GCDEigtAndFourIsMinusFour)
{
	ASSERT_EQ(4 , GCDRecurs(-8, -4));
	ASSERT_EQ(4, GCDUnRecurs(-8, -4));
}

TEST(GCDTests, GCDFourAndFourIsFour)
{
	ASSERT_EQ(4 , GCDRecurs(4, 4));
	ASSERT_EQ(4, GCDUnRecurs(4, 4));
}
TEST(GCDTests, GCDEightAndZeroIsZero)
{
	ASSERT_EQ(0 , GCDRecurs(8, 0));
	ASSERT_EQ(0, GCDUnRecurs(8, 0));
}
TEST(GCDTests, ThreeAndFiveIsSimple)
{
	ASSERT_EQ(1 , GCDRecurs(3, 5));
	ASSERT_EQ(1, GCDUnRecurs(3, 5));
}
