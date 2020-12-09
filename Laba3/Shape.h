#pragma once
#include <string>
struct Point { double x, y; };
class Shape
{
public:
	Shape(Point& point, double* edgeslength) : point(point), edgeslength(edgeslength) {};
	void virtual Move(Point &point);
	void virtual Rotate(int rotation);

	double virtual getArea() const { return area; }
	Point virtual const &getCenterOfMass() const { return point;  }
	double virtual getPerimeter() const { return perimeter; }
	int virtual getRotation() const { return rotation; }
	Point virtual const &getPoint() const { return point; }
	int virtual getEdgesCount() const { return edgescount; }
	double virtual *getEdgesLength() const { return edgeslength; }
	std::string virtual getName() const = 0;
	double virtual getMaxRadius() const { return maxradius; }

	
protected:
	void virtual countPerimeter() = 0;
	void virtual countArea() = 0;
	void virtual countMaxRadius() = 0;
	const int edgescount = 0;
	double* edgeslength = nullptr;

	double maxradius = 0;
	double area = 0;
	double perimeter = 0;
	int rotation = 90;
	Point point;
};

