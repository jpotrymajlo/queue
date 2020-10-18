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
    Queue<std::string> & queue;
    Encoder & encoder;
    std::thread readingThread;
    void readFromQueue();
    std::atomic<bool> run;
public:
    Obfuscator(Queue<std::string> &, Encoder &);
    virtual ~Obfuscator();
};

}


#endif