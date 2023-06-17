#include "pch.h"
#include "../Task5/Encoder.h"
#include <fstream>

TEST(EncoderTests, Key4Simbols)
{
	const char inputFileName[] = "ciphertext1.txt";
	const char outputFileName[] = "opentext1.txt";
	const char result[] = "121212121212121212";
	const char key[19] = "abc";
	
	Encoder(inputFileName, outputFileName, key);
	
	std::ifstream inputFile(outputFileName, std::ios::binary);
	char str[19];
	inputFile.getline(str, 19, '\0');
	
	ASSERT_STREQ(result, str);
}

TEST(EncoderTests, NormalText)
{
	const char inputFileName[] = "ciphertext2.txt";
	const char outputFileName[] = "opentext2.txt";
	const char result[] = "Ukmu\"sd{p&kt!paepbu";
	const char key[20] = { 1, 3, 4, 6, 2, 7,'\0' };

	Encoder(inputFileName, outputFileName, key);

	std::ifstream inputFile(outputFileName, std::ios::binary);
	char str[20];
	inputFile.getline(str, 20, '\0');

	ASSERT_STREQ(result, str);
}