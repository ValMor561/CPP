#include "pch.h"
#include "../Task3/TransformationArray.h"

TEST(TransformationArray, FromZeroToNine)
{
	double a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	TransformationArray(a, 10);
	
	double b[10] = { 0 ,1 ,9 ,3 ,7 ,5 ,6 ,4 ,8 ,2 };
	
	for (int i = 0; i < 10; ++i)
	{
		ASSERT_DOUBLE_EQ(b[i], a[i]);
	}
}
TEST(TransformationArray, FromZeroToEight)
{
	double a[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	TransformationArray(a, 9);

	double b[9] = { 0, 1, 7, 3, 5, 4, 6, 2, 8 };
	
	for (int i = 0; i < 9; ++i)
	{
		ASSERT_DOUBLE_EQ(b[i], a[i]);
	}
}
