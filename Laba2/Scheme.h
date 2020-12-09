#pragma once
#include "Element.h"

class Scheme
{
public:
    Scheme();
    ~Scheme();
    bool doStep();
    bool getOutput();
    void genNewInput();


private:
    const int n;
    Element* logics[10];
    bool output;
    short int path[10][10];
};

