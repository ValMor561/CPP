#include "pch.h"
#include "FindInFigure.h"
#include"Figure.h"

           // const Figure* arr, const wchar_t* str
Figure* SearchByColor(const Figure* arr, const wchar_t* str,int count)
{
    // Также названия аргументов (везде, в общем-то) странные
    // почему arr? Это же фигуры - вот и назовите figures.
    // str - искомый цвет, так и назовите "color" или "neededColor"
    // count тоже не стоит отрывать от массива, они должны идти подряд
	Figure* resultArr = new Figure[count];
	int j = 0;
	for (int i = 0; i < count; ++i)
	{
		if (wcscmp(arr[i].Color, str) == 0)
		{
			resultArr[j] = arr[i];
			++j;
		}
	}
	if (j == 0)
		return nullptr; // а память освободить? Вы же уже выделили

	return resultArr; // А размер вернуть? Как пользователь поймет, сколько фигур найдено?
}

int CountOfOverlap(const Figure* arr, const wchar_t* str, int count)
{
	Figure* resultArr = new Figure[count];
	int j = 0;
	for (int i = 0; i < count; ++i)
	{
		if (wcscmp(arr[i].Color, str) == 0)
		{
			++j;
		}
	}
	return j;
}