#include "pch.h"
#include "../Task3/SumOfPozitiveBetweenMax.h"
TEST(SumOfPozitiveBetweenMax, OneToTenArr)
{
	double a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ASSERT_EQ(45, SumOfPozitiveBetweenMax(a, 10));
}
TEST(SumOfPozitiveBetweenMax, OneToTenArrButTenInMidle)
{
	double a[10] = { 1, 2, 3, 4, 5, 10, 7, 8, 9, 5 };
	ASSERT_EQ(15, SumOfPozitiveBetweenMax(a, 10));
}
TEST(SumOfPozitiveBetweenMax, SumOfPositiveIsNull)
{
	double a[10] = { -5, 8, -5, 0, -3, -4, -6, -7, -9, 2 };
	ASSERT_EQ(0, SumOfPozitiveBetweenMax(a, 10));
}
TEST(SumOfPozitiveBetweenMax, SumOfPositiveMix)
{
	double a[9] = { 5, 8, -5, 0, -3, -4, 6, -7, 9 };
	ASSERT_EQ(19, SumOfPozitiveBetweenMax(a, 9));
}
TEST(SumOfPozitiveBetweenMax, ZeroArr)
{
	double a[10] = { 0 };
	ASSERT_EQ(0, SumOfPozitiveBetweenMax(a, 9));
}