#pragma once

#include <iostream>

class Double {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value);
    };

    Node* head;
    Node* tail;
    size_t length;

public:
    Double();
    ~Double();

    void push_back(int value);
    void insert(size_t index, int value);
    void erase(size_t index);
    size_t size() const;
    void print() const;
};

