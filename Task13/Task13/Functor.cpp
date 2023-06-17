#include "pch.h"
#include "Functor.h"
#include <cmath>

bool FunctorForInt::operator()(int element, int value)
{
	if (element == value)
		return true;
	return false;
}

bool FunctorForDouble::operator()(double element, double value)
{
	double eps = 0.0001;
	if (abs(element - value) < eps)
		return true;
	return false;
}

bool FunctorForPoint::operator()(Point element, double value)
{
	double x = element.GetX();
	double y = element.GetY();
	double z = element.GetZ();
	double distance = sqrt(x * x + y * y + z * z);
	double eps = 0.0001;
	if (abs(distance - value) < eps)
		return true;
	return false;
}
