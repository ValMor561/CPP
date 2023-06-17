#include "pch.h"
#include "../Task4/SwapTwoWords.h"


TEST(SwapTwoWordsTests, Test1)
{
	const char* str1 = "abc 11 defgh 222 ccc 00 456789 21";

	const char* str2 = "11 abc 222 defgh 00 ccc 21 456789";

	char* str3 = SwapTwoWords(str1);
	ASSERT_STREQ(str2, str3);

}

TEST(SwapTwoWordsTests, Test2)
{
	char str1[] = "abc 11 defgh 222 ccc 00 456789";

	char str2[] = "11 abc 222 defgh 00 ccc 456789";

	char *str3 = SwapTwoWords(str1);
	ASSERT_STREQ(str2,str3); 
}

TEST(SwapTwoWordsTests, Test3)
{
	char str1[] = " abc  11 defgh   222 ccc 00 456789 21";

	char str2[] = " 11  abc 222   defgh 00 ccc 21 456789";

	char* str3 = SwapTwoWords(str1);
	ASSERT_STREQ(str2, str3);
}

