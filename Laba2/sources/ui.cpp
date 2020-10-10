#include "../headers/ui.h"
#include "../headers/logic.h"
#include <iostream>
#include <unistd.h>


using std::cout, std::endl;

UI::UI(): running {true}
{
    Scheme scheme;
    bool result = 0;
    while (running)
    {
        result = scheme.doStep();
        cout << result << endl;
        scheme.genNewInput();
        usleep(100000);
    }
    return;
}