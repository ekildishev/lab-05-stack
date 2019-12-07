// Copyright 2018 Your Name <ekildisev@gmail.com>

#pragma once

#include <utility>
#include <exception>

template<typename T>
class stack {
protected:
    struct element {
        T data;
        element *next;
    };
    element *stackHead = nullptr;
public:
    stack() = default;

    virtual void push(T &&value) {
        auto elem = new element{std::forward<T>(value), stackHead};
        stackHead = elem;
    }

    const T &head() const {
        if (stackHead == nullptr) {
            throw std::exception();
        } else {
            return stackHead->data;
        }
    }

    virtual ~stack() = default;
};
