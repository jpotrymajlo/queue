#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <memory>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <iostream>

namespace jp {

template<typename T>
class Queue 
{
    template<typename U>
    struct Node 
    {
        std::unique_ptr<Node<U>> next;
        U value;
        Node(U && s) :
            value {std::forward<U>(s)},
            next {nullptr}
        {
        }
    };
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    std::condition_variable dataInQueue;
    std::mutex queueMutex;

public:
    Queue() : 
        head(nullptr),
        tail(nullptr) {}

    virtual ~Queue()
    {
        std::unique_lock<std::mutex> popLock (queueMutex);
        while (head != nullptr)
        {
            head = std::move(head->next);
        }
    }

     void push(T && s);
     std::vector<T> pop();
     bool isEmpty();
};

using namespace std::chrono_literals;


template<typename T>
void Queue<T>::push(T && s)
{
    std::unique_lock<std::mutex> pushLock (queueMutex);
    auto tmp = std::make_unique<Node<T>>(std::forward<T>(s));

    if (tmp != nullptr){
        if (head == nullptr)
        {
            head = std::move(tmp);
            tail = head.get();
        }
        else
        {
            auto new_tail = tmp.get();
            tail->next = std::move(tmp);
            tail = new_tail;
        }
        dataInQueue.notify_one();
    }
}

template<typename T>
std::vector<T> Queue<T>::pop()
{
    std::unique_lock<std::mutex> popLock (queueMutex);
    std::vector<T> result;

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
        result.push_back(std::move(head->value));
        head = std::move(head->next);
    }
    return result;
}

template<typename T>
bool Queue<T>::isEmpty()
{
    std::unique_lock<std::mutex> queueLock (queueMutex);
    return head == nullptr ? true : false;
}


}

#endif