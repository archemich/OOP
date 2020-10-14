/*
// ЮФУ ИКТИБ МОП ЭВМ
// Неприн Михаил Андреевич, КТбо2-1
// Лабораторная работ №1, Вариант №14
// 05.09.2020
*/

#include "interface.h"
#include <iostream>

using namespace std;

Interface::Interface()
{
    const int parking_size = 20;
    bool running = true;
    Parking parking(parking_size);
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
            bool doNotPark=false;
            do{
                doNotPark=false;
                cout << "Введите номер машины, которую нужно поставить на парковку.\n0 - чтобы отменить действие\n";
                printCarArray(cars);
                x = ReadInt();
                if (x > this->cars_amount)
                {
                    doNotPark = true;
                    cout << "Машин всего " << this->cars_amount << endl;
                }
                else if (x < 0)
                {
                    doNotPark = true;
                    cout << "Неверный ввод\n";
                }
                else if (x == 0){
                    doNotPark = true;
                    break;
                }
                else if (cars[x-1].isParked())
                {
                    doNotPark = true;
                    cout << "Эта машина уже припаркована\n";
                }
            }while (doNotPark);

            if (!doNotPark)
                cars[x-1].park(parking);
            cout << endl << "Припаркованные машины:" << endl;
            printParkedCars(parking);
            cout << endl;
            printMenuText();
            break;
            }

        case 2: {
            int x = 0;
            bool doNotPark=false;
            do{
               doNotPark = false;
               cout << "Введите номер машины, которую нужно убрать с парковки.\n0 - чтобы отменить действие\n";
               printCarArray(cars);
               x = ReadInt();
               if (x > this->cars_amount)
               {
                   doNotPark = true;
                   cout << "Машин всего " << this->cars_amount << endl;
               }
               else if (x < 0)
               {
                   doNotPark = true;
                   cout << "Неверный ввод\n";
               }
               else if (x == 0) {
                   doNotPark = true;
                   break;
               }
               else if (!cars[x-1].isParked())
               {
                   doNotPark = true;
                   cout << "Эта машина не на парковке\n";
               }
               }while (doNotPark);
            if (!doNotPark)
                cars[x-1].unpark();
            cout << endl << "Припаркованные машины:" << endl;
            printParkedCars(parking);
            cout << endl;
            printMenuText();
            break;
            }


        case 3: {
            cout << "Припаркованные машины:" << endl;
            printParkedCars(parking);
            printMenuText();
            break;
            }

        case 4: {
            cout << "Все машины:" << endl;
            printCarArray(cars);
            printMenuText();
            break;
        }
        case 5: {
            Car** all_cars = parking.getAllCars();
            cout << "Машины зафиксированные на парковке:" << endl;
            printCarArray(all_cars);
            break;
        }
        case 6: printMenuText(); break;
        }

    } // while (running)
}


Interface::~Interface()
{
    delete[] cars;
}

void Interface::printMenuText() {
    std::cout << "\nВведите 1, чтобы поставить на парковку машину.\nВведите 2, чтобы убрать машину с парковки.\n"
                 "Введите 2, чтобы добавить новый автомобиль\n"
                 "Введите 3, чтобы вывести список всех припаркованных автомобилей.\n"
                 "Введите 4, чтобы вывести список всех автомобилей\n"
                 "Введите 5, чтобы вывести список всех автомобилей, зафиксированных на парковке\n"
                 "Введите 6, чтобы повторить этот текст\n"
                 "Введите 0, чтобы выйти.\n\n";
    return;
}


void Interface::prompt() {
    std::cout << "$ ";
    return;
}


void Interface::printCarArray(Car* array)
{
    for (int i = 0; i < this->cars_amount ; ++i)
    {
        cout << "(" << array[i].getCarNumber() << ", " << array[i].getModel() << ", " << array[i].getColor() << ")" << endl;
    }
}


void Interface::printCarArray(Car** array)
{
    for (size_t i = 0; array[i] != nullptr; ++i)
    {
        cout << "(" << array[i]->getCarNumber() << ", " << array[i]->getModel() << ", " << array[i]->getColor() << ")" << endl;
    }
}


void Interface::printParkedCars(Parking &parking)
{
    Car **parked_cars;
    parked_cars = parking.getParkedCars();
    printCarArray(parked_cars);
}

int Interface::ReadInt()
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
        }while (cin.fail());
    }
    return a;
}
