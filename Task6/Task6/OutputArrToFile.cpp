#include "pch.h"
#include "OutputArrToFile.h"
#include "Figure.h"

void OutputArrToFile(const char* filename, Figure* arr, int count)
{
	FILE* stream;
	stream = fopen(filename, "wb");

    // Не обращайте внимания, у меня линукс немного с ума сошел от символа "№"
	fwprintf(stream, L"| # |       Name       |  Coordinates  |    Color    | distance |\n");
	fwprintf(stream, L"+---+------------------+-------+-------+-------------+----------+ \n");

	for (int i = 0; i < count; ++i)
	{
		fwprintf(stream, L"| %-1d | %-16s | %-5d | %-5d | %-11s | %-8d |\n", i + 1,arr[i].Name, arr[i].Coordinate[0], arr[i].Coordinate[1], arr[i].Color,arr[i].distance);
		fwprintf(stream, L"+---+------------------+-------+-------+-------------+----------+ \n");
	}
}
