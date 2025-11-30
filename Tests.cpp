#include "ThreeByteInt.h"
#include <iostream>

void runTests() {
    std::cout << "Running tests...\n";

    // Тест створення
    try {
        ThreeByteInt a(5000000); // за межами
        std::cout << "ERROR: Overflow not detected!\n";
    } catch (...) {
        std::cout << "OK: Overflow detected on constructor\n";
    }

    // Тест +
    try {
        ThreeByteInt a((1 << 23) - 2);
        ThreeByteInt b(5);
        auto c = a + b;
        std::cout << "ERROR: overflow not detected\n";
    } catch (OverflowException&) {
        std::cout << "OK: addition overflow detected\n";
    }

    // Тест ділення на 0
    try {
        ThreeByteInt x(10), y(0);
        auto z = x / y;
        std::cout << "ERROR: division by zero not detected\n";
    } catch (DivisionByZeroException&) {
        std::cout << "OK: division by zero detected\n";
    }

    // Тест pow()
    try {
        ThreeByteInt x(1000);
        auto r = x.pow(4); // 1000^4 буде переповнення
        std::cout << "ERROR: overflow in pow not detected\n";
    } catch (OverflowException&) {
        std::cout << "OK: pow overflow detected\n";
    }

    std::cout << "All tests completed.\n";
}
