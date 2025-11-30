#include <iostream>
#include "ThreeByteInt.h"
#include "Exceptions.h"

void runTests(); // from Tests.cpp

int main() {
    runTests();

    std::cout << "\n=== Manual demo ===\n";

    ThreeByteInt x, y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;

    try {
        std::cout << "x + y = " << (x + y) << "\n";
        std::cout << "x - y = " << (x - y) << "\n";
        std::cout << "x * y = " << (x * y) << "\n";
        std::cout << "x / y = " << (x / y) << "\n";
    } catch (ThreeByteException& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    unsigned int n;
    std::cout << "Enter power n: ";
    std::cin >> n;

    try {
        std::cout << "x^n = " << x.pow(n) << "\n";
    } catch (ThreeByteException& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
