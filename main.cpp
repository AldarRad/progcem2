#include <iostream>
#include <map>
#include "custom_allocator.h"
#include "custom_container.h"


int factorial(int n) 
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() 
{
    std::map<int, int> map_std;
    for (int i = 0; i < 10; ++i) {
        map_std[i] = factorial(i);
    }

    std::cout << "Standard map contents:\n";
    for (const auto& pair : map_std) {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    std::map<int, int, std::less<int>, BlockAllocator<std::pair<const int, int>>> map_custom(BlockAllocator<std::pair<const int, int>>(10));
    for (int i = 0; i < 10; ++i) {
        map_custom[i] = factorial(i);
    }

    std::cout << "\nCustom map with block allocator contents:\n";   
    for (const auto& pair : map_custom) {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    CustomContainer<int> customContainer(10);
    for (int i = 0; i < 10; ++i) {
        customContainer.push_back(i);
    }


    for (auto val : customContainer) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    CustomContainer<int, BlockAllocator<int>> customContainerWithAlloc(10, BlockAllocator<int>(10));
    for (int i = 0; i < 10; ++i) {
        customContainerWithAlloc.push_back(i);
    }

    std::cout << "\nCustom container with block allocator contents:\n";
    for (auto val : customContainerWithAlloc) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
