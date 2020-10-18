#include "input.h"
#include <iostream>

namespace jp 
{

Input::Input(Queue & q) :
    queue {q},
    inputThread {&Input::readFromStdInput, this}
{

}

Input::~Input()
{
    inputThread.join();
}

void Input::readFromStdInput(void)
{
    while (!std::cin.eof())
    {
        std::string value;
        std::cin>>value;
        queue.push(value);
    }
}

}
