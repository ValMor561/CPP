#include "pch.h"
#include <iostream>
#include <sstream>
#include "../Task13/Set.h"
#include "../Task13/Point.h"
#include "../Task13/Functor.h"

TEST(SetPointTests, Test1)
{
	Set<Point> a;

	Set<Point> b(10);

	Set<Point> c(b);

	Point r1(1, 2, 5), r2(12, 5, 1);

	Point arr[2] = { r1,r2 };
	
	c.AddElement(r1);
	c.AddElement(r2);
	c.RemoveElement(r1);

	ASSERT_TRUE(r2 == *c.GetData());

	b.AddElement(r1);

	Set<Point> d;

	d = b + c;

	for (int i = 0; i < d.GetSize(); ++i)
	{
		ASSERT_TRUE(arr[i] == d.GetData()[i]);
	}

}

TEST(SetPointTests, Test2)
{
	Set<Point> b(10);

	Set<Point> c(b);

	Point r1(1, 2, 5), r2(12, 5, 1);

	c.AddElement(r1);
	c.AddElement(r2);
	
	b.AddElement(r1);

	Set<Point> d;

	d = b*c;

	for (int i = 0; i < d.GetSize(); ++i)
	{
		ASSERT_TRUE(r1 == d.GetData()[i]);
	}
}


TEST(SetPointTests, Test3)
{
	Set<Point> b(10);

	Set<Point> c(b);

	Point r1(1, 2, 5), r2(12, 5, 1);

	c.AddElement(r1);
	
	
	b.AddElement(r1);
	b.AddElement(r2);

	Set<Point> d;

	d = b - c;

	for (int i = 0; i < d.GetSize(); ++i)
	{
		ASSERT_TRUE(r2 == d.GetData()[i]);
	}
}

TEST(SetPointTests, Test4)
{
	FunctorForPoint functor;
	Set<Point> b(10);

	Point r1(1, 2, 5), r2(12, 5, 1);

	b.AddElement(r1);
	b.AddElement(r2);

	ASSERT_TRUE(b.FindElement(5.4772, functor));
	ASSERT_TRUE(b.FindElement(13.0384, functor));
}

TEST(SetPointTests, Test5)
{
	Set<Point> b(2);

	std::stringstream ss;
	ss << "1 2 3 3 2 1";
	ss >> b;
	std::cout << b;

}

