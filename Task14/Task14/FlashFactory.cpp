#include "pch.h"
#include "FlashFactory.h"
#include "Cilinder.h"
#include "Conus.h"


void RegisterLoaders()
{
	FlashFactory::GetInstance().RegisterLoader("Conus", Conus::Load);
	FlashFactory::GetInstance().RegisterLoader("Cilinder", Cilinder::Load);
}

void Save(std::ostream& stream, IFlash** flashes, int count)
{
	for (int i = 0; i < count; ++i)
		flashes[i]->Save(stream);
}

std::vector<IFlash*> Load(std::ifstream& stream)
{
	std::vector<IFlash*> result;
	std::string typeName;
	while (stream >> typeName)
	{
		IFlash* flash = FlashFactory::GetInstance().GetLoader(typeName)(stream);
		result.push_back(flash);
	}
	return result;
}

void FlashFactory::RegisterLoader(const std::string& typeName, FlashLoaderPtr loader)
{
	_data[typeName] = loader;
}

FlashLoaderPtr FlashFactory::GetLoader(const std::string& typeName)
{
	if (_data.find(typeName) == _data.end())
		throw std::runtime_error("Illegal type!");
	return _data[typeName];
}

FlashFactory& FlashFactory::GetInstance()
{
	static FlashFactory soleInstance;
	return soleInstance;
}
