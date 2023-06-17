#pragma once
#include "IFlash.h"

typedef IFlash* (*FlashLoaderPtr)(std::ifstream& stream);

TASK14_API void RegisterLoaders();
TASK14_API void Save(std::ostream& stream, IFlash** flashes, int count);
TASK14_API std::vector<IFlash*> Load(std::ifstream& stream);

class FlashFactory
{
public:
	TASK14_API void RegisterLoader(const std::string& typeName, FlashLoaderPtr loader);
	TASK14_API FlashLoaderPtr GetLoader(const std::string& typeName);
	TASK14_API static FlashFactory& GetInstance();
private:
	std::map<std::string, FlashLoaderPtr> _data;
};
