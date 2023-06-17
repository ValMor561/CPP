#include "pch.h"
#include "Trigonometry.hpp"
#define _USE_MATH_DEFINES
#include <cmath>



double Func1(double  a)
{
	return (cos(a) + sin( a) + cos(3 * a) + sin(3 * a));
}
double Func2(double a)
{
	return (2*sqrt(2)*cos(a)*sin( M_PI /4+2*a));
}