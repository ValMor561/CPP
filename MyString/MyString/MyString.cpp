#include "stdafx.h"
#include "MyString.h"
#include <iostream>
using namespace std;
MyString::MyString(size_t size) :
	_data(new char[size+1])
{
	_data[0] = '\0';
}

MyString::MyString(const char* str) :
	_data(new char[strlen(str)+1]) //_data(strdup(str))
{
	cout << "Container with const char* argument";
	strcpy_s(_data, strlen(str)+1, str);
}

const char* MyString::Get()
{
	return _data;
}

size_t MyString::Length()
{
	return strlen(_data);
}

MyString::~MyString() 
{
	delete[] _data;
}
MyString& MyString::operator=(const MyString& other)
{	
	cout << "Container with operator= argument";
	if (this == &other){//сравнивая указатели мы проверяем один и тоте же это объект ил нет if(*this == &other) сравниваются объекты
		return *this;
	}
	delete[] _data;
	_data = new char[strlen(other._data) + 1];
	strcpy_s(_data, strlen(other._data) + 1, other._data);

	return *this;
}

MyString::MyString( MyString && other): _data(other._data)// переприсовим кусок памяти
{	
	other._data = nullptr;
}
