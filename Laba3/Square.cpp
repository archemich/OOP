#include "Square.h"
#include <cmath>


Square::Square(Point& point, double* edgeslength) : Shape(point, edgeslength)
{
	countPerimeter();
	countArea();
	countMaxRadius();
	return;
}

void Square::countArea()
{
	area = edgeslength[0]*2;
}

void Square::countMaxRadius()
{
	maxradius = edgeslength[0] / sqrt(2);
}

void Square::countPerimeter()
{
	perimeter = edgeslength[0] * 4;
}


