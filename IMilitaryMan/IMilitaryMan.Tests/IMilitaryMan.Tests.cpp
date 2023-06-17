#include "pch.h"
#include "../IMilitaryMan/IMilitaryMan.h"

TEST(IMilitaryManTests, Test1)
{
	Soldier a;
	IMilitaryMan &militaryMan = a;
	militaryMan.Serve();
	
	ASSERT_EQ(1, a.GetJob());

	ASSERT_EQ(1,a.GetCount());
}
TEST(IMilitaryManTests, Test2)
{
	Soldier s1, s2, s3, s4, s5;
	IMilitaryMan** d = new IMilitaryMan * [2];
	d[0] = &s1;
	d[1] = &s2;

	Officer of(d,2);

	ASSERT_EQ(6, of.GetCount());

	IMilitaryMan** c = new IMilitaryMan * [4];
	c[0] = &s3;
	c[1] = &s4;
	c[2] = &s5;
	c[3] = &of;
	
	Officer gen(c, 4);
	
	ASSERT_EQ(7, of.GetCount());
	
	gen.Serve();

	ASSERT_EQ(1, s1.GetJob());
	ASSERT_EQ(1, s2.GetJob());
	ASSERT_EQ(1, s3.GetJob());
	ASSERT_EQ(1, s4.GetJob());
	ASSERT_EQ(1, s5.GetJob());		
}

TEST(IMilitaryManTests, Test3)
{
	{
		Soldier s1, s2, s3, s4, s5;
		IMilitaryMan** d = new IMilitaryMan * [2];
		d[0] = &s1;
		d[1] = &s2;

		Officer of(d, 2);
		int count = IMilitaryMan::_count;
		ASSERT_EQ(6, count);
	}
	int count = IMilitaryMan::_count;
	ASSERT_EQ(0, count);
}
