#include "pch.h"
#include "Cilinder.h"

Cilinder::Cilinder(double h, double R)
	:_h(h), _R(R)
{
}

double Cilinder::Area()
{
	return 2 * M_PI * _R * (_h + _R);
}

double Cilinder::Volume()
{
	return M_PI * _R * _R * _h;
}

IFlash* Cilinder::Load(std::ifstream& stream)
{
	double h, R;
	stream >> h >> R;
	return new Cilinder(h, R);
}

void Cilinder::Save(std::ostream& stream)
{
	stream << "Cilinder" << " " << _h << " " << _R << std::endl;
}

double Cilinder::GetH()
{
	return _h;
}

double Cilinder::GetR()
{
	return _R;
}