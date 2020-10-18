#ifndef __INPUT_H__
#define __INPUT_H__

#include <thread>
#include "queue/queue.h"


namespace jp
{
/* Class reads the data from standard input in separate thread. Reading thread reads
 * data from queue passed a Input constructor parameter
 */
class Input 
{
private:
    Queue<std::string> & queue;
    std::thread inputThread;
    void readFromStdInput(); /* reading thread */
public:
    Input(Queue<std::string> &);
    virtual ~Input();
    void waitUntilFinished(); /* blocking function. It waits until all data are read from standard input */


};

}

#endif