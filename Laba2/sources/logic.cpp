#include "../headers/logic.h"
#include <random>


Element::Element(): input {0,0}, output (0), isFirst (0)
{}


void Element::setInput(bool input)
{
    if (isFirst) {
        this->input[0] = input;
    }
    else {
        this->input[1] = input;
    }
    isFirst = !isFirst; 
    return;
}


bool Element::getOutput()
{
    return output;
}


bool And::produceOutput()
{
    return output = (input[0] && input [1]);
}

bool Or::produceOutput()
{
    return output = (input[0] || input [1]);
}


Scheme::Scheme(): n{10}, output {}, path{
    {0,0,1,1,0,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},
    {0,0,0,1,1,1,1,0,0,0},
    {0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0}
}
{
    for (size_t i = 0; i < n; ++i)
    {
        bool r = rand() % 2;
        if (r) {
            logics[i] = new Or;
        }
        else {
            logics[i] = new And;
        }
    }
    

}


Scheme::~Scheme()
{
    delete[](logics);
}


bool Scheme::doStep()
{
    for (size_t i = 0; i < n; ++i) {
        logics[i]->produceOutput();
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; j++) {
            if (path [i][j]) {
                logics[j]->setInput(logics[i]->getOutput());
            }
        }
    }
    return output = logics[9]->getOutput();
}


bool Scheme::getOutput()
{
    return output;
}


void Scheme::genNewInput()
{
    logics[0]->setInput(rand()%2);
    logics[0]->setInput(rand()%2);
    logics[1]->setInput(rand()%2);
    logics[1]->setInput(rand()%2);

}