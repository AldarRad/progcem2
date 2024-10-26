#include <iostream>
#include <map>
#include "custom_allocator.h"
#include "custom_container.h"

// Функция для вычисления факториала
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    // 1. Создание std::map<int, int> и заполнение
    std::map<int, int> map_std;
    for (int i = 0; i < 10; ++i) {
        map_std[i] = factorial(i);
    }

    // 2. Вывод содержимого map_std
    std::cout << "Standard map contents:\n";
    for (const auto& pair : map_std) {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    // 3. Создание std::map с блочным аллокатором
    std::map<int, int, std::less<int>, BlockAllocator<std::pair<const int, int>>> map_custom(BlockAllocator<std::pair<const int, int>>(10));
    for (int i = 0; i < 10; ++i) {
        map_custom[i] = factorial(i);
    }

    // 4. Вывод содержимого map_custom
    std::cout << "\nCustom map with block allocator contents:\n";
    for (const auto& pair : map_custom) {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    // 5. Создание пользовательского контейнера для int
    CustomContainer<int> customContainer(10);
    for (int i = 0; i < 10; ++i) {
        customContainer.push_back(i);
    }

    // 6. Вывод содержимого customContainer
    std::cout << "\nCustom container contents:\n";
    for (auto val : customContainer) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // 7. Создание пользовательского контейнера с блочным аллокатором
    CustomContainer<int, BlockAllocator<int>> customContainerWithAlloc(10, BlockAllocator<int>(10));
    for (int i = 0; i < 10; ++i) {
        customContainerWithAlloc.push_back(i);
    }

    // 8. Вывод содержимого customContainerWithAlloc
    std::cout << "\nCustom container with block allocator contents:\n";
    for (auto val : customContainerWithAlloc) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
