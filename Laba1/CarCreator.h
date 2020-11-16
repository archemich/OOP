#pragma once
#include "Car.h"
class CarCreator
{
public:
	static Car* createCar(string &num, string &brand, string &color);
};

