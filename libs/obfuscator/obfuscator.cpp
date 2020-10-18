
#include <iostream>
#include "obfuscator.h"

namespace jp
{

Obfuscator::Obfuscator(Queue<std::string> & q, Encoder & e) :
    queue {q},
    encoder {e},
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
    while (run.load() || !queue.isEmpty()) //even if destructor is called we want to 
                                           //read all data from queue
    {
        data = queue.pop();
        for (auto & text : data)
        {
            encoder.encode(text);
            std::cout<<text<<" ";
        }
    }
}

}

