#pragma once

#include <vector>
#include <cstdlib>
#include <new>
#include <stdexcept>

template <typename T>
class BlockAllocator {
public:
    using value_type = T;

    template <typename U>
    struct rebind 
    {
        using other = BlockAllocator<U>;
    };

    explicit BlockAllocator(size_t blockSize): blockSize_(blockSize), freeList_(nullptr), currentBlock_(nullptr), allocatedBlocks_(0) {}

    template <typename U>
    BlockAllocator(const BlockAllocator<U>& other): blockSize_(other.blockSize_), freeList_(nullptr), currentBlock_(nullptr), allocatedBlocks_(0) {}

    ~BlockAllocator() 
    {
        for (void* block : blocks_) {::operator delete(block);}
    }

    T* allocate(size_t n) 
    {
        if (n > blockSize_) 
        {
            throw std::bad_alloc();
        }

        if (!freeList_) 
        {
            expandPool();
        }

        T* result = freeList_;
        freeList_ = *reinterpret_cast<T**>(freeList_);
        return result;
    }

    void deallocate(T* p, size_t n) 
    {
        if (p) 
        {
            *reinterpret_cast<T**>(p) = freeList_;
            freeList_ = p;
        }
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* p) 
    {
        p->~U();
    }

private:
    size_t blockSize_;               
    T* freeList_;                    
    T* currentBlock_;                
    size_t allocatedBlocks_;         
    std::vector<void*> blocks_;      

    void expandPool() 
    {
        currentBlock_ = static_cast<T*>(::operator new(blockSize_ * sizeof(T)));
        blocks_.push_back(currentBlock_);

        for (size_t i = 0; i < blockSize_ - 1; ++i) 
        {
            *reinterpret_cast<T**>(currentBlock_ + i) = currentBlock_ + i + 1;
        }
        *reinterpret_cast<T**>(currentBlock_ + blockSize_ - 1) = nullptr;
        freeList_ = currentBlock_;
        ++allocatedBlocks_;
    }

    template <typename U>
    friend class BlockAllocator;
};
