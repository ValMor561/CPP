#include "pch.h"
#include "../Task10/TemplateFunction.h"

TEST(ChangeArrTests, Test1)
{
	int arr[5] = { 4,0,5,6,0 };

	ChangeArr(arr, 5);

	int testArr[5] = { 4,3,5,6,3 };
	for (int i = 0; i < 5; ++i)
	{
		ASSERT_EQ(testArr[i], arr[i]);
	}
}

TEST(ChangeArrTests, Test2)
{
	double arr[5] = { 4.3,0,5.1,6.7,0 };

	ChangeArr(arr, 5);

	double testArr[5] = { 4.3,3.22,5.1,6.7,3.22 };
	for (int i = 0; i < 5; ++i)
	{
		ASSERT_DOUBLE_EQ(testArr[i], arr[i]);
	}
}


TEST(MaxElementTests, Test1)
{
	int arr[5] = { 4,0,5,6,0 };

	ASSERT_EQ(6, MaxElement(arr, 5));
}



TEST(MaxElementTests, Test2)
{
	char* str1 = "feij";
	char* str2 = "dd";
	char* str3 = "abgr";
	char* arr[3] = { str1,str2,str3 };
	
	ASSERT_STREQ(str1, MaxElement(arr, 3));
}

TEST(MaxElementTests, Test3)
{
	double arr[5] = { 4.3,0,5.1,6.7,0 };

	ASSERT_DOUBLE_EQ(6.7, MaxElement(arr,5));
}



TEST(SumElementTests, Test1)
{
	int arr[5] = { 4,0,5,6,0 };

	ASSERT_EQ(15, SumElements(arr, 5));
}

TEST(SumElementTests, Test2)
{
	char* str1 = "feij";
	char* str2 = "dd";
	char* str3 = "abgr";
	char* arr[3] = { str1,str2,str3 };

	char* testStr = "feijddabgr";

	ASSERT_STREQ(testStr, SumElements(arr, 3));
}

TEST(SumElementTests, Test3)
{
	double arr[5] = { 4.3,0,5.1,6.7,0 };

	ASSERT_DOUBLE_EQ(16.1, SumElements(arr, 5));
}

TEST(NewArrTests, Test1)
{
	int arr[5] = { 4,0,5,6,0 };

	int testArr[7] = { 4,0,5,6,0,6,15 };

	int* newArr = NewArr(arr, 5);

	for (int i = 0; i < 7; ++i)
	{
		ASSERT_EQ(testArr[i], newArr[i]);
	}
}


TEST(NewArrTests, Test2)
{
	char* str1 = "feij";
	char* str2 = "dd";
	char* str3 = "abgr";
	char* arr[3] = { str1,str2,str3 };

	char* sumStr = "feijddabgr";

	char* testArr[5] = { str1,str2,str3,str1,sumStr };

	char** newArr = NewArr(arr, 3);

	for (int i = 0; i < 5; ++i)
	{
		ASSERT_TRUE(strcmp(testArr[i], newArr[i]) == 0);
	}
}


TEST(NewArrTests, Test3)
{
	double arr[5] = { 4.3,0,5.1,6.7,0 };

	double* newArr = NewArr(arr, 5);

	double testArr[7] = { 4.3,0,5.1,6.7,0,6.7,16.1 };

	for (int i = 0; i < 7; ++i)
	{
		ASSERT_DOUBLE_EQ(testArr[i], newArr[i]);
	}
}
