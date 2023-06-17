#include "pch.h"
#include "TransformationArray.h"
#include <iostream>



void TransformationArray(double *arr, int n)
{
	for (int i = 1; i <= n / 2; ++i)
	{
		double t;
		if (n % 2 == 1)
			if (i % 2 == 0)
			{
				t = arr[n - i];
				arr[n - i] = arr[i];
				arr[i] = t;
			}
		if (n % 2 == 0)
			if (i % 2 == 0)
			{
				t = arr[n - i + 1];
				arr[n - i + 1] = arr[i];
				arr[i] = t;
			}
	}
	int i = 0;
}