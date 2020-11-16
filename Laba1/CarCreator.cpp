#include "CarCreator.h"

Car* CarCreator::createCar(string &num, string &brand, string &color)
{
	return new Car(num, brand, color);
}