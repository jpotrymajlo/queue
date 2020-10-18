#include <chrono>
#include "queue.h"


namespace jp {

using namespace std::chrono_literals;

Queue::Queue() :
    head(nullptr),
    tail(nullptr)
{

}

Queue::~Queue()
{
    std::unique_lock<std::mutex> popLock (queueMutex);
    while (head != nullptr)
    {
        head = std::move(head->next);
    }
}

void Queue::push(std::string s)
{
    std::unique_lock<std::mutex> pushLock (queueMutex);
    auto tmp = std::make_unique<node>(s);

    if (tmp != nullptr){
        if (head == nullptr)
        {
            head = std::move(tmp);
            tail = head.get();
        }
        else
        {
            node* new_tail = tmp.get();
            tail->next = std::move(tmp);
            tail = new_tail;
        }
        dataInQueue.notify_one();
    }
}

std::vector<std::string> Queue::pop()
{
    std::unique_lock<std::mutex> popLock (queueMutex);
    std::vector<std::string> result;

    while (head == nullptr) 
    {
        auto timeout = std::chrono::system_clock::now() + 100ms;
        if (std::cv_status::timeout == dataInQueue.wait_until(popLock, timeout))
        {
           return result;
        }
    }
   
    while (head != nullptr)
    {
        result.push_back(head->value);
        head = std::move(head->next);
    }
    return result;
}

bool Queue::isEmpty()
{
    std::unique_lock<std::mutex> queueLock (queueMutex);
    return head == nullptr ? true : false;
}

}
