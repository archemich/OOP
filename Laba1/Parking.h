#pragma once
#include "Car.h"
class Car;

class Parking
{
public:
	Parking(int cap, int dbsize);
	~Parking();

	int park(Car& car);
	void unpark(int lot);

	int getCapacity();
	Car** getCurrentCars();
	Car** getAllCars();

private:
	const int CAPACITY;
	const int DBSIZE;
	Car** current_cars;
	Car** all_cars;
	int all_cars_iterator = 0;
};

