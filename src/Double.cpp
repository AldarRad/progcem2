#include "Double.h"
#include <stdexcept>

Double::Node::Node(int value) : data(value), next(nullptr), prev(nullptr) {}

Double::Double() : head(nullptr), tail(nullptr), length(0) {}

Double::~Double() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Double::push_back(int value) {
    Node* new_node = new Node(value);
    if (tail == nullptr) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    length++;
}

void Double::insert(size_t index, int value) {
    if (index > length) {
        throw std::out_of_range("Index out of range");
    }
    Node* new_node = new Node(value);
    if (index == 0) {
        new_node->next = head;
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
        if (length == 0) {  // если вставляем в пустой список
            tail = new_node;
        }
    } else if (index == length) {
        push_back(value);  // вставка в конец
    } else {
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        new_node->next = current;
        new_node->prev = current->prev;
        if (current->prev) {
            current->prev->next = new_node;
        }
        current->prev = new_node;
    }
    length++;
}

void Double::erase(size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;  // если удаляем последний элемент
        }
        delete temp;
    } else {
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;  // если удаляем последний элемент
        }
        delete current;
    }
    length--;
}

size_t Double::size() const {
    return length;
}

void Double::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
