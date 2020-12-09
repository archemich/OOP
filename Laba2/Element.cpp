#include "Element.h"

Element::Element() : input{ 0,0 }, output(0), isFirst(0)
{
}


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