#include "pch.h"
#include "ForwardList.h"

TEST(ForwardLstTests, Test1)
{
	ForwardList<int> a;
	
	a.push_back(9);
	a.push_back(8);
	a.push_front(7);
	
	ASSERT_EQ(9,a.get(2));
	ASSERT_FALSE(a.empty());
	ASSERT_EQ(3, a.size());

	ForwardList<int> b(a);
	ASSERT_TRUE(a == b);
}

TEST(ForwardLstTests, Test2)
{
	ForwardList<int> a;

	a.push_back(9);
	a.push_back(8);
	a.push_front(7);
	ForwardList<int> b;

	b.push_back(9);
	b.push_back(8);
	b.push_front(6);

	ASSERT_FALSE(a == b);
	ASSERT_TRUE(a != b);
}

TEST(ForwardLstTests, Test3)
{
	ForwardList<int> a;
	a.push_front(3);
	a.push_front(1);
	a.push_back(4);

	a.insert_after(a.first(), 2);

	ASSERT_EQ(a.get(1), 1);
	ASSERT_EQ(a.get(2), 2);
	ASSERT_EQ(a.get(3), 3);
	ASSERT_EQ(a.get(4), 4);

	a.reverse();

	ASSERT_EQ(a.get(1), 4);
	ASSERT_EQ(a.get(2), 3);
	ASSERT_EQ(a.get(3), 2);
	ASSERT_EQ(a.get(4), 1);
}


TEST(ForwardLstTests, Test4)
{
	ForwardList<int> a;

	a.push_back(9);
	a.push_back(8);
	a.push_back(10);
	a.push_front(7);

	a.remove(8);

	ASSERT_EQ(7, a.get(1));
	ASSERT_EQ(9, a.get(2));
	ASSERT_EQ(10, a.get(3));

}


TEST(ForwardLstTests, Test5)
{
	ForwardList<double> a;

	a.push_back(9.8);
	a.push_back(8.5);
	a.push_front(7.2);

	ASSERT_EQ(9.8, a.get(2));
	ASSERT_FALSE(a.empty());
	ASSERT_EQ(3, a.size());

	ForwardList<double> b(a);
	ASSERT_TRUE(a == b);
}

TEST(ForwardLstTests, Test6)
{
	ForwardList<double> a;

	a.push_back(9.8);
	a.push_back(8.5);
	a.push_front(7.2);
	ForwardList<double> b;

	b.push_back(9.8);
	b.push_back(8.5);
	b.push_front(6.4);

	ASSERT_FALSE(a == b);
	ASSERT_TRUE(a != b);
}

TEST(ForwardLstTests, Test7)
{
	ForwardList<double> a;
	a.push_front(3.7);
	a.push_front(1.4);
	a.push_back(4.2);

	a.insert_after(a.first(), 2.9);

	ASSERT_EQ(a.get(1), 1.4);
	ASSERT_EQ(a.get(2), 2.9);
	ASSERT_EQ(a.get(3), 3.7);
	ASSERT_EQ(a.get(4), 4.2);

	a.reverse();

	ASSERT_EQ(a.get(1), 4.2);
	ASSERT_EQ(a.get(2), 3.7);
	ASSERT_EQ(a.get(3), 2.9);
	ASSERT_EQ(a.get(4), 1.4);
}


TEST(ForwardLstTests, Test8)
{
	ForwardList<double> a;

	a.push_back(9.8);
	a.push_back(8.5);
	a.push_back(10.5);
	a.push_front(7.2);

	a.remove(8.5);

	ASSERT_EQ(7.2, a.get(1));
	ASSERT_EQ(9.8, a.get(2));
	ASSERT_EQ(10.5, a.get(3));

}