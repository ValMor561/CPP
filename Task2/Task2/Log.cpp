#include "pch.h"
#include "Log.h"
#include <math.h>


double Logarifm(int a)
{
	if (a <= 0)
		return -2;
	int n = 0;
	while (a % 2 == 0)
	{
		n += 1;
		a /= 2;
	}
	if (a == 1)
		return n;
	else
		return -1;
}

