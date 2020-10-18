#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <memory>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <iostream>

namespace jp {

/*
 * Queue parametrized with the type. Methods operating on queue are thread safe
 */
template<typename T>
class Queue 
{
    //Node structure for opaquing data stored in queue
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
        //deleting all nodes before destroying Queue
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
/*
 * Addin data to the queue. It handles both rvalues and lvalues
 */
template<typename T>
void Queue<T>::push(T && s)
{
    std::unique_lock<std::mutex> pushLock (queueMutex);
    //depeding on reference type (rvalue or lvalue) data are moved or copied
    auto tmp = std::make_unique<Node<T>>(std::forward<T>(s));

    if (tmp != nullptr){
        if (head == nullptr) // queue is empty 
        {
            head = std::move(tmp);
            tail = head.get();
        }
        else // queue has elements 
        {
            // add data to the end (tail) of the queue
            auto new_tail = tmp.get();
            tail->next = std::move(tmp);
            tail = new_tail;
        }
        // notify reading thread 
        dataInQueue.notify_one();
    }
}

/* 
 * Gets and remove data from the beginning (head) of the queue
 * Result is return as a std::vector. RVO (return value optimization)
 * allows on returning data without copying
 */
template<typename T>
std::vector<T> Queue<T>::pop()
{
    std::unique_lock<std::mutex> popLock (queueMutex);
    std::vector<T> result;

    while (head == nullptr) 
    {
        // wait for data available in the queue
        // If timeout is triggered empty array is returned
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
/*
 * return true if the queue is empty
 */
template<typename T>
bool Queue<T>::isEmpty()
{
    std::unique_lock<std::mutex> queueLock (queueMutex);
    return head == nullptr ? true : false;
}


}

#endif