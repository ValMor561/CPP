#include "pch.h"
#include "TargetFunc.h"
bool Target(double x, double y, double R)
{

	bool isInCircle = x * x + y * y <= R * R;
	bool isInSecondQuarter = y >= 0 && x <= 0;
	bool isInFourthQuarter = y <= 0 && x >= 0;
	bool isInTriangle = y >= 2 * (x - R) && y >= -2 * x;
	return isInCircle && isInSecondQuarter || isInFourthQuarter && isInCircle;
}