#include "Parking.h"


Parking::Parking(int cap, int dbsize) : CAPACITY(cap), DBSIZE(dbsize)
{
	this->all_cars = new Car * [DBSIZE] {nullptr};
	this->current_cars = new Car * [CAPACITY] {nullptr};
}


Parking::~Parking()
{
	delete[] all_cars;
	delete[] current_cars;
}


int Parking::park(Car& car)
{
	int i = 0;
	bool saved = false;
	for (i = 0; i < all_cars_iterator; i++)
	{
		if (*all_cars[i] == car)
		{
			saved = true;
			break;
		}
	}

	if (!saved)
	{
		all_cars[all_cars_iterator++] = &car;
	}


	for (i = 0; i < this->CAPACITY; i++)
	{
		if (this->current_cars[i] == nullptr)
		{
			current_cars[i] = &car;
			return i;
		}
	}
	return -1;
}


void Parking::unpark(int lot)
{
	current_cars[lot] = nullptr;
	return;
}


int Parking::getCapacity()
{
	return CAPACITY;
}

Car** Parking::getCurrentCars()
{
	return current_cars;
}

Car** Parking::getAllCars()
{
	return all_cars;
}