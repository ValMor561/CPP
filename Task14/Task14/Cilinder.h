#pragma once
#include "IFlash.h"
#define _USE_MATH_DEFINES
#include <math.h> // ����� pi
class Cilinder : public IFlash
{
public:
	TASK14_API Cilinder(double h, double R);
	TASK14_API double Area() override;
	TASK14_API double Volume() override;
	TASK14_API static IFlash* Load(std::ifstream& stream);
	TASK14_API void Save(std::ostream& stream) override;
	TASK14_API double GetH(); //����� ��� ������
	TASK14_API double GetR(); //����� ��� ������
private:
	double _h;
	double _R;
};