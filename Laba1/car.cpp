/*
// ЮФУ ИКТИБ МОП ЭВМ
// Неприн Михаил Андреевич, КТбо2-1
// Лабораторная работ №1, Вариант №14
// 05.09.2020
*/

#include "car.h"

Car::Car() : _carNumber(nullptr), _model(nullptr), _color(nullptr)
{};


Car::Car(std::string carNumber, std::string model, std::string color)
    : _carNumber(carNumber), _model(model), _color(color)
{};


Car::~Car()
{
    _current_parking = nullptr;
}


bool Car::operator==(const Car &other)
{
    if (this->_color == other._color
        && this->_carNumber == other._carNumber
        && this->_model == other._model)
        return true;
    return false;
}


void Car::park(Parking &parking)
{
    parking.park(*this);
    _current_parking  = &parking;
    return;
}

void Car::unpark()
{
    _current_parking->unpark(*this);
    _current_parking = nullptr;
    return;
}

bool Car::isParked()
{
    return ((_current_parking != nullptr) ? true : false);
}

void Car::setColor(std::string &color)
{
    _color = color;
    return;
}

std::string Car::getColor() const
{
    return _color;
}


std::string Car::getModel() const
{
    return _model;
}

Parking* Car::getCurrentParking() const
{
    return _current_parking;
}
void Car::setCarNumber(std::string &carNumber)
{
    _carNumber = carNumber;
    return;
}

std::string Car::getCarNumber() const
{
    return _carNumber;
}
