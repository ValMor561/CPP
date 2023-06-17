#pragma once
#include "IFlash.h"
#define _USE_MATH_DEFINES
#include <math.h> // число pi
class Conus : public IFlash
{
public:
	TASK14_API Conus(double h, double R, double l);
	TASK14_API double Area() override;
	TASK14_API double Volume() override;
	TASK14_API static IFlash* Load(std::ifstream& stream);
	TASK14_API void Save(std::ostream& stream) override;
	TASK14_API double GetH(); //нужен для тестов
	TASK14_API double GetR(); //нужен для тестов
	TASK14_API double GetL(); //нужен для тестов

private:
	double _h;
	double _R;
	double _l;
};