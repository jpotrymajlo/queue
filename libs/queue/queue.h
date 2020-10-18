#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <memory>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>

namespace jp {

class Queue 
{
    struct node 
    {
        std::unique_ptr<node> next;
        std::string value;
        node(std::string s) :
            value {s},
            next {nullptr}
        {
        }
    };
private:
     std::unique_ptr<node> head;
     node* tail;
     std::condition_variable dataInQueue;
     std::mutex queueMutex;

public:
     Queue();
     virtual ~Queue();

     void push(std::string s);
     std::vector<std::string> pop();
     bool isEmpty();
};

}

#endif