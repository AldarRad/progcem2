#pragma once
#include <iostream>

class Single {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value);
    };

    Node* head;
    size_t length;

public:
    Single();
    ~Single();

    void push_back(int value);
    void insert(size_t index, int value);
    void erase(size_t index);
    size_t size() const;
    void print() const;
};


