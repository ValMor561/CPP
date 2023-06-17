#include "pch.h"
#include "../Task6/ArrayOfFigure.h"
#include "../Task6/FindInFigure.h"
#include "../Task6/OutputArrToFile.h"

TEST(a, Test1)
{
	char* str = StrFromFile("Figure.json");
	Figure* arr = ArrayOfFigure(str);
	int count = CountOfSructs(str);

	Figure* newArr = SearchByColor(arr, L"Blue", count);

	int countOverlap = CountOfOverlap(arr, L"Blue", count); // не нужно отдельный метод, пусть тот вернет размер
	const char* color = "Blue";
	for (int i = 0; i < countOverlap; ++i)
	{
		for (int j = 0; j < strlen(color); ++j)
		{
			ASSERT_EQ(newArr[i].Color[j], color[j]);
		}
	}

	OutputArrToFile("FindInArr.txt", newArr, countOverlap);
}