#include "pch.h"
#include "../Task6/SortArr.h"
#include "../Task6/ArrayOfFigure.h"
#include "../Task6/OutputArrToFile.h"

TEST(ArrayOfStructTests, Test1)
{
	char* str = StrFromFile("Figure.json");
	Figure* arr = ArrayOfFigure(str);
	int count = CountOfSructs(str);

	SortArr(arr, count);
	
	OutputArrToFile("SortArr.txt",arr, count);

	for (int i = 0; i < count - 1; ++i)
	{
		ASSERT_TRUE(arr[i].distance < arr[i + 1].distance);
	}
}