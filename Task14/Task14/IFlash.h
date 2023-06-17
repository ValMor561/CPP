#pragma once
#include "Task14Api.hpp" 
class  IFlash
{
public:
	TASK14_API virtual ~IFlash();
	TASK14_API virtual double Area() = 0;
	TASK14_API virtual double Volume() = 0;
	TASK14_API virtual void Save(std::ostream& stream) = 0;
};

