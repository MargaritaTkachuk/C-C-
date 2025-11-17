#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    std::ifstream fin("input_.txt");
    if (!fin.is_open()) {
        std::cerr << "Помилка: не вдалося відкрити файл input_.txt\n";
        return 1;
    }

    std::vector<unsigned long long> numbers;
    unsigned long long a;
    while (fin >> a)
        numbers.push_back(a);
    fin.close();

    std::cout << std::fixed << std::setprecision(3);
    for (int i = numbers.size() - 1; i >= 0; --i)
        std::cout << std::sqrt((long double)numbers[i]) << std::endl;

    return 0;
}
