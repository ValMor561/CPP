#include "pch.h"
#include "../Task3/CountOfLocalMin.h"
#include <fstream>



TEST(CountOfLocalMin, OneToTenArr)
{
	int n = 3;

	int** arr = new int* [n];
	
	arr[0] = new int[n] {1, 2, 3};
	arr[1] = new int[n] {4, 5, 6};
	arr[2] = new int[n] {7, 8, 9};

	ASSERT_EQ(1, CountOfLocalMin(arr, n));
	
	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
	}

	delete[] arr;
} 

TEST(CountOfLocalMin, OneAndZeroArrFromFile)
{
	int n;
	
	std::ifstream in("Arr.txt");

	in >> n;

	int** arr = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			in >> arr[i][j];

	int count;
	
	in >> count;

	ASSERT_EQ(count, CountOfLocalMin(arr, n));

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
	}

	delete[] arr;
}
