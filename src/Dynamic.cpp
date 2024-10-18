#include "Dynamic.h"
#include <stdexcept>

Dynamic::Dynamic() : data(nullptr), capacity(0), length(0) {}

Dynamic::~Dynamic() {
    delete[] data;
}

void Dynamic::resize(size_t new_capacity) {
    int* new_data = new int[new_capacity];
    for (size_t i = 0; i < length; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void Dynamic::push_back(int value) {
    if (length == capacity) {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        resize(new_capacity);
    }
    data[length++] = value;
}

void Dynamic::insert(size_t index, int value) {
    if (index > length) {
        throw std::out_of_range("Index out of range");
    }
    if (length == capacity) {
        resize(capacity * 2);
    }
    for (size_t i = length; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    length++;
}

void Dynamic::erase(size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < length - 1; ++i) {
        data[i] = data[i + 1];
    }
    length--;
}

size_t Dynamic::size() const {
    return length;
}

int& Dynamic::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void Dynamic::print() const {
    for (size_t i = 0; i < length; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
