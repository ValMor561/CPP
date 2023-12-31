#include "pch.h"
#include "../TemplateArray/TemplateArray.h"

TEST(TemplataArray, Test1)
{	
	Array<int> b(3);
	
	b.push_back(3);

	Array<int> c(b);
	 
	ASSERT_EQ(1, c.size());
	ASSERT_EQ(3, c[0]);

	c.push_back(1);
	ASSERT_EQ(2, c.size());
	ASSERT_EQ(1, c[1]);

	c.push_back(2);
	ASSERT_EQ(3, c.size());
	ASSERT_EQ(3, c.capacity());
	
	c.push_back(3);
	ASSERT_EQ(6, c.capacity());
	
	c.push_back(4);
	c.push_back(5);

	ASSERT_EQ(3, *(c.begin()));
	ASSERT_EQ(5, *(c.end() - 1));

	ASSERT_THROW(c[10], std::runtime_error);
}

TEST(TemplataArray, Test2)
{
	Array<double> b(3);

	b.push_back(3.1);

	Array<double> c(b);

	ASSERT_EQ(1, c.size());
	ASSERT_DOUBLE_EQ(3.1, c[0]);

	c.push_back(1.42);

	ASSERT_EQ(2, c.size());
	ASSERT_DOUBLE_EQ(1.42, c[1]);

	c.push_back(2.14);

	ASSERT_EQ(3, c.size());
	ASSERT_EQ(3, c.capacity());

	c.push_back(3);
	ASSERT_EQ(6, c.capacity());

	c.push_back(4);
	c.push_back(5.19393);

	ASSERT_DOUBLE_EQ(3.1, *(c.begin()));
	ASSERT_DOUBLE_EQ(5.19393, *(c.end() - 1));

	ASSERT_THROW(c[10], std::runtime_error);
}