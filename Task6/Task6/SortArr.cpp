#include "pch.h"
#include "Figure.h"
#include "SortArr.h"

void SortArr(Figure* arr, int count)
{
	Figure temp;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count - 1; ++j)
		{
			if (arr[j].distance > arr[j + 1].distance)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}