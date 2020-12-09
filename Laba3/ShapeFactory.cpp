#include "ShapeFactory.h"
#include "Square.h"
#include "Triangle.h"

Shape* ShapeFactory::CreateShape(char cd, Point &point, double *edgeslength)
{
    Shape* sh = nullptr;
	switch (cd)
	{
	case 'S': sh = new Square(point, edgeslength); break;
	case 'T': sh = new Triangle(point, edgeslength); break;
	}
    return sh;
}
