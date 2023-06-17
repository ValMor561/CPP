#include "pch.h"
#include "PiecemealFunc.h"
#include <cmath>

double f1()
{
	return - 3;
}

double f2(double x)
{
	return 0.5*x + 2;
}

double f3(double x)
{
	return -sqrt(16 - x*x);
}

double f4(double x)
{
	return x - 3;
}

double f5()
{
	return 3;
}

double f(double x)
{
	if (x < -10 || x > 8)
		return 0.0;
	if (x < -8)
		return f1();
	if (x < -3)
		return f2(x);
	if (x < 3)
		return f3(x);
	if (x < 5)
		return f4(x);
	//if (x < 8)
	return f5();
}