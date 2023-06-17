#include "pch.h"
#include "SwapTwoWords.h"

char* SwapTwoWords(const char* str)
{
	if (str == nullptr)
		return nullptr;
	char* newStr = new char[strlen(str) + 1];
	int beginfirst, endfirst, beginsecond,endsecond;
	int j = 0;
	for (int i = 0; i < strlen(str);)
	{
		while (str[i] == ' ')
		{
			++i;
			newStr[j] = ' ';
			++j;
		}
		beginfirst = i;
		while (str[i] != ' ' && str[i] != '\0')
		{
			++i;
		}
		endfirst = i;
		while (str[i] == ' ')
			++i;
		beginsecond = i;
		while (str[i] != ' ' && str[i] != '\0')
		{
			++i;
		}
		endsecond = i;
		
		for (int i = beginsecond; i < endsecond; ++i)
		{
			newStr[j] = str[i];
			++j;
		}
		for (int i = endfirst; i < beginsecond; ++i)
		{
			newStr[j] = ' ';
			++j;
		}
		for (int i = beginfirst; i < endfirst; ++i)
		{
			newStr[j] = str[i];
			++j;
		}
		
	}
	newStr[j] = '\0';
	return newStr;
	
}