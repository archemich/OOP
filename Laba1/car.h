#ifndef CAR_H
#define CAR_H
#include "parking.h"
#include <string>
class Parking;

class Car
{
public:
    Car();
    Car(std::string carNumber, std::string model, std::string color);
    ~Car();
    bool operator== (const Car &other);
    void park(Parking &parking);
    void unpark();

    void setCarNumber(std::string& carNumber);
    std::string getCarNumber() const;
    std::string getModel() const;
    void setColor(std::string& color);
    std::string getColor() const;
    Parking* getCurrentParking() const;
    bool isParked();

private:
    std::string _carNumber;
    const std::string _model;
    std::string _color;
    Parking *_current_parking;
};

#endif // CAR_H
