#include "input.h"
#include <iostream>

namespace jp 
{

Input::Input(Queue<std::string> & q) :
    queue {q},
    inputThread {&Input::readFromStdInput, this}
{

}

Input::~Input()
{
    if (inputThread.joinable())
    {
        inputThread.join();
    }
}

void Input::readFromStdInput(void)
{
    while (!std::cin.eof())
    {
        std::string value;
        std::cin>>value;
        queue.push(std::move(value));
    }
}

void Input::waitUntilFinished()
{
    if (inputThread.joinable())
    {
        inputThread.join();
    }
}

}
