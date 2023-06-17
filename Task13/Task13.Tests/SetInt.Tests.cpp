#include "pch.h"
#include <iostream>
#include "../Task13/Set.h"
#include "../Task13/Functor.h"

TEST(SetTests, Test1)
{
	Set<int> a;

	Set<int> b(10);

	Set<int> c(b);

	c.AddElement(10);
	c.AddElement(9);
	c.RemoveElement(10);

	ASSERT_EQ(9, *c.GetData());

	b.AddElement(10);
	b.AddElement(9);

	int arr[2] = { 10,9 };

	Set<int> d;

	d = b + c;
	
	for (int i = 0; i < d.GetSize(); ++i)
	{
		ASSERT_EQ(arr[i], d.GetData()[i]);
	}
}


TEST(SetTests, Test2)
{
	Set<int> a(5);
	Set<int> b(6);

	a.AddElement(10);
	a.AddElement(9);
	
	b.AddElement(9);
	b.AddElement(10);
	b.AddElement(8);

	Set<int> d;

	int arr[2] = { 9,10 };

	d = b * a;

	for (int i = 0; i < d.GetSize(); ++i)
	{
		ASSERT_EQ(arr[i], d.GetData()[i]);
	}
}

TEST(SetTests, Test3)
{
	Set<int> a(5);
	Set<int> b(6);

	a.AddElement(10);
	a.AddElement(9);

	b.AddElement(7);
	b.AddElement(9);
	b.AddElement(10);
	b.AddElement(8);

	Set<int> d;

	int arr[2] = { 7,8 };

	d = b - a;

	for (int i = 0; i < d.GetSize(); ++i)
	{
		ASSERT_EQ(arr[i], d.GetData()[i]);
	}	
}

TEST(SetTests, Test4)
{
	FunctorForInt functor;

	Set<int> a(5);
	
	a.AddElement(10);
	a.AddElement(9);
	a.AddElement(7);

	ASSERT_TRUE(a.FindElement(7, functor));
	ASSERT_FALSE(a.FindElement(8, functor));
}


TEST(SetTests, Test5)
{
	FunctorForDouble functor;

	Set<double> a(5);

	a.AddElement(10.12);
	a.AddElement(9.13);
	a.AddElement(7.58);

	ASSERT_TRUE(a.FindElement(7.58, functor));
	ASSERT_FALSE(a.FindElement(8.12, functor));
}

TEST(SetTests, Test6)
{
	Set<int> a(5);

	std::stringstream ss;
	ss << "1 2 3 4 5";
	ss >> a;
	std::cout << a;
}



