#include "pch.h"
#include "Point.h"
#include <cmath>

Point::Point()
	:_x(0),_y(0),_z(0)
{
}

Point::Point(double x, double y, double z)
	:_x(x), _y(y), _z(z)
{
}

Point::Point(const Point& other)
	:_x(other._x),_y(other._y),_z(other._z)
{
}

Point::Point(Point&& other) noexcept
	:_x(other._x), _y(other._y), _z(other._z)
{
	other._x = 0;
	other._y = 0;
	other._z = 0;
}

Point::~Point()
{
}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	_x = other._x;
	_y = other._y;
	_z = other._z;
	return *this;
}

Point& Point::operator=(Point&& other) noexcept
{
	if (this == &other)
		return *this;
	_x = other._x;
	_y = other._y;
	_z = other._z;
	other._x = 0;
	other._y = 0;
	other._z = 0;
	return *this;
}

bool Point::operator==(const Point& other) const
{
	double eps = 0.0000001;
	if ( abs(_x - other._x) > eps || abs(_y - other._y) > eps || abs(_y - other._y) > eps)
		return false;
	return true;
}

double Point::GetX() const
{
	return _x;
}

double Point::GetY() const
{
	return _y;
}

double Point::GetZ() const
{
	return _z;
}

std::istream& operator>>(std::istream& stream, Point& c)
{
	stream >> c._x >> c._y >> c._z;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Point& c)
{
	stream << "Coordinate x=" << c._x << " Coordinate y=" << c._y << " Coordinate z=" << c._z << std::endl;
	return stream;
}
