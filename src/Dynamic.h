#pragma once

#include <iostream>

class Dynamic {
private:
    int* data;
    size_t capacity;
    size_t length;

    void resize(size_t new_capacity);

public:
    Dynamic();
    ~Dynamic();

    void push_back(int value);
    void insert(size_t index, int value);
    void erase(size_t index);
    size_t size() const;
    int& operator[](size_t index);
    void print() const;
};


