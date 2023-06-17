#include "pch.h"
#include "../Task14/FlashFactory.h"
#include "../Task14/Conus.h"
#include "../Task14/Cilinder.h"

TEST(CunusTests, Test1)
{
	Conus a(1,4.2,4);
	IFlash& con = a;
	ASSERT_NEAR(108.1964, con.Area(),1e-4);
	ASSERT_NEAR(18.4725, con.Volume(),1e-4);
}

TEST(CilinderTests, Test1)
{
	Cilinder a(1, 4.2);
	IFlash& cir = a;
	ASSERT_NEAR(137.2247, cir.Area(),1e-4);
	ASSERT_NEAR(55.4176, cir.Volume(),1e-4);
}

TEST(FlashTests, Test1)
{
	
	IFlash* objects[] = { new Conus(2,2.4,8),new Cilinder(1,28) };
	std::ofstream fout;
	fout.open("AbstractFactory.txt");
	Save(fout, objects, 2);
	fout.close();
}
TEST(FlashTests, Test2)
{
	RegisterLoaders();
	std::ifstream fin;
	fin.open("AbstractFactory.txt");
	std::vector<IFlash*>loadedObjects = Load(fin);

	int size = loadedObjects.size();
	ASSERT_EQ(2, size);

	std::cout << "Loaded objects:" << std::endl;
	std::cout << "Load Conus" << " " << ((Conus*)loadedObjects[0])->GetH() << " " << ((Conus*)loadedObjects[0])->GetR() << " " << ((Conus*)loadedObjects[0])->GetL() << std::endl;
	std::cout << "Load Cilinder" << " " <<  ((Cilinder*)loadedObjects[0])->GetH() << " " << ((Cilinder*)loadedObjects[0])->GetR() << std::endl;
	fin.close();
}