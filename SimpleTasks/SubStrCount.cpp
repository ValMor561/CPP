#include <iostream>
#include <vector>
#include <string>

bool IsItSubStr(const char* str, const char* subStr)
{
	for (int i = 0;i < strlen(subStr);++i)
	{
		if (str[i] != subStr[i])
		{
			return false;
		}
	}
	return true;
}
template <typename T>
bool IsItSubStr(const T* str, const T* subStr)
{
	while (*subStr)
	{
		if (*str != *subStr)
		{
			return false;
		}
		++str;
		++subStr;
	}
	return true;
}
int SubStrCount(const char* str, const char* subStr)
{
	int count = 0;
	while (*str)
	{
		if (IsItSubStr(str, subStr))
		{
			str+=strlen(subStr);
			++count;
		}
		else
		{
			++str;
		}
	}
	return count;
}
template <typename T>
int SubStrCount(const T* str, const T* subStr)
{
	int count = 0;
	while (*str)
	{
		if (IsItSubStr(str, subStr))
		{
			++str;
			++count;
		}
		else
		{
			++str;
		}
	}
	return count;
}

int main()
{
	std::cout << SubStrCount("555", "5");
}
