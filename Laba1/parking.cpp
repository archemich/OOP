/*
// ЮФУ ИКТИБ МОП ЭВМ
// Неприн Михаил Андреевич, КТбо2-1
// Лабораторная работ №1, Вариант №14
// 05.09.2020
*/

#include "parking.h"
#include <iostream>
#include <stdexcept>


Parking::Parking(int parking_spaces): parking_spaces(parking_spaces)
{};


Parking::~Parking()
{
    delete[] _all_cars;
    delete[] _current_cars;
}

void Parking::saveNewCar(Car &car)
{
    try{
        _all_cars[_all_cars_iter] = &car;
    } catch(std::range_error &e) {
        throw std::range_error("Not enough memory to save a new car");
        return;
    }

    ++_all_cars_iter;
    return;
}


void Parking::park(Car &car)
{
    bool hasFound = false;
    for (int i = 0; i < _all_cars_iter; ++i) {
        if (car == *_all_cars[i]) {
            hasFound = true;
            break;
        }
    }
    if (!hasFound) {
        try
        {
            try {
                while (_current_cars[_current_cars_iter] != nullptr){
                    ++_current_cars_iter;
                }
            } catch (std::range_error &no_space) {
                throw std::range_error("No parking space to park this car");
            }
            _current_cars[_current_cars_iter] = &car;
            saveNewCar(car);
        } //try
        catch(std::range_error &e)
        {
            throw &e;
        }
    }
    return;
}


void Parking::unpark(Car &car)
{
    for (int i = 0; i < parking_spaces; i++)
    {
        if (car == *_current_cars[i])
        {
            _current_cars[i] = nullptr;
            break;
        }
    }
    return;
}


bool Parking::isCarParked(Car &car)
{
    for (int i = 0; i < parking_spaces; ++i){
        if (*_current_cars[i] == car){
            return true;
        }
    }
    return false;
}


Car** Parking::getParkedCars()
{

    return _current_cars;
}


Car** Parking::getAllCars()
{
     return _all_cars;
}
