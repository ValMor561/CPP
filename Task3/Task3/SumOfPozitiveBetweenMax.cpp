#include "pch.h"
#include "SumOfPozitiveBetweenMax.h"


int IndexOfMaxElement(const double *arr, int n)
{
	int indMax = 0; 
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > arr[indMax])
			indMax = i;
	}
	return indMax;
}

double SumOfPozitiveBetweenMax(const double *arr, int n)
{
	int indMax = 0;
	double sum = 0;
	indMax = IndexOfMaxElement(arr, n);
	for (int i = 0; i < indMax; ++i)
	{
		if (arr[i] > 0)
			sum += arr[i];
	}
	return sum;
}