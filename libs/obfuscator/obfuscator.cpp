
#include <iostream>
#include "obfuscator.h"

namespace jp
{

Obfuscator::Obfuscator(Queue & q) :
    queue {q},
    readingThread {&Obfuscator::readFromQueue, this }
{
}

Obfuscator::~Obfuscator()
{
    run.store(false);
    readingThread.join();
}

void Obfuscator::readFromQueue(void)
{
    run.store(true);
    std::vector<std::string> data;
    while (run.load()){
        data = queue.pop();
        std::cout<<data.size()<<std::endl;
        for (auto & text : data)
        {
        }
    }
}

}

