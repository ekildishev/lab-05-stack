#pragma once

#include "stack.hpp"

template<typename T>
class stackArgs : public stack<T> {
public:
    template<typename ... Args>
    void push_emplace(Args &&... value) {
        auto temp = stack<T>::stackHead;
        stack<T>::stackHead = new typename stack<T>::element{{std::forward<Args>(value)...}, temp};
    }

    T pop() {
        if (stack<T>::stackHead == nullptr) {
            throw std::exception();
        } else {
            auto temp = stack<T>::stackHead->data;
            stack<T>::stackHead = stack<T>::stackHead->next;
            return temp;
        }
    }
};