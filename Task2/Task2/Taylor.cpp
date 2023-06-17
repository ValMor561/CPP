#include "pch.h"
#include  <iostream>
#include "Taylor.h"

double Taylor(double x, double epsilon, int &n)
{
	n = 1;
	double c = 1;
	double sum = 1;
	for (; abs(c) >= epsilon; ++n)
	{
		c *= -x / n;
			sum += c;
	}
	return sum;
}
