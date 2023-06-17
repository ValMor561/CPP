#include "pch.h"
#include "../Task4/ArrayOfOddWords.h"


TEST(ArrayOfOddWordsTests, WithoutOddWords)
{
	char str1[] = " ab 11   defg 22: cc 00 5689";

	int count = CountOfOddWords(str1);
	ASSERT_EQ(0, count);


	char** arrayOfOddWords = ArrayOfOddWords(str1);
	EXPECT_EQ(nullptr, arrayOfOddWords);

	delete[] arrayOfOddWords;

}

TEST(ArrayOfOddWordsTests, RandomStr)
{
	char str1[] = " abc 11   defgh 222: ccc 00 456789";

	int count = CountOfOddWords(str1); 
	ASSERT_EQ(4, count);

	char** str2 = new char* [4];

	str2[0] = "abc";  
	str2[1] = "defgh"; 
	str2[2] = "222";  
	str2[3] = "ccc";  

	char** arrayOfOddWords = ArrayOfOddWords(str1);
	for (int i = 0; i < 4; ++i)
		ASSERT_EQ(strcmp(str2[i],arrayOfOddWords[i]),0);

	
	delete[] arrayOfOddWords; 
	delete[] str2;
}
