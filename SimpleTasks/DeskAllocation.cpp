#include <iostream>
#include <algorithm>

int DeskAllocation(int a)
{
	double f = (1 + sqrt(5)) / 2;
	int n = a + 1;
	return (pow(f, n) - pow(-f, -n)) / (2 * f - 1);
}

int main()
{
	std::cout << DeskAllocation(6);
}