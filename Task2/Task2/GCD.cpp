#include "pch.h"
#include "GCD.h"
#include <cmath>

int GCDRecurs(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	if (abs(a) >= abs(b))
	{
		int r = a % b;
		if (r == 0)
			return abs(b);

		return GCDRecurs(b, r);
	}
	int r = b % a;
	if (r == 0)
		return abs(a);
	
	return GCDRecurs(a, r);
}





int GCDUnRecurs(int a, int b)
{
	int r = 1;
	if (a == 0 || b == 0)
		return 0;
	while (r != 0)
	{
		if (abs(a) >= abs(b))
		{
			r = a % b;
			if (r == 0)
				return abs(b);
			a = b;
			b = r;
		}
		r = b % a;
		if (r == 0)
			return abs(a);
		b = r;
	}

}