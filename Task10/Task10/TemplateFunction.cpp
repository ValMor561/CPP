#include "pch.h"
#include "TemplateFunction.h"
#include <string.h>

template<>
char* MaxElement<char*>(char** arr, int size)
{
	char* max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (strcmp(arr[i], max) > 0)
			max = arr[i];
	}
	return max;
}

template<>
char* SumElements<char*>(char** arr, int size)
{
	int lenght = 0;
	for (int i = 0; i < size; ++i)
	{
		lenght += strlen(arr[i]);
	}
	char* sum = new char[lenght + 1];

	strcpy(sum, arr[0]);
	for (int i = 1; i < size; ++i)
	{
		strcat(sum, arr[i]);
	}
	return sum;
}

