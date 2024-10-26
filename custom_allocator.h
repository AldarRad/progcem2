#pragma once

#include <vector>
#include <cstdlib>
#include <new>
#include <stdexcept>

template <typename T>
class BlockAllocator {
public:
    using value_type = T;

    // Параметр rebind для совместимости с контейнерами STL
    template <typename U>
    struct rebind {
        using other = BlockAllocator<U>;
    };

    // Конструктор принимает размер блока
    explicit BlockAllocator(size_t blockSize)
        : blockSize_(blockSize), freeList_(nullptr), currentBlock_(nullptr), allocatedBlocks_(0) {}

    // Конструктор копирования
    template <typename U>
    BlockAllocator(const BlockAllocator<U>& other)
        : blockSize_(other.blockSize_), freeList_(nullptr), currentBlock_(nullptr), allocatedBlocks_(0) {}

    // Деструктор освобождает всю выделенную память
    ~BlockAllocator() {
        for (void* block : blocks_) {
            ::operator delete(block);
        }
    }

    // Выделение памяти
    T* allocate(size_t n) {
        if (n > blockSize_) {
            throw std::bad_alloc();
        }

        if (!freeList_) {
            expandPool();
        }

        T* result = freeList_;
        freeList_ = *reinterpret_cast<T**>(freeList_);
        return result;
    }

    // Освобождение памяти
    void deallocate(T* p, size_t n) {
        if (p) {
            *reinterpret_cast<T**>(p) = freeList_;
            freeList_ = p;
        }
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        new (p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* p) {
        p->~U();
    }

private:
    size_t blockSize_;               // Размер блока
    T* freeList_;                    // Указатель на список свободных блоков
    T* currentBlock_;                // Указатель на текущий блок памяти
    size_t allocatedBlocks_;         // Количество выделенных блоков
    std::vector<void*> blocks_;      // Хранение всех выделенных блоков

    void expandPool() {
        currentBlock_ = static_cast<T*>(::operator new(blockSize_ * sizeof(T)));
        blocks_.push_back(currentBlock_);

        for (size_t i = 0; i < blockSize_ - 1; ++i) {
            *reinterpret_cast<T**>(currentBlock_ + i) = currentBlock_ + i + 1;
        }
        *reinterpret_cast<T**>(currentBlock_ + blockSize_ - 1) = nullptr;
        freeList_ = currentBlock_;
        ++allocatedBlocks_;
    }

    // Объявление всех BlockAllocator<U> дружественными для доступа к приватным полям
    template <typename U>
    friend class BlockAllocator;
};
