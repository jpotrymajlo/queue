#include "queue.h"
#include <iostream>

namespace jp {

queue::queue() :
    head(nullptr),
    tail(nullptr)
{

}

queue::~queue()
{

}

void queue::push(std::string s)
{
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
    }
}

std::vector<std::string> queue::pop()
{
    std::vector<std::string> result;
    while (head != nullptr)
    {
        result.push_back(head->value);
        head = std::move(head->next);
    }
    return result;
}

}
