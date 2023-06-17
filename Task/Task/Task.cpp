#include "pch.h"

#include "Task.h"

char *function(char c, int n)
{
	char *str = new char[n + 1];
	str[n] = '\0';
	while (n-- > 0)
		str[n] = c;
	return str;
}