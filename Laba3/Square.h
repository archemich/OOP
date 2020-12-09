#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square(Point& point, double* edgeslength);
	std::string getName() const { return "Square"; }

private:
	const int edgescount = 4;

	void countPerimeter() override;
	void countArea() override;
	void countMaxRadius() override;
};
