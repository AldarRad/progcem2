#include "Single.h"
#include <stdexcept>

Single::Node::Node(int value) : data(value), next(nullptr) {}

Single::Single() : head(nullptr), length(0) {}

Single::~Single() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Single::push_back(int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    length++;
}

void Single::insert(size_t index, int value) {
    if (index > length) {
        throw std::out_of_range("Index out of range");
    }
    Node* new_node = new Node(value);
    if (index == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    length++;
}

void Single::erase(size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    length--;
}

size_t Single::size() const {
    return length;
}

void Single::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
