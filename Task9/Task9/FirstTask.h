#pragma once
#include "Task9Api.hpp"
typedef double(*Func)(double);
TASK9_API double Method(double a, double b, double eps,Func);