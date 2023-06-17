#include "pch.h"
#include "Logic.h" 

bool Func1(bool  a, bool b, bool c)
{
	return  !(!a && b) || !c;
}
bool Func2(bool  a, bool b, bool c)
{
	return (a || !b) || !c;
}