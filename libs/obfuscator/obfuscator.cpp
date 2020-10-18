
#include <iostream>
#include "obfuscator.h"

namespace jp
{

Obfuscator::Obfuscator(Queue & q, Encoder & e) :
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
    while (run.load()){
        data = queue.pop();
        for (auto & text : data)
        {
            encoder.encode(text);
            std::cout<<text<<" ";
        }
    }
}

}

