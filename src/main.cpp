#include <iostream>
#include "Dynamic.h"
#include "Double.h"
#include "Single.h"

void testDynamicArray() {
    std::cout << "Testing DynamicArray:" << std::endl;

    Dynamic array;

    // 2. Добавление в контейнер десяти элементов (0, 1 … 9).
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }

    // 3. Вывод содержимого контейнера на экран.
    array.print(); // Ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.

    // 4. Вывод размера контейнера на экран.
    std::cout << "Size: " << array.size() << std::endl; // Ожидаемый результат: 10.

    // 5. Удаление третьего, пятого и седьмого элементов.
    array.erase(2); // Удалить элемент с индексом 2 (третий элемент)
    array.erase(3); // Удалить элемент с индексом 3 (пятый элемент)
    array.erase(4); // Удалить элемент с индексом 4 (седьмой элемент)

    // 6. Вывод содержимого контейнера на экран.
    array.print(); // Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9.

    // 7. Добавление элемента 10 в начало контейнера.
    array.insert(0, 10);
    array.print(); // Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9.

    // 9. Добавление элемента 20 в середину контейнера.
    array.insert(4, 20); // Вставка элемента 20 на позицию 4.
    array.print(); // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9.

    // 11. Добавление элемента 30 в конец контейнера.
    array.push_back(30);
    array.print(); // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30.

    std::cout << "-------------------" << std::endl;
}

void testDoublyLinkedList() {
    std::cout << "Testing DoublyLinkedList:" << std::endl;

    Double list;

    // 2. Добавление в контейнер десяти элементов (0, 1 … 9).
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }

    // 3. Вывод содержимого контейнера на экран.
    list.print(); // Ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.

    // 4. Вывод размера контейнера на экран.
    std::cout << "Size: " << list.size() << std::endl; // Ожидаемый результат: 10.

    // 5. Удаление третьего, пятого и седьмого элементов.
    list.erase(2); // Удалить элемент с индексом 2 (третий элемент)
    list.erase(3); // Удалить элемент с индексом 3 (пятый элемент)
    list.erase(4); // Удалить элемент с индексом 4 (седьмой элемент)

    // 6. Вывод содержимого контейнера на экран.
    list.print(); // Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9.

    // 7. Добавление элемента 10 в начало контейнера.
    list.insert(0, 10);
    list.print(); // Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9.

    // 9. Добавление элемента 20 в середину контейнера.
    list.insert(4, 20); // Вставка элемента 20 на позицию 4.
    list.print(); // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9.

    // 11. Добавление элемента 30 в конец контейнера.
    list.push_back(30);
    list.print(); // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30.

    std::cout << "-------------------" << std::endl;
}

void testSinglyLinkedList() {
    std::cout << "Testing SinglyLinkedList:" << std::endl;

    Single list;

    // 2. Добавление в контейнер десяти элементов (0, 1 … 9).
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }

    // 3. Вывод содержимого контейнера на экран.
    list.print(); // Ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.

    // 4. Вывод размера контейнера на экран.
    std::cout << "Size: " << list.size() << std::endl; // Ожидаемый результат: 10.

    // 5. Удаление третьего, пятого и седьмого элементов.
    list.erase(2); // Удалить элемент с индексом 2 (третий элемент)
    list.erase(3); // Удалить элемент с индексом 3 (пятый элемент)
    list.erase(4); // Удалить элемент с индексом 4 (седьмой элемент)

    // 6. Вывод содержимого контейнера на экран.
    list.print(); // Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9.

    // 7. Добавление элемента 10 в начало контейнера.
    list.insert(0, 10);
    list.print(); // Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9.

    // 9. Добавление элемента 20 в середину контейнера.
    list.insert(4, 20); // Вставка элемента 20 на позицию 4.
    list.print(); // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9.

    // 11. Добавление элемента 30 в конец контейнера.
    list.push_back(30);
    list.print(); // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30.

    std::cout << "-------------------" << std::endl;
}

int main() {
    // Тестируем динамический массив
    testDynamicArray();

    // Тестируем двусвязный список
    testDoublyLinkedList();

    // Тестируем односвязный список
    testSinglyLinkedList();

    return 0;
}