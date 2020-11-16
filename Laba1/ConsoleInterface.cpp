



/*
// ЮФУ ИКТИБ МОП ЭВМ
// Неприн Михаил Андреевич, КТбо2-1
// Лабораторная работ №1, Вариант №14
// 05.09.2020
*/

#include "ConsoleInterface.h"
#include "CarCreator.h"
#include <iostream>

using namespace std;

ConsoleInterface::ConsoleInterface()
{
    const int parking_size = 20;
}


ConsoleInterface::~ConsoleInterface()
{
    delete parking;
    delete[] cars;
}


void ConsoleInterface::run()
{
    bool running = true;
    printMenuText();
    while (running)
    {

        int input;
        input = ReadInt();
        switch (input) {
        case 0: {
            running = false;
            break;
        }
        case 1: {
            int x = 0;
            bool doNotPark = false;
            do {
                doNotPark = false;
                cout << "Enter the number of the car you want to park.\n0 - to cancel.\n";
                printCarArray(cars);
                x = ReadInt();
                if (x > this->cars_amount)
                {
                    doNotPark = true;
                    cout << "Cars in total: " << this->cars_amount << endl;
                }
                else if (x < 0)
                {
                    doNotPark = true;
                    cout << "Wrong input.\n";
                }
                else if (x == 0) {
                    doNotPark = true;
                    break;
                }
                else if (cars[x - 1].isParked())
                {
                    doNotPark = true;
                    cout << "This car have already parked.\n";
                }
            } while (doNotPark);

            if (!doNotPark)
                cars[x - 1].park(*parking);
            cout << endl << "Parked cars:" << endl;
            printParkedCars(*parking);
            cout << endl;
            printMenuText();
            break;
        }

        case 2: {
            int x = 0;
            bool doNotPark = false;
            do {
                doNotPark = false;
                cout << "Enter the number of the car you want to unpark.\n0 - to cancel\n";
                printCarArray(cars);
                x = ReadInt();
                if (x > this->cars_amount)
                {
                    doNotPark = true;
                    cout << "Cars in total: " << this->cars_amount << endl;
                }
                else if (x < 0)
                {
                    doNotPark = true;
                    cout << "Wrong output\n";
                }
                else if (x == 0) {
                    doNotPark = true;
                    break;
                }
                else if (!cars[x - 1].isParked())
                {
                    doNotPark = true;
                    cout << "This car unparked\n";
                }
            } while (doNotPark);
            if (!doNotPark)
                cars[x - 1].unpark();
            cout << endl << "Parked cars: " << endl;
            printParkedCars(*parking);
            cout << endl;
            printMenuText();
            break;
        }


        case 3: {
            cout << "Parked cars: " << endl;
            printParkedCars(*parking);
            printMenuText();
            break;
        }

        case 4: {
            cout << "All cars: " << endl;
            printCarArray(cars);
            printMenuText();
            break;
        }
        case 5: {
            Car** all_cars = parking->getAllCars();
            cout << "Cars that have ever been on the park:" << endl;
            printCarArray(all_cars);
            printMenuText();
            break;
        }
        case 6: printMenuText(); break;
        }

    } // while (running)
}


void ConsoleInterface::printMenuText() {
    std::cout << "\nEnter 1 to park a car.\nEnter 2 to unpark a car.\n"
        "Enter 3 to print the list of all parked cars.\n"
        "Enter 4 to print the list of all cars.\n"
        "Enter 5 to print the list of cars that have ever been on the park.\n"
        "Enter 6 to print this text again.\n"
        "Enter 0 to exit.\n\n";
    return;
}


void ConsoleInterface::prompt() {
    std::cout << "$ ";
    return;
}


void ConsoleInterface::printCarArray(Car* array)
{
    for (int i = 0; i < this->cars_amount; ++i)
    {
        cout << "(" << array[i].getCarNumber() << ", " << array[i].getBrand() << ", " << array[i].getColor() << ")" << endl;
    }
}


void ConsoleInterface::printCarArray(Car** array)
{
    for (size_t i = 0; i < cars_amount; ++i)
    {
        if (array[i] != nullptr)
        cout << "(" << array[i]->getCarNumber() << ", " << array[i]->getBrand() << ", " << array[i]->getColor() << ")" << endl;
    }
}


void ConsoleInterface::printParkedCars(Parking& parking)
{
    Car** parked_cars;
    parked_cars = parking.getCurrentCars();
    printCarArray(parked_cars);
}

int ConsoleInterface::ReadInt()
{
    int a = 0;
    prompt();
    cin >> a;
    if (cin.fail())
    {
        do
        {
            prompt();
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
            cin >> a;
        } while (cin.fail());
    }
    return a;
}
