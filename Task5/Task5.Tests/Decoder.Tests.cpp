#include "pch.h"
#include "../Task5/Decoder.h"
#include <fstream>

TEST(DecoderTests, Key4Simbols)
{
	const char outputFileName[] = "ciphertext1.txt";
	const char inputFileName[] = "opentext1.txt";
	const char result[] = "PPRSSQPPRSSQPPRSSQ";

	const char key[19] = "abc";

	Decoder(inputFileName, outputFileName, key);

	std::ifstream inputFile(outputFileName, std::ios::binary);
	char str[20];
	inputFile.getline(str, 19, '\0');

	ASSERT_STREQ(result, str);
}

TEST(DecoderTests, NormalText)
{
	const char outputFileName[] = "ciphertext2.txt";
	const char inputFileName[] = "opentext2.txt";
	const char result[] = "This text is secret";
	const char key[20] = { 1, 3, 4, 6, 2, 7,'\0' };

	Decoder(inputFileName, outputFileName, key);

	std::ifstream inputFile(outputFileName, std::ios::binary);
	char str[20];
	inputFile.getline(str, 20, '\0');

	ASSERT_STREQ(result, str);
}