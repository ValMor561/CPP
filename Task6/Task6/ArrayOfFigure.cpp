#include "pch.h"
#include "ArrayOfFigure.h"
#include "Figure.h"

#include <math.h>



char* StrFromFile(const char* fileName)
{

	FILE* ptrFile;
	ptrFile = fopen(fileName, "r+");
	if (ptrFile == nullptr)
		return nullptr;

	fseek(ptrFile, 0, SEEK_END);
	long fileSize = ftell(ptrFile); 
	rewind(ptrFile); 
	char* buffer = new char[fileSize + 1]{};
	fread(buffer, 1, fileSize, ptrFile); 
	fclose(ptrFile); 
	return buffer;
}

int CountOfSructs(const char* str)
{
	int count = 0;
	while (*str)
	{
		if (*str++ == '{')
			++count;
	}
	return count;
}

wchar_t* StrToWideStr(const char* str)
{
	size_t length = strlen(str);
	size_t converted = 0;
	// лишнего выделяете. Причем значительно, у вас в исходное строке
	// символов меньше, чем байтов (в случае, например, русского текста - ровно вдвое)
	// Здесь лучше воспользоваться функцией MultibyteToWidechar, хотя бы чтобы узнать нужный размер
	wchar_t* wstr = new wchar_t[length + 1];
	converted = mbstowcs(wstr, str, length + 1);
	if (converted != length)
		return nullptr;

	return wstr;
}

wchar_t* SkipUnnecessarySymbols(wchar_t* wstr)
{
	int indexOfColon = 0;
	swscanf(wstr, L"%*[^:]%n", &indexOfColon); 
	if (*(wstr + indexOfColon) == L':')
		++indexOfColon; 
	return wstr + indexOfColon;
}

Figure* ArrayOfFigure(const char* str)
{
	int count = CountOfSructs(str);
	if (!count)
			return nullptr;
	wchar_t* wstr = StrToWideStr(str);

	Figure* arr = new Figure[count];
	for (int k = 0; k < count; ++k)
	{
	
		int distance = 0;
		wstr = SkipUnnecessarySymbols(wstr); 
		swscanf(wstr, L"%*[^\"]%n", &distance); 
		wstr += distance + 1; 
		swscanf(wstr, L"%[^\"]s", &arr[k].Name); 
		wstr = SkipUnnecessarySymbols(wstr); 
		for (int i = 0; i < 2; ++i)
		{
			distance = 0;
			swscanf(wstr, L"%*[^0-9]%n", &distance);
			wstr += distance;
			swscanf(wstr, L"%d", &arr[k].Coordinate[i]);
			int indexOfColon;
			swscanf(wstr, L"%*[^,]%n", &indexOfColon);
			if (*(wstr + indexOfColon) == L',')
				++indexOfColon;
			wstr += indexOfColon;
		}
		wstr = SkipUnnecessarySymbols(wstr);
		swscanf(wstr, L"%*[^\"]%n", &distance);
		wstr += distance + 1;
		swscanf(wstr, L"%[^\"]s", &arr[k].Color);

		arr[k].distance = sqrt((arr[k].Coordinate[0] * arr[k].Coordinate[0]) + (arr[k].Coordinate[1] * arr[k].Coordinate[1]));
	}
	return arr;
}