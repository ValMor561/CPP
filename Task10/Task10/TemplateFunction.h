#pragma once
#include "Task10Api.hpp"

template<typename T>
void ChangeArr(T* arr, int size)
{
	T sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == 0)
			arr[i] = sum / size;
	}
}

template<typename T>
T MaxElement(T* arr, int size)
{
	T max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}


template<>
TASK10_API char* MaxElement<char*>(char** arr, int size);

template<typename T>
T SumElements(T* arr, int size)
{
	T sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

template<>
TASK10_API char* SumElements<char*>(char** arr, int size);


template<typename T>
T* NewArr(T* arr, int size)
{
	T* newArr = new T[size + 1];
	for (int i = 0; i < size; ++i)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = MaxElement(arr, size);
	newArr[size + 1] = SumElements(arr, size);
	return newArr;
}

