#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cout << "Введіть n: ";
    std::cin >> n;

    std::vector<int> m(n);
    std::cout << "Введіть " << n << " цілих чисел m_i:\n";
    for (int i = 0; i < n; ++i)
        std::cin >> m[i];

    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        std::cerr << "Помилка: файл input.txt не знайдено.\n";
        return 1;
    }

    std::vector<double> x(n);
    for (int i = 0; i < n; ++i) {
        if (!(fin >> x[i])) {
            std::cerr << "Помилка: некоректні дані у файлі.\n";
            return 1;
        }
    }
    fin.close();

    std::ofstream fout("output.txt");
    if (!fout.is_open()) {
        std::cerr << "Помилка: не вдалося відкрити output.txt для запису.\n";
        return 1;
    }

    for (int i = 0; i < n; ++i)
        fout << std::pow(x[i], m[i]) << " ";

    fout.close();
    std::cout << "Результат записано у файл output.txt\n";

    return 0;
}
