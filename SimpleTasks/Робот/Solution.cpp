bool IsReturnToStart(const char* str)
{
	int x = 0;
	int y = 0;
	char direction = 'N';
	while (*str)
	{
		if (*str == 'G')
		{
			if (direction == 'N')
				++y;
			else if (direction == 'S')
				--y;
			else if (direction == 'E')
				--x;
			else if (direction == 'W')
				++x;
		}
		else if (*str == 'L')
		{
			if (direction == 'N')
				direction = 'E';
			else if (direction == 'S')
				direction = 'W';
			else if (direction == 'E')
				direction = 'S';
			else if (direction == 'W')
				direction = 'N';
		}
		else if (*str == 'R')
		{
			if (direction == 'N')
				direction = 'W';
			else if (direction == 'S')
				direction = 'E';
			else if (direction == 'E')
				direction = 'N';
			else if (direction == 'W')
				direction = 'S';
		}
	}
	if (x == 0 && y == 0)
		return true;
	return false;
}