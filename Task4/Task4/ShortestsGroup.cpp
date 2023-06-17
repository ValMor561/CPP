#include "pch.h"
#include "ShortestsGroup.h"

char* ShortestGroup(const char* str)
{
	if (str == nullptr)
		return nullptr;
	int beginword, endword;
	int beginminword = 0;
	int endminword = strlen(str);
	for (int i = 0; i < strlen(str); ++i)
	{
		while (str[i] == ' ')
			++i;
		
		beginword = i;
		while (str[i] != ' ' && str[i] != '\0')
		{
			++i;
		}
		endword = i;
		if (endword - beginword < endminword - beginminword)
		{	
			beginminword = beginword;
			endminword = endword;
		}
	}
	char* min = new char[endminword - beginminword];
	int j = 0;
	for (int i = beginminword; i < endminword; ++i)
	{
		min[j] = str[i];
		++j;
	}
	min[j] = '\0';
	return min;	
}