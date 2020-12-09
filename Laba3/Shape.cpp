#include "Shape.h"


void Shape::Move(Point &point)
{
	this->point = point;
}

void Shape::Rotate(int rotation)
{
	this->rotation = rotation;
}