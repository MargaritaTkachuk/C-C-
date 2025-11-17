#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int width = 6;

    for (int i = 0; i < n * width; ++i)
        std::cout << "+";
    std::cout << std::endl;

    for (int i = 1; i <= n; ++i)
        std::cout << std::setw(width) << i;
    std::cout << std::endl;

    for (int i = 0; i < n * width; ++i)
        std::cout << "+";
    std::cout << std::endl;

    for (int i = 1; i <= n; ++i) {
        double r = std::sqrt(i);
        if (r == (int)r)
            std::cout << std::setw(width) << std::fixed << std::setprecision(0) << r;
        else
            std::cout << std::setw(width) << std::fixed << std::setprecision(2) << r;
    }
    std::cout << std::endl;

    for (int i = 0; i < n * width; ++i)
        std::cout << "+";
    std::cout << std::endl;

    return 0;
}
