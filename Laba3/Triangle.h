#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(Point& point, double* edgeslength);
	std::string getName() const { return "Triangle"; }

private:
	const int edgescount = 3;
	void countPerimeter() override;
	void countArea() override;
	void countMaxRadius() override;
};

