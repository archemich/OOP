#pragma once
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

class ShapeFactory
{
public:
	static Shape* CreateShape(char cd, Point& point, double* edgeslength);
};

