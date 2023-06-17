#include "pch.h"
#include "Conus.h"



Conus::Conus(double h, double R, double l)
	:_h(h), _R(R), _l(l)
{
}

double Conus::Area()
{
	return M_PI * _R * (_l + _R);
}

double Conus::Volume()
{
	return M_PI * _R * _R * _h * 1 / 3;
}

IFlash* Conus::Load(std::ifstream& stream)
{
	double h, R, l;
	stream >> h >> R >> l;
	return new Conus(h, R, l);
}

void Conus::Save(std::ostream& stream)
{
	stream << "Conus" << " " << _h << " " << _R << " " << _l << std::endl;
}

double Conus::GetH()
{
	return _h;
}

double Conus::GetR()
{
	return _R;
}

double Conus::GetL()
{
	return _l;
}