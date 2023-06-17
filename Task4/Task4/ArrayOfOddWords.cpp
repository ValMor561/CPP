#include "pch.h"
#include "ArrayOfOddWords.h"
 
char* NewWord(int begin, int end, const char* str)
{
	char* word = new char[end - begin];
	int j = 0;
	for (int i = begin; i < end; ++i)
	{
		word[j] = str[i];
		++j;
	}
	word[j] = '\0';
	return word;
}
int CountOfOddWords(const char* str)
{
	if (str == nullptr)
		return 0;
	int count = 0;
	int begin, end;
	for (int i = 0; i < strlen(str); ++i)
	{
		while (str[i] == ' ' || str[i] == ':')
			++i;

		begin = i;
		while (str[i] != ' ' && str[i] != ':' && str[i] != '\0')
		{
			++i;
		}
		end = i;
		if ((end - begin) % 2 != 0)
		{
			++count;
		}
	}
	return count;
}
char** ArrayOfOddWords(const char* str)
{
	if (str == nullptr)
		return nullptr;
	int begin, end;
	int count = CountOfOddWords(str);
	if (count == 0)
		return nullptr;
	char** arr = new char* [count] {};
	int j = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		while (str[i] == ' ' || str[i] == ':')
			++i;

		begin = i;
		while (str[i] != ' ' && str[i] != ':' && str[i] != '\0')
		{
			++i;
		}
		end = i;
		if ((end - begin) % 2 != 0)
		{
			arr[j] = NewWord(begin, end, str);
			++j;
		}
	}
	return arr;
}