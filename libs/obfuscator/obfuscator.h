#ifndef __OBFUSCATOR_H__
#define __OBFUSCATOR_H__

#include <thread>
#include <atomic>
#include "queue/queue.h"
#include "encoder.h"

namespace jp 
{

class Obfuscator
{
private:
    Queue & queue;
    Encoder & encoder;
    std::thread readingThread;
    void readFromQueue();
    std::atomic<bool> run;
public:
    Obfuscator(Queue &, Encoder &);
    virtual ~Obfuscator();
};

}


#endif