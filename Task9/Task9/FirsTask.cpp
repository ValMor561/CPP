#include "pch.h"
#include "FirstTask.h"
#include <stdexcept> 

double Method(double a, double b, double eps,Func f)
{
	if (f(a) * f(b) > 0)
		throw std::runtime_error("No solutions");

	double c = (a + b) / 2;

	if (abs(a - b) < 2 * eps)
	{
		return c;
	}
	if (f(a) * f(c) <= 0)
	{
		return Method(a, c, eps, f);
	}
	else
	{
		return Method(c, b, eps, f);
	}
}