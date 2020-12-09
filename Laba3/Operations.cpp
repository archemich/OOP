#include "Operations.h"

int Operations::compare(Shape& shape1, Shape& shape2)
{
	if (shape1.getArea() > shape2.getArea())
		return 1;
	else if (shape1.getArea() < shape2.getArea())
		return -1;
	else
		return 0;
}


bool Operations::isIncluded(Shape& shape1, Shape& shape2)
{
	double radius1 = shape1.getMaxRadius();
	double radius2 = shape2.getMaxRadius();

	Point point1 = shape1.getPoint();
	Point point2 = shape2.getPoint();
	double dist = getDistance(point1, point2);

	if (dist <= abs(radius1 - radius2))
	{
		return true;
	}
	return false;
}


bool Operations::isIntersected(Shape& shape1, Shape& shape2)
{
	double radius1 = shape1.getMaxRadius();
	double radius2 = shape2.getMaxRadius();

	Point point1 = shape1.getPoint();
	Point point2 = shape2.getPoint();
	double dist = getDistance(point1, point2);

	if (dist > radius1 + radius2 || dist <= abs(radius1 - radius2))
	{
		return false;
	}
	return true;
}

double Operations::getDistance(Point& point1, Point& point2)
{
	return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

