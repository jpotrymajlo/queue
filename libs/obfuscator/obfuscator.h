#ifndef __OBFUSCATOR_H__
#define __OBFUSCATOR_H__

#include <thread>
#include <atomic>
#include "queue/queue.h"

namespace jp 
{

class Obfuscator
{
private:
    Queue & queue;
    std::thread readingThread;
    void readFromQueue();
    std::atomic<bool> run;
public:
    Obfuscator(Queue&);
    virtual ~Obfuscator();
};

}


#endif