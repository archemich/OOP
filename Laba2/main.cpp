/*
// ЮФУ ИКТИБ МОП ЭВМ
// Неприн Михаил Андреевич, КТбо2-1
// Лабораторная работ №2, Вариант №10
// 15.10.2020
*/


#include "ui.h"
#include <random>
#include <ctime>

int main()
{
    srand(time(0));
    UI ui;
    ui.run();
    return 0;
}