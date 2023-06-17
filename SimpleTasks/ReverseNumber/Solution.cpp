using namespace std;
#include <iostream>

unsigned int ReverseNumber(unsigned int number)
{
	unsigned int reverse;
	while (number != 0)
	{
		reverse *= 10;
		reverse += number % 10;
		number /= 10;
	}
	return reverse;
}

