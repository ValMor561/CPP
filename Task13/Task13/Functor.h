#pragma once
#include "Task13Api.hpp" 
#include "Point.h"


class FunctorForInt
{
public:
	TASK13_API bool operator()(int element, int value);
};

class FunctorForDouble
{
public:
	TASK13_API bool operator()(double element, double value);
};

class FunctorForPoint
{
public:
	TASK13_API bool operator()(Point element, double value);
};