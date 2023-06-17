#include "pch.h"
#include "..//MyString/MyString.h"
TEST(MyStringTests, TestNomberOne)
{
	MyString str(size_t(0));
	ASSERT_STREQ(str.Get(), "");
}

TEST(MyStringTests, TestNomberTwo)
{
	MyString str("Hello, world!");
	ASSERT_STREQ(str.Get(), "Hello, world!");
}

TEST(MyStringTests, TestNomberThree)
{
	MyString str("Hello, world!");
	ASSERT_EQ(str.Length(),13);
}


TEST(MST, nomber1)
{
	MyString str1("Hello");
	MyString str2("Hi");
	str1 = str2;
	ASSERT_STREQ(str1.Get(), "Hi");
}
TEST(MST, welcome_to_error)
{

	MyString str1("Hello");
	str1 = str1;
	ASSERT_STREQ(str1.Get(), "Hello");
}

TEST(MST, welcome_to_error_tripple_operator_test)
{
	MyString str1("1");
	MyString str2("2");
	MyString str3("3");
	str1 = str2 = str3;
	ASSERT_STREQ(str1.Get(), "3");
	ASSERT_STREQ(str2.Get(), "3");
	ASSERT_STREQ(str3.Get(), "3");
}
















