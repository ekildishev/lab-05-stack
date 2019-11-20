#pragma once

#include "stack.hpp"

template <typename T>
class usualStack : public stack<T>
{
public:
    void push(const T& value)
    {
        auto elem = new typename stack<T>::element{value, stack<T>::stackHead};
        stack<T>::stackHead = elem;
    }

    void push(T&& arg) override {
        stack<T>::push(std::forward<T>(arg));
    }

    void pop()
    {
        if(stack<T>::stackHead == nullptr)
        {
            throw std::exception();
        }
        else
        {
            stack<T>::stackHead = stack<T>::stackHead->next;
        }
    }
};