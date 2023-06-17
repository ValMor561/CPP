#include "pch.h"
#include "Encoder.h"
#include <fstream> 

int Encoder(const char* inputFileName, const char* outputFileName, const char* key)
{
	char ch{};
	int i = 0;
	std::ifstream inputFile(inputFileName, std::ios_base::binary);

	if (!inputFile.is_open())  
	{   
		return 1; 
	}

	std::ofstream outputFile(outputFileName, std::ios_base::out | std::ios_base::trunc);

	if (!outputFile.is_open()) 
	{   
		inputFile.close(); 
		return -1; 
	}

	while (!inputFile.eof())
	{
		ch = inputFile.get();
		ch = ch ^ (int)key[i];
		outputFile.put(ch);
		++i;
		if (i == (strlen(key)))
			i = 0;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
