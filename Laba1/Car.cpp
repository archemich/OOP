#include "Car.h"


Car::Car(string num, string brand, string color) : car_number(num), brand(brand), color(color)
{};

Car::Car() : car_number(nullptr), brand(nullptr), color(nullptr)
{};


Car::~Car()
{
	delete parking;
}


bool Car::operator==(Car& other)
{
	return this->car_number == other.getCarNumber() ? true : false;
}


void Car::park(Parking& parking)
{
	if (this->parking == nullptr)
	{
		int lot = parking.park(*this);
		if (lot >= 0)
		{
			this->parking = &parking;
			this->parking_lot = lot + 1;
		}
	}
}


void Car::unpark()
{
	if (this->parking != nullptr)
	{
		this->parking->unpark(this->parking_lot - 1);
		this->parking = nullptr;
		this->parking_lot = NULL;
	}
}


string& Car::getCarNumber()
{
	return car_number;
}

string& Car::getBrand()
{
	return brand;
}

string& Car::getColor()
{
	return color;
}

int Car::getParkingLot()
{
	return parking_lot;
}

bool Car::isParked()
{
	return this->parking ? true : false;
}