#ifndef __INPUT_H__
#define __INPUT_H__

#include <thread>
#include "queue/queue.h"


namespace jp
{

class Input 
{
private:
    Queue<std::string> & queue;
    std::thread inputThread;
    void readFromStdInput();
public:
    Input(Queue<std::string> &);
    virtual ~Input();
    void waitUntilFinished();


};

}

#endif