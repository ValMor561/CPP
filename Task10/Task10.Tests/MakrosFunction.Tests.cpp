#include "pch.h"
#include "../Task10/MakrosFunction.h"

TEMPLATE_SORT_BY_BUBBLE(int);
TEMPLATE_SORT_BY_BUBBLE(double);

TEST(SortByBubbleTests,Test1)
{
	int arr[5] = { 9,3,5,10,7 };

	SortByBubble_int(arr, 5);

	int sortArr[5] = { 3,5,7,9,10 };

	for (int i = 0; i < 5; ++i)
	{
		ASSERT_EQ(sortArr[i], arr[i]);
	}
}

TEST(SortByBubbleTests, Test2)
{
	double arr[5] = { 9.2,3.1,5.7,10.1,7.3 };

	SortByBubble_double(arr, 5);

	double sortArr[5] = { 3.1,5.7,7.3,9.2,10.1 };

	for (int i = 0; i < 5; ++i)
	{
		ASSERT_DOUBLE_EQ(sortArr[i], arr[i]);
	}
}