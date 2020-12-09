#include "ui.h"
#include "Scheme.h"
#include <iostream>
#include <Windows.h>


using std::cout; using std::endl;

UI::UI(): running {false}
{
}

void UI::run()
{
    running = true;
    Scheme scheme;
    bool result = 0;
    while (running)
    {
        result = scheme.doStep();
        cout << result << endl;
        scheme.genNewInput();
        Sleep(100);
    }
}