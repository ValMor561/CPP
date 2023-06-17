#include "pch.h"
#include "../Task6/ArrayOfFigure.h"
#include "../Task6/OutputArrToFile.h"

TEST(ArrayOfStructTests, ArrayFromFileNameTest)
{
	char* str = StrFromFile("Figure.json");
	Figure* arr = ArrayOfFigure(str);

	const char* name = "Circle";
	for (int i = 0; i < strlen(name); ++i)
	{
		ASSERT_EQ(name[i], arr[0].Name[i]); // Fail. См. замечание ниже
	}
	name = "Triangle";
	for (int i = 0; i < strlen(name); ++i)
	{
		ASSERT_EQ(name[i], arr[1].Name[i]);
	}
}

TEST(ArrayOfStructTests, ArrayFromFileCoordinateTest)
{
	char* str = StrFromFile("Figure.json");
	Figure* arr = ArrayOfFigure(str);

	int coordinate1[2] = {533,112};
	for (int i = 0; i < 2; ++i)
	{
		ASSERT_EQ(coordinate1[i], arr[0].Coordinate[i]);
	}
	int coordinate2[2] = { 121,331 };
	for (int i = 0; i < 2; ++i)
	{
		ASSERT_EQ(coordinate2[i], arr[1].Coordinate[i]);
	}
}

TEST(ArrayOfStructTests, ArrayFromFileColorTest)
{
	char* str = StrFromFile("Figure.json");
	Figure* arr = ArrayOfFigure(str);

	const char* color = "Red";
	for (int i = 0; i < strlen(color); ++i)
	{
		ASSERT_EQ(color[i], arr[0].Color[i]); // не прошел тест
		// Ну и вопрос, вообще, у вас color типа wchar_t, а вы вот так сравниваете их
	}
	color = "Blue";
	for (int i = 0; i < strlen(color); ++i)
	{
		ASSERT_EQ(color[i], arr[1].Color[i]);
	}
}

TEST(ArrayOfStructTests, OutputToFileTest)
{	
	char* str = StrFromFile("Figure.json");
	int count = CountOfSructs(str);
	Figure* arr = ArrayOfFigure(str);
	OutputArrToFile("ArrFigure.txt", arr, count);
}