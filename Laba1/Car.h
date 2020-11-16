#pragma once
#include "Parking.h"
#include <string>

using std::string;
class Parking;
class Car
{
public:
	Car();
	Car(string num, string brand, string color);
	~Car();
	bool operator==(Car& other);

	void park(Parking& parking);
	void unpark();

	string& getCarNumber();
	string& getBrand();
	string& getColor();
	int getParkingLot();
	bool isParked();

private:
	string car_number;
	string brand;
	string color;
	int parking_lot = NULL;
	Parking* parking = nullptr;
};

