#pragma once
#include "MyStringApi.hpp"
class MyString {
public:
	MYSTRING_API MyString(size_t size);
	MYSTRING_API MyString(const char* str);
	MYSTRING_API const char* Get();
	MYSTRING_API size_t Length();
	MYSTRING_API ~MyString();
	MYSTRING_API MyString& operator=(const MyString& other);
	MYSTRING_API MyString(MyString&& ohter);//Konstruct of teleport
private:
	char* _data;
};