#include "pch.h"
#include "Convert.h"
#include <math.h>
#include <iostream>
int CountNumberInIntPart(const char* str)
{
	int count = 0;
	while (*str != '.' && *str != '\0')
	{
		++str;
		++count;
	}
	return count;
}

bool IsItNegative(const char* str)
{
	if (*str == '-')
		return true;
	return false;
}

bool IsItWithWrongLetter(const char* str,int system)
{
	int digit = 0;
	while (*str)
	{
		digit = *str - 'a' + 10;
		if (digit >= system)
			return true;
		++str;
	}
	return false;
}

double ConvertToDouble(const char* str, int system)
{
	if (IsItWithWrongLetter(str, system))
	{
		std::cout << "Wrong Letter";
		return -1;
	}
	int digit = 0;
	double sum = 0;
	bool isItNegative = IsItNegative(str);
	int count = CountNumberInIntPart(str) - 1;
	while (*str)
	{
		if (*str != '.')
		{
			if (*str >= 'a')
				digit = *str - 'a' + 10;
			else if (*str <= '10' && *str >= '0')
				digit = *str - '0';
			sum += digit * pow(system, count);
			--count;
			++str;
		}
		else
		{
			++str;
		}
	}
	if (isItNegative)
		return -sum;
	return sum;
}



