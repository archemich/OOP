#ifndef INTERFACE_H
#define INTERFACE_H
#include "parking.h"
#include "car.h"

const int start_cars = 5;

class Interface
{
public:
    Interface();
    ~Interface();
    void printMenuText();
    void prompt(); //Приглашение командной строки
    void printCarArray(Car* array);
    void printCarArray(Car** array);
    void printParkedCars(Parking &parking);
    int ReadInt();

private:
    int cars_amount = start_cars;
    Car *cars = new Car[start_cars]
    {
        Car("x235aq23", "Honda", "White"),
        Car("a241as77", "Toyota", "White"),
        Car("e137rz11", "Ford", "Grey"),
        Car("h888qq777", "Kia", "Blue"),
        Car("e849dl93", "Peugeot", "Black")
    };

};



#endif // INTERFACE_H  