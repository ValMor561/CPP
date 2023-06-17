#pragma once
#include "Task13Api.hpp"
#include <iostream>

class Point
{
public:
	TASK13_API Point();
	TASK13_API Point(double x, double y, double z);
	TASK13_API Point(const Point& other);
	TASK13_API Point(Point&& other) noexcept;
	TASK13_API ~Point();
	
	TASK13_API Point& operator=(const Point& other);
	TASK13_API Point& operator=(Point&& other) noexcept;
	TASK13_API bool operator==(const Point& other) const; 
	TASK13_API friend std::istream& operator >> (std::istream& stream, Point& c);
	TASK13_API friend std::ostream& operator << (std::ostream& stream, Point& c);

	TASK13_API double GetX() const; 
	TASK13_API double GetY() const; 
	TASK13_API double GetZ() const; 
private:
	double _x;
	double _y;
	double _z;
};