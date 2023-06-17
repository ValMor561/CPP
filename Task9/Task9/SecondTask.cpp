#include "pch.h"
#include "SecondTask.h"
#include <string>
#include <sstream>
int Sum(int a, int b)
{
	return a + b;
}

double Sum(std::string str1, std::string str2, std::string str3)
{
	double a, b, c;
	std::stringstream stream1(str1);
	stream1 >> a;
	std::stringstream stream2(str2);
	stream2 >> b;
	std::stringstream stream3(str3);
	stream3 >> c;
	return a + b + c;
}