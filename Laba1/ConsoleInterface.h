#pragma once

#include "Car.h"
#include "Parking.h"

class ConsoleInterface
{
public:
	ConsoleInterface();
    ~ConsoleInterface();
	void run();
    void printMenuText();
    void prompt(); //Приглашение командной строки
    void printCarArray(Car* array);
    void printCarArray(Car** array);
    void printParkedCars(Parking& parking);
    int ReadInt();
	

private:
    int cars_amount = 5;
    Car* cars = new Car[5]
    {
    Car("x235aq23", "Honda", "White"),
    Car("a241as77", "Toyota", "White"),
    Car("e137rz11", "Ford", "Grey"),
    Car("h888qq777", "Kia", "Blue"),
    Car("e849dl93", "Peugeot", "Black")
    };
	const int parking_size = 100;
	Parking* parking = new Parking(parking_size, parking_size * 10);

};

