#include "pch.h"
#include "../Task9/FirstTask.h"

double Func1(double x)
{
	return x * x - x - 91;
}

double Func2(double x)
{
	return x * x * x - 52;
}


TEST(MethodTests, Test1)
{
	
	ASSERT_NEAR(-9.0524, Method(-12, -3, 0.0001, Func1),0.0001);
}


TEST(MethodTests, Test2)
{

	ASSERT_NEAR(-9.0524, Method(-20, 2, 0.0001, Func1), 0.0001);
}



TEST(MethodTests, Test3)
{

	ASSERT_THROW(Method(20, 29, 0.0001, Func1),std::runtime_error);
}


TEST(MethodTests, Test4)
{

	ASSERT_THROW(Method(20, 29, 0.0001, Func2), std::runtime_error);
}


TEST(MethodTests, Test5)
{
	ASSERT_NEAR(3.7325, Method(-12, 18, 0.0001, Func2), 0.0001);
}

