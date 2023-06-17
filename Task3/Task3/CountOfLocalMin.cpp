#include "pch.h" 
#include "CountOfLocalMin.h"
#include <iostream>
#include <strstream>

int CountOfLocalMin(int **arr, int size)
{
	
	int ñount = 0; 
	bool leftNeighbor = false;
	bool lowerNeighbor = false;
	bool rightNeighbor = false;
	bool upperNeighbor = false;

	for (int i = 0; i < size ; ++i)
	{
		for (int j = 0; j < size ; ++j)
		{

			if (i == 0)
				upperNeighbor = true;
			else
				upperNeighbor = arr[i][j] < arr[i - 1][j];
			
			
			if (i == size -1)
				lowerNeighbor = true;
			else
				lowerNeighbor = arr[i][j] < arr[i + 1][j];
			
			
			if (j == 0)
				leftNeighbor = true;
			else 
				leftNeighbor = arr[i][j] < arr[i][j - 1];
			
			
			if (j == size - 1)
				rightNeighbor = true;
			else 
				rightNeighbor = arr[i][j] < arr[i][j + 1];
				
				
	
			
			if (leftNeighbor && lowerNeighbor && rightNeighbor && upperNeighbor)
				++ñount;
		}
	}
	return ñount;
}