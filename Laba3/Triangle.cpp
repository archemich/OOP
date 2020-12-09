#include "Triangle.h"
#include <cmath>

Triangle::Triangle(Point& point, double* edgeslength) : Shape(point, edgeslength)
{
	countPerimeter();
	countArea();
	countMaxRadius();
	return;
}


void Triangle::countArea()
{
	double p = perimeter / 2;
	area = sqrt(p * (p - edgeslength[0]) * (p - edgeslength[1]) * (p - edgeslength[2]));
}


void Triangle::countPerimeter()
{
	perimeter = edgeslength[0] + edgeslength[1] + edgeslength[2];
}

void Triangle::countMaxRadius()
{
	double p = perimeter / 2;
	maxradius = (edgeslength[0] * edgeslength[1] * edgeslength[2]) / (4 * sqrt(p * (p - edgeslength[0]) * (p - edgeslength[1]) * (p - edgeslength[2])));
}

