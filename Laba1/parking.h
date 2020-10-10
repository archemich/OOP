#ifndef PARKING_H
#define PARKING_H

#include "car.h"
#include <string>
class Car;

class Parking
{
public:
    Parking(int parking_spaces);
    ~Parking();
    void saveNewCar(Car &car);
    void park(Car &car);
    void unpark(Car &car);
    bool isCarParked(Car &car);
    Car** getParkedCars();
    Car** getAllCars();

private:
    static const int all_cars_multiplyer = 100;
    const int parking_spaces;
    int _all_cars_iter = 0;
    int _current_cars_iter = 0;
    Car **_all_cars = new Car*[parking_spaces * all_cars_multiplyer]{nullptr};
    Car **_current_cars = new Car*[parking_spaces]{nullptr};
};

#endif // PARKING_H
