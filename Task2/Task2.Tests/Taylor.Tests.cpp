#include "pch.h"
#include "../Task2/Taylor.h"

TEST(TeylorTests, OneToThrePowEpsilonMinusSix)
{
	printf("________________________________________________________________________________\n");
	printf("|	x	|	exp(-x)		|	n	|	f(x)		|\n");
	printf("________________________________________________________________________________\n");
	double x = 0, F;
	double a = 1;
	double b = 3;
	double dx = 0.2;
	int n = 1;
	for (int i = 0; x < b; ++i)
	{
		x = a + dx * i;
		std::cout << "|	" << x << "	|	" << exp(-x) << "	|	" << n << "	|	" << Taylor(x, 1e-6, n) << "	|" << std::endl;
		ASSERT_NEAR(exp(-x), Taylor(x, 1e-6, n), 1e-6);
	}
	printf("________________________________________________________________________________\n");
	
}
TEST(TeylorTests, ZeroPoinSixToFivePowEpsilonMinusSeven)
{
	printf("________________________________________________________________________________\n");
	printf("|	x	|	f(x)		|	n	|	exp(-x)		|\n");
	printf("________________________________________________________________________________\n");
	double x = 0, F;
	double a = 0.6;
	double b = 5;
	double dx = 0.5;
	int n = 1;
	for (int i = 0; x < b; ++i)
	{
		x = a + dx * i;
		std::cout << "|	" << x << "	|	" << exp(-x) << "	|	" << n << "	|	" << Taylor(x, 1e-6, n) << "	|" << std::endl;
		ASSERT_NEAR(exp(-x), Taylor(x, 1e-7, n), 1e-7);
	}
	printf("________________________________________________________________________________\n");
}
TEST(TeylorTests, ZeroPoinEightToFivePowEpsilonMinusThre)
{
	printf("________________________________________________________________________________\n");
	printf("|	x	|	f(x)		|	n	|	exp(-x)		|\n");
	printf("________________________________________________________________________________\n");
	double x = 0, F;
	double a = 0.8;
	double b = 5;
	double dx = 0.5;
	int n = 1;
	for (int i = 0; x < b; ++i)
	{
		x = a + dx * i;
		std::cout << "|	" << x << "	|	" << exp(-x) << "	|	" << n << "	|	" << Taylor(0.5, 1e-3, n) << "		|" << std::endl;
		ASSERT_NEAR(exp(-x), Taylor(x, 1e-6, n), 1e-3);

	}
	printf("________________________________________________________________________________\n");
}
