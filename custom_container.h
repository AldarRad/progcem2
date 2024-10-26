#pragma once

#include <memory>
#include <stdexcept>

// Пользовательский контейнер, поддерживающий работу с аллокатором
template <typename T, typename Alloc = std::allocator<T>>
class CustomContainer {
public:
    using allocator_type = Alloc;
    using iterator = T*;
    using const_iterator = const T*;

    CustomContainer(size_t capacity, const Alloc& alloc = Alloc())
        : size_(0), capacity_(capacity), alloc_(alloc) {
        data_ = alloc_.allocate(capacity_);
    }

    ~CustomContainer() {
        clear();
        alloc_.deallocate(data_, capacity_);
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            throw std::runtime_error("Exceeding capacity!");
        }
        alloc_.construct(data_ + size_, value);
        ++size_;
    }

    iterator begin() { return data_; }
    iterator end() { return data_ + size_; }
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

private:
    void clear() {
        for (size_t i = 0; i < size_; ++i) {
            alloc_.destroy(data_ + i);
        }
        size_ = 0;
    }

    T* data_;
    size_t size_;
    size_t capacity_;
    Alloc alloc_;
};

