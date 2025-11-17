#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("task9.txt");
    if (!fin.is_open()) {
        std::cerr << "Помилка: не вдалося відкрити файл task9.txt\n";
        return 1;
    }

    std::vector<unsigned long long> nums;
    unsigned long long x;
    while (fin >> x)
        nums.push_back(x);
    fin.close();

    if (nums.empty()) {
        std::cerr << "Файл порожній або некоректний.\n";
        return 1;
    }

    for (size_t i = 0; i + 1 < nums.size(); ++i)
        if (nums[i] > nums[i + 1])
            nums[i] = nums[i] * nums[i];

    std::ofstream fout("task9.txt");
    if (!fout.is_open()) {
        std::cerr << "Помилка: не вдалося відкрити файл task9.txt для запису\n";
        return 1;
    }

    for (size_t i = 0; i < nums.size(); ++i)
        fout << nums[i] << (i + 1 == nums.size() ? "" : " ");
    fout.close();

    std::cout << "Файл оновлено успішно.\n";
    return 0;
}
