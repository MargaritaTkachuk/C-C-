#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x, y;
    std::cin >> x >> y;
    double result = std::pow(x, y);
    std::cout << std::fixed << std::setprecision(6) << result << std::endl;
    std::cout << std::scientific << std::setprecision(6) << result << std::endl;
    return 0;
}
