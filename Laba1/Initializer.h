#pragma once
#include "Car.h"
#include <string>

class Initializer
{
public:
    Car* getCars();

private:
    Car* cars = new Car[5]
    {
    Car("x235aq23", "Honda", "White"),
    Car("a241as77", "Toyota", "White"),
    Car("e137rz11", "Ford", "Grey"),
    Car("h888qq777", "Kia", "Blue"),
    Car("e849dl93", "Peugeot", "Black")
    };
};

