#include "ConsoleInterface.h"
#include "ShapeFactory.h"
#include "Operations.h"
#include <iostream>

enum commands { _EXIT, _CREATESHAPE, _ISINTERSECTED, _ISINCLUDES, _SHOWSHAPES, _PRINTMENUTEXT };

void ConsoleInterface::run()
{
    bool running = true;
    int shapes_max = 10;
    Shape** shapes = new Shape * [shapes_max] {nullptr};
    int sh_counter = 0;
    printMenuText();
    while (running)
    {

        int input;
        input = ReadInt();
        switch (input) {
        case _EXIT:
            running = false;
            break;

        case _CREATESHAPE: {
            char cd;
            bool ok = false;
            while (!ok) 
            {
                std::cout << "Choose a shape to create ('S' - Square, 'T' - Triangle): ";
                std::cin >> cd;
                cd = toupper(cd);
                if (cd == '0')
                {
                    break;
                }
                if (cd != 'S' && cd != 'T') {
                    ok = false;
                }
                else {
                    ok = true;
                }
                
                Point point; 
                std::cout << " Write x: " << std::endl;
                point.x = ReadDouble();
                std::cout << " Write y: " << std::endl;
                point.y = ReadDouble();
                double sides[3]{NULL};
                std::cout << "Write edges " << std::endl; 
                std::cout << "Write A: " << std::endl;
                sides[0] = ReadDouble();
                if (cd == 'T') 
                {
                    std::cout << "Write B: " << std::endl;
                    sides[1] = ReadDouble();
                    std::cout << "Write C: " << std::endl;
                    sides[2] = ReadDouble();
                }
                Shape *nsh = ShapeFactory::CreateShape(cd, point, sides);
                if (nsh != nullptr)
                {
                    shapes[sh_counter++] = nsh;
                    std::cout << nsh->getName() << " Created";
                }
                else
                {
                    std::cout << "Shape not created";

                }
                std::cout << std::endl;
            }
            break;
        }
        case _ISINTERSECTED: {
            int f, s;
            std::cout << "Write first shape: " << std::endl;
            f = ReadInt();
            if (f == 0)
                break;
            std::cout << "Write second shape: " << std::endl;
            s = ReadInt();
            if (f == 0)
                break;
            if ((shapes[f-1] != nullptr) && (shapes[s-1] != nullptr)) {
                if (Operations::isIntersected(*shapes[f - 1], *shapes[s - 1]))
                {
                    std::cout << "They are intersect" << std::endl;
                }
                else
                {
                    std::cout << "They are not intersect" << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid shape" << std::endl;
            }
            printMenuText();
            break;
        }
        case _ISINCLUDES: {
            int f, s;
            std::cout << "Write first shape: " << std::endl;
            f = ReadInt();
            if (f == 0)
                break;
            std::cout << "Write second shape: " << std::endl;
            s = ReadInt();
            if (f == 0)
                break;
            if (Operations::isIncluded(*shapes[f - 1], *shapes[s - 1]))
            {
                std::cout << shapes[f-1]->getName() << " include " << shapes[s - 1]->getName() << std::endl;
            }
            else
            {
                std::cout << shapes[f - 1]->getName() << " not include " << shapes[s - 1]->getName() << std::endl;
            }
            printMenuText();
            break;
        }
        case _SHOWSHAPES: {
            for (int i = 0; (i < shapes_max); ++i)
            {
                if (shapes[i] != nullptr)
                {
                    std::cout << i + 1 << ". " << shapes[i]->getName() << std::endl;
                }
            }
            break;
        }
        case _PRINTMENUTEXT: {
            printMenuText();
            break;
        }
        } // while (running)
    }
}

void ConsoleInterface::printMenuText()
{
    std::cout << _CREATESHAPE << " - Create Shape\n"
        << _ISINTERSECTED << " - To check if shapes are intersect\n"
        << _ISINCLUDES << " - To check if first shape includes second\n"
        << _SHOWSHAPES << " - To print all shapes\n"
        << _PRINTMENUTEXT << " - To print this text\n"
        << _EXIT << " - To exit\n";

    return;
}

void ConsoleInterface::prompt() 
{
    std::cout << "$ ";
    return;
}

int ConsoleInterface::ReadInt()
{
    using std::cin;
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

double ConsoleInterface::ReadDouble()
{
    using std::cin;
    double a = 0;
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
