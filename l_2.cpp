#include <iostream>
#include <vector>
#include <string>

int main() {
    int p;
    std::cin >> p;
    std::vector<unsigned long long> numbers(p);
    std::string s;
    std::cin >> s;

    for (int i = 0; i < p; ++i) {
        std::string part = s.substr(i * 10, 10);
        numbers[i] = std::stoull(part);
    }

    unsigned long long sum = 0;
    for (auto n : numbers) sum += n;

    std::cout << sum << std::endl;
    return 0;
}
