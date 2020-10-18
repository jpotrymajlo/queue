#ifndef __OBFUSCATOR_H__
#define __OBFUSCATOR_H__

#include <thread>
#include <atomic>
#include "queue/queue.h"
#include "encoder.h"

namespace jp 
{
/**
 * Data consumer. It handles passed data depending on algotyhm passed in the constructor.
 * It receives data from separate thread reading queue passed as Obfuscator constructor parameter
 * Encoded data are sent to standard output
 */
class Obfuscator
{
private:
    Queue<std::string> & queue;
    Encoder & encoder;
    std::thread readingThread;
    void readFromQueue(); /* reading thread */
    std::atomic<bool> run;
public:
    /* Encoder parameter is used for passing algorytm to obfuscate (cipher) data */
    Obfuscator(Queue<std::string> &, Encoder &);
    virtual ~Obfuscator();
};

}


#endif