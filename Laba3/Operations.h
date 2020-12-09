#pragma once
#include "Shape.h"
class Operations
{
public:
	static int compare(Shape& shape1, Shape& shape2);
	static bool isIncluded(Shape& shape1, Shape& shape2);
	static bool isIntersected(Shape& shape1, Shape& shape2);
	static double getDistance(Point& point1, Point& point2);

};

